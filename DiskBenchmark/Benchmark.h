#pragma once
#include <vector>
#include "ReadTest.h"
#include "ModificationTest.h"
#include "DeletingTest.h"
#include "CopyingTest.h"
#include "TestResult.h"

class Benchmark
{
public:
	Benchmark();

	void Start();
	void SetTimeOfALlTests(double t);
	double GetTimeOfAllTests();
	std::vector<TestResult>& GetResults();
private:
	std::vector<TestResult>Results;
	double TimeOfAllTests;

	void RunReadTest();
	void RunModificationTest();
	void RunCopyingTest();
	void RunDeletingTest();
};

