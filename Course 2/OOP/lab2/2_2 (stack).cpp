#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct spis
{
	int data;
    spis *next;
} stack;

spis * FillInc(int n)
{
	stack *p, *next, *head;
	head = new spis;
	head -> next = 0;
	for (int i = 0; i < n; i++ )
	{
		p = new spis;
    	p -> data = i + 1;
		p -> next = head -> next;
		head -> next = p;
	}
	return head;
}

spis * FillRand(int n)
{
	stack *p, *next, *head;
	srand( time(NULL) );
	head = p = new spis;
	head -> next = 0;
    for ( int i = 0; i < n; i++ )
    {
    	p = new spis;
    	p -> data = rand()%101;
		p -> next = head -> next;
		head -> next = p;
    }
    return head;
}

void PrintStack(stack *head)
{
	stack *p, *next;
    for (p = head -> next; p; p = p -> next) printf("%d ", p -> data);
}

void DeleteStack(stack *head)
{
	stack *p, *next, *t;
	for (p = head; p; p = t)
	{
		t = p -> next;
		delete (p);
	}
}

int main()
{
	stack *head;
	printf("Length: ");
	int n;
	scanf("%d", &n);
	printf("\n");
	head = FillInc(n);
	PrintStack(head);
	DeleteStack(head);
	printf("\n\nStack deleted.");
	return 0;
}
