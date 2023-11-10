#include <bpsk_modulation_factory.h>

BPSKModulationFactory::BPSKModulationFactory(double amplitude,
                                             double sample_rate,
                                             double central_frequency,
                                             double symbol_duration)
                                             : _amplitude(amplitude),
                                                 _sample_rate(sample_rate),
                                                 _central_frequency(central_frequency),
                                                 _symbol_duration(symbol_duration) {}

std::unique_ptr<IModulation<double, bool>> BPSKModulationFactory::createModulationProduct() const
{
    return std::make_unique<BPSKModulation>(_amplitude, _sample_rate, _central_frequency, _symbol_duration);
}

std::unique_ptr<IDemodulation<bool, double>> BPSKModulationFactory::createDemodulationProduct() const
{
    return std::make_unique<BPSKDemodulation>(_sample_rate, _symbol_duration);
}
