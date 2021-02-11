#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TFrac.h"
#include "../MPT/TFrac.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TFracTest)
	{
	public:
		
		TEST_METHOD(Fraction_Correct_Defenition)
		{
			std::string expect = "2/5";
			TFrac test(2, 5);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_2)
		{
			std::string expect = "2/5";
			TFrac test("2/5");
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_3)
		{
			std::string expect = "0/1";
			TFrac test(1, 0);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_4)
		{
			std::string expect = "4/5";
			TFrac test(000004, 00005);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_5)
		{
			std::string expect = "-1/2";
			TFrac test(-50, 100);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_6)
		{
			std::string expect = "-4/5";
			TFrac test(4, -5);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_7)
		{
			std::string expect = "1/4";
			TFrac test(-8, -32);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Defenition_8)
		{
			std::string expect = "0/1";
			TFrac test("5/0");
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reduction_Num)
		{
			std::string expect = "1/3";
			TFrac test(2, 6);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reduction_Num_2)
		{
			std::string expect = "-5/1";
			TFrac test(25, -5);
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reduction_String)
		{
			std::string expect = "3/7";
			TFrac test("9/21");
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reduction_String_2)
		{
			std::string expect = "-15/1";
			TFrac test("30/-2");
			Assert::AreEqual(expect, test.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Addition)
		{
			std::string expect = "4/5";
			TFrac test("1/5");
			TFrac test2("3/5");
			Assert::AreEqual(expect, test.add(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Addition_2)
		{
			std::string expect = "-1/4";
			TFrac test("1/2");
			TFrac test2(3, -4);
			Assert::AreEqual(expect, test.add(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Multiplication)
		{
			std::string expect = "16/25";
			TFrac test("1/5");
			TFrac test2("16/5");
			Assert::AreEqual(expect, test.multiply(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Multiplication_2)
		{
			std::string expect = "-2/1";
			TFrac test("-1/6");
			TFrac test2("12/1");
			Assert::AreEqual(expect, test.multiply(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Subtraction)
		{
			std::string expect = "1/5";
			TFrac test("6/10");
			TFrac test2("2/5");
			Assert::AreEqual(expect, test.subtract(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Subtraction_2)
		{
			std::string expect = "1/2";
			TFrac test("3/5");
			TFrac test2("1/10");
			Assert::AreEqual(expect, test.subtract(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Division)
		{
			std::string expect = "25/9";
			TFrac test("5/3");
			TFrac test2("3/5");
			Assert::AreEqual(expect, test.divide(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Division_2)
		{
			std::string expect = "-25/9";
			TFrac test("5/3");
			TFrac test2("3/-5");
			Assert::AreEqual(expect, test.divide(test2).getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reverse)
		{
			std::string expect = "7/3";
			TFrac test(3, 7);
			Assert::AreEqual(expect, test.reverse().getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Reverse_2)
		{
			std::string expect = "1/2";
			TFrac test(10, 5);
			Assert::AreEqual(expect, test.reverse().getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Square)
		{
			std::string expect = "1/4";
			TFrac test(5, 10);
			Assert::AreEqual(expect, test.square().getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Square_2)
		{
			std::string expect = "9/49";
			TFrac test(3, 7);
			Assert::AreEqual(expect, test.square().getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Comparison)
		{
			TFrac test("3/5");
			TFrac test2("3/5");
			Assert::IsTrue(test == test2);
		}

		TEST_METHOD(Fraction_Correct_Comparison_2)
		{
			TFrac test("3/5");
			TFrac test2("1/100");
			Assert::IsTrue(test > test2);
		}

		TEST_METHOD(Fraction_Correct_Comparison_3)
		{
			TFrac test("3/5");
			TFrac test2("6/10");
			Assert::IsTrue(test == test2);
		}

		TEST_METHOD(Fraction_Correct_Copy) 
		{
			TFrac test(8, 11);
			TFrac test2 = test.copy();
			Assert::AreEqual(test.getFractionString(), test2.getFractionString());
		}

		TEST_METHOD(Fraction_Correct_Copy_2)
		{
			TFrac test("15/17");
			TFrac test2 = test.copy();
			Assert::AreEqual(test.getFractionString(), test2.getFractionString());
		}

		TEST_METHOD(Fraction_Get_Numerator)
		{
			TFrac test(8, 11);
			std::string expect = "8";
			Assert::AreEqual(expect, test.getNumeratorString());
		}

		TEST_METHOD(Fraction_Get_Numerator_2)
		{
			TFrac test(8, 11);
			int expect = 8;
			Assert::AreEqual(expect, test.getNumeratorNum());
		}

		TEST_METHOD(Fraction_Get_Numerator_3)
		{
			TFrac test(-1, 3);
			int expect = -1;
			Assert::AreEqual(expect, test.getNumeratorNum());
		}

		TEST_METHOD(Fraction_Get_Denominator)
		{
			TFrac test(8, 11);
			std::string expect = "11";
			Assert::AreEqual(expect, test.getDenominatorString());
		}

		TEST_METHOD(Fraction_Get_Denominator_2)
		{
			TFrac test(8, 11);
			int expect = 11;
			Assert::AreEqual(expect, test.getDenominatorNum());
		}

		TEST_METHOD(Fraction_Get_Denominator_3)
		{
			TFrac test(2, -13);
			int expect = 13;
			Assert::AreEqual(expect, test.getDenominatorNum());
		}
	};
}
