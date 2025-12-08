#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq; 
    for (int x : nums) pq.push(x);
    int res = 0;
    while (k--) {
        res = pq.top();
        pq.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
   cout << findKthLargest(nums, 2) << "\n"; // expected 5
    return 0;
}
