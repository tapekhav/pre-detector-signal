#ifndef PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H

#include <base_exception.h>


/*!
 * \class InformationMarkerReadError
 * \brief Exception class for errors encountered while reading information markers.
 *
 * This class inherits from the BaseException class and is used to indicate errors
 * related to the read operation of information markers.
 */
class InformationMarkerReadError final : public BaseException
{
public:
    /*!
     * \brief Get the name of the exception.
     * \return A string containing the name "InformationMarkerReadError".
     */
    [[nodiscard]] inline const char* name() const noexcept final { return "InformationMarkerReadError"; }
    /*!
     * \brief Get a string describing the exception.
     * \return A string containing an error message indicating the failure to read information about the marker.
     */
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read the information about marker"; }

    //! Destructor
    ~InformationMarkerReadError() noexcept final = default;
};

#endif //PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H
