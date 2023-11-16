#ifndef PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
#define PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H

#include <memory>

#include <binary_phase-shift_keying_modulation.h>

class SignalGenerator
{
public:
    explicit SignalGenerator(double sample_rate,
                             const std::vector<double>& modulating_signal,
                             std::unique_ptr<IModulation<double, bool>>& modulation);

    SignalGenerator(const SignalGenerator& other);

    SignalGenerator(SignalGenerator&& other) noexcept;

    [[nodiscard]] inline std::vector<double> getTimeVector() const { return _time_vector; }
    [[nodiscard]] inline std::vector<bool> getModulatingSignal() const { return _modulating_signal; }

    inline std::vector<double> modulateSignal() { return _modulation->modulate(getModulatingSignal()); };

    void tryToSetModulation(const std::unique_ptr<IModulation<double, bool>>& other_modulation);

private:
    std::vector<double> _time_vector;
    std::vector<bool> _modulating_signal;

    std::unique_ptr<IModulation<double, bool>> _modulation;
};

#endif //PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
