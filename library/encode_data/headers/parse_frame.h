#ifndef PRE_DETECTOR_SIGNAL_PARSE_FRAME_H
#define PRE_DETECTOR_SIGNAL_PARSE_FRAME_H

#include <vector>
#include <string>
#include <memory>

#include <full_decode_number.h>

namespace spdlog
{
    class logger;
}

class ParseFrame
{
public:
    explicit ParseFrame(double sample_step);

    bool tryToParseFrame(std::string frame);

    void tryToParseBeginMarker();

    double tryToParseParameter();

    void tryToParseSync();

    void tryToParseAllParams();

    [[nodiscard]] inline double getTime() const { return _time; }
    [[nodiscard]] inline size_t getNumberFrame() const { return _number_frame; }
    [[nodiscard]] inline std::vector<double> getParams() const { return _params; }
private:
    std::string _frame;
    size_t _current_sym;
    std::vector<double> _params;

    size_t _number_frame;
    double _time;
    double _sample_step;

    std::unique_ptr<spdlog::logger> _logger;
};

#endif //PRE_DETECTOR_SIGNAL_PARSE_FRAME_H
