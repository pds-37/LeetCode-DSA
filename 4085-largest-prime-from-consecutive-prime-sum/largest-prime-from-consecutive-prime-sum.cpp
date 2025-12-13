class Solution {
public:
    int largestPrime(int n) {
        if (n < 2) return 0;

        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    is_prime[i] = false;
            }
        }

        long long current_sum = 0;
        int ans = 0;

        for (int p = 2; p <= n; p++) {
            if (is_prime[p]) {
                current_sum += p;

                if (current_sum > n) break;

                if (is_prime[current_sum]) {
                    ans = current_sum;
                }
            }
        }

        return ans;
    }
};