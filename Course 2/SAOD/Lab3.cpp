#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node //звено дерева
{
    int data;
    node *left;
    node *right;
} *root;

int tree_depth(struct node *p)
{
    if(p == NULL) return 0;
    else return(1 + max(tree_depth(p->left), tree_depth(p->right)));
}

int tree_size(struct node *p)
{
    if(p == NULL) return 0;
    else return(1 + (tree_size(p->left) + tree_size(p->right)));
}

float tree_average_depth(struct node *p, int L)
{
    if(p == NULL) return 0;
    else return(L + tree_average_depth(p -> left, L+1) + tree_average_depth(p -> right, L+1));
}

int tree_sum(struct node *p)
{
    if (p == NULL) return 0;
    else return (p->data + tree_sum(p->left) + tree_sum(p->right));
}

void leftright_representation(struct node *p) //обход слева направо
{
    if (p == NULL) return;
    else
    {
        leftright_representation(p->left);
        printf("%d ", p->data);
        leftright_representation(p->right);
    }
}

node *SDP (node **root, int D)
{
    node **p = root;
    while ((*p) != NULL)
    {
        if (D < (*p) -> data)
        {
            p = &((*p) -> left);
        }
        else if (D > (*p) -> data)
        {
            p = &((*p) -> right);
        }
        else
        {
            return(*p);
        }
    }
    if ((*p) == NULL)
    {
        (*p) = new node;
        (*p) -> data = D;
        (*p) -> right= (*p) -> left = NULL;
    }
}

node *SDP_delete (int x, node *root)
{
    node **p = &root;
    node *q, *r, *s;
    while ((*p) != NULL)
    {
        if ((*p)->data > x)
        {
            p = &((*p) -> left);
        }
        else if ((*p) -> data < x)
        {
            p = &((*p) -> right);
        }
        else
        {
            break;
        }
    }
    if ((*p) != NULL)
    {
        q = (*p);
        if (q -> left == NULL)
        {
            (*p) = q -> right;
        }
        else if (q -> right == NULL)
        {
            (*p) = q -> left;
        }
        else
        {
            r = q -> left;
            s = q;
   			if(r->right = NULL)
        	{
        		r->right = q->right;
        		(*p) = r;
			}
			else 
			{
				while (r -> right != NULL)
        		{
            		s = r;
            		r = r -> right;
        		}
        		s -> right = r -> left;
        		r -> left = q -> left;
        		r -> right = q -> right;
        		(*p) = r;
			}
		}
		delete(q);
    }
}

int main()
{
    int n, *A, x;
    srand(time(NULL));
    /*
    printf ("Enter number of elements: ");
    scanf ("%d", &n);
    */
    n = 20;
    A = new int [n];
    for (int i = 0; i < n; i++) //заполняем
    {
    	A[i] = rand()%10;
    	printf("%d ",A[i]);
    	SDP(&root, A[i]);
	}
	int counter = 30;
	do
    {
        printf("Left-Right for SDP:\n");
        leftright_representation(root);
        printf("\nWhat element would you like to delete?");
        scanf ("%d", &x);
        SDP_delete (x, root);
        counter--;
    }while (counter > 0);
	return 0;
}
