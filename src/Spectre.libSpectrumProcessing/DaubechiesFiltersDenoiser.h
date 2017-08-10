#pragma once
#include <memory>
#include "DataTypes.h"
#include "Spectre.libSpectrumProcessing/MeanAbsoluteDeviationNoiseEstimator.h"

namespace Spectre::libSpectrumProcessing
{
class DaubechiesFiltersDenoiser
{
public:
    using NoiseEstimator = std::unique_ptr<MeanAbsoluteDeviationNoiseEstimator>;
    explicit DaubechiesFiltersDenoiser(NoiseEstimator noiseEstimator);
    Signal Denoise(const Signal& singal);
private:
    static constexpr unsigned m_Base = 4;
    static constexpr unsigned m_LevelsOfDecomposition = 10;
    const NoiseEstimator m_NoiseEstimator;
};
}
