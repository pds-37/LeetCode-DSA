#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) {
    vector<int> list;
    if (matrix.empty()) return list;
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) list.push_back(matrix[top][i]);
        top++;
        for (int i = top; i <= bottom; ++i) list.push_back(matrix[i][right]);
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) list.push_back(matrix[bottom][i]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) list.push_back(matrix[i][left]);
            left++;
        }
    }
    return list;
}

int main() {
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> res = spiralOrder(mat);
    for (int x : res) cout << x << " ";
    cout << "\n"; // expected 1 2 3 6 9 8 7 4 5
    return 0;
}
