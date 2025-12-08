#include <bits/stdc++.h>
using namespace std;


int searchRotated(const vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] >= nums[low]) {
            if (nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> a = {4,5,6,7,0,1,2};
    cout << searchRotated(a, 0) << "\n"; // expected 4
    cout << searchRotated(a, 3) << "\n"; // expected -1
    return 0;
}
