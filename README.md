# Rolling Statistics

I am deriving an expression for the rolling mean and
variance of a discrete time series, which is useful for online applications, where limited
computational resources don’t allow the computation of the mean every time a new
data point is received. This approach considers that the rolling mean and variance
are computed with one incoming data point on every update, but can be extended to
consider multiple data points at once.

The full derivation can be found [here](https://github.com/orphefs/rolling_statistics/blob/9a49f341c27bbea2382a85d9244547f7a7dcd824/Rolling_Mean_and_Variance_of_a_Time_Series.pdf).

A demonstration of the algorithm in Python can be found [here](https://github.com/orphefs/rolling_statistics/blob/master/python/main.py).

The source code in C++ can be found [here](https://github.com/orphefs/rolling_statistics/tree/master/cpp).
