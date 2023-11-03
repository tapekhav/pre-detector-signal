#ifndef PRE_DETECTOR_SIGNAL_IDEMODULATION_H
#define PRE_DETECTOR_SIGNAL_IDEMODULATION_H

#include <vector>

class IDemodulation
{
public:
    virtual std::vector<double> demodulate(const std::vector<double>& modulated_signal) = 0;
};

#endif //PRE_DETECTOR_SIGNAL_IDEMODULATION_H
