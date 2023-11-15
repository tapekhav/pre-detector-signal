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

    [[nodiscard]] std::string getCurrentFrameInfo() const { return _current_frame; }

    inline ~FileReader() { _file.close(); }
private:
    void readAllParams();

    void readSync();

    bool readParam();

    void readBeginningOfFrame();

    void readBeginMarker();

    void readInformationAboutFrame();
private:
    size_t _char_read;
    std::fstream _file;
    std::string _current_frame;

    std::unique_ptr<spdlog::logger> _logger;
};

#endif //PRE_DETECTOR_SIGNAL_FILE_READER_H
