#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) meaning u → v:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int neighbor = adj[i][j];
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    if (topo.size() != n) {
        cout << "Graph has a cycle, topo sort not possible.\n";
    } else {
        cout << "Topological Order (BFS): ";
        for (int i = 0; i < topo.size(); i++) {
            cout << topo[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

