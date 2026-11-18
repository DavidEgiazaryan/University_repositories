#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Dispatcher {

    struct Drone {
        long long value;
        int id;
    };

    struct Compare {
        bool operator()(const Drone a, const Drone b) const {
            if (a.value != b.value)
                return a.value > b.value;
            return a.id > b.id;
        }
    };

    priority_queue<Drone, vector<Drone>, Compare> mainqueue;

    static const int max_id = 200000;
    vector<long long> current_value;
    vector<bool> active;

    Dispatcher() {
        current_value.resize(max_id + 1);
        active.resize(max_id + 1, false);
    }

    void spawn(int id, long long value) {
        current_value[id] = value;
        active[id] = true;
        mainqueue.push({ value, id });
    }

    void boost(int id, long long new_value) {
        current_value[id] = new_value;
        mainqueue.push({ new_value, id });
    }

    void dispatch() {
        while (!mainqueue.empty()) {
            Drone top = mainqueue.top();
            mainqueue.pop();

            if (active[top.id] and current_value[top.id] == top.value) {
                cout << top.id << " " << top.value << "\n";
                active[top.id] = false;
                return;
            }
        }
    }
};

int main() {
    int q;
    cin >> q;

    Dispatcher system;

    while (q--) {
        string command;
        cin >> command;

        if (command == "spawn") {
            int id;
            long long value;
            cin >> id >> value;
            system.spawn(id, value);
        }
        else if (command == "boost") {
            int id;
            long long value;
            cin >> id >> value;
            system.boost(id, value);
        }
        else if (command == "dispatch") {
            system.dispatch();
        }
    }

    return 0;
}