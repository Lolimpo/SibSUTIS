#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n = 4;
    int i = 0, j = 0;
    unsigned char **A = new unsigned char* [n];
    for (int temp = 0; temp < n; temp++)
    {
        A[temp] = new unsigned char [n];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = rand()%256;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("\t%5d", A[i][j]);
        }
        printf("\n");
    }
    int i1 = 0, i2, j2;
	j = n;
	i = 0;
    unsigned char *B = new unsigned char [n*n]; // правые диагонали
    do
    {
        j--;
		i2 = i;
		j2 = j;
		while(i2 < n && j2 < n)
		{
		  	B[i1] = A[i2][j2];
		  	i1++;
		  	i2++;
		  	j2++;
		}

	}while (j != 0);
	i++;
	do
    {
    	i2 = i;
		j2 = j;
	    while(i2 < n && j2 < n)
		{
		  	B[i1] = A[i2][j2];
		  	i1++;
		  	i2++;
		  	j2++;
		}
	    i++;
    }while(i < n);
	printf("\n");
	for (j = 0; j < n*n; j++)
    {
        printf("%5d ", B[j]);
    }


    unsigned char *D = new unsigned char [n*n]; // левые диагонали
    i1 = 0;
	j = -1;
	i = 0;
    do
    {
        j++;
		i2 = i;
		j2 = j;
		while(i2 < n && j2 >= 0)
		{
		  	D[i1] = A[i2][j2];
		  	i1++;
		  	i2++;
		  	j2--;
		}
	}while (j != n-1);
	i++;
	do
    {
    	i2 = i;
		j2 = j;
		i++;
	    while(i2 < n && j2 >= 0)
		{
		  	D[i1] = A[i2][j2];
		  	i1++;
		  	i2++;
		  	j2--;
		}
    }while(i < n);
    printf("\n");
	for (j = 0; j < n*n; j++)
    {
        printf("%5d ", D[j]);
    }
    unsigned char *E = new unsigned char [n*n];
    int center = n/2 - 1;
    i2 = center;
    j2 = center;
    i1 = 0;
    int step = 1;
    int counter = step;
    E[i1] = A[i2][j2];
    i1++;
    while(j2 >= 0)
	{
		while(counter > 0) // right
		{
			j2++;
			counter--;
			E[i1] = A[i2][j2];
			i1++;
		}
		counter = step;
		while(counter > 0) // down
		{
			i2++;
			counter--;
			E[i1] = A[i2][j2];
			i1++;
		}
		step++;
		counter = step;
		while((counter > 0) && (j2 >= 0)) // left
		{
			j2--;
			counter--;
			E[i1] = A[i2][j2];
			i1++;
		}
		if(!(j2 >= 0)) break;
		counter = step;
		while(counter > 0) // up
		{
			i2--;
			counter--;
			E[i1] = A[i2][j2];
			i1++;
		}
		step++;
		counter = step;
	}
	printf("\n");

	for (j = 0; j < n*n; j++)
    {
        printf("%5d ", E[j]);
    }

    unsigned char Z[n*n];
	i2 = 0;
	j2 = 0;
	i1 = 0;
    center = n/2 - 1;
    step = n - 1;
    counter = step;
	int step_1 = step;
	int begin = 0;
    Z[i1] = A[i2][j2];
    i1++;
    printf("\n");

    while(counter > 0) // warning! shitcode
	{
		j2++;
		Z[i1] = A[i2][j2];
		i1++;
		counter--;
	}
	counter = step;
	while(counter > 0)
	{
		i2++;
        Z[i1] = A[i2][j2];

        i1++;
        counter--;
	}
	counter = step;
	while(counter > 0)
	{
		j2--;
        Z[i1] = A[i2][j2];
        i1++;
        counter--;
	}
	step--;
	counter = step;


    while(!((i2 == center + 1) && (j2 == center)))
	{
        while((counter > 0) && (!((i2 == center + 1) && (j2 == center)))) // up
        {
            i2--;
            Z[i1] = A[i2][j2];
            i1++;
            counter--;
		}
		counter = step;


		while((counter > 0) && ((i2 != center + 1) || (j2 != center))) // right
        {
            j2++;
            Z[i1] = A[i2][j2];
            i1++;
            counter--;
        }
        step--;
		counter = step;

		while((counter > 0) && (!((i2 == center + 1) && (j2 == center)))) // down
        {
            i2++;
            Z[i1] = A[i2][j2];
            i1++;
            counter--;
        }
		counter = step;

		while((counter > 0) && (!((i2 == center + 1) && (j2 == center)))) // left
        {
            j2--;
            Z[i1] = A[i2][j2];
            i1++;
            counter--;
        }
        step--;
		counter = step;
	}
	for (j = 0; j < n*n; j++)
    {
        printf("%5d ", Z[j]);
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
