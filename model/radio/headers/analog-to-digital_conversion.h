#ifndef PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
#define PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H

#include <vector>
#include <functional>

using adc_conversion = std::function<std::vector<int>(std::vector<double>)>;

/*!
 * Конечно, давайте подробнее рассмотрим этот процесс с использованием формул и обозначений.

1. **АЦП (аналого-цифровое преобразование):**
   - АЦП преобразует аналоговый сигнал \(x(t)\) в цифровую форму с использованием разрядности \(N\) (в вашем случае, \(N = 16\) бит):

     \[x_{\text{дискр}}[n] = \text{round}\left(\frac{x(t)}{V_{\text{max}}} \cdot (2^N - 1)\right)\]

     Где:
     - \(x_{\text{дискр}}[n]\) - дискретное значение сигнала после АЦП.
     - \(n\) - дискретный индекс времени.
     - \(V_{\text{max}}\) - максимальное (опорное) напряжение АЦП (в вашем случае, \(V_{\text{max}} = 5\) В).
*/

class ADC
{
public:
    ADC(int bit_depth, double voltage);

    void conversionNumber(const std::vector<double>& re, const std::vector<double>& im = {});

    [[nodiscard]] std::vector<int> getDiscreteSignalRe() const { return _discrete_signal_re; }
    [[nodiscard]] std::vector<int> getDiscreteSignalIm() const { return _discrete_signal_im; }
private:
    adc_conversion _formula;

    int _bit_depth;
    double _max_reference_voltage;

    std::vector<int> _discrete_signal_re;
    std::vector<int> _discrete_signal_im;
};

#endif //PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
