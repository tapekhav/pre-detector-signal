#ifndef PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
#define PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H

#include <fstream>
#include <cassert>
#include <algorithm>

#include <library_consts.h>

//! RAII
class BinaryFileManager
{
public:
    explicit BinaryFileManager(const std::string& file_name = "result.txt");

    void addSynchronize();

    void setStartFrameMarker(size_t number, double time_step);

    void writeBitset(const bitset_sequence& number);

    inline ~BinaryFileManager() { _file.close(); }
private:
    std::ofstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
