#include "pch.h"
#include "CppUnitTest.h"
#include <set>

#include "../MPT/TSet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TSet_Test)
	{
	public:
		TEST_METHOD(INIT_1) {
			TSet<int> a;
			set<int> b{};
			Assert::AreEqual(true, a.container == b);
		}

		TEST_METHOD(INIT_2) {
			TSet<int> a;
			set<int> b{1};
			Assert::AreEqual(true, a.container != b);
		}

		TEST_METHOD(CLEAR_1) {
			TSet<int> a;
			a.insert_(1);
			a.clear();
			set<int> b{};
			Assert::AreEqual(true, a.container == b);
		}

		TEST_METHOD(CLEAR_2) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.clear();
			set<int> b{};
			Assert::AreEqual(true, a.container == b);
		}

		TEST_METHOD(INSERT_1) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			set<int> b{1, 2};
			Assert::AreEqual(true, a.container == b);
		}

		TEST_METHOD(INSERT_2) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			set<int> b{ 1, 2, 3 };
			Assert::AreEqual(true, a.container == b);
		}

		TEST_METHOD(IS_EMPTY) {
			TSet<int> a;
			Assert::AreEqual(true, a.count() == 0);
		}

		TEST_METHOD(CONTAINS_1) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			Assert::AreEqual(true, a.contains(1));
		}

		TEST_METHOD(CONTAINS_2) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			Assert::AreEqual(true, a.contains(2));
		}

		TEST_METHOD(CONTAINS_3) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			Assert::AreEqual(true, a.contains(3));
		}

		TEST_METHOD(UNION_1) {
			TSet<int> a;
			TSet<int> b;
			set<int> c { 1, 2, 3, 4 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(4);
			TSet<int> result = a.add(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(UNION_2) {
			TSet<int> a;
			TSet<int> b;
			set<int> c{ 1, 2, 3 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(1);
			b.insert_(2);
			b.insert_(3);
			TSet<int> result = a.add(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(SUBTRACT_1) {
			TSet<int> a;
			TSet<int> b;
			set<int> c{ 2, 3 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(1);
			TSet<int> result = a.subtract(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(SUBTRACT_2) {
			TSet<int> a;
			TSet<int> b;
			set<int> c{ 1, 2, 3 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(4);
			TSet<int> result = a.subtract(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(MULTIPLY_1) {
			TSet<int> a;
			TSet<int> b;
			set<int> c{ 1, 2, 3 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(1);
			b.insert_(2);
			b.insert_(3);
			TSet<int> result = a.multiply(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(MULTIPLY_2) {
			TSet<int> a;
			TSet<int> b;
			set<int> c{ 1 };
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			b.insert_(1);
			b.insert_(4);
			b.insert_(5);
			TSet<int> result = a.multiply(b);
			Assert::AreEqual(true, result.container == c);
		}

		TEST_METHOD(COUNTER_1) {
			TSet<int> a;
			a.insert_(1);
			a.insert_(2);
			a.insert_(3);
			Assert::AreEqual(3, a.count());
		}

		TEST_METHOD(COUNTER_2) {
			TSet<int> a;
			Assert::AreEqual(0, a.count());
		}

		TEST_METHOD(ELEMENT_1) {
			auto constr = [] {TSet<int> a; a.insert_(1); a.element(5); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(ELEMENT_2) {
			auto constr = [] {TSet<int> a; a.insert_(1); a.element(-5); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(ELEMENT_3) {
			auto constr = [] {TSet<int> a; a.insert_(1); a.element(1000); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}

		TEST_METHOD(ELEMENT_4) {
			TSet<int> a;
			a.insert_(5);
			Assert::AreEqual(5, a.element(0));
		}
	};
};
