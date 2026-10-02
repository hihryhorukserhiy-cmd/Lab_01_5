#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_1_5/Triad.h"
#include "../lab_1_5/Triad.cpp"
#include "../lab_1_5/Data.h"
#include "../lab_1_5/Data.cpp"





using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Triad t;
			t.Init(1, 2, 3);
			t.IncrementAll();
			Assert::AreEqual(2, t.GetFirst());
			Assert::AreEqual(3, t.GetSecond());
			Assert::AreEqual(4, t.GetThird());
		}
	};
}
