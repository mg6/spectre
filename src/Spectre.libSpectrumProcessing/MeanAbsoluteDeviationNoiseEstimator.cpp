#include "MeanAbsoluteDeviationNoiseEstimator.h"

namespace Spectre::libSpectrumProcessing
{
MeanAbsoluteDeviationNoiseEstimator::MeanAbsoluteDeviationNoiseEstimator(DataType multiplier) :
    m_Multiplier(multiplier)
{
    
}

DataType MeanAbsoluteDeviationNoiseEstimator::Estimate(const Signal& intensities)
{
    throw std::exception("Not implemented yet.");
}

}