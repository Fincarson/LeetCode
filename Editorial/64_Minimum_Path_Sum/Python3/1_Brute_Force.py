class Solution:
    def calculate(self, grid: List[List[int]], i: int, j: int) -> int:
        if i == len(grid) or j == len(grid[0]):
            return float("inf")
        if i == len(grid) - 1 and j == len(grid[0]) - 1:
            return grid[i][j]
        return grid[i][j] + min(
            self.calculate(grid, i + 1, j), self.calculate(grid, i, j + 1)
        )

    def minPathSum(self, grid: List[List[int]]) -> int:
        return self.calculate(grid, 0, 0)
