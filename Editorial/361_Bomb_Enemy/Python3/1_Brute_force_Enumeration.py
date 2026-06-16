class Solution:
    def maxKilledEnemies(self, grid: List[List[str]]) -> int:
        if len(grid) == 0:
            return 0

        rows, cols = len(grid), len(grid[0])

        def killEnemies(row, col):
            enemy_count = 0
            row_ranges = [range(row - 1, -1, -1), range(row + 1, rows, 1)]
            for row_range in row_ranges:
                for r in row_range:
                    if grid[r][col] == 'W':
                        break
                    elif grid[r][col] == 'E':
                        enemy_count += 1

            col_ranges = [range(col - 1, -1, -1), range(col + 1, cols, 1)]
            for col_range in col_ranges:
                for c in col_range:
                    if grid[row][c] == 'W':
                        break
                    elif grid[row][c] == 'E':
                        enemy_count += 1

            return enemy_count

        max_count = 0
        for row in range(0, rows):
            for col in range(0, cols):
                if grid[row][col] == '0':
                    max_count = max(max_count, killEnemies(row, col))

        return max_count
