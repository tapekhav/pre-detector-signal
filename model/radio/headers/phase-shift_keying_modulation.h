#ifndef PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
#define PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H

#include <modulation_interface.h>

/**
 * The general form for BPSK follows the equation:

    {\displaystyle s_{n}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft+\pi (1-n)),\quad n=0,1.}

This yields two phases, 0 and π. In the specific form, binary data is often conveyed with the following signals:[citation needed]

    {\displaystyle s_{0}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft+\pi )=-{\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft)} for binary "0"
    {\displaystyle s_{1}(t)={\sqrt {\frac {2E_{b}}{T_{b}}}}\cos(2\pi ft)} for binary "1"

where f is the frequency of the base band.

Hence, the signal space can be represented by the single basis function

   {\displaystyle \phi (t)={\sqrt {\frac {2}{T_{b}}}}\cos(2\pi ft)}
 * */

class PSKModulation final : public IModulation
{
public:
    explicit PSKModulation(double amplitude,
                           double freq,
                           double central_frequency = 433 * 10e6,
                           double modulation_rate = 4096);

    std::vector<double> modulate(const std::vector<double>& initial_signal) final;
private:
    [[nodiscard]] std::vector<double> integrate(const std::vector<double>& signal) const;

private:
    double _amplitude;
    double _sample_freq;
    double _central_frequency;
    double _modulation_rate;
};

#endif //PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
