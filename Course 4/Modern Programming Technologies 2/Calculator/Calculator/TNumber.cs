using System;
using System.Globalization;

namespace Calculator {
    public sealed class TNumber : ANumber {
        public double Number { get; }
        public TNumber() {
            Number = 0;
        }
        public TNumber(double n) {
            Number = n;
        }
        public TNumber(string str) {
            if (double.TryParse(str, NumberStyles.Float, CultureInfo.InvariantCulture, out double NewNumber))
                Number = NewNumber;
            else
                Number = 0;
        }
        public TNumber(TNumber num) {
            Number = num.Number;
        }

        public override ANumber Add(ANumber a) {
            return new TNumber(Number + (a as TNumber).Number);
        }
        public override ANumber Div(ANumber a) {
            if ((a as TNumber).IsZero())
                throw new DivideByZeroException();
            return new TNumber(Number / (a as TNumber).Number);
        }
        public override ANumber Sub(ANumber a) {
            return new TNumber(Number - (a as TNumber).Number);
        }
        public override ANumber Mul(ANumber a) {
            return new TNumber(Number * (a as TNumber).Number);
        }
        public override bool IsZero() {
            return Number == 0;
        }
        public override object Reverse() {
            return new TNumber(1 / Number);
        }
        public override object Square() {
            return new TNumber(Number * Number);
        }

        public override string ToString() {
            return Number.ToString("0.###", CultureInfo.InvariantCulture);
        }
        public override bool Equals(object obj) {
            var number = obj as TNumber;
            return number != null &&
                   Number == number.Number;
        }

        public override void SetString(string str) { }
        public static TNumber operator +(TNumber a, TNumber b) {
            return new TNumber(a.Number + b.Number);
        }
        public static TNumber operator *(TNumber a, TNumber b) {
            return new TNumber(a.Number * b.Number);
        }
        public static TNumber operator -(TNumber a, TNumber b) {
            return new TNumber(a.Number - b.Number);
        }
        public static TNumber operator /(TNumber a, TNumber b) {
            if (b.IsZero())
                throw new DivideByZeroException();
            return new TNumber(a.Number / b.Number);
        }
        public static bool operator ==(TNumber a, TNumber b) {
            return a.Number == b.Number;
        }
        public static bool operator ==(TNumber a, int b) {
            return a.Number == b;
        }
        public static bool operator !=(TNumber a, TNumber b) {
            return a.Number != b.Number;
        }
        public static bool operator !=(TNumber a, int b) {
            return a.Number != b;
        }
        public static bool operator >(TNumber a, TNumber b) {
            return (a.Number) > (b.Number);
        }
        public static bool operator <(TNumber a, TNumber b) {
            return (a.Number < b.Number);
        }
        public static bool operator >(TNumber a, int b) {
            return (a.Number) > (b);
        }
        public static bool operator <(TNumber a, int b) {
            return (a.Number < b);
        }
        public static TNumber operator -(TNumber a) {
            return new TNumber(-a.Number);
        }
        public static TNumber operator /(TNumber a, int b) {
            if (b == 0)
                throw new DivideByZeroException();
            return new TNumber(a.Number / b);
        }
        public static TNumber operator /(TNumber a, long b) {
            if (b == 0)
                throw new DivideByZeroException();
            return new TNumber(a.Number / b);
        }
        public static TNumber operator +(TNumber a, int b) {
            return new TNumber(a.Number + b);
        }
        public static TNumber operator -(TNumber a, int b) {
            return new TNumber(a.Number - b);
        }
        public static TNumber operator *(TNumber a, int b) {
            return new TNumber(a.Number * b);
        }
    }
}
