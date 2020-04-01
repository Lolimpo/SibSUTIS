#include <bits/stdc++.h> 

using namespace std; 

const int N = 7; 
int final_path[N+1]; 
bool visited[N]; 
int path_cost = INT_MAX; 
int O = 0;

void copyToFinal(int curr_path[]) 
{ 
    for (int i=0; i<N; i++) 
        final_path[i] = curr_path[i]; 
    final_path[N] = curr_path[0]; 
} 
  
int firstMin(int matrix[N][N], int i) 
{ 
    int min = INT_MAX; 
    for (int k=0; k<N; k++) 
        if (matrix[i][k] < min && i != k) 
            min = matrix[i][k]; 
    return min; 
} 
  
int secondMin(int matrix[N][N], int i) 
{ 
    int first = INT_MAX, second = INT_MAX; 
    for (int j = 0; j < N; j++) 
    { 
        if (i == j) 
            continue; 
  
        if (matrix[i][j] <= first) 
        { 
            second = first; 
            first = matrix[i][j]; 
        } 
        else if (matrix[i][j] <= second && matrix[i][j] != first) 
            second = matrix[i][j]; 
    } 
    return second; 
} 

void TSPRec(int matrix[N][N], int curr_bound, int curr_weight,  int level, int curr_path[]) 
{ 
    if (level == N) 
    { 
        if (matrix[curr_path[level-1]][curr_path[0]] != 0) 
        { 
            int curr_res = curr_weight + matrix[curr_path[level-1]][curr_path[0]]; 
            //O++;
            if (curr_res < path_cost) 
            { 
                copyToFinal(curr_path); 
                path_cost = curr_res; 
            } 
        } 
        return; 
    } 

    for (int i = 0; i < N; i++) 
    {
        if (matrix[curr_path[level - 1]][i] != 0 && visited[i] == false) 
        { 
            int temp = curr_bound; 
            curr_weight += matrix[curr_path[level - 1]][i]; 
            //O++;
            if(level == 1) 
              curr_bound -= ((firstMin(matrix, curr_path[level-1]) + firstMin(matrix, i))/2); 
            else
              curr_bound -= ((secondMin(matrix, curr_path[level-1]) + firstMin(matrix, i))/2); 

            if(curr_bound + curr_weight < path_cost) 
            { 
                O++;
                curr_path[level] = i; 
                visited[i] = true; 
                TSPRec(matrix, curr_bound, curr_weight, level + 1, curr_path); 
            } 
            curr_weight -= matrix[curr_path[level - 1]][i]; 
            curr_bound = temp; 
            memset(visited, false, sizeof(visited)); 
            for (int j = 0; j <= level - 1; j++) 
            {
                visited[curr_path[j]] = true; 
            }
        } 
    } 
} 
  
void TSP(int matrix[N][N]) 
{ 
    int curr_path[N+1]; 
    int curr_bound = 0; 
    memset(curr_path, -1, sizeof(curr_path)); 
    memset(visited, 0, sizeof(curr_path)); 
  
    for (int i = 0; i < N; i++) 
    {
        curr_bound += (firstMin(matrix, i) + secondMin(matrix, i)); 
    }
    
    curr_bound = (curr_bound & 1)? curr_bound/2 + 1 : curr_bound/2; 

    visited[0] = true; 
    curr_path[0] = 0; 

    TSPRec(matrix, curr_bound, 0, 1, curr_path); 
} 
  
int main() 
{ 
    int matrix[N][N];
    cout << "Enter villages matrix: " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    TSP(matrix); 
    if(path_cost != INT_MAX)
    {
        cout << "Minimal cost: " << path_cost << endl;
        cout << "Path of jorney:" << endl; 
        for (int i = 0; i <= N; i++)  
        {
            if(i != N)
                cout << final_path[i] << " -> ";
            else
            {
                cout << final_path[i] << endl;
            }
        
        } 
        cout << "Difficulty: " << O << endl;
    }
    else
    {
        cout << "Couldn't go through all villages." << endl;
    } 
    return 0; 
} 
/*
0 1 0 1 0 6 0
1 0 1 1 1 0 0
0 1 0 0 2 0 3
1 1 0 0 2 5 0
0 1 2 2 0 4 2
6 0 0 5 4 0 1
0 0 3 0 2 1 0
*/
/*
0 3 3 1 0 0
3 0 4 0 5 0
3 4 0 2 1 0
1 0 2 0 0 5
0 5 1 0 0 3
0 0 0 5 3 0
*/