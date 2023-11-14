#ifndef PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H
#define PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H

#include <exception>

class BaseException : public std::exception
{
public:
    [[nodiscard]] virtual const char* name() const noexcept { return "BaseException"; }
    [[nodiscard]] const char* what() const noexcept override { return "Something wrong"; }

    ~BaseException() noexcept override = default;
};

#endif //PRE_DETECTOR_SIGNAL_MY_EXCEPTION_H
