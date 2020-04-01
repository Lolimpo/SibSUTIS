#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 99999;
using namespace std;

struct edge
{
    int a, b, cost;
};
vector<edge> e;

void solve(int n, int m)
{
    int start, finish;
    cout << "Enter starting point: " << endl;
    cin >> start;
    start--;
    system("cls");
    vector<int> D (n, INF);
    D[start] = 0;
    vector<int> p (n, -1);
    for(;;)
    {
        bool any = false;
        for(int j = 0; j < m; ++j)
            if(D[e[j].a] < INF)
                if(D[e[j].b] > D[e[j].a] + e[j].cost)
                {
                    for(int i = 0; i < n; i++)
                        cout << D[i] << ' ';
                    cout << endl;
                    D[e[j].b] = D[e[j].a] + e[j].cost;
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if(!any)
            break;
    }
    cout << "D:" << endl;
    for(int i = 0; i < n; i++)
        cout << D[i] << ' ';
    cout << endl;
    /*cout << "Enter finish point: " << endl;
    cin >> finish;
    finish--;
    */
    for(int j = 0; j < n; j++)
    {
        vector<int> path;
        for(int cur = j; cur != -1; cur = p[cur])
            path.push_back(cur);
        reverse(path.begin(), path.end());
        if(start != j)
        {
            if(path.size() > 1){
                cout << "Path from " << start + 1 << " to " << j+1 << ": " << endl;
                for(auto i: path)
                    cout << i+1 << ' ';
                cout << endl;
            }
            
        }
    }
}

int main()
{
    int n, m = 0;
    cout << "Enter size: ";
    cin >> n;
    vector<vector<int>> C(n, vector<int>(n, INF));

    cout << "Enter graph:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> C[i][j];
            if(C[i][j])
            {
                e.push_back({i, j, C[i][j]});
                m++;
            }
        }
    }
    /*for(auto i: e)
        cout << i.a << ' ' << i.b << ' ' << i.cost << endl;*/
    solve(n, m);
    return 0;
    //0 1 0 0 11 8 0 15 0 12 0 0 0 0 0 0 0 6 1 0 0 0 0 0 0 9 0 7 0 13 2 0 0 0 3 7 0 0 0 4 0 0 0 0 6 17 0 5 0
    /*0 1 99999 1 99999 6 99999
    1 0 1 1 1 99999 99999
    99999 1 0 99999 2 99999 3
    1 1 99999 0 2 5 99999
    99999 1 2 2 0 4 2
    6 99999 99999 5 4 0 1
    99999 99999 3 99999 2 1 0*/
}
