#include "Benchmark.h"
#include "TimeGet.h"

const int sizes[] = { 1, 8, 16 };
Benchmark::Benchmark()
{

}

void Benchmark::Start()
{
	auto start = TimeGet::MeasuringTime();
	RunReadTest();
	RunModificationTest();
	RunDeletingTest();
	RunCopyingTest();
	SetTimeOfALlTests(TimeGet::CountTime(start, TimeGet::MeasuringTime()));
}

void Benchmark::SetTimeOfALlTests(double t)
{
	TimeOfAllTests = t;
}

void Benchmark::RunReadTest()
{
	for (int size : sizes)
	{
		for (size_t i = 1; i <= 3; i++)
		{
			Results.push_back(ReadTest(size).Start(static_cast<FileSizeType>(i)));
		}
	}
	
}

void Benchmark::RunModificationTest()
{
	for (int size : sizes)
	{
		for (size_t i = 1; i <= 3; i++)
		{
			Results.push_back(ModificationTest(size).Start(static_cast<FileSizeType>(i)));
		}
	}
}

void Benchmark::RunCopyingTest()
{
	for (int size : sizes)
	{
		for (size_t i = 1; i <= 3; i++)
		{
			Results.push_back(CopyingTest(size).Start(static_cast<FileSizeType>(i)));
		}
	}
}

void Benchmark::RunDeletingTest()
{

	for (int size : sizes)
	{
		for (size_t i = 1; i <= 3; i++)
		{
			Results.push_back(DeletingTest(size).Start(static_cast<FileSizeType>(i)));
		}
	}
}

double Benchmark::GetTimeOfAllTests()
{
	return TimeOfAllTests;
}

std::vector<TestResult>& Benchmark::GetResults()
{
    return Results;
}
