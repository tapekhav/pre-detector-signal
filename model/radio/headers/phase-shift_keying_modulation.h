#ifndef PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
#define PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H

#include <modulation_interface.h>

/*!
 * The general form for BPSK follows the equation:

    {\displaystyle s_{n}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft+\pi (1-n)),\quad n=0,1.}

This yields two phases, 0 and π. In the specific form, binary data is often conveyed with the following signals:[citation needed]

    {\displaystyle s_{0}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft+\pi )=-{\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft)} for binary "0"
    {\displaystyle s_{1}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft)} for binary "1"

where f is the frequency of the base band.

Hence, the signal space can be represented by the single basis function

   {\displaystyle \phi (t)={\sqrt {\frac {2}{T_{b}}}}\cos(2\pi ft)}
*/

class PSKModulation final : public IModulation<double, bool>
{
public:
    explicit PSKModulation(double amplitude,
                           double sample_rate,
                           double central_frequency,
                           double symbol_duration);

    std::vector<double> modulate(const std::vector<bool>& initial_signal) final;
private:
    double _amplitude;
    double _sample_rate;
    double _central_frequency;
    double _symbol_duration;
};

#endif //PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
