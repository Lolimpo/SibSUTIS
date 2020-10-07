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
    int bal;
};
node *root1 = NULL;

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

node *LL (node *&p)
{
    node *q;
    q = p -> left;
    q -> bal = p -> bal = 0;
    p -> left = q -> right;
    q -> right = p;
    p = q;
}

node *RR (node *&p)
{
    node *q;
    q = p -> right;
    q -> bal = p -> bal = 0;
    p -> right = q -> left;
    q -> left = p;
    p = q;
}

node *LR (node *&p)
{
    node *q, *r;
    q = p -> left;
    r = q -> right;
    if (r -> bal < 0)
    {
        p -> bal = 1;
    }
    else
    {
        p -> bal = 0;
    }
    if (r -> bal > 0)
    {
        q -> bal = -1;
    }
    else
    {
        q -> bal = 0;
    }
    r -> bal = 0;
    q -> right = r -> left;
    p -> left = r -> right;
    r -> left = q;
    r -> right = p;
    p = r;
}

node *RL (node *&p)
{
    node *q, *r;
    q = p -> right;
    r = q -> left;
    if (r -> bal < 0)
    {
        q -> bal = 1;
    }
    else
    {
        q -> bal = 0;
    }
    if (r -> bal > 0)
    {
        p -> bal = -1;
    }
    else
    {
        p -> bal = 0;
    }
    r -> bal = 0;
    q -> left= r -> right;
    p -> right = r -> left;
    r -> right = q;
    r -> left = p;
    p = r;
}

bool Rost = false;

node *AVL (node *&p, int D)
{
if (p == NULL)
    {
        p = new node;
        p -> data = D;
        p -> left = p -> right = NULL;
        p -> bal = 0;
        Rost = true;
    }
    else
    {
        if (p -> data > D)
        {
            AVL(p -> left, D);
            if (Rost)
            {
                if (p -> bal > 0)
                {
                    p -> bal = 0;
                    Rost = false;
                }
				else
				{
                    if (p -> bal == 0)
                    {
                        p -> bal = -1;
                        Rost = true;
                    }
                    else
                    {
                        if (p -> left -> bal < 0)
                        {
                            LL(p);
                            Rost = false;
                        }
                        else
                        {
                            LR(p);
                            Rost = false;
                        }
                    }
                }
            }
        }
        else
        {
            if (p -> data < D)
            {
                AVL(p -> right, D);
                if (Rost)
                {
                    if (p -> bal < 0)
                    {
                        p -> bal = 0;
                        Rost = false;
                    }
				    else
				    {
                        if (p -> bal == 0)
                        {
                            p -> bal = 1;
                            Rost = true;
                        }
                        else
                        {
                            if (p -> right -> bal > 0)
                            {
                                RR(p);
                                Rost = false;
                            }
                            else
                            {
                                RL(p);
                                Rost = false;
                            }
                        }
                    }
                }
            }
            else
            {
                cout << "Puk";
            }
        }
    }
}

node *SDP (node **p, int D)
{
    while ((*p) != NULL)
    {
        if (D < (*p)->data)
        {
            p = &((*p)->left);
        }
        else if (D > (*p)->data)
        {
            p = &((*p)->right);
        }
        else
        {
            break;
        }
    }
    if ((*p) == NULL)
    {
        (*p) = new node;
        (*p)->data = D;
        (*p)->right= (*p)->left = NULL;
    }
}

int main()
{
    node *root2 = NULL;
    int n, *A, *B;
    srand(time(NULL));
    printf ("Enter number of elements: ");
    scanf ("%d", &n);
    A = new int [n];
    B = new int [n];
    for (int i = 0; i < n; i++) //заполняем
    {
    	A[i] = i + 1;
    	B[i] = i + 1;
    	AVL(root1, A[i]);
    	SDP(&root2, B[i]);
	}
    printf("Left-Right for AVL:\n");
    leftright_representation(root1);
    printf("\n");
    printf("+------------------------------------------------+\n");
    printf("+n=%d|  Size  |  Sum  |  Height  |  Av.Height  |\n",n);
    printf("+------------------------------------------------+\n");
    printf("+ SDP |%6d  |%5d  |%8d  |%11.2f  |\n",tree_size(root2), tree_sum(root2), tree_depth(root2), tree_average_depth(root2, 1) / tree_size(root2));
    printf("+ AVL |%6d  |%5d  |%8d  |%11.2f  |\n",tree_size(root1), tree_sum(root1), tree_depth(root1), tree_average_depth(root1, 1) / tree_size(root1));
    printf("+------------------------------------------------+\n");
    return 0;
}
