#ifndef PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
#define PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H

#include <bitset>
#include <library_consts.h>

/*!
 * \class IDiffEncryption
 * \brief An interface representing the contract for differential encryption.
 *
 * This interface defines a method for applying differential encryption/decryption on a bitset.
 */
class IDiffEncryption
{
public:
    /*!
     * \brief Applies differential encryption to the provided bitset.
     * \param bitset A reference to a bitset on which the differential encryption will be applied.
     */
    virtual void doDiffCode(std::bitset<param_consts::kSizeBitset>& bitset) = 0;

    //! Virtual destructor
    virtual ~IDiffEncryption() = default;
};

#endif //PRE_DETECTOR_SIGNAL_DIFF_ENCRYPTION_INTERFACE_H
