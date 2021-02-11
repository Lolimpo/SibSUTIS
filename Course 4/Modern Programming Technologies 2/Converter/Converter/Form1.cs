using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Converter
{
    public partial class Form1 : Form
    {
        ADT_Control_ control_ = new ADT_Control_();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label1.Text = control_.editor.Number;
            trackBar1.Value = control_.Pin;
            trackBar2.Value = control_.Pout;
            label2.Text = "0";
            UpdateButtons();
        }

        private void doCmnd(Editor.Commands j)
        {
            if(j == Editor.Commands.exec)
                label2.Text = control_.doCmnd(j);
            else
            {
                if (control_.St == ADT_Control_.State.Converted)
                    label1.Text = control_.doCmnd(Editor.Commands.CLEAR);
                label1.Text = control_.doCmnd(j);
                label2.Text = "0";
            }
        }

        private void UpdateButtons()
        {
            foreach(Control i in Controls)
            {
                if(i is Button)
                {
                    int j = Convert.ToInt16(i.Tag.ToString());
                    if (j < trackBar1.Value)
                        i.Enabled = true;
                    if ((j >= trackBar1.Value) && (j <= 15))
                        i.Enabled = false;
                }
            }
        }

        private void trackbar1_Scroll(object sender, EventArgs e)
        {
            numericUpDown1.Value = trackBar1.Value;
            UpdateP1();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            trackBar1.Value = Convert.ToByte(numericUpDown1.Value);
            UpdateP1();
        }

        private void UpdateP1()
        {
            control_.Pin = trackBar1.Value;
            UpdateButtons();
            label1.Text = control_.doCmnd(Editor.Commands.CLEAR);
            label2.Text = "0";
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            numericUpDown2.ValueChanged -= numericUpDown2_ValueChanged;
            numericUpDown2.Value = trackBar2.Value;
            numericUpDown2.ValueChanged += numericUpDown2_ValueChanged;
            UpdateP2();
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            trackBar2.Value = Convert.ToByte(numericUpDown2.Value);
            UpdateP2();
        }

        private void UpdateP2()
        {
            control_.Pout = trackBar2.Value;
            label2.Text = control_.doCmnd(Editor.Commands.exec);
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void историяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 history = new Form2();
            history.Show();
            if (control_.history.Count() == 0)
            {
                MessageBox.Show("История пуста", "Внимание", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            for (int i = 0; i < control_.history.Count(); i++)
            {
                List<string> currentRecord = control_.history[i].toList();
                history.dataGridView1.Rows.Add(currentRecord[0], currentRecord[1], currentRecord[2], currentRecord[3]);
            }
        }

        private void справкаToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Ковертер p1_p2.\n" +
                "Авторы: Михеев Никита\n" +
                "Устенко Дмитрий\n" +
                "Группа: ИП-713.", "Справка", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            int i = -1;
            if (e.KeyChar >= 'A' && e.KeyChar <= 'F')
                i = e.KeyChar - 'A' + 10;
            if (e.KeyChar >= 'a' && e.KeyChar <= 'f')
                i = e.KeyChar - 'a' + 10;
            if (e.KeyChar >= '0' && e.KeyChar <= '9')
                i = e.KeyChar - '0';
            if (e.KeyChar == '.')
                i = 16;
            if (e.KeyChar == 8)
                i = 17;
            if (e.KeyChar == 13)
                i = 19;
            if (i == -1)
                return;
            doCmnd((Editor.Commands)Enum.GetValues(typeof(Editor.Commands)).GetValue(i));
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
                doCmnd(Editor.Commands.BS);
            if (e.KeyCode == Keys.Execute)
                doCmnd(Editor.Commands.exec);
            if (e.KeyCode == Keys.Decimal)
                doCmnd(Editor.Commands.addDot);
        }

        private void button_Click(object sender, EventArgs e)
        {
            Button but = (Button)sender;
            int j = Convert.ToInt16(but.Tag.ToString());
            doCmnd((Editor.Commands)Enum.GetValues(typeof(Editor.Commands)).GetValue(j));
        }
    }
}
