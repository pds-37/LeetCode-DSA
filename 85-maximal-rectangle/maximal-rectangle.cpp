class Solution {
public:
    
    int largestRectangleHistogram(vector<int>& height) {
        stack<int> st;
        int maxArea = 0;
        
        height.push_back(0); // Sentinel
        
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] < height[st.top()]) {
                int h = height[st.top()];
                st.pop();
                
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                    
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        
        height.pop_back();
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> height(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            
            maxArea = max(maxArea, largestRectangleHistogram(height));
        }
        
        return maxArea;
    }
};
