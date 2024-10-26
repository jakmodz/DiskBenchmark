#include "TimeGet.h"

boost::chrono::steady_clock::time_point TimeGet::MeasuringTime()
{
    return  boost::chrono::steady_clock::now();
}

double TimeGet::CountTime(boost::chrono::steady_clock::time_point start, boost::chrono::steady_clock::time_point end)
{
    boost::chrono::duration<double> elapsed_time = end - start;
    return elapsed_time.count();
}
