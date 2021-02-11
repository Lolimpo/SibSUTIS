using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Converter
{
    public class ADT_Convert_10_p
    {
        //Преобразовать целое в символ.
        public static char int_to_Char(int d)
        {
            if (d < 0 || d > 15)
                throw new IndexOutOfRangeException();

            string allSymbols = "0123456789ABCDEF";
            return allSymbols.ElementAt(d);
        }

        //Преобразовать десятичное целое в с.сч. с основанием р.
        public static string int_to_p(long n, long p)
        {
            if (p < 2 || p > 16)
                throw new IndexOutOfRangeException();
            if (n == 0)
                return "0";
            if (p == 10)
                return n.ToString();

            bool isNegative = false;
            if (n < 0)
            {
                isNegative = true;
                n *= -1;
            }
            string pNumber = String.Empty;

            while(n > 0)
            {
                pNumber += int_to_Char((int)(n % p));
                n /= p;
            }

            if (isNegative)
                pNumber += "-";

            char[] tmp = pNumber.ToCharArray();
            Array.Reverse(tmp);
            return new string(tmp);
        }

        //Преобразовать десятичную дробь в с.сч. с основанием р.
        public static string flt_to_p(double n, int p, int c)
        {
            if (p < 2 || p > 16)
                throw new IndexOutOfRangeException();
            if (c < 0 || c > 10)
                throw new IndexOutOfRangeException();

            string pNumber = String.Empty;
            for(int i = 0; i < c; i++)
            {
                pNumber += int_to_Char((int)(n * p));
                n = n * p - (int)(n * p);
            }
            return pNumber;
        }

        //Преобразовать десятичное
        //действительное число в с.сч. с осн. р.
        public static string Do(double n, int p, int c)
        {
            if (p < 2 || p > 16)
                throw new IndexOutOfRangeException();
            if (c < 0 || c > 10)
                throw new IndexOutOfRangeException();

            long leftSide = (long)n;

            double rightSide = n - leftSide;
            if (rightSide < 0)
                rightSide *= -1;

            string leftSideString = int_to_p(leftSide, p);
            string rightSideString = flt_to_p(rightSide, p, c);

            return leftSideString + (rightSideString == String.Empty ? "" : ".") + rightSideString;
        }
    }
}
