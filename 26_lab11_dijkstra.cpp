#include <bits/stdc++.h>
using namespace std;
int main() {
    int vertex, edge; 
    cin >> vertex >> edge;
    vector<pair<int,int>> graph[vertex];
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w; 
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w)); 
    }
    int s=0;
    int d[vertex];
    for (int i = 0; i < vertex; i++) {
        d[i] = INT_MAX; 
    }
    d[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int dist_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();
     if (dist_u > d[u]) continue; 
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int,int> edge = graph[u][i];
            int v = edge.first;
            int cost = edge.second;
            if (d[u] + cost < d[v]) {
                d[v] = d[u] + cost;
                pq.push(make_pair(d[v], v));
            }
        }
    }
    cout << "Distances from node; " << s << ":\n";
    for (int i = 0; i < vertex; i++) {
        if (d[i] == INT_MAX)
            cout << "Node" << i << ": INF\n";
        else
            cout << i << ": " << d[i] << "\n";
    }
    return 0;
}
