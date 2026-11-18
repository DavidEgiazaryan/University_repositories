#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 and s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == s[j])
        {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main() {

    string s, t;
    cin >> s >> t;

    int best_len = 0;
    int best_s = 0;
    int best_t = 0;

    for (int start = 0; start < (int)s.size(); start++)
    {
        string p = "";

        for (int i = start; i < (int)s.size(); i++)
        {
            p += s[i];
        }

        string joined = p + "#" + t;
        vector<int> pi = prefix_function(joined);

        int m = p.size();

        for (int i = m + 1; i < (int)joined.size(); i++)
        {
            int len = pi[i];

            if (len == 0)
            {
                continue;
            }

            int pos_t = i - m - len + 1;
            int pos_s = start + 1;

            if (len > best_len)
            {
                best_len = len;
                best_s = pos_s;
                best_t = pos_t;
            }
            else if (len == best_len and len > 0)
            {
                if (pos_t < best_t or (pos_t == best_t and pos_s < best_s))
                {
                    best_s = pos_s;
                    best_t = pos_t;
                }
            }
        }
    }

    if (best_len == 0)
    {
        cout << "0 0 0" << endl;
    }
    else
    {
        cout << best_len << ' ' << best_s << ' ' << best_t << endl;
    }

    return 0;
}