#include <iostream>
#include <vector>
using namespace std;

bool is_RBT(int n, int root,
    vector<long long> val,
    vector<string> col,
    vector<int> L,
    vector<int> R)
{
    if (n == 0) return true;

    if (col[root] != "BLACK")
        return false;

    {
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

            int cur = st.back();
            st.pop_back();

            if (have_last && val[cur] <= last)
                return false;

            last = val[cur];
            have_last = true;

            v = R[cur];
        }
    }

    vector<int> st1, st2;
    st1.push_back(root);

    while (!st1.empty()) {
        int v = st1.back();
        st1.pop_back();
        st2.push_back(v);

        if (L[v] != 0) st1.push_back(L[v]);
        if (R[v] != 0) st1.push_back(R[v]);
    }

    vector<int> bh(n + 1, 0);

    while (!st2.empty()) {
        int v = st2.back();
        st2.pop_back();

        int left = L[v];
        int right = R[v];

        int left_bh = (left == 0 ? 1 : bh[left]);
        int right_bh = (right == 0 ? 1 : bh[right]);

        if (left_bh != right_bh)
            return false;

        if (col[v] == "RED") {
            if ((left != 0 && col[left] == "RED") or
                (right != 0 && col[right] == "RED"))
                return false;
        }

        bh[v] = left_bh + (col[v] == "BLACK");
    }

    return true;
}

int main() {
    int n, root;
    cin >> n >> root;

    if (n == 0) {
        cout << "SEALED\n";
        return 0;
    }

    vector<long long> val(n + 1);
    vector<string> col(n + 1);
    vector<int> L(n + 1), R(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> val[i] >> col[i] >> L[i] >> R[i];
    }

    cout << (is_RBT(n, root, val, col, L, R)
        ? "SEALED\n"
        : "FRACTURED\n");

    return 0;
}