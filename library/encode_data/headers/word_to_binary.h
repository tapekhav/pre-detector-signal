#ifndef PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
#define PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H

#include <string>

#include <consts.h>

class BinaryWord
{
public:
    explicit BinaryWord(double num);

    [[nodiscard]] bitset_sequence getResultBitset() const;

private:
    std::bitset<14> getBitset(std::bitset<48> encoded_value, int& offset) const;
private:
    std::bitset<64> _bitset_num;
};

#endif //PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
