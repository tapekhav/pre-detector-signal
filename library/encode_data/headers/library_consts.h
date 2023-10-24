#ifndef PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
#define PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H

#include <cstdint>
#include <vector>
#include <bitset>

namespace lib_consts
{
    const size_t kSizeBitset = 14;
    const size_t kSizeInfoBits = 12;
    const size_t kSizeDouble = 64;
    const size_t kSizeAllInfo = 48;
    const size_t kNumOfBitset = 4;
}

using bitset_sequence = std::vector<std::bitset<lib_consts::kSizeBitset>>;

#endif //PRE_DETECTOR_SIGNAL_LIBRARY_CONSTS_H
