using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using Calculator;

namespace Test
{
    [TestClass]
    public class TFracTest 
    {
        [TestMethod]
        public void InitString1() {
            string fracString = "1/2";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }
        [TestMethod]
        public void InitString2() {
            string fracString = "111/2";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }
        [TestMethod]
        public void InitString3() {
            string fracString = "1/999";
            TFrac fracClass = new TFrac(fracString);
            Assert.AreEqual(fracString, fracClass.ToString());
        }
        [TestMethod]
        public void InitString4() {
            string fracString = "100/10";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "10/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitString5() {
            string fracString = "-100/60";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "-5/3";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitString6() {
            string fracString = "00000003/000004";
            TFrac fracClass = new TFrac(fracString);
            string fracCompar = "3/4";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber1() {
            TFrac fracClass = new TFrac(2, 4);
            string fracCompar = "1/2";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber2() {
            TFrac fracClass = new TFrac(17, 9);
            string fracCompar = "17/9";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber3() {
            TFrac fracClass = new TFrac(100, 100);
            string fracCompar = "1/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber4() {
            TFrac fracClass = new TFrac(-100, -99);
            string fracCompar = "100/99";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber5() {
            TFrac fracClass = new TFrac(0, 0);
            string fracCompar = "0/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitNumber6() {
            TFrac fracClass = new TFrac(100, -5);
            string fracCompar = "-20/1";
            Assert.AreEqual(fracCompar, fracClass.ToString());
        }
        [TestMethod]
        public void InitCopy1() {
            TFrac fracClass = new TFrac(100, -5);
            TFrac copyClass = new TFrac(fracClass);
            Assert.AreEqual(fracClass.ToString(), copyClass.ToString());
        }
        [TestMethod]
        public void InitCopy2() {
            TFrac fracClass = new TFrac(1, 4);
            TFrac copyClass = new TFrac(fracClass);
            Assert.AreEqual(fracClass.ToString(), copyClass.ToString());
        }

        [TestMethod]
        public void Add1() {
            TFrac fracClass1 = new TFrac(1, 2);
            TFrac fracClass2 = new TFrac(-3, 4);
            fracClass2 = fracClass1 + fracClass2;
            string answer = "-1/4";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Add2() {
            TFrac fracClass1 = new TFrac(-1, 2);
            TFrac fracClass2 = new TFrac(-1, 2);
            fracClass2 = fracClass1 + fracClass2;
            string answer = "-1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Add3() {
            TFrac fracClass1 = new TFrac(-6, 2);
            TFrac fracClass2 = new TFrac(6, 2);
            fracClass2 = fracClass1 + fracClass2;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Add4() {
            TFrac fracClass1 = new TFrac(50, 3);
            TFrac fracClass2 = new TFrac(0, 1);
            fracClass2 = fracClass1 + fracClass2;
            string answer = "50/3";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Multiply1() {
            TFrac fracClass1 = new TFrac(-1, 2);
            TFrac fracClass2 = new TFrac(-1, 2);
            fracClass2 = fracClass1 * fracClass2;
            string answer = "1/4";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Multiply2() {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            fracClass2 = fracClass1 * fracClass2;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Multiply3() {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(1, 6);
            fracClass2 = fracClass1 * fracClass2;
            string answer = "1/36";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Multiply4() {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(12, 1);
            fracClass2 = fracClass1 * fracClass2;
            string answer = "-2/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Substract1() {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1 - fracClass2;
            string answer = "-1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Substract2() {
            TFrac fracClass1 = new TFrac(5, 1);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1 - fracClass2;
            string answer = "4/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Substract3() {
            TFrac fracClass1 = new TFrac(1, 2);
            TFrac fracClass2 = new TFrac(1, 2);
            fracClass2 = fracClass1 - fracClass2;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Substract4() {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(-1, 6);
            fracClass2 = fracClass1 - fracClass2;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        [TestMethod]
        public void Divide1() {
            TFrac fracClass1 = new TFrac(5, 6);
            TFrac fracClass2 = new TFrac(1, 1);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "5/6";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Divide2() {
            TFrac fracClass1 = new TFrac(1, 1);
            TFrac fracClass2 = new TFrac(5, 6);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "6/5";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Divide3() {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(5, 6);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Divide4() {
            TFrac fracClass1 = new TFrac(2, 3);
            TFrac fracClass2 = new TFrac(7, 4);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "8/21";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Divide5() {
            TFrac fracClass1 = new TFrac(2, 3);
            TFrac fracClass2 = new TFrac(2, 3);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "1/1";
            Assert.AreEqual(answer, fracClass2.ToString());
        }
        [TestMethod]
        public void Divide6() {
            TFrac fracClass1 = new TFrac(-1, 3);
            TFrac fracClass2 = new TFrac(-9, 5);
            fracClass2 = fracClass1 / fracClass2;
            string answer = "5/27";
            Assert.AreEqual(answer, fracClass2.ToString());
        }

        #region Other Functions Test
        [TestMethod]
        public void Reverse1() {
            TFrac fracClass = new TFrac(-2, 3);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "-3/2";
            Assert.AreEqual(answer, fracClass.ToString());
        }
        [TestMethod]
        public void Reverse2() {
            TFrac fracClass = new TFrac(0, 1);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass.ToString());
        }
        [TestMethod]
        public void Reverse3() {
            TFrac fracClass = new TFrac(5, 6);
            fracClass = fracClass.Reverse() as TFrac;
            string answer = "6/5";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        [TestMethod]
        public void Square1() {
            TFrac fracClass = new TFrac(1, 3);
            fracClass = fracClass.Square() as TFrac;
            string answer = "1/9";
            Assert.AreEqual(answer, fracClass.ToString());
        }
        [TestMethod]
        public void Square2() {
            TFrac fracClass = new TFrac(0, 1);
            fracClass = fracClass.Square() as TFrac;
            string answer = "0/1";
            Assert.AreEqual(answer, fracClass.ToString());
        }
        [TestMethod]
        public void Square3() {
            TFrac fracClass = new TFrac(-2, 3);
            fracClass = fracClass.Square() as TFrac;
            string answer = "4/9";
            Assert.AreEqual(answer, fracClass.ToString());
        }

        #endregion

        #region Test Compare Operators
        [TestMethod]
        public void Equal1() {
            TFrac fracClass1 = new TFrac(1, 3);
            TFrac fracClass2 = new TFrac(1, 3);
            Assert.IsTrue(fracClass1 == fracClass2);
        }
        [TestMethod]
        public void Equal2() {
            TFrac fracClass1 = new TFrac(0, 6);
            TFrac fracClass2 = new TFrac(1, 6);
            Assert.IsFalse(fracClass1 == fracClass2);
        }
        [TestMethod]
        public void Equal3() {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(-1, 6);
            Assert.IsTrue(fracClass1 == fracClass2);
        }
        [TestMethod]
        public void Equal4() {
            TFrac fracClass1 = new TFrac(-1, 7);
            TFrac fracClass2 = new TFrac(1, 7);
            Assert.IsFalse(fracClass1 == fracClass2);
        }
        [TestMethod]
        public void Equal5() {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1 == fracClass2);
        }
        [TestMethod]
        public void Greater1() {
            TFrac fracClass1 = new TFrac(1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsTrue(fracClass1 > fracClass2);
        }
        [TestMethod]
        public void Greater2() {
            TFrac fracClass1 = new TFrac(0, 1);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1 > fracClass2);
        }
        [TestMethod]
        public void Greater3() {
            TFrac fracClass1 = new TFrac(-1, 6);
            TFrac fracClass2 = new TFrac(0, 1);
            Assert.IsFalse(fracClass1 > fracClass2);
        }
        [TestMethod]
        public void Greater4() {
            TFrac fracClass1 = new TFrac(17, 3);
            TFrac fracClass2 = new TFrac(16, 3);
            Assert.IsTrue(fracClass1 > fracClass2);
        }
        [TestMethod]
        public void Greater5() {
            TFrac fracClass1 = new TFrac(-2, 3);
            TFrac fracClass2 = new TFrac(-1, 3);
            Assert.IsFalse(fracClass1 > fracClass2);
        }
        #endregion
    }

    #region Test FracEditor
    [TestClass]
    public class FracEditorTest {
        #region Test Constructor
        [TestMethod]
        public void TestInit1() {
            FracEditor testClass = new FracEditor();
            string input = "3/4";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit2() {
            FracEditor testClass = new FracEditor();
            string input = "-16/3";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit3() {
            FracEditor testClass = new FracEditor();
            string input = "0/8";
            testClass.Number = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Number);
        }
        [TestMethod]
        public void TestInit4() {
            FracEditor testClass = new FracEditor();
            string input = "-17/4";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit5() {
            FracEditor testClass = new FracEditor();
            string input = "0/1";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit6() {
            FracEditor testClass = new FracEditor();
            string input = "666/6666";
            testClass.Number = input;
            string result = "111/1111";
            Assert.AreEqual(result, testClass.Number);
        }
        [TestMethod]
        public void TestInit7() {
            FracEditor testClass = new FracEditor();
            string input = "aaaa";
            testClass.Number = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Number);
        }
        [TestMethod]
        public void TestInit8() {
            FracEditor testClass = new FracEditor();
            string input = "0/1";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit9() {
            FracEditor testClass = new FracEditor();
            string input = "0/1";
            testClass.Number = input;
            Assert.AreEqual(input, testClass.Number);
        }
        [TestMethod]
        public void TestInit10() {
            FracEditor testClass = new FracEditor();
            string input = "16/000000";
            testClass.Number = input;
            string result = "0/1";
            Assert.AreEqual(result, testClass.Number);
        }
        #endregion

        #region Test Override Methods
        [TestMethod]
        public void IsZero1() {
            FracEditor testClass = new FracEditor("14/3");
            Assert.AreEqual(false, testClass.IsZero());
        }
        [TestMethod]
        public void IsZero2() {
            FracEditor testClass = new FracEditor("16/00000");
            Assert.AreEqual(true, testClass.IsZero());
        }

        [TestMethod]
        public void ToogleMinus1() {
            FracEditor testClass = new FracEditor("14/3");
            testClass.ToogleSign();
            string result = "-14/3";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void ToogleMinus2() {
            FracEditor testClass = new FracEditor("-14/3");
            testClass.ToogleSign();
            string result = "14/3";
            Assert.AreEqual(result, testClass.ToString());
        }
        #endregion
        #region Test Input/Delete
        [TestMethod]
        public void AddDeleteTest1() {
            FracEditor testClass = new FracEditor("123/123");
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddSeparator();
            testClass.ToogleSign();
            string result = "-1/1013";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest2() {
            FracEditor testClass = new FracEditor(123, 123);
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
        public void AddDeleteTest3() {
            FracEditor testClass = new FracEditor(1234567, 12345678);
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
        public void AddDeleteTest4() {
            FracEditor testClass = new FracEditor("0/1");
            for (int i = 0; i < 100; ++i)
                testClass.AddNumber(i);
            string result = "0/10123456789";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void Clear() {
            FracEditor testClass = new FracEditor("2345678/345678");
            testClass.Clear();
            string result = "0";
            Assert.AreEqual(result, testClass.ToString());
        }
        #endregion
    }
    #endregion

    #region Test Memory
    [TestClass]
    public class TMemoryTest {
        #region Test Init and Output
        [TestMethod]
        public void InitAndOutput1() {
            TFrac frac = new TFrac(22, 33);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "2/3";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        [TestMethod]
        public void InitAndOutput2() {
            TFrac frac = new TFrac();
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "0/1";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        [TestMethod]
        public void InitAndOutput3() {
            TFrac frac = new TFrac(-1, 5);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            string answer = "-1/5";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        #endregion
        #region Test Sum
        [TestMethod]
        public void Sum1() {
            TFrac frac = new TFrac(-1, 5);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TFrac summator = new TFrac(1, 2);
            memory.Add(summator);
            string answer = "3/10";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        [TestMethod]
        public void Sum2() {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TFrac summator = new TFrac(-16, 3);
            memory.Add(summator);
            string answer = "-40/9";
            Assert.AreEqual(answer, memory.FNumber.ToString());
        }
        #endregion

        #region Test FState Handling
        [TestMethod]
        public void TestFState1() {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            memory.Clear();
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.OFF;
            Assert.AreEqual(expected, memory.FState);
        }
        [TestMethod]
        public void TestFState2() {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.OFF;
            Assert.AreEqual(expected, memory.FState);
        }
        [TestMethod]
        public void TestFState3() {
            TFrac frac = new TFrac(8, 9);
            TMemory<TFrac> memory = new TMemory<TFrac>(frac);
            memory.Add(frac);
            TMemory<TFrac>.NumStates expected = TMemory<TFrac>.NumStates.ON;
            Assert.AreEqual(expected, memory.FState);
        }
        #endregion
    }
    #endregion

    #region Test Proc
    [TestClass]
    public class TProcTest {
        #region Test Init and Output
        [TestMethod]
        public void Init1() {
            TFrac leftFrac = new TFrac();
            TFrac rightFrac = new TFrac();
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "0/1";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
            Assert.AreEqual(answer, proc.Rop.ToString());
        }
        [TestMethod]
        public void Init2() {
            TFrac leftFrac = new TFrac(11, 3);
            TFrac rightFrac = new TFrac();
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "11/3";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }
        [TestMethod]
        public void Init3() {
            TFrac leftFrac = new TFrac(16, 4);
            TFrac rightFrac = new TFrac(17, 9);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            string answer = "17/9";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }
        #endregion
        #region Test Operation
        [TestMethod]
        public void Operation1() {
            TFrac leftFrac = new TFrac(1, 2);
            TFrac rightFrac = new TFrac(1, 2);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.Oper.Add;
            proc.DoOper();
            string answer = "1/1";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }
        [TestMethod]
        public void Operation2() {
            TFrac leftFrac = new TFrac(3, 4);
            TFrac rightFrac = new TFrac(5, 6);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.Oper.Sub;
            proc.DoOper();
            string answer = "-1/12";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }
        [TestMethod]
        public void Operation3() {
            TFrac leftFrac = new TFrac(12, 7);
            TFrac rightFrac = new TFrac(5, 9);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.Oper.Mul;
            proc.DoOper();
            string answer = "20/21";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }
        [TestMethod]
        public void Operation4() {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.Operation = TProc<TFrac>.Oper.Div;
            proc.DoOper();
            string answer = "-12/11";
            Assert.AreEqual(answer, proc.Lop_Res.ToString());
        }
        #endregion

        #region Test Function
        [TestMethod]
        public void TestFState1() {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.DoFunc(TProc<TFrac>.Func.Rev);
            string answer = "-3/22";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }
        [TestMethod]
        public void TestFState2() {
            TFrac leftFrac = new TFrac(56, 7);
            TFrac rightFrac = new TFrac(-22, 3);
            TProc<TFrac> proc = new TProc<TFrac>(leftFrac, rightFrac);
            proc.DoFunc(TProc<TFrac>.Func.Sqr);
            string answer = "484/9";
            Assert.AreEqual(answer, proc.Rop.ToString());
        }
        #endregion
    }
    #endregion

    #region Test PNumber
    [TestClass]
    public class TPNumberTest {
        #region Test Constructors
        [TestMethod]
        public void Init1() {
            TPNumber tPNumber = new TPNumber(10, 10, 3);
            string answer = "10";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init2() {
            TPNumber tPNumber = new TPNumber("-12100.11201002", 3, 8);
            string answer = "-12100.11201002";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init3() {
            TPNumber tPNumber = new TPNumber(16, 16, 3);
            string answer = "10";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init4() {
            TPNumber tPNumber = new TPNumber(255, 2, 3);
            string answer = "11111111";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init5() {
            TPNumber tPNumber = new TPNumber(14.471, 7, 5);
            string answer = "20.32036";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init6() {
            TPNumber tPNumber = new TPNumber(145.1742, 15, 8);
            string answer = "9A.292DD1D1";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init7() {
            TPNumber tPNumber = new TPNumber(36.09, 16, 2);
            string answer = "24.17";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init8() {
            TPNumber tPNumber = new TPNumber(88.88, 8, 9);
            string answer = "130.70243656";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init9() {
            TPNumber tPNumber = new TPNumber(256.256, 2, 5);
            string answer = "100000000.01";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init10() {
            TPNumber tPNumber = new TPNumber(-356.22, 10, 5);
            string answer = "-356.22";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init11() {
            TPNumber tPNumber = new TPNumber(0, 2, 1);
            string answer = "0";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        [TestMethod]
        public void Init12() {
            TPNumber tPNumber = new TPNumber("A3.158", 12, 3);
            string answer = "A3.158";
            Assert.AreEqual(answer, tPNumber.ToString());
        }
        #endregion

        #region Test Math Operators
        [TestMethod]
        public void Add1() {
            TPNumber class1 = new TPNumber(15, 7, 5);
            TPNumber class2 = new TPNumber(66.66, 7, 5);
            class1 = class1 + class2;
            double answer = 81.66;
            Assert.AreEqual(answer, class1.Number.Number);
        }
        [TestMethod]
        public void Add2() {
            TPNumber class1 = new TPNumber(12, 16, 10);
            TPNumber class2 = new TPNumber(-13, 3, 6);
            class1 = class1 + class2;
            double answer = -1;
            Assert.AreEqual(answer, class1.Number.Number);
        }

        [TestMethod]
        public void Multiply1() {
            TPNumber class1 = new TPNumber(12.23, 7, 5);
            TPNumber class2 = new TPNumber(-6.66, 7, 5);
            class1 = class1 * class2;
            double answer = -81.4518;
            Assert.AreEqual(answer, class1.Number.Number);
        }
        [TestMethod]
        public void Multiply2() {
            TPNumber class1 = new TPNumber(15.6, 16, 11);
            TPNumber class2 = new TPNumber(0, 7, 5);
            class1 = class1 - class2;
            double answer = 0;
            Assert.AreEqual(answer, class1.Number.Number);
        }

        [TestMethod]
        public void Substract1() {
            TPNumber class1 = new TPNumber(12.23, 7, 5);
            TPNumber class2 = new TPNumber(6.66, 7, 5);
            class1 = class1 - class2;
            double answer = 5.57;
            Assert.AreEqual(answer, class1.Number.Number);
        }
        [TestMethod]
        public void Substract2() {
            TPNumber class1 = new TPNumber(12.22, 16, 10);
            TPNumber class2 = new TPNumber(-6.67, 7, 5);
            class1 = class1 - class2;
            double answer = 18.89;
            Assert.AreEqual(answer, class1.Number.Number);
        }

        [TestMethod]
        public void Divide1() {
            TPNumber class1 = new TPNumber(3, 7, 5);
            TPNumber class2 = new TPNumber(8, 7, 5);
            class1 = class1 / class2;
            double answer = 0.375;
            Assert.AreEqual(answer, class1.Number.Number);
        }
        [TestMethod]
        public void Divide2() {
            TPNumber class1 = new TPNumber(666, 16, 5);
            TPNumber class2 = new TPNumber(-333, 2, 5);
            class1 = class1 / class2;
            double answer = -2;
            Assert.AreEqual(answer, class1.Number.Number);
        }
        #endregion

        #region Other Functions Test
        [TestMethod]
        public void Square1() {
            TPNumber testClass = new TPNumber(-1.57, 7, 5);
            testClass = testClass.Square() as TPNumber;
            double answer = 2.4649;
            Assert.AreEqual(answer, testClass.Number.Number);
        }
        #endregion
    }
    #endregion

    #region Test PNumberEditor
    [TestClass]
    public class PNumberEditorTest {
        #region Test Constructors
        [TestMethod]
        public void Init1() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "2.3F";
            edit.Number = Input;
            string Output = Input;
            Assert.AreEqual(Output, edit.Number);
        }
        [TestMethod]
        public void Init2() {
            PNumberEditor edit = new PNumberEditor(0.0f, 2, 5);
            string Input = "11101.01011";
            edit.Number = Input;
            string Output = Input;
            Assert.AreEqual(Output, edit.Number);
        }
        [TestMethod]
        public void Init3() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "-FF.FF";
            edit.Number = Input;
            string Output = Input;
            Assert.AreEqual(Output, edit.Number);
        }
        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Init4() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "aaaaaaaaaaaaa";
            edit.Number = Input;
        }
        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Init5() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "16.ppppp";
            edit.Number = Input;
        }
        [ExpectedException(typeof(IndexOutOfRangeException))]
        [TestMethod]
        public void Init6() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "FFZZZ";
            edit.Number = Input;
        }
        [TestMethod]
        public void Init7() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "888.8888";
            edit.Number = Input;
            string Output = Input;
            Assert.AreEqual(Output, edit.Number);
        }
        [TestMethod]
        public void Init8() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "-01.03";
            edit.Number = Input;
            string Output = "-1.03";
            Assert.AreEqual(Output, edit.Number);
        }
        [TestMethod]
        public void Init9() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "-9992D.DDDD";
            edit.Number = Input;
            string Output = Input;
            Assert.AreEqual(Output, edit.Number);
        }
        [TestMethod]
        public void Init10() {
            PNumberEditor edit = new PNumberEditor(0.0f, 16, 5);
            string Input = "7777.7777";
            edit.Number = Input;
            string Output = "7777.7777";
            Assert.AreEqual(Output, edit.Number);
        }
        #endregion

        #region Test Input/Delete
        [TestMethod]
        public void AddDeleteTest1() {
            PNumberEditor testClass = new PNumberEditor();
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddSeparator();
            testClass.ToogleSign();
            string result = "-13.";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest2() {
            PNumberEditor testClass = new PNumberEditor(0.0f, 16, 5);
            for (int i = 0; i < 16; ++i)
                testClass.AddNumber(i);
            string result = "123456789ABCDEF";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest3() {
            PNumberEditor testClass = new PNumberEditor(0.0f, 16, 5);
            for (int i = 0; i < 100; ++i)
                testClass.RemoveSymbol();
            testClass.AddSeparator();
            testClass.AddSeparator();
            testClass.AddSeparator();
            testClass.AddNumber(15);
            string result = "0.F";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest4() {
            PNumberEditor testClass = new PNumberEditor(0.0f, 2, 5);
            for (int i = 2; i < 100; ++i)
                testClass.AddNumber(i);
            string result = "0";
            Assert.AreEqual(result, testClass.ToString());
        }
        #endregion
    }
    #endregion

    #region Test TComplex
    [TestClass]
    public class TComplexTest {
        #region Test Init
        [TestMethod]
        public void Init1() {
            TComplex testClass = new TComplex(6, 3);
            string output = "6 + i * 3";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init2() {
            TComplex testClass = new TComplex(0, 0);
            string output = "0 + i * 0";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init3() {
            TComplex testClass = new TComplex(3, -2);
            string output = "3 + i * -2";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init4() {
            TComplex testClass = new TComplex(4.01, 6);
            string output = "4.01 + i * 6";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init5() {
            TComplex testClass = new TComplex(-3.02, 7);
            string output = "-3.02 + i * 7";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init6() {
            TComplex testClass = new TComplex(0, -22.22);
            string output = "0 + i * -22.22";
            Assert.AreEqual(output, testClass.ToString());
        }
        #endregion

        #region Test Operations (Square/Reverse/Abs/GetRad/GetDegree/Pow/Root)
        [TestMethod]
        public void Reverse1() {
            TComplex testClass = new TComplex(0, -3);
            testClass = testClass.Reverse() as TComplex;
            string output = "0 + i * 0.333";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Reverse2() {
            TComplex testClass = new TComplex(3, 4);
            testClass = testClass.Reverse() as TComplex;
            string output = "0.12 + i * -0.16";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Square1() {
            TComplex testClass = new TComplex(3, 4);
            testClass = testClass.Square() as TComplex;
            string output = "-7 + i * 24";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Square2() {
            TComplex testClass = new TComplex(0, -3);
            testClass = testClass.Square() as TComplex;
            string output = "-9 + i * 0";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Abs1() {
            TComplex testClass = new TComplex(3, 4);
            double answer = 5;
            Assert.AreEqual(answer, testClass.Abs(), 4);
        }
        [TestMethod]
        public void Abs2() {
            TComplex testClass = new TComplex(0, -3);
            double answer = 3;
            Assert.AreEqual(answer, testClass.Abs(), 4);
        }
        [TestMethod]
        public void GetRad1() {
            TComplex testClass = new TComplex(3, 4);
            double answer = 0.927295;
            Assert.AreEqual(answer, testClass.GetRad(), 4);
        }
        [TestMethod]
        public void GetRad2() {
            TComplex testClass = new TComplex(0, -3);
            double answer = -1.570796;
            Assert.AreEqual(answer, testClass.GetRad(), 4);
        }
        [TestMethod]
        public void GetDegree1() {
            TComplex testClass = new TComplex(3, 4);
            double answer = 53.1301;
            Assert.AreEqual(answer, testClass.GetDegree(), 4);
        }
        [TestMethod]
        public void GetDegree2() {
            TComplex testClass = new TComplex(0, -3);
            double answer = -90;
            Assert.AreEqual(answer, testClass.GetDegree(), 4);
        }
        [TestMethod]
        public void Pow1() {
            TComplex testClass = new TComplex(3, 4);
            testClass = testClass.Pwr(5);
            string output = "-237 + i * -3116";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Pow2() {
            TComplex testClass = new TComplex(0, -3);
            testClass = testClass.Pwr(5);
            string output = "0 + i * -243";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Root1() {
            TComplex testClass = new TComplex(3, 4);
            testClass = testClass.Root(5, 3);
            string output = "-0.353 + i * 1.334";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Root2() {
            TComplex testClass = new TComplex(16, -2);
            testClass = testClass.Root(10, 4);
            string output = "-0.301 + i * 1.286";
            Assert.AreEqual(output, testClass.ToString());
        }
        #endregion
    }
    #endregion

    #region Test ComplexEditor
    [TestClass]
    public class ComplexEditorTest {
        #region Constructors
        [TestMethod]
        public void Init1() {
            ComplexEditor testClass = new ComplexEditor();
            string input = "10.3";
            testClass.Number = input;
            string output = "10.3 + i * 0";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init2() {
            ComplexEditor testClass = new ComplexEditor();
            string input = "10. + i * -12.";
            testClass.Number = input;
            string output = "10 + i * -12";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init3() {
            ComplexEditor testClass = new ComplexEditor();
            string input = "-0 + i * -0";
            testClass.Number = input;
            string output = "0 + i * 0";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init4() {
            ComplexEditor testClass = new ComplexEditor();
            string input = "66.66 + i * 66.66";
            testClass.Number = input;
            string output = "66.66 + i * 66.66";
            Assert.AreEqual(output, testClass.ToString());
        }
        [TestMethod]
        public void Init5() {
            ComplexEditor testClass = new ComplexEditor();
            string input = "10.3 + ";
            testClass.Number = input;
            string output = "0 + i * 0";
            Assert.AreEqual(output, testClass.ToString());
        }
        #endregion
        #region Test Input/Delete
        [TestMethod]
        public void AddDeleteTest1() {
            ComplexEditor testClass = new ComplexEditor();
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddSeparator();
            testClass.ToogleSign();
            string result = "-13 + i * -0";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest2() {
            ComplexEditor testClass = new ComplexEditor();
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddSeparator();
            testClass.ToogleSign();
            testClass.RemoveSymbol();
            string result = "-13 + i * -";
            Assert.AreEqual(result, testClass.ToString());
        }
        [TestMethod]
        public void AddDeleteTest3() {
            ComplexEditor testClass = new ComplexEditor();
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddNumberSeparator();
            testClass.AddSeparator();
            testClass.ToogleSign();
            testClass.AddNumber(0);
            testClass.AddNumber(1);
            testClass.AddNumber(3);
            testClass.AddNumberSeparator();
            string result = "-13 + i * -13.";
            Assert.AreEqual(result, testClass.ToString());
        }
        #endregion
    }
    #endregion
}
