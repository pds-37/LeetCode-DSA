#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};


void deleteNode(ListNode* node) {
    if (!node || !node->next) return;
    ListNode* nxt = node->next;
    node->val = nxt->val;
    node->next = nxt->next;
    delete nxt;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before: ";
    printList(head);
    deleteNode(head->next);
    cout << "After:  ";
    printList(head);
    // cleanup
    while (head) {
        ListNode* t = head;
        head = head->next;
        delete t;
    }
    return 0;
}
