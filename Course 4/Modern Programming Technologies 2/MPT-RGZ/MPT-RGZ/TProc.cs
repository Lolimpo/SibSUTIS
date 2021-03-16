using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MPT_RGZ
{
    public class TProc<T> where T: TFrac, new()
    {
        public enum TOprtn {None, Add, Sub, Mul, Div }
        public enum TFunc {Rev, Sqr }

        T lop_res;
        T rop;
        TOprtn operation;
        public T Lop_Res { get => lop_res; set => lop_res = value; }
        public T Rop { get => rop; set => rop = value; }
        public TOprtn Operation { get => operation; set => operation = value; }

        public TProc()
        {
            operation = TOprtn.None;
            lop_res = new T();
            rop = new T();
        }

        public TProc(T leftObj, T rightObj)
        {
            operation = TOprtn.None;
            lop_res = leftObj;
            rop = rightObj;
        }

        public void ResetProc()
        {
            operation = TOprtn.None;
            T newObj = new T();
            lop_res = rop = newObj;
        }

        public void DoOper()
        {
            try
            {
                dynamic a = lop_res;
                dynamic b = rop;
                switch (operation)
                {
                    case TOprtn.Add:
                        lop_res = a.Add(b);
                        break;
                    case TOprtn.Sub:
                        lop_res = a.Sub(b);
                        break;
                    case TOprtn.Mul:
                        lop_res = a.Mul(b);
                        break;
                    case TOprtn.Div:
                        lop_res = a.Div(b);
                        break;
                }
            } 
            catch
            {
                throw new System.OverflowException();
            }
        }

        public void DoFunc(TFunc func)
        {
            dynamic a = rop;
            switch (func)
            {
                case TFunc.Rev:
                    a = a.Reverse();
                    rop = (T)a;
                    break;
                case TFunc.Sqr:
                    a = a.Square();
                    rop = (T)a;
                    break;
                default:
                    break;
            }
        }
    }
}