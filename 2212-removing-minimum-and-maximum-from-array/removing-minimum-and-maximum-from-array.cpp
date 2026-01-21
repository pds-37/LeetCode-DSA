class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }

        // Ensure minIdx < maxIdx
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        int front = maxIdx + 1;
        int back = n - minIdx;
        int mixed = (minIdx + 1) + (n - maxIdx);

        return min({front, back, mixed});
    }
};
