namespace Calculator {
    public sealed class TMemory<T> where T : ANumber, new() {
        public enum NumStates {
            OFF, ON
        }

        public enum Commands {
            Store, Add, Clear, Copy
        }

        T fNumber;
        NumStates fState;
        public T FNumber {
            get { fState = NumStates.ON; return fNumber; }
            set { fNumber = value; fState = NumStates.ON; }
        }
        public NumStates FState {
            get => fState;
            set => fState = value;
        }

        public TMemory() {
            FNumber = new T();
            FState = NumStates.OFF;
        }

        public TMemory(T number) {
            FNumber = number;
            FState = NumStates.OFF;
        }

        public T Add(T number) {
            FState = NumStates.ON;
            dynamic a = fNumber;
            dynamic b = number;
            fNumber = (T)(a + b);
            return fNumber;
        }

        public void Clear() {
            fNumber = new T();
            FState = NumStates.OFF;
        }

        public (T, NumStates) Edit(Commands command, T newNumber) {
            switch (command) {
                case Commands.Store:
                    FState = NumStates.ON;
                    fNumber = newNumber;
                    break;
                case Commands.Add:
                    FState = NumStates.ON;
                    dynamic a = fNumber;
                    dynamic b = newNumber;
                    fNumber = (T)(a + b);
                    break;
                case Commands.Clear:
                    Clear();
                    break;
            }
            return (fNumber, fState);
        }
    }
}
