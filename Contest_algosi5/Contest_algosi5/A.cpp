#include <iostream>
using namespace std;
#define MAXN 200005

char s[MAXN];

int countOnes(int l, int r) {
    int cnt = 0;

    for (int i = l; i < r; i++) {
        if (s[i] == '1') {
            cnt++;
        }
    }

    return cnt;
}

void archive(int l,int r,long long* ans) {

    int len = r - l;
    int cnt = countOnes(l, r);
    *ans += len + cnt;

    if (len == 1) {
        return;
    }

    int mid = l + (r - l) / 2;
    
    archive(l, mid, ans);
    archive(mid, r, ans);
}


int main() {
    int n;
    long long ans = 0;

    cin >> n;
    cin >> s;

    archive(0, n, &ans);

    cout << ans << '\n';

    return 0;
}




