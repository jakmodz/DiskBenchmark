#pragma once
#include <boost/chrono.hpp>
class TimeGet
{
public:
	static boost::chrono::steady_clock::time_point MeasuringTime();
	static double CountTime(boost::chrono::steady_clock::time_point start, boost::chrono::steady_clock::time_point end);
};

