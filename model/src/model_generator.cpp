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

    setMotionFormula();
    setTemperatureFormula();
    setHumidityFormula();
    setBoardVoltage();

    for(double i = time_interval.begin; i < time_interval.end; i += time_interval.step)
    {
        Model model;

        model.set_allocated_wgs(_motion_formula(i));

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
    _motion_formula = [=](double time_point)
    {
        auto coordinates = _initial_model.wgs().coordinates();
        auto speed = _initial_model.wgs().speed();
        auto wind_speed = _initial_model.wind_speed();

        std::unique_ptr<WGS84> new_wgs84;
        std::unique_ptr<Speed> new_speed;
        std::unique_ptr<Coordinates> new_coordinates;

        new_speed->CopyFrom(speed);

        new_coordinates->set_x(coordinates.x() + time_point * (speed.vx() + wind_speed.vx()));
        new_coordinates->set_y(coordinates.y() + time_point * (speed.vy() + wind_speed.vy()));
        new_coordinates->set_z(coordinates.z() + time_point * (speed.vz() + wind_speed.vz()));

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
