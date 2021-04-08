using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Calculator {
    public sealed class TPNumber : ANumber {
        public static class Conver_10_p {
            public static string Do(double n, int p, int c) {
                if (p < 2 || p > 16)
                    throw new IndexOutOfRangeException();
                if (c < 0 || c > 10)
                    throw new IndexOutOfRangeException();

                string LeftSideString;
                string RightSideString;
                long LeftSide = 0;
                double RightSide = 0f;

                try {
                    LeftSide = (long)n;
                    RightSide = n - LeftSide;
                    if (RightSide < 0)
                        RightSide *= -1;

                    LeftSideString = int_to_P(LeftSide, p);
                    RightSideString = flt_to_P(RightSide, p, c);
                }
                catch {
                    throw new OverflowException();
                }
                return LeftSideString + (RightSideString == String.Empty ? "" : ".") + RightSideString;
            }
            public static char int_to_Char(long d) {
                if (d < 0 || d > 15)
                    throw new IndexOutOfRangeException();

                string SymbolArray = "0123456789ABCDEF";
                return SymbolArray.ElementAt((int)d);
            }
            public static string int_to_P(long n, long p) {
                if (p < 2 || p > 16)
                    throw new IndexOutOfRangeException();
                if (n == 0)
                    return "0";
                bool HaveMinus = false;
                if (n < 0) {
                    HaveMinus = true;
                    n *= -1;
                }
                string PNumber = string.Empty;

                while (n > 0) {
                    PNumber += int_to_Char(n % p);
                    n /= p;
                }

                if (HaveMinus)
                    PNumber += "-";

                char[] TempArray = PNumber.ToCharArray();
                Array.Reverse(TempArray);
                return new string(TempArray);
            }
            public static string flt_to_P(double n, int p, int c) {
                if (p < 2 || p > 16)
                    throw new IndexOutOfRangeException();
                if (c < 0 || c > 10)
                    throw new IndexOutOfRangeException();

                string PNumber = string.Empty;
                for (int i = 0; i < c; ++i) {
                    PNumber += int_to_Char((int)(n * p));
                    n = n * p - (int)(n * p);
                }
                PNumber = PNumber.TrimEnd('0');
                return PNumber;
            }
        }
        public static class Conver_p_10 {
            private static int char_To_num(char ch) {
                string AllVariants = "0123456789ABCDEF";
                if (!AllVariants.Contains(ch))
                    throw new IndexOutOfRangeException();
                return AllVariants.IndexOf(ch);
            }
            private static double convert(string P_num, int P, double weight) {
                if (weight % P != 0)
                    throw new Exception();

                long Degree = (long)Math.Ceiling(Math.Log(weight, P)) - 1;
                double Result = 0.0f;

                for (int i = 0; i < P_num.Length; ++i, --Degree)
                    Result += char_To_num(P_num.ElementAt(i)) * Math.Pow(P, Degree);

                return Result;
            }
            public static double dval(string P_num, int P) {
                if (P < 2 || P > 16)
                    throw new IndexOutOfRangeException();
                bool HaveMinus = false;
                if (P_num.First() == '-') {
                    HaveMinus = true;
                    P_num = P_num.Remove(0, 1);
                }
                foreach (char ch in P_num) {
                    if (ch == '.')
                        continue;
                    if (char_To_num(ch) > P)
                        throw new Exception();
                }

                double Number = 0.0f;
                Regex LeftRight = new Regex("^[0-9A-F]+\\.[0-9A-F]+$");
                Regex Right = new Regex("^0\\.[0-9A-F]+$");
                Regex Left = new Regex("^[0-9A-F]+.?$");
                if (LeftRight.IsMatch(P_num)) {
                    Number = convert(P_num.Remove(P_num.IndexOf('.'), 1), P, Math.Pow(P, P_num.IndexOf('.')));
                }
                else if (Left.IsMatch(P_num)) {
                    if (P_num.Last() == '.')
                        P_num = P_num.Remove(P_num.Length - 1);
                    Number = convert(P_num, P, Math.Pow(P, P_num.Length));
                }
                else if (Right.IsMatch(P_num)) {
                    Number = convert(P_num.Remove(P_num.IndexOf('.'), 1), P, 0);
                }
                else throw new Exception();

                return HaveMinus ? -Number : Number;
            }
        }

        public TNumber Number;
        public TNumber Notation;
        public TNumber Precision;

        public TPNumber() {
            Number = new TNumber();
            Notation = new TNumber(10);
            Precision = new TNumber(5);
        }
        public TPNumber(TNumber num, TNumber not, TNumber pre) {
            if (not < 2 || not > 16 || pre < 0 || pre > 10) {
                Number = new TNumber();
                Notation = new TNumber(10);
                Precision = new TNumber(5);
            }
            else {
                Number = new TNumber(num);
                Notation = new TNumber(not);
                Precision = new TNumber(pre);
            }
        }
        public TPNumber(TNumber num, int not, int pre) {
            if (not < 2 || not > 16 || pre < 0 || pre > 10) {
                Number = new TNumber();
                Notation = new TNumber(10);
                Precision = new TNumber(5);
            }
            else {
                Number = new TNumber(num);
                Notation = new TNumber(not);
                Precision = new TNumber(pre);
            }
        }
        public TPNumber(double num, int not, int pre) {
            if (not < 2 || not > 16 || pre < 0 || pre > 10) {
                Number = new TNumber();
                Notation = new TNumber(10);
                Precision = new TNumber(5);
            }
            else {
                Number = new TNumber(num);
                Notation = new TNumber(not);
                Precision = new TNumber(pre);
            }
        }
        public TPNumber(TPNumber anotherTPNumber) {
            Number = anotherTPNumber.Number;
            Notation = anotherTPNumber.Notation;
            Precision = anotherTPNumber.Precision;
        }
        public TPNumber(string str, TNumber not, TNumber pre) {
            Notation = not;
            Precision = pre;
            try {
                Number = new TNumber(Conver_p_10.dval(str, Convert.ToInt32(not.Number)));
            }
            catch {
                throw new System.OverflowException();
            }
        }
        public TPNumber(string str, int not, int pre) {
            try {
                Number = new TNumber(Conver_p_10.dval(str, not));
                Notation = new TNumber(not);
                Precision = new TNumber(pre);
            }
            catch {
                throw new System.OverflowException();
            }
        }

        public static TPNumber operator +(TPNumber a, TPNumber b) {
            return new TPNumber(a.Number + b.Number, a.Notation, a.Precision);
        }
        public static TPNumber operator *(TPNumber a, TPNumber b) {
            return new TPNumber(a.Number * b.Number, a.Notation, b.Notation);
        }
        public static TPNumber operator -(TPNumber a, TPNumber b) {
            return new TPNumber(a.Number - b.Number, a.Notation, a.Precision);
        }
        public static TPNumber operator /(TPNumber a, TPNumber b) {
            return new TPNumber(a.Number / b.Number, a.Notation, a.Precision);
        }
        public static TPNumber operator -(TPNumber a) {
            return new TPNumber(-a.Number, a.Notation, a.Precision);
        }
        public static bool operator ==(TPNumber a, TPNumber b) {
            return a.Number == b.Number;
        }
        public static bool operator !=(TPNumber a, TPNumber b) {
            return a.Number != b.Number;
        }
        public static bool operator >(TPNumber a, TPNumber b) {
            return a.Number > b.Number;
        }
        public static bool operator <(TPNumber a, TPNumber b) {
            return a.Number < b.Number;
        }
        public override ANumber Add(ANumber a) {
            return new TPNumber((a as TPNumber).Number + Number, Notation, Precision);
        }
        public override ANumber Mul(ANumber a) {
            return new TPNumber((a as TPNumber).Number * Number, Notation, Precision);
        }
        public override ANumber Div(ANumber a) {
            return new TPNumber((a as TPNumber).Number / Number, Notation, Precision);
        }
        public override ANumber Sub(ANumber a) {
            return new TPNumber((a as TPNumber).Number - Number, Notation, Precision);
        }
        public override object Square() {
            return new TPNumber((TNumber)Number.Square(), Notation, Precision);
        }
        public override object Reverse() {
            return new TPNumber((TNumber)Number.Reverse(), Notation, Precision);
        }
        public override bool IsZero() {
            return Number.IsZero();
        }
        public override void SetString(string str) {
            Number = new TNumber(Conver_p_10.dval(str, Convert.ToInt32(Notation.Number)));
        }

        public override string ToString() {
            string str;
            try {
                str = Conver_10_p.Do(Number.Number, Convert.ToInt32(Notation.Number), Convert.ToInt32(Precision.Number));

            }
            catch {
                throw new System.OverflowException();
            }
            return str;
        }
        public override bool Equals(object obj) {
            var number = obj as TPNumber;
            return number != null &&
                   EqualityComparer<TNumber>.Default.Equals(Number, number.Number) &&
                   EqualityComparer<TNumber>.Default.Equals(Notation, number.Notation) &&
                   EqualityComparer<TNumber>.Default.Equals(Precision, number.Precision);
        }
    }
}
