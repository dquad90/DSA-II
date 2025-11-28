#include <bits/stdc++.h>
using namespace std;

int main() {
    int vertex, edge;
    cin >> vertex >> edge;
    vector<pair<int, int>> graph[vertex];
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > Q;
    vector<bool> visited(vertex, false);
    vector<tuple<int, int, int>> mst_edges; 
    int min_cost = 0;
    int start_node = 0;

    Q.push(make_pair(0, make_pair(-1, start_node))); 

    while (!Q.empty()) {
        pair<int, pair<int, int>> p = Q.top();
        Q.pop();

        int weight = p.first;
        int from = p.second.first;
        int to = p.second.second;

        if (visited[to])
            continue;

        visited[to] = true;
        min_cost += weight;
        if (from != -1)
            mst_edges.push_back(make_tuple(from, to, weight));
        for (int i = 0; i < (int)graph[to].size(); i++) {
            int next = graph[to][i].first;
            int w = graph[to][i].second;
            if (!visited[next]) {
                Q.push(make_pair(w, make_pair(to, next)));
            }
        }
    }

    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (int i = 0; i < (int)mst_edges.size(); i++) {
        int u = get<0>(mst_edges[i]);
        int v = get<1>(mst_edges[i]);
        int w = get<2>(mst_edges[i]);
        cout << u << " -> " << v << " (weight " << w << ")\n";
    }
    cout << "\nTotal Minimum Cost: " << min_cost << endl;
    return 0;
}


