#ifndef PRE_DETECTOR_SIGNAL_FILE_READER_H
#define PRE_DETECTOR_SIGNAL_FILE_READER_H

#include <string>
#include <fstream>

#include <library_consts.h>

class FileReader
{
public:
    explicit FileReader(const std::string& file_name = "result.txt");

    inline void addSynchronize() { std::bitset<15> syn("111100010011010"); _file << syn.to_string(); }

    void setStartFrameMarker(size_t number, double time_step);

    inline ~FileReader() { _file.close(); }
private:
    std::fstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_FILE_READER_H
