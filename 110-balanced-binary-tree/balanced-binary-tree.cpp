/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int HeightOfTree(TreeNode*root,bool & valid){
        if(root==NULL)return 0;

        int left= HeightOfTree(root->left,valid);
        int right= HeightOfTree(root->right,valid);

        if(abs(left-right)>1){
            valid=0;
            
        }
        return 1+(max(left,right));
    }

    bool isBalanced(TreeNode* root) {

        if(root==NULL)return 1;
        bool valid=1;

        HeightOfTree(root,valid);

        return valid;

    }
};