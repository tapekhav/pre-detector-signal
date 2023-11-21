#ifndef PRE_DETECTOR_SIGNAL_PREDECTOR_SIGNAL_CLASS_H
#define PRE_DETECTOR_SIGNAL_PREDECTOR_SIGNAL_CLASS_H

#include <memory>

#include <modulation_interface.h>
#include <demodulation_interface.h>

class ADC;

class PreDetectorSignalClass
{
public:
    explicit PreDetectorSignalClass(const std::vector<bool>& signal);

    void doPreDetectorSignal();

    [[nodiscard]] std::vector<bool> demodulateSignal() const { return _demodulation->demodulate(_modulated_signal); }

    void doADC();
private:
    std::vector<complex> _modulated_signal;

    std::unique_ptr<IModulation<complex, bool>> _modulation;
    std::unique_ptr<IDemodulation<bool, complex>> _demodulation;

    std::unique_ptr<ADC> _adc;
};

#endif //PRE_DETECTOR_SIGNAL_PREDECTOR_SIGNAL_CLASS_H
