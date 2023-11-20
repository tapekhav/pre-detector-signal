#ifndef PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H

#include <base_exception.h>

/*!
 * \class BeginMarkerReadError
 * \brief Exception class for errors encountered while reading the begin marker.
 *
 * This class inherits from the BaseException class and is used to indicate errors
 * related to the read operation of the begin marker.
 */
class BeginMarkerReadError final : public BaseException
{
public:
    /*!
     * \brief Get the name of the exception.
     * \return A string containing the name "BeginMarkerReadError".
     */
    [[nodiscard]] inline const char* name() const noexcept final { return "BeginMarkerReadError"; }

    /*!
     * \brief Get a string describing the exception.
     * \return A string containing an error message indicating the failure to read the begin marker.
     */
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read the begin marker"; }

    //! Destructor
    ~BeginMarkerReadError() noexcept final = default;
};

#endif // PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
