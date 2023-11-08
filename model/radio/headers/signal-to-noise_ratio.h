#ifndef PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H
#define PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H

#include <random>
#include <memory>

/*! \class NoiseGenerator
*   \brief Generate noise with normal distribution
*/
class NoiseGenerator
{
public:
    inline explicit NoiseGenerator(int sigma) : _rd(), _gen(_rd()), _distribution(0, sigma) {}
    inline double generate() { return _distribution(_gen); }

private:
    std::random_device _rd;
    std::mt19937 _gen;
    std::normal_distribution<double> _distribution;
};

/**
 * Деление и умножение на 10 используются для преобразования отношения сигнал/шум из децибелов (dB) в линейную шкалу.
 * В децибелах отношение сигнал/шум (SNR) выражается как логарифмическая величина, и чтобы перейти к линейной шкале,
 * нужно выполнить следующие операции:

1. Разделить значение в децибелах на 10, чтобы получить отношение в натуральных логарифмах (десятичные децибелы).
2. Взять экспоненту полученного значения, чтобы перейти к линейной шкале.

Формула для этого преобразования выглядит следующим образом:

\[ \text{Linear Value} = 10^{\left(\frac{\text{dB Value}}{10}\right)} \]

Таким образом, деление на 10 выполняет первый шаг, переводя значение из децибелов в десятичные децибелы,
 а затем возведение в степень 10 выполняет второй шаг, переводя значение в линейную шкалу.
 Это преобразование позволяет работать с отношением сигнал/шум в линейной форме при моделировании или анализе сигналов и шумов.*/

class SNR
{
public:
    SNR(double snr_dB, double noise_dB);

    [[nodiscard]] inline double getBeginSNRLinear() const { return _snr_linear; }
    [[nodiscard]] inline double getResultSNR() const { return _result_snr; }

    [[nodiscard]] inline double findPmin(int modulation_speed) const;

    [[nodiscard]] inline double generate() const { return _generator->generate(); }
private:
    double _snr_linear;
    double _result_snr;

    std::unique_ptr<NoiseGenerator> _generator;
};

#endif //PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H
