#ifndef PRE_DETECTOR_SIGNAL_ENCODE_H
#define PRE_DETECTOR_SIGNAL_ENCODE_H

#include <cstdint>
#include <bitset>
#include <vector>
#include <algorithm>

class EncodeNumber
{
public:
    explicit inline EncodeNumber(double num) { _num = static_cast<uint32_t>(num * 10 * 3); }

    std::vector<std::bitset<14>> CastToBitsets();

private:
    void encodeInformationValue(std::vector<std::uint32_t>& vector);

    void addBits(std::vector<std::uint32_t>& vector);

    uint8_t countOne(uint32_t num);

private:
    uint32_t _num;
};

#endif //PRE_DETECTOR_SIGNAL_ENCODE_H
