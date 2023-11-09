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
    /*!
     * \brief Constructor for the NoiseGenerator class.
     *
     * \param sigma The standard deviation of the normal distribution.
     */
    inline explicit NoiseGenerator(int sigma) : _rd(), _gen(_rd()), _distribution(0, sigma) {}
    /*!
     * \brief Generate a random noise value with a normal distribution.
     *
     * \return The generated noise value.
     */
    inline double generate() { return _distribution(_gen); }

private:
    //! Random device for seeding the random number generator.
    std::random_device _rd;
    //! Mersenne Twister random number generator.
    std::mt19937 _gen;
    //! Normal distribution with specified sigma.
    std::normal_distribution<double> _distribution;
};

/*!
 * \class SNR
 * \brief Calculates Signal-to-Noise Ratio (SNR) and provides functionality to generate noise based on SNR values.
 *
 * The SNR class allows for the calculation of Signal-to-Noise Ratio (SNR) and provides a method to generate
 * noise based on specified SNR values.
 */
class SNR
{
public:
    /*!
     * \brief Constructor for the SNR class.
     *
     * \param snr_dB The Signal-to-Noise Ratio in decibels.
     * \param noise_dB The noise level in decibels.
     */
    SNR(double snr_dB, double noise_dB);

    /*!
     * \brief Getter for the initial SNR value in linear scale.
     *
     * \return The initial SNR value in linear scale.
     */
    [[nodiscard]] inline double getBeginSNRLinear() const { return _snr_linear; }
    /*!
     * \brief Get the result SNR value after calculations.
     *
     * \return The result SNR value.
     */
    [[nodiscard]] inline double getResultSNR() const { return _result_snr; }

    /*!
     * \brief Find the minimum power level required based on modulation speed.
     *
     * \param modulation_speed The modulation speed.
     * \return The minimum power level required.
     */
    [[nodiscard]] inline double findPmin(int modulation_speed) const;

    /*!
     * \brief Generate noise based on SNR values.
     *
     * \return The generated noise value.
     */
    [[nodiscard]] inline double generate() const { return _generator->generate(); }
private:
    //! The initial SNR value in linear scale.
    double _snr_linear;
    //! The result SNR value after calculations.
    double _result_snr;

    //! Pointer to the NoiseGenerator instance.
    std::unique_ptr<NoiseGenerator> _generator;
};

#endif //PRE_DETECTOR_SIGNAL_SIGNAL_TO_NOISE_RATIO_H
