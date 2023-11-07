#ifndef PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H

#include <vector>

template<class OutputType, class SignalType>
class IModulation
{
public:
    virtual std::vector<OutputType> modulate(const std::vector<SignalType>& initial_signal) = 0;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
