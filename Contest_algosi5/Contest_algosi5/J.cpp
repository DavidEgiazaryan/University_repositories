#include <iostream>
#include <string>
using namespace std;

const int MAXN = 500 + 5;
const int INF = 1e9;

string s;
int dp[MAXN][MAXN];

int get(int l, int r) {
    if (l > r) {
        return 0;
    }

    return dp[l][r];
}

int main() {
    cin >> s;

    int n = s.size();

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;

            dp[l][r] = 1 + get(l + 1, r);

            for (int k = l + 1; k <= r; k++) {
                if (s[l] == s[k]) {
                    int cost = max(1, get(l + 1, k - 1)) + get(k + 1, r);
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }
    }

    cout << dp[0][n - 1];

    return 0;
}