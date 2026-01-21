class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans;
        int prefix=0;
        for(int i=0; i<nums.size(); i++){
            prefix+=nums[i];
            ans.push_back(prefix);
        }
        return ans;
    }
};