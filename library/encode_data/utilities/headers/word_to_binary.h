#ifndef PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
#define PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H

#include <string>

#include <library_consts.h>

/*!
 * \brief A class responsible for converting a double value into a bitset sequence.
 *
 * This class provides functionality to convert a double value into a bitset sequence,
 * allowing for representation in binary form with a specific size.
 */
class BinaryWord
{
public:
    /*!
     * \name BinaryWord
     * \brief Constructs a BinaryWord object for a given double value.
     * \param num The double value to be converted into a bitset sequence.
     */
    explicit BinaryWord(double num);

    /*!
     * \brief Gets the result bitset sequence obtained from the conversion.
     * \return The bitset sequence representing the converted double value.
     */
    [[nodiscard]] bitset_sequence getResultBitset() const;

private:
    /*!
     * \brief Converts the encoded value to a bitset with a specified offset.
     *
     * This private method is used internally to convert an encoded value into a bitset
     * with a specified offset.
     *
     * \param encoded_value The encoded value to be converted.
     * \param offset The offset used during the conversion.
     * \return The resulting bitset from the conversion.
     */
    std::bitset<param_consts::kSizeBitset> getBitset(std::bitset<param_consts::kSizeAllInfo> encoded_value, int& offset) const;

private:
    //! The bitset representation of the double value.
    std::bitset<param_consts::kSizeDouble> _bitset_num;
};

#endif //PRE_DETECTOR_SIGNAL_WORD_TO_BINARY_H
