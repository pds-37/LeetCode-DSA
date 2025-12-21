class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansRow;
        long long ans = 1;   // use long long for safety
        ansRow.push_back(1);

        for (int i = 1; i <= rowIndex; i++) {
            ans = ans * (rowIndex - i + 1);
            ans = ans / i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};
