#include <analog-to-digital_conversion.h>
#include <cmath>
#include <thread>

ADC::ADC(int bit_depth,
         double voltage)
         : _bit_depth(bit_depth),
           _max_reference_voltage(voltage)
{
    _formula =
    [this](const std::vector<double>& signal)
    {
        std::vector<int> result;
        for (int i : signal)
        {
            result.push_back(static_cast<int>(std::round(i / _max_reference_voltage *
                                                        (std::pow(2, _bit_depth) - 1))));
        }

        return result;
    };
}

void ADC::conversionNumber(const std::vector<double> &re, const std::vector<double> &im)
{
    std::thread thread_re([this, &re]()
    {
        _discrete_signal_re = _formula(re);
    });

    std::thread thread_im([this, &im]()
    {
        _discrete_signal_im = _formula(im);
    });

    thread_re.join();
    thread_im.join();
}
