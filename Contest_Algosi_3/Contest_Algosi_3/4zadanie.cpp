#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(int from, vector<vector<int> >& graph, vector<int>& colors,
    vector<int>& parent, vector<int>& depth,
    int color, int& cycle_start, int& cycle_end) {
    colors[from] = color;

    for (int to : graph[from]) {
        if (to == parent[from]) {
            continue;
        }

        if (colors[to] == -1) {
            parent[to] = from;
            depth[to] = depth[from] + 1;

            if (!dfs(to, graph, colors, parent, depth, color ^ 1, cycle_start, cycle_end)) {
                return false;
            }
        }
        else {
            if (colors[to] == color) {
                cycle_start = from;
                cycle_end = to;
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> colors(n + 1, -1);
    vector<int> parent(n + 1, -1);
    vector<int> depth(n + 1, 0);

    int cycle_start = -1;
    int cycle_end = -1;

    bool ok = true;

    for (int v = 1; v <= n; v++) {
        if (colors[v] == -1) {
            if (!dfs(v, graph, colors, parent, depth, 0, cycle_start, cycle_end)) {
                ok = false;
                break;
            }
        }
    }

    if (ok) {
        cout << "YES\n";
        for (int v = 1; v <= n; v++) {
            cout << colors[v] + 1 << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";

        vector<int> path1;
        vector<int> path2;

        int v = cycle_start;
        int u = cycle_end;

        while (depth[v] > depth[u]) {
            path1.push_back(v);
            v = parent[v];
        }

        while (depth[u] > depth[v]) {
            path2.push_back(u);
            u = parent[u];
        }

        while (v != u) {
            path1.push_back(v);
            path2.push_back(u);
            v = parent[v];
            u = parent[u];
        }

        path1.push_back(v);

        reverse(path2.begin(), path2.end());

        vector<int> cycle;

        for (int x : path1) {
            cycle.push_back(x);
        }
        for (int x : path2) {
            cycle.push_back(x);
        }

        cout << cycle.size() << '\n';
        for (int x : cycle) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}