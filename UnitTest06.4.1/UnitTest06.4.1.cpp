#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab6.4.1/ChyrunSofialab6.4.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest0641
{
	TEST_CLASS(UnitTest0641)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int n = 6, C=3;
			double a[n] = { 1,2,3,4,5,6 };
			t = Count(a, n, C);
			Assert::AreEqual(t, 2);
		}
	};
}
