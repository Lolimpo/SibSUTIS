#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cout << "Enter number of vertex:";
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    cout << "Enter matrix";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    vector <int> d(n, INT32_MAX), p(n, -1);
    vector <bool> used(n);
    int start, finish, mn, u;
    cout << "Enter starting point:";
    cin >> start;
    d[start] = 0;
    for (int i = 0; i < n; i++)
    {
        mn = INT32_MAX, u = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && d[j] < mn)
                mn = d[j], u = j;
        used[u] = true;
        for (int j = 0; j < n; j++)
            if (d[j] > d[u] + g[u][j] && g[u][j] > 0)
                d[j] = d[u] + g[u][j], p[j] = u;
    }
    cout << "Distance to all vertexes from " << start << endl;
    for(auto i: d)
        cout << i << ' ';
    cout << endl;
    for(int finish = 0; finish < n; finish++){
        vector <int> v;
        cout << "Path from " << start << " to " << finish << " is ";
        if (p[finish] == -1)
            cout << "empty" << endl;
        else{
            for (int u = finish; u != -1; u = p[u])
                v.push_back(u);
            reverse(v.begin(), v.end());
            for (int i=0;i<v.size();++i)
            {
                if (i > 0) cout << " -> ";
                cout<<v[i];
            }
            cout << endl;
        }
    }
    return 0;
}
/*
0 7 9999 9999 2 9999 1 9999
7 0 2 9999 9999 9999 9999 9999
9999 2 0 4 4 9999 9999 2
9999 9999 4 0 9999 10 2 1
2 9999 4 9999 0 9999 10 1
9999 9999 9999 10 9999 0 1 1
1 9999 9999 2 10 1 0 4
9999 9999 2 1 1 1 4 0
*/