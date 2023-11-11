#ifndef PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H

#include <base_exception.h>

class InformationMarkerReadError final : public BaseException
{
public:
    [[nodiscard]] inline const char* name() const noexcept { return "InformationMarkerReadError"; }
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read the information about marker"; }

    ~InformationMarkerReadError() noexcept final = default;
};

#endif //PRE_DETECTOR_SIGNAL_INFORMATION_MARKER_READ_ERROR_H
