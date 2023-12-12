#ifndef PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
#define PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H

#include <vector>
#include <functional>

/*!
 * \typedef dac_conversion
 * \brief Typedef for the function signature of analog-to-digital conversion.
 *
 * This typedef represents a function that takes a vector of doubles (representing the real and imaginary parts
 * of a complex signal) and returns a vector of integers as the result of the analog-to-digital conversion process.
 */
using dac_conversion = std::function<std::vector<double>(std::vector<int>)>;

/*!
 * \class DAC
 * \brief Analog-to-Digital Converter (ADC) class.
 *
 * The DAC class provides functionality for converting digital signals to analog signals with a specified bit depth.
 */
class DAC
{
public:
    /*!
     * \brief Constructor for the ADC class.
     *
     * \param resolution The number of bits used for digital representation.
     * \param voltage The maximum reference voltage of the ADC.
     */
    DAC(int resolution, double voltage, double sample_rate, double input_amplitude);

    /*!
     * \brief Performs digital-to-analog conversion on a complex signal.
     *
     * The digital-to-analog conversion is applied separately to the real and imaginary parts of a complex signal.
     *
     * \details
     * The conversion process involves creating two separate threads, one for the real part and one for the imaginary part,
     * to perform the digital-to-analog conversion concurrently.
     *
     * \note
     * It is important to ensure that the vectors `re` and `im` remain valid and unchanged throughout the duration of the
     * conversion process, as the threads access them by reference.
     *
     * \warning
     * Calling this function without providing valid vectors for the real and imaginary parts may result in undefined behavior.
     *
     * \param re Vector representing the real part of the complex signal.
     * \param im Vector representing the imaginary part of the complex signal (default is an empty vector for real signals).
     */
    void digitalToAnalog(const std::vector<int>& re, const std::vector<int>& im = {});

    /*!
     * \brief Getter for the discrete representation of the real part of the converted signal.
     *
     * \return A vector of integers representing the discrete values of the real part of the converted signal.
     */
    [[nodiscard]] std::vector<double> getAnalogSignalRe() const { return _analog_signal_re; }

    /*!
     * \brief Getter for the discrete representation of the imaginary part of the converted signal.
     *
     * \return A vector of integers representing the discrete values of the imaginary part of the converted signal.
     */
    [[nodiscard]] std::vector<double> getAnalogSignalIm() const { return _analog_signal_im; }
private:
    //! Amplitude of source signal
    double _input_amplitude;
    //! Number of bits used for digital representation.
    int _resolution;
    //! Maximum reference voltage of the DAC.
    double _max_reference_voltage;
    //! Sample rate of analog signal

    //! Analog representation of the real part of the converted signal.
    std::vector<double> _analog_signal_re;
    //! Analog representation of the imaginary part of the converted signal.
    std::vector<double> _analog_signal_im;
};

#endif //PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
