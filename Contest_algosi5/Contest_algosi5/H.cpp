#include <iostream>
using namespace std;

const int MAXN = 5000 + 5;
const long long INF = 1e18;

long long a[MAXN];
long long cost[MAXN][MAXN];
long long dp[MAXN];

int main() {
    int n, L, R;
    cin >> n >> L >> R;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int l = 1; l <= n; l++) {
        long long mn = a[l];
        long long mx = a[l];

        for (int r = l; r <= n; r++) {
            mn = min(mn, a[r]);
            mx = max(mx, a[r]);

            cost[l][r] = mx - mn;
        }
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int len = L; len <= R; len++) {
            if (i - len >= 0 && dp[i - len] != INF) {
                int l = i - len + 1;
                int r = i;

                dp[i] = min(dp[i], dp[i - len] + cost[l][r]);
            }
        }
    }

    if (dp[n] == INF) {
        cout << -1;
    }
    else {
        cout << dp[n];
    }

    return 0;
}