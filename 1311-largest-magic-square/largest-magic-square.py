class Solution:
    def largestMagicSquare(self, grid: list[list[int]]) -> int:
        m, n = len(grid), len(grid[0])
        
        # Helper function to check if a specific k x k subgrid is a magic square
        def is_magic(r, c, k):
            # Calculate the target sum using the first row
            target = sum(grid[r][c : c + k])
            
            # Check rows
            for i in range(r + 1, r + k):
                if sum(grid[i][c : c + k]) != target:
                    return False
            
            # Check columns
            for j in range(c, c + k):
                col_sum = 0
                for i in range(r, r + k):
                    col_sum += grid[i][j]
                if col_sum != target:
                    return False
            
            # Check diagonals
            d1 = sum(grid[r + i][c + i] for i in range(k))
            d2 = sum(grid[r + i][c + k - 1 - i] for i in range(k))
            
            if d1 != target or d2 != target:
                return False
                
            return True

        # Iterate from largest possible k down to 2
        for k in range(min(m, n), 1, -1):
            # Check every top-left position (i, j) that allows a k x k grid
            for i in range(m - k + 1):
                for j in range(n - k + 1):
                    if is_magic(i, j, k):
                        return k
                        
        return 1