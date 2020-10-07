#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

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
	spis *dbd_head;
	spis *dbd_tail;
	int bal;
}*root;

int size_array_of_code = 0;

struct encoding
{
    unsigned char symbol;
    float p;
    char code[20];
    int length;
} array_code[256];

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
    int k = 0, i = 0, size = 4000;
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
            cout << i + 1 << "\t";
            cout << p -> data -> name << "\t ";
            cout << p -> data -> street << "\t ";
            cout << p -> data -> house << "\t ";
            cout << p -> data -> flat << "\t ";
            cout << p -> data -> date << endl;
            p = p -> next;
        }
        cout << "\nPrint 0 to stop or any key to continue..." << endl;
        cin.ignore(1);
        cin >> c;
        if(c == '0')
            break;
    }
    while(i < size);
}

void printmas(spis *mas[])
{
	int i = 1, k = 0;
	int move;
	bool key = true;
	do
	{
	if(key)
	{
		k = i + 20;
		for(; i < k; i++)
		{
			cout << i << "\t";
            cout << mas[i] -> data -> name << "\t ";
            cout << mas[i] -> data -> street << "\t ";
            cout << mas[i] -> data -> house << "\t ";
            cout << mas[i] -> data -> flat << "\t ";
            cout << mas[i] -> data -> date << endl;
		}
	}
	else
	{
		k = i - 20;
		for(i = i - 40; i < k; i++)
		{
			cout << i << "\t";
            cout << mas[i] -> data -> name << "\t ";
            cout << mas[i] -> data -> street << "\t ";
            cout << mas[i] -> data -> house << "\t ";
            cout << mas[i] -> data -> flat << "\t ";
            cout << mas[i] -> data -> date << endl;
		}
	}
	cout << "1-next\n2-back" << endl;
	cin >> move;
	if(move == 1)
		if(i < 4000)
			key = true;
		else
			return;
	if(move == 2)
		if(i > 21)
			key = false;
		else
			return;
	if(move != 1 && move != 2)
		return;
	}while(1);
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

int Separation(spis* &head, spis* &a, spis* &b, int &n)
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
    int m = 0;
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
    node *q = NULL;
    if (p == NULL)
    {
        p = new node;
        p -> data = D;
        p -> dbd_head = NULL;
        p -> left = p -> right = NULL;
        p -> bal = 0;
        VR = true;
    }
    else if((p -> data -> flat) > (D -> flat))
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
    else if((p -> data -> flat) < (D -> flat))
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
    else if((p -> data -> flat) == (D -> flat))
    {
        add_queue(p -> dbd_head, p -> dbd_tail, D);
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

int count_of_symbols = 0;

void open_file_base()
{
    unsigned char ch;
    FILE *file = fopen("testBase4.dat", "rb");
    if (file == NULL)
    {
        printf("Database can't open. Press any key for return to menu.");
        return;
    }
    for (int i = 0; i < 256; i++)
    {
        array_code[i].symbol = 1;
        array_code[i].p = 0;
        array_code[i].length = 0;
    }
    while (!feof(file))
    {
        fscanf(file, "%c", &ch);
        array_code[ch].p += 1.0;
        array_code[ch].symbol = ch;
        count_of_symbols++;
    }
    fclose(file);
    for (int i = 0; i < 256; i++)
    {
        if (array_code[i].p != (float)0)
        {
            array_code[i].p /= (float)count_of_symbols;
            size_array_of_code++;
        }
    }
}

void sort()
{
	encoding temp;
	for(int i = 0; i < 256; i++)
		for(int j = 255; j > i; j--)
		{
			if(array_code[j].p > array_code[j - 1].p)
			{
				temp = array_code[j];
				array_code[j] = array_code[j-1];
				array_code[j-1] = temp;
			}
		}
}

void encoding_gilbert_mur()
{
    float Q[size_array_of_code], sum = 0;
    char ch;
    Q[0] = array_code[0].p / 2; array_code[0].length = (int)ceilf(-log2f(array_code[0].p)) + 1;
    sum = array_code[0].p;
    for (int i = 1; i < size_array_of_code; i++)
    {
        Q[i] = sum + array_code[i].p / 2;
        array_code[i].length = (int)ceilf(-log2f(array_code[i].p)) + 1;
        sum += array_code[i].p;
    }
    for (int i = 0; i < size_array_of_code; i++)
    {
        for (int j = 0; j < array_code[i].length; j++)
        {
            Q[i] *= 2;
            int digit = (int)Q[i];
            if (digit == 0)
                ch = '0';
            if (digit == 1)
                ch = '1';
            array_code[i].code[j] = ch;
            if (Q[i] > 1)
                Q[i]--;
        }
    }
}

void print_code()
{
    cout << "Symbol      Chance          Code word          Length of code word\n" <<endl;
    for (int i = 0; i < size_array_of_code; i++)
    {
        printf("  %c  ", array_code[i].symbol);
        printf("        ");
        printf("%f", array_code[i].p);
        printf("        ");
        printf("%s\t\t", array_code[i].code);
        printf("        ");
        printf("%d\n", array_code[i].length);
    }
    float entropy = 0, average_length = 0;
    float wes = 0;
    for (int i = 0; i < size_array_of_code; i++)
    {
        average_length += array_code[i].length * array_code[i].p;
        entropy += array_code[i].p * -log2f(array_code[i].p);
    }
    wes = average_length * count_of_symbols;
    printf("\n\nAverage length of code word: %f\n", average_length);
    printf("Entropy of source file: %f\n", entropy);
    printf("Code mass: %.3f KB\n", wes/8/1024);
}

node* treeSearch(node *p, short int tree_key)
{
    short int house = p -> data -> flat;
	short int a = house - tree_key;
	if (p != NULL)
	{
		if(a > 0)
		{
			treeSearch(p -> left, tree_key);
		}
		if(a < 0)
		{
			treeSearch(p -> right, tree_key);
		}
		if(a == 0)
		{
			return p;
		}
	}
	else
    {
        cout <<"Not found"<< endl;
        system("PAUSE");
        return NULL;
    }
}

int main()
{
    spis *PArray[4000], *p;
    node *q = NULL;
    char *key;
    string str;
    int size = 4000;
    int i = 0, button, pos;
    short int tree_key;
    spis *mas[4000];
    read_file();
    MergeSort(head); //merge sort

    for(p = head, i = 0; p; p = p -> next, i++) //Points array
    {
        PArray[i] = p;
    }

    for(p = base_head, i = 0; p; p = p->next, i++)
    {
    	mas[i] = p;
	}
    open_file_base();
    sort();
    encoding_gilbert_mur();

    while(1)
    {
        system("cls");
        cout << "1. Main Base" << endl;
        cout << "2. Sorted Base" << endl;
        cout << "3. Binary Search" << endl;
        cout << "4. DBD-Tree" << endl;
        cout << "5. Base Coding" <<endl;
        cout << "0. Exit" << endl;
        cin >> button;
        system("cls");
        switch(button)
        {
        case 1:
            printmas(mas); //start base
            break;
        case 2:
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
        {
            if (search_head == NULL)
            {
                cout << "Make search first!" << endl;
            }
            else
            {
                for(p = search_head; p; p = p -> next)
                {
                    DBD(root, p -> data);
                }
                leftright_representation(root);
                cout << "What house would you like to find?" << endl;
                cin >> tree_key;
                node *q = treeSearch(root, tree_key);
                if(q != NULL)
                {
                    cout << q -> data -> name << "\t ";
                    cout << q -> data -> street << "\t ";
                    cout << q -> data -> house << "\t ";
                    cout << q -> data -> flat << "\t ";
                    cout << q -> data -> date << endl;
                    print_spis(q -> dbd_head);
                }
            }
            system("PAUSE");
        }
        break;
        case 5:
            print_code();
            system("PAUSE");
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
