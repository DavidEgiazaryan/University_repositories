#include <iostream>
#include <string>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    int diff = 0;
    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++)
    {
        if (a[r] != b[r])
        {
            diff += 1;
        }

        while (diff > k)
        {
            if (a[l] != b[l])
            {
                diff -= 1;
            }

            l += 1;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << endl;

    return 0;
}