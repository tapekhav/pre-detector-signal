#ifndef PRE_DETECTOR_SIGNAL_BINARY_PHASE_SHIFT_KEYING_DEMODULATION_H
#define PRE_DETECTOR_SIGNAL_BINARY_PHASE_SHIFT_KEYING_DEMODULATION_H

#include <demodulation_interface.h>

/*!
 * \class BPSKDemodulation
 * \brief Demodulates Phase Shift Keying signals to recover the original modulating binary signal.
 *
 * The BPSKDemodulation class implements the IDemodulation interface and provides functionality for demodulating
 * Binary Phase Shift Keying (BPSK) signals.
 */
class BPSKDemodulation final : public IDemodulation<bool, double>
{
public:
    /*!
     * \brief Constructor.
     *
     * \param sample_rate The sampling rate of the modulated signal.
     * \param symbol_duration The duration of each symbol in the modulated signal.
     */
    explicit BPSKDemodulation(double sample_rate,
                              double symbol_duration);

    /*!
     * \brief Demodulates a BPSK signal.
     *
     * @param modulated_signal The input modulated signal.
     * @return A vector of demodulated binary values returns the recovered modulating signal.
     */
    std::vector<bool> demodulate(const std::vector<double>& in_phase,
                                 const std::vector<double>& quadrature) final;
    
    /*!
     * \brief Destructor.
     */
    ~BPSKDemodulation() final = default;
private:
    //! The sampling rate of the modulated signal.
    double _sample_rate;
    //! The duration of each symbol in the modulated signal.
    double _symbol_duration;
};

#endif //PRE_DETECTOR_SIGNAL_BINARY_PHASE_SHIFT_KEYING_DEMODULATION_H
