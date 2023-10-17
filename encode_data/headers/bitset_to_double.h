#ifndef PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H
#define PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H

#include <consts.h>

class BitsetToDouble
{
public:
    explicit BitsetToDouble(bitset_sequence sequence) : _sequence(std::move(sequence)) {}

    [[nodiscard]] double getDouble() const;
private:
    void setValueFromSequence(std::bitset<64>& information_bitset, std::bitset<14> value, size_t& offset) const;
private:
    bitset_sequence _sequence;
};

#endif //PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H
