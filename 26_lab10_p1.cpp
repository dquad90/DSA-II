#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cout << "Enter the cell size: ";
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    cout << "Enter the number of connected cells: ";
    cin >> m;
    cout << "Enter the cells: ";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
    int root;
    cout << "Enter the root: ";
    cin >> root;
    int visited[n] = {0};
    stack<int> s;
    s.push(root);
    visited[root] = 1;
    int destination;
    cout << "Enter the destination: ";
    cin >> destination;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        if (destination == current)
        {
            cout << "Yes" << endl;
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                s.push(i);
            }
        }
    }
    cout << "No" << endl;
    return 0;
}