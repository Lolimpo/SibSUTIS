#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TPNumber.h"
#include "../MPT/TPNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TPNumberTest)
	{
	public:
		TEST_METHOD(CONSTR_1)
		{
			Assert::AreEqual(10, TPNumber(1, 10, 2).getBase());
		}

		TEST_METHOD(CONSTR_2)
		{
			Assert::AreEqual(10, TPNumber(1, -1, 2).getBase());
		}

		TEST_METHOD(CONSTR_STR_1)
		{
			Assert::AreEqual(10, TPNumber("1", "10", "2").getBase());
		}

		TEST_METHOD(COPY_1)
		{
			TPNumber a(1, 10, 2);
			TPNumber b = a.copy();
			Assert::AreEqual(1.0, b.getNumber());
		}

		TEST_METHOD(COPY_2)
		{
			TPNumber a(-1.0, 10, 2);
			TPNumber b = a.copy();
			Assert::AreEqual(-1.0, b.getNumber());
		}

		TEST_METHOD(ADD_1)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(5.0, 10, 2);
			Assert::AreEqual(10.0, a.add(b).getNumber());
		}

		TEST_METHOD(ADD_2)
		{
			TPNumber a(-5.0, 10, 2);
			TPNumber b(-5.0, 10, 2);
			Assert::AreEqual(-10.0, a.add(b).getNumber());
		}

		TEST_METHOD(MULT_1)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(5.0, 10, 2);
			Assert::AreEqual(25.0, a.mult(b).getNumber());
		}

		TEST_METHOD(MULT_2)
		{
			TPNumber a(-5.0, 10, 2);
			TPNumber b(-5.0, 10, 2);
			Assert::AreEqual(25.0, a.mult(b).getNumber());
		}

		TEST_METHOD(SUBTR_1)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(5.0, 10, 2);
			Assert::AreEqual(0.0, a.subtr(b).getNumber());
		}

		TEST_METHOD(SUBTR_2)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(-5.0, 10, 2);
			Assert::AreEqual(10.0, a.subtr(b).getNumber());
		}

		TEST_METHOD(DIV_1)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(5.0, 10, 2);
			Assert::AreEqual(1.0, a.div(b).getNumber());
		}

		TEST_METHOD(DIV_2)
		{
			TPNumber a(5.0, 10, 2);
			TPNumber b(-5.0, 10, 2);
			Assert::AreEqual(-1.0, a.div(b).getNumber());
		}

		TEST_METHOD(INV_1)
		{
			TPNumber a(5.0, 10, 3);
			Assert::AreEqual(0.2, a.inverse().getNumber());
		}

		TEST_METHOD(INV_2)
		{
			TPNumber a(1.0, 10, 2);
			Assert::AreEqual(1.0, a.inverse().getNumber());
		}

		TEST_METHOD(SQ_1)
		{
			TPNumber a(2.0, 10, 2);
			Assert::AreEqual(4.0, a.square().getNumber());
		}

		TEST_METHOD(SQ_2)
		{
			TPNumber a(1.0, 10, 2);
			Assert::AreEqual(1.0, a.square().getNumber());
		}

		TEST_METHOD(GETNUM_1)
		{
			TPNumber a(2.0, 10, 2);
			Assert::AreEqual(2.0, a.getNumber());
		}

		TEST_METHOD(GETNUM_2)
		{
			TPNumber a(-5.0, 10, 2);
			Assert::AreEqual(-5.0, a.getNumber());
		}

		TEST_METHOD(GETNUMST_1)
		{
			TPNumber a(15, 16, 2);
			Assert::AreEqual(string("F"), a.getNumberString());
		}

		TEST_METHOD(GETNUMST_2)
		{
			TPNumber a(10, 16, 2);
			Assert::AreEqual(string("A"), a.getNumberString());
		}

		TEST_METHOD(GETBASE_1)
		{
			TPNumber a(10, 16, 2);
			Assert::AreEqual(16, a.getBase());
		}

		TEST_METHOD(GETBASESTR_1)
		{
			TPNumber a(10, 16, 2);
			Assert::AreEqual(string("16"), a.getBaseString());
		}

		TEST_METHOD(GETPR_1)
		{
			TPNumber a(10, 16, 2);
			Assert::AreEqual(2, a.getPrecision());
		}

		TEST_METHOD(GETPRSTR_1)
		{
			TPNumber a(10, 16, 2);
			Assert::AreEqual(string("2"), a.getPrecisionString());
		}

		TEST_METHOD(SET_BASE_1)
		{
			TPNumber a(10, 16, 2);
			a.setBase(5);
			Assert::AreEqual(5, a.getBase());
		}

		TEST_METHOD(SET_BASE_STR_1)
		{
			TPNumber a(10, 16, 2);
			a.setBase("5");
			Assert::AreEqual(5, a.getBase());
		}

		TEST_METHOD(SET_PR_1)
		{
			TPNumber a(10, 16, 2);
			a.setPrecision(3);
			Assert::AreEqual(3, a.getPrecision());
		}

		TEST_METHOD(SET_PR_STR_1)
		{
			TPNumber a(10, 16, 2);
			a.setPrecision("3");
			Assert::AreEqual(3, a.getPrecision());
		}

	};
}
