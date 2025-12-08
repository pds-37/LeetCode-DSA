#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };

void dfsRight(TreeNode* root, int level, vector<int>& res) {
    if (!root) return;
    if (level == res.size()) res.push_back(root->val);
    dfsRight(root->right, level + 1, res);
    dfsRight(root->left, level + 1, res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    dfsRight(root, 0, res);
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> view = rightSideView(root);
    for (int v : view) cout << v << " "; // expected 1 3 4
    cout << "\n";
    return 0;
}

