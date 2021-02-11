#include "pch.h"
#include "CppUnitTest.h"
#include <set>

#include "../MPT/TPoly.h"
#include "../MPT/TPoly.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TPoly_Test)
	{
	public:
		TEST_METHOD(POWER_1) {
			TPoly a(1, 2);
			TPoly b(1, 3);
			TPoly c = a + b;
			Assert::AreEqual(3, c.maxDegree());
		}

		TEST_METHOD(POWER_2) {
			TPoly a(1, 2);
			TPoly b(1, 4);
			TPoly c = a + b;
			Assert::AreEqual(4, c.maxDegree());
		}

		TEST_METHOD(COEFF_1) {
			TPoly a(1, 0);
			TPoly b(123, 2);
			TPoly c(452, 3);
			TPoly d = a + b + c;
			Assert::AreEqual(452, d.coeff(3));
		}

		TEST_METHOD(COEFF_2) {
			TPoly a(1, 555);
			TPoly b(123, 2);
			TPoly c(452, 3);
			TPoly d = a + b + c;
			Assert::AreEqual(1, d.coeff(555));
		}

		TEST_METHOD(CLEAR_1) {
			TPoly a(1, 555);
			a.clear();
			Assert::AreEqual(0.0, a.compute(1.0));
		}

		TEST_METHOD(CLEAR_2) {
			TPoly a(-123, 55345435);
			a.clear();
			Assert::AreEqual(0.0, a.compute(1.0));
		}

		TEST_METHOD(ADD_1) {
			TPoly a(1, 2);
			TPoly b(2, 3);
			TPoly c(3, 4);
			TPoly d(4, 4);
			TPoly e = a + b + c + d;
			set<string> result;
			for (int i = 0; i < 3; ++i)
				result.emplace(e[i].monomialToString());
			set<string> expected = { "1*x^2", "2*x^3", "7*x^4" };
			Assert::AreEqual(true, result == expected);
		}

		TEST_METHOD(ADD_2) {
			TPoly a(1, 2);
			TPoly b(1, 2);
			TPoly c = a + b;
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> expected = { "2*x^2" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(MULT_1) {
			TPoly a(1, 1);
			TPoly b(2, 2);
			TPoly c = a * b;
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> exp = { "2*x^3" };
			bool r = result == exp;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(MULT_2) {
			TPoly a(3, 5);
			TPoly b(5, 3);
			TPoly c = a * b;
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> expected = { "15*x^8" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(SUB_1) {
			TPoly a(5, 5);
			TPoly b(1, 5);
			TPoly c = a - b;
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> expected = { "4*x^5" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(SUB_2) {
			TPoly a(1, 5);
			TPoly b(5, 5);
			TPoly c = a - b;
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> expected = { "-4*x^5" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(MINUS) {
			TPoly a(1, 5);
			TPoly c = a.minus();
			set<string> result;
			for (int i = 0; i < 1; ++i)
				result.emplace(c[i].monomialToString());
			set<string> expected = { "-1*x^5" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(DIFF_1) {
			TPoly a(5, 0);
			TPoly b(1, 2);
			TPoly c = a + b;
			TPoly e = c.differentiate();
			set<string> result;
			for (int i = 0; i < 2; ++i)
				result.emplace(e[i].monomialToString());
			set<string> expected = { "2*x^1", "0" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(DIFF_2) {
			TPoly a(5, 0);
			TPoly b(1, 2);
			TPoly bb(2, 3);
			TPoly c = a + b + bb;
			TPoly e = c.differentiate();
			set<string> result;
			for (int i = 0; i < 3; ++i)
				result.emplace(e[i].monomialToString());
			set<string> expected = { "2*x^1", "0", "6*x^2" };
			bool r = result == expected;
			Assert::AreEqual(true, r);
		}

		TEST_METHOD(COMPUTE_1) {
			TPoly a(5, 0);
			TPoly b(1, 2);
			TPoly c = a + b;
			double e = c.compute(1.0);
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(COMPUTE_EXC_1) {
			auto constr = [] {TPoly a(INT_MAX, INT_MAX); a.compute(INT_MAX); };
			Assert::ExpectException<std::overflow_error>(constr);
		}
	};
}
