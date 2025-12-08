#include <bits/stdc++.h>
using namespace std;

int trap(const vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) leftMax[i] = max(height[i], leftMax[i-1]);
    rightMax[n-1] = height[n-1];
    for (int i = n - 2; i >= 0; --i) rightMax[i] = max(height[i], rightMax[i+1]);
    int water = 0;
    for (int i = 0; i < n; ++i) water += max(0, min(leftMax[i], rightMax[i]) - height[i]);
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << "\n"; // 6
    return 0;
}
