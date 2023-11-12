#ifndef PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
#define PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H

#include <vector>
#include <functional>

/*!
 * \typedef adc_conversion
 * \brief Typedef for the function signature of analog-to-digital conversion.
 *
 * This typedef represents a function that takes a vector of doubles (representing the real and imaginary parts
 * of a complex signal) and returns a vector of integers as the result of the analog-to-digital conversion process.
 */
using adc_conversion = std::function<std::vector<int>(std::vector<double>)>;

/*!
 * \class ADC
 * \brief Analog-to-Digital Converter (ADC) class.
 *
 * The ADC class provides functionality for converting analog signals to digital signals with a specified bit depth.
 */
class ADC
{
public:
    /*!
     * \brief Constructor for the ADC class.
     *
     * \param bit_depth The number of bits used for digital representation.
     * \param voltage The maximum reference voltage of the ADC.
     */
    ADC(int bit_depth, double voltage);

    /*!
     * \brief Performs analog-to-digital conversion on a complex signal.
     *
     * The analog-to-digital conversion is applied separately to the real and imaginary parts of a complex signal.
     *
     * \details
     * The conversion process involves creating two separate threads, one for the real part and one for the imaginary part,
     * to perform the analog-to-digital conversion concurrently.
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
    void conversionNumber(const std::vector<double>& re, const std::vector<double>& im = {});

    /*!
     * \brief Getter for the discrete representation of the real part of the converted signal.
     *
     * \return A vector of integers representing the discrete values of the real part of the converted signal.
     */
    [[nodiscard]] std::vector<int> getDiscreteSignalRe() const { return _discrete_signal_re; }

    /*!
     * \brief Getter for the discrete representation of the imaginary part of the converted signal.
     *
     * \return A vector of integers representing the discrete values of the imaginary part of the converted signal.
     */
    [[nodiscard]] std::vector<int> getDiscreteSignalIm() const { return _discrete_signal_im; }
private:
    //! Function for the ADC conversion formula.
    adc_conversion _formula;

    //! Number of bits used for digital representation.
    int _bit_depth;
    //! Maximum reference voltage of the ADC.
    double _max_reference_voltage;

    //! Discrete representation of the real part of the converted signal.
    std::vector<int> _discrete_signal_re;
    //! Discrete representation of the imaginary part of the converted signal.
    std::vector<int> _discrete_signal_im;
};

#endif //PRE_DETECTOR_SIGNAL_ANALOG_TO_DIGITAL_CONVERSION_H
