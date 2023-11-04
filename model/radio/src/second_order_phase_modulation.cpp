#include <second_order_phase_modulation.h>
#include <cstddef>
#include <cmath>
#include <algorithm>


PhaseModulationTwo::PhaseModulationTwo(double amplitude,
                                       double freq,
                                       double central_frequency,
                                       double modulation_rate)
                                        : AbstractModulation(amplitude,
                                                             freq,
                                                             central_frequency,
                                                             modulation_rate) {}

std::vector<double> PhaseModulationTwo::modulate(const std::vector<double> &initial_signal)
{
    auto modulation_index = std::abs(_modulation_rate / _amplitude);

    std::vector<double> modulated_signal;

    auto integrated_signal = integrateSignal(initial_signal);
    for (size_t i = 0; i < initial_signal.size(); ++i)
    {
        double time_point = static_cast<double>(i) / _sample_freq;
        modulated_signal.push_back(_amplitude * cos(2 * M_PI * _central_frequency * time_point +
                                   2 * M_PI * integrated_signal[i] * modulation_index));
    }

}

std::vector<double> PhaseModulationTwo::integrateSignal(const std::vector<double> &signal)
{
    std::vector<double> integral;
    double cumulative_sum = 0.0;

    for (size_t i = 0; i < signal.size(); ++i)
    {
        cumulative_sum += (signal[i] + (i > 0 ? signal[i - 1] : 0)) / 2.0;
        integral.push_back(cumulative_sum / _sample_freq);
    }

    return integral;
}

