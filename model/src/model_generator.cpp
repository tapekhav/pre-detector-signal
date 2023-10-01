#include <model_generator.h>
#include <complex>

const double g = 9.81;

std::vector<double> ModelGenerator::generateModel(Interval time_interval)
{
    std::vector<double> result;

    setMotion();

    return result;
}

void ModelGenerator::setMotion()
{
    _motion_formula = [=](double time_point)
    {
        auto coordinates = _model.coordinates().coordinates();
        auto speed = _model.coordinates().speed();
        auto wind_speed = _model.wind_speed();

        Coordinates new_coordinates;

        new_coordinates.set_x(coordinates.x() + time_point * (speed.vx() + wind_speed.vx()));
        new_coordinates.set_y(coordinates.y() + time_point * (speed.vy() + wind_speed.vy()));
        new_coordinates.set_z(coordinates.z() + time_point * (speed.vz() + wind_speed.vz()));

        return new_coordinates;
    };
}
