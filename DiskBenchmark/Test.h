#pragma once
#include "TestResult.h"
const std::string FILE_NAME = "test.txt";
class Test
{
public:
	virtual TestResult Start(FileSizeType SizeType) = 0;
protected:

	Test(int threads = 1);


	void SetThreads(int count);
	size_t CreateTestFile(const std::string& FileName ,FileSizeType SizeType);
	int threads;
};

