#include <iostream>
#include <vector>
using namespace std;

bool isBST(int n, int root, vector<long long> val,  vector<int> L, vector<int> R)
{
    if (n == 0) return true;

    vector<int> st;

    int v = root;
    long long last = 0;
    bool have_last = false;

    while (true) {
        if (v != 0) {
            st.push_back(v);
            v = L[v];
            continue;
        }

        if (st.empty())
            break;

        int curr = st.back();
        st.pop_back();

        if (have_last && val[curr] <= last)
            return false;

        last = val[curr];
        have_last = true;

        v = R[curr];
    }

    return true;
}

int main() {
    int n, root;
    cin >> n >> root;

    vector<long long> val(n+1);
    vector<int> L(n+1), R(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> val[i] >> L[i] >> R[i];
    }

    cout << (isBST(n, root, val, L, R) ? "SAFE\n" : "BREACH\n");
    return 0;
}