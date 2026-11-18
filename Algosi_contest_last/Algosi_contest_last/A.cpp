#include <iostream>
#include <map>
#include <vector>
using namespace std;

const long long START_MAX = -1;

struct Answer {
    long long oneCovered;
    long long maxMass;
    long long left;
    long long length;
};

void add_event(map<long long, pair<long long, long long>>& events,
    long long x, long long countDelta, long long massDelta) {
    events[x].first += countDelta;
    events[x].second += massDelta;
}

void update_best(long long x, long long len, long long count, long long mass, Answer& ans) {
    if (count == 1) {
        ans.oneCovered += len;
    }

    if (count > 0 && mass > ans.maxMass) {
        ans.maxMass = mass;
        ans.left = x;
        ans.length = len;
    }
    else if (count > 0 && mass == ans.maxMass && ans.left + ans.length == x) {
        ans.length += len;
    }
}

int main() {

    int n;
    cin >> n;

    map<long long, pair<long long, long long>> events;

    for (int i = 0; i < n; i++)
    {
        long long l, r, w;
        cin >> l >> r >> w;

        add_event(events, l, 1, w);
        add_event(events, r + 1, -1, -w);
    }

    long long count = 0;
    long long mass = 0;

    Answer ans = { 0, START_MAX, 0, 0 };

    bool first = true;
    long long lastX = 0;

    for (auto event : events)
    {
        long long x = event.first;

        if (!first)
        {
            long long len = x - lastX;
            update_best(lastX, len, count, mass, ans);
        }

        count += event.second.first;
        mass += event.second.second;

        lastX = x;
        first = false;
    }

    cout << ans.oneCovered << ' ' << ans.maxMass << ' ' << ans.left << ' ' << ans.length << endl;

    return 0;
}