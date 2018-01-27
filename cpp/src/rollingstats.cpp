#include "rollingstats.h"
#include <deque>
#include <iostream>

RollingMean::RollingMean(std::size_t windowSize_t) : m_windowSize(windowSize_t)
{
}

void RollingMean::isCumulativeMode()
{
    m_isCumulativeMode = m_samples.size() < m_windowSize;
    std::cout << "is cumulative: " << m_isCumulativeMode << std::endl;
}

void RollingMean::insertSample(float const &sample_t)
{
    m_newSample = sample_t;
    isCumulativeMode();
    if (m_isCumulativeMode)
    {
        m_samples.push_back(sample_t);
    }
    else
    {
        m_samples.push_back(sample_t);
        m_oldSample = m_samples[0];
        m_samples.pop_front();
    }
    updateState();
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
    if (m_isCumulativeMode)
    {
        m_newMean = RollingMean::computeMean(m_samples);
        std::cout << "New Mean: " << m_newMean << std::endl;
    }
    else
    {
        m_newMean = m_oldMean + (m_newSample / m_windowSize) - (m_oldSample / m_windowSize);
        std::cout << "New Mean: "  << m_newMean << "=" << m_oldMean << "+" << m_newSample << "/" << m_windowSize << "-" << m_oldSample << "/" << m_windowSize << std::endl;
    }
    m_oldMean = m_newMean;
}