#ifndef PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H
#define PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H

#include <exception>

/*!
 * \class BaseException
 * \brief The base class for custom exceptions in the pre-detector signal application.
 *
 * This class inherits from std::exception and serves as the base class for custom exceptions.
 */
class BaseException : public std::exception
{
public:
    /*!
     * \brief Get the name of the exception.
     * \return A string containing the name of the exception.
     */
    [[nodiscard]] virtual const char* name() const noexcept { return "BaseException"; }

    /*!
     * \brief Get a string describing the exception.
     * \return A string containing a description of the exception.
     */
    [[nodiscard]] const char* what() const noexcept override { return "Something wrong"; }

    //! Destructor
    ~BaseException() noexcept override = default;
};

#endif //PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H
