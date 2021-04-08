namespace Calculator {
    public sealed class TProc<T> where T : ANumber, new() {
        public enum Oper {
            None, Add, Sub, Mul, Div
        }
        public enum Func {
            Rev, Sqr
        }

        Oper operation;
        T lop_Res;
        T rop;

        public T Lop_Res { get => lop_Res; set => lop_Res = value; }
        public T Rop { get => rop; set => rop = value; }
        public Oper Operation { get => operation; set => operation = value; }

        public TProc() {
            operation = Oper.None;
            Lop_Res = new T();
            Rop = new T();
        }

        public TProc(T leftObj, T rightObj) {
            operation = Oper.None;
            Lop_Res = leftObj;
            Rop = rightObj;
        }

        public void Reset() {
            operation = Oper.None;
            T newObj = new T();
            Lop_Res = Rop = newObj;
        }

        public void DoOper() {
            try {
                dynamic a = Lop_Res;
                dynamic b = Rop;
                switch (operation) {
                    case Oper.Add:
                        Lop_Res = (T)(a + b);
                        break;
                    case Oper.Sub:
                        Lop_Res = (T)(a - b);
                        break;
                    case Oper.Mul:
                        Lop_Res = (T)(a * b);
                        break;
                    case Oper.Div:
                        Lop_Res = (T)(a / b);
                        break;
                    default:
                        break;
                }
            } catch {
                throw new System.OverflowException();
            }
        }

        public void DoFunc(Func func) {
            dynamic a = Rop;
            switch (func) {
                case Func.Rev:
                    a = a.Reverse();
                    Rop = (T)a;
                    break;
                case Func.Sqr:
                    a = a.Square();
                    Rop = (T)a;
                    break;
                default:
                    break;
            }
        }

    }
}
