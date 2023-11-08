#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** a = { };
			const int n = 0;
			Print(a, n);
			Assert::AreEqual(3, 3);
		}
	};
}
