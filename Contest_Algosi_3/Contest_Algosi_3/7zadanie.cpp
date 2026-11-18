#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& graph, int start,
    vector<long long>& d, vector<int>& parent) {
    d[start] = 0;

    priority_queue<pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>> queue;

    queue.push({ d[start], start });

    while (queue.size() > 0) {
        long long dist = queue.top().first;
        int from_node = queue.top().second;
        queue.pop();

        if (dist > d[from_node]) {
            continue;
        }

        for (pair<int, int> rebro : graph[from_node]) {
            int to = rebro.first;
            int weight = rebro.second;

            long long new_dist = d[from_node] + weight;
            if (d[to] > new_dist) {
                d[to] = new_dist;
                parent[to] = from_node;
                queue.push({ d[to], to });
            }
        }
    }
}

int main() {

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    vector<long long> d(n + 1, (long long)1e18);
    vector<int> parent(n + 1, -1);

    dijkstra(graph, s, d, parent);

    if (d[t] == (long long)1e18) {
        cout << -1 << '\n';
        return 0;
    }

    vector<int> path;
    int v = t;

    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());

    cout << d[t] << '\n';
    cout << path.size() << '\n';
    for (int v : path) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}