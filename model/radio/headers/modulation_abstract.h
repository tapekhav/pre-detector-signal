#ifndef PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H
#define PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H

#include <vector>

class AbstractModulation
{
public:
    explicit AbstractModulation(double amplitude, double freq, double central_frequency, double modulation_rate)
        : _amplitude(amplitude),
          _sample_freq(freq),
          _central_frequency(central_frequency),
          _modulation_rate(modulation_rate) {}

    virtual std::vector<double> modulate(const std::vector<double>& initial_signal) = 0;
protected:
    double _amplitude;
    double _sample_freq;
    double _central_frequency;
    double _modulation_rate;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H
