#include <full_encode_number.h>

#include <diff_encryption.h>

EncodeData::EncodeData(double number) : _encode_word(std::make_unique<DiffEncryption>()),
                                        _seq(BinaryWord(number).getResultBitset())
                                        {
                                            _encode_word.codeSequence(_seq);
                                        }

