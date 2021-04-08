using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Lab11;

namespace UAbonentList_test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CorrectPhone_1()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsTrue(uAbonentList.Insert("Vasya", "+79139504314"));
        }

        [TestMethod]
        public void CorrectPhone_2()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsFalse(uAbonentList.Insert("Vasya", "+791395043"));
        }

        [TestMethod]
        public void CorrectPhone_3()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsTrue(uAbonentList.Insert("Vasya", "79139504314"));
        }

        [TestMethod]
        public void CorrectPhone_4()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsFalse(uAbonentList.Insert("Vasya", ""));
        }

        [TestMethod]
        public void CorrectPhone_5()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsFalse(uAbonentList.Insert("", "79139504314"));
        }

        [TestMethod]
        public void CorrectPhone_6()
        {
            UAbonentList uAbonentList = new UAbonentList();
            Assert.IsTrue(uAbonentList.Insert("Vasya", "-79139504314"));
        }

        [TestMethod]
        public void CorrectRemove_1()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Remove(""));
        }

        [TestMethod]
        public void CorrectRemove_2()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Remove("Vasya"));
        }

        [TestMethod]
        public void CorrectRemove_3()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Remove("79139504314"));
        }

        [TestMethod]
        public void CorrectEdit_1()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Edit("Vasya", "123"));
        }

        [TestMethod]
        public void CorrectEdit_2()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Edit("Vasya", "+79139504314"));
        }

        [TestMethod]
        public void CorrectEdit_3()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Edit("V", "79139504314"));
        }

        [TestMethod]
        public void CorrectEdit_4()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Edit("Vasya", "+79131231234"));
        }

        [TestMethod]
        public void CorrectFind_1()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Find("Vasya", "79131231234"));
        }

        [TestMethod]
        public void CorrectFind_2()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Find("Vasya", ""));
        }

        [TestMethod]
        public void CorrectFind_3()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsTrue(uAbonentList.Find("", "79139504314"));
        }

        [TestMethod]
        public void CorrectFind_4()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Find("Valya", "79131231234"));
        }

        [TestMethod]
        public void CorrectFind_5()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            Assert.IsFalse(uAbonentList.Find("", "7913123123"));
        }

        [TestMethod]
        public void WorkingClear()
        {
            UAbonentList uAbonentList = new UAbonentList();
            uAbonentList.Insert("Vasya", "79139504314");
            try
            {
                uAbonentList.Clear();
            }
            catch (Exception e)
            {
                Assert.Fail(e.ToString());
            }
        }
    }
}
