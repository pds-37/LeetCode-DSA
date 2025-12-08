#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val; ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}

void printList(ListNode* h) {
    while (h) { cout << h->val; if (h->next) cout << " -> "; h = h->next; } cout << "\n";
}

int main() {
    // 342 + 465 = 807  (lists in reverse order)
    ListNode* a = new ListNode(2); a->next = new ListNode(4); a->next->next = new ListNode(3);
    ListNode* b = new ListNode(5); b->next = new ListNode(6); b->next->next = new ListNode(4);
    ListNode* sum = addTwoNumbers(a, b);
    printList(sum); // 7 -> 0 -> 8
    // cleanup
    while (sum) { ListNode* t = sum; sum = sum->next; delete t; }
    delete a->next->next; delete a->next; delete a; // safe because nodes were not reused
    delete b->next->next; delete b->next; delete b;
    return 0;
}
