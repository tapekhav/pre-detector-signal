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

    std::unique_ptr<Params> params = std::make_unique<Params>();

    std::unique_ptr<Coordinates> coordinates = std::make_unique<Coordinates>();
    std::unique_ptr<Coordinates> speed = std::make_unique<Coordinates>();

    coordinates->set_x(values.at("x"));
    coordinates->set_y(values.at("y"));
    coordinates->set_z(values.at("z"));

    speed->set_x(values.at("vx"));
    speed->set_y(values.at("vy"));
    speed->set_z(values.at("vz"));

    params->set_allocated_coordinates(coordinates.release());
    params->set_allocated_speed(speed.release());

    _model.set_allocated_wgs(params.release());
}

void ConfigParser::setWindSpeed()
{
    auto values = _json_data["model_settings"]["wind_speed"];

    std::unique_ptr<Params> params = std::make_unique<Params>();

    std::unique_ptr<Coordinates> speed = std::make_unique<Coordinates>();
    std::unique_ptr<Coordinates> acceleration = std::make_unique<Coordinates>();


    speed->set_x(values.at("vx"));
    speed->set_y(values.at("vy"));
    speed->set_z(values.at("vz"));

    acceleration->set_x(values.at("ax"));
    acceleration->set_y(values.at("ay"));
    acceleration->set_z(values.at("az"));

    params->set_allocated_speed(speed.release());
    params->set_allocated_acceleration(acceleration.release());

    _model.set_allocated_wind_speed(params.release());
}
