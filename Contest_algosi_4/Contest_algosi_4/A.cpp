#include <iostream>

long long absolute_value(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
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
    y = x1 - (a / b) * y1;

    return g;
}

bool find_solution(long long a, long long b, long long c, long long& x, long long& y) {
    if (a == 0 && b == 0) {
        if (c == 0) {
            x = 0;
            y = 0;
            return true;
        }
        return false;
    }

    long long x0, y0;
    long long aa = absolute_value(a);
    long long bb = absolute_value(b);

    long long g = extended_gcd(aa, bb, x0, y0);

    if (c % g != 0) {
        return false;
    }

    long long k = c / g;

    x = x0 * k;
    y = y0 * k;

    if (a < 0) {
        x = -x;
    }
    if (b < 0) {
        y = -y;
    }

    return true;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long a, b, c;
        long long x, y;

        std::cin >> a >> b >> c;

        if (find_solution(a, b, c, x, y)) {
            std::cout << "YES " << x << ' ' << y << '\n';
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}