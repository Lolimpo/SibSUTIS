#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

struct record
{
    char name[32];
    char street[18];
    short int house;
    short int flat;
    char date[10];
} *tt;

struct spis
{
    spis *next;
    record *data;
}*base_head, *base_tail, *head, *tail, *search_head, *search_tail;

struct queue
{
	spis *head;
	spis *tail;
};

struct node
{
	record *data;
	node *left;
	node *right;
	int bal;
}*root;

void add_queue(spis* &head, spis* &tail, record *array)
{
    spis *p = new spis;
    p -> data = array;
    p -> next = NULL;
    if (head == NULL)
    {
        head = tail = p;
        head -> next = NULL;
    }
    else
    {
        tail -> next = p;
        tail = p;
    }
}

void read_file()
{
    fstream file("testBase4.dat", ios::binary | ios::in);
    for(int i = 0; i < 4000; i++)
    {
        tt = new record;
        file.seekp(64*i, ios::beg);
        file.read((char*)tt, sizeof(record));
        add_queue(head, tail, tt);
        add_queue(base_head, base_tail, tt);
    }
    file.close();
}

void print_spis(spis *head)
{
    int k, i = 0, size = 4000;
    char c;
    spis *p;
    p = head;
    do
    {
        system("cls");
        k = i + 20;
        for(i; i < k; i++)
        {
            if(p == NULL)
                return;
            cout << p -> data -> name << "\t ";
            cout << p -> data -> street << "\t ";
            cout << p -> data -> house << "\t ";
            cout << p -> data -> flat << "\t ";
            cout << p -> data -> date << endl;
            p = p -> next;
        }
        cout << "\nPrint 0 to stop or any key to continue..." << endl;
        cin >> c;
        if(c == '0')
            break;
    }
    while(i < size);
}

bool Comparator(string str1, string str2, string str3, string str4)
{
    int year = str1.compare(6, 2, str2, 6, 2);
    int month = str1.compare(3, 2, str2, 3, 2);
    int day = str1.compare(0, 2, str2, 0, 2);
    if((year <= 0) && (month <= 0) && (day <= 0) && (str3 < str4))
    {
        return true;
    }
    else if((year <= 0) && (month <= 0) && (day < 0))
    {
        return true;
    }
    else if((year <= 0) && (month < 0))
    {
        return true;
    }
    else if(year < 0)
    {
        return true;
    }
    return false;
}

void Separation(spis* &head, spis* &a, spis* &b, int &n)
{
    spis *p,*q;
   	a = head;
   	b = head -> next;
   	n = 1;
	p = a;
	q = b;
   	while (q)
   	{
   	    n++;
        p -> next = q -> next;
        p = q;
        q = q -> next;
    }
}

int MergeSort(spis* &head)
{
   int m, n;
   spis *a, *b, *s, *d;
   queue c[2];
   int p = 1, q, r;
   if(head == 0)
    return 0;
   Separation(head, a, b, n);

   while(p < n)
   {
      c[0].tail = (spis*) & (c[0].head);
      c[1].tail = (spis*) & (c[1].head);
      int i = 0;
	  m = n;
      while(m > 0)
      {
          if(m >= p)
            q = p;
          else
            q = m;
        m -= q;

        if(m >= p)
            r = p;
        else
            r = m;
        m -= r;

        while((q > 0) && (r > 0))
        {
            string str1 = a -> data -> date;
            string str2 = b -> data -> date;
            string str3 = a -> data -> street;
            string str4 = b -> data -> street;
            if(Comparator(str1, str2, str3, str4))
            {
                c[i].tail -> next = a;
                c[i].tail = a;
                a = a -> next;
                q--;
            }
            else
            {
	            c[i].tail -> next = b;
	            c[i].tail = b;
                b = b -> next;
	            r--;
            }
        }

        while(q > 0)
        {
            c[i].tail -> next = a;
            c[i].tail = a;
            a = a -> next;
            q--;
        }

        while(r > 0)
        {
            c[i].tail->next = b;
            c[i].tail = b;
            b = b->next;
            r--;
        }
        i = 1-i;
      }
      a = c[0].head;
	  b = c[1].head;
      p*= 2;
   }
   c[0].tail -> next=0;
   head = c[0].head;
}

