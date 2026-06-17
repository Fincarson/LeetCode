class Solution:
    # Direction vectors for up, down, left, right movement
    _DIRS = [(0, 1), (0, -1), (-1, 0), (1, 0)]

    def getFood(self, grid: list[list[str]]) -> int:
        rows, cols = len(grid), len(grid[0])
        start = None
        foods = []

        # Find starting position and all food locations
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "*":
                    start = [r, c]
                elif grid[r][c] == "#":
                    foods.append([r, c])

        if not foods:
            return -1

        # Track visited cells to avoid cycles
        seen = set()

        # Priority queue stores: (estimated total cost, steps taken, row, col)
        pq = [
            (self._calc_dist(start[0], start[1], foods), 0, start[0], start[1])
        ]

        while pq:
            est_cost, steps, r, c = heapq.heappop(pq)

            # Try all four directions
            for dr, dc in self._DIRS:
                new_r, new_c = r + dr, c + dc

                if (
                    not self._is_valid(grid, new_r, new_c)
                    or (new_r, new_c) in seen
                ):
                    continue

                # If food found, return total steps taken
                if grid[new_r][new_c] == "#":
                    return steps + 1

                seen.add((new_r, new_c))
                # Calculate new Manhattan distance estimate
                new_est = self._calc_dist(new_r, new_c, foods)
                heapq.heappush(
                    pq, (new_est + steps + 1, steps + 1, new_r, new_c)
                )

        return -1

    # Calculate Manhattan distance to nearest food
    def _calc_dist(self, r: int, c: int, foods: list[list[int]]) -> int:
        return min(abs(food[0] - r) + abs(food[1] - c) for food in foods)

    # Check if position is within grid bounds and not an obstacle
    def _is_valid(self, grid: list[list[str]], r: int, c: int) -> bool:
        return (
            0 <= r < len(grid) and 0 <= c < len(grid[0]) and grid[r][c] != "X"
        )
