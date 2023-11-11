#ifndef PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H

#include <base_exception.h>

class ParameterReadError final : public BaseException
{
public:
    [[nodiscard]] inline const char* name() const noexcept { return "ParameterReadError"; }
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read parameter"; }

    ~ParameterReadError() noexcept final = default;
};

#endif //PRE_DETECTOR_SIGNAL_PARAMETER_READ_ERROR_H
