#ifndef PRE_DETECTOR_SIGNAL_SIGNAL_TRANSMISSION_MODEL_H
#define PRE_DETECTOR_SIGNAL_SIGNAL_TRANSMISSION_MODEL_H

#include <vector>
#include <complex>

using cosine_signal_type = std::vector<std::complex<double>>;

class TransmissionModel
{
public:
    explicit TransmissionModel(double sample_rate,
                               double carrier_frequency = 433e6,
                               double modulation_rate = 4096,
                               double transmitter_power = 1.0);

    void generateCosineSignal(size_t num_samples);

    void perfomFM2Modulation();

private:
    double _sample_rate;
    double _carrier_frequency;
    double _modulation_rate;
    double _transmitter_power;

    std::vector<std::complex<double>> _cosine_signal;
};

#endif //PRE_DETECTOR_SIGNAL_SIGNAL_TRANSMISSION_MODEL_H
