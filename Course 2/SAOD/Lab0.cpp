#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node // звено дерева
{
    int data;
    node *left;
    node *right;
};

struct node *new_node(int data)
{
    struct node *node = new(struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

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

void leftright_representation(struct node *p)
{
    if (p == NULL) return;
    else
    {
        leftright_representation(p->left);
        printf("%d ", p->data);
        leftright_representation(p->right);
    }
}

void updown_representation(struct node *p)
{
    if (p == NULL) return;
    else
    {
    	printf("%d ", p->data);
        leftright_representation(p->left);
        leftright_representation(p->right);
    }
}

void downup_representation(struct node *p)
{
    if (p == NULL) return;
    else
    {
        leftright_representation(p->left);
        leftright_representation(p->right);
        printf("%d ", p->data);
    }
}

int main()
{
    srand(time(NULL));
    struct node *root = new_node(1);
    root->left = new_node(2);
    root->left->left = new_node(3);
    root->left->right = new_node(4);
    root->right = new_node(5);
    root->right->right = new_node(6);
    printf("Depth of a binary tree: %d\n", tree_depth(root));
    printf("Size of a binary tree: %d\n", tree_size(root));
    printf("Average depth: %.2f \n", tree_average_depth(root, 1) / tree_size(root));
    printf("Sum: %d\n", tree_sum(root));
    printf("leftright\n");
    leftright_representation(root);

    printf("\nupdown\n");
    updown_representation(root);

    printf("\ndownup\n");
    downup_representation(root);
    return 0;
}
