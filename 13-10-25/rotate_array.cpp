#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> result(n);

        for (int i = 0; i < k; i++)
            result[i] = nums[n - k + i];

        for (int i = k; i < n; i++)
            result[i] = nums[i - k];

        nums = result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7};
    s.rotate(nums, 3);

    for (int x : nums) cout << x << " ";
    return 0;
}
