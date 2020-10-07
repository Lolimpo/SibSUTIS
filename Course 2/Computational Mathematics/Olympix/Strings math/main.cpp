#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int fill_zero(char symbol)
{
    return symbol - '0';
}

main()
{
    string bigger, smaller, result;
    int raz, sum, data = 0;
    string A;
    string B;
    cout << "Enter A:";
    cin >> A;
    cout << "Enter B:";
    cin >> B;
    if(A.size() >= B.size())
    {
        bigger = A;
        smaller = B;
    }
    else
    {
        bigger = B;
        smaller = A;
    }

    raz = abs(bigger.size() - smaller.size());
    //cout << raz << endl;
    smaller.insert(0, raz, '0');

    for(int i = bigger.size() - 1; i >= 0; i--)
    {
        sum = fill_zero(bigger[i]) + fill_zero(smaller[i]) + data;
        result += sum % 10 + '0';
        if(i == 0)
            result += to_string(sum);
        data = sum / 10;
    }
    reverse(result.begin()-1, result.end());
    cout << result << endl;
    return 0;
}
