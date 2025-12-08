#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x): val(x), left(nullptr), right(nullptr) {} };

void helper(TreeNode* root, vector<int>& list) {
    if (!root) return;
    list.push_back(root->val);
    helper(root->left, list);
    helper(root->right, list);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> list;
    helper(root, list);
    return list;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> list;
    helper(root, list);
    return list;
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> list;
    helper(root, list);
    return list;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    auto res = preorderTraversal(root);
    for (int x : res) cout << x << " "; // expected 1 2 3
    cout << "\n";
    return 0;
}
