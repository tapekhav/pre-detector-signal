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

/*!
 * \brief A class responsible for parsing a data frame and extracting relevant information.
 *
 * This class provides functionality to get from string a data frame, extracting time, frame number,
 * and parameters.
 */
class ParseFrame
{
public:
    /*!
     * \name Constructor
     * \brief Constructs a ParseFrame object with a given sample step.
     * \param sample_step The time step between samples in the data frame.
     */
    explicit ParseFrame(double sample_step);

    /*!
     * \brief Attempts to parse the entire data frame.
     * \param frame The data frame to be parsed.
     * \return True if the parsing is successful, false otherwise.
     */
    bool tryToParseFrame(std::string frame);

    //! Attempts to parse the beginning marker of a data frame.
    void tryToParseBeginMarker();

    /*!
     * \brief Attempts to parse a parameter from the data frame.
     * \return The parsed parameter value.
     */
    double tryToParseParameter();

    /*!
     * \brief Attempts to parse synchronization information from the data frame.
     */
    void tryToParseSync();

    /*!
     * \brief Attempts to parse all parameters from the data frame.
     */
    void tryToParseAllParams();

    /*!
     * \brief Gets the time value extracted from the parsed data frame.
     *
     * \return The extracted time value.
     */
    [[nodiscard]] inline double getTime() const { return _time; }

    /*!
     * \brief Gets the frame number extracted from the parsed data frame.
     *
     * \return The extracted frame number.
     */
    [[nodiscard]] inline size_t getNumberFrame() const { return _number_frame; }

    /*!
     * \brief Gets the parameters extracted from the parsed data frame.
     *
     * \return The extracted parameters as a vector of doubles.
     */
    [[nodiscard]] inline std::vector<double> getParams() const { return _params; }
private:
    //! The data frame being parsed.
    std::string _frame;
    //! The current position in the data frame during parsing.
    size_t _current_sym;
    //! The extracted parameters from the data frame.
    std::vector<double> _params;

    //! The extracted frame number.
    size_t _number_frame;
    //! The extracted time value.
    double _time;
    //! The time step between samples in the data frame.
    double _sample_step;

    //! Logger for internal logging.
    std::unique_ptr<spdlog::logger> _logger;
};

#endif //PRE_DETECTOR_SIGNAL_PARSE_FRAME_H
