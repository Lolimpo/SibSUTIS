#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TMonomial.h"
#include "../MPT/TMonomial.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TMonomial_Test)
	{
	public:
		TEST_METHOD(INIT_1) {
			TMonomial a(1, 1);
			Assert::AreEqual(string("1*x^1"),
				a.monomialToString());
		}
		TEST_METHOD(INIT_2) {
			TMonomial a(555, 1);
			Assert::AreEqual(string("555*x^1"),
				a.monomialToString());
		}
		TEST_METHOD(INIT_3) {
			TMonomial a(1, 222);
			Assert::AreEqual(string("1*x^222"),
				a.monomialToString());
		}
		TEST_METHOD(INIT_4) {
			TMonomial a(123, 123);
			Assert::AreEqual(string("123*x^123"),
				a.monomialToString());
		}
		TEST_METHOD(INIT_5) {
			TMonomial a(-1, -1);
			Assert::AreEqual(string("-1*x^-1"),
				a.monomialToString());
		}
		TEST_METHOD(WRPOW_1) {
			TMonomial a(1, 1);
			a.writePower(5);
			Assert::AreEqual(string("1*x^5"),
				a.monomialToString());
		}
		TEST_METHOD(WRPOW_2) {
			TMonomial a(1, 1);
			a.writePower(100);
			Assert::AreEqual(string("1*x^100"),
				a.monomialToString());
		}
		TEST_METHOD(WRCOEFF_1) {
			TMonomial a(1, 1);
			a.writeCoeff(100);
			Assert::AreEqual(string("100*x^1"),
				a.monomialToString());
		}
		TEST_METHOD(WRCOEFF_2) {
			TMonomial a(1, 1);
			a.writeCoeff(555);
			Assert::AreEqual(string("555*x^1"),
				a.monomialToString());
		}
		TEST_METHOD(EQ_1) {
			bool result = TMonomial(1, 1).isEqual(TMonomial(1, 1));
			Assert::AreEqual(true, result);
		}
		TEST_METHOD(EQ_2) {
			bool result = TMonomial(1, 2).isEqual(TMonomial(1, 1));
			Assert::AreEqual(false, result);
		}
		TEST_METHOD(DIFF_1) {
			TMonomial a(2, 1);
			TMonomial b = a.differentiate();
			Assert::AreEqual(string("2*x^0"), b.monomialToString());
		}
		TEST_METHOD(DIFF_2) {
			TMonomial a(2, 2);
			TMonomial b = a.differentiate();
			Assert::AreEqual(string("4*x^1"), b.monomialToString());
		}
		TEST_METHOD(COMP_1) {
			TMonomial a(2, 2);
			double b = a.compute(1.0);
			Assert::AreEqual(2.0, b);
		}
		TEST_METHOD(COMP_2) {
			TMonomial a(2, 2);
			double b = a.compute(2.0);
			Assert::AreEqual(8.0, b);
		}
		TEST_METHOD(RPOW_1) {
			TMonomial a(2, 2);
			int b = a.readPower();
			Assert::AreEqual(2, b);
		}
		TEST_METHOD(RPOW_2) {
			TMonomial a(2, 3);
			int b = a.readPower();
			Assert::AreEqual(3, b);
		}
		TEST_METHOD(RCOEFF_1) {
			TMonomial a(2, 3);
			int b = a.readCoeff();
			Assert::AreEqual(2, b);
		}
		TEST_METHOD(RCOEFF_2) {
			TMonomial a(5, 3);
			int b = a.readCoeff();
			Assert::AreEqual(5, b);
		}
		TEST_METHOD(DIFF_EXC_1) {
			auto constr = [] {TMonomial a(INT_MAX, INT_MAX); a.compute(INT_MAX); };
			Assert::ExpectException<std::overflow_error>(constr);
		}
	};
}
