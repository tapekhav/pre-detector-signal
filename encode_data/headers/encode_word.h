#ifndef PRE_DETECTOR_SIGNAL_ENCODE_WORD_H
#define PRE_DETECTOR_SIGNAL_ENCODE_WORD_H

#include <memory>

#include <word_to_binary.h>
#include <diff_encryption.h>

class EncodeWord
{
public:
    explicit EncodeWord(std::unique_ptr<IDiffEncryption> differential) : _differential(std::move(differential)) {}

    void codeSequence(bitset_sequence& sequence);
private:
    std::unique_ptr<IDiffEncryption> _differential;
};

#endif //PRE_DETECTOR_SIGNAL_ENCODE_WORD_H
