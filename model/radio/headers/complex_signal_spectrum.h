#ifndef PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H
#define PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H

#include <vector>
#include <complex>

#include <fftw3.h>

using complex = std::complex<double>;

class ComplexSpectrum
{
public:
    explicit ComplexSpectrum(const std::vector<double>& signal);
    ~ComplexSpectrum() { fftw_destroy_plan(_plan); }

    inline void calculateComplexSpectrum() { fftw_execute(_plan); }

   [[nodiscard]] inline std::vector<complex> getComplexSpectrum() const { return _complex_spectrum; }
private:
    std::vector<complex> _complex_spectrum;
    fftw_plan _plan;
};

#endif //PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H
