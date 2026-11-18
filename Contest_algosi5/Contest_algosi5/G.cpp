#include <iostream>
using namespace std;

const long long NEG = -1;
const int MAXW = 10000 + 5;

long long dp[MAXW];

int main() {
    int n, W;
    cin >> n >> W;

    for (int weight = 0; weight <= W; weight++) {
        dp[weight] = NEG;
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int w;
        long long v;

        cin >> w >> v;

        for (int weight = W; weight >= w; weight--) {
            if (dp[weight - w] != NEG) {
                dp[weight] = max(dp[weight], dp[weight - w] + v);
            }
        }
    }

    long long bestValue = 0;
    int bestWeight = 0;

    for (int weight = 0; weight <= W; weight++) {
        if (dp[weight] > bestValue) {
            bestValue = dp[weight];
            bestWeight = weight;
        }
    }

    cout << bestValue << " " << bestWeight;

    return 0;
}