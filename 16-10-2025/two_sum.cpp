#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for (int i = 0; i < (int)nums.size(); ++i) {
        int need = target - nums[i];
        if (mp.count(need)) return {mp[need], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n"; // 0 1
    return 0;
}
