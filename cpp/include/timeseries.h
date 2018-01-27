#include <vector>

class TimeSeries final
{
  public:
    TimeSeries(std::vector<float> const & timeSeries_t);
    std::vector<float> getTimeseries() const { return m_timeSeries; };
  private:
    std::vector<float> m_timeSeries;
};