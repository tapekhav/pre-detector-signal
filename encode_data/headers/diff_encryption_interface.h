#ifndef PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H

#include <bitset>

class IDiffEncryption
{
public:
    virtual void doDiffCode(std::bitset<14>& bitset) = 0;
    virtual ~IDiffEncryption() = default;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
