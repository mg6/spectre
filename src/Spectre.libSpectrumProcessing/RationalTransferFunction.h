#pragma once
#include <span.h>
#include "DataTypes.h"

namespace Spectre::libSpectrumProcessing
{
class RationalTransferFunction
{
public:
    explicit RationalTransferFunction(gsl::span<const DataType> numerator);
    Signal Filter(const Signal& signal);
private:
    std::vector<DataType> m_Numerator;
};
}
