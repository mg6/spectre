#include "DaubechiesFiltersDenoiser.h"

namespace Spectre::libSpectrumProcessing
{
DaubechiesFiltersDenoiser::DaubechiesFiltersDenoiser(NoiseEstimator noiseEstimator) :
    m_NoiseEstimator(std::move(noiseEstimator))
{
    // @gmrukwa: TODO: Add initialization of filter parameters here.
}

Signal DaubechiesFiltersDenoiser::Denoise(const Signal&)
{
    throw std::exception("Not implemented yet.");
}

}