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

vector<int> get_echo_lengths(const string& s) {
    vector<int> pi = prefix_function(s);
    vector<int> lengths;

    int current = pi.back();

    while (current > 0) {
        lengths.push_back(current);
        current = pi[current - 1];
    }

    reverse(lengths.begin(), lengths.end());
    return lengths;
}

int main() {

    string s;
    cin >> s;

    vector<int> answer = get_echo_lengths(s);

    cout << answer.size() << endl;

    for (int length : answer) {
        cout << length << ' ';
    }

    cout << '\n';

    return 0;
}