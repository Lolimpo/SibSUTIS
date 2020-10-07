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
};

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

node *ISDP (int L, int R, int *A )
{
    int m;
    node *p;
    if (L > R) return NULL;
    else
    {
        m = (L + R)/2;
        p = new node;
        p -> data = A[m];
        p -> left = ISDP (L, m-1, A);
        p -> right = ISDP (m+1, R, A);
        return p;
    }
}

node *SDP (node **root, int D)
{
    node **p = root;
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
    node *root1 = NULL;
    node *root2 = NULL;
    int n, *A, *B;
    srand(time(NULL));
    /*
    printf ("Enter number of elements: ");
    scanf ("%d", &n);
    */
    n = 100;
    A = new int [n];
    B = new int [n];
    for (int i = 0; i < n; i++) //заполняем
    {
    	A[i] = i + 1;
    	B[i] = rand()%101;
	}
    root1 = ISDP (0, n-1, A);
    for (int i = 0; i < n; i++)
    {
        SDP(&root2, B[i]);
    }
    printf("Left-Right for SDP:\n");
    leftright_representation(root2);
    printf("\n");
    printf("+------------------------------------------------+\n");
    printf("+n=%d |  Size  |  Sum  |  Height  |  Av.Height  |\n",n);
    printf("+------------------------------------------------+\n");
    printf("+ ISDP |%6d  |%5d  |%8d  |%11.2f  |\n",tree_size(root1), tree_sum(root1), tree_depth(root1), tree_average_depth(root1, 1) / tree_size(root1));
    printf("+ SDP  |%6d  |%5d  |%8d  |%11.2f  |\n",tree_size(root2), tree_sum(root2), tree_depth(root2), tree_average_depth(root2, 1) / tree_size(root2));
    printf("+------------------------------------------------+\n");
    return 0;
}
