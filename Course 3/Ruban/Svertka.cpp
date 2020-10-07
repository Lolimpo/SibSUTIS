#include <bits/stdc++.h>

using namespace std;

int O = 0;

void svertka(int n, int m)
{

    int *A = new int[n];
    int *B = new int[m];
    int *C = new int[n * m];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < m; i++)
        cin >> B[i];

    for(int i = 0; i < (n + m) - 1; i++)
    {
        C[i] = 0;
        for(int k = 0; k < n; k++)
        {
            for(int l = 0; l < m; l++)
            {
                if(k + l == i)
                {
                    C[i] += A[k] * B[l];
                    O += 2;
                }

            }
        }
    }
    cout << endl;
    for(int i = 0; i < (n + m) - 1; i++)
        cout << C[i] << endl;
    cout << "Difficulty: " << O << endl;
}

main()
{
    int n, m;
    cin >> n >> m;
    svertka(n, m);
    system("PAUSE");
    return 0;
}
