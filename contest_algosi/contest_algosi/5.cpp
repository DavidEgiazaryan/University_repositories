#include <iostream>
#include <vector>

long long merge_count(std::vector<long long>& a, std::vector<long long>& temp, int l, int r) {
    if (r - l <= 1) return 0;
    int m = l + (r - l) / 2;

    long long inv = 0;
    inv += merge_count(a, temp, l, m);
    inv += merge_count(a, temp, m, r);

    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            inv += (m - i);
        }
    }
    while (i < m) temp[k++] = a[i++];
    while (j < r) temp[k++] = a[j++];

    for (int t = l; t < r; t++) a[t] = temp[t];
    return inv;
}

int main() {

    int n;
    std::cin >> n;
    std::vector<long long> a(n), temp(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];

    std::cout << merge_count(a, temp, 0, n) << "\n";
    return 0;
}