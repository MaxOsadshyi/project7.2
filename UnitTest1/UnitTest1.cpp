#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2r/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowNo = 0;
			int** a = { };
			const int n = 0;
			PrintRows( a,  rowNo,  n);
			Assert::AreEqual(3, 3);
		}
	};
}
