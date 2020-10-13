#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

double exp_(double x, double eps)
{
    double s = 1, n = 1, a = 1;
    while(1)
    {
        a *= x / n;
        if(fabs(a) <= eps)
            break;
        s += a;
        n++;
    }
    return s;
}

main()
{
    double x;
    while(1)
    {
        cin >> x;
        int startMs = GetTickCount();
        cout << "exp(" << x << ")" << exp_(x, 1e-14) << endl;
        int endMs = GetTickCount();
        cout << fixed;
        cout << "Time by GetTickCount(): " << endMs - startMs << endl;
    }
    return 0;
}
