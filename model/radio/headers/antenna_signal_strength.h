#ifndef PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H
#define PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H

#include <functional>

class SignalStrength
{
public:
    explicit SignalStrength(double pt = 1, double gt = 10, double gr = 3000);

    double getPowerReceiving(double distance, double frequency);

private:
    double _power_transmitter;

    double _gain_transmitter;
    double _gain_receiving;

    std::function<double(double)> _get_wavelength;
};

#endif //PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H
