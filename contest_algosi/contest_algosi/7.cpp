#include <iostream>
#include <climits>
#include <string>

class List {
    struct Node {
        int x;
        Node* next, * prev;
    };
    Node* head;
public:
    List() {
        head = new Node();
        head->next = head;
        head->prev = head;
    }

    bool Empty() {
        return head->next == head;
    }

    void PushBack(int x) {
        Node* new_node = new Node();
        new_node->x = x;
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }

    void PushFront(int x) {
        Node* new_node = new Node();
        new_node->x = x;
        new_node->next = head->next;
        new_node->prev = head;
        head->next->prev = new_node;
        head->next = new_node;
    }

    int PopBack() {
        if (head->prev == head) {
            return INT_MAX;
        }
        Node* on_delete = head->prev;
        on_delete->prev->next = head;
        head->prev = on_delete->prev;
        int x = on_delete->x;
        delete on_delete;
        return x;
    }

    int PopFront() {
        if (head->next == head) {
            return INT_MAX;
        }
        Node* on_delete = head->next;
        on_delete->next->prev = head;
        head->next = on_delete->next;
        int x = on_delete->x;
        delete on_delete;
        return x;
    }

    void Print() {
        Node* current = head->next;
        while (current != head) {
            std::cout << current->x << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int Back() const {
        if (head->prev == head) return INT_MAX;
        return head->prev->x;
    }

    int Front() const {
        if (head->next == head) return INT_MAX;
        return head->next->x;
    }

};

class Queue {
    List list;
public:
    void Enqueue(int x) {
        list.PushBack(x);
    }

    int Dequeue() {
        return list.PopFront();
    }

    bool Empty() {
        return list.Empty();
    }

    int PopBack() { 
        return list.PopBack(); 
    }

    int Front() const {
        return list.Front(); 
    }

    int Back() const { 
        return list.Back(); 
    }
};

int main() {

    int q;
    std::cin >> q;

    Queue qu;
    Queue mx;

    for (int i = 0; i < q; i++) {
        std::string op;
        std::cin >> op;

        if (op == "push") {
            int x;
            std::cin >> x;

            qu.Enqueue(x);

            while (!mx.Empty() && mx.Back() < x) {
                mx.PopBack();
            }
            mx.Enqueue(x);

        }
        else if (op == "pop") {
            int v = qu.Dequeue();
            if (!mx.Empty() && v == mx.Front()) {
                mx.Dequeue();
            }

        }
        else if (op == "max") {
            std::cout << mx.Front() << "\n";
        }
    }

    return 0;
}