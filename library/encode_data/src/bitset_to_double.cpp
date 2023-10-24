#include <bitset_to_double.h>

#include <cassert>
#include <memory.h>

double BitsetToDouble::getDouble() const
{
    size_t offset = lib_consts::kSizeDouble - 1;
    std::bitset<lib_consts::kSizeDouble> information_bitset;
    for (int i = 0; i < lib_consts::kNumOfBitset; ++i)
    {
        setValueFromSequence(information_bitset, _sequence[i], offset);
    }

    for (size_t i = offset; i > 0; --i)
    {
        information_bitset[i] = false;
    }
    auto bits_as_uint64 = information_bitset.to_ullong();

    double result;
    memcpy(&result, &bits_as_uint64, sizeof(double));

    return result;
}

void BitsetToDouble::setValueFromSequence(std::bitset<lib_consts::kSizeDouble> &information_bitset,
                                            std::bitset<lib_consts::kSizeBitset> value,
                                            size_t &offset) const
{
    assert(value[0] == 1);

    offset -= lib_consts::kSizeInfoBits;

    int k = 0;
    for (size_t i = lib_consts::kSizeInfoBits; i > 0; --i)
    {
        information_bitset[offset + i] = value[i];
        k = value[i] ? k + 1 : k;
    }

    assert((value[13] + k % 2) % 2 == 0);
}
