#include <iostream>
using namespace std;

long long normalize(long long x, long long mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

long long mul_mod(long long a, long long b, long long mod) {
    a = normalize(a, mod);
    b = normalize(b, mod);

    long long result = 0;

    while (b > 0) {
        if (b & 1) {
            if (result >= mod - a) result -= (mod - a);
            else result += a;
        }

        if (a >= mod - a) a -= (mod - a);
        else a += a;

        b >>= 1;
    }

    return result;
}

long long extended_gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = (long long)((long long)x1 - (long long)(a / b) * y1);

    return g;
}

bool get_inverse(long long b, long long mod, long long& inv) {
    long long x, y;
    long long g = extended_gcd(b, mod, x, y);

    if (g != 1) return false;

    inv = normalize(x, mod);
    return true;
}

long long solve_query(long long a, long long b, long long m) {
    long long inv;

    if (!get_inverse(b, m, inv)) return -1;

    return mul_mod(a, inv, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        long long a, b, m;
        cin >> a >> b >> m;
        cout << solve_query(a, b, m) << '\n';
    }

    return 0;
}