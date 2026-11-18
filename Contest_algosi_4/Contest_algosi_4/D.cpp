#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 2000000;

vector<int> lp(MAXN + 1);
vector<int> primes;

void linear_sieve(int n) {
    for (int x = 2; x <= n; ++x) {
        if (lp[x] == 0) {
            lp[x] = x;
            primes.push_back(x);
        }

        for (int p : primes) {
            if (p > lp[x] || x * p > n) {
                break;
            }
            lp[x * p] = p;
        }
    }
}

void solve_number(int n, long long& d_cnt, long long& s_sum, long long& phi) {
    d_cnt = 1;
    s_sum = 1;
    phi = n;

    while (n > 1) {
        int p = lp[n];
        int alpha = 0;

        while (n % p == 0) {
            n /= p;
            alpha++;
        }

        d_cnt *= (alpha + 1);

        long long cur_sum = 1;
        long long cur_pow = 1;
        for (int i = 0; i < alpha; ++i) {
            cur_pow *= p;
            cur_sum += cur_pow;
        }
        s_sum *= cur_sum;

        phi = phi / p * (p - 1);
    }
}

int main() {
    int q;
    cin >> q;

    linear_sieve(MAXN);

    while (q--) {
        int n;
        cin >> n;

        long long d_cnt, s_sum, phi;
        solve_number(n, d_cnt, s_sum, phi);

        cout << d_cnt << ' ' << s_sum << ' ' << phi << '\n';
    }

    return 0;
}