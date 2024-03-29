﻿using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;

namespace ConverterTests
{
    [TestClass]
    public class Test_ADT_Convert_10_p
    {
        [TestMethod]
        public void TestDo1()
        {
            double n = 123.123;
            int p = 12;
            int c = 3;
            string Expect = "A3.158";
            string Actual = Converter.ADT_Convert_10_p.Do(n, p, c);
            Assert.AreEqual(Expect, Actual);
        }

        [TestMethod]
        public void TestDo2()
        {
            double n = -144.523;
            int p = 3;
            int c = 8;
            string Expect = "-12100.11201002";
            string Actual = Converter.ADT_Convert_10_p.Do(n, p, c);
            Assert.AreEqual(Expect, Actual);
        }

        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void TestDo3()
        {
            double n = -12312.1231;
            int p = 3;
            int c = -8;
            Converter.ADT_Convert_10_p.Do(n, p, c);
        }

        [TestMethod]
        [ExpectedException(typeof(IndexOutOfRangeException))]
        public void TestDo4()
        {
            double n = -12312.1231;
            int p = -3;
            int c = 8;
            Converter.ADT_Convert_10_p.Do(n, p, c);
        }

        [TestMethod]
        public void TestIntToChar1()
        {
            int n = 12;
            char ExpectedChar = 'C';
            char ActualChar = Converter.ADT_Convert_10_p.int_to_Char(n);
            Assert.AreEqual(ExpectedChar, ActualChar);
        }

        [TestMethod]
        public void TestIntToChar2()
        {
            int n = 3;
            char ExpectedChar = '3';
            char ActualChar = Converter.ADT_Convert_10_p.int_to_Char(n);
            Assert.AreEqual(ExpectedChar, ActualChar);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestIntToChar3()
        {
            int n = -12;
            Converter.ADT_Convert_10_p.int_to_Char(n);
        }

        [TestMethod]
        public void TestIntToP1()
        {
            int n = 123;
            int p = 12;
            string ExpectedString = "A3";
            string ActualString = Converter.ADT_Convert_10_p.int_to_p(n, p);
            Assert.AreEqual(ExpectedString, ActualString);
        }

        [TestMethod]
        public void TestIntToP2()
        {
            int n = -234567;
            int p = 9;
            string ExpectedString = "-386680";
            string ActualString = Converter.ADT_Convert_10_p.int_to_p(n, p);
            Assert.AreEqual(ExpectedString, ActualString);
        }
        
        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestIntToP3()
        {
            int n = 123;
            int p = -24;
            Converter.ADT_Convert_10_p.int_to_p(n, p);
        }

        [TestMethod]
        public void TestFltToP1()
        {
            double n = 0.123;
            int p = 12;
            int c = 3;
            string ExpectedString = "158";
            string ActualString = Converter.ADT_Convert_10_p.flt_to_p(n, p, c);
            Assert.AreEqual(ExpectedString, ActualString);
        }

        [TestMethod]
        public void TestFltToP2()
        {
            double n = 0.417;
            int p = 9;
            int c = 5;
            string ExpectedString = "36688";
            string ActualString = Converter.ADT_Convert_10_p.flt_to_p(n, p, c);
            Assert.AreEqual(ExpectedString, ActualString);
        }

        
        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestFltToP3()
        {
            double n = 1.5;
            int p = 12;
            int c = 3;
            Converter.ADT_Convert_10_p.flt_to_p(n, p, c);
        }
    }
    
    [TestClass]
    public class Test_ADT_Convert_p_10 
    {
        [TestMethod]
        public void TestDval1()
        {
            string Number = "123.321";
            int P = 4;
            double ExpectedValue = 27.890625;
            double ActualValue = Converter.ADT_Convert_p_10.dval(Number, P);
            Assert.AreEqual(ExpectedValue, ActualValue, 0.00001);
        }

        [TestMethod]
        public void TestDval2()
        {
            string Number = "37.53";
            int P = 8;
            double ExpectedValue = 31.671875;
            double ActualValue = Converter.ADT_Convert_p_10.dval(Number, P);
            Assert.AreEqual(ExpectedValue, ActualValue, 0.00001);
        }

        [TestMethod]
        public void TestDval3()
        {
            string Number = "A8F.9C9";
            int P = 16;
            double ExpectedValue = 2703.611572265625;
            double ActualValue = Converter.ADT_Convert_p_10.dval(Number, P);
            Assert.AreEqual(ExpectedValue, ActualValue, 0.00001);
        }

        [TestMethod]
        public void TestDval4()
        {
            string Number = "0.23A5";
            int P = 13;
            double ExpectedValue = 0.17632435839081264662;
            double ActualValue = Converter.ADT_Convert_p_10.dval(Number, P);
            Assert.AreEqual(ExpectedValue, ActualValue, 0.00001);
        }

        [TestMethod]
        public void TestDval5()
        {
            string Number = "9876";
            int P = 11;
            double ExpectedValue = 13030;
            double ActualValue = Converter.ADT_Convert_p_10.dval(Number, P);
            Assert.AreEqual(ExpectedValue, ActualValue, 0.00001);
        }

        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void TestDval6()
        {
            string Number = ".A";
            int P = 11;
            Converter.ADT_Convert_p_10.dval(Number, P);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestDval7()
        {
            string Number = "AA";
            int P = 77;
            Converter.ADT_Convert_p_10.dval(Number, P);
        }

        [TestMethod]
        [ExpectedException(typeof(System.Exception))]
        public void TestDval8()
        {
            string Number = "FFF";
            int P = 2;
            Converter.ADT_Convert_p_10.dval(Number, P);
        }
    }

