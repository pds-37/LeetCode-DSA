#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
    unordered_map<int,int> mp;
    stack<int> st;
    for (int num : nums2) {
        while (!st.empty() && st.top() < num) {
            mp[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }
    while (!st.empty()) { mp[st.top()] = -1; st.pop(); }
    vector<int> res;
    for (int x : nums1) res.push_back(mp[x]);
    return res;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for (int x : ans) cout << x << " ";
    cout << "\n"; // expected -1 3 -1
    return 0;
}
