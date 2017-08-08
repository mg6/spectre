#pragma once
#include <vector>
#include "DataTypes.h"
#include "Spectre.libSpectrumProcessing/MeanAbsoluteDeviationNoiseEstimator.h"

namespace Spectre::libSpectrumProcessing
{
class DaubechiesFiltersDenoiser
{
public:
    explicit DaubechiesFiltersDenoiser(MeanAbsoluteDeviationNoiseEstimator&& noiseEstimator);
    Signal Denoise(const Signal& singal);
private:
    const unsigned m_Base = 4;
    const unsigned m_LevelsOfDecomposition = 10;
    const MeanAbsoluteDeviationNoiseEstimator m_NoiseEstimator;
};
}
