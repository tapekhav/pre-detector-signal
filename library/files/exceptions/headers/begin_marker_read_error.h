#ifndef PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
#define PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H

#include <exception>

class BeginMarkerReadError final : public std::exception
{
public:
    [[nodiscard]] const char* what() const noexcept final { return "Failed to read the begin marker"; }

    [[nodiscard]] const char* name() const noexcept { return "BeginMarkerReadError"; }

    ~BeginMarkerReadError() noexcept final = default;
};
#endif //PRE_DETECTOR_SIGNAL_BEGIN_MARKER_READ_ERROR_H
