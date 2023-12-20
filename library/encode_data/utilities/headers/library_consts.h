#ifndef PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
#define PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H

#include <cstdint>
#include <vector>
#include <bitset>
#include <map>

/*!
 * \namespace param_consts
 * \brief Namespace containing constants related to bitset sizes and data representation.
 */
namespace param_consts
{
    const size_t kSizeBitset = 14;
    const size_t kSizeInfoBits = 12;
    const size_t kSizeDouble = 64;
    const size_t kSizeAllInfo = 48;
    const size_t kNumOfBitset = 4;
    const size_t kSizeOfSync = 15;
    const size_t kNumOfBits = 8;
    const size_t kSizeInt = sizeof(int) * kNumOfBits;
}

/*!
 * \namespace markers
 * \brief Namespace containing constants related to markers.
 */
namespace markers
{
    const std::string kBeginMarker = "111111000000";
    const std::string kSyncMarker = "111100010011010";
}

/*!
 * \namespace model_consts
 * \brief Namespace containing constants related to model logging.
 */
namespace model_consts
{
    const size_t kNumParams = 10;
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

namespace file_consts
{
    const std::string kPath("/home/vladimir/pre-detector-signal/library/encode-data/utilities/result.bin");
}

//! \typedef Type alias for a sequence of bitsets used throughout the library.
using bitset_sequence = std::vector<std::bitset<param_consts::kSizeBitset>>;

#endif //PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
