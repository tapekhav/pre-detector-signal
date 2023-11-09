#ifndef PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
#define PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H

#include <modulation_interface.h>

/*!
 * \class BPSKModulation
 * \brief Modulates binary data using Binary Phase Shift Keying modulation.
 *
 * The BPSKModulation class implements the IModulation interface and provides functionality for modulating binary
 * data using Binary Phase Shift Keying modulation.
 */
class BPSKModulation final : public IModulation<double, bool>
{
public:
    /*!
     * \brief Constructor.
     *
     * \param amplitude The amplitude of the modulated signal.
     * \param sample_rate The sampling rate of the modulated signal.
     * \param central_frequency The central frequency of the modulated signal.
     * \param symbol_duration The duration of each symbol in the modulated signal.
     */
    explicit BPSKModulation(double amplitude,
                            double sample_rate,
                            double central_frequency,
                            double symbol_duration);

    /*!
     * \brief Modulates binary data using BPSK modulation.
     *
     * The modulation process involves generating BPSK-modulated signals.
     *
     * \param initial_signal The input binary signal to be modulated.
     * \return A vector of modulated signal values.
     */
    std::vector<double> modulate(const std::vector<bool>& initial_signal) final;

    /*!
     * \brief Destructor.
     */
    ~BPSKModulation() final = default;
private:
    //! The amplitude of the modulated signal.
    double _amplitude;
    //! The sampling rate of the modulated signal.
    double _sample_rate;
    //! The central frequency of the BPSK signal.
    double _central_frequency;
    //! The duration of each symbol in the modulated signal.
    double _symbol_duration;
};

#endif //PRE_DETECTOR_SIGNAL_FREQUENCY_MODULATION_2_H
