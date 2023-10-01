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
    _model.set_wind_speed(values.at("wind_speed"));
    _model.set_humidity(values.at("humidity"));
    _model.set_board_voltage(values.at("board_voltage"));
    _model.set_control_voltage(values.at("control_voltage"));

    setCoordinates();
}

void ConfigParser::setCoordinates()
{
    auto values = _json_data["model_settings"]["coordinates"];

    std::unique_ptr<WGS84> coordinates = std::make_unique<WGS84>();

    coordinates->set_x(values.at("x"));
    coordinates->set_y(values.at("y"));
    coordinates->set_z(values.at("z"));
    coordinates->set_vx(values.at("xv"));
    coordinates->set_vy(values.at("yv"));
    coordinates->set_vz(values.at("zv"));

    _model.set_allocated_coordinates(coordinates.release());
}
