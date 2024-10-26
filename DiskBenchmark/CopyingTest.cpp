#include "CopyingTest.h"
#include <vector>
#include <thread>
#include <fstream>
#include "TimeGet.h"
using namespace std;
CopyingTest::CopyingTest(int ThreadCount) : Test(ThreadCount)
{
    
}

TestResult CopyingTest::Start(FileSizeType SizeType)
{
    size_t FileSize = CreateTestFile(FILE_NAME,SizeType);
    long long ChunkSize = FileSize / threads;
    std::vector<std::thread> ThreadsBuffer;
    auto start = TimeGet::MeasuringTime();
    for (int i = 0; i < threads; ++i)
    {
        size_t start = i * ChunkSize;
        size_t  size = (i == threads - 1) ? (FileSize - start) : ChunkSize;
        thread thr([this, start, size]()
            {
                CopyChunk("test.txt", "source.txt", start, size);
            });
        ThreadsBuffer.push_back(std::move(thr));
    }
    for (std::thread& th : ThreadsBuffer)
    {
        th.join();
    }
    auto end = TimeGet::MeasuringTime();
    std::remove("test.txt");
    std::remove("source.txt");
    return TestResult(TimeGet::CountTime(start,end), TestType::Copying, SizeType, threads);
}

void CopyingTest::CopyChunk(const std::string& filename, const std::string& DestinatioFilename, size_t start, size_t size)
{
    fstream File(filename, std::ios::binary);
    fstream FileOut(DestinatioFilename, std::ios::binary);

    File.seekg(start);
    FileOut.seekp(start);

    std::vector<char> buffer(1024);

    size_t remaining = size;
    while(remaining > 0)
    {
        size_t readSize = std::min(static_cast<size_t>(buffer.size()), remaining);
        File.read(buffer.data(), readSize);
        FileOut.write(buffer.data(), readSize);
        remaining -= readSize;
    }

    File.close();
    FileOut.close();
}


