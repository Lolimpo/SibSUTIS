using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MPT_RGZ
{
    public class TMemory<T> where T : TFrac, new()
    {
        public enum NumStates { OFF, ON }

        public enum Commands { Store, Add, Clear, Copy }

        T number;
        NumStates state;
        public T FNumber
        {
            get { state = NumStates.ON; return number; }
            set { number = value; state = NumStates.ON; }
        }
        public NumStates FState
        {
            get => state;
            set => state = value;
        }

        public TMemory()
        {
            number = new T();
            state = NumStates.OFF;
        }

        public TMemory(T num)
        {
            number = num;
            state = NumStates.OFF;
        }

        public T Add(T num)
        {
            state = NumStates.ON;
            dynamic a = number;
            dynamic b = num;
            number = a.Add(b);
            return number;
        }

        public void Clear()
        {
            number = new T();
            state = NumStates.OFF;
        }

        public (T, NumStates) Edit(Commands command, T newNumber)
        {
            switch(command)
            {
                case Commands.Store:
                    state = NumStates.ON;
                    number = newNumber;
                    break;
                case Commands.Add:
                    dynamic a = number;
                    dynamic b = newNumber;
                    number = a.Add(b);
                    break;
                case Commands.Clear:
                    Clear();
                    break;
            }
            return (number, state);
        }
    }
}
