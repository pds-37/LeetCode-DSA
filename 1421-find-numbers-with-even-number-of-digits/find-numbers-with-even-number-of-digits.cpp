class Solution {
public:
    bool even(int number){
        int count =1;
        while(number>=10){
            number/=10;
            count++;
        }
        if(count%2==0){
            return true;
        }
        return false;
    }

    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(even(nums[i])){
                ans++;
            }
        }
        return ans;
    }
};