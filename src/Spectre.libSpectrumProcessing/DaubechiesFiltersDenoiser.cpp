#include "DaubechiesFiltersDenoiser.h"

namespace Spectre::libSpectrumProcessing
{
DaubechiesFiltersDenoiser::DaubechiesFiltersDenoiser(MeanAbsoluteDeviationNoiseEstimator &&noiseEstimator) :
    m_NoiseEstimator(noiseEstimator)
{
    // @gmrukwa: TODO: Add initialization of filter parameters here.
}

Signal DaubechiesFiltersDenoiser::Denoise(const Signal& singal)
{
    throw std::exception("Not implemented yet.");
}

}