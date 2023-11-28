#include <full_decode_number.h>

#include <diff_decryption.h>


DecodeData::DecodeData(bitset_sequence bitset) : _encode_word(std::make_unique<DiffDecryption>())
{
    _encode_word.codeSequence(bitset);
    _encrypt_seq = std::move(bitset);
}


