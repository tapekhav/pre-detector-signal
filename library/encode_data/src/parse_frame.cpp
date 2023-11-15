#include <parse_frame.h>

#include <bitset>
#include <utility>

#include <begin_marker_read_error.h>
#include <parameter_read_error.h>

#include <spdlog/logger.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

ParseFrame::ParseFrame(double sample_step)
                       : _sample_step(sample_step),
                         _current_sym(0),
                         _time(0),
                         _number_frame(0)
{
    auto console_logger = spdlog::stdout_logger_mt("console_logger");
    auto file_logger = spdlog::basic_logger_mt("file_logger", "error.log");

    _logger = std::make_unique<spdlog::logger>("multi_sink_logger",
                                               spdlog::sinks_init_list({file_logger->sinks().front(),
                                                                        console_logger->sinks().front()}));
}

bool ParseFrame::tryToParseFrame(std::string frame)
{
    _frame = std::move(frame);

    try
    {
        tryToParseBeginMarker();
        tryToParseAllParams();
    }
    catch (const BaseException& error)
    {
        _logger->error("{}: {}(error while parsing)", error.name(),
                                                      error.what());
        return false;
    }

    return true;
}

void ParseFrame::tryToParseBeginMarker()
{
    std::string begin_marker("111111000000");
    if (_frame.compare(_current_sym, 12, begin_marker))
    {
        throw BeginMarkerReadError();
    }
    _current_sym += 12;

    std::bitset<32> number(_frame.substr(_current_sym, 32));
    auto current_number = number.to_ulong();
    if (current_number != _number_frame + 1)
    {
        throw BeginMarkerReadError();
    }

    _number_frame = current_number;
    _current_sym += 32;

    _time = tryToParseParameter();

    if (static_cast<double>(_number_frame) * _sample_step != _time)
    {
        throw BeginMarkerReadError();
    }
}

void ParseFrame::tryToParseSync()
{
    std::string sync_param("111100010011010");
    if (_frame.compare(_current_sym, 15, sync_param))
    {
        _logger->error("problem with sync");
        throw ParameterReadError();
    }

    _current_sym += 15;
}

double ParseFrame::tryToParseParameter()
{
    bitset_sequence param_number;
    for (size_t i = 0; i < 4; ++i)
    {
        std::string param_data = _frame.substr(_current_sym, 14);
        param_number.emplace_back(param_data);
        _current_sym += 14;
    }

    return DecodeData(param_number).execute();
}

void ParseFrame::tryToParseAllParams()
{
    for (size_t i = 0; i < 10; ++i)
    {
        tryToParseSync();
        _params.push_back(tryToParseParameter());
    }
}
