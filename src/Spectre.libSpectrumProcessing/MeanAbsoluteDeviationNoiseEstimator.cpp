#include "Spectre.libPlatform/Statistics.h"
#include "MeanAbsoluteDeviationNoiseEstimator.h"

namespace Spectre::libSpectrumProcessing
{
MeanAbsoluteDeviationNoiseEstimator::MeanAbsoluteDeviationNoiseEstimator(DataType multiplier) :
    m_Multiplier(multiplier)
{
    
}

DataType MeanAbsoluteDeviationNoiseEstimator::Estimate(const Signal& intensities) const
{
    constexpr auto locationOfThirdQuartileInNormalDistribution = static_cast<DataType>(.6745);
    return m_Multiplier
        * sqrt(2 * log(intensities.size()))
        * libPlatform::Statistics::MeanAbsoluteDeviation(gsl::as_span(intensities))
        / locationOfThirdQuartileInNormalDistribution;
}
}