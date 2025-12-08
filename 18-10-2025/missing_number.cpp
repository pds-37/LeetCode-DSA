#include <bits/stdc++.h>
using namespace std;

// Using XOR (O(n) time, O(1) space)
int missingNumber(const vector<int>& nums) {
    int n = nums.size();
    int xr = 0;
    for (int i = 0; i < n; ++i) xr ^= nums[i];
    for (int i = 0; i <= n; ++i) xr ^= i;
    return xr;
}

int main() {
    cout << missingNumber({3,0,1}) << "\n"; // 2
    cout << missingNumber({0,1}) << "\n";   // 2
    return 0;
}
