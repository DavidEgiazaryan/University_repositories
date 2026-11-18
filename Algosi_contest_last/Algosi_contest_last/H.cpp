#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int to;
    long long a, p, w;
};

int main() {

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> g(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long a, p, w;
        cin >> u >> v >> a >> p >> w;

        g[u].push_back({ v, a, p, w });
    }

    vector<long long> d(n + 1, INF);
    vector<int> parent(n + 1, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    d[s] = 0;
    pq.push({ 0, s });

    while (!pq.empty())
    {
        long long cur = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (cur != d[v])
        {
            continue;
        }

        for (Edge edge : g[v])
        {
            long long ost = d[v] % edge.p;
            long long wait = (edge.a - ost + edge.p) % edge.p;

            if (d[edge.to] > d[v] + wait + edge.w)
            {
                d[edge.to] = d[v] + wait + edge.w;
                parent[edge.to] = v;
                pq.push({ d[edge.to], edge.to });
            }
        }
    }

    if (d[t] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << d[t] << endl;
    }

    return 0;
}