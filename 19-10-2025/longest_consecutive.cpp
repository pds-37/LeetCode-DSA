#include <bits/stdc++.h>
using namespace std;

// Find length of longest consecutive sequence (O(n) using hash set)
int longestConsecutive(const vector<int>& nums) {
    if (nums.empty()) return 0;
    unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int num : s) {
        // only start counting at sequence starts
        if (!s.count(num - 1)) {
            int cur = num;
            int len = 1;
            while (s.count(cur + 1)) {
                cur++;
                ++len;
            }
            best = max(best, len);
        }
    }
    return best;
}

int main() {
    cout << longestConsecutive({100, 4, 200, 1, 3, 2}) << "\n"; // expected 4 (1,2,3,4)
    cout << longestConsecutive({0,3,7,2,5,8,4,6,0,1}) << "\n"; // expected 9 (0..8)
    return 0;
}
