#include <file_reader.h>

#include <iostream>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <begin_marker_read_error.h>

FileReader::FileReader(const std::string &file_name)
        : _file(file_name, std::ios::binary),
          _char_read(0)
{
    assert(_file.is_open());

    auto console_logger = spdlog::stdout_logger_mt("console_logger");
    auto file_logger = spdlog::basic_logger_mt("file_logger", "error.log");

    _logger = std::make_unique<spdlog::logger>("multi_sink_logger",
                                               spdlog::sinks_init_list({file_logger->sinks().front(),
                                                                        console_logger->sinks().front()}));
}

bool FileReader::readFrame()
{
    try
    {
        std::string begin_marker;
        _file.read(begin_marker.data(), 12);

        _char_read += _file.gcount();

        if (_file.fail())
        {
            throw BeginMarkerReadError();
        }
    }
    catch (const BeginMarkerReadError& begin_marker_read_error)
    {
        std::cerr << begin_marker_read_error.name() << ": "
                  << begin_marker_read_error.what() << '\n';
    }

    return false;
}
