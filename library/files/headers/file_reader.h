#ifndef PRE_DETECTOR_SIGNAL_FILE_READER_H
#define PRE_DETECTOR_SIGNAL_FILE_READER_H

#include <string>
#include <fstream>
#include <cassert>

#include <spdlog/spdlog.h>

#include <library_consts.h>
#include <base_component.h>

/*!
 * \class FileReader
 * \brief A class responsible for reading and parsing data frames from a binary file.
 *
 * This class provides methods to read various components of a data frame, including synchronization markers,
 * start frame markers, and parameter information. It follows the RAII (Resource Acquisition Is Initialization)
 * principle to ensure proper file closure when the object goes out of scope.
 */
class FileReader final : public BaseComponent
{
public:
    /*!
     * \name Destructor
     * \brief Constructs a FileReader object, opening the specified file for reading.
     *
     * \param file_name The name of the file to be read. Defaults to "result.bin".
     */
    explicit FileReader(const std::string& file_name = file_consts::kPath);

    /*!
     * \brief Reads and parses all data from the file.
     *
     * \return True if reading is successful, false otherwise.
     */
    void readAllFile();

    /*!
     * \brief Gets the information about the currently read data frame.
     *
     * \return A string containing information about the current frame.
     */
    [[nodiscard]] std::string getFileInfo() const { return _current_frame; }

    /*!
     * \name Destructor
     * \brief Destructor responsible for closing the file.
     */
    ~FileReader();

private:
    /*!
     * \brief Reads information about all parameters in a data frame.
     */
    void readAllParams();

    /*!
     * \brief Reads synchronization information from the file.
     */
    void readSync();

    /*!
     * \brief Reads a parameter from the file.
     *
     * \return True if the parameter is successfully read, false otherwise.
     */
    bool readParam();

    /*!
     * \brief Reads the beginning of a data frame.
     */
    void readBeginningOfFrame();

    /*!
     * \brief Reads the begin marker of a data frame.
     */
    void readBeginMarker();

    /*!
     * \brief Reads general information about a data frame.
     */
    void readInformationAboutFrame();

    /*!
     * \brief Reads and parses a data frame from the file.
     *
     * \return True if reading is successful, false otherwise.
     */
    bool readFrame();

private:
    //! The number of characters read during file operations.
    size_t _char_read;
    //! The managed fstream object for file reading.
    std::fstream _file;
    //! Information about the currently read data frame.
    std::string _current_frame;

    //! Logger for internal logging.
    std::unique_ptr<spdlog::logger> _logger;
};

#endif //! PRE_DETECTOR_SIGNAL_FILE_READER_H
