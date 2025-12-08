#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;

    priority_queue<pair<int,int>> pq;
    for (auto &p : freq) {
        pq.push({p.second, p.first});
    }

    vector<int> res;
    while (k--) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = topKFrequent(nums, 2);
    for (int x : ans) cout << x << " "; // expected 1 2
    cout << "\n";
    return 0;
}
