#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for (int x : nums2) {
            if (s.count(x)) {
                ans.push_back(x);
                s.erase(x);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> a = {1,2,2,1};
    vector<int> b = {2,2};

    vector<int> res = s.intersection(a, b);
    for (int x : res) cout << x << " ";
    return 0;
}
