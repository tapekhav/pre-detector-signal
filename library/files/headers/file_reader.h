#ifndef PRE_DETECTOR_SIGNAL_FILE_READER_H
#define PRE_DETECTOR_SIGNAL_FILE_READER_H

#include <string>
#include <fstream>
#include <cassert>

#include <spdlog/spdlog.h>

#include <library_consts.h>

class FileReader
{
public:
    explicit FileReader(const std::string& file_name = "result.txt");

    bool readFrame();

    inline ~FileReader() { _file.close(); }
private:
    size_t _char_read;
    std::fstream _file;
    std::string _current_frame;

    std::unique_ptr<spdlog::logger> _logger;
};

#endif //PRE_DETECTOR_SIGNAL_FILE_READER_H
