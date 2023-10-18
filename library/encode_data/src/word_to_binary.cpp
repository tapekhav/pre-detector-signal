#include <word_to_binary.h>

BinaryWord::BinaryWord(double num)
{
    _bitset_num = *reinterpret_cast<unsigned long long*>(&num);
}

std::bitset<lib_consts::kSizeBitset> BinaryWord::getBitset(std::bitset<48> encoded_value, int &offset) const {
    std::bitset<lib_consts::kSizeBitset> value;
    uint8_t k = 0;

    uint16_t j = 0;
    for (size_t i = lib_consts::kSizeInfoBits; i > 0; --i)
    {
        auto val = offset - j++;
        value[i] = encoded_value[val];
        k = value[i] ? k + 1 : k;
    }

    offset -= lib_consts::kSizeInfoBits;

    value[13] = k % 2 != 0;
    value[0] = true;

    return value;
}

bitset_sequence BinaryWord::getResultBitset() const
{
    std::bitset<lib_consts::kSizeAllInfo> short_bitset;

    auto begin = _bitset_num.size() - 1;
    size_t k = lib_consts::kSizeAllInfo;
    for (size_t i = begin; i > begin - lib_consts::kSizeAllInfo; --i)
    {
        short_bitset[--k] = _bitset_num[i];
    }

    bitset_sequence result;
    int offset = lib_consts::kSizeAllInfo - 1;
    for(size_t i = 0; i < lib_consts::kNumOfBitset; ++i)
    {
        result.push_back(getBitset(short_bitset, offset));
    }

    return result;
}

