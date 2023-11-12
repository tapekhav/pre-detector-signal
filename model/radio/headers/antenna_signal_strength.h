#ifndef PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H
#define PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H

#include <functional>

/*!
 * \class SignalStrength
 *
 * \brief Calculates signal strength using the Friis Transmission Equation.
 *
 * The Friis Transmission Equation is used to calculate the received power at a given distance for a radio signal.
 * This class provides a convenient interface to perform such calculations based on the specified parameters.
 */
class SignalStrength
{
public:
    /*!
     * \brief Constructor.
     *
     * \param pt Power of the transmitter.
     * \param gt Gain of the transmitter antenna.
     * \param gr Gain of the receiving antenna.
     */
    explicit SignalStrength(double pt = 1, double gt = 10, double gr = 3000);

    /*!
     * \brief Calculates the received power at a given distance and frequency.
     *
     * Uses the Friis Transmission Equation to compute the received power based on the transmitter power, antenna gains,
     * wavelength, and distance.
     *
     * \param distance Distance between the transmitter and receiver (in meters).
     * \param frequency Frequency of the signal (in Hertz).
     * \return The received power at the specified distance and frequency.
     */
    double getPowerReceiving(double distance, double frequency);

private:
    //! Power of the transmitter.
    double _power_transmitter;
    //! Gain of the transmitter antenna.
    double _gain_transmitter;
    //! Gain of the receiving antenna.
    double _gain_receiving;

    /*!
     * \brief Function to calculate the wavelength of the signal based on the frequency.
     *
     * Uses the speed of light and the given frequency to compute the wavelength.
     *
     * \param frequency Signal frequency.
     * \return The wavelength of the signal.
     */
    std::function<double(double)> _get_wavelength;
};

#endif //PRE_DETECTOR_SIGNAL_FRIIS_FORMULA_H
