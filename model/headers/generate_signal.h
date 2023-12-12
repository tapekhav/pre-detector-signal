#ifndef PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
#define PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H

#include <memory>

#include <binary_phase-shift_keying_modulation.h>
#include <model_generator.h>
#include <vector>

class SignalGenerator
{
public:
    SignalGenerator(const std::vector<bool>& modulating_signal,
                    std::unique_ptr<IModulation<double, bool>>& modulation);

    SignalGenerator(const SignalGenerator& other);
    auto operator=(const SignalGenerator& other) -> SignalGenerator&;

    void swap(SignalGenerator& other);

    SignalGenerator(SignalGenerator&& other) noexcept;

    [[nodiscard]] inline std::vector<double> getTimeVector() const { return _time_vector; }
    [[nodiscard]] inline std::vector<bool> getModulatingSignal() const { return _modulating_signal; }

    void modulateSignal(const Interval& time_interval);

    [[nodiscard]] inline std::vector<double> getInPhase() const { return _in_phase; }
    [[nodiscard]] inline std::vector<double> getQuadrature() const { return _quadrature; }

    void tryToSetModulation(const std::unique_ptr<IModulation<double, bool>>& other_modulation);

    void setTimeInterval(const Interval& time_interval);

    ~SignalGenerator() = default;

private:
    std::vector<double> _time_vector;
    std::vector<bool> _modulating_signal;

    std::vector<double> _in_phase;
    std::vector<double> _quadrature;

    std::unique_ptr<IModulation<double, bool>> _modulation;
};


#endif //PRE_DETECTOR_SIGNAL_GENERATE_SIGNAL_H
