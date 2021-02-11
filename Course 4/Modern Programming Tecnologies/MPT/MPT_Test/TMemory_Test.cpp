#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TMemory.h"
#include "../MPT/TFrac.h"
#include "../MPT/TFracEditor.h"
#include "../MPT/TPNumber.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TMemory_Test)
	{
	public:
		TEST_METHOD(ADD_1)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			tmem.add(tfrac);
			Assert::AreEqual(string("2/5"), tmem.get().getFractionString());
		}

		TEST_METHOD(ADD_2)
		{
			TFrac tfrac(1, 4);
			TMemory<TFrac> tmem(tfrac);
			tmem.add(tfrac);
			Assert::AreEqual(string("1/2"), tmem.get().getFractionString());
		}

		TEST_METHOD(ADD_3)
		{
			TFrac tfrac(1, 999);
			TMemory<TFrac> tmem(tfrac);
			tmem.add(tfrac);
			Assert::AreEqual(string("2/999"), tmem.get().getFractionString());
		}

		TEST_METHOD(WRITE_1)
		{
			TFrac tfrac(1, 5);
			TFrac tfrac2(5, 7);
			TMemory<TFrac> tmem(tfrac);
			tmem.write(tfrac2);
			Assert::AreEqual(string("5/7"), tmem.get().getFractionString());
		}

		TEST_METHOD(WRITE_2)
		{
			TFrac tfrac(1, 5);
			TFrac tfrac2(1, 10);
			TMemory<TFrac> tmem(tfrac);
			tmem.write(tfrac2);
			Assert::AreEqual(string("1/10"), tmem.get().getFractionString());
		}

		TEST_METHOD(WRITE_3)
		{
			TFrac tfrac(1, 5);
			TFrac tfrac2(2, 99);
			TMemory<TFrac> tmem(tfrac);
			tmem.write(tfrac2);
			Assert::AreEqual(string("2/99"), tmem.get().getFractionString());
		}

		TEST_METHOD(GET_1)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(string("1/5"), tmem.get().getFractionString());
		}

		TEST_METHOD(GET_2)
		{
			TFrac tfrac(2, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(string("2/5"), tmem.get().getFractionString());
		}

		TEST_METHOD(GET_3)
		{
			TFrac tfrac(3, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(string("3/5"), tmem.get().getFractionString());
		}

		TEST_METHOD(CLEAR_1)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			tmem.clear();
			Assert::AreEqual(string("0/1"), tmem.get().getFractionString());
		}

		TEST_METHOD(READ_FSTATE_1)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			tmem.clear();
			Assert::AreEqual(string("0"), tmem.readFState());
		}

		TEST_METHOD(READ_FSTATE_2)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			tmem.add(tfrac);
			Assert::AreEqual(string("1"), tmem.readFState());
		}

		TEST_METHOD(READ_NUMBER_1)
		{
			TFrac tfrac(1, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(tfrac.getFractionString(), tmem.readNumber().getFractionString());
		}

		TEST_METHOD(READ_NUMBER_2)
		{
			TFrac tfrac(2, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(tfrac.getFractionString(), tmem.readNumber().getFractionString());
		}

		TEST_METHOD(READ_NUMBER_3)
		{
			TFrac tfrac(4, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(tfrac.getFractionString(), tmem.readNumber().getFractionString());
		}

		TEST_METHOD(READ_NUMBER_4)
		{
			TFrac tfrac(5, 5);
			TMemory<TFrac> tmem(tfrac);
			Assert::AreEqual(tfrac.getFractionString(), tmem.readNumber().getFractionString());
		}

		TEST_METHOD(CONSTR_1)
		{
			auto constr = [] {TFracEditor a; TMemory<TFracEditor> b(a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(CONSTR_2)
		{
			auto constr = [] {TPNumber a; TMemory<TPNumber> b(a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(CONSTR_3)
		{
			auto constr = [] {bool a = true; TMemory<bool> b(a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(CONSTR_4)
		{
			auto constr = [] {string a; TMemory<string> b(a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
	};
}
