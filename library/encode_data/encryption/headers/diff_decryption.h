#ifndef PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H
#define PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H

#include <diff_encryption_interface.h>

/*!
 * \class DiffDecryption
 * \brief A class representing the differential decryption functionality.
 *
 * This class inherits from the IDiffEncryption interface, decrypt input bitset in method doDiffCode.
 */
class DiffDecryption final : public IDiffEncryption
{
public:
    /*!
     * \brief Performs differential decryption on the provided bitset.
     *
     * This method is an implementation of the pure virtual method from the IDiffEncryption interface.
     * It applies the differential decryption algorithm to modify the provided bitset.
     *
     * \param bitset A reference to a bitset on which the differential decryption will be applied.
     */
    void doDiffCode(std::bitset<param_consts::kSizeBitset>& bitset) final;

    //! Destructor
    ~DiffDecryption() final = default;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_DECRYPTION_H
