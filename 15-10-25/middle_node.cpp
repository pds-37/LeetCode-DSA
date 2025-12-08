#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* t = head;
    for (int i = 2; i <= 6; ++i) t = (t->next = new ListNode(i));
    ListNode* mid = middleNode(head);
    cout << "Middle value: " << (mid ? mid->val : -1) << "\n"; // 4 (for 1..6)
    // cleanup
    while (head) { ListNode* tmp = head; head = head->next; delete tmp; }
    return 0;
}
