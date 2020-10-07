#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    list *next;
} *head, *tail;

void add_to_list(int data)
{
    list *p = (list*)malloc(sizeof(list));
    p -> data = data;
    p -> next = NULL;
    if(head == NULL)
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

void print_list()
{
    list *p;
    for(p = head; p; p = p -> next)
    {
        printf("%d ", p -> data);
    }
    puts("");
}

void delete_from_list(int element)
{
    list *p = head;
    list *temp;
    int i;
    for(i = 0; i < element - 1; i++)
    {
        p = p -> next;
    }
    if(i == 0)
    {
        temp = p;
        head = p -> next;
        free(temp);
    }
    temp = p -> next;
    p -> next = p -> next -> next;
    free(temp);
}

int main()
{
    add_to_list(16);
    add_to_list(64);
    add_to_list(128);
    add_to_list(256);
    print_list();
    delete_from_list(2);
    print_list();
    return 0;
}
