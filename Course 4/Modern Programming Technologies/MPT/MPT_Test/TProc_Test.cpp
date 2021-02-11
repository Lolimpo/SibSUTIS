#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TProc.h"
#include "../MPT/TFrac.h"
#include "../MPT/TFracEditor.h"
#include "../MPT/TPNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TProc_Test)
	{
	public:

		TEST_METHOD(CONSTR_1)
		{
			auto constr = [] {TFracEditor a; TProc b(a, a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
		TEST_METHOD(CONSTR_2)
		{
			auto constr = [] {TPNumber a; TProc b(a, a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
		TEST_METHOD(CONSTR_3)
		{
			auto constr = [] {bool a; TProc b(a, a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
		TEST_METHOD(CONSTR_4)
		{
			auto constr = [] {string a; TProc b(a, a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
		TEST_METHOD(CONSTR_5)
		{
			auto constr = [] {string a("abc"); TProc b(a, a); };
			Assert::ExpectException<std::invalid_argument>(constr);
		}
		TEST_METHOD(Init_1) { // 0/1 0/1
			TFrac leftFrac;
			TFrac rightFrac;
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer;
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Init_2) { // 11/3 11/3
			TFrac leftFrac(11, 3);
			TFrac rightFrac;
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(11, 3);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Init_3) { // 17/9 17/9
			TFrac leftFrac(16, 4);
			TFrac rightFrac(17, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(17, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Init_4) { // 17/9 17/9
			TFrac leftFrac(500, 4);
			TFrac rightFrac(-300, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(-300, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Init_5) { // 17/9 17/9
			TFrac leftFrac(500, 4);
			TFrac rightFrac(123, 45);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFrac answer(123, 45);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Operation_1) { // 1/2 + 1/2 = 1/1
			TFrac leftFrac(1, 2);
			TFrac rightFrac(1, 2);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Add;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(1, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_2) { // 3/4 - 5/6 = -1/12
			TFrac leftFrac(3, 4);
			TFrac rightFrac(5, 6);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Sub;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(-1, 12);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Operation_3) { // 12/7 * 5/9 = 20/21
			TFrac leftFrac(12, 7);
			TFrac rightFrac(5, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Mul;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(20, 21);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Operation_4) { // 56/7 : -22/3 = -12/11
			TFrac leftFrac(56, 7);
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Div;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(-12, 11);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_5) {
			TFrac leftFrac(15, 10);
			TFrac rightFrac(55, 60);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Add;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(29, 12);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_6) {
			TFrac leftFrac(1, 1);
			TFrac rightFrac(1, 1);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Add;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(2, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_7) {
			TFrac leftFrac(3, 1);
			TFrac rightFrac(1, 1);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Add;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(4, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_8) { // 12/7 * 5/9 = 20/21
			TFrac leftFrac(7, 7);
			TFrac rightFrac(7, 7);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Mul;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(1, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_9) { // 12/7 * 5/9 = 20/21
			TFrac leftFrac(8, 7);
			TFrac rightFrac(8, 7);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Mul;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(64, 49);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}

		TEST_METHOD(Operation_10) { // 12/7 * 5/9 = 20/21
			TFrac leftFrac(5, 7);
			TFrac rightFrac(1, 1);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TOperations oper = Mul;
			obj.writeOper(oper);
			obj.doOper();
			TFrac answer(5, 7);
			Assert::AreEqual(answer.getFractionString(), obj.readLeft().getFractionString());
		}
		TEST_METHOD(Function_1) { // reverse
			TFrac leftFrac(56, 7);
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Rev;
			obj.doFunc(funcOper);
			TFrac answer(-3, 22);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}
		TEST_METHOD(Function_2) {
			TFrac leftFrac;
			TFrac rightFrac(-22, 3);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Sqr;
			obj.doFunc(funcOper);
			TFrac answer(484, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Function_3) {
			TFrac leftFrac;
			TFrac rightFrac(1, 1);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Sqr;
			obj.doFunc(funcOper);
			TFrac answer(1, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Function_4) {
			TFrac leftFrac;
			TFrac rightFrac(2, 2);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Sqr;
			obj.doFunc(funcOper);
			TFrac answer(1, 1);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

		TEST_METHOD(Function_5) {
			TFrac leftFrac;
			TFrac rightFrac(3, 9);
			TProc<TFrac> obj(leftFrac, rightFrac);
			TFunc funcOper = Sqr;
			obj.doFunc(funcOper);
			TFrac answer(1, 9);
			Assert::AreEqual(answer.getFractionString(), obj.readRight().getFractionString());
		}

	};
}