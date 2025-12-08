#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,2,2,3};
    int k = s.removeDuplicates(nums);

    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    return 0;
}
