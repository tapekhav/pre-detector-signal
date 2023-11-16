#include <diff_encryption.h>

void DiffEncryption::doDiffCode(std::bitset<param_consts::kSizeBitset> &bitset)
{
    std::bitset<param_consts::kSizeBitset> copy(bitset);
    for (size_t i = param_consts::kSizeInfoBits - 1; i > 0; --i)
    {
        bitset[i] = bitset[i] ^ copy[i + 1];
    }
}