#include <bits/stdc++.h>
using namespace std;

int maxArea(const vector<int>& height) {
    int i = 0, j = (int)height.size() - 1;
    int maxA = 0;
    while (i < j) {
        int h = min(height[i], height[j]);
        maxA = max(maxA, h * (j - i));
        if (height[i] < height[j]) ++i;
        else --j;
    }
    return maxA;
}

int main() {
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(h) << "\n"; // 49
    return 0;
}
