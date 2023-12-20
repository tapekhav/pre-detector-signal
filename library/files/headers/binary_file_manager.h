#ifndef PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
#define PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H

#include <fstream>
#include <cassert>
#include <algorithm>

#include <library_consts.h>
#include <base_component.h>


/*!
 * \class BinaryFileManager
 * \brief A class responsible for writing info in file.
 *
 * This class facilitates writing binary data to a file, including synchronization markers
 * and start frame markers. It follows the RAII (Resource Acquisition Is Initialization) principle
 * to ensure proper file closure when the object goes out of scope.
 */
class BinaryFileManager final : public BaseComponent
{
public:
    /*!
     * \name Constructor
     * \brief Constructor responsible for opening the file.
     */
    explicit BinaryFileManager(const std::string& file_name = file_consts::kPath);

    /*!
     * \brief Adds a synchronization marker to the binary file.
     */
    void addSynchronize();

    /*!
     * \brief Sets a start frame marker with the given frame number and time step.
     *
     * \param number The frame number for the start marker.
     * \param time_step The time step represented as a bitset sequence.
     */
    void setStartFrameMarker(size_t number, const bitset_sequence& time_step);

    /*!
     * \brief Writes a bitset sequence to the binary file.
     *
     * \param number The bitset sequence to be written.
     */
    void writeBitset(const bitset_sequence& number);

    /*!
     * \name Destructor
     * \brief Destructor responsible for closing the file.
     */
    ~BinaryFileManager();

private:
    //! The managed fstream object for binary file operations.
    std::ofstream _file;
};

#endif //PRE_DETECTOR_SIGNAL_BINARY_FILE_MANAGER_H
