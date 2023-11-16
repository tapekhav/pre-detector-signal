#include <antenna_signal_strength.h>
#include <cmath>

static const double kLightSpeed = 299792458;

SignalStrength::SignalStrength(
        double pt,
        double gt,
        double gr,
        double frequency
)
        : _power_transmitter(pt),
          _gain_transmitter(gt),
          _gain_receiving(gr),
          _wavelength(kLightSpeed / frequency) {}

double SignalStrength::getPowerReceiving(double distance) const
{
    return _power_transmitter * _gain_receiving * _gain_transmitter * std::pow(_wavelength, 2)
            / std::pow((4 * M_PI * distance), 2);
}
