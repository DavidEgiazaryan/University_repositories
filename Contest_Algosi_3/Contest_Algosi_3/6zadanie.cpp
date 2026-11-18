//#include <iostream>
//#include <vector>
//#include <deque>
//
//using namespace std;
//
//void bfs(vector<vector<pair<int, int>>>& graph, int start, int finish) {
//    int n = graph.size() - 1;
//    vector<int> dist(n + 1, 1e9);
//    deque<int> queue;
//
//    queue.push_front(start);
//    dist[start] = 0;
//
//    while (!queue.empty()) {
//        int v = queue.front();
//        queue.pop_front();
//
//        for (auto rebro : graph[v]) {
//            int to = rebro.first;
//            int cost = rebro.second;
//
//            if (dist[to] > dist[v] + cost) {
//                dist[to] = dist[v] + cost;
//
//                if (cost == 0) {
//                    queue.push_front(to);
//                }
//                else {
//                    queue.push_back(to);
//                }
//            }
//        }
//    }
//
//    if (dist[finish] == 1e9) {
//        cout << -1;
//    }
//    else {
//        cout << dist[finish];
//    }
//}
//
//int main() {
//    int n, m, s, t;
//    cin >> n >> m >> s >> t;
//
//    vector<vector<pair<int, int>>> graph(n + 1);
//
//    for (int i = 0; i < m; ++i) {
//        int u, v, c;
//        cin >> u >> v >> c;
//        graph[u].push_back({ v, c });
//    }
//
//    bfs(graph, s, t);
//
//    return 0;
//}