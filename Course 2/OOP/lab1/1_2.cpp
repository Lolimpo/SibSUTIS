#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n = 0, width = 0;
    printf("Print a number: ");
    scanf("%d", &n);
    printf("Print a max width of a array: ");
    scanf("%d", &width);
    int i = 0, j = 0;
    unsigned char **A = new unsigned char* [n];
    for (int temp = 0; temp < n; temp++)
    {
        A[temp] = new unsigned char [n];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 1; j++)
        {
            A[i][j] = rand() % width + 1;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < A[i][0]; j++)
        {
            A[i][j] = rand()%256;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < A[i][0]; j++)
        {
            printf("\t%5d", A[i][j]);
        }
        printf("\n");
    }
    for (int temp = 0; temp < n; temp++)
    {
        delete A[temp];
        A[temp] = NULL;
    }
    delete A;
    A = NULL;
    return 0;
}
