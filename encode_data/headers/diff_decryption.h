#ifndef PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H
#define PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H

#include <diff_encryption_interface.h>

class DiffDecryption final : public IDiffEncryption
{
public:
    void doDiffCode(std::bitset<14>& bitset) final;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H
