#include <pre_dector_signal_class.h>

#include <analog-to-digital_conversion.h>
#include <bpsk_modulation_factory.h>
#include <consts.h>

PreDetectorSignalClass::PreDetectorSignalClass(const std::vector<bool> &signal)
{
    BPSKModulationFactory factory(1, 1, consts::radio::kCentralFrequency, 1);

    _modulation = factory.createModulationProduct();
    _demodulation = factory.createDemodulationProduct();

    _modulated_signal = _modulation->modulate(signal);
}

void PreDetectorSignalClass::doPreDetectorSignal()
{

}

