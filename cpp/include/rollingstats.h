#include <vector>
#include <deque>

class RollingMean
{
  public:
    RollingMean(std::size_t windowSize_t);
    static float computeMean(std::deque<float> const &m_samples);
    void insertSample(float const &sample_t);
    void isCumulativeMode();
    float getRollingMean() const { return m_newMean; };
    std::size_t getSize() const { return m_samples.size(); };
    float &operator[](int i) { return m_samples[i]; };

  private:
    void updateState();
    bool m_isCumulativeMode;
    std::size_t m_windowSize;
    std::deque<float> m_samples;
    float m_rollingMean;
    float m_oldMean;
    float m_newMean;
    float m_newSample;
    float m_oldSample;
};