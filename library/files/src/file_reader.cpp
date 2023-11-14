#include <file_reader.h>

#include <iostream>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <begin_marker_read_error.h>
#include <information_marker_read_error.h>
#include <parameter_read_error.h>

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
        readBeginningOfFrame();
        readAllParams();
    }
    catch (const BaseException& error)
    {
        _logger->error("{}: {}(error while reading)", error.name(),
                                                      error.what());
        return false;
    }

    return true;
}

void FileReader::readAllParams()
{
    for (size_t i = 0; i < 10; ++i)
    {
        bool was_bitset_read = readParam();
        if (!was_bitset_read)
        {
            _logger->error(model_consts::kLogMap.at(i));
            throw ParameterReadError();
        }
    }
}

void FileReader::readBeginningOfFrame()
{
    readBeginMarker();
    readInformationAboutFrame();
}

void FileReader::readBeginMarker() {
    char buffer[12];
    _file.read(buffer, 12);

    _char_read += _file.gcount();

    if (_file.fail())
    {
        throw BeginMarkerReadError();
    }

    _current_frame.append(buffer);
}

void FileReader::readInformationAboutFrame()
{
    char buffer[64];
    _file.read(buffer, 64);

    _char_read += _file.gcount();

    if (_file.fail())
    {
        throw InformationMarkerReadError();
    }

    _current_frame.append(buffer);
}

bool FileReader::readParam()
{
    char buffer[lib_consts::kSizeBitset];
    for(uint8_t i = 0; i < lib_consts::kNumOfBitset; ++i)
    {
        _file.read(buffer, lib_consts::kSizeBitset);
        _char_read += _file.gcount();

        if (_file.fail())
        {
            return false;
        }
    }

    return true;
}