int Binary_Search(int n, spis* A[], char *key)
{
    int m;
    int l = 0, r = n - 1;
    string str;
    while(l < r)
    {
        m = (l + r) / 2;
        str = A[m] -> data -> date;
        if(str.compare(6, 2, key, 0, 2) < 0)
            l = m + 1;
        else
            r = m;
    }
    str = A[r] -> data -> date;
    if(str.compare(6, 2, key, 0, 2) == 0)
        return r;
    else
        return -1;
}

bool VR = 1, HR = 1;

void DBD (node *&p, record *D)
{
    node *q;
    if (p == NULL)
    {
        p = new node;
        p -> data = D;
        p -> left = p -> right = NULL;
        p -> bal = 0;
        VR = true;
    }
    else if((p -> data -> house) >= (D -> house))
    {
        DBD(p -> left, D);
        if(VR == true)
        {
            if(p -> bal == 0)
            {
                q = p -> left;
                p -> left = q -> right;
                q -> right = p;
                p = q;
                q -> bal = 1;
                VR = false;
                HR = true;

            }
            else
            {
                p -> bal = 0;
                VR = true;
                HR = false;
            }


        }
        else
            HR = false;
    }
    else if((p -> data -> house) <= (D -> house))
    {
        DBD(p -> right, D);
        if(VR == true)
        {
            p -> bal = 1;
            HR = true;
            VR = false;
        }
        else if(HR == true)
        {
            if(p -> bal == 1)
            {
                q = p -> right;
                p -> bal = 0;
                q -> bal = 0;
                p -> right = q -> left;
                q -> left = p;
                p = q;
                VR = true;
                HR = false;
            }
            else
                HR = false;
        }
    }
}

void leftright_representation(struct node *p) //обход слева направо
{
    if (p == NULL) return;
    else
    {
        leftright_representation(p->left);

        cout << p -> data -> name << "\t ";
        cout << p -> data -> street << "\t ";
        cout << p -> data -> house << "\t ";
        cout << p -> data -> flat << "\t ";
        cout << p -> data -> date << endl;

        leftright_representation(p->right);
    }
}

int main()
{
    spis *PArray[4000], *p;
    char *key;
    string str;
    int size = 4000;
    int i = 0, button, pos;
    read_file();

    for(p = head; p; p = p -> next) //Points array
    {
        PArray[i] = p;
    }

    while(1)
    {
        system("cls");
        cout << "1. Main Base" << endl;
        cout << "2. Sorted Base" << endl;
        cout << "3. Binary Search" << endl;
        cout << "4. DBD-Tree" << endl;
        cout << "0. Exit" << endl;
        cin >> button;
        system("cls");
        switch(button)
        {
        case 1:
            print_spis(base_head); //start base
            break;
        case 2:
            MergeSort(head); //merge sort
            print_spis(head); //sorted base
            break;
        case 3:
            cout << "Print a key:";
            cin >> key;
            pos = Binary_Search(size, PArray, key);
            if(pos != -1)
            {
                str = PArray[pos] -> data -> date;
                while(str.compare(6, 2, key, 0, 2) == 0)
                {
                    add_queue(search_head, search_tail, PArray[pos] -> data);
                    pos++;
                    str = PArray[pos] -> data -> date;
                }
            }
            print_spis(search_head); //search base
            break;
        case 4:
            if (search_head == NULL)
            {
                cout << "Make search first!" << endl;
                system("PAUSE");
            }
            else
            {
                for(p = search_head; p; p = p -> next)
                {
                    DBD(root, p -> data);
                }
                leftright_representation(root);
            }
            break;
        default:
            terminate();
        }
    }
    return 0;
}
