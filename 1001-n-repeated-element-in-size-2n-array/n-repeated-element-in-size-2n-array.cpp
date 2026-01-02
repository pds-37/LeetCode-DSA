class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>frequency_map;
        int n=nums.size()/2;

        for(int num : nums){
            frequency_map[num]++;
        }
        for(auto const &i : frequency_map){
            if(i.second==n){
                return i.first;
            }
        }
    return -1;
    }
};