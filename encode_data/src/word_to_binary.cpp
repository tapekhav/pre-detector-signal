#include <word_to_binary.h>

BinaryWord::BinaryWord(double num)
{
    _bitset_num = *reinterpret_cast<unsigned long long*>(&num);
}

std::bitset<14> BinaryWord::getBitset(std::bitset<48> encoded_value, int &offset) const {
    std::bitset<14> value;
    uint8_t k = 0;

    for (size_t i = 13; i > 1; --i)
    {
        value[i] = encoded_value[48 - (offset + i - 1)];
    }

    offset += 12;

    value[13] = k % 2 != 0;
    value[0] = true;

    return value;
}

std::vector<std::bitset<14>> BinaryWord::getResultBitset() const
{
    std::bitset<48> short_bitset;

    auto begin = _bitset_num.size() - 1;
    size_t k = 48;
    for (size_t i = begin; i > begin - 48; --i)
    {
        short_bitset[--k] = _bitset_num[i];
    }

    std::vector<std::bitset<14>> result;
    int offset = 0;
    for(size_t i = 0; i < 4; ++i)
    {
        result.push_back(getBitset(short_bitset, offset));
    }

    return result;
}

