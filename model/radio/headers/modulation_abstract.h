#ifndef PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H
#define PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H

#include <vector>

class AbstractModulation
{
public:
    explicit AbstractModulation(double amplitude) : _amplitude(amplitude) {}
    virtual std::vector<double> modulate(const std::vector<double>& initial_signal) = 0;
protected:
    double _amplitude;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_ABSTRACT_H
