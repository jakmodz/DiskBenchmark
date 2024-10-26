#pragma once
#include "Test.h"
class DeletingTest : public Test 
{
public:
	DeletingTest(int ThreadCount);

	TestResult Start(FileSizeType SizeType) override;
private:
	void DeleteFile(const std::string FileName);
};

