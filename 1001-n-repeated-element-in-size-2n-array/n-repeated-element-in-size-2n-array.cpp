class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> frequencyMap;
    int n=nums.size()/2;
    for (int num : nums) {
        frequencyMap[num]++;
    }

    for (auto const& pair : frequencyMap) {
        if(pair.second==n){
            return pair.first;
        }
    }
    return -1;
    }
};