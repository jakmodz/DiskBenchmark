#pragma once
#include "Test.h"
class ModificationTest : public Test
{
public:
	ModificationTest(int ThreadCount);

	TestResult Start(FileSizeType SizeType) override;
private:


	void ModifyChunk(const std::string& filename, size_t start, size_t size);
};

