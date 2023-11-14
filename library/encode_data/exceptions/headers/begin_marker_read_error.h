#ifndef PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H

#include <base_exception.h>

class BeginMarkerReadError final : public BaseException
{
public:
    [[nodiscard]] inline const char* name() const noexcept final { return "BeginMarkerReadError"; }
    [[nodiscard]] inline const char* what() const noexcept final { return "Failed to read the begin marker"; }

    ~BeginMarkerReadError() noexcept final = default;
};

#endif //PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
