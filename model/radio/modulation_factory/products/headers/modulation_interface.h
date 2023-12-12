#ifndef PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H

#include <vector>
#include <complex>

using complex = std::complex<double>;

/*!
 * \class IModulation
 * \brief Interface for signal modulation_factory.
 *
 * The IModulation class represents an interface for modulating an initial signal to produce a modulated signal.
 * It is template class, allowing for flexibility in the types.
 *
 * \tparam OutputType The type of the modulated output.
 * \tparam SignalType The type of the initial signal.
 */
template<class OutputType, class SignalType>
class IModulation
{
public:
    /*!
     * \brief Virtual function to perform signal modulation_factory.
     *
     * This function modulate an initial signal and returning the modulated output.
     *
     * \param initial_signal The input initial signal to be modulated.
     * \return A vector of modulated output values.
     */
    virtual void modulate(const std::vector<SignalType>& initial_signal) = 0;

    virtual std::vector<OutputType> getInPhase() const = 0;

    virtual std::vector<OutputType> getQuadrature() const = 0;
    /*!
     * \brief Virtual destructor.
     *
     * Ensures proper cleanup when the interface is used polymorphically.
     */
    virtual ~IModulation() = default;
};

#endif //PRE_DETECTOR_SIGNAL_MODULATION_INTERFACE_H
