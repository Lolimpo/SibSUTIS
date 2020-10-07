#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

typedef struct spis
{
	int data;
	spis *next;
} queue;
queue *head, *next, *p, *tail;

void add(spis *head, int a, int b)
{
	int i=1;
	queue  *k;
	for(p = head; p; p = p->next)
	{
		if(i == a)
		{
			k = new spis;
			k->data = b;
			k->next = p->next;
			p->next = k;
			return;
		}
		i++;
	}
	return;
}

void del( int a)
{
	int i=1;
	queue  *k;
	for(p = head; p; p = p->next)
	{
		if(a == 1)
		{
			k = head;
			head = head->next;
			delete(k);
			return;
		}
		if(i == a-1)
		{
			k = p->next;
			p->next = p->next->next;
			delete(k);
			return;
		}
		i++;
	}
}

int number(spis *head)
{
	int i=0;
	for (spis *p = head; p; p = p->next)
    {
    	i++;
	}	
	return(i);
}
void print(spis *head)
{
	for (spis *p = head; p; p = p->next)
    {
    	printf("%d ",p->data);
	}	
}

int main()
{
    unsigned char *squares_num_under_255 = new unsigned char [16];
    for (int i = 0; i < 16; i++)
    {
        squares_num_under_255[i] = i*i;
    }
    int n = 15;
    int a, b;
	tail = head = new spis;
	head->data = rand()%101;
	head -> next = 0;
	for (int i = 0; i < n-1; i++)
	{
		p = new spis;
		p -> data = rand()%101;
		p -> next = tail -> next;
		tail -> next = p;
		tail = p;
    }
	print(head);
	printf("\nPrint a and b");
	scanf("%d %d", &a, &b);
	add(head, a, b);
	printf("\n");
	print(head);
	printf("\n print k");
	scanf("%d", &a);
	del(a);
	print(head);
	printf("kol el=%d", number(head));
    return 0;
}
