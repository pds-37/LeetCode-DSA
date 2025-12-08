#include <bits/stdc++.h>
using namespace std;

// Search in rotated sorted array with duplicates; return true/false
bool searchRotatedWithDup(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;
        if (nums[low] == nums[mid] && nums[high] == nums[mid]) {
            ++low; --high;
        } else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<int> a = {2,5,6,0,0,1,2};
    cout << (searchRotatedWithDup(a, 0) ? "true" : "false") << "\n"; // true
    cout << (searchRotatedWithDup(a, 3) ? "true" : "false") << "\n"; // false
    return 0;
}
