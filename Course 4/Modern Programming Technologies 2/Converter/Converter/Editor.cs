using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Converter
{
    public class Editor
    {
        public enum Commands
        {
            add0, add1, add2, add3, 
            add4, add5, add6, add7, 
            add8, add9, addA, addB, 
            addC, addD, addE, addF, 
            addDot, BS, CLEAR, exec
        };
        //Поле для хранения редактируемого числа.
        string number = zero;
        //Разделитель целой и дробной частей.
        const string delim = ".";
        //Ноль.
        const string zero = "0";
        //Свойствое для чтения редактируемого числа.
        public string Number
        { get => number; set => number = value; }
        //Добавить цифру.
        public string addDigit(int n) 
        {
            if (n < 0 || n > 16)
                throw new IndexOutOfRangeException();

            if (number == zero)
                number = ADT_Convert_10_p.int_to_Char(n).ToString();
            else
                number += ADT_Convert_10_p.int_to_Char(n);
            return Number;
        }
        //Точность представления результата.
        public int acc() 
        {
            return number.Contains(delim) ? number.Length - number.IndexOf(delim) - 1 : 0;
        }
        //Добавить ноль.
        public string addZero() 
        {
            return addDigit(0);
        }
        //Добавить разделитель.
        public string addDelim() 
        {
            if (number.Length > 0 && !number.Contains(delim))
                number += delim;
            return Number;
        }
        //Удалить символ справа.
        public string bs() 
        {
            if (number.Length > 1)
                number = number.Remove(number.Length - 1);
            else
                number = zero;
            return Number;
        }
        //Очистить редактируемое число.
        public string clear() 
        {
            number = zero;
            return Number;
        }
        //Выполнить команду редактирования.
        public string doEdit(Commands j) 
        { 
            switch(j)
            {
                case Commands.add0:
                    addZero();
                    break;
                case Commands.add1:
                    addDigit(1);
                    break;
                case Commands.add2:
                    addDigit(2);
                    break;
                case Commands.add3:
                    addDigit(3);
                    break;
                case Commands.add4:
                    addDigit(4);
                    break;
                case Commands.add5:
                    addDigit(5);
                    break;
                case Commands.add6:
                    addDigit(6);
                    break;
                case Commands.add7:
                    addDigit(7);
                    break;
                case Commands.add8:
                    addDigit(8);
                    break;
                case Commands.add9:
                    addDigit(9);
                    break;
                case Commands.addA:
                    addDigit(10);
                    break;
                case Commands.addB:
                    addDigit(11);
                    break;
                case Commands.addC:
                    addDigit(12);
                    break;
                case Commands.addD:
                    addDigit(13);
                    break;
                case Commands.addE:
                    addDigit(14);
                    break;
                case Commands.addF:
                    addDigit(15);
                    break;
                case Commands.addDot:
                    addDelim();
                    break;
                case Commands.BS:
                    bs();
                    break;
                case Commands.CLEAR:
                    clear();
                    break;
                default:
                    return number;
            }
            return number;
        }
    }
}
