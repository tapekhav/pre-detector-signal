#ifndef PRE_DETECTOR_SIGNAL_PHASE_SHIFT_KEYING_DEMODULATION_H
#define PRE_DETECTOR_SIGNAL_PHASE_SHIFT_KEYING_DEMODULATION_H

#include <demodulation_interface.h>

/*!
 * To demodulate an FM signal with the given formula, you can use the following demodulation approach and then provide C++ code to implement it. The demodulation process involves taking the derivative of the FM signal to obtain the instantaneous frequency and then integrating it to recover the original modulating signal. Here's the formula:

1. Differentiate the FM signal \(s(t)\) to obtain the instantaneous frequency \(f_i(t)\):
\[f_i(t) = \frac{1}{2\pi} \frac{d}{dt}\left(2\pi f_c t + 2\pi k_f \int_{0}^{t} m(\tau) d\tau\right)\]

2. Integrate \(f_i(t)\) over time to recover the original modulating signal \(m(t)\):
\[m(t) = \frac{1}{2\pi k_f} \int_{0}^{t} f_i(\tau) d\tau\]*/

class PSKDemodulation final : public IDemodulation<bool, double>
{
public:
    explicit PSKDemodulation(double sample_rate,
                             double central_frequency,
                             double symbol_duration);

    std::vector<bool> demodulate(const std::vector<double> &modulated_signal) final;
private:
    double _central_frequency;
    double _sample_rate;
    double _symbol_duration;
};

#endif //PRE_DETECTOR_SIGNAL_PHASE_SHIFT_KEYING_DEMODULATION_H
