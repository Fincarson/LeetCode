# 2257. Count Unguarded Cells in the Grid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2257 - Count Unguarded Cells in the Grid](https://leetcode.com/problems/count-unguarded-cells-in-the-grid/)

## Problem

You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

Return the number of unoccupied cells that are not guarded.

### Example 1

```text
Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.
```

### Example 2

```text
Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.
```

## Constraints

- 1 <= m, n <= 105
- 2 <= m * n <= 105
- 1 <= guards.length, walls.length <= 5 * 104
- 2 <= guards.length + walls.length <= m * n
- guards[i].length == walls[j].length == 2
- 0 <= rowi, rowj < m
- 0 <= coli, colj < n
- All the positions in guards and walls are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Bomb Enemy](https://leetcode.com/problems/bomb-enemy/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Available Captures for Rook](https://leetcode.com/problems/available-captures-for-rook/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2257. Count Unguarded Cells in the Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iterative Simulation | C++, Java, Python3 |
| Recursive Way | C++, Java, Python3 |
| Visibility Axis | C++, Java, Python3 |

## Approach 1: Iterative Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markguarded(int row, int col, vector<vector<int>>& grid) {
        // Traverse upwards
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse downwards
        for (int r = row + 1; r < grid.size(); r++) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse leftwards
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
        // Traverse rightwards
        for (int c = col + 1; c < grid[row].size(); c++) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            markguarded(guard[0], guard[1], grid);
        }

        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int UNGUARDED = 0;
    private static final int GUARDED = 1;
    private static final int GUARD = 2;
    private static final int WALL = 3;

    public void markguarded(int row, int col, int[][] grid) {
        // Traverse upwards
        for (int r = row - 1; r >= 0; r--) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse downwards
        for (int r = row + 1; r < grid.length; r++) {
            if (grid[r][col] == WALL || grid[r][col] == GUARD) break;
            grid[r][col] = GUARDED;
        }
        // Traverse leftwards
        for (int c = col - 1; c >= 0; c--) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
        // Traverse rightwards
        for (int c = col + 1; c < grid[0].length; c++) {
            if (grid[row][c] == WALL || grid[row][c] == GUARD) break;
            grid[row][c] = GUARDED;
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        // Mark guards' positions
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (int[] guard : guards) {
            markguarded(guard[0], guard[1], grid);
        }

        // Count unguarded cells
        int count = 0;
        for (int[] row : grid) {
            for (int cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3

    def _mark_guarded(self, row: int, col: int, grid: List[List[int]]) -> None:
        # Traverse upwards
        for r in range(row - 1, -1, -1):
            if grid[r][col] == self.WALL or grid[r][col] == self.GUARD:
                break
            grid[r][col] = self.GUARDED

        # Traverse downwards
        for r in range(row + 1, len(grid)):
            if grid[r][col] == self.WALL or grid[r][col] == self.GUARD:
                break
            grid[r][col] = self.GUARDED

        # Traverse leftwards
        for c in range(col - 1, -1, -1):
            if grid[row][c] == self.WALL or grid[row][c] == self.GUARD:
                break
            grid[row][c] = self.GUARDED

        # Traverse rightwards
        for c in range(col + 1, len(grid[0])):
            if grid[row][c] == self.WALL or grid[row][c] == self.GUARD:
                break
            grid[row][c] = self.GUARDED

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
            self._mark_guarded(guard[0], guard[1], grid)

        # Count unguarded cells
        count = 0
        for row in grid:
            for cell in row:
                if cell == self.UNGUARDED:
                    count += 1

        return count
```

</details>

<br>

## Approach 2: Recursive Way

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void recurse(int row, int col, vector<vector<int>>& grid, char direction) {
        if (row < 0 || row >= grid.size() || col < 0 ||
            col >= grid[row].size() || grid[row][col] == GUARD ||
            grid[row][col] == WALL) {
            return;
        }
        grid[row][col] = GUARDED;  // Mark cell as guarded
        if (direction == 'U') recurse(row - 1, col, grid, 'U');  // Up
        if (direction == 'D') recurse(row + 1, col, grid, 'D');  // Down
        if (direction == 'L') recurse(row, col - 1, grid, 'L');  // Left
        if (direction == 'R') recurse(row, col + 1, grid, 'R');  // Right
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (const auto& guard : guards) {
            recurse(guard[0] - 1, guard[1], grid, 'U');  // Up
            recurse(guard[0] + 1, guard[1], grid, 'D');  // Down
            recurse(guard[0], guard[1] - 1, grid, 'L');  // Left
            recurse(guard[0], guard[1] + 1, grid, 'R');  // Right
        }

        // Count unguarded cells
        int count = 0;
        for (const auto& row : grid) {
            for (const auto& cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int UNGUARDED = 0;
    private static final int GUARDED = 1;
    private static final int GUARD = 2;
    private static final int WALL = 3;

    // Depth-First Search to mark guarded cells
    private void recurse(int row, int col, int[][] grid, char direction) {
        if (
            row < 0 ||
            row >= grid.length ||
            col < 0 ||
            col >= grid[0].length ||
            grid[row][col] == GUARD ||
            grid[row][col] == WALL
        ) {
            return;
        }
        grid[row][col] = GUARDED; // Mark cell as guarded
        if (direction == 'U') recurse(row - 1, col, grid, 'U'); // Up
        if (direction == 'D') recurse(row + 1, col, grid, 'D'); // Down
        if (direction == 'L') recurse(row, col - 1, grid, 'L'); // Left
        if (direction == 'R') recurse(row, col + 1, grid, 'R'); // Right
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        // Mark guards' positions
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Mark cells as guarded by traversing from each guard
        for (int[] guard : guards) {
            recurse(guard[0] - 1, guard[1], grid, 'U'); // Up
            recurse(guard[0] + 1, guard[1], grid, 'D'); // Down
            recurse(guard[0], guard[1] - 1, grid, 'L'); // Left
            recurse(guard[0], guard[1] + 1, grid, 'R'); // Right
        }

        // Count unguarded cells
        int count = 0;
        for (int[] row : grid) {
            for (int cell : row) {
                if (cell == UNGUARDED) count++;
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
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
```

</details>

<br>

## Approach 3: Visibility Axis

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Helper lambda to update visibility
        auto updateCellVisibility = [&](int row, int col,
                                        bool isGuardLineActive) -> bool {
            if (grid[row][col] == GUARD) {
                return true;
            }
            if (grid[row][col] == WALL) {
                return false;
            }
            if (isGuardLineActive) {
                grid[row][col] = GUARDED;
            }
            return isGuardLineActive;
        };

        // Horizontal passes
        for (int row = 0; row < m; row++) {
            bool isGuardLineActive = grid[row][0] == GUARD;
            for (int col = 1; col < n; col++) {
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
            }

            isGuardLineActive = grid[row][n - 1] == GUARD;
            for (int col = n - 2; col >= 0; col--) {
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
            }
        }

        // Vertical passes
        for (int col = 0; col < n; col++) {
            bool isGuardLineActive = grid[0][col] == GUARD;
            for (int row = 1; row < m; row++) {
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
            }

            isGuardLineActive = grid[m - 1][col] == GUARD;
            for (int row = m - 2; row >= 0; row--) {
                isGuardLineActive =
                    updateCellVisibility(row, col, isGuardLineActive);
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == UNGUARDED) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int UNGUARDED = 0;
    private static final int GUARDED = 1;
    private static final int GUARD = 2;
    private static final int WALL = 3;

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        // Create and initialize grid
        int[][] grid = new int[m][n];

        // Mark guards' positions
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        // Mark walls' positions
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = WALL;
        }

        // Horizontal passes
        for (int row = 0; row < m; row++) {
            // Left to right pass
            boolean isGuardLineActive = grid[row][0] == GUARD;
            for (int col = 1; col < n; col++) {
                isGuardLineActive = updateCellVisibility(
                    grid,
                    row,
                    col,
                    isGuardLineActive
                );
            }

            // Right to left pass
            isGuardLineActive = grid[row][n - 1] == GUARD;
            for (int col = n - 2; col >= 0; col--) {
                isGuardLineActive = updateCellVisibility(
                    grid,
                    row,
                    col,
                    isGuardLineActive
                );
            }
        }

        // Vertical passes
        for (int col = 0; col < n; col++) {
            // Top to bottom pass
            boolean isGuardLineActive = grid[0][col] == GUARD;
            for (int row = 1; row < m; row++) {
                isGuardLineActive = updateCellVisibility(
                    grid,
                    row,
                    col,
                    isGuardLineActive
                );
            }

            // Bottom to top pass
            isGuardLineActive = grid[m - 1][col] == GUARD;
            for (int row = m - 2; row >= 0; row--) {
                isGuardLineActive = updateCellVisibility(
                    grid,
                    row,
                    col,
                    isGuardLineActive
                );
            }
        }

        // Count unguarded cells
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == UNGUARDED) {
                    count++;
                }
            }
        }

        return count;
    }

    // Helper method to update cell visibility
    private boolean updateCellVisibility(
        int[][] grid,
        int row,
        int col,
        boolean isGuardLineActive
    ) {
        // If current cell is a guard, reactivate the guard line
        if (grid[row][col] == GUARD) {
            return true;
        }

        // If current cell is a wall, deactivate the guard line
        if (grid[row][col] == WALL) {
            return false;
        }

        // If guard line is active, mark cell as guarded
        if (isGuardLineActive) {
            grid[row][col] = GUARDED;
        }

        return isGuardLineActive;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    UNGUARDED = 0
    GUARDED = 1
    GUARD = 2
    WALL = 3

    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        grid = [[self.UNGUARDED] * n for _ in range(m)]

        # Mark guards' positions
        for row, col in guards:
            grid[row][col] = self.GUARD

        # Mark walls' positions
        for row, col in walls:
            grid[row][col] = self.WALL

        # Updates the visibility of a cell based on the current guard line state.
        def _updatecell_visibility(row, col, is_guard_line_active):
            # If current cell is a guard, reactivate the guard line
            if grid[row][col] == self.GUARD:
                return True

            # If current cell is a wall, deactivate the guard line
            if grid[row][col] == self.WALL:
                return False

            # If guard line is active, mark cell as guarded
            if is_guard_line_active:
                grid[row][col] = self.GUARDED
            return is_guard_line_active

        # Horizontal passes
        for row in range(m):
            is_guard_line_active = grid[row][0] == self.GUARD
            for col in range(1, n):
                is_guard_line_active = _updatecell_visibility(
                    row, col, is_guard_line_active
                )
            is_guard_line_active = grid[row][n - 1] == self.GUARD
            for col in range(n - 2, -1, -1):
                is_guard_line_active = _updatecell_visibility(
                    row, col, is_guard_line_active
                )

        # Vertical passes
        for col in range(n):
            is_guard_line_active = grid[0][col] == self.GUARD
            for row in range(1, m):
                is_guard_line_active = _updatecell_visibility(
                    row, col, is_guard_line_active
                )
            is_guard_line_active = grid[m - 1][col] == self.GUARD
            for row in range(m - 2, -1, -1):
                is_guard_line_active = _updatecell_visibility(
                    row, col, is_guard_line_active
                )

        # Count unguarded cells
        count = 0
        for row in range(m):
            for col in range(n):
                if grid[row][col] == self.UNGUARDED:
                    count += 1
        return count
```

</details>
