#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;
    ListNode* curr = head;
    int length = 1;
    while (curr->next) { curr = curr->next; ++length; }
    curr->next = head; // make circular
    k = k % length;
    int stepsToNewTail = length - k;
    ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail - 1; ++i) newTail = newTail->next;
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}

void printList(ListNode* h) {
    while (h) { cout << h->val; if (h->next) cout << " -> "; h = h->next; } cout << "\n"; }

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for (int i = 2; i <= 5; ++i) t = (t->next = new ListNode(i)); // 1->2->3->4->5
    cout << "Before: "; printList(head);
    ListNode* r = rotateRight(head, 2);
    cout << "After:  "; printList(r); // expected 4->5->1->2->3
    // cleanup
    while (r) { ListNode* tmp = r; r = r->next; delete tmp; }
    return 0;
}
