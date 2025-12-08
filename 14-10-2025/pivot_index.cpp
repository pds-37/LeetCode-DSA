#include <bits/stdc++.h>
using namespace std;

int pivotIndex(const vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (left == total - left - nums[i]) return i;
        left += nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {1,7,3,6,5,6};
    cout << pivotIndex(nums) << "\n";
    return 0;
}
