#include <iostream>
#include "timeseries.h"

int main()
{

    std::cout << "Hello World" << std::endl;
    std::vector<float> sampleData{1.0,2.0,3.0};
    TimeSeries myTimeSeries(sampleData);
    std::vector<float> sampleData1 =  myTimeSeries.getTimeseries();
    for (auto it = sampleData1.begin(); it != sampleData1.end(); it++){
        std::cout << *it << std::endl;
    }

    return 0;
}