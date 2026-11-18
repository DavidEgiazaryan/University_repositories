#include <bits/stdc++.h>




using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<ll> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        topo.push_back(v);

        for (int to : g[v]) {
            indeg[to]--;

            if (indeg[to] == 0) {
                q.push(to);
            }
        }
    }

    if ((int)topo.size() != n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<ll> dp(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = d[i];
    }

    for (int v : topo) {
        for (int to : g[v]) {
            ll candidate = dp[v] + d[to];

            if (candidate > dp[to]) {
                dp[to] = candidate;
                parent[to] = v;
            }
            else if (candidate == dp[to]) {
                if (parent[to] == 0 || v < parent[to]) {
                    parent[to] = v;
                }
            }
        }
    }

    int finish = 1;

    for (int i = 2; i <= n; i++) {
        if (dp[i] > dp[finish]) {
            finish = i;
        }
        else if (dp[i] == dp[finish] && i < finish) {
            finish = i;
        }
    }

    vector<int> path;

    int cur = finish;
    while (cur != 0) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << dp[finish] << '\n';
    cout << path.size() << '\n';

    for (int v : path) {
        cout << v << ' ';
    }

    cout << '\n';

    return 0;
}