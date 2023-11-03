#include <signal_transmission_model.h>

TransmissionModel::TransmissionModel(double sample_rate,
                                     double carrier_frequency,
                                     double modulation_rate,
                                     double transmitter_power) : _sample_rate(sample_rate),
                                                                 _carrier_frequency(carrier_frequency),
                                                                 _modulation_rate(modulation_rate),
                                                                 _transmitter_power(transmitter_power) {}

void TransmissionModel::generateCosineSignal(size_t num_samples)
{
    for (int i = 0; i < num_samples; ++i)
    {
        double phase = 2.0 * M_PI * _carrier_frequency * i / _sample_rate;
        _cosine_signal.push_back(std::polar(1.0, phase));
    }
}

void TransmissionModel::perfomFM2Modulation()
{
    /*for (int i = 0; i < signal.size(); ++i)
    {
        double phase_offset = modulation_rate * data[i];
        double frequency_offset = modulation_rate * data[i];
        double phase = std::arg(signal[i]);
        signal[i] = std::polar(1.0, phase + phase_offset);
        signal[i] *= std::polar(1.0, frequency_offset);
    } */
}
