#ifndef PRE_DETECTOR_SIGNAL_FREQUENCY_DEMODULATION_H
#define PRE_DETECTOR_SIGNAL_FREQUENCY_DEMODULATION_H

#include <demodulation_interface.h>

/*!
 * To demodulate an FM signal with the given formula, you can use the following demodulation approach and then provide C++ code to implement it. The demodulation process involves taking the derivative of the FM signal to obtain the instantaneous frequency and then integrating it to recover the original modulating signal. Here's the formula:

1. Differentiate the FM signal \(s(t)\) to obtain the instantaneous frequency \(f_i(t)\):
\[f_i(t) = \frac{1}{2\pi} \frac{d}{dt}\left(2\pi f_c t + 2\pi k_f \int_{0}^{t} m(\tau) d\tau\right)\]

2. Integrate \(f_i(t)\) over time to recover the original modulating signal \(m(t)\):
\[m(t) = \frac{1}{2\pi k_f} \int_{0}^{t} f_i(\tau) d\tau\]*/

class FrequencyDemodulation : public IDemodulation
{
public:
    explicit FrequencyDemodulation(double sample_rate, double amplitude, double central_freq, double);
private:
    double _central_freq;
    double _amplitude;
    double _sample_rate;
};

#endif //PRE_DETECTOR_SIGNAL_FREQUENCY_DEMODULATION_H
