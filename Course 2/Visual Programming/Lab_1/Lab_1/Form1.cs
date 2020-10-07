using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            listBox2.BeginUpdate();
            foreach(Object Item in listBox1.SelectedItems)
            {
                listBox2.Items.Add(Item);
            }
            listBox2.EndUpdate();
            for (int i = listBox1.Items.Count - 1; i >= 0; i--)
            {
                if (listBox1.GetSelected(i)) listBox1.Items.RemoveAt(i);
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            
        }

        private void открытьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog OpenDlg = new OpenFileDialog();
            if(OpenDlg.ShowDialog() == DialogResult.OK)
            {

                StreamReader Reader = new StreamReader(OpenDlg.FileName, Encoding.Default);
                richTextBox1.Text = Reader.ReadToEnd();
                Reader.Close();
            }
            OpenDlg.Dispose();
        }

        private void сохранитьToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog SaveDlg = new OpenFileDialog();
            if(SaveDlg.ShowDialog() == DialogResult.OK)
            {
                StreamWriter Writer = new StreamWriter(SaveDlg.FileName);
                for(int i = 0; i < listBox2.Items.Count; i++)
                {
                    Writer.WriteLine((string)listBox2.Items[i]);
                }
                Writer.Close();
            }
            SaveDlg.Dispose();
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Выполнили студенты группы ИП-713:\nМихеев Никита\nУстенко Дмитрий\nФролов Кирилл");
        }

        private void button14_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox3.Items.Clear();

            listBox1.BeginUpdate();

            string[] Strings = richTextBox1.Text.Split(new char[] { '\n', '\t', ' ' }, StringSplitOptions.RemoveEmptyEntries);
            foreach(string s in Strings)
            {
                string str = s.Trim();

                if(str == String.Empty) continue;
                if(radioButton1.Checked) listBox1.Items.Add(str);
                if(radioButton2.Checked)
                {
                    if (Regex.IsMatch(str, @"\d")) listBox1.Items.Add(str);
                }
                if (radioButton3.Checked)
                {
                    if (Regex.IsMatch(str, @"\w+@\w+\.\w+")) listBox1.Items.Add(str);
                }
            }
            listBox1.EndUpdate();
        }

        private void button13_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            listBox2.Items.Clear();
            listBox3.Items.Clear();
            textBox2.Clear();
            richTextBox1.Clear();
            radioButton1.Checked = true;
            checkBox1.Checked = true;
            checkBox2.Checked = false;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            listBox2.Items.Clear();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            listBox3.Items.Clear();

            string Temp = textBox2.Text;

            if(checkBox1.Checked)
            {
                foreach(string String in listBox1.Items)
                {
                    if (String.Contains(Temp)) listBox3.Items.Add(String);
                }
            }

            if (checkBox2.Checked)
            {
                foreach (string String in listBox2.Items)
                {
                    if (String.Contains(Temp)) listBox3.Items.Add(String);
                }
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Form2 AddRecord = new Form2();
            AddRecord.Owner = this;
            AddRecord.ShowDialog();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedItems.Count == 1)
            {
                DeleteSelectedStrings(1);
            }
            if(listBox2.SelectedItems.Count == 1)
            {
                DeleteSelectedStrings(2);
            }
        }

        void DeleteSelectedStrings(int flag)
        {
            if(flag == 1)
            {
                for (int i = listBox1.Items.Count - 1; i >= 0; i--)
                {
                    if (listBox1.GetSelected(i)) listBox1.Items.RemoveAt(i);
                }
            }
            if (flag == 2)
            {
                for (int i = listBox2.Items.Count - 1; i >= 0; i--)
                {
                    if (listBox2.GetSelected(i)) listBox2.Items.RemoveAt(i);
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            listBox2.BeginUpdate();
            listBox2.Items.AddRange(listBox1.Items);
            listBox1.Items.Clear();
            listBox2.EndUpdate();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            listBox1.BeginUpdate();
            listBox1.Items.AddRange(listBox2.Items);
            listBox2.Items.Clear();
            listBox1.EndUpdate();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            listBox1.BeginUpdate();
            foreach (Object Item in listBox2.SelectedItems)
            {
                listBox1.Items.Add(Item);
            }
            listBox1.EndUpdate();
            for (int i = listBox2.Items.Count - 1; i >= 0; i--)
            {
                if (listBox2.GetSelected(i)) listBox2.Items.RemoveAt(i);
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (comboBox1.GetItemText(comboBox1.SelectedItem) == "Алфавиту (по возрастанию)")
            {
                listBox1.Sorted = true;
            }
            if (comboBox1.GetItemText(comboBox1.SelectedItem) == "Алфавиту (по убыванию)")
            {
                listBox1.Sorted = true;
                string[] clist = listBox1.Items.OfType<string>().ToArray();
                listBox1.Sorted = false;
                Array.Reverse(clist);
                listBox1.Items.Clear();
                listBox1.Items.AddRange(clist);
            }
            if (comboBox1.GetItemText(comboBox1.SelectedItem) == "Длине слова (по возрастанию)")
            {
                string[] clist = listBox1.Items.OfType<string>().ToArray();
                for (int i = 0; i < clist.Length - 1; i++)  
                    for (int j = 0; j < clist.Length - i - 1; j++)
                    {
                        if (clist[j].Length > clist[j + 1].Length)
                        {
                            string TEMP = clist[j];
                            clist[j] = clist[j+1];
                            clist[j+1] = TEMP;
                        }
                }
                listBox1.Items.Clear();
                listBox1.Items.AddRange(clist);
            }
            if(comboBox1.GetItemText(comboBox1.SelectedItem) == "Длине слова (по убыванию)")
            {
                string[] clist = listBox1.Items.OfType<string>().ToArray();
                for (int i = 0; i < clist.Length - 1; i++)
                    for (int j = 0; j < clist.Length - i - 1; j++)
                    {
                        if (clist[j].Length > clist[j + 1].Length)
                        {
                            string TEMP = clist[j];
                            clist[j] = clist[j + 1];
                            clist[j + 1] = TEMP;
                        }
                    }
                listBox1.Items.Clear();
                Array.Reverse(clist);
                listBox1.Items.AddRange(clist);
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (comboBox2.GetItemText(comboBox2.SelectedItem) == "Алфавиту (по возрастанию)")
            {
                listBox2.Sorted = true;
            }
            if (comboBox2.GetItemText(comboBox2.SelectedItem) == "Алфавиту (по убыванию)")
            {
                listBox2.Sorted = true;
                string[] clist = listBox2.Items.OfType<string>().ToArray();
                listBox2.Sorted = false;
                Array.Reverse(clist);
                listBox2.Items.Clear();
                listBox2.Items.AddRange(clist);
            }
            if (comboBox2.GetItemText(comboBox2.SelectedItem) == "Длине слова (по возрастанию)")
            {
                string[] clist = listBox2.Items.OfType<string>().ToArray();
                for (int i = 0; i < clist.Length - 1; i++)
                    for (int j = 0; j < clist.Length - i - 1; j++)
                    {
                        if (clist[j].Length > clist[j + 1].Length)
                        {
                            string TEMP = clist[j];
                            clist[j] = clist[j + 1];
                            clist[j + 1] = TEMP;
                        }
                    }
                listBox2.Items.Clear();
                listBox2.Items.AddRange(clist);
            }
            if (comboBox2.GetItemText(comboBox2.SelectedItem) == "Длине слова (по убыванию)")
            {
                string[] clist = listBox2.Items.OfType<string>().ToArray();
                for (int i = 0; i < clist.Length - 1; i++)
                    for (int j = 0; j < clist.Length - i - 1; j++)
                    {
                        if (clist[j].Length > clist[j + 1].Length)
                        {
                            string TEMP = clist[j];
                            clist[j] = clist[j + 1];
                            clist[j + 1] = TEMP;
                        }
                    }
                listBox2.Items.Clear();
                Array.Reverse(clist);
                listBox2.Items.AddRange(clist);
            }
        }
    }
}