class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        
        # 1. Build the 2D Prefix Sum Array (1-based indexing for easier boundary handling)
        # P[i][j] stores the sum of the rectangle from (0,0) to (i-1, j-1)
        P = [[0] * (n + 1) for _ in range(m + 1)]
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                P[i][j] = (P[i-1][j] + P[i][j-1] - P[i-1][j-1] + mat[i-1][j-1])
        
        max_len = 0
        
        # 2. Iterate through the matrix
        # 'i' and 'j' represent the bottom-right corner of a potential square
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # We only try to extend the side length by 1.
                # If we find a valid square of size (max_len + 1), we increment max_len.
                target_len = max_len + 1
                
                # Check if a square of size 'target_len' fits within the boundaries ending at (i, j)
                if i >= target_len and j >= target_len:
                    # Calculate sum using the inclusion-exclusion principle
                    r1 = i - target_len
                    c1 = j - target_len
                    
                    current_sum = (P[i][j] 
                                   - P[r1][j] 
                                   - P[i][c1] 
                                   + P[r1][c1])
                    
                    if current_sum <= threshold:
                        max_len += 1
                        
        return max_len