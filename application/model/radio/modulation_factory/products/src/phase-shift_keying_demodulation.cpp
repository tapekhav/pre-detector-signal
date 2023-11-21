#include <binary_phase-shift_keying_demodulation.h>

#include <numeric>


BPSKDemodulation::BPSKDemodulation(double sample_rate,
                                   double symbol_duration)
                                                : _sample_rate(sample_rate),
                                                  _symbol_duration(symbol_duration) {}

std::vector<bool> BPSKDemodulation::demodulate(const std::vector<complex> &received_signal)
{
    std::vector<bool> demodulated_bits;

    int num_samples_per_symbol = static_cast<int>(_sample_rate * _symbol_duration);

    for (int i = 0; i < received_signal.size(); i += num_samples_per_symbol)
    {
        complex symbol_sum = std::accumulate(
                received_signal.begin() + i,
                received_signal.begin() + i + num_samples_per_symbol,
                complex(0.0, 0.0)
        );

        double phase = std::arg(symbol_sum);

        bool demodulated_bit = (phase > 0.0);
        demodulated_bits.push_back(demodulated_bit);
    }

    return demodulated_bits;
}
