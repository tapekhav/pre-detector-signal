#ifndef PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H
#define PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H

#include <memory>

#include <encode_word.h>

/*!
 * \brief A class responsible for fully encoding a numeric value.
 *
 * This class takes a numeric value and utilizes the EncodeWord class to fully encode it.
 * The fully encoded result is stored in a bitset_sequence, which can be retrieved using the
 * execute method.
 */
class EncodeData
{
public:
    /*!
     * \name Constructor
     * \brief Constructs an EncodeData object for a given numeric value.
     * \param number The numeric value to be fully encoded.
     */
    explicit EncodeData(double number);

    /*!
     * \brief Executes the full encoding process and returns the result as a bitset sequence.
     * \return The fully encoded bitset sequence.
     */
    [[nodiscard]] inline bitset_sequence execute() const { return _seq; }

private:
    //! EncodeWord used for encoding all parameter.
    EncodeWord _encode_word;
    //! The fully encoded bitset sequence.
    bitset_sequence _seq;
};

#endif //PRE_DETECTOR_SIGNAL_FULL_ENCODE_NUMBER_H
