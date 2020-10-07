#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of villages:" << endl;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int> (n));
    vector<bool>path;
    cout << "Enter villages matrix:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

}