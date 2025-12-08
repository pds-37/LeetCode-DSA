#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; TreeNode *left, *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

// compute diameter (number of edges in longest path)
int diameterAns = 0;
int height(TreeNode* root) {
    if (!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    diameterAns = max(diameterAns, lh + rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    diameterAns = 0;
    height(root);
    return diameterAns;
}

int main() {
    // build tree: [1,2,3,4,5] sample
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Diameter: " << diameterOfBinaryTree(root) << "\n"; // expected 3
    return 0;
}
