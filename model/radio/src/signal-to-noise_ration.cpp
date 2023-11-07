#include <signal-to-noise_ratio.h>


SNR::SNR(double snr_dB, double noise_dB)
{
    _snr_linear = std::pow(10, snr_dB / 10.0);
    double noise_variance = std::pow(10, noise_dB / 10.0);

    _generator = std::make_unique<NoiseGenerator>(std::sqrt(noise_variance));
}