#include <word_to_binary.h>
#include <iostream>

BinaryWord::BinaryWord(double num)
{
    _bitset_num = *reinterpret_cast<unsigned long long*>(&num);
}

std::bitset<14> BinaryWord::getBitset(std::bitset<48> encoded_value, int &offset) const {
    std::bitset<14> value;
    uint8_t k = 0;

    uint16_t j = 0;
    for (size_t i = 12; i > 0; --i)
    {
        auto val = offset - j++;
        value[i] = encoded_value[val];
        k = value[i] ? k + 1 : k;
    }

    offset -= 12;

    value[13] = k % 2 != 0;
    value[0] = true;

    return value;
}

bitset_sequence BinaryWord::getResultBitset() const
{
    std::bitset<48> short_bitset;

    auto begin = _bitset_num.size() - 1;
    size_t k = 48;
    for (size_t i = begin; i > begin - 48; --i)
    {
        short_bitset[--k] = _bitset_num[i];
    }

    bitset_sequence result;
    int offset = 47;
    for(size_t i = 0; i < 4; ++i)
    {
        result.push_back(getBitset(short_bitset, offset));
    }

    return result;
}

