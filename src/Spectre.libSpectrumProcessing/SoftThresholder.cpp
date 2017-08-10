#include "Spectre.libPlatform/Functional.h"
#include "SoftThresholder.h"

namespace Spectre::libSpectrumProcessing
{
SoftThresholder::SoftThresholder(DataType threshold)
    : m_Threshold(threshold)
{
    
}


Signal SoftThresholder::operator()(const Signal &signal) const
{
    const auto& threshold = m_Threshold;
    const auto thresholding = [threshold](DataType value)
    {
        return std::max(static_cast<DataType>(0), std::abs(value) - threshold) * (value < 0 ? -1 : 1);
    };
    return libPlatform::Functional::transform(gsl::as_span(signal), thresholding);
}

}
