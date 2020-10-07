#include <bits/stdc++.h>

using namespace std;

void PrintBrackets(int i, int j, int n, int *bracket, char &name) 
{ 
    if (i == j) 
    { 
        cout << name++; 
        return; 
    } 
    cout << "("; 
    PrintBrackets(i, *((bracket+i*n)+j), n, bracket, name);  
    PrintBrackets(*((bracket+i*n)+j) + 1, j, n, bracket, name); 
    cout << ")"; 
} 

void MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int bracket[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            m[i][j] = 0;
    for(int L = 2; L < n; L++)
    {
        for(int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT32_MAX;
            for(int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    bracket[i][j] = k; 
                }
            }
        }
    }
    cout << "Matrix of multiplications:" << endl;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)  
        {
            if(m[i][j] > 0)
                cout << m[i][j] << '\t';
            else
                cout << 0 << '\t';    
        }
        cout << endl;
    }
    cout << "Optimal brackets placement:" << endl;
    char name = 'A';
    PrintBrackets(1, n - 1, n, (int *)bracket, name);
}

int main()
{
    int n;
    cout << "Enter number of matrix" << endl;
    cin >> n;
    int A[n+1];
    //int A[] = {100, 20, 70, 10, 90};
    cout << "Enter matrix sizes:" << endl;
    for(int i = 0; i <= n; i++)
        cin >> A[i];
    n = sizeof(A) / sizeof(A[0]);
    MatrixChainOrder(A, n);
    return 0;
}