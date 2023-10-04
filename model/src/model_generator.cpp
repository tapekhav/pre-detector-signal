#include <model_generator.h>
#include <complex>

static const double L = 0.0065;
static const double H = 1500;

static const double TCV = 0.0002;
static const double TC_t = 0.0001;

static const double k_latitude = 111.32 * 10e4;
static const double k_longitude = 66.96 * 10e4;

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
        model.set_board_voltage(_voltage_formula(model.temperature(), i));

        result.push_back(model);
    }

    return result;
}

void ModelGenerator::setMotionFormula()
{
    _motion_formula = [=](double time_point, const Coordinates& wind_speed)
    {
        auto coordinates = _initial_model.wgs().coordinates();
        auto speed = _initial_model.wgs().speed();

        std::unique_ptr<Params> new_wgs84 = std::make_unique<Params>();
        std::unique_ptr<Coordinates> new_speed = std::make_unique<Coordinates>(speed);
        std::unique_ptr<Coordinates> new_coordinates = std::make_unique<Coordinates>();

        new_coordinates->set_x((coordinates.x() * k_latitude + time_point * std::exp(std::log(wind_speed.x())))
                                                                                                        / k_latitude);
        new_coordinates->set_y((coordinates.y() * k_longitude + time_point * std::exp(std::log(wind_speed.y())))
                                                                                                        / k_longitude);
        new_coordinates->set_z(coordinates.z() + time_point * speed.z());

        new_wgs84->set_allocated_coordinates(new_coordinates.release());
        new_wgs84->set_allocated_speed(new_speed.release());

        return new_wgs84.release();
    };
}

void ModelGenerator::setTemperatureFormula()
{
    _atmosphere_formula = [=](double h)
    {
        return _initial_model.temperature() - L * h;
    };
}

void ModelGenerator::setHumidityFormula()
{
    _humidity_formula = [=](double h)
    {
        return _initial_model.humidity() * std::exp((h - _initial_model.wgs().coordinates().z()) / H);
    };
}

void ModelGenerator::setBoardVoltage()
{
    _voltage_formula = [=](double temperature, double time_point)
    {
        return _initial_model.board_voltage() + TCV * (temperature - _initial_model.temperature()) + TC_t * time_point;
    };

}
