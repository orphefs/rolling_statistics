#include <vector>
#include <deque>

class RollingMean
{
  public:
    RollingMean(std::size_t windowSize_t);
    void insertSample(float const &sample_t);
    std::size_t getSize() const { return m_samples.size(); };
    float &operator[](int i) { return m_samples[i]; };

  private:
    void updateState();
    std::size_t m_windowSize;
    std::deque<float> m_samples;
    float m_rollingMean;
    float m_newSample;
    float m_oldSample;
};