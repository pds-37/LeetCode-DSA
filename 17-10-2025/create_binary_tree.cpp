#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

// descriptions: vector of {parent, child, isLeft(1) or isRight(0)}
TreeNode* createBinaryTree(const vector<vector<int>>& descriptions) {
    unordered_map<int, TreeNode*> mp;
    unordered_set<int> children;
    for (auto &d : descriptions) {
        int p = d[0], c = d[1], isLeft = d[2];
        if (!mp.count(p)) mp[p] = new TreeNode(p);
        if (!mp.count(c)) mp[c] = new TreeNode(c);
        if (isLeft == 1) mp[p]->left = mp[c];
        else mp[p]->right = mp[c];
        children.insert(c);
    }
    TreeNode* root = nullptr;
    for (auto &kv : mp) if (!children.count(kv.first)) { root = kv.second; break; }
    return root;
}

void preorder(TreeNode* r) {
    if (!r) return;
    cout << r->val << " ";
    preorder(r->left);
    preorder(r->right);
}

int main() {
    vector<vector<int>> desc = {
        {20,15,1},{20,17,0},{15,10,1}
    };
    TreeNode* root = createBinaryTree(desc);
    preorder(root); // expected preorder of the built tree (20 15 10 17)
    cout << "\n";
    return 0;
}
