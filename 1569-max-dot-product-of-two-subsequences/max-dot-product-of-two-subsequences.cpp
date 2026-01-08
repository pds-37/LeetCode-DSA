

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Initialize DP table
        // dp[i][j] stores the max dot product using subsequences of nums1[0...i] and nums2[0...j]
        vector<vector<int>> dp(n, vector<int>(m));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                
                int product = nums1[i] * nums2[j];
                
                // Get values from previous states, handling boundary checks
                int prev_diag = (i > 0 && j > 0) ? dp[i-1][j-1] : INT_MIN;
                int prev_top  = (i > 0) ? dp[i-1][j] : INT_MIN;
                int prev_left = (j > 0) ? dp[i][j-1] : INT_MIN;
                
                // We use 'product + prev_diag' only if prev_diag is valid (not INT_MIN).
                // However, since we want to handle negative numbers correctly, 
                // a simpler logic is to take the max of the valid previous states directly.
                
                // 1. Start fresh with current pair
                dp[i][j] = product;
                
                // 2. Extend previous chain (if previous diagonal exists)
                if (i > 0 && j > 0) {
                    dp[i][j] = max(dp[i][j], product + prev_diag);
                }
                
                // 3. Skip current nums1[i] (take value from top)
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], prev_top);
                }
                
                // 4. Skip current nums2[j] (take value from left)
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], prev_left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};