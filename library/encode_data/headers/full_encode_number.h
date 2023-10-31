#ifndef PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H
#define PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H

#include <memory>

#include <encode_word.h>

class EncodeData
{
public:
    explicit EncodeData(double number);

    [[nodiscard]] inline bitset_sequence execute() const { return _seq; }
private:
    EncodeWord _encode_word;
    bitset_sequence _seq;
};

#endif //PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H
