#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int O = -1;

ll ten(ll val)
{
    ll temp = 1;
    while(val)
    {
        temp *= 10;
        val--;
    }
    return temp;
}

ll count_size(ll num)
{
    ll n = 0;
    num = abs(num);
    while(num > 0)
    {
        n++;
        num /= 10;
    }
    return n;
}

void do_math(ll num1, ll num2)
{
    ll n, temp = 0, result = 0, znak = 1;
    n = count_size(num2);
    ll m = count_size(num1);
    ll *A = new ll[n];
    if(num1 < 0 && num2 < 0);
    else if(num1 < 0 || num2 < 0)
        znak *= -1;
    ll tempnum1 = num1;
    num1 = abs(num1), num2 = abs(num2);
    for(int i = 0; i < n; i++)
    {
        temp = num2 % 10;
        num2 /= 10;
        A[i] = num1 * temp;
        if(A[i] != 0 && tempnum1 % 10)
            O += n;
        tempnum1 /= 10;
        cout.width(20 - i); cout << right << A[i] << endl;
        result += A[i] * ten(i);
        if(A[i])
            O++;
    }
    cout << "-------------------" << endl;
    cout.width(20); cout << result * znak << endl;
}

int main()
{
    ll num1, num2, result;
    cout << "Enter first num:" << endl;
    cin >> num1;
    cout << "Enter second num:" << endl;
    cin >> num2;
    system("cls");
    cout.width(20); cout << right << num1 << endl;
    cout.width(20); cout << right <<num2 << endl;
    cout << "--------------------" << endl;
    do_math(num1, num2);
    cout << "Trudoemkost: " << O << endl;
    return 0;
}
