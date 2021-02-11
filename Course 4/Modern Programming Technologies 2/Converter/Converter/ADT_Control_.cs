using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Converter
{
    public class ADT_Control_
    {
        //Основание системы сч. исходного числа.
        int pin = 10;
        //Основание системы сч. результата.
        int pout = 16;
        //Число разрядов в дробной части результата.
        const int accuracy = 10;
        public History history = new History();
        public enum State { Edit, Converted }
        private State state;
        //Свойство для чтения и записи состояние Конвертера.
        internal State St { get => state; set => state = value; }
        //Свойство для чтения и записи основание системы сч. р1.
        public int Pin { get => pin; set => pin = value; }
        //Свойство для чтения и записи основание системы сч. р2.
        public int Pout { get => pout; set => pout = value; }
        //Конструктор.
        public ADT_Control_()
        {
            St = State.Edit;
            Pin = pin;
            Pout = pout;
        }
        //объект редактор
        public Editor editor = new Editor();
        //Выполнить команду конвертера.
        public string doCmnd(Editor.Commands j)
        {
            if(j == Editor.Commands.exec)
            {
                double r = ADT_Convert_p_10.dval(editor.Number, Pin);
                string res = ADT_Convert_10_p.Do(r, Pout, acc());
                St = State.Converted;
                history.addRecord(Pin, Pout, editor.Number, res);
                return res;
            }
            else
            {
                St = State.Edit;
                return editor.doEdit(j);
            }
        }

        //Точность представления результата.
        private int acc()
        {
            return (int)Math.Round(editor.acc() * Math.Log(Pin) / Math.Log(Pout) + 0.5);
        }
    }
}
