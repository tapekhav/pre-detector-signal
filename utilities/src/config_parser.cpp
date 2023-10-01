#include <config_parser.h>

ConfigParser::ConfigParser(const std::string &file_name)
{
    std::ifstream file(file_name);
    assert(file.is_open());

    file >> _json_data;
}

void ConfigParser::setData()
{
    auto values = _json_data["model_settings"];

    _model.set_temperature(values.at("temperature"));
    _model.set_humidity(values.at("humidity"));
    _model.set_board_voltage(values.at("board_voltage"));
    _model.set_control_voltage(values.at("control_voltage"));

    setWindSpeed();
    setCoordinates();
}

void ConfigParser::setCoordinates()
{
    auto values = _json_data["model_settings"]["coordinates"];

    std::unique_ptr<WGS84> params = std::make_unique<WGS84>();

    std::unique_ptr<Coordinates> coordinates = std::make_unique<Coordinates>();
    std::unique_ptr<Speed> speed = std::make_unique<Speed>();

    coordinates->set_x(values.at("x"));
    coordinates->set_y(values.at("y"));
    coordinates->set_z(values.at("z"));

    speed->set_vx(values.at("xv"));
    speed->set_vy(values.at("yv"));
    speed->set_vz(values.at("zv"));

    params->set_allocated_coordinates(coordinates.release());
    params->set_allocated_speed(speed.release());

    _model.set_allocated_wgs(params.release());
}

void ConfigParser::setWindSpeed()
{
    auto values = _json_data["model_settings"]["wind_speed"];

    std::unique_ptr<Speed> coordinates = std::make_unique<Speed>();

    coordinates->set_vx(values.at("xv"));
    coordinates->set_vy(values.at("yv"));
    coordinates->set_vz(values.at("zv"));

    _model.set_allocated_wind_speed(coordinates.release());
}
