class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;   // sum -> first index
        mp[0] = -1;                    // base case
        
        int sum = 0;
        int maxLen = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            // treat 0 as -1, 1 as +1
            sum += (nums[i] == 1 ? 1 : -1);
            
            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;   // store first occurrence only
            }
        }
        
        return maxLen;
    }
};
