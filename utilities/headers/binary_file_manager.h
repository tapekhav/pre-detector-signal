#ifndef PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
#define PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H

#include <fstream>
#include <cassert>
#include <algorithm>

#include <consts.h>

class BinaryFileManager
{
public:
    explicit BinaryFileManager(const std::string& file_name = "result.txt");

    inline void addSynchronize() { std::bitset<15> syn("111100010011010"); _file << syn.to_string(); }

    void setStartFrameMarker(size_t number, double time_step);

    inline void writeBitset(const bitset_sequence& number) { std::for_each(number.begin(), number.end(),
                                                             [&](std::bitset<14> bits) { _file << bits.to_string(); }); }


    inline ~BinaryFileManager() { _file.close(); }
private:
    std::ofstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
