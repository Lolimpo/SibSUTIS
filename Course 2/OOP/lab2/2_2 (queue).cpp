#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct spis
{
	int data;
	spis *next;
} queue;
queue *head, *p, *tail, *temp;

void FillRand(int n)
{
	srand( time(NULL) );
	tail = head = new spis;
	head -> next = 0;
	for (int i = 0; i < n; i++)
	{
		p = new spis;
		p -> data = rand()%101;
		p -> next = tail -> next;
		tail -> next = p;
		tail = p;
	}
}

void FillInc(int n)
{
	srand( time(NULL) );
	tail = head = new spis;
	head -> next = 0;
	for (int i = 0; i < n; i++)
	{
		p = new spis;
		p -> data = i + 1;
		p -> next = tail -> next;
		tail -> next = p;
		tail = p;
	}
}

void PrintQueue()
{
    for (p = head -> next; p; p = p -> next) printf("%d ", p -> data);
}

void DeleteQueue()
{
	temp = p = head;
	while (p != NULL)
	{
		p = temp -> next;
		delete(temp);
		temp = p;
	}
	head = NULL;
}

int main()
{
	int n;
	printf("Length: ");
	scanf("%d", &n);
	printf("\n");
	FillInc(n);
	PrintQueue();
	DeleteQueue();
	printf("\n\nQueue deleted.");
	//PrintQueue();
	return 0;
}


