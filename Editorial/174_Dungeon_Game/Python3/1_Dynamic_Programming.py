class Solution(object):
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows, cols = len(dungeon), len(dungeon[0])
        dp = [[float("inf")] * cols for _ in range(rows)]

        def get_min_health(currCell: int, nextRow: int, nextCol: int) -> float:
            if nextRow >= rows or nextCol >= cols:
                return float("inf")
            nextCell = dp[nextRow][nextCol]
            # hero needs at least 1 point to survive
            return max(1, nextCell - currCell)

        for row in reversed(range(rows)):
            for col in reversed(range(cols)):
                currCell = dungeon[row][col]

                right_health = get_min_health(currCell, row, col + 1)
                down_health = get_min_health(currCell, row + 1, col)
                next_health = min(right_health, down_health)

                if next_health != float("inf"):
                    min_health = next_health
                else:
                    min_health = 1 if currCell >= 0 else (1 - currCell)

                dp[row][col] = min_health

        return dp[0][0]
