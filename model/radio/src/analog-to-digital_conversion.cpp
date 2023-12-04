#include <analog-to-digital_conversion.h>
#include <cmath>
#include <thread>

ADC::ADC(int resolution,
         double voltage,
         double sample_rate)
         : _resolution(resolution),
           _max_reference_voltage(voltage) {}

void ADC::analogToDigital(const std::vector<double> &re, const std::vector<double> &im)
{
    auto formula =
    [this](const std::vector<double>& signals)
    {
        std::vector<int> result;

        result.reserve(signals.size());
        for (double signal : signals)
        {
            result.push_back(static_cast<int>(std::round(signal / _max_reference_voltage *
                                                           ((1 << _resolution) - 1))));
        }

        return result;
    };

    std::thread thread_re([this, &re, formula]()
    {
        _discrete_signal_re = formula(re);
    });

    _discrete_signal_im = formula(im);


    thread_re.join();
}

void ADC::convertDigitalToAnalog(double sample_rate, const std::vector<double> &re, const std::vector<double> &im)
{
    auto formula = [this, sample_rate](const std::vector<double>& signal)
    {
        std::vector<int> result;
        for (double i : signal)
        {
            result.push_back(static_cast<int>(std::round(i / _max_reference_voltage *
                                                         ((1 << _resolution) - 1))));
        }

        return result;
    };
}
