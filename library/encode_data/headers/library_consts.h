#ifndef PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
#define PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H

#include <cstdint>
#include <vector>
#include <bitset>
#include <map>

namespace lib_consts
{
    const size_t kSizeBitset = 14;
    const size_t kSizeInfoBits = 12;
    const size_t kSizeDouble = 64;
    const size_t kSizeAllInfo = 48;
    const size_t kNumOfBitset = 4;
}

namespace file_consts
{
    const std::map<size_t, std::string> kLogMap =
    {
            {0, "temperature"},
            {1, "wind_speed_x"},
            {2, "wind_speed_y"},
            {3, "coordinates_x"},
            {4, "coordinates_y"},
            {5, "coordinates_z"},
            {6, "wgs_speed_z"},
            {7, "humidity"},
            {8, "board_voltage"},
            {9, "control_voltage"}
    };
}

using bitset_sequence = std::vector<std::bitset<lib_consts::kSizeBitset>>;

#endif //PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
