class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        total = 0
        m = len(grid)
        n = len(grid[0])
        for i in range(m):
            for j in range(n):
                total += grid[i][j]
        for _ in range(2):
            sum_val = 0
            m = len(grid)
            n = len(grid[0])
            for i in range(m - 1):
                for j in range(n):
                    sum_val += grid[i][j]
                if sum_val * 2 == total:
                    return True
            grid = self.rotation(grid)
        return False

    def rotation(self, grid: List[List[int]]) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        tmp = [[0] * m for _ in range(n)]
        for i in range(m):
            for j in range(n):
                tmp[j][m - 1 - i] = grid[i][j]
        return tmp
