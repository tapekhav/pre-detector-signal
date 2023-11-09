#include <binary_phase-shift_keying_demodulation.h>

#include <cmath>
#include <cstddef>


BPSKDemodulation::BPSKDemodulation(double sample_rate,
                                   double symbol_duration)
                                                : _sample_rate(sample_rate),
                                                  _symbol_duration(symbol_duration) {}

std::vector<bool> BPSKDemodulation::demodulate(const std::vector<double> &modulated_signal)
{
    std::vector<bool> binary_data;

    int num_samples_per_symbol = static_cast<int>(_sample_rate * _symbol_duration);

    for (int i = 0; i < modulated_signal.size(); i += num_samples_per_symbol)
    {
        double sum = 0.0;

        for (int j = i; j < i + num_samples_per_symbol; ++j)
        {
            sum += modulated_signal[j];
        }

        binary_data.push_back(sum >= 0);
    }

    return binary_data;
}
