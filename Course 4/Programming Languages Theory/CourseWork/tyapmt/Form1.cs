using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace tyapmt
{
    public partial class Form1 : Form
    {
        public List<String> alphabet = new List<string>();
        public string subchain = "";
        public string symbol = "";
        public int krat;
        public string _gen;
        int num1, num2;

        public Form1()
        {
            InitializeComponent();
        }

        private void авторToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Автор: Михеев Н.А.\nГруппа: ИП-713\nВариант: №9",
                "Автор", 
                MessageBoxButtons.OK, 
                MessageBoxIcon.Information);
        }

        private void заданиеToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Написать программу, которая по предложенному описанию языка построит регулярное выражение, " +
                "задающее этот язык, и сгенерирует с его помощью все цепочки языка в заданном диапазоне длин." +
                "Предусмотреть также возможность генерации цепочек по введённому пользователем РВ(в рамках варианта).\n" +
                "Алфавит, кратность вхождения некоторого символа алфавита во все цепочки языка и заданная подцепочка всех цепочек языка.",
                "Тема", 
                MessageBoxButtons.OK, 
                MessageBoxIcon.Information);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            alphabet.Clear();
            subchain = "";
            symbol = "";
            krat = 0;
            Regex rg = new Regex(@"^([a-zA-Z]{1}([,]|$)){1,}$");
            if (!rg.IsMatch(textBox1.Text))
            {
                MessageBox.Show("Некорректно введен алфавит.\nВведите символы алфавита через запятую.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
                foreach (string letter in textBox1.Text.Split(','))
                    alphabet.Add(letter);
            if(textBox2.Text.Length < 1)
            {
                if(textBox2.Text.Length == 0)
                {
                    subchain = "";
                }
                else
                {
                    MessageBox.Show("Некорректно введенная подцепочка.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
            }
            else
            {
                foreach(char tmp in textBox2.Text.ToCharArray())
                {
                    if(!alphabet.Contains(tmp.ToString()))
                    {
                        MessageBox.Show("Подцепочка состоит из символов, непринадлежащих алфавиту.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                }
                subchain = textBox2.Text;
            }
            if (textBox3.Text.Length != 1)
            {
                MessageBox.Show("Введено больше 1 символа.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
            { 
                if(!alphabet.Contains(textBox3.Text))
                {
                    MessageBox.Show("Такого символа для кратности нет в алфавите.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }
                else
                    symbol = Convert.ToString(textBox3.Text);
            }
            try { krat = Convert.ToInt32(textBox4.Text); }
            catch(FormatException)
            {
                MessageBox.Show("Задана неправильная кратность.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            gen_regular_expression();
    }

        private void gen_regular_expression()
        {
            List<String> free_symbols = alphabet;
            free_symbols.Remove(symbol);

            string regular_free_chain = "(" + String.Join("+", free_symbols) + ")*";
            string regular_with_krat = "(" + String.Concat(Enumerable.Repeat(regular_free_chain + symbol, krat)) + regular_free_chain + ")*";

            int count_of_symb_in_subchain = new Regex(Regex.Escape(symbol)).Matches(subchain).Count;
            if (count_of_symb_in_subchain % krat == 0)
            {
                //richTextBox1.Text = regular_with_krat + subchain + regular_with_krat;
                if (subchain.Length != 0)
                {
                    List<string> perms = new List<string>();
                    
                    List<string> vals = new List<string>();
                    vals.Add(subchain + regular_free_chain);
                    for (int i = 0; i < krat - 2; i++)
                        vals.Add(symbol + regular_free_chain);
                    foreach(var perm in vals.GetPermutations())
                    {
                        if (!perms.Contains(string.Join("", perm)))
                            perms.Add(string.Join("", perm));
                    }
                    /*richTextBox1.Text = regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length) +
                        "(" + subchain + "+" + symbol + regular_free_chain + subchain + regular_free_chain + symbol + ")"
                        + regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length);*/
                    richTextBox1.Text = regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length) + "(" + subchain + "+";
                    for (int i = 0; i < perms.Count; i++)
                    {
                        //richTextBox1.Text += symbol + regular_free_chain + perm;
                        if (i == perms.Count - 1)
                            richTextBox1.Text += symbol + regular_free_chain + perms[i];
                        else
                            richTextBox1.Text += symbol + regular_free_chain + perms[i] + symbol + "+";
                    }
                    richTextBox1.Text += symbol + ")" +regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length);

                }
                else
                    richTextBox1.Text = regular_with_krat + "(" + regular_free_chain + subchain + regular_free_chain + ")" + regular_with_krat;
                return;
            }

            List<String> premutations = new List<string>();
            int num_of_premutations = krat - count_of_symb_in_subchain % krat + 1;
            for (int i = 0; i < num_of_premutations; i++)
            {
                List<String> perm = new List<string>();
                for (int j = 0; j < num_of_premutations; j++)
                    perm.Add(symbol);
                perm[i] = subchain;
                premutations.Add(String.Join(regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length), perm));
            }
            richTextBox1.Text = regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length) + "((" + String.Join(")+(", premutations) + "))" + regular_free_chain + regular_with_krat.Remove(regular_with_krat.IndexOf(regular_free_chain), regular_free_chain.Length);
            return;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox2.Text = "";
            num1 = Convert.ToInt32(numericUpDown1.Value.ToString());
            num2 = Convert.ToInt32(numericUpDown2.Value.ToString());
            if (num1 > num2)
            {
                int tmp = num1;
                num1 = num2;
                num2 = tmp;
            }
            if (!String.IsNullOrEmpty(richTextBox1.Text))
            {
                string regular = richTextBox1.Text;
                List<String> str = MergeBlocks(regular, num2, false);

                List<string> out_str = new List<string>();
                foreach(var i in str)
                {
                    if (i.Length >= num1)
                    {
                        if (num1 == 0 && i.Length == num1)
                            out_str.Add("λ");
                        else if(i.Contains(subchain) || subchain.Length == 0)
                            out_str.Add(i);
                    }
                }
                out_str.Sort((x, y) => x.Length.CompareTo(y.Length));
                richTextBox2.Text = String.Join(" ", out_str);
            }
            else
            {
                MessageBox.Show("Сначала сгенерируйте регулярное выражение.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private List<string> SplitByPlus(string chain)
        {
            int scobki = 0;
            List<string> SpPlus = new List<string>();
            string str = "";
            for(int i = 0; i < chain.Length; i++)
            {
                if (chain[i] == '(')
                    scobki++;
                else if (chain[i] == ')')
                    scobki--;
                if ((chain[i] != '+') || (scobki != 0))
                    str += chain[i];
                else if(scobki == 0)
                {
                    SpPlus.Add(str);
                    str = "";
                }
            }
            SpPlus.Add(str);
            return SpPlus;
        }

        private List<string> SplitByBrackets(string chain)
        {
            int scobki = 0;
            List<string> Split = new List<string>();
            string str = "";
            for (int i = 0; i < chain.Length; i++)
            {
                if (chain[i] == '(')
                    scobki++;
                else if(chain[i] == ')')
                {
                    scobki--;
                    if((chain.Length > (i + 1)) && (chain[i + 1] == '*'))
                    {
                        str += chain[i];
                        i++;
                    }
                }
                str += chain[i];
                if(scobki == 0)
                {
                    Split.Add(str);
                    str = "";
                }
            }
            return Split;
        }

        private List<string> BuildBricks(string s, int max)
        {
            List<string> SpScob = SplitByBrackets(s);
            List<List<string>> Mas = new List<List<string>>();

            bool newinf = false;
            for(int i = 0; i < SpScob.Count; i++)
            {
                if(SpScob[i][0] == '(')
                {
                    string tmp = "";
                    if(SpScob[i][SpScob[i].Length - 1] == '*')
                    {
                        tmp = SpScob[i].Substring(1, SpScob[i].Length - 3);
                        newinf = true;
                    }
                    else if(SpScob[i][SpScob[i].Length - 1] == ')')
                        tmp = SpScob[i].Substring(1, SpScob[i].Length - 2);

                    List<string> merge = MergeBlocks(tmp, max, newinf);
                    Mas.Add(merge);
                }
                else
                {
                    List<string> str = new List<string>();
                    str.Add(SpScob[i]);
                    Mas.Add(str);
                }
            }

            HashSet<string> set = new HashSet<string>();
            ConcatenateBricks(ref Mas, max, 0, "", ref set);
            List<string> NewBrick = new List<string>();
            foreach (var i in set)
                NewBrick.Add(i);
            return NewBrick;
        }

        private void ConcatenateBricks(ref List<List<string>> Mas, int max, int index, string s, ref HashSet<string> set)
        {
            if(index == Mas.Count)
            {
                set.Add(s);
                return;
            }

            for(int i = 0; i < Mas[index].Count; i++)
            {
                string newS = s + Mas[index][i];
                if (newS.Length > max)
                    continue;
                ConcatenateBricks(ref Mas, max, index + 1, newS, ref set);
            }
        }

        private List<string> MergeBlocks(string s, int max, bool inf)
        {
            List<string> MergeList = new List<string>();
            List<string> SpPlus = SplitByPlus(s);

            for (int i = 0; i < SpPlus.Count; i++)
            {
                List<string> buildB = BuildBricks(SpPlus[i], max);

                for(int j = 0; j < buildB.Count; j++)
                {
                    for(int k = 0; k < MergeList.Count; k++)
                    {
                        if(MergeList[k] == buildB[j])
                        {
                            MergeList.RemoveAt(0 + k);
                            k--;
                        }
                    }
                }
                for(int j = 0; j < buildB.Count; j++)
                    MergeList.Add(buildB[j]);
            }

            if(inf)
            {
                HashSet<string> set = new HashSet<string>();
                Generator(ref MergeList, max, "", ref set);
                MergeList.Clear();
                foreach (var i in set)
                    MergeList.Add(i);
                MergeList.Add("");
            }
            return MergeList;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            List<String> file_lines = new List<string>();
            if(textBox1.Text.Length != 0)
            {
                file_lines.Add("Алфавит:");
                file_lines.Add(textBox1.Text);
            }
            if(textBox2.Text.Length != 0)
            {
                file_lines.Add("Подцепочка:");
                file_lines.Add(textBox2.Text);
            }
            if(textBox3.Text.Length != 0)
            {
                file_lines.Add("Символ: " + textBox3.Text);
            }
            if(textBox4.Text.Length != 0)
            {
                file_lines.Add("Кратность:" + textBox4.Text);
            }
            if(richTextBox1.Text.Length == 0)
            {
                MessageBox.Show("Нет регулярного выражения для записи в файл.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            else
            {
                file_lines.Add("Регулярное выражение:");
                file_lines.Add(richTextBox1.Text);
            }
            if(richTextBox2.Text.Length == 0)
            {
                MessageBox.Show("Нет сгенерированых цепочек.", "Предупреждение", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                file_lines.Add("Сгенерированные цепочки от " + numericUpDown1.Value + " до " + numericUpDown2.Value + ":");
                file_lines.Add(richTextBox2.Text);
            }
            string file_name = @"results" + DateTime.Now.ToString("dd-M-yyyy--HH-mm-ss") + ".txt";
            System.IO.File.WriteAllLines(file_name, file_lines);
            Process.Start(file_name);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Generator(ref List<string> MergeList, int max, string s, ref HashSet<string> set)
        {
            for(int i = 0; i < MergeList.Count; i++)
            {
                string newS = s + MergeList[i];
                List<string> set_list = set.ToList();
                if (newS.Length > max || set_list.Contains(newS))
                    continue;
                set.Add(newS);
                Generator(ref MergeList, max, newS, ref set);
            }
        }
    }
}
