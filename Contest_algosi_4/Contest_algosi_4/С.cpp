#include <iostream>

using namespace std;

long long bin_pow_mod(long long a, long long x, long long mod) {
    long long base = a % mod;
    long long answer = 1;
    while (x) {
        if (x % 2) {
            answer = (answer * base) % mod;
        }
        base = (base * base) % mod;
        x /= 2;
    }
    return answer;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        long long a, b, c, p;
        cin >> a >> b >> c >> p;

        long long e = bin_pow_mod(b, c, p - 1);
        long long answer = bin_pow_mod(a, e, p);

        cout << answer << '\n';
    }

    return 0;
}