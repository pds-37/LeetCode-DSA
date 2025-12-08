#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    int sum = 0;
    for (int x : dp) sum += x;
    return sum;
}

int main() {
    cout << countSetBits(4); // expected 5
}
