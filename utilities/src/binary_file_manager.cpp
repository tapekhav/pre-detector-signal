#include <binary_file_manager.h>

BinaryFileManager::BinaryFileManager(const std::string &file_name)
        : _file(file_name, std::ios::binary) { assert(_file.is_open()); }

void BinaryFileManager::setStartFrameMarker(size_t number, double time_step)
{
    _file.write(reinterpret_cast<const char*>(&consts::marker::startFrameMarker),
                sizeof(consts::marker::startFrameMarker));
    _file.write(reinterpret_cast<char*>(&number), sizeof(number));
    _file.write(reinterpret_cast<char*>(&time_step), sizeof(time_step));
}
