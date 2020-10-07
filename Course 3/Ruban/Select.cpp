#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll select(ll n, ll *A)
{
    ll i, j, sr = 0, per = 0, temp;
    for(i = 0; i < n - 1; i++)
    {
        int jmin = i;
        for(j = i + 1; j < n; j++)
        {
            sr++;
            if(A[j] < A[jmin])
            {
                jmin = j;
            }
        }
        if(jmin != i)
        {
            per += 3;
            temp = A[i];
            A[i] = A[jmin];
            A[jmin] = temp;
        }
    }
    cout << "Sorted:";
    for(int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\nCompares: " << sr << " Changes: " << per;
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
    select(n, A);
    return 0;
}
