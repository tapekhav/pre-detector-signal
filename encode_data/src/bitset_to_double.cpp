#include <bitset_to_double.h>

#include <cassert>
#include <memory.h>
#include <iostream>

double BitsetToDouble::getDouble() const
{
    size_t offset = 63;
    std::bitset<64> information_bitset;
    for (int i = 0; i < 4; ++i)
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

void BitsetToDouble::setValueFromSequence(std::bitset<64> &information_bitset,
                                            std::bitset<14> value,
                                            size_t &offset) const
{
    assert(value[0] == 1);

    offset -= 12;

    int k = 0;
    for (size_t i = 12; i > 0; --i)
    {
        information_bitset[offset + i] = value[i];
        k = value[i] ? k + 1 : k;
    }

    assert((value[13] + k % 2) % 2 == 0);
}
