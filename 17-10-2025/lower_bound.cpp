#include <bits/stdc++.h>
using namespace std;

// returns first index i such that arr[i] >= target, or n if none
int lowerBound(const vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 7};
    cout << lowerBound(arr, 4) << "\n"; // expected 2
    cout << lowerBound(arr, 6) << "\n"; // expected 5
    cout << lowerBound(arr, 8) << "\n"; // expected 6 (n)
    return 0;
}
