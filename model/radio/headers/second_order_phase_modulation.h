#ifndef PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
#define PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H

#include <modulation_abstract.h>

//! Quadrature Phase Shift Keying or Binary Phase Shift Keying? странно, здесь не используются modulate rate
/**
 * Converting the phase modulation formula to second-order representation typically involves taking into account the modulation rate (bandwidth) and expressing the modulation in terms of its frequency domain characteristics. To do this, we can introduce the modulation rate \(B\) and the frequency deviation \(Δf\). The formula for second-order phase modulation is as follows:

\[s(t) = A \cdot \cos\left(2\pi f_c t + 2\pi k_f \int_{0}^{t} m(\tau) d\tau\right)\]

Where:
- \(s(t)\) is the modulated signal as a function of time.
- \(A\) is the carrier signal's amplitude.
- \(2\pi\) represents the mathematical constant, which is approximately equal to 6.28318.
- \(f_c\) is the carrier frequency in hertz (Hz).
- \(t\) is time in seconds.
- \(k_f\) is the frequency modulation index, which relates the modulation rate to the frequency deviation.
- \(m(t)\) is the message signal that modulates the frequency.

In this representation, the message signal \(m(t)\) is integrated to determine the phase deviation, and the frequency deviation \(Δf\) is given by:

\[Δf = 2\pi k_f \int m(t) dt\]

The modulation rate (bandwidth) \(B\) is related to \(k_f\) and the message signal bandwidth through the following equation:

\[B = k_f \cdot \text{max}|m(t)|\]

Where \(B\) is the bandwidth of the modulated signal and \(\text{max}|m(t)|\) represents the maximum amplitude of the message signal within its bandwidth.

This representation is commonly used when dealing with frequency modulation (FM), and it relates the phase modulation to the frequency deviation and the modulation rate. It provides a more intuitive understanding of how the message signal affects the carrier frequency.*/
class PhaseModulationTwo final : public AbstractModulation
{
public:
    explicit PhaseModulationTwo(double amplitude,
                                double freq,
                                double central_frequency = 433 * 10e6,
                                double modulation_rate = 4096);

    std::vector<double> modulate(const std::vector<double>& initial_signal) final;
private:
    [[nodiscard]] std::vector<double> integrateSignal(const std::vector<double>& signal);
};

#endif //PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
