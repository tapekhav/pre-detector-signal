#include <diff_encryption.h>

void DiffEncryption::doDiffCode(std::bitset<14> &bitset)
{
    std::bitset<14> copy(bitset);
    for (size_t i = 11; i > 0; --i)
    {
        bitset[i] = bitset[i] ^ copy[i + 1];
    }
}