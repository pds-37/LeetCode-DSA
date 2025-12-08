#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = nums[0];

        for (int i = 1; i < n; i++)
            res[i] = nums[i] + res[i - 1];

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = s.runningSum(nums);

    for (int x : res) cout << x << " ";
    return 0;
}
