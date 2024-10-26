#include "Application.h"

#include "iostream"
#include <iomanip>

void Application::Run()
{
	benchmark.Start();
	DisplayResults(benchmark.GetResults());
}

void Application::DisplayResults(std::vector<TestResult> Results)
{
    std::cout << std::left << std::setw(20) << "Test Type"
        << std::setw(15) << "Speed (MB/S)"
        << std::setw(15) << "Speed (S)"
        << std::setw(20) << "File Size Type"
        << std::setw(15) << "Thread Number" << std::endl;
    std::cout << std::string(80, '-') << std::endl; 

    for (auto& Result : Results) {
        std::cout << std::left << std::setw(20) << GetTestTypeString(Result.GetTestType())
            << std::setw(15) << GetFileSize(Result.GetFileSizeType())/(Result.GetSpeed() *1024*1024)
            << std::setw(15) << Result.GetSpeed()
            << std::setw(20) << GetFileSizeTypeString(Result.GetFileSizeType())
            << std::setw(15) << Result.GetThreadCount() << std::endl;
    }
	std::cout << "Time of all tests : " << benchmark.GetTimeOfAllTests()<<" seconds " << std::endl;
}
