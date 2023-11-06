#include <generate_signal.h>
#include <cmath>


SignalGenerator::SignalGenerator(double amplitude,
                                   double frequency,
                                   double phase,
                                   double duration,
                                   int sample_rate)
                                    : _amplitude(amplitude),
                                    _frequency(frequency),
                                    _phase(phase),
                                    _duration(duration),
                                    _sample_rate(sample_rate),
                                    _modulation(std::make_unique<FrequencyModulation>(_amplitude,
                                                                                      _frequency,
                                                                                      _sample_rate)){}

std::vector<double> SignalGenerator::generateSignal()
{
    int num_samples = static_cast<int>(_duration * _sample_rate);

    for (int i = 0; i < num_samples; i++)
    {
        double time = static_cast<double>(i) / _sample_rate;
        _time_vector.push_back(time);
        _modulating_signal.push_back(_amplitude * std::sin(2.0 * M_PI * _frequency * time + _phase));
    }

    return _modulating_signal;
}

