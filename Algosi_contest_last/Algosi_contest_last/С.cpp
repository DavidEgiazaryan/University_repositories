#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long long MOD = 1000000007;

struct Query {
    int l, r, c;
};

void paint(int l, int r, int c, vector<int>& color, set<int>& free_cells) {
    auto it = free_cells.lower_bound(l);

    while (it != free_cells.end() && *it <= r)
    {
        int pos = *it;
        color[pos] = c;

        it = free_cells.erase(it);
    }
}

pair<int, long long> get_answer(const vector<int>& color, int n) {
    int segments = 1;
    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && color[i] != color[i - 1])
        {
            segments += 1;
        }

        long long add = (long long)i * color[i];
        sum = (sum + add) % MOD;
    }

    return { segments, sum };
}

int main() {

    int n, q;
    cin >> n >> q;

    vector<Query> queries(q);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].l >> queries[i].r >> queries[i].c;
    }

    vector<int> color(n + 1, 0);
    set<int> free_cells;

    for (int i = 1; i <= n; i++)
    {
        free_cells.insert(i);
    }

    for (int i = q - 1; i >= 0; i--)
    {
        paint(queries[i].l, queries[i].r, queries[i].c, color, free_cells);
    }

    pair<int, long long> answer = get_answer(color, n);

    cout << answer.first << ' ' << answer.second << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << ' ';
    }

    cout << endl;

    return 0;
}