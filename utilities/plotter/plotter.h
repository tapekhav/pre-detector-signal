#ifndef MLAT_PLOTTER_H
#define MLAT_PLOTTER_H

#include <fstream>
#include <string>
#include <cassert>

/*! \class Plotter
*   \brief Converts data to file.
* 	It translates the data needed to build a graph into some file.
* 	Then the script that launches the chart is manually launched.
*/
class Plotter
{
public:
    //! Constructor
    inline explicit Plotter(const std::string& filepath) : _file(new std::ofstream(filepath)) {}
    //! Destructor
    inline ~Plotter() { delete _file; }
    //! Insert point to the file
    void addPoint(double x, double y, double z)
    {
        assert(_file->is_open());
        (*_file) << x << ' ' << y << ' ' << z << std::endl;
    }

private:
    //! Result file with points
    std::ofstream* _file;
};
#endif