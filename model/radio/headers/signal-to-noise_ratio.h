#ifndef PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H
#define PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H

#include <random>

static const double kDispersion = 0;

/*! \class NoiseGenerator
*   \brief Generate noise with normal distribution
*/
class NoiseGenerator
{
public:
    inline NoiseGenerator(): _rd(), _gen(_rd()), _distribution(0, kDispersion) {}
    inline double generate() { return _distribution(_gen); }

private:
    std::random_device _rd;
    std::mt19937 _gen;
    std::normal_distribution<double> _distribution;
};

class SNR
{

};

#endif //PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H
