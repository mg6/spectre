#pragma once
#include <vector>
#include "DataTypes.h"

namespace Spectre::libSpectrumProcessing
{
class MeanAbsoluteDeviationNoiseEstimator
{
public:
    explicit MeanAbsoluteDeviationNoiseEstimator(DataType multiplier);
    DataType Estimate(const Signal& intensities);
private:
    const DataType m_Multiplier;
};
}
