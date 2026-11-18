#include <iostream>
using namespace std;

const int MAXN = 200000 + 5;

int n;
long long c;
long long a[MAXN];
long long temp[MAXN];

int firstGreater(int left, int right, long long x) {
    int ans = right + 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] > x) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return ans;
}

long long mergeSort(int left, int right) {
    if (left >= right) {
        return 0;
    }

    int mid = left + (right-left) / 2;

    long long answer = 0;

    answer += mergeSort(left, mid);
    answer += mergeSort(mid + 1, right);

    for (int j = mid + 1; j <= right; j++) {
        long long limit = 2 * a[j] + c;
        int pos = firstGreater(left, mid, limit);

        answer += mid - pos + 1;
    }

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid) {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (int p = left; p <= right; p++) {
        a[p] = temp[p];
    }

    return answer;
}

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << mergeSort(0, n - 1);

    return 0;
}