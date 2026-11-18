#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    int cnt[101] = { 0 };
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    bool first = true;
    for (int v = 0; v <= 100; v++) {
        for (int k = 0; k < cnt[v]; k++) {
            if (!first) std::cout << ' ';
            first = false;
            std::cout << v;
        }
    }
    std::cout << '\n';
    return 0;
}
