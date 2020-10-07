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

int main()
{
    node *root = NULL;
    int n, *A;
    srand(time(NULL));

    printf ("Enter number of elements: ");
    scanf ("%d", &n);
    A = new int [n];    
    for (int i = 0; i < n; i++)
    {
    	A[i] = i + 1;
    	printf("%d ", A[i]);
	}
	
    root = ISDP (0, n-1, A);

    printf("Depth of a binary tree: %d\n", tree_depth(root));
    printf("Size of a binary tree: %d\n", tree_size(root));
    printf("Average depth: %.2f \n", tree_average_depth(root, 1) / tree_size(root));
    printf("Sum: %d\n", tree_sum(root));
    printf("leftright\n");
    leftright_representation(root);

    return 0;
}
