#ifndef PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H

#include <bitset>
#include <library_consts.h>

class IDiffEncryption
{
public:
    virtual void doDiffCode(std::bitset<lib_consts::kSizeBitset>& bitset) = 0;
    virtual ~IDiffEncryption() = default;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
