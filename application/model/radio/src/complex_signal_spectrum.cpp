#include <complex_signal_spectrum.h>


//! TODO выглядит крайне стремно :/
ComplexSpectrum::ComplexSpectrum(const std::vector<double> &signal) : _complex_spectrum(signal.size())
{
    _plan = fftw_plan_dft_r2c_1d(static_cast<int>(signal.size()),
                                 reinterpret_cast<double*>(const_cast<double*>(&signal[0])),
                                 reinterpret_cast<fftw_complex*>(&_complex_spectrum[0]),
                                 FFTW_ESTIMATE);
}
