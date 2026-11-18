#include <iostream>
#include <vector>
using namespace std;

void quick_sort(vector<long long>& a, int left, int right) {
    int i = left;
    int j = right;
    long long pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}

long long count_pairs(vector<long long>& a, long long x) {
    int l = 0;
    int r = (int)a.size() - 1;
    long long cnt = 0;

    while (l < r) {
        if (a[l] + a[r] <= x) {
            cnt += r - l;
            l++;
        }
        else {
            r--;
        }
    }

    return cnt;
}

int main() {
    int n;
    long long L, R;
    cin >> n >> L >> R;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quick_sort(a, 0, n - 1);

    long long ans = count_pairs(a, R) - count_pairs(a, L - 1);

    cout << ans << endl;

    return 0;
}