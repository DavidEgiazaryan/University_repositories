//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//void bfs(vector<vector<int>>& graph, int start) {
//    int n = graph.size() - 1;
//    vector<bool> visited(n + 1, false);
//    vector<int> dist(n + 1, -1);
//    queue<int> queue;
//
//    queue.push(start);
//    visited[start] = true;
//    dist[start] = 0;
//
//    while (!queue.empty()) {
//        int v = queue.front();
//        queue.pop();
//
//        for (int to : graph[v]) {
//            if (visited[to]) continue;
//            visited[to] = true;
//            dist[to] = dist[v] + 1;
//            queue.push(to);
//        }
//    }
//
//    for (int i = 1; i <= n; ++i) {
//        cout << dist[i] << ' ';
//    }
//}
//
//int main() {
//
//    int n, m;
//    cin >> n >> m;
//
//    vector<vector<int>> graph(n + 1);
//
//    for (int i = 0; i < m; ++i) {
//        int u, v;
//        cin >> u >> v;
//        graph[u].push_back(v);
//        graph[v].push_back(u);
//    }
//
//    bfs(graph, 1);
//
//    return 0;
//}