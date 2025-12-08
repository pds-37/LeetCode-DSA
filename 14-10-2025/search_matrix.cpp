#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] > target) col--;
        else row++;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10,11,16,20},
        {23,30,34,60}
    };
    cout << (searchMatrix(mat, 3) ? "true" : "false") << "\n"; // true
    cout << (searchMatrix(mat, 13) ? "true" : "false") << "\n"; // false
    return 0;
}
