#include <diff_decryption.h>

void DiffDecryption::doDiffCode(std::bitset<lib_consts::kSizeBitset> &bitset)
{
    for (size_t i = lib_consts::kSizeInfoBits - 1; i > 0; --i)
    {
        bitset[i] = bitset[i] ^ bitset[i + 1];
    }
}