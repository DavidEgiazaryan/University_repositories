#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    array<int, 26> cnt{};
    int diff = 0;
    int l = 0;
    int ans = 0;
    
    for (int r = 0; r < n;r++)
    {
        int x = s[r] - 'a';
        if (cnt[x] == 0)
        {
            diff += 1;
        }

        cnt[x] += 1;



        while (diff > k)
        {
            int y = s[l] - 'a';

            if (cnt[y] - 1 <= 0)
            {
                diff -= 1;
            }
            cnt[y] -= 1;
            l += 1;
        }

        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;

return 0;
}