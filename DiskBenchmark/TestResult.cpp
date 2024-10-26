#include "TestResult.h"



TestResult::TestResult(double Speed, TestType Type, FileSizeType FileSizeType, int ThreadCount): Speed(Speed),Type(Type),
SizeType(FileSizeType),ThreadCount(ThreadCount)
{
}

double TestResult::GetSpeed()
{
	return Speed;
}

TestType TestResult::GetTestType()
{
	return Type;
}

FileSizeType TestResult::GetFileSizeType()
{
	return SizeType;
}

int TestResult::GetThreadCount()
{
	return ThreadCount;
}

long long GetFileSize(FileSizeType SizeType)
{
	switch (SizeType)
	{
	case Small: 
	{
		return  1* 1024 * 1024;
	}
		break;
	case Medium:
	{
		return 100 * 1024 * 1024;
	}
		break;
	case Big:
		return 1000 * 1024 * 1024;
		break;
	}
}

std::string GetTestTypeString(TestType testType)
{
	switch (testType)
	{
	case Reading:
		return std::string("reading");
		break;
	case Copying:
		return std::string("copying");
		break;
	case Modification:
		return std::string("modification");
		break;
	case Deleting:
		return std::string("deleting");
		break;
	default:
		break;
	}
}

std::string GetFileSizeTypeString(FileSizeType fileSizeType)
{
	
		switch (fileSizeType)
		{
		case Small:
			return std::string("small");
			break;
		case Medium:
			return std::string("medium");
			break;
		case Big:
			return std::string("big");
			break;

		}
}
