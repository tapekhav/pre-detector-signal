#include <file_reader.h>

#include <iostream>

bool FileReader::readFrame()
{
    std::string file_data;
    _file >> file_data;

    size_t length = file_data.length();
    if (length != 11)
    {
        return false;
    }

    for (size_t i = 0; i < length; ++i)
    {
       // if ()
    }
}
