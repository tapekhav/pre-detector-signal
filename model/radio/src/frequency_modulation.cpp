#include <frequency_modulation.h>
#include <cmath>
#include <algorithm>


FrequencyModulation::FrequencyModulation(double amplitude,
                                         double freq,
                                         double central_frequency,
                                         double modulation_rate)
                                               : _amplitude(amplitude),
                                                 _sample_freq(freq),
                                                 _central_frequency(central_frequency),
                                                 _modulation_rate(modulation_rate) {}

std::vector<double> FrequencyModulation::modulate(const std::vector<double> &initial_signal)
{
    auto modulation_index = [initial_signal](double modulation_rate)
    {
        double max_value = std::numeric_limits<double>::min();
        for (const auto& i : initial_signal)
        {
            max_value = std::max(std::abs(i), max_value);
        }

        return std::abs(modulation_rate / max_value);
    };

    std::vector<double> modulated_signal;

    auto integrated_signal = integrate(initial_signal);
    for (size_t i = 0; i < initial_signal.size(); ++i)
    {
        double time_point = static_cast<double>(i) / _sample_freq;
        modulated_signal.push_back(_amplitude * cos(2 * M_PI * _central_frequency * time_point +
                                   2 * M_PI * integrated_signal[i] * modulation_index(_modulation_rate)));
    }

    return modulated_signal;
}

std::vector<double> FrequencyModulation::integrate(const std::vector<double> &signal) const
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
