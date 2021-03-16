using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MPT_RGZ
{
    public class TFracEditor
    {
        private string fraction;
        public string Fraction { 
            get => fraction; 
            set 
            { 
                fraction = new TFrac(value).ToString(); 
            } 
        }
        
        const string ZeroFraction = "0/";
        const string Separator = "/";
        const int LeftSideOnlyLimit = 14;
        const int BothSideLimit = 22;
        public enum Command
        {
            Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Sign, Separator, BS, CE, None
        }

        public TFracEditor()
        {
            fraction = "0";
        }

        public TFracEditor(long a, long b)
        {
            fraction = new TFrac(a, b).ToString();
        }

        public TFracEditor(string frac)
        {
            fraction = new TFrac(frac).ToString();
        }

        public bool hasZero() => fraction.StartsWith(ZeroFraction) || fraction == "0";

        public string AddSign()
        {
            if (fraction[0] == '-')
                fraction = fraction.Remove(0, 1);
            else
                fraction = '-' + fraction;
            return fraction;
        }

        public string AddNumber(long a)
        {
            if (!fraction.Contains(Separator) && fraction.Length > LeftSideOnlyLimit)
                return fraction;
            else if (fraction.Length > BothSideLimit)
                return fraction;
            if (a < 0 || a > 9)
                return fraction;
            if (a == 0)
                AddZero();
            else if (fraction == "0" || fraction == "-0")
                fraction = fraction.First() == '-' ? "-" + a.ToString() : a.ToString();
            else
                fraction += a.ToString();
            return fraction;
        }

        public string AddZero()
        {
            if (fraction.Contains(Separator) && fraction.Last().ToString() == Separator)
                return fraction;
            if (fraction == "0" || fraction == "0/")
                return fraction;
            fraction += "0";
            return fraction;
        }

        public string RemoveSymbol()
        {
            if (fraction.Length == 1)
                fraction = "0";
            else if (fraction.Length == 2 && fraction.First() == '-')
                fraction = "-0";
            else
                fraction = fraction.Remove(fraction.Length - 1);
            return fraction;
        }

        public string Clear()
        {
            fraction = "0";
            return fraction;
        }

        public string Edit(Enum command)
        {
            switch(command)
            {
                case Command.Zero:
                    AddZero();
                    break;
                case Command.One:
                    AddNumber(1);
                    break;
                case Command.Two:
                    AddNumber(2);
                    break;
                case Command.Three:
                    AddNumber(3);
                    break;
                case Command.Four:
                    AddNumber(4);
                    break;
                case Command.Five:
                    AddNumber(5);
                    break;
                case Command.Six:
                    AddNumber(6);
                    break;
                case Command.Seven:
                    AddNumber(7);
                    break;
                case Command.Eight:
                    AddNumber(8);
                    break;
                case Command.Nine:
                    AddNumber(9);
                    break;
                case Command.Sign:
                    AddSign();
                    break;
                case Command.Separator:
                    AddSeparator();
                    break;
                case Command.BS:
                    RemoveSymbol();
                    break;
                case Command.CE:
                    Clear();
                    break;
                default:
                    break;
            }
            return fraction;
        }

        public string AddSeparator()
        {
            if (!fraction.Contains(Separator))
                fraction += Separator;
            return fraction;
        }

        public override string ToString()
        {
            return Fraction;
        }
    }
}
