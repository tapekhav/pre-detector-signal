#ifndef PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
#define PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H

#include <string>

#include <library_consts.h>

class BinaryWord
{
public:
    explicit BinaryWord(double num);

    [[nodiscard]] bitset_sequence getResultBitset() const;

private:
    std::bitset<lib_consts::kSizeBitset> getBitset(std::bitset<lib_consts::kSizeAllInfo> encoded_value, int& offset) const;
private:
    std::bitset<lib_consts::kSizeDouble> _bitset_num;
};

#endif //PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
