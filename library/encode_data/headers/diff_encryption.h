#ifndef PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H
#define PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H

#include <diff_encryption_interface.h>

class DiffEncryption final : public IDiffEncryption
{
public:
    void doDiffCode(std::bitset<14>& bitset) final;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H
