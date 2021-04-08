using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab11
{
    public partial class Form1 : Form
    {
        public UAbonentList contacts;
        public Form1()
        {
            InitializeComponent();
            contacts = new UAbonentList();
            contacts.Load();
            UpdateTextBox();
        }

        private void UpdateTextBox()
        {
            richTextBox1.Clear();
            foreach(KeyValuePair<String, String> kvp in contacts.contactsMap)
            {
                richTextBox1.AppendText("Name: " + kvp.Key + "; " + "Phone: " + kvp.Value + ";\n");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            contacts.Save();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            contacts.Remove(textBox1.Text);
            UpdateTextBox();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            contacts.Clear();
            UpdateTextBox();
        }

        private void button4_Click(object sender, EventArgs e)
        {

            if (contacts.Edit(textBox1.Text, textBox2.Text))
            {
                textBox1.Clear();
                textBox2.Clear();
                UpdateTextBox();
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if(contacts.Insert(textBox1.Text, textBox2.Text))
            {
                textBox1.Clear();
                textBox2.Clear();
                UpdateTextBox();
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if(contacts.Find(textBox1.Text, textBox2.Text))
            {
                textBox1.Clear();
                textBox2.Clear();
            }
        }
    }
}
