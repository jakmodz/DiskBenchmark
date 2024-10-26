#pragma once
#include "Test.h"

class ReadTest : public Test
{
public:
	ReadTest(int ThreadCount);

	TestResult Start(FileSizeType SizeType) override;
private:
	void ReadChunk(const std::string& filename,size_t start,size_t end);
};

