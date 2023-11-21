#include <pre_detector_signal_class.h>

#include <analog-to-digital_conversion.h>
#include <bpsk_modulation_factory.h>
#include <consts.h>

PreDetectorSignalClass::PreDetectorSignalClass(const std::vector<bool> &signal)
{
    BPSKModulationFactory factory(1, 1, consts::radio::kCentralFrequency, 1);

    _modulation = factory.createModulationProduct();
    _demodulation = factory.createDemodulationProduct();

    _modulating_signal = signal;
}

void PreDetectorSignalClass::doPreDetectorSignal()
{

}

void PreDetectorSignalClass::doADC(const std::vector<complex>& modulated_signal)
{
    ADC(consts::radio::kADCSize, consts::radio::kReferenceADCVoltage);
}

std::vector<complex> PreDetectorSignalClass::doModulation()
{
    return _modulation->modulate(_modulating_signal);
}
