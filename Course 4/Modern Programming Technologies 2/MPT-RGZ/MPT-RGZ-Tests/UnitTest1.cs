using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using MPT_RGZ;

namespace MPT_RGZ_Tests
{
    [TestClass]
    public class TFracTest
    {
        [TestMethod]
        public void InitString1()
        {
            string fracString = "1/2";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }

        [TestMethod]
        public void InitString2()
        {
            string fracString = "111/2";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }

        [TestMethod]
        public void InitString3()
        {
            string fracString = "1/999";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }

        [TestMethod]
        public void InitString4()
        {
            string fracString = "100/10";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "10/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitString5()
        {
            string fracString = "-100/60";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "-5/3";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitString6()
        {
            string fracString = "00000003/000004";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "3/4";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber1()
        {
            TFrac fracClass = new TFrac(2, 4);
            string fracCompar = "1/2";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber2()
        {
            TFrac fracClass = new TFrac(17, 3);
            string fracCompar = "17/3";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber3()
        {
            TFrac fracClass = new TFrac(100, 100);
            string fracCompar = "1/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber4()
        {
            TFrac fracClass = new TFrac(-100, -99);
            string fracCompar = "100/99";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber5()
        {
            TFrac fracClass = new TFrac(0, 0);
            string fracCompar = "0/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitNumber6()
        {
            TFrac fracClass = new TFrac(100, -5);
            string fracCompar = "-20/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }

        [TestMethod]
        public void InitCopy1()
        {
            TFrac fracClass = new TFrac(100, -5);
            TFrac copyClass = new TFrac(fracClass);
            Assert.AreEqual(fracClass.ToString(), copyClass.ToString());
        }

        [TestMethod]
        public void InitCopy2()
        {
            TFrac fracClass = new TFrac(1, 4);
            TFrac copyClass = new TFrac(fracClass);
            Assert.AreEqual(fracClass.ToString(), copyClass.ToString());
        }

        [TestMethod]
        public void Add1()
        {
            TFrac fracClass1 = new TFrac(1, 2);
            TFrac fracClass2 = new TFrac(-3, 4);
            fracClass2 = fracClass1.Add(fracClass2);
            string answer = "-1/4";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Add2()
        {
            TFrac fracClass1 = new TFrac(-1, 2);
            TFrac fracClass2 = new TFrac(-1, 2);
            fracClass2 = fracClass1.Add(fracClass2);
            string answer = "-1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Add3()
        {
            TFrac fracClass1 = new TFrac(-6, 2);
            TFrac fracClass2 = new TFrac(6, 2);
            fracClass2 = fracClass1.Add(fracClass2);
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Add4()
        {
            TFrac fracClass1 = new TFrac(50, 3);
            TFrac fracClass2 = new TFrac(0, 1);
            fracClass2 = fracClass1.Add(fracClass2);
            string answer = "50/3";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Multiply1()
        {
            TFrac fracClass1 = new TFrac(-1, 2);
            TFrac fracClass2 = new TFrac(-1, 2);
            fracClass2 = fracClass1.Mul(fracClass2);
            string answer = "1/4";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Multiply2()
        {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            fracClass2 = fracClass1.Mul(fracClass2);
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Multiply3()
        {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(1, 6);
            fracClass2 = fracClass1.Mul(fracClass2);
            string answer = "1/36";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Multiply4()
        {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(12, 1);
            fracClass2 = fracClass1.Mul(fracClass2);
            string answer = "-2/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Substract1()
        {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1.Sub(fracClass2);
            string answer = "-1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Substract2()
        {
            TFrac fracClass1 = new TFrac(5, 1);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1.Sub(fracClass2);
            string answer = "4/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Substract3()
        {
            TFrac fracClass1 = new TFrac(1, 2);
            TFrac fracClass2 = new TFrac(1, 2);
            fracClass2 = fracClass1.Sub(fracClass2);
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Substract4()
        {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(-1, 6);
            fracClass2 = fracClass1.Sub(fracClass2);
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide1()
        {
            TFrac fracClass1 = new TFrac(5, 6);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "5/6";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide2()
        {
            TFrac fracClass1 = new TFrac(1, 1);
            TFrac fracClass2 = new TFrac(5, 6);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "6/5";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide3()
        {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(5, 6);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide4()
        {
            TFrac fracClass1 = new TFrac(2, 3);
            TFrac fracClass2 = new TFrac(7, 4);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "8/21";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide5()
        {
            TFrac fracClass1 = new TFrac(2, 3);
            TFrac fracClass2 = new TFrac(2, 3);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide6()
        {
            TFrac fracClass1 = new TFrac(-1, 3);
            TFrac fracClass2 = new TFrac(-9, 5);
            fracClass2 = fracClass1.Div(fracClass2);
            string answer = "5/27";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Reverse1()
        {
            TFrac fracClass = new TFrac(-2, 3);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "-3/2";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Reverse2()
        {
            TFrac fracClass = new TFrac(0, 1);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Reverse3()
        {
            TFrac fracClass = new TFrac(5, 6);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "6/5";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Square1()
        {
            TFrac fracClass = new TFrac(1, 3);
            fracClass = fracClass.Square() as TFrac;
            string answer = "1/9";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Square2()
        {
            TFrac fracClass = new TFrac(0, 1);
            fracClass = fracClass.Square() as TFrac;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Square3()
        {
            TFrac fracClass = new TFrac(-2, 3);
            fracClass = fracClass.Square() as TFrac;
            string answer = "4/9";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Equal1()
        {
            TFrac fracClass1 = new TFrac(1, 3);
            TFrac fracClass2 = new TFrac(1, 3);
            Assert.IsTrue(fracClass1.Equal(fracClass2));
        }

        [TestMethod]
        public void Equal2()
        {
            TFrac fracClass1 = new TFrac(0, 6);
            TFrac fracClass2 = new TFrac(1, 6);
            Assert.IsFalse(fracClass1.Equal(fracClass2));
        }

        [TestMethod]
        public void Equal3()
        {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(-1, 6);
            Assert.IsTrue(fracClass1.Equal(fracClass2));
        }

        [TestMethod]
        public void Equal4()
        {
            TFrac fracClass1 = new TFrac(-1, 7);
            TFrac fracClass2 = new TFrac(1, 7);
            Assert.IsFalse(fracClass1.Equal(fracClass2));
        }

        [TestMethod]
        public void Equal5()
        {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1.Equal(fracClass2));
        }

        [TestMethod]
        public void Greater1()
        {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsTrue(fracClass1 > fracClass2);
        }

        [TestMethod]
        public void Greater2()
        {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1 > fracClass2);
        }

        [TestMethod]
        public void Greater3()
        {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1 > fracClass2);
        }

        [TestMethod]
        public void Greater4()
        {
            TFrac fracClass1 = new TFrac(17, 3);
            TFrac fracClass2 = new TFrac(16, 3);
            Assert.IsTrue(fracClass1 > fracClass2);
        }

        [TestMethod]
        public void Greater5()
        {
            TFrac fracClass1 = new TFrac(-2, 3);
            TFrac fracClass2 = new TFrac(-1, 3);
            Assert.IsFalse(fracClass1 > fracClass2);
        }
    }

    [TestClass]
    public class FracEditorTest
    {
        [TestMethod]
        public void TestInit1()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "3/4";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit2()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "-16/3";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit3()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "0/8";
            testClass.Fraction = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit4()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "-17/4";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit5()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "0/1";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit6()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "666/6666";
            testClass.Fraction = input;
            string result = "111/1111";
            Assert.AreEqual(result, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit7()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "aaaa";
            testClass.Fraction = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit8()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "0/1";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit9()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "0/1";
            testClass.Fraction = input;
            Assert.AreEqual(input, testClass.Fraction);
        }
        [TestMethod]
        public void TestInit10()
        {
            TFracEditor testClass = new TFracEditor();
            string input = "16/000000";
            testClass.Fraction = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Fraction);
        }

        [TestMethod]
        public void hasZero1()
        {
            TFracEditor testClass = new TFracEditor("14/3");
            Assert.AreEqual(false, testClass.hasZero());
        }
        [TestMethod]
        public void hasZero2()
        {
            TFracEditor testClass = new TFracEditor("16/00000");
            Assert.AreEqual(true, testClass.hasZero());
        }

        [TestMethod]
        public void ToogleMinus1()
        {
            TFracEditor testClass = new TFracEditor("14/3");
            testClass.AddSign();
            string result = "-14/3";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void ToogleMinus2()
        {
            TFracEditor testClass = new TFracEditor("-14/3");
            testClass.AddSign();
            string result = "14/3";
            Assert.AreEqual(result, testClass.ToString());
        }

        [TestMethod]
        public void AddDeleteTest1()
        {
            TFracEditor testClass = new TFracEditor("123/123");
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddSeparator();
            testClass.AddSign();
            string result = "-1/1013";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest2()
        {
            TFracEditor testClass = new TFracEditor(123, 123);
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.RemoveSymbol();
            testClass.AddNumber(1);
            testClass.AddNumber(2);
            testClass.AddNumber(3);
            testClass.AddNumber(4);
            testClass.AddNumber(5);
            testClass.AddSeparator();
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            string result = "12345/1111";
            Assert.AreEqual(result, testClass.ToString());
        }

        [TestMethod]
        public void AddDeleteTest3()
        {
            TFracEditor testClass = new TFracEditor(1234567, 12345678);
            for (int i = 0; i < 100; ++i)
                testClass.RemoveSymbol();
            for (int i = 0; i < 100; ++i)
                testClass.AddSeparator();
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            testClass.AddNumber(1);
            string result = "0/1111";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest4()
        {
            TFracEditor testClass = new TFracEditor("0/1");
            for (int i = 0; i < 100; ++i)
                testClass.AddNumber(i);
            string result = "0/10123456789";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void Clear()
        {
            TFracEditor testClass = new TFracEditor("2345678/345678");
            testClass.Clear();
            string result = "0";
            Assert.AreEqual(result, testClass.ToString());
        }
    }

    [TestClass]
    public class TMemoryTest
    {
        [TestMethod]
        public void InitAndOutput1()
        {
            TFrac frac = new TFrac(22, 33);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "2/3";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        [TestMethod]
        public void InitAndOutput2()
        {
            TFrac frac = new TFrac();
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "0/1";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        [TestMethod]
        public void InitAndOutput3()
        {
            TFrac frac = new TFrac(-1, 5);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "-1/5";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }

        [TestMethod]
        public void Sum1()
        {
            TFrac frac = new TFrac(-1, 5);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TFrac summator = new TFrac(1, 2);
            memory.Add(summator);
            string answer = "3/10";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }

        [TestMethod]
        public void Sum2()
        {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TFrac summator = new TFrac(-16, 3);
            memory.Add(summator);
            string answer = "-40/9";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }

        [TestMethod]
        public void TestFState1()
        {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            memory.Clear();
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.OFF;
            Assert.AreEqual(expected, memory.FState);
        }

        [TestMethod]
        public void TestFState2()
        {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.OFF;
            Assert.AreEqual(expected, memory.FState);
        }

        [TestMethod]
        public void TestFState3()
        {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            memory.Add(frac);
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.ON;
            Assert.AreEqual(expected, memory.FState);
        }
    }

    [TestClass]
    public class TProcTest
    {
        [TestMethod]
        public void Init1()
        {
            TFrac leftFrac = new TFrac();
            TFrac rightFrac = new TFrac();
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "0/1";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
            Assert.AreEqual(answer, proc.Rop.ToString());
        }

        [TestMethod]
        public void Init2()
        {
            TFrac leftFrac = new TFrac(11, 3);
            TFrac rightFrac = new TFrac();
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "11/3";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }

        [TestMethod]
        public void Init3()
        {
            TFrac leftFrac = new TFrac(16, 4);
            TFrac rightFrac = new TFrac(17, 9);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "17/9";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }

        [TestMethod]
        public void Operation1()
        {
            TFrac leftFrac = new TFrac(1, 2);
            TFrac rightFrac = new TFrac(1, 2);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.TOprtn.Add;
            proc.DoOper();
            string answer = "1/1";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }

        [TestMethod]
        public void Operation2()
        {
            TFrac leftFrac = new TFrac(3, 4);
            TFrac rightFrac = new TFrac(5, 6);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.TOprtn.Sub;
            proc.DoOper();
            string answer = "-1/12";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }

        [TestMethod]
        public void Operation3()
        {
            TFrac leftFrac = new TFrac(12, 7);
            TFrac rightFrac = new TFrac(5, 9);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.TOprtn.Mul;
            proc.DoOper();
            string answer = "20/21";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }

        [TestMethod]
        public void Operation4()
        {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.TOprtn.Div;
            proc.DoOper();
            string answer = "-12/11";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }

        [TestMethod]
        public void TestFState1()
        {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.DoFunc(TProc<TFrac>.TFunc.Rev);
            string answer = "-3/22";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }

        [TestMethod]
        public void TestFState2()
        {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.DoFunc(TProc<TFrac>.TFunc.Sqr);
            string answer = "484/9";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }
    }
}
