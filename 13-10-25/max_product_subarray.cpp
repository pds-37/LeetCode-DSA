#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minSoFar = nums[0], maxSoFar = nums[0], result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            if (curr < 0) swap(maxSoFar, minSoFar);

            maxSoFar = max(curr, curr * maxSoFar);
            minSoFar = min(curr, curr * minSoFar);

            result = max(result, maxSoFar);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,3,-2,4};
    cout << s.maxProduct(nums);
    return 0;
}
