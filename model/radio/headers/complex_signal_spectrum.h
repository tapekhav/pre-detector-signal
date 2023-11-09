#ifndef PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H
#define PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H

#include <vector>
#include <complex>

#include <fftw3.h>

/*!
 * \typedef complex
 * \brief Typedef for a complex number using the std::complex<double> type.
 */
using complex = std::complex<double>;

/*!
 * \class ComplexSpectrum
 * \brief Calculates the complex spectrum of a given signal using FFTW library.
 *
 * The ComplexSpectrum class uses the FFTW library to perform a real-to-complex FFT
 * on the input signal, providing the complex spectrum of the signal.
 */
class ComplexSpectrum
{
public:
    /*!
     * \brief Constructor.
     *
     * \param signal The input signal for which the complex spectrum is to be calculated.
     */
    explicit ComplexSpectrum(const std::vector<double>& signal);
    /*!
     * \brief Destructor.
     *
     * Frees the FFTW plan.
     */
    ~ComplexSpectrum() { fftw_destroy_plan(_plan); }

    /*!
     * \brief Calculates the complex spectrum.
     */
    inline void calculateComplexSpectrum() { fftw_execute(_plan); }

    /*!
     * \brief Getter for the calculated complex spectrum.
     *
     * \return A vector of complex numbers representing the complex spectrum.
     */
   [[nodiscard]] inline std::vector<complex> getComplexSpectrum() const { return _complex_spectrum; }
private:
    //! Vector to store the calculated complex spectrum.
    std::vector<complex> _complex_spectrum;
   //! FFTW plan for performing the real-to-complex FFT.
    fftw_plan _plan;
};

#endif //PRE_DETECTOR_SIGNAL_COMPLEX_SIGNAL_SPECTRUM_H
