#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TFracEditor.h"
#include "../MPT/TFracEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TFracEditorTest)
	{
	public:
		TEST_METHOD(FracEditor_Constructor)
		{
			std::string expected = "0/1";
			TFracEditor editor;
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_AddNumber)
		{
			std::string expected = "8";
			TFracEditor editor;
			editor.addNumber(8);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_AddNumber_2)
		{
			std::string expected = "-8";
			TFracEditor editor;
			editor.addNumber(-8);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_isZero)
		{
			TFracEditor editor;
			Assert::IsTrue(editor.isZero());
		}

		TEST_METHOD(FracEditor_isZero_2)
		{
			TFracEditor editor;
			editor.addNumber(8);
			Assert::IsFalse(editor.isZero());
		}

		TEST_METHOD(FracEditor_addSign)
		{
			std::string expected = "-8";
			TFracEditor editor;
			editor.addNumber(8);
			editor.addSign();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_addSign_2)
		{
			std::string expected = "8";
			TFracEditor editor;
			editor.addNumber(-8);
			editor.addSign();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_addSign_3)
		{
			std::string expected = "-1/2";
			TFracEditor editor;
			editor.addNumber(8);
			editor.addDivider();
			editor.addNumber(16);
			editor.addSign();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_addZero)
		{
			std::string expected = "0";
			TFracEditor editor;
			editor.addZero();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_addZero_2)
		{
			std::string expected = "80";
			TFracEditor editor;
			editor.addNumber(8);
			editor.addZero();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_removeLastDigit)
		{
			std::string expected = "8";
			TFracEditor editor;
			editor.addNumber(80);
			editor.removeLastDigit();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_removeLastDigit_2)
		{
			std::string expected = "-8";
			TFracEditor editor;
			editor.addNumber(-80);
			editor.removeLastDigit();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_removeLastDigit_3)
		{
			std::string expected = "-3/";
			TFracEditor editor;
			editor.addNumber(3);
			editor.addDivider();
			editor.addNumber(-7);
			editor.removeLastDigit();
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_editFraction)
		{
			std::string expected = "0";
			TFracEditor editor;
			editor.editFraction(Operations::ADD_ZERO);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_editFraction_2)
		{
			std::string expected = "1/2";
			TFracEditor editor;
			editor.addNumber(8);
			editor.editFraction(Operations::ADD_DIVIDER);
			editor.addNumber(16);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_editFraction_3)
		{
			std::string expected = "1/";
			TFracEditor editor;
			editor.addNumber(8);
			editor.editFraction(Operations::ADD_DIVIDER);
			editor.addNumber(16);
			editor.editFraction(Operations::REMOVE_LAST_DIGIT);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_editFraction_4)
		{
			std::string expected = "-1/2";
			TFracEditor editor;
			editor.addNumber(8);
			editor.editFraction(Operations::ADD_DIVIDER);
			editor.addNumber(16);
			editor.editFraction(Operations::ADD_SIGN);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_editFraction_5)
		{
			std::string expected = "0/1";
			TFracEditor editor;
			editor.addNumber(8);
			editor.editFraction(Operations::ADD_DIVIDER);
			editor.addNumber(16);
			editor.editFraction(Operations::CLEAR);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_getFraction)
		{
			std::string expected = "0/1";
			TFracEditor editor;
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_getFraction_2)
		{
			std::string expected = "8";
			TFracEditor editor;
			editor.addNumber(8);
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_setFraction)
		{
			std::string expected = "5/2";
			TFracEditor editor;
			editor.setFraction("5/2");
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_setFraction_2)
		{
			std::string expected = "-5/2";
			TFracEditor editor;
			editor.setFraction("-5/2");
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_setFraction_3)
		{
			std::string expected = "-5/2";
			TFracEditor editor;
			editor.setFraction("-10/4");
			Assert::AreEqual(expected, editor.getFraction());
		}

		TEST_METHOD(FracEditor_setFraction_4)
		{
			auto func = [] {TFracEditor editor; editor.setFraction("1"); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}