    [TestClass]
    public class Test_Editor 
    {
        [TestMethod]
        public void TestAddDigit1()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(0);
            string ExpectedValue = "0";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDigit2()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(0);
            editor.addDigit(0);
            editor.addDigit(0);
            editor.addDigit(0);
            editor.addDigit(0);
            string ExpectedValue = "0";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDigit3()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(0);
            editor.addDelim();
            editor.addDigit(0);
            editor.addDigit(0);
            editor.addDigit(0);
            editor.addDigit(0);
            string ExpectedValue = "0.0000";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDigit4()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(15);
            editor.addDigit(12);
            editor.addDigit(1);
            editor.addDelim();
            editor.addDigit(1);
            editor.addDigit(9);
            string ExpectedValue = "FC1.19";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestAddDigit5()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(17);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestAddDigit6()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(-12);
        }

        [TestMethod]
        public void TestAcc1()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(15);
            editor.addDigit(12);
            editor.addDigit(1);
            editor.addDelim();
            editor.addDigit(1);
            editor.addDigit(9);
            int ExpectedValue = 2;
            int ActualValue = editor.acc();
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAcc2()
        {
            Converter.Editor editor = new Converter.Editor();
            int ExpectedValue = 0;
            int ActualValue = editor.acc();
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAcc3()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDelim();
            editor.addDigit(1);
            editor.addDigit(9);
            editor.addDigit(9);
            editor.addDigit(9);
            editor.addDigit(9);
            int ExpectedValue = 5;
            int ActualValue = editor.acc();
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDelim1()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(15);
            editor.addDigit(15);
            editor.addDigit(15);
            editor.addDelim();
            editor.addDelim();
            editor.addDelim();
            editor.addDigit(15);
            editor.addDigit(15);
            editor.addDigit(15);
            editor.addDelim();
            editor.addDelim();
            editor.addDelim();
            string ExpectedValue = "FFF.FFF";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDelim2()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(0);
            editor.addDelim();
            editor.addDelim();
            editor.addDelim();
            editor.addDigit(0);
            editor.addDelim();
            editor.addDelim();
            editor.addDelim();
            string ExpectedValue = "0.0";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddDelim3()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDelim();
            editor.addDelim();
            editor.addDelim();
            string ExpectedValue = "0.";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestBs1()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.bs();
            editor.bs();
            editor.bs();
            editor.bs();
            editor.bs();
            string ExpectedValue = "0";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestBs2()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.bs();
            editor.bs();
            editor.bs();
            editor.bs();
            editor.bs();
            string ExpectedValue = "0";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestBs3()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(3);
            editor.addDigit(3);
            editor.addDigit(3);
            editor.addDelim();
            editor.bs();
            string ExpectedValue = "333";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestBs4()
        {
            Converter.Editor editor = new Converter.Editor();
            editor.addDigit(3);
            editor.addDigit(3);
            editor.addDigit(3);
            editor.addDelim();
            editor.addDigit(3);
            editor.addDigit(3);
            editor.addDigit(3);
            editor.bs();
            editor.bs();
            editor.bs();
            string ExpectedValue = "333.";
            string ActualValue = editor.Number;
            Assert.AreEqual(ExpectedValue, ActualValue);
        }
    }

    [TestClass]
    public class Test_History 
    {
        [TestMethod]
        public void TestAddRecord1()
        {
            Converter.History history = new Converter.History();
            history.addRecord(12, 4, "23.42", "52.42");
            Converter.History.Record ExpectedValue = new Converter.History.Record(12, 4, "23.42", "52.42");
            Converter.History.Record ActualValue = history[0];
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestAddRecord2()
        {
            Converter.History history = new Converter.History();
            history.addRecord(3, 7, "11.11", "11.11");
            Converter.History.Record ExpectedValue = new Converter.History.Record(3, 7, "11.11", "11.11");
            Converter.History.Record ActualValue = history[0];
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestOverride1()
        {
            Converter.History history = new Converter.History();
            history.addRecord(12, 4, "23.42", "52.42");
            history.addRecord(12, 4, "23.42", "52.42");
            history.addRecord(12, 4, "11", "11");
            Converter.History.Record ExpectedValue = new Converter.History.Record(12, 4, "11", "11");
            Converter.History.Record ActualValue = history[2];
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        public void TestOverride2()
        {
            Converter.History history = new Converter.History();
            history.addRecord(12, 4, "23.42", "52.42");
            history.addRecord(12, 4, "23.42", "52.42");
            history.addRecord(12, 4, "11", "11");
            Converter.History.Record ToOverride = new Converter.History.Record(1, 1, "1", "1");
            history[1] = ToOverride;
            Converter.History.Record ExpectedValue = new Converter.History.Record(1, 1, "1", "1");
            Converter.History.Record ActualValue = history[1];
            Assert.AreEqual(ExpectedValue, ActualValue);
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestOverride3()
        {
            Converter.History history = new Converter.History();
            history.addRecord(3, 7, "11.11", "11.11");
            Converter.History.Record Value = history[-1];
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestOverride4()
        {
            Converter.History history = new Converter.History();
            history.addRecord(3, 7, "11.11", "11.11");
            Converter.History.Record Value = history[1];
        }

        [TestMethod]
        [ExpectedException(typeof(System.IndexOutOfRangeException))]
        public void TestOverride5()
        {
            Converter.History history = new Converter.History();
            Converter.History.Record Value = new Converter.History.Record(12, 4, "11", "11");
            history[0] = Value;
        }
    }


}
