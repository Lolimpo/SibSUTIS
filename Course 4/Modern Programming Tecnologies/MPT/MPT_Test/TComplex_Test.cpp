#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TComplex.h"
#include "../MPT/TComplex.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TComplexTest)
	{
	public:

		TEST_METHOD(Complex_Correct_Defenition)
		{
			std::string expect = "2+i*2";
			TComplex test(2, 2);
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Defenition_2)
		{
			std::string expect = "2-i*2";
			TComplex test(2, -2);
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Defenition_3)
		{
			std::string expect = "-2-i*2";
			TComplex test("-2-i*2");
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Defenition_4)
		{
			std::string expect = "3.15-i*2";
			TComplex test("3.15-i*2");
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Defenition_5)
		{
			std::string expect = "235.265+i*742.763";
			TComplex test(235.265, 742.763);
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Defenition_6)
		{
			std::string expect = "235.265-i*742.763";
			TComplex test(235.265, -742.763);
			Assert::AreEqual(expect, test.getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Copy)
		{
			std::string expect = "235.265+i*742.763";
			TComplex test(235.265, 742.763);
			Assert::AreEqual(expect, test.copy().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Copy_2)
		{
			std::string expect = "23.26+i*74.76";
			TComplex test("23.26+i*74.76");
			Assert::AreEqual(expect, test.copy().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Add)
		{
			std::string expect = "5+i*7";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.add(TComplex(2, 1)).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Add_2)
		{
			std::string expect = "5+i*7";
			TComplex test("3+i*6");
			Assert::AreEqual(expect, test.add(TComplex(2, 1)).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Add_3)
		{
			std::string expect = "5+i*7";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.add(TComplex("2+i*1")).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Subtract)
		{
			std::string expect = "1+i*5";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.subtract(TComplex(2, 1)).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Subtract_2)
		{
			std::string expect = "1+i*5";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.subtract(TComplex("2+i*1")).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Multiply)
		{
			std::string expect = "0+i*15";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.multiply(TComplex(2, 1)).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Multiply_2)
		{
			std::string expect = "0+i*15";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.multiply(TComplex("2+i*1")).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Divide)
		{
			std::string expect = "2.4+i*1.8";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.divide(TComplex(2, 1)).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Divide_2)
		{
			std::string expect = "2.4+i*1.8";
			TComplex test(3, 6);
			Assert::AreEqual(expect, test.divide(TComplex("2+i*1")).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Abs)
		{
			double expect = 5;
			TComplex test(3, 4);
			Assert::AreEqual(expect, test.abs());
		}

		TEST_METHOD(Complex_Correct_Abs_2)
		{
			double expect = 5;
			TComplex test(0, -5);
			Assert::AreEqual(expect, test.abs());
		}

		TEST_METHOD(Complex_Correct_AngleRad)
		{
			double expect = 0;
			TComplex test(0, 0);
			Assert::AreEqual(expect, test.angleRad());
		}

		TEST_METHOD(Complex_Correct_AngleRad_2)
		{
			double expect = M_PI_2;
			TComplex test(0, 6);
			Assert::AreEqual(expect, test.angleRad());
		}

		TEST_METHOD(Complex_Correct_AngleDegree)
		{
			double expect = 90;
			TComplex test(0, 6);
			Assert::AreEqual(expect, test.angleDegree());
		}

		TEST_METHOD(Complex_Correct_AngleDegree_2)
		{
			double expect = 0;
			TComplex test(0, 0);
			Assert::AreEqual(expect, test.angleDegree());
		}

		TEST_METHOD(Complex_Correct_Pow)
		{
			std::string expect = "-16+i*30";
			TComplex test(3, 5);
			Assert::AreEqual(expect, test.pow(2).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Pow_2)
		{
			std::string expect = "-0.0138408-i*0.0259516";
			TComplex test(3, 5);
			Assert::AreEqual(expect, test.pow(-2).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Root)
		{
			TComplex test(3, 7);
			Assert::IsTrue(test.root(3, 1).getReNum() - -1.556006 < 0.001);
			Assert::IsTrue(test.root(3, 1).getImNum() - 1.2040441 < 0.001);
		}

		TEST_METHOD(Complex_Correct_Root_2)
		{
			std::string expect = "0+i*0";
			TComplex test(3, 5);
			Assert::AreEqual(expect, test.root(2, 10).getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Reverse)
		{
			std::string expect = "0.1-i*0.1";
			TComplex test(5, 5);
			Assert::AreEqual(expect, test.reverse().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Reverse_2)
		{
			std::string expect = "0.25+i*0.25";
			TComplex test(2, -2);
			Assert::AreEqual(expect, test.reverse().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Square)
		{
			std::string expect = "-5+i*12";
			TComplex test(2, 3);
			Assert::AreEqual(expect, test.square().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Square_2)
		{
			std::string expect = "9+i*40";
			TComplex test(5, 4);
			Assert::AreEqual(expect, test.square().getComplexStr());
		}

		TEST_METHOD(Complex_Correct_Equal)
		{
			TComplex test(5, 4);
			TComplex test2(5, 4);
			Assert::IsTrue(test == test2);
		}

		TEST_METHOD(Complex_Correct_Equal_2)
		{
			TComplex test(5, 4);
			TComplex test2(4, 5);
			Assert::IsFalse(test == test2);
		}

		TEST_METHOD(Complex_Correct_NotEqual)
		{
			TComplex test(5, 4);
			TComplex test2(4, 5);
			Assert::IsTrue(test != test2);
		}

		TEST_METHOD(Complex_Correct_NotEqual_2)
		{
			TComplex test(5, 4);
			TComplex test2(5, 4);
			Assert::IsFalse(test != test2);
		}
	};
}