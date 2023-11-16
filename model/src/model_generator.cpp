#include <model_generator.h>

#include <complex>

#include <consts.h>
#include <antenna_signal_strength.h>

ModelGenerator::ModelGenerator(Model model)
        : _initial_model(std::move(model)),
          _plotter(std::make_unique<Plotter>(plt_dir)),
          _meters_plotter(std::make_unique<Plotter>(plt))
{
    _distance_formula = [this](const Coordinates& current_coordinates)
    {
        const auto& first = current_coordinates;
        auto second = _initial_model.wgs().coordinates();

        return std::sqrt((first.x() - second.x()) * (first.x() - second.x()) +
                         (first.y() - second.y()) * (first.y() - second.y()) +
                         (first.z() - second.z()) * (first.z() - second.z()));
    };
}

std::vector<Model> ModelGenerator::generateModel(Interval time_interval)
{
    std::vector<Model> result;

    setMotionFormula();
    setTemperatureFormula();
    setHumidityFormula();
    setBoardVoltage();

    for(double i = time_interval.begin; i < time_interval.end; i += time_interval.step)
    {
        Model model;

        model.set_allocated_wind_speed(std::make_unique<Coordinates>(_initial_model.wind_speed()).release());
        model.set_allocated_wgs(_motion_formula(i, model.wind_speed()));

        auto h = model.wgs().coordinates().z();
        model.set_temperature(_atmosphere_formula(h));
        model.set_humidity(_humidity_formula(h));
        model.set_board_voltage(_friis_formula(_distance_formula(model.wgs().coordinates())));

        result.push_back(model);
    }

    return result;
}

void ModelGenerator::setMotionFormula()
{
    auto toRadians = [](double degrees)
    {
        return degrees * M_PI / 180.0;
    };

    auto toDegrees = [](double radians)
    {
        return radians * 180.0 / M_PI;
    };

    auto latToMeters = [=](double lat_rad, double rad)
    {
        return rad * log(atan(lat_rad / 2 + M_PI / 4));
    };

    auto lonToMeters = [](double lon, double rad) {
        return lon * rad * M_PI / 180.0;
    };

    auto metersToLat = [=](double y, double rad)
    {
        return toDegrees(2.0 * atan(exp(y / rad)) - M_PI / 2.0);
    };

    auto metersToLon = [=](double x, double rad) {
        return toDegrees(x / rad);
    };


    _motion_formula = [=](double time_point, const Coordinates& wind_speed)
    {
        auto coordinates = _initial_model.wgs().coordinates();
        auto speed = _initial_model.wgs().speed();

        std::unique_ptr<Params> new_wgs84 = std::make_unique<Params>();
        std::unique_ptr<Coordinates> new_speed = std::make_unique<Coordinates>(speed);
        std::unique_ptr<Coordinates> new_coordinates = std::make_unique<Coordinates>();

        double lat_rad = toRadians(coordinates.y());
        double rad = getRadius(lat_rad);

        double init_meters_lat = latToMeters(lat_rad, rad);
        double init_meters_lon = lonToMeters(coordinates.x(), rad);

        auto meters_lat = init_meters_lat + wind_speed.y() * std::exp(std::log10(time_point));
        auto meters_lon = init_meters_lon + wind_speed.x() * std::exp(std::log10(time_point));

        auto lat = metersToLat(meters_lat, rad);
        auto lon = metersToLon(meters_lon, rad);

        new_coordinates->set_x(lon);
        new_coordinates->set_y(lat);

        auto h = coordinates.z() + time_point * speed.z();
        new_coordinates->set_z(h > 12000 ? 12000 : h);

        new_wgs84->set_allocated_coordinates(new_coordinates.release());
        new_wgs84->set_allocated_speed(new_speed.release());

        _plotter->addPoint(lon, lat, h);
        _meters_plotter->addPoint(std::abs(meters_lon - init_meters_lon), std::abs(meters_lat - init_meters_lat), h);

        return new_wgs84.release();
    };
}

double ModelGenerator::getRadius(double lat_rad)
{
    double numerator = (consts::physics::kMajorAxis * consts::physics::kMajorAxis * cos(lat_rad) * cos(lat_rad)) +
                       (consts::physics::kMinorAxis * consts::physics::kMinorAxis * sin(lat_rad) * sin(lat_rad));
    double denominator = (cos(lat_rad) * cos(lat_rad)) + (sin(lat_rad) * sin(lat_rad));

    return sqrt(numerator / denominator);
}

void ModelGenerator::setTemperatureFormula()
{
    _atmosphere_formula = [=](double h)
    {
        return _initial_model.temperature() - consts::physics::L * h;
    };
}

void ModelGenerator::setHumidityFormula()
{
    _humidity_formula = [=](double h)
    {
        return _initial_model.humidity() * std::exp((h - _initial_model.wgs().coordinates().z()) / consts::physics::H);
    };
}

void ModelGenerator::setBoardVoltage()
{
    _friis_formula = [=](double distance)
    {
        SignalStrength friis_formula(
                1,
                10,
                3000,
                consts::radio::kCentralFrequency
        );

        return friis_formula.getPowerReceiving(distance);
    };
}
