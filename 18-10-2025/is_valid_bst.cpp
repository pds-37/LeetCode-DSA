#include <bits/stdc++.h>
using namespace std;
struct TreeNode { long long val; TreeNode *left, *right; TreeNode(long long x): val(x), left(nullptr), right(nullptr) {} };

bool validate(TreeNode* node, long long minV, long long maxV) {
    if (!node) return true;
    if (node->val <= minV || node->val >= maxV) return false;
    return validate(node->left, minV, node->val) && validate(node->right, node->val, maxV);
}

bool isValidBST(TreeNode* root) {
    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << (isValidBST(root) ? "true" : "false") << "\n"; // true
    root->right->val = 0;
    cout << (isValidBST(root) ? "true" : "false") << "\n"; // false
    return 0;
}
