class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_sum=nums[0];
        int curr_sum=0;
        for(int i=0; i<nums.size(); i++)
        {
              curr_sum+=nums[i];
              nums[i]=curr_sum;
              
              if(curr_sum>global_sum){
                global_sum=curr_sum;
              }
              if(curr_sum<0){
                curr_sum=0;
              }
            
        }
        return global_sum;
    }
};