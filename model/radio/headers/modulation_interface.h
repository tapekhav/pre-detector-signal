#ifndef PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H

#include <vector>

class IModulation
{
public:
    virtual std::vector<double> modulate(const std::vector<double>& signal) = 0;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
