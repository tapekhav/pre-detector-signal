#include <file_reader.h>
#include <cassert>

FileReader::FileReader(const std::string &file_name) : _file(file_name, std::ios::binary) { assert(_file.is_open()); }

void FileReader::setStartFrameMarker(size_t number, double time_step)
{

}



