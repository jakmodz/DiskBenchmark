#pragma once
#include <string>


enum TestType
{
	Reading,
	Copying,
	Modification,
	Deleting
};
enum FileSizeType
{
	Small = 1,
	Medium = 2,
	Big = 3
};
long long GetFileSize(FileSizeType SizeType);
std::string GetTestTypeString(TestType testType);

std::string GetFileSizeTypeString(FileSizeType fileSizeType);

class TestResult
{
public:
	TestResult(double Speed, TestType Type, FileSizeType FileSizeType,int ThreadCount);
	double GetSpeed();
	TestType GetTestType();
	FileSizeType GetFileSizeType();
	int GetThreadCount();
private:
	double Speed;
	TestType Type;
	FileSizeType SizeType;
	int ThreadCount;
};

