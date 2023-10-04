#ifndef PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
#define PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H

#include <fstream>
#include <cassert>

#include <consts.h>

class BinaryFileManager
{
public:
    explicit BinaryFileManager(const std::string& file_name = "result.txt");

    inline void addMarker(char* marker) { _file.write(marker, sizeof(marker)); }

    void setStartFrameMarker(size_t number, double time_step);

    inline ~BinaryFileManager() { _file.close(); }
private:
    std::ofstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
