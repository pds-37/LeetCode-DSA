class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = INT_MIN;
        int maxLevelIndex = 1; // Stores the final answer
        int currentLevel = 1;  // Tracks current level during BFS
        
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            long long currentLevelSum = 0; // Use long long for potential overflow

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                currentLevelSum += current->val;

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }

            // Update only if we find a STRICTLY greater sum
            // This ensures we keep the smallest level index for ties
            if (currentLevelSum > maxSum) {
                maxSum = (int)currentLevelSum;
                maxLevelIndex = currentLevel;
            }
            
            currentLevel++;
        }
        
        return maxLevelIndex;
    }
};
