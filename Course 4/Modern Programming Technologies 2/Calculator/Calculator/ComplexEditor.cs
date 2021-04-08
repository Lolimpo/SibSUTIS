using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

namespace Calculator {
    public sealed class ComplexEditor : AEditor {
        private string number;
        public override string Number {
            get => number;
            set {
                number = new TComplex(value).ToString();
            }
        }
        const int OverflowStringLimit = 15;
        Regex ZeroComplex = new Regex(@"^-?(0+.?0*)(\s*\+\s*i\s*\*\s*-?(0+.?0*)|(\s*\+\s*i\s*\*\s*-?))?$");
        const string Separator = " + i * ";
        public ComplexEditor() {
            number = "0";
        }
        public ComplexEditor(int a, int b) {
            number = new TComplex(a, b).ToString();
        }
        public ComplexEditor(string str) {
            number = new TComplex(str).ToString();
        }
        public override bool IsZero() {
            return ZeroComplex.IsMatch(number);
        }
        public override string ToogleSign() {
            if (HaveSeparator()) {
                List<string> Parts = new List<string>();
                Parts = Number.Split(new string[] { Separator }, StringSplitOptions.None).ToList();
                if (Parts[0].First() == '-')
                    Parts[0] = Parts[0].Remove(0, 1);
                else
                    Parts[0] = '-' + Parts[0];
                if (Parts[1].First() == '-')
                    Parts[1] = Parts[1].Remove(0, 1);
                else
                    Parts[1] = '-' + Parts[1];
                number = Parts[0] + Separator + Parts[1];
                return number;
            }
            if (number.First() == '-')
                number = number.Remove(0, 1);
            else
                number = '-' + number;
            return number;
        }
        public override string AddNumber(int a) {
            if (a < 0 || a > 9)
                return number;
            if (a == 0)
                AddZero();
            else if (number == "0" || number == "-0")
                number = number.First() == '-' ? "-" + a.ToString() : a.ToString();
            else if (number.EndsWith(" 0") || number.EndsWith(" -0"))
                number = number.Remove(number.Length - 1) + a.ToString();
            else number += a.ToString();
            return number;
        }

        public override string AddZero() {
            if (number == "0" || number == "-0" || number.EndsWith(" 0") || number.EndsWith(" -0") || number.EndsWith(Separator))
                return number;
            number += "0";
            return number;
        }
        public override string RemoveSymbol() {
            if (number.Length == 1)
                number = "0";
            else if (number.Length == 2 && Number.First() == '-')
                number = "-0";
            else if (HaveSeparator() && Number.ElementAt(Number.Length - 2) == ' ')
                number = number.Remove(number.IndexOf(Separator));
            else
                number = number.Remove(number.Length - 1);
            return number;
        }
        public override string Clear() {
            number = "0";
            return Number;
        }
        public override string Edit(Enum com) {
            switch (com) {
                case Command.cZero:
                    AddZero();
                    break;
                case Command.cOne:
                    AddNumber(1);
                    break;
                case Command.cTwo:
                    AddNumber(2);
                    break;
                case Command.cThree:
                    AddNumber(3);
                    break;
                case Command.cFour:
                    AddNumber(4);
                    break;
                case Command.cFive:
                    AddNumber(5);
                    break;
                case Command.cSix:
                    AddNumber(6);
                    break;
                case Command.cSeven:
                    AddNumber(7);
                    break;
                case Command.cEight:
                    AddNumber(8);
                    break;
                case Command.cNine:
                    AddNumber(9);
                    break;
                case Command.cSign:
                    ToogleSign();
                    break;
                case Command.cSeparator:
                    AddNumberSeparator();
                    break;
                case Command.cBS:
                    RemoveSymbol();
                    break;
                case Command.CE:
                    Clear();
                    break;
                case Command.cNumbSeparator:
                    AddSeparator();
                    break;
                default:
                    break;
            }
            return Number;
        }
        public override string AddSeparator() {
            if (!HaveSeparator())
                Number = string.Concat(Number, Separator, "0");
            return Number;
        }
        public override bool HaveSeparator() {
            return Number.Contains(Separator);
        }
        public override string ToString() {
            return Number;
        }

        public string AddNumberSeparator() {
            if (!HaveSeparator() && !number.Contains("."))
                number += ".";
            else if (HaveSeparator()) {
                List<string> Parts = new List<string>();
                Parts = Number.Split(new string[] { Separator }, StringSplitOptions.None).ToList();
                if (!Parts[1].Contains("."))
                    number += ".";
            }
            return number;
        }
    }
}
