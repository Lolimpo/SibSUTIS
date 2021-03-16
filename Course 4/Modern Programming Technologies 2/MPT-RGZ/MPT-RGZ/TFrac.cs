using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace MPT_RGZ
{
    public class TFrac
    {
        private long numerator;
        public long Numerator { get; }
        private long denominator;
        public long Denominator { get; }

        static void Swap<T>(ref T lhs, ref T rhs)
        {
            T temp;
            temp = lhs;
            lhs = rhs;
            rhs = temp;
        }

        public static long GCD(long a, long b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            while (b > 0)
            {
                a %= b;
                Swap(ref a, ref b);
            }
            return a;
        }

        public TFrac()
        {
            numerator = 0;
            denominator = 1;
        }

        public TFrac(long a, long b)
        {
            if (a < 0 && b < 0)
            {
                a *= -1;
                b *= -1;
            }
            else if (b < 0 && a > 0)
            {
                b *= -1;
                a *= -1;
            }
            else if (a == 0 && b == 0 || b == 0 || a == 0 && b == 1)
            {
                numerator = 0;
                denominator = 1;
                return;
            }
            numerator = a;
            denominator = b;
            long gcdRes = GCD(a, b);
            if (gcdRes > 1)
            {
                numerator /= gcdRes;
                denominator /= gcdRes;
            }
        }

        public TFrac(string frac)
        {
            Regex FracRegex = new Regex(@"^-?(\d+)/(\d+)$");
            Regex NumberRegex = new Regex(@"^-?\d+/?$");
            if (FracRegex.IsMatch(frac))
            {
                List<string> FracParts = frac.Split('/').ToList();
                numerator = Convert.ToInt64(FracParts[0]);
                denominator = Convert.ToInt64(FracParts[1]);
                if (denominator == 0)
                {
                    numerator = 0;
                    denominator = 1;
                    return;
                }
                long gcdResult = GCD(numerator, denominator);
                if (gcdResult > 1)
                {
                    numerator /= gcdResult;
                    denominator /= gcdResult;
                }
                return;
            }
            else if (NumberRegex.IsMatch(frac))
            {
                if (long.TryParse(frac, out long NewNumber))
                    numerator = NewNumber;
                else
                    numerator = 0;
                denominator = 1;
                return;
            }
            else
            {
                numerator = 0;
                denominator = 1;
                return;
            }
        }

        public TFrac(TFrac anotherFrac)
        {
            numerator = anotherFrac.numerator;
            denominator = anotherFrac.denominator;
        }

        public void SetString(string str)
        {
            TFrac TempFrac = new TFrac(str);
            numerator = TempFrac.numerator;
            denominator = TempFrac.denominator;
        }

        public TFrac Add(TFrac a)
        => new TFrac(numerator * a.denominator + denominator * a.numerator, denominator * a.denominator);

        public TFrac Mul(TFrac a)
        => new TFrac(numerator * a.numerator, denominator * a.denominator);

        public TFrac Sub(TFrac a)
        => new TFrac(numerator * a.denominator - denominator * a.numerator, denominator * a.denominator);

        public TFrac Div(TFrac a)
        => new TFrac(numerator * a.denominator, denominator * a.numerator);

        public TFrac Square()
        => new TFrac(numerator * numerator, denominator * denominator);

        public TFrac Reverse() => new TFrac(denominator, numerator);

        public TFrac Minus() => new TFrac(-numerator, denominator);

        public bool Equal(TFrac a) => numerator == a.numerator && denominator == a.denominator;

        public static bool operator >(TFrac a, TFrac b) => (Convert.ToDouble(a.numerator) / Convert.ToDouble(a.denominator)) > (Convert.ToDouble(b.numerator) / Convert.ToDouble(b.denominator));

        public static bool operator <(TFrac a, TFrac b) => (Convert.ToDouble(a.numerator) / Convert.ToDouble(a.denominator)) < (Convert.ToDouble(b.numerator) / Convert.ToDouble(b.denominator));

        public long getNumeratorNum() => numerator;

        public long getDenominatorNum() => denominator;

        public string getNumeratorString() => numerator.ToString();

        public string getDenominatorString() => denominator.ToString();

        public override string ToString() => getNumeratorString() + "/" + getDenominatorString();
    }
}
