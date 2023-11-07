#include <phase-shift_keying_modulation.h>
#include <cmath>
#include <algorithm>


PSKModulation::PSKModulation(double amplitude,
                             double sample_rate,
                             double central_frequency,
                             double symbol_duration)
                                               : _amplitude(amplitude),
                                                 _sample_rate(sample_rate),
                                                 _central_frequency(central_frequency),
                                                 _symbol_duration(symbol_duration) {}

std::vector<double> PSKModulation::modulate(const std::vector<bool> &initial_signal)
{
    std::vector<double> bpsk_signal;

    int num_samples_per_symbol = static_cast<int>(_sample_rate * _symbol_duration);

    for (int bit : initial_signal)
    {
        for (int i = 0; i < num_samples_per_symbol; ++i)
        {
            double t = i / _sample_rate;
            double phase = 2.0 * M_PI * _central_frequency * t;

            if (bit == 0)
            {
                bpsk_signal.push_back(_amplitude * cos(phase));
            }
            else
            {
                bpsk_signal.push_back(_amplitude * cos(phase + M_PI));
            }
        }
    }

    return bpsk_signal;
}