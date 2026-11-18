#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 1000000000;

int n;
string a, b;
vector<vector<vector<int>>> dp;

int add_cost(int x, int y) {
    if (x >= INF || y >= INF) {
        return INF;
    }
    return x + y;
}

int solve(int level, int i, int j) {
    int& answer = dp[level][i][j];

    if (answer != -1) {
        return answer;
    }

    if (level == 0) {
        if (a[i] == b[j]) {
            answer = 0;
        }
        else {
            answer = INF;
        }

        return answer;
    }

    int left_a = i * 2;
    int left_b = j * 2;

    int without_swap = add_cost(
        solve(level - 1, left_a, left_b),
        solve(level - 1, left_a + 1, left_b + 1)
    );

    int with_swap = add_cost(
        solve(level - 1, left_a, left_b + 1),
        solve(level - 1, left_a + 1, left_b)
    );

    if (with_swap < INF) {
        with_swap += 1;
    }

    answer = min(without_swap, with_swap);

    return answer;
}

int main() {

    cin >> n;
    cin >> a >> b;

    int levels = 0;
    while ((1 << levels) < n) {
        levels++;
    }

    dp.resize(levels + 1);

    for (int level = 0; level <= levels; level++) {
        int len = 1 << level;
        int blocks = n / len;

        dp[level].assign(blocks, vector<int>(blocks, -1));
    }

    int answer = solve(levels, 0, 0);

    if (answer >= INF) {
        cout << -1 << endl;
    }
    else {
        cout << answer << endl;
    }

    return 0;
}