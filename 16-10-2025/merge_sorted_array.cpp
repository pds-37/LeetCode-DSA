#include <bits/stdc++.h>
using namespace std;

// LeetCode 88: merge nums2 into nums1 which has enough space at end
void mergeArrays(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    mergeArrays(nums1, 3, nums2, 3);
    for (int x : nums1) cout << x << " ";
    cout << "\n"; // 1 2 2 3 5 6
    return 0;
}
