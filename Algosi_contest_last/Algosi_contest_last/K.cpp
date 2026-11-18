#include <iostream>
#include <string>
using namespace std;

int main() {

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;

        if (command == "set")
        {
            int p;
            char c;
            cin >> p >> c;

            s[p - 1] = c;
        }
        else
        {
            int l, r;
            cin >> l >> r;

            l -= 1;
            r -= 1;

            bool ok = true;

            while (l < r)
            {
                if (s[l] != s[r])
                {
                    ok = false;
                    break;
                }

                l += 1;
                r -= 1;
            }

            if (ok)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}