using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MPT_RGZ
{
    public partial class Form1 : Form
    {
        TCtrl<TFrac, TFracEditor> fracController;
        bool fracMode = true;
        const string operations = "+-/*";
        string clipboard = string.Empty;

        private string NumberBeatifier(string v)
        {
            if (v == "ERROR")
                return v;
            string toReturn = v;
            if (fracMode == true)
                toReturn = v;
            else if (new TFrac(v).getDenominatorNum() == 1)
                toReturn = new TFrac(v).getNumeratorString();
            return toReturn;
        }

        private static TFracEditor.Command CharToEditorCommand(char ch)
        {
            TFracEditor.Command command = TFracEditor.Command.None;
            switch (ch)
            {
                case '0':
                    command = TFracEditor.Command.Zero;
                    break;
                case '1':
                    command = TFracEditor.Command.One;
                    break;
                case '2':
                    command = TFracEditor.Command.Two;
                    break;
                case '3':
                    command = TFracEditor.Command.Three;
                    break;
                case '4':
                    command = TFracEditor.Command.Four;
                    break;
                case '5':
                    command = TFracEditor.Command.Five;
                    break;
                case '6':
                    command = TFracEditor.Command.Six;
                    break;
                case '7':
                    command = TFracEditor.Command.Seven;
                    break;
                case '8':
                    command = TFracEditor.Command.Eight;
                    break;
                case '9':
                    command = TFracEditor.Command.Nine;
                    break;
                case '.':
                    command = TFracEditor.Command.Separator;
                    break;
                case '-':
                    command = TFracEditor.Command.Sign;
                    break;
            }
            return command;
        }

        private static TProc<T>.TOprtn CharToOperationsCommand<T>(char ch) where T : TFrac, new()
        {
            TProc<T>.TOprtn command = TProc<T>.TOprtn.None;
            switch (ch)
            {
                case '+':
                    command = TProc<T>.TOprtn.Add;
                    break;
                case '-':
                    command = TProc<T>.TOprtn.Sub;
                    break;
                case '*':
                    command = TProc<T>.TOprtn.Mul;
                    break;
                case '/':
                    command = TProc<T>.TOprtn.Div;
                    break;
            }
            return command;
        }

        private static TFracEditor.Command KeyCodeToEditorCommand(Keys ch)
        {
            TFracEditor.Command command = TFracEditor.Command.None;
            switch (ch)
            {
                case Keys.Back:
                    command = TFracEditor.Command.BS;
                    break;
                case Keys.Delete:
                case Keys.Escape:
                    command = TFracEditor.Command.CE;
                    break;
            }
            return command;
        }

        public Form1()
        {
            fracController = new TCtrl<TFrac, TFracEditor>();
            InitializeComponent();
        }

        public void Button_Number_Edit(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string fulltag = button.Tag.ToString();
            Enum.TryParse(fulltag, out TFracEditor.Command ParsedEnum);
            textBox1.Text = fracController.ExecComandEditor(ParsedEnum);
        }

        public void Button_Number_Operation(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string fulltag = button.Tag.ToString();
            Enum.TryParse(fulltag, out TProc<TFrac>.TOprtn ParsedEnum);
            textBox1.Text = NumberBeatifier(fracController.ExecOperation(ParsedEnum));
        }

        public void Button_Number_Function(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string fulltag = button.Tag.ToString();
            Enum.TryParse(fulltag, out TProc<TFrac>.TFunc ParsedEnum);
            textBox1.Text = NumberBeatifier(fracController.ExeFunction(ParsedEnum));
        }

        private void Button_Reset(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string fulltag = button.Tag.ToString();
            textBox1.Text = fracController.Reset();
            label1.Text = string.Empty;
        }

        private void Button_FinishEval(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string FullTag = button.Tag.ToString();
            textBox1.Text = NumberBeatifier(fracController.Calculate());
        }

        private void Button_Memory(object sender, EventArgs e)
        {
            Button button = (Button)sender;
            string FullTag = button.Tag.ToString();
            Enum.TryParse(FullTag, out TMemory<TFrac>.Commands ParsedEnum);
            dynamic exec = fracController.ExecCommandMemory(ParsedEnum, textBox1.Text);
            if (ParsedEnum == TMemory<TFrac>.Commands.Copy)
                textBox1.Text = exec.Item1.ToString();
            label1.Text = exec.Item2 == TMemory<TFrac>.NumStates.ON ? "M" : string.Empty;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
                button26.PerformClick();
            else
            {
                TFracEditor.Command comm = KeyCodeToEditorCommand(e.KeyCode);
                if (comm != TFracEditor.Command.None)
                    textBox1.Text = fracController.ExecComandEditor(comm);
            }
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar >= '0' && e.KeyChar <= '9' || e.KeyChar == '.')
                textBox1.Text = fracController.ExecComandEditor(CharToEditorCommand(e.KeyChar));
            else if (operations.Contains(e.KeyChar))
                textBox1.Text = NumberBeatifier(fracController.ExecOperation(CharToOperationsCommand<TFrac>(e.KeyChar)));
        }

        private void дробьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            дробьToolStripMenuItem.Checked = true;
            числоToolStripMenuItem.Checked = false;
            fracMode = true;
        }

        private void числоToolStripMenuItem_Click(object sender, EventArgs e)
        {
            дробьToolStripMenuItem.Checked = false;
            числоToolStripMenuItem.Checked = true;
            fracMode = false;
        }

        private void копироватьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            clipboard = textBox1.Text;
        }

        private void вставитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (clipboard == string.Empty)
            {
                MessageBox.Show("Буфер обмена пуст.\n" +
                    "Нечего вставить.", 
                    "Ошибка", 
                    MessageBoxButtons.OK, 
                    MessageBoxIcon.Exclamation);
                return;
            }
            foreach(char i in clipboard)
                textBox1.Text = fracController.ExecComandEditor(CharToEditorCommand(i));
        }

        private void справкаToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Калькулятор дробных чисел.\n" +
                "Разработал: Михеев Н.А.\n" +
                "Группа: ИП-713.", 
                "Справка", 
                MessageBoxButtons.OK, 
                MessageBoxIcon.Information);
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            Form2 history = new Form2();
            history.Show();
            if (fracController.history.Count() == 0)
            {
                MessageBox.Show("История пуста", "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            for (int i = 0; i < fracController.history.Count(); i++)
            {
                List<string> currentRecord = fracController.history[i].ToList();
                history.dataGridView1.Rows.Add(currentRecord[0], currentRecord[1]);
            }
        }
    }
}
