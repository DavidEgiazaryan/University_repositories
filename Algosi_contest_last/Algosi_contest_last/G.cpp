#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<long long> d(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    vector<vector<int>> g(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        indeg[v] += 1;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<long long> dp(n + 1, 0);
    vector<int> parent(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = d[i];
    }

    int used = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        used += 1;

        for (int to : g[v])
        {
            long long new_time = dp[v] + d[to];

            if (new_time > dp[to])
            {
                dp[to] = new_time;
                parent[to] = v;
            }
            else if (new_time == dp[to] and (parent[to] == -1 or v < parent[to]))
            {
                parent[to] = v;
            }

            indeg[to] -= 1;

            if (indeg[to] == 0)
            {
                q.push(to);
            }
        }
    }

    if (used < n)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int finish = 1;

    for (int i = 2; i <= n; i++)
    {
        if (dp[i] > dp[finish])
        {
            finish = i;
        }
        else if (dp[i] == dp[finish] and i < finish)
        {
            finish = i;
        }
    }

    vector<int> path;

    int cur = finish;

    while (cur != -1)
    {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << dp[finish] << endl;
    cout << path.size() << endl;

    for (int v : path)
    {
        cout << v << ' ';
    }

    cout << endl;

    return 0;
}