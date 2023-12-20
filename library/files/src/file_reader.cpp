#include <library_consts.h>
#include <bits/types/FILE.h>
#include <file_reader.h>

#include <iostream>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_sinks.h>

#include <begin_marker_read_error.h>
#include <information_marker_read_error.h>
#include <parameter_read_error.h>

FileReader::FileReader(const std::string &file_name)
        : _file(file_name),
          _char_read(0)
{
    assert(_file.is_open());

    auto console_logger = spdlog::stdout_logger_mt("console_log");
    auto file_logger = spdlog::basic_logger_mt("file_log", "error.log");

    _logger = std::make_unique<spdlog::logger>("multi_sink_logger",
                                               spdlog::sinks_init_list({file_logger->sinks().front(),
                                                                        console_logger->sinks().front()}));
}

void FileReader::readAllFile()
{
    while(readFrame()) {}
    MEDIATE(EventType::ReadFromFile);
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
    for (size_t i = 0; i < model_consts::kNumParams; ++i)
    {
        readSync();
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
    char buffer[param_consts::kSizeInfoBits];
    _file.read(buffer, param_consts::kSizeInfoBits);
    buffer[param_consts::kSizeInfoBits] = '\0';

    _char_read += param_consts::kSizeInfoBits;

    if (_file.fail())
    {
        throw BeginMarkerReadError();
    }

    _current_frame.append(buffer);
}

void FileReader::readInformationAboutFrame()
{
    char buffer[param_consts::kSizeInt];
    _file.read(buffer, param_consts::kSizeInt);

    buffer[param_consts::kSizeInt] = '\0';

    _char_read += _file.gcount();

    if (_file.fail())
    {
        throw InformationMarkerReadError();
    }
    _current_frame.append(buffer);

    readParam();
}

bool FileReader::readParam()
{
    char buffer[param_consts::kSizeBitset];
    for(uint8_t i = 0; i < param_consts::kNumOfBitset; ++i)
    {
        _file.read(buffer, param_consts::kSizeBitset);
        buffer[param_consts::kSizeBitset] = '\0';

        if (_file.fail())
        {
            return false;
        }
        _char_read += param_consts::kSizeBitset;
        _current_frame.append(buffer);
    }

    return true;
}

void FileReader::readSync()
{
    char buffer[param_consts::kSizeOfSync];
    _file.read(buffer, param_consts::kSizeOfSync);
    buffer[param_consts::kSizeOfSync] = '\0';

    _char_read += param_consts::kSizeOfSync;

    if (_file.fail())
    {
        _logger->error("problem with sync");
        throw ParameterReadError();
    }

    _current_frame.append(buffer);
}


FileReader::~FileReader()
{
    _file.close(); 
}