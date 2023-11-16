#include <binary_file_manager.h>
#include <full_encode_number.h>

BinaryFileManager::BinaryFileManager(const std::string &file_name)
                                     : _file(file_name)
{
    assert(_file.is_open());
}

void BinaryFileManager::setStartFrameMarker(size_t number, const bitset_sequence& time_step)
{
    _file << markers::kBeginMarker;

    std::bitset<param_consts::kSizeInt> number_bits_set(number);
    _file << number_bits_set;

    writeBitset(time_step);
}

void BinaryFileManager::writeBitset(const bitset_sequence &number)
{
    std::for_each(number.begin(), number.end(), [&](std::bitset<param_consts::kSizeBitset> bits) { _file << bits.to_string(); });
}

void BinaryFileManager::addSynchronize()
{
    _file << markers::kSyncMarker;
}

BinaryFileManager::~BinaryFileManager()
{
    _file.close();
}
