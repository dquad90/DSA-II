#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertices, edges;
    cout << "Enter vertices: ";
    cin >> vertices;
    cout << "Enter edges: ";
    cin >> edges;
    vector<vector<int>> adj(vertices);
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    int source;
    cout << "Enter source: ";
    cin >> source;
    vector<int> cost(vertices, -1);
    queue<int> q;
    cost[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent]) {
            if (cost[child] == -1) {
                cost[child] = cost[parent] + 1;
                q.push(child);
            }
        }
    }
    cout << "Cost from source as list:\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i << ": " << cost[i] << endl;
    }
    return 0;
}
