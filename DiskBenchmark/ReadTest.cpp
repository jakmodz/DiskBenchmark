#include "ReadTest.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <thread>
#include <cstdio>
#include "TimeGet.h"

using namespace std;
ReadTest::ReadTest(int ThreadCount) : Test(ThreadCount)
{
}

TestResult ReadTest::Start(FileSizeType SizeType)
{
   
    size_t FileSize = CreateTestFile(FILE_NAME,SizeType);
    long long ChunkSize = FileSize / threads;
    std::vector<std::thread> ThreadsBuffer;
    auto start = TimeGet::MeasuringTime();
    for (int i = 0; i < threads; ++i) 
    {   
        size_t start = i * ChunkSize;
        size_t  size = (i == threads - 1) ? (FileSize - start) : ChunkSize;
        thread thr([this, start, size]() {
            ReadChunk("test.txt", start, size);
            });
        ThreadsBuffer.push_back(std::move(thr));
    }
    for (std::thread& th : ThreadsBuffer)
    {
        th.join();
    }
    auto end = TimeGet::MeasuringTime();
    std::remove("text.txt");
    return TestResult(TimeGet::CountTime(start,end), TestType::Reading, SizeType, threads);
}

void ReadTest::ReadChunk(const std::string& filename, size_t start, size_t end)
{
    std::ifstream File(filename, std::ios::binary);

    File.seekg(start);

    std::vector<char> buffer(1024); 

    size_t remaining = end;
    while (remaining > 0) 
    {
        size_t readSize = std::min(static_cast<size_t>(buffer.size()), remaining);
        File.read(buffer.data(), readSize);
        remaining -= readSize;
    }
    File.close();
}


