#include <encode_word.h>

void EncodeWord::codeSequence(std::vector<std::bitset<14>> &sequence)
{
    for (auto& bits : sequence)
    {
        _differential->doDiffCode(bits);
    }
}
