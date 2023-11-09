#ifndef PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H
#define PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H

#include <library_consts.h>

/*!
 * \class BitsetToDouble
 * \brief Converts a bitset sequence to a double value.
 *
 * This class provides functionality to convert a bitset sequence to a double value
 * based on specified bit sizes.
 */
class BitsetToDouble
{
public:
    /*!
     * \brief Constructor.
     *
     * \param sequence The bitset sequence to be converted to a double.
     */
    explicit BitsetToDouble(bitset_sequence sequence) : _sequence(std::move(sequence)) {}

    /*!
     * \brief Getter for the double value converted from the bitset sequence.
     *
     * \return The double value obtained from the bitset sequence.
     */
    [[nodiscard]] double getDouble() const;
private:
    /*!
     * \brief Sets the value in the information bitset from the given bitset value.
     *
     * Auxiliary function for getDouble to save not the whole double, but 14 pieces each
     *
     * \param information_bitset The bitset where the value will be set.
     * \param value The bitset containing the value to be set(for filling information_bitset).
     * \param offset The offset in the bitset sequence.
     */
    void setValueFromSequence(std::bitset<lib_consts::kSizeDouble>& information_bitset,
                              std::bitset<lib_consts::kSizeBitset> value,
                              size_t& offset) const;
private:
    //! The bitset sequence to be converted.
    bitset_sequence _sequence;
};

#endif //PRE_DETECTOR_SIGNAL_BITSET_TO_DOUBLE_H
