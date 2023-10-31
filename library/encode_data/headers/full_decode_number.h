#ifndef PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H
#define PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H

#include <memory>

#include <encode_word.h>
#include <bitset_to_double.h>

class DecodeData
{
public:
    explicit DecodeData(bitset_sequence bitset);

    [[nodiscard]] inline double execute() const { return BitsetToDouble(_encrypt_seq).getDouble(); }
private:
    EncodeWord _encode_word;
    bitset_sequence _encrypt_seq;
};

#endif //PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H
