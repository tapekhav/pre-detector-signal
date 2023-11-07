#ifndef PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
#define PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H

#include <memory>

#include <phase-shift_keying_modulation.h>

class SignalGenerator
{
public:
    explicit SignalGenerator(double amplitude = 1.0,
                             double frequency = 1.0,
                             double phase = 0.0,
                             double duration = 2.0,
                             int sample_rate = 100);

    std::vector<double> generateSignal();

    inline std::vector<double> modulateSignal() { return _modulation->modulate(generateSignal()); };

    [[nodiscard]] inline std::vector<double> getTimeVector() const { return _time_vector; }
    [[nodiscard]] inline std::vector<double> getModulatingSignal() const { return _modulating_signal; }

private:
    double _amplitude;
    double _frequency;
    double _phase;
    double _duration;
    int _sample_rate;

    std::vector<double> _time_vector;
    std::vector<double> _modulating_signal;

    std::unique_ptr<IModulation> _modulation;
};

#endif //PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
