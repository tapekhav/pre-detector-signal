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
    //! TODO correct modulation_index(max(|m(t)|) instead of A)
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

std::vector<double> FrequencyModulation::integrateSignal(const std::vector<double> &signal)
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
