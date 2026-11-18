#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int v, int p, vector<vector<int> >& graph, vector<int>& visited,
    vector<int>& parent, int& cycle_start, int& cycle_end) {
    visited[v] = 1;

    for (int to : graph[v]) {
        if (to == p) {
            continue;
        }

        if (visited[to] == 0) {
            parent[to] = v;
            if (dfs(to, v, graph, visited, parent, cycle_start, cycle_end)) {
                return true;
            }
        }
        else if (visited[to] == 1) {
            cycle_start = to;
            cycle_end = v;
            return true;
        }
    }

    visited[v] = 2;
    return false;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int cycle_start = -1;
    int cycle_end = -1;

    for (int v = 1; v <= n; ++v) {
        if (visited[v] == 0) {
            if (dfs(v, -1, graph, visited, parent, cycle_start, cycle_end)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << 0 << '\n';
    }
    else {
        vector<int> cycle;

        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v]) {
            cycle.push_back(v);
        }

        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << '\n';
        for (int v : cycle) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}