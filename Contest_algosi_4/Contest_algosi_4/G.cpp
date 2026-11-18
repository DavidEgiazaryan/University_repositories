#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <ctime>

#define int long long
#define ITERS 30

using namespace std;

int mul_mod(int a, int b, int mod) {
    return (__int128)a * b % mod;
}

int bin_pow(int a, int p, int mod) {
    int answer = 1;
    int base = a % mod;
    while (p) {
        if (p % 2 == 1) {
            answer = mul_mod(answer, base, mod);
        }
        base = mul_mod(base, base, mod);
        p /= 2;
    }
    return answer;
}

int get_rand(int l, int r) {
    unsigned long long value = 0;
    for (int i = 0; i < 5; ++i) {
        value = (value << 15) ^ rand();
    }
    return l + value % (unsigned long long)(r - l + 1);
}

bool miller_rabin_iter(int a, int n, int s, int d) {
    int x = bin_pow(a, d, n);
    if (x == 1 || x == n - 1) return true;

    for (int i = 1; i < s; ++i) {
        x = mul_mod(x, x, n);
        if (x == n - 1) return true;
    }
    return false;
}

bool is_prime_miller_rabin(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    int d = n - 1, s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    for (int i = 0; i < ITERS; ++i) {
        int a = get_rand(2, n - 2);
        if (!miller_rabin_iter(a, n, s, d)) return false;
    }
    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    srand(time(0));

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;

        if (is_prime_miller_rabin(n)) {
            cout << "PRIME\n";
        }
        else {
            cout << "COMPOSITE\n";
        }
    }

    return 0;
}