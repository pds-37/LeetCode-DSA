class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            int p = nums[i];
            
            
            if (p == 2) {
                ans[i] = -1;
                continue;
            }

            
            int bit = 1;
            int temp = p;
            
            while ((temp & 1) == 1) {
                temp >>= 1;
                bit <<= 1;
            }
            
            
            ans[i] = p - (bit >> 1);
        }
        return ans;
    }
};