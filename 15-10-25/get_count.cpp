#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

int getCount(Node* head) {
    int size = 0;
    Node* temp = head;
    while (temp) {
        temp = temp->next;
        ++size;
    }
    return size;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << "Count = " << getCount(head) << "\n"; // 3
    
    while (head) { Node* t = head; head = head->next; delete t; }
    return 0;
}
