#ifndef PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H

#include <base_exception.h>

/*!
 * \class ParameterReadError
 * \brief Exception class for errors encountered while reading parameters.
 *
 * This class inherits from the BaseException class and is used to indicate errors
 * related to the read operation of parameters.
 */
class ParameterReadError final : public BaseException
{
public:
    /*!
     * \brief Get the name of the exception.
     * \return A string containing the name "ParameterReadError".
     */
    [[nodiscard]] inline const char* name() const noexcept final { return "ParameterReadError"; }

    /*!
     * \brief Get a string describing the exception.
     * \return A string containing an error message indicating the failure to read a parameter.
     */
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read parameter"; }

    //! Destructor
    ~ParameterReadError() noexcept final = default;
};

#endif //PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H
