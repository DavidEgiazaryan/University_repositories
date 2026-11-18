#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2000000;

int lp[MAXN + 1];
int phi[MAXN + 1];
long long pref[MAXN + 1];
vector<int> primes;

void linear_sieve(int n) {
    phi[1] = 1;

    for (int x = 2; x <= n; ++x) {
        if (lp[x] == 0) {
            lp[x] = x;
            primes.push_back(x);
            phi[x] = x - 1;
        }

        for (int p : primes) {
            if (p > lp[x] || 1LL * x * p > n) {
                break;
            }
            lp[x * p] = p;
            if (p == lp[x]) {
                phi[x * p] = phi[x] * p;
                break;
            }
            else {
                phi[x * p] = phi[x] * (p - 1);
            }
        }
    }
}

void build_prefix(int n) {
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + phi[i];
    }
}

long long get_sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

int main() {
    int n, q;
    cin >> n >> q;

    linear_sieve(n);
    build_prefix(n);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get_sum(l, r) << '\n';
    }

    return 0;
}