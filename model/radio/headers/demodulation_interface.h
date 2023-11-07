#ifndef PRE_DETECTOR_SIGNAL_IDEMODULATION_H
#define PRE_DETECTOR_SIGNAL_IDEMODULATION_H

#include <vector>

template<class OutputType, class SignalType>
class IDemodulation
{
public:
    virtual std::vector<OutputType> demodulate(const std::vector<SignalType>& modulated_signal) = 0;
};

#endif //PRE_DETECTOR_SIGNAL_IDEMODULATION_H
