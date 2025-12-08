#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int x : nums) mp[x]++;

        int mx = 0, cnt = 0;
        for (auto &p : mp) mx = max(mx, p.second);
        for (auto &p : mp) if (p.second == mx) cnt += p.second;

        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,2,3,3,3};
    cout << s.maxFrequencyElements(nums);
    return 0;
}
