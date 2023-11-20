#ifndef PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H
#define PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H

#include <memory>

#include <encode_word.h>
#include <bitset_to_double.h>

/*!
 * \brief A class responsible for fully decoding a bitset sequence into a numeric value.
 *
 * This class takes a bitset sequence and utilizes the EncodeWord class to perform the decoding process.
 * The fully decoded result is obtained using the execute method, which returns the numeric value.
 */
class DecodeData
{
public:
    /*!
     * \name Constructor
     * \brief Constructs a DecodeData object for a given bitset sequence.
     * \param bitset The bitset sequence to be fully decoded.
     */
    explicit DecodeData(bitset_sequence bitset);

    /*!
     * \brief Executes the full decoding process and returns the result as a double.
     * \return The fully decoded numeric value.
     */
    [[nodiscard]] inline double execute() const { return BitsetToDouble(_encrypt_seq).getDouble(); }

private:
    //! The EncodeWord strategy used for decoding.
    EncodeWord _encode_word;
    //! The bitset sequence to be fully decoded.
    bitset_sequence _encrypt_seq;
};

#endif //PRE_DETECTOR_SIGNAL_FULL_DECODE_NUMBER_H
