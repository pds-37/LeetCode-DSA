#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main() {
    auto res = countBits(5);
    for (int x : res) cout << x << " ";
    return 0; // expected 0 1 1 2 1 2
}
