#pragma once
#include "Test.h"
class CopyingTest : public Test
{
public:
	CopyingTest(int ThreadCount);

	TestResult Start(FileSizeType SizeType) override;
private:
	void CopyChunk(const std::string& filename, const std::string& DestinatioFilename, size_t start, size_t size);
};

