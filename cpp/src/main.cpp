#include <iostream>
#include "timeseries.h"
#include "rollingstats.h"

int main()
{

    std::cout << "Hello World" << std::endl;
    std::vector<float> sampleData{1.0, 2.0, 3.0};
    TimeSeries myTimeSeries(sampleData);
    std::vector<float> sampleData1 = myTimeSeries.getTimeseries();


    RollingMean myRollingMean(std::size_t{4});
    myRollingMean.insertSample(1.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;    
    myRollingMean.insertSample(2.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;
    myRollingMean.insertSample(3.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;    
    myRollingMean.insertSample(4.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;
    myRollingMean.insertSample(5.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;
    myRollingMean.insertSample(6.0);
    std::cout << myRollingMean.getRollingMean() << std::endl;
    
    
    


    return 0;
}