#include <antenna_signal_strength.h>
#include <cmath>

static const double kLightSpeed = 299792458;

SignalStrength::SignalStrength(double pt, double gt, double gr) : _power_transmitter(pt),
                                                                  _gain_transmitter(gt),
                                                                  _gain_receiving(gr)
{
    _get_wavelength = [](double frequency) { return kLightSpeed / frequency; };
}

double SignalStrength::getPowerReceiving(double distance, double frequency)
{
    return _power_transmitter * _gain_receiving * _gain_transmitter * std::pow(_get_wavelength(frequency), 2)
            / std::pow((4 * M_PI * distance), 2);
}
