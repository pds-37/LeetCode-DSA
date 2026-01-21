class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i];
            
            // Case 1: Even prime (2) cannot be formed by x | (x+1)
            if (p == 2) {
                ans[i] = -1;
                continue;
            }

            // Case 2: Odd numbers
            // Find the position of the first zero bit starting from LSB
            // This tells us the range of the trailing 1s.
            int bit = 1;
            int temp = p;
            
            while ((temp & 1) == 1) {
                temp >>= 1;
                bit <<= 1;
            }
            
            // 'bit' is now just above the trailing 1s.
            // We want to subtract half of 'bit' (the MSB of the trailing 1s).
            ans[i] = p - (bit >> 1);
        }
        return ans;
    }
};