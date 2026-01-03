class Solution {
public:
    int numOfWays(int n) {
         const long MOD = 1e9 + 7;

        long dpA = 6; // Type A
        long dpB = 6; // Type B

        for (int i = 2; i <= n; i++) {
            long newA = (2 * dpA + 2 * dpB) % MOD;
            long newB = (2 * dpA + 3 * dpB) % MOD;
            dpA = newA;
            dpB = newB;
        }

        return (dpA + dpB) % MOD;
    }
};