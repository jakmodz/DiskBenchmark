#pragma once
#include "../DiskBenchmark/Benchmark.h"
class Application
{
public:
	void Run();


private:
	void DisplayResults(std::vector<TestResult>Results);
	Benchmark benchmark;
};

