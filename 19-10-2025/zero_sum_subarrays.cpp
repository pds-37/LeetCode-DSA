#include <bits/stdc++.h>
using namespace std;


long long countZeroSumSubarrays(const vector<int>& arr) {
    unordered_map<int,int> freq; 
    long long count = 0;
    int sum = 0;
    for (int x : arr) {
        sum += x;
        if (sum == 0) count++;                  
        if (freq.find(sum) != freq.end()) {
            count += freq[sum];                 
        }
        freq[sum]++;                           
    }
    return count;
}

int main() {
    cout << countZeroSumSubarrays({1, -1, 2, -2, 3, -3}) << "\n"; 
    cout << countZeroSumSubarrays({0,0,0}) << "\n"; 
    cout << countZeroSumSubarrays({1,2,3}) << "\n"; 
    return 0;
}
