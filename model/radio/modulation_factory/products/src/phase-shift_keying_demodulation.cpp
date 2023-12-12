#include <binary_phase-shift_keying_demodulation.h>

#include <numeric>
#include <cmath>

BPSKDemodulation::BPSKDemodulation(double sample_rate,
                                   double symbol_duration)
                                   : _sample_rate(sample_rate),
                                     _symbol_duration(symbol_duration) {}

std::vector<bool> BPSKDemodulation::demodulate(const std::vector<double>& in_phase,
                                               const std::vector<double>& quadrature)
{
    std::vector<bool> demodulated_bits;

    int num_samples_per_symbol = static_cast<int>(_sample_rate * _symbol_duration);

    for (int i = 0; i < in_phase.size(); i += num_samples_per_symbol)
    {
        double phase = std::atan2(in_phase[i], quadrature[i]);

        demodulated_bits.push_back(phase > 0);
    }

    return demodulated_bits;
}
