//#include <iostream>
//#include <vector>
//#include <queue>
//#include <map>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> dx = { 0, 0, 1, -1 };
//vector<int> dy = { 1, -1, 0, 0 };
//
//void bfs(vector<string>& m, pair<int, int> start, pair<int, int> finish) {
//    int n = m.size();
//    int w = m[0].size();
//
//    vector<vector<bool>> visited(n, vector<bool>(w));
//    map<pair<int, int>, pair<int, int>> prev;
//    queue<pair<int, int>> queue;
//    queue.push(start);
//    prev[start] = { -1, -1 };
//    visited[start.first][start.second] = true;
//
//    while (!queue.empty()) {
//        auto c = queue.front();
//        queue.pop();
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = c.first + dx[i];
//            int ny = c.second + dy[i];
//
//            if (nx < 0 || ny < 0 || nx >= n || ny >= w || visited[nx][ny] || m[nx][ny] == '#')
//                continue;
//
//            visited[nx][ny] = true;
//            queue.push({ nx, ny });
//            prev[{nx, ny}] = c;
//        }
//    }
//
//    if (!visited[finish.first][finish.second]) {
//        cout << -1;
//        return;
//    }
//
//    string path;
//    pair<int, int> cur = finish;
//
//    while (cur != start) {
//        pair<int, int> p = prev[cur];
//
//        if (cur.first == p.first && cur.second == p.second + 1) path.push_back('R');
//        else if (cur.first == p.first && cur.second == p.second - 1) path.push_back('L');
//        else if (cur.first == p.first + 1 && cur.second == p.second) path.push_back('D');
//        else if (cur.first == p.first - 1 && cur.second == p.second) path.push_back('U');
//
//        cur = p;
//    }
//
//    reverse(path.begin(), path.end());
//
//    cout << path.size() << '\n';
//    cout << path << '\n';
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    vector<string> a(n);
//    pair<int, int> start, finish;
//
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        for (int j = 0; j < m; ++j) {
//            if (a[i][j] == 'S') start = { i, j };
//            if (a[i][j] == 'T') finish = { i, j };
//        }
//    }
//
//    bfs(a, start, finish);
//}