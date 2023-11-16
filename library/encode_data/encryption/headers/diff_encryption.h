#ifndef PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H
#define PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H

#include <diff_encryption_interface.h>

/*!
 * \class DiffEncryption
 * \brief A class representing the differential encryption functionality.
 *
 * This class inherits from the IDiffEncryption interface, encrypt input bitset in method doDiffCode.
 */
class DiffEncryption final : public IDiffEncryption
{
public:
    /*!
     * \brief Performs differential encryption on the provided bitset.
     *
     * This method is an implementation of the pure virtual method from the IDiffEncryption interface.
     * It applies the differential encryption algorithm to modify the provided bitset.
     *
     * \param bitset A reference to a bitset on which the differential encryption will be applied.
     */
    void doDiffCode(std::bitset<param_consts::kSizeBitset>& bitset) final;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_ENCODE_H
