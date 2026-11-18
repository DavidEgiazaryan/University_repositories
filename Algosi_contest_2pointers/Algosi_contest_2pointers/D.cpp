#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(const string& s) {
    vector<int> pi(s.size(), 0);

    for (int i = 1; i < (int)s.size(); i++) {
        int j = pi[i - 1];

        while (j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

vector<int> find_positions(const string& pattern, const string& text) {
    string joined = pattern + "#" + text;
    vector<int> pi = prefix_function(joined);

    vector<int> positions;
    int m = pattern.size();

    for (int i = m + 1; i < (int)joined.size(); i++) {
        if (pi[i] == m) {
            positions.push_back(i - 2 * m + 1);
        }
    }

    return positions;
}

int main() {

    string p, t;
    cin >> p >> t;

    vector<int> answer = find_positions(p, t);

    cout << answer.size() << '\n';

    for (int pos : answer) {
        cout << pos << ' ';
    }

    cout << '\n';

    return 0;
}