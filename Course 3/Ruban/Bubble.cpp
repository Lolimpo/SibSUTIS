#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool sorted(ll n, ll *A)
{
    for(int i = 0; i < n - 1; i++)
        if(A[i] > A[i + 1])
            return 0;
    return 1;
}

ll bubble(ll n, ll *A)
{
    ll temp, ch = 0, sr = 0;
    if(sorted(n, A))
    {
        cout << "\nMassive sorted! \nCompares: " << n-1 << " Changes: " << ch;
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
    {
       for(int j = 0; j < n - i - 1; j++)
       {
           sr++;
           if(A[j] > A[j + 1])
           {
               temp = A[j];
               A[j] = A[j + 1];
               A[j + 1] = temp;
               ch += 3;
           }
       }
    }
    cout << "\nSorted bubble:";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\nChanges: " << ch << " Compares: " << sr << endl;
    return 0;
}

int main()
{
    ll n;
    cin >> n;
    ll A[n];
    for(int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Base:";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    bubble(n, A);
    return 0;
}
