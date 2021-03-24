using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MPT_RGZ
{
    public class TCtrl<T, TEditor> 
        where T : TFrac, new() 
        where TEditor: TFracEditor, new()
    {
        public enum TCtrlState { cStart, cEditing, FunDone, cValDone, cExpDone, cOpDone, cOpChange, cError }
        
        TCtrlState calcState;
        TEditor editor;
        TProc<T> proc;
        TMemory<T> memory;
        TFrac number;
        public THistory history = new THistory();

        public TCtrlState CurState { get => calcState; set => calcState = value; }
        public TProc<T> Proc { get => proc; set => proc = value; }
        public TMemory<T> Memory { get => memory; set => memory = value; }
        public TEditor Edit { get => editor; set => editor = value; }

        public TCtrl()
        {
            Edit = new TEditor();
            Proc = new TProc<T>();
            Memory = new TMemory<T>();
            CurState = TCtrlState.cStart;
        }

        public string Reset()
        {
            Edit.Clear();
            Proc.ResetProc();
            Memory.Clear();
            CurState = TCtrlState.cStart;
            return Edit.ToString();
        }

        public string ExecComandEditor(TFracEditor.Command command)
        {
            string toReturn;
            if(CurState == TCtrlState.cExpDone)
            {
                Proc.ResetProc();
                CurState = TCtrlState.cStart;
            }
            if (CurState != TCtrlState.cStart)
                CurState = TCtrlState.cEditing;
            toReturn = Edit.Edit(command);
            T tmp = new T();
            tmp.SetString(toReturn);
            proc.Rop = tmp;
            history.AddRecord(toReturn, command.ToString());
            return toReturn;
        }

        public string ExecOperation(TProc<T>.TOprtn oper)
        {
            if (oper == TProc<T>.TOprtn.None)
                return Edit.Fraction;
            string toReturn;
            try
            {
                switch (CurState)
                {
                    case TCtrlState.cStart:
                        Proc.Lop_Res = Proc.Rop;
                        Proc.Operation = oper;
                        CurState = TCtrlState.cOpDone;
                        Edit.Clear();
                        break;
                    case TCtrlState.cEditing:
                        Proc.DoOper();
                        Proc.Operation = oper;
                        Edit.Clear();
                        CurState = TCtrlState.cOpDone;
                        break;
                    case TCtrlState.FunDone:
                        if (Proc.Operation == TProc<T>.TOprtn.None)
                            Proc.Lop_Res = Proc.Rop;
                        else
                            Proc.DoOper();
                        Proc.Operation = oper;
                        Edit.Clear();
                        CurState = TCtrlState.cOpChange;
                        break;
                    case TCtrlState.cOpDone:
                        CurState = TCtrlState.cOpChange;
                        Edit.Clear();
                        break;
                    case TCtrlState.cValDone:
                        break;
                    case TCtrlState.cExpDone:
                        Proc.Operation = oper;
                        Proc.Rop = Proc.Lop_Res;
                        CurState = TCtrlState.cOpChange;
                        Edit.Clear();
                        break;
                    case TCtrlState.cOpChange:
                        Proc.Operation = oper;
                        Edit.Clear();
                        break;
                    case TCtrlState.cError:
                        Proc.ResetProc();
                        return "ERR";
                }
                toReturn = Proc.Lop_Res.ToString();
            }
            catch
            {
                Reset();
                return "ERROR";
            }
            history.AddRecord(toReturn, oper.ToString());
            return toReturn;
        }

        public string ExeFunction(TProc<T>.TFunc func)
        {
            string toReturn;
            try
            {
                if(CurState == TCtrlState.cExpDone)
                {
                    Proc.Rop = Proc.Lop_Res;
                    Proc.Operation = TProc<T>.TOprtn.None;
                }
                Proc.DoFunc(func);
                CurState = TCtrlState.FunDone;
                toReturn = Proc.Rop.ToString();
            }
            catch
            {
                Reset();
                return "ERROR";
            }
            history.AddRecord(toReturn, func.ToString());
            return toReturn;
        }

        public string Calculate()
        {
            string ToReturn;
            try
            {
                if (CurState == TCtrlState.cStart)
                    Proc.Lop_Res = Proc.Rop;
                Proc.DoOper();
                CurState = TCtrlState.cExpDone;
                ToReturn = Proc.Lop_Res.ToString();
            }
            catch
            {
                Reset();
                return "ERROR";
            }
            return ToReturn;
        }

        public (T, TMemory<T>.NumStates) ExecCommandMemory(TMemory<T>.Commands command, string str)
        {
            T tmp = new T();
            tmp.SetString(str);
            (T, TMemory<T>.NumStates) obj = (null, TMemory<T>.NumStates.OFF);
            try
            {
                obj = Memory.Edit(command, tmp);
            }
            catch
            {
                Reset();
                return obj;
            }
            if(command == TMemory<T>.Commands.Copy)
            {
                Edit.Fraction = obj.Item1.ToString();
                Proc.Rop = obj.Item1;
            }
            return obj;
        }
    }
}