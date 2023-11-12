#ifndef PRE_DETECTOR_SIGNAL_IDEMODULATION_H
#define PRE_DETECTOR_SIGNAL_IDEMODULATION_H

#include <vector>

/*!
 * \class IDemodulation
 * \brief Interface for signal demodulation.
 *
 * The IDemodulation class represents an interface for demodulating a modulated signal to extract the original information.
 * It is template class, allowing for flexibility in the types of the modulated signal and the
 * demodulated output.
 *
 * \tparam OutputType The type of the demodulated output.
 * \tparam SignalType The type of the modulated signal.
 */
template<class OutputType, class SignalType>
class IDemodulation
{
public:
    /*!
     * \brief Virtual function to perform signal demodulation.
     *
     * This function demodulate a modulated signal and returning the demodulated output.
     *
     * \param modulated_signal The input modulated signal.
     * \return A vector of demodulated signal.
     */
    virtual std::vector<OutputType> demodulate(const std::vector<SignalType>& modulated_signal) = 0;
    /*!
     * \brief Virtual destructor.
     *
     * Ensures proper cleanup when the interface is used polymorphically.
     */
    virtual ~IDemodulation() = default;
};

#endif //PRE_DETECTOR_SIGNAL_IDEMODULATION_H
