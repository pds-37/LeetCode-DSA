class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long absSum = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                absSum += abs(x);
                if (x < 0) negCount++;
                minAbs = min(minAbs, abs(x));
            }
        }

        if (negCount % 2 == 0)
            return absSum;
        else
            return absSum - 2LL * minAbs;
    }
};
