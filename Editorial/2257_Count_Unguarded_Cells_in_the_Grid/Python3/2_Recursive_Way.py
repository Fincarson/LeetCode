class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3

    # Depth-First Search to mark guarded cells
    def _recurse(
        self, row: int, col: int, grid: List[List[int]], direction: str
    ) -> None:
        if (
            row < 0
            or row >= len(grid)
            or col < 0
            or col >= len(grid[0])
            or grid[row][col] == self.GUARD
            or grid[row][col] == self.WALL
        ):
            return

        grid[row][col] = self.GUARDED  # Mark cell as guarded
        if direction == "U":
            self._recurse(row - 1, col, grid, "U")  # Up
        if direction == "D":
            self._recurse(row + 1, col, grid, "D")  # Down
        if direction == "L":
            self._recurse(row, col - 1, grid, "L")  # Left
        if direction == "R":
            self._recurse(row, col + 1, grid, "R")  # Right

    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        grid = [[self.UNGUARDED] * n for _ in range(m)]

        # Mark guards' positions
        for guard in guards:
            grid[guard[0]][guard[1]] = self.GUARD

        # Mark walls' positions
        for wall in walls:
            grid[wall[0]][wall[1]] = self.WALL

        # Mark cells as guarded by traversing from each guard
        for guard in guards:
            self._recurse(guard[0] - 1, guard[1], grid, "U")  # Up
            self._recurse(guard[0] + 1, guard[1], grid, "D")  # Down
            self._recurse(guard[0], guard[1] - 1, grid, "L")  # Left
            self._recurse(guard[0], guard[1] + 1, grid, "R")  # Right

        # Count unguarded cells
        count = sum(row.count(self.UNGUARDED) for row in grid)
        return count
