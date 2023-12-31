#include <signal-to-noise_ratio.h>


SNR::SNR(double snr_dB, double noise_dB)
{
    _result_snr = snr_dB - noise_dB;
    _snr_linear = std::pow(10, _result_snr / 10.0);

    double noise_variance = std::pow(10, noise_dB / 10.0);

    _generator = std::make_unique<NoiseGenerator>(std::sqrt(noise_variance));
}

double SNR::findPmin(int modulation_speed) const
{
    return -174 + _result_snr + 10 * std::log10(modulation_speed);
}
