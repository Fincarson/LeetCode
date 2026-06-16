class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        below_row = triangle[-1]
        n = len(triangle)
        for row in reversed(range(n - 1)):
            curr_row = []
            for col in range(row + 1):
                smallest_below = min(below_row[col], below_row[col + 1])
                curr_row.append(triangle[row][col] + smallest_below)
            below_row = curr_row
        return below_row[0]
