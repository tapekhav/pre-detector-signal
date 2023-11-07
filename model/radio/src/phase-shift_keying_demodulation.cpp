#include <phase-shift_keying_demodulation.h>

#include <cmath>
#include <cstddef>


PSKDemodulation::PSKDemodulation(double sample_rate,
                                 double central_freq,
                                 double modulation_rate)
                                                : _sample_rate(sample_rate),
                                                  _central_freq(central_freq),
                                                  _modulation_rate(modulation_rate) {}

std::vector<double> PSKDemodulation::integrate(const std::vector<double> &modulated_signal) const
{
    std::vector<double> integral;

    double cumulative_sum = 0.0;
    for (size_t i = 1; i < modulated_signal.size(); ++i)
    {
        cumulative_sum += (modulated_signal[i] + (i > 0 ? modulated_signal[i - 1] : 0)) / 2.0;
        integral.push_back(cumulative_sum / _sample_rate);
    }

    return integral;
}

std::vector<double> PSKDemodulation::demodulate(const std::vector<double> &modulated_signal)
{

    auto modulation_index = [modulated_signal](double modulation_rate)
    {
        double max_value = *std::max(modulated_signal.begin(), modulated_signal.end());

        return std::abs(modulation_rate / max_value);
    };

    std::vector<double> demodulated_signal, fi;
    for (size_t i = 1; i < modulated_signal.size(); ++i)
    {
        fi.push_back((modulated_signal[i] - modulated_signal[i - 1]) /
                     (2 * M_PI * modulation_index(_modulation_rate) / _sample_rate));
    }



    return demodulated_signal;
}
