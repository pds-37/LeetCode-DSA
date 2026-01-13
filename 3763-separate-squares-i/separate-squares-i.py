class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        # Total area of all squares
        total_area = sum(l * l for _, _, l in squares)
        half_area = total_area / 2.0

        # Binary search range for y
        low = min(y for _, y, _ in squares)
        high = max(y + l for _, y, l in squares)

        # Function to compute area below a horizontal line at height y
        def area_below(y):
            area = 0.0
            for _, yi, li in squares:
                if y <= yi:
                    continue
                elif y >= yi + li:
                    area += li * li
                else:
                    area += li * (y - yi)
            return area

        # Binary search with sufficient precision
        for _ in range(60):  # enough for 1e-5 accuracy
            mid = (low + high) / 2.0
            if area_below(mid) < half_area:
                low = mid
            else:
                high = mid

        return (low + high) / 2.0
