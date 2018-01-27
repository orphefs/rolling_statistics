#include "rollingstats.h"
#include <deque>
#include <iostream>

RollingMean::RollingMean(std::size_t windowSize_t) : m_windowSize(windowSize_t)
{
}

void RollingMean::insertSample(float const &sample_t)
{
    m_newSample = sample_t;
    if (m_samples.size() < m_windowSize)
    {
        m_samples.push_back(sample_t);
        updateState();
    }
    else
    {
        m_samples.push_back(sample_t);
        m_samples.pop_front();
        updateState();
    }
}

float RollingMean::computeMean(std::deque<float> const &m_samples)
{
    float mean(0.0);

    for (auto it = m_samples.begin(); it != m_samples.end(); ++it)
    {
        mean += *it * (1.0 / m_samples.size());
    }
    return mean;
}

void RollingMean::updateState()
{
    // if (m_samples.size() < m_windowSize)
    // {
    m_newMean = RollingMean::computeMean(m_samples);
    // }
    // else
    // {
    //     m_newMean = m_oldMean + m_samples[m_windowSize] / m_windowSize - m_samples[0] / m_windowSize;
    // }
    m_oldMean = m_newMean;
}