#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX, maxVal = INT_MIN;
        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < minVal) minVal = nums[i], minIdx = i;
            if (nums[i] > maxVal) maxVal = nums[i], maxIdx = i;
        }

        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        int front = maxIdx + 1;
        int back = n - minIdx;
        int both = (minIdx + 1) + (n - maxIdx);

        return min(front, min(back, both));
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    cout << s.minimumDeletions(nums);
    return 0;
}
