#include <bits/stdc++.h>
using namespace std;

struct ListNode { int val; ListNode* next; ListNode(int x): val(x), next(nullptr) {} };

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        while (curr->next && curr->val == curr->next->val) {
            ListNode* toDel = curr->next;
            curr->next = curr->next->next;
            delete toDel;
        }
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* h) { while (h) { cout << h->val; if (h->next) cout << " -> "; h = h->next; } cout << "\n"; }

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    cout << "Before: "; printList(head);
    head = deleteDuplicates(head);
    cout << "After:  "; printList(head); // 1 -> 2 -> 3
    // cleanup
    while (head) { ListNode* tmp = head; head = head->next; delete tmp; }
    return 0;
}
