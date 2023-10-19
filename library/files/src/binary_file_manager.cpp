#include <binary_file_manager.h>

BinaryFileManager::BinaryFileManager(const std::string &file_name)
        : _file(file_name, std::ios::binary) { assert(_file.is_open()); }

void BinaryFileManager::setStartFrameMarker(size_t number, double time_step)
{
    std::bitset<11> bits("11111100000");
    _file << bits.to_string();

    std::bitset<8> number_bits_set(number);
    std::bitset<32> time_step_bits_set(*reinterpret_cast<uint32_t*>(&time_step));

    _file << number_bits_set << time_step_bits_set;
}
