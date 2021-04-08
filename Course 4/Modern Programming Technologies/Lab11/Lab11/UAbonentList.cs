using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Net.Http;
using System.Security.Policy;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab11
{
    public class UAbonentList
    {
        public SortedDictionary<string, string> contactsMap;

        public UAbonentList()
        {
            contactsMap = new SortedDictionary<string, string>();
        }

        public bool Insert(string name, string number)
        {
            Regex numReg = new Regex("\\+?\\d{11}");
            if(name.Length == 0 || !numReg.IsMatch(number))
            {
                MessageBox.Show("Wrong name or number.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if(contactsMap.ContainsKey(name))
            {
                MessageBox.Show("Abonent already exists.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            contactsMap.Add(name, number);
            return true;
        }

        public bool Remove(string name)
        {
            if(!contactsMap.ContainsKey(name))
            {
                MessageBox.Show("No such abonent.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            contactsMap.Remove(name);
            return true;
        }

        public bool Edit(string name, string number)
        {
            if(!contactsMap.ContainsKey(name))
            {
                MessageBox.Show("No such abonent.\nNothing to change", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            Regex numReg = new Regex("\\+?\\d{11}");
            if (!numReg.IsMatch(number))
            {
                MessageBox.Show("Wrong number.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            contactsMap[name] = number;
            return true;
        }

        public bool Find(string name, string number)
        {
            if(name.Length != 0)
            {
                if(contactsMap.ContainsKey(name))
                {
                    MessageBox.Show("Name: " + name + "\nNumber: " + contactsMap[name], "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return true;
                }
            }
            else if(number.Length != 0)
            {
                if (contactsMap.ContainsValue(number))
                {
                    MessageBox.Show("Name: " + contactsMap.FirstOrDefault(x => x.Value == number).Key + "\nNumber: " + number, "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    return true;
                }
            }
            else if(name.Length == 0 && number.Length == 0)
            {
                MessageBox.Show("Empty search.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            MessageBox.Show("No such abonent.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            return false;
        }

        public void Clear()
        {
            contactsMap.Clear();
        }

        public void Save()
        {
            try
            {
                using(StreamWriter sw = new StreamWriter("contacts.txt"))
                {
                    
                    foreach(KeyValuePair<String, String> kvp in contactsMap)
                    {
                        Console.WriteLine(kvp.Key + ";" + kvp.Value);
                        sw.WriteLine(kvp.Key + ";" + kvp.Value);
                    }
                }
                MessageBox.Show("File saved successfully.", "Successful", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception e)
            {
                Console.WriteLine("Error while opening file: " + e.ToString());
            }
        }

        public void Load()
        {
            if (File.Exists("contacts.txt"))
            {
                try
                {
                    using (StreamReader sr = new StreamReader("contacts.txt", Encoding.Default))
                    {
                        string str;
                        while ((str = sr.ReadLine()) != null)
                        {
                            string[] entry;
                            string[] sep = { ";" };
                            entry = str.Split(sep, StringSplitOptions.RemoveEmptyEntries);
                            contactsMap.Add(entry[0], entry[1]);
                        }
                    }
                }
                catch (Exception e)
                {
                    Debug.WriteLine("Error while reading file: " + e.ToString());
                }
            }
            else
            {
                File.Open("contacts.txt", FileMode.Create);
            }
        }

    }
}
