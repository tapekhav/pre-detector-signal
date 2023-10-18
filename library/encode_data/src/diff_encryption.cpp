#include <diff_encryption.h>

void DiffEncryption::doDiffCode(std::bitset<lib_consts::kSizeBitset> &bitset)
{
    std::bitset<lib_consts::kSizeBitset> copy(bitset);
    for (size_t i = lib_consts::kSizeInfoBits - 1; i > 0; --i)
    {
        bitset[i] = bitset[i] ^ copy[i + 1];
    }
}