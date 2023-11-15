#include <binary_file_manager.h>
#include <full_encode_number.h>

BinaryFileManager::BinaryFileManager(const std::string &file_name)
                                     : _file(file_name)
{
    assert(_file.is_open());
}

void BinaryFileManager::setStartFrameMarker(size_t number, double time_step)
{
    _file << "111111000000";

    std::bitset<32> number_bits_set(number);

    _file << number_bits_set;

    //! TODO костыль(хуета) ну да бля реально же хуетень
    auto num = EncodeData(time_step).execute();
    writeBitset(num);
}

void BinaryFileManager::writeBitset(const bitset_sequence &number)
{
    std::for_each(number.begin(), number.end(), [&](std::bitset<14> bits) { _file << bits.to_string(); });
}

void BinaryFileManager::addSynchronize()
{
    _file << "111100010011010";
}

BinaryFileManager::~BinaryFileManager()
{
    _file.close();
}
