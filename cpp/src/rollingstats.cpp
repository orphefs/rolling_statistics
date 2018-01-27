#include "rollingstats.h"
#include <deque>

RollingMean::RollingMean(std::size_t windowSize_t) : m_windowSize(windowSize_t)
{
}

void RollingMean::insertSample(float const &sample_t)
{
    if (m_samples.size() < m_windowSize)
    {
        m_samples.push_back(sample_t);
    }
    else
    {
        m_samples.push_back(sample_t);
        m_samples.pop_front();
    }
}
