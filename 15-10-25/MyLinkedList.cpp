#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

class MyLinkedList {
private:
    Node* head;
    int size;
public:
    MyLinkedList(): head(nullptr), size(0) {}

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index; ++i) curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        Node* curr = new Node(val);
        curr->next = head;
        head = curr;
        ++size;
    }

    void addAtTail(int val) {
        Node* curr = new Node(val);
        if (!head) head = curr;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = curr;
        }
        ++size;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) { addAtHead(val); return; }
        if (index == size) { addAtTail(val); return; }
        Node* curr = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) temp = temp->next;
        curr->next = temp->next;
        temp->next = curr;
        ++size;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* toDel = head;
            head = head->next;
            delete toDel;
        } else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) temp = temp->next;
            Node* toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
        --size;
    }

    // helper: print list
    void printList() {
        Node* t = head;
        while (t) {
            cout << t->val;
            if (t->next) cout << " -> ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    MyLinkedList list;
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2); // list: 1->2->3
    cout << "get(1): " << list.get(1) << "\n"; // 2
    list.printList();
    list.deleteAtIndex(1); // list: 1->3
    list.printList();
    return 0;
}
