using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace Converter
{
    public class ADT_Convert_p_10
    {
        //Преобразовать цифру в число.
        private static int char_to_num(char ch)
        {
            string allNums = "0123456789ABCDEF";
            if (!allNums.Contains(ch))
                throw new IndexOutOfRangeException();
            return allNums.IndexOf(ch);
        }

        //Преобразовать строку в число
        private static double convert(string pNumber, int p, double weight)
        {
            if (weight % p != 0)
                throw new Exception();

            long degree = (long)Math.Log(weight, p) - 1;
            double result = 0.0f;

            for(int i = 0; i < pNumber.Length; i++, degree--)
                result += char_to_num(pNumber.ElementAt(i)) * Math.Pow(p, degree);
            return result;
        }

        //Преобразовать из с.сч. с основанием р
        //в с.сч. с основанием 10.
        public static double dval(string pNumber, int p)
        {
            if (p < 2 || p > 16)
                throw new IndexOutOfRangeException();
            foreach (char ch in pNumber)
            {
                if (ch == '.')
                    continue;
                if (char_to_num(ch) > p)
                    throw new Exception();
            }

            Regex LeftRight = new Regex("^[0-9A-F]+\\.[0-9A-F]+$");
            Regex Right = new Regex("^0\\.[0-9A-F]+$");
            Regex Left = new Regex("^[0-9A-F]+$");

            double Number;
            if (LeftRight.IsMatch(pNumber))
                Number = convert(pNumber.Remove(pNumber.IndexOf('.'), 1), p, Math.Pow(p, pNumber.IndexOf('.')));
            else if (Left.IsMatch(pNumber))
                Number = convert(pNumber, p, Math.Pow(p, pNumber.Length));
            else if (Right.IsMatch(pNumber))
                Number = convert(pNumber.Remove(pNumber.IndexOf('.'), 1), p, 0);
            else
                throw new Exception();

            return Number;
        }
    }
}
