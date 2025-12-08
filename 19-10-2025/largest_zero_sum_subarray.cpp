#include <bits/stdc++.h>
using namespace std;

// Return length of largest subarray with sum = 0
int maxLengthZeroSum(const vector<int>& arr) {
    int n = arr.size();
    unordered_map<int,int> firstIndex; // prefix_sum -> first index where seen
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum == 0) {
            maxLen = max(maxLen, i + 1);
        } else if (firstIndex.find(sum) != firstIndex.end()) {
            maxLen = max(maxLen, i - firstIndex[sum]);
        } else {
            firstIndex[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    cout << maxLengthZeroSum({15, -2, 2, -8, 1, 7, 10, 23}) << "\n"; // expected 5 (-2,2,-8,1,7)
    cout << maxLengthZeroSum({1, 2, 3}) << "\n"; // expected 0
    cout << maxLengthZeroSum({1, -1, 3, -3, 5, -5}) << "\n"; // expected 6
    return 0;
}
