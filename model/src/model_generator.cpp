#include <model_generator.h>
#include <complex>

static const double g = 9.81;
static const double L = 0.0065;
static const double H = 1500;

static const double TCV = 0.0002;
static const double TC_t = 0.0001;

std::vector<Model> ModelGenerator::generateModel(Interval time_interval)
{
    std::vector<Model> result;

    setWind();
    setMotionFormula();
    setTemperatureFormula();
    setHumidityFormula();
    setBoardVoltage();

    for(double i = time_interval.begin; i < time_interval.end; i += time_interval.step)
    {
        Model model;

        model.set_allocated_wind_speed(_wind_formula(i));
        model.set_allocated_wgs(_motion_formula(i, model.wind_speed().speed()));

        auto h = model.wgs().coordinates().z();
        model.set_temperature(_atmosphere_formula(h));
        model.set_humidity(_humidity_formula(h));
        model.set_board_voltage(_voltage_formula(model.temperature(), i));

        model.set_allocated_wind_speed(std::make_unique<Params>(_initial_model.wind_speed()).release());

        result.push_back(model);
    }

    return result;
}

void ModelGenerator::setWind()
{
    _wind_formula = [=](double time_point)
    {
        std::unique_ptr<Params> new_wind_speed = std::make_unique<Params>();

        auto acceleration = _initial_model.wind_speed().acceleration();
        auto speed = _initial_model.wind_speed().speed();

        speed.set_x(speed.x() + acceleration.x() * time_point);
        speed.set_y(speed.y() + acceleration.y() * time_point);
        speed.set_z(speed.z() + acceleration.z() * time_point);

        std::unique_ptr<Coordinates> new_speed = std::make_unique<Coordinates>(speed);
        std::unique_ptr<Coordinates> new_acceleration = std::make_unique<Coordinates>(acceleration);

        new_wind_speed->set_allocated_speed(new_speed.release());
        new_wind_speed->set_allocated_acceleration(new_acceleration.release());

        return new_wind_speed.release();
    };

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

        new_coordinates->set_x(coordinates.x() + time_point * (speed.x() + wind_speed.x()));
        new_coordinates->set_y(coordinates.y() + time_point * (speed.y() + wind_speed.y()));
        new_coordinates->set_z(coordinates.z() + time_point * (speed.z() + wind_speed.z()));

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
