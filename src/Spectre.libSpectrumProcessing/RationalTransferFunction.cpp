#include "RationalTransferFunction.h"

namespace Spectre::libSpectrumProcessing
{
RationalTransferFunction::RationalTransferFunction(gsl::span<const DataType> numerator)
    : m_Numerator(numerator.begin(), numerator.end())
{
    
}

Signal RationalTransferFunction::Filter(const Signal &signal)
{
    std::vector<DataType> filtered(signal.size());
    for(unsigned n = 0u; n < signal.size(); ++n)
    {
        for (unsigned i = 0u; i < m_Numerator.size() && static_cast<int>(n) - static_cast<int>(i) >= 0; ++i)
        {
            filtered[n] += m_Numerator[i] * signal[n - i];
        }
    }
    return filtered;
}
}
