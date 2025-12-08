#include <bits/stdc++.h>
using namespace std;

// Simulate VersionControl API
int FIRST_BAD = 4; // change for testing

bool isBadVersion(int v) {
    return v >= FIRST_BAD;
}

int firstBadVersion(int n) {
    int low = 1, high = n;
    int ans = n+1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) {
            ans = mid;
            high = mid - 1;
        } else low = mid + 1;
    }
    return ans == n+1 ? -1 : ans;
}

int main() {
    int n = 10;
    cout << "First bad version: " << firstBadVersion(n) << "\n"; // expected 4
    return 0;
}
