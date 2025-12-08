#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : arr) pq.push(x);
    int res = 0;
    while (k--) {
        res = pq.top();
        pq.pop();
    }
    return res;
}

int main() {
    vector<int> arr = {7,10,4,3,20,15};
    cout << kthSmallest(arr, 3) << "\n"; // expected 7
    return 0;
}
