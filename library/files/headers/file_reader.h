#ifndef PRE_DETECTOR_SIGNAL_FILE_READER_H
#define PRE_DETECTOR_SIGNAL_FILE_READER_H

#include <string>
#include <fstream>
#include <cassert>

#include <library_consts.h>

class FileReader
{
public:
    explicit FileReader(const std::string& file_name = "result.txt")
             : _file(file_name, std::ios::binary) { assert(_file.is_open()); }

    bool readFrame();

    inline ~FileReader() { _file.close(); }
private:
    std::fstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_FILE_READER_H
