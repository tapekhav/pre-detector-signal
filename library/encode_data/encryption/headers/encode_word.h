#ifndef PRE_DETECTOR_SIGNAL_ENCODE_WORD_H
#define PRE_DETECTOR_SIGNAL_ENCODE_WORD_H

#include <memory>

#include <word_to_binary.h>
#include <diff_encryption_interface.h>

/*!
 * \brief A class responsible for encoding a sequence of bitsets using differential encryption.
 *
 * This class takes a unique pointer to an object implementing the IDiffEncryption interface,
 * providing a strategy for differential encryption. It then applies this strategy to encode a
 * sequence of bitsets using the codeSequence method.
 */
class EncodeWord
{
public:
    /*!
     * \brief Constructor
     *
     * \param differential A unique pointer to an object implementing the IDiffEncryption interface.
     */
    explicit EncodeWord(std::unique_ptr<IDiffEncryption> differential) : _differential(std::move(differential)) {}

    /*!
     * \brief Encodes a sequence of bitsets using the configured differential encryption strategy.
     *
     * \param sequence A reference to the sequence of bitsets to be encoded.
     */
    void codeSequence(bitset_sequence& sequence);

private:
    //! The differential encryption strategy.
    std::unique_ptr<IDiffEncryption> _differential;
};

#endif //PRE_DETECTOR_SIGNAL_ENCODE_WORD_H
