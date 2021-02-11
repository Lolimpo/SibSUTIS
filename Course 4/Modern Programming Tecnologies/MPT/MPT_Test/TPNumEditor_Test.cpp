#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TPNumEditor.h"
#include "../MPT/TPNumEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TPNumEditorTest)
	{
	public:
		TEST_METHOD(CONSTR_1)
		{
			Assert::AreEqual(string("0"), TPNumEditor().getNumberString());
		}

		TEST_METHOD(EQ_ZERO_1)
		{
			Assert::AreEqual(true, TPNumEditor().equalsZero());
		}

		TEST_METHOD(EQ_ZERO_2)
		{
			TPNumEditor tpneditor;
			tpneditor.addDigit(5);
			Assert::AreEqual(false, tpneditor.equalsZero());
		}

		TEST_METHOD(CHANGE_SIGN_1)
		{
			TPNumEditor o1;
			o1.addDigit(5);
			Assert::AreEqual(string("-5"), o1.changeSign());
		}

		TEST_METHOD(CHANGE_SIGN_2)
		{
			TPNumEditor o1;
			o1.addDigit(15);
			Assert::AreEqual(string("-F"), o1.changeSign());
		}

		TEST_METHOD(ADD_DIGIT_1)
		{
			TPNumEditor o1;
			o1.addDigit(5);
			Assert::AreEqual(string("5"), o1.getNumberString());
		}

		TEST_METHOD(ADD_DIGIT_2)
		{
			TPNumEditor o1;
			o1.addDigit(2);
			Assert::AreEqual(string("2"), o1.getNumberString());
		}

		TEST_METHOD(ADD_ZERO_1)
		{
			TPNumEditor o1;
			o1.addDigit(2);
			o1.addZero();
			Assert::AreEqual(string("20"), o1.getNumberString());
		}

		TEST_METHOD(CLEAR_1)
		{
			TPNumEditor o1;
			o1.addDigit(2);
			o1.clear();
			Assert::AreEqual(string("0"), o1.getNumberString());
		}

		TEST_METHOD(GETNUMBERSTRING_1)
		{
			TPNumEditor o1;
			Assert::AreEqual(string("0"), o1.getNumberString());
		}

		TEST_METHOD(ADD_DIVIDER_1)
		{
			TPNumEditor o1;
			o1.addDigit(5);
			o1.addDivider();
			o1.addDigit(5);
			Assert::AreEqual(string("5.5"), o1.getNumberString());
		}

		TEST_METHOD(SET_NUMBER_1)
		{
			TPNumEditor o1;
			o1.setNumber(111);
			Assert::AreEqual(string("111"), o1.getNumberString());
		}

		TEST_METHOD(SET_NUMBER_2)
		{
			TPNumEditor o1;
			o1.setNumber(222);
			Assert::AreEqual(string("222"), o1.getNumberString());
		}

		TEST_METHOD(SET_NUMBER_3)
		{
			TPNumEditor o1;
			o1.setNumber(333);
			Assert::AreEqual(string("333"), o1.getNumberString());
		}

		TEST_METHOD(EDIT_NUMBER_1)
		{
			TPNumEditor o1;
			o1.editNumber("123");
			Assert::AreEqual(string("123"), o1.getNumberString());
		}

		TEST_METHOD(EDIT_NUMBER_2)
		{
			TPNumEditor o1;
			o1.editNumber("321.321");
			Assert::AreEqual(string("321.321"), o1.getNumberString());
		}

		TEST_METHOD(EDIT_NUMBER_3)
		{
			TPNumEditor o1;
			o1.editNumber("10");
			Assert::AreEqual(string("10"), o1.getNumberString());
		}
	};


}
