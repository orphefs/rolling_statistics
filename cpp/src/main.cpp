#include <iostream>
#include "timeseries.h"
#include "rollingstats.h"

int main()
{

    std::cout << "Hello World" << std::endl;
    std::vector<float> sampleData{1.0, 2.0, 3.0};
    TimeSeries myTimeSeries(sampleData);
    std::vector<float> sampleData1 = myTimeSeries.getTimeseries();
    for (auto it = sampleData1.begin(); it != sampleData1.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << myTimeSeries[0] << std::endl;

    RollingMean myRollingMean(std::size_t{42});
    myRollingMean.insertSample(3.0);

    return 0;
}