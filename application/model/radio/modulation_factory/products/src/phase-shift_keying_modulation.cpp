#include <binary_phase-shift_keying_modulation.h>
#include <cmath>


BPSKModulation::BPSKModulation(double amplitude,
                               double sample_rate,
                               double central_frequency,
                               double symbol_duration)
                                               : _amplitude(amplitude),
                                                 _sample_rate(sample_rate),
                                                 _central_frequency(central_frequency),
                                                 _symbol_duration(symbol_duration) {}

std::vector<complex> BPSKModulation::modulate(const std::vector<bool> &initial_signal)
{
    std::vector<complex> bpsk_signal;

    int num_samples_per_symbol = static_cast<int>(_sample_rate * _symbol_duration);

    for (int bit : initial_signal)
    {
        for (int i = 0; i < num_samples_per_symbol; ++i)
        {
            double t = i / _sample_rate;

            double phase_shift = (1 - bit) * M_PI;
            double phase = 2.0 * M_PI * _central_frequency * t + phase_shift;

            bpsk_signal.emplace_back(std::polar(_amplitude, phase));
        }
    }

    return bpsk_signal;
}