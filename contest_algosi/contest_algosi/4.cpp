#include <iostream>
#include <vector>
#include <deque>

int main() {

    int n, k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::deque<int> dq;
    bool first = true;

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);

        if (dq.front() <= i - k) dq.pop_front();

        if (i >= k - 1) {
            if (!first) std::cout << ' ';
            first = false;
            std::cout << a[dq.front()];
        }
    }
    std::cout << "\n";
    return 0;
}