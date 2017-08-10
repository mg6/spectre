#pragma once
#include "DataTypes.h"

namespace Spectre::libSpectrumProcessing
{
class SoftThresholder
{
public:
    explicit SoftThresholder(DataType threshold);
    Signal operator()(const Signal& signal) const;
private:
    const DataType m_Threshold;
};
}
