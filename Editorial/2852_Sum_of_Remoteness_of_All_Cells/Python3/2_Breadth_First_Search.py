class Solution:
    def sumRemoteness(self, grid: list[list[int]]) -> int:
        # Direction arrays for moving up, down, left, right
        self.dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        n = len(grid)

        # Calculate total sum of all non-blocked cells
        total_sum = sum(val for row in grid for val in row if val != -1)

        # Calculate remoteness for each non-blocked cell
        result = 0
        for row in range(n):
            for col in range(n):
                if grid[row][col] > 0:
                    result += self._bfs(grid, row, col, total_sum)

        return result

    # BFS to find sum and count of all cells reachable from (row, col)
    def _bfs(
        self, grid: list[list[int]], row: int, col: int, total_sum: int
    ) -> int:
        comp_sum = grid[row][col]  # Sum of values in current component
        comp_size = 1  # Number of cells in component
        grid[row][col] = -1  # Mark as visited

        queue = deque([(row, col)])
        while queue:
            curr_row, curr_col = queue.popleft()

            # Explore all 4 directions
            for di, dj in self.dir:
                new_row, new_col = curr_row + di, curr_col + dj
                if self._is_valid(grid, new_row, new_col):
                    queue.append((new_row, new_col))
                    comp_sum += grid[new_row][new_col]
                    comp_size += 1
                    grid[new_row][new_col] = -1  # Mark as visited

        # Return remoteness value for this component
        return (total_sum - comp_sum) * comp_size

    # Checks if cell (row, col) is within grid bounds and not blocked/visited
    def _is_valid(self, grid: list[list[int]], row: int, col: int) -> bool:
        n = len(grid)
        return 0 <= row < n and 0 <= col < n and grid[row][col] > 0
