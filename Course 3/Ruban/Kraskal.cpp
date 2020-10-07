#include <bits/stdc++.h>
#define n 7
using namespace std;

int parent[n];

int find_v(int i)
{
    while(parent[i] != i)
        i = parent[i];
    return i;
}

int union1(int i, int j)
{
    int a = find_v(i);
    int b = find_v(j);
    parent[a] = b;
}

void solve(int cost[][n])
{
    int mincost = 0;
    for(int i = 0; i < n; i++)
        parent[i] = i;
    int edge_count = 0;
    while(edge_count < n - 1)
    {
        int mini = INT_MAX, a = -1, b = -1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(find_v(i) != find_v(j) && cost[i][j] < mini)
                {
                    mini = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        cout << "Edge " << edge_count++ << ": (" << a << ' ' << b << ") cost: " << mini << endl;
        mincost += mini;
    }
    cout << "Minimal cost: " << mincost << endl;
}

int main()
{
    int m = 0;
    //cout << "Enter size: ";
    //cin >> n;
    int C[n][n];
    cout << "Enter graph:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> C[i][j];
        }
    }
    solve(C);
    /*for(auto i: e)
        cout << i.a << ' ' << i.b << ' ' << i.cost << endl;*/
    return 0;
    //9999 1 99999 9999 11 8 9999 15 9999 12 9999 9999 9999 9999 9999 9999 9999 6 1 9999 9999 9999 9999 9999 9999 9 9999 7 99999 13 2 9999 9999 9999 3 7 9999 9999 9999 4 99999 9999 9999 9999 6 17 9999 5 9999
    /*0 1 99999 1 99999 6 99999
    1 0 1 1 1 99999 99999
    99999 1 0 99999 2 99999 3
    1 1 99999 0 2 5 99999
    99999 1 2 2 0 4 2
    6 99999 99999 5 4 0 1
    99999 99999 3 99999 2 1 0*/
}
