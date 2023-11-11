#include <binary_file_manager.h>

BinaryFileManager::BinaryFileManager(const std::string &file_name)
                                     : _file(file_name,
                                             std::ios::binary)
{
    assert(_file.is_open());
}

void BinaryFileManager::setStartFrameMarker(size_t number, double time_step)
{
    std::bitset<12> bits("111111000000");
    _file << bits.to_string();

    std::bitset<8> number_bits_set(number);
    std::bitset<32> time_step_bits_set(*reinterpret_cast<uint32_t*>(&time_step));

    _file << number_bits_set << time_step_bits_set;
}

void BinaryFileManager::writeBitset(const bitset_sequence &number)
{
    std::for_each(number.begin(), number.end(), [&](std::bitset<14> bits) { _file << bits.to_string(); });
}

void BinaryFileManager::addSynchronize()
{
    std::bitset<15> syn("111100010011010");
    _file << syn.to_string();
}
