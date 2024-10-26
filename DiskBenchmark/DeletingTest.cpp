#include "DeletingTest.h"
#include "TimeGet.h"
#include <thread>
#include <fstream>
#include <vector>
#include <filesystem>
using namespace std;
DeletingTest::DeletingTest(int ThreadCount) : Test(ThreadCount)
{
}

TestResult DeletingTest::Start(FileSizeType SizeType)
{
	
	
    CreateTestFile(FILE_NAME , SizeType);
    fstream Src(FILE_NAME);
    for (int i = 1; i < threads; i++)
    {
        fstream Dst(FILE_NAME + char(i + 48));
        Dst << Src.rdbuf();
        Dst.close();
    }
    Src.close(); 
    std::vector<std::thread> ThreadsBuffer;
    auto start = TimeGet::MeasuringTime();
    for (int i = 0; i < threads; ++i)
    {
        
        
        thread thr([this, i]() 
            {
           DeleteFile(FILE_NAME + char(i+48));
            });
        ThreadsBuffer.push_back(std::move(thr));
    }
    for (std::thread& th : ThreadsBuffer)
    {
        th.join();
    }
    auto end = TimeGet::MeasuringTime();
    return TestResult(TimeGet::CountTime(start,end), TestType::Deleting, SizeType, threads);
}

void DeletingTest::DeleteFile(const std::string FileName)
{
    std::remove(FileName.c_str());
}
