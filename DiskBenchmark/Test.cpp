#include "Test.h"
#include <vector>
#include <fstream>
Test::Test(int threads) : threads(threads)
{

}

void Test::SetThreads(int count)
{
	this->threads = count;
}

size_t Test::CreateTestFile(const std::string& FileName, FileSizeType SizeType)
{

    std::vector<char>buffer(GetFileSize(SizeType));
    for (size_t i = 0; i < buffer.size(); i++)
    {
        buffer[i] = rand() % 256;
    }

    std::ofstream OutFile(FileName, std::ios::binary);
    OutFile.write(buffer.data(), buffer.size());
    OutFile.close();
    return buffer.size();
}

