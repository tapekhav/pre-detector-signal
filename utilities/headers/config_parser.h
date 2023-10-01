#ifndef PRE_DETECTOR_SIGNAL_CONFIG_PARSER_H
#define PRE_DETECTOR_SIGNAL_CONFIG_PARSER_H

#include <cassert>
#include <fstream>

#include <json.hpp>
#include <model.pb.h>

class ConfigParser
{
public:
    explicit ConfigParser(const std::string& file_name = path_to_config);

    void setData();

    [[nodiscard]] inline Model getModel() const { return _model; }

private:
    void setCoordinates();
private:
    Model _model;
    nlohmann::json _json_data;
};

#endif //PRE_DETECTOR_SIGNAL_CONFIG_PARSER_H
