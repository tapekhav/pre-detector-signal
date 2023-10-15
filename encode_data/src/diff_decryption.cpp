#include <diff_decryption.h>

void DiffDecryption::doDiffCode(std::bitset<14> &bitset)
{
    for (size_t i = 1; i < 13; ++i)
    {
        bitset[i] = bitset[i] ^ bitset[i - 1];
    }
}

