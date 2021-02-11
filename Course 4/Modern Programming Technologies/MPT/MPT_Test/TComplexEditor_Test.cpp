#include "pch.h"
#include "CppUnitTest.h"

#include "../MPT/TComplexEditor.h"
#include "../MPT/TComplexEditor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MPT_Tests
{
	TEST_CLASS(TComplexEditorTest)
	{
	public:

		TEST_METHOD(TComplexEditor_construction)
		{
			std::string expected = "0";
			TComplexEditor a;
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_isZero)
		{
			TComplexEditor a;
			Assert::IsTrue(a.isZero());
		}

		TEST_METHOD(TComplexEditor_isZero_2)
		{
			TComplexEditor a;
			a.addNumber(1);
			Assert::IsFalse(a.isZero());
		}

		TEST_METHOD(TComplexEditor_addNumber)
		{
			std::string expected = "1";
			TComplexEditor a;
			a.addNumber(1);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addNumber2)
		{
			std::string expected = "-16";
			TComplexEditor a;
			a.addNumber(-16);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addSign)
		{
			std::string expected = "-16";
			TComplexEditor a;
			a.addNumber(16);
			a.addSign();
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addSign2)
		{
			std::string expected = "16+i*12";
			TComplexEditor a;
			a.setComplexString("-16+i*12");
			a.addSign();
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addSign3)
		{
			std::string expected = "-5-i*10";
			TComplexEditor a;
			a.addNumber(-5);
			a.addImPart();
			a.addNumber(10);
			a.addSign();
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addImPart)
		{
			std::string expected = "15+i*4";
			TComplexEditor a;
			a.addNumber(15);
			a.addImPart();
			a.addNumber(4);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addImPart2)
		{
			std::string expected = "-5+i*10";
			TComplexEditor a;
			a.addNumber(-5);
			a.addImPart();
			a.addNumber(10);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_addImPart3)
		{
			auto func = [] { TComplexEditor a; a.addImPart(); a.addImPart(); };
			Assert::ExpectException<std::logic_error>(func);
		}

		TEST_METHOD(TComplexEditor_editComplex)
		{
			std::string expected = "-8";
			TComplexEditor a;
			a.addNumber(8);
			a.editComplex(ComplexOperations::ADD_SIGN);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_editComplex2)
		{
			std::string expected = "8";
			TComplexEditor a;
			a.addNumber(-8);
			a.editComplex(ComplexOperations::ADD_SIGN);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_editComplex3)
		{
			std::string expected = "8+i*4";
			TComplexEditor a;
			a.addNumber(8);
			a.editComplex(ComplexOperations::ADD_IMPART);
			a.addNumber(4);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_editComplex4)
		{
			std::string expected = "8+i*40";
			TComplexEditor a;
			a.addNumber(8);
			a.editComplex(ComplexOperations::ADD_IMPART);
			a.addNumber(4);
			a.editComplex(ComplexOperations::ADD_ZERO);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_editComplex5)
		{
			std::string expected = "8-i*4";
			TComplexEditor a;
			a.addNumber(8);
			a.editComplex(ComplexOperations::ADD_IMPART);
			a.addNumber(4);
			a.editComplex(ComplexOperations::ADD_SIGN);
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_setComplexString)
		{
			std::string expected = "8+i*4";
			TComplexEditor a;
			a.setComplexString("8+i*4");
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_setComplexString2)
		{
			std::string expected = "-8-i*4";
			TComplexEditor a;
			a.setComplexString("-8-i*4");
			Assert::AreEqual(expected, a.getComplexString());
		}

		TEST_METHOD(TComplexEditor_setComplexString3)
		{
			auto func = [] {TComplexEditor a; a.setComplexString("i*4"); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}