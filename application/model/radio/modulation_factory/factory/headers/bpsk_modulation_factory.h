#ifndef PRE_DETECTOR_SIGNAL_MODULATION_FACTORY_H
#define PRE_DETECTOR_SIGNAL_MODULATION_FACTORY_H

#include <abstract_modulation_factory.h>

class BPSKModulationFactory final : public AbstractModulationFactory<complex, bool>
{
public:
    BPSKModulationFactory(double amplitude,
                          double sample_rate,
                          double central_frequency,
                          double symbol_duration);


    [[nodiscard]] std::unique_ptr<IModulation<complex, bool>> createModulationProduct() const final;
    [[nodiscard]] std::unique_ptr<IDemodulation<bool, complex>> createDemodulationProduct() const final;

    ~BPSKModulationFactory() final = default;

private:
    //! The amplitude of the modulated signal.
    double _amplitude;
    //! The sampling rate of the modulated signal.
    double _sample_rate;
    //! The central frequency of the BPSK signal.
    double _central_frequency;
    //! The duration of each symbol in the modulated signal.
    double _symbol_duration;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_FACTORY_H