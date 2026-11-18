#include <iostream>
#include <string>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1000 + 5;

string a[MAXN][MAXN];
long long dp[MAXN][MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            dp[i][j] = INF;
        }
    }

    if (a[0][0] == "#") {
        cout << -1;
        return 0;
    }

    dp[0][0] = stoll(a[0][0]);

    for (int i = 1; i < n; i++) {
        if (a[i][0] != "#" && dp[i - 1][0] != INF) {
            dp[i][0] = dp[i - 1][0] + stoll(a[i][0]);
        }
    }

    for (int j = 1; j < m; j++) {
        if (a[0][j] != "#" && dp[0][j - 1] != INF) {
            dp[0][j] = dp[0][j - 1] + stoll(a[0][j]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != "#" && min(dp[i][j - 1], dp[i - 1][j]) != INF) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + stoll(a[i][j]);
            }
        }
    }

    if (dp[n - 1][m - 1] == INF) {
        cout << -1;
    }
    else {
        cout << dp[n - 1][m - 1];
    }

    return 0;
}