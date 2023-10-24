#include <encode_word.h>

void EncodeWord::codeSequence(bitset_sequence &sequence)
{
    for (auto& bits : sequence)
    {
        _differential->doDiffCode(bits);
    }
}
