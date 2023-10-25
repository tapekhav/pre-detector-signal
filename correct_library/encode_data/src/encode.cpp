#include <encode.h>
#include <cmath>


std::vector<uint32_t> EncodeNumber::CastToBitsets()
{
    std::vector<uint32_t> vec;

    encodeInformationValue(vec);
    addBits(vec);

    return vec;
}

void EncodeNumber::encodeInformationValue(std::vector<std::uint32_t> &vector)
{
    const int numBits = std::log2(_num) + 1;
    int numGroups = (numBits + 11) / 12;

    _num &= 0xFFFFFFFE;
    for (int i = numGroups - 1; i >= 0; i--)
    {
        uint32_t group = (_num >> (12 * i)) & 0xFFF;
        vector.push_back(group);
    }
}

void EncodeNumber::addBits(std::vector<std::uint32_t> &vector)
{
    std::for_each(vector.begin(), vector.end(), [=](uint32_t& group)
    {
        group = (group << 1);
        group = countOne(group) % 2 == 1 ? group + 8192 : group;
        group += 1;
    });
}

uint8_t EncodeNumber::countOne(uint32_t num)
{
    std::bitset<14> bitset(num);

    uint8_t k = 0;
    for(size_t i = 0; i < bitset.size(); ++i)
    {
        k = bitset[i] ? k + 1 : k;
    }

    return k;
}
