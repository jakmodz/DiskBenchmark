#include "ModificationTest.h"
#include <fstream>
#include <vector>
#include <thread>
#include "TimeGet.h"
using namespace std;
ModificationTest::ModificationTest(int ThreadCount) : Test(ThreadCount)
{
}

TestResult ModificationTest::Start(FileSizeType SizeType)
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
            ModifyChunk("test.txt", start, size);
            });
        ThreadsBuffer.push_back(std::move(thr));
    }
    for (std::thread& th : ThreadsBuffer)
    {
        th.join();
    }
    auto end = TimeGet::MeasuringTime();
    std::remove("test.txt");
    return TestResult(TimeGet::CountTime(start,end), TestType::Modification, SizeType, threads);
}

void ModificationTest::ModifyChunk(const std::string& filename, size_t start, size_t size)
{
    fstream File(filename, std::ios::binary);

    File.seekp(start);

    std::vector<char> buffer(4096, 'X');

    size_t remaining = size;

    while (remaining > 0)
    {
        size_t writeSize = std::min(static_cast<size_t>(buffer.size()), remaining);
        File.write(buffer.data(), writeSize);
        remaining -= writeSize;
    }
    File.close();
}
