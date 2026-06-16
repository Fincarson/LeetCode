# 2852. Sum of Remoteness of All Cells

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/sum-of-remoteness-of-all-cells/)  
`Array` `Hash Table` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 2852 - Sum of Remoteness of All Cells](https://leetcode.com/problems/sum-of-remoteness-of-all-cells/)

## Problem

You are given a 0-indexed matrix grid of order n * n. Each cell in this matrix has a value grid[i][j], which is either a positive integer or -1 representing a blocked cell.

You can move from a non-blocked cell to any non-blocked cell that shares an edge.

For any cell (i, j), we represent its remoteness as R[i][j] which is defined as the following:

- If the cell (i, j) is a non-blocked cell, R[i][j] is the sum of the values grid[x][y] such that there is no path from the non-blocked cell (x, y) to the cell (i, j).
- For blocked cells, R[i][j] == 0.

Return the sum of R[i][j] over all cells.

### Example 1

```text
Input: grid = [[-1,1,-1],[5,-1,4],[-1,3,-1]]
Output: 39
Explanation: In the picture above, there are four grids. The top-left grid contains the initial values in the grid. Blocked cells are colored black, and other cells get their values as it is in the input. In the top-right grid, you can see the value of R[i][j] for all cells. So the answer would be the sum of them. That is: 0 + 12 + 0 + 8 + 0 + 9 + 0 + 10 + 0 = 39.
Let's jump on the bottom-left grid in the above picture and calculate R[0][1] (the target cell is colored green). We should sum up the value of cells that can't be reached by the cell (0, 1). These cells are colored yellow in this grid. So R[0][1] = 5 + 4 + 3 = 12.
Now let's jump on the bottom-right grid in the above picture and calculate R[1][2] (the target cell is colored green). We should sum up the value of cells that can't be reached by the cell (1, 2). These cells are colored yellow in this grid. So R[1][2] = 1 + 5 + 3 = 9.
```

### Example 2

```text
Input: grid = [[-1,3,4],[-1,-1,-1],[3,-1,-1]]
Output: 13
Explanation: In the picture above, there are four grids. The top-left grid contains the initial values in the grid. Blocked cells are colored black, and other cells get their values as it is in the input. In the top-right grid, you can see the value of R[i][j] for all cells. So the answer would be the sum of them. That is: 3 + 3 + 0 + 0 + 0 + 0 + 7 + 0 + 0 = 13.
Let's jump on the bottom-left grid in the above picture and calculate R[0][2] (the target cell is colored green). We should sum up the value of cells that can't be reached by the cell (0, 2). This cell is colored yellow in this grid. So R[0][2] = 3.
Now let's jump on the bottom-right grid in the above picture and calculate R[2][0] (the target cell is colored green). We should sum up the value of cells that can't be reached by the cell (2, 0). These cells are colored yellow in this grid. So R[2][0] = 3 + 4 = 7.
```

### Example 3

```text
Input: grid = [[1]]
Output: 0
Explanation: Since there are no other cells than (0, 0), R[0][0] is equal to 0. So the sum of R[i][j] over all cells would be 0.
```

## Constraints

- 1 <= n <= 300
- 1 <= grid[i][j] <= 106 or grid[i][j] == -1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2852. Sum of Remoteness of All Cells

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Depth-First Search (DFS) | C++, Java, Python3 |
| Breadth-First Search (BFS) | C++, Java, Python3 |
| Disjoint Set Union (Union-Find) | C++, Java, Python3 |

## Approach 1: Depth-First Search (DFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Direction arrays for moving up, down, left, right
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();
        // Calculate total sum of all non-blocked cells
        long long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    // arr[0] = sum of reachable cells
                    // arr[1] = count of reachable cells
                    vector<long long> arr(2, 0);
                    dfs(grid, row, col, arr);

                    // For each reachable cell, add unreachable sum to result
                    // unreachable sum = totalSum - sum of reachable cells
                    result += (totalSum - arr[0]) * arr[1];
                }
            }
        }
        return result;
    }

private:
    // DFS to find sum and count of all cells reachable from (row, col)
    void dfs(vector<vector<int>>& grid, int row, int col,
             vector<long long>& arr) {
        arr[0] += grid[row][col];  // Add current cell value to sum
        arr[1]++;                  // Increment reachable cells count
        grid[row][col] = -1;       // Mark as visited

        // Explore all 4 directions
        for (auto& d : dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            if (isValid(grid, newRow, newCol)) {
                dfs(grid, newRow, newCol, arr);
            }
        }
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction arrays for moving up, down, left, right
    private final int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public long sumRemoteness(int[][] grid) {
        int n = grid.length;
        // Calculate total sum of all non-blocked cells
        long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    // arr[0] = sum of reachable cells
                    // arr[1] = count of reachable cells
                    long[] arr = new long[2];
                    dfs(grid, row, col, arr);

                    // For each reachable cell, add unreachable sum to result
                    // unreachable sum = totalSum - sum of reachable cells
                    result += (totalSum - arr[0]) * arr[1];
                }
            }
        }
        return result;
    }

    // DFS to find sum and count of all cells reachable from (row, col)
    private void dfs(int[][] grid, int row, int col, long[] arr) {
        arr[0] += grid[row][col]; // Add current cell value to sum
        arr[1]++; // Increment reachable cells count
        grid[row][col] = -1; // Mark as visited

        // Explore all 4 directions
        for (int[] d : dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            if (isValid(grid, newRow, newCol)) {
                dfs(grid, newRow, newCol, arr);
            }
        }
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    private boolean isValid(int[][] grid, int row, int col) {
        int n = grid.length;
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
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
                    # arr[0] = sum of reachable cells
                    # arr[1] = count of reachable cells
                    arr = [0, 0]
                    self._dfs(grid, row, col, arr)
                    result += (total_sum - arr[0]) * arr[1]

        return result

    # DFS to find sum and count of all cells reachable from (row, col)
    def _dfs(
        self, grid: list[list[int]], row: int, col: int, arr: list
    ) -> None:
        arr[0] += grid[row][col]  # Add current cell value to sum
        arr[1] += 1  # Increment reachable cells count
        grid[row][col] = -1  # Mark as visited

        # Explore all 4 directions
        for di, dj in self.dir:
            new_row, new_col = row + di, col + dj
            if self._is_valid(grid, new_row, new_col):
                self._dfs(grid, new_row, new_col, arr)

    # Checks if cell (row, col) is within grid bounds and not blocked/visited
    def _is_valid(self, grid: list[list[int]], row: int, col: int) -> bool:
        n = len(grid)
        return 0 <= row < n and 0 <= col < n and grid[row][col] > 0
```

</details>

<br>

## Approach 2: Breadth-First Search (BFS)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Direction arrays for moving up, down, left, right
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();
        // Calculate total sum of all non-blocked cells
        long long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    result += bfs(grid, row, col, totalSum);
                }
            }
        }
        return result;
    }

private:
    // BFS to find sum and count of all cells reachable from (row, col)
    long long bfs(vector<vector<int>>& grid, int row, int col,
                  long long totalSum) {
        // Sum of values in current component
        long long compSum = grid[row][col];
        long long compSize = 1;  // Number of cells in component
        grid[row][col] = -1;     // Mark as visited

        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            // Explore all 4 directions
            for (auto& d : dir) {
                int newRow = curr.first + d[0];
                int newCol = curr.second + d[1];
                if (isValid(grid, newRow, newCol)) {
                    q.push({newRow, newCol});
                    compSum += grid[newRow][newCol];
                    compSize++;
                    grid[newRow][newCol] = -1;  // Mark as visited
                }
            }
        }
        // Return remoteness value for this component
        return (totalSum - compSum) * compSize;
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction arrays for moving up, down, left, right
    private final int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public long sumRemoteness(int[][] grid) {
        int n = grid.length;
        // Calculate total sum of all non-blocked cells
        long totalSum = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] != -1) {
                    totalSum += grid[row][col];
                }
            }
        }

        // Calculate remoteness for each non-blocked cell
        long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] > 0) {
                    result += bfs(grid, row, col, totalSum);
                }
            }
        }
        return result;
    }

    // BFS to find sum and count of all cells reachable from (row, col)
    private long bfs(int[][] grid, int row, int col, long totalSum) {
        long compSum = grid[row][col]; // Sum of values in current component
        long compSize = 1; // Number of cells in component
        grid[row][col] = -1; // Mark as visited

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[] { row, col });

        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            // Explore all 4 directions
            for (int[] d : dir) {
                int newRow = d[0] + curr[0];
                int newCol = d[1] + curr[1];
                if (isValid(grid, newRow, newCol)) {
                    queue.add(new int[] { newRow, newCol });
                    compSum += grid[newRow][newCol];
                    compSize++;
                    grid[newRow][newCol] = -1; // Mark as visited
                }
            }
        }
        // Return remoteness value for this component
        return (totalSum - compSum) * compSize;
    }

    // Checks if cell (row, col) is within grid bounds and not blocked/visited
    private boolean isValid(int[][] grid, int row, int col) {
        int n = grid.length;
        return row >= 0 && col >= 0 && row < n && col < n && grid[row][col] > 0;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
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
```

</details>

<br>

## Approach 3: Disjoint Set Union (Union-Find)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    // Direction arrays for moving up, down, left, right
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size();
        // Initialize Union-Find data structure with size n*n
        UnionFind uf(n);

        // First pass: Connect all adjacent non-blocked cells into components
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                // Skip blocked cells
                if (grid[row][col] == -1) continue;

                // For each valid cell, check all 4 adjacent cells
                for (auto& d : dir) {
                    int newRow = d[0] + row;
                    int newCol = d[1] + col;
                    // If adjacent cell is valid, connect it to current cell
                    if (isValid(grid, newRow, newCol)) {
                        // Convert 2D coordinates to 1D index and union them
                        uf.unite(getIndex(n, row, col),
                                 getIndex(n, newRow, newCol));
                    }
                }
            }
        }

        // Second pass: Calculate sum of values in each connected component
        long long totalSum = 0;
        // Maps component root to its sum
        unordered_map<int, long long> compSum;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Find the root of current cell's component
                int parent = uf.find(getIndex(n, row, col));
                // Add current cell's value to its component sum
                compSum[parent] += grid[row][col];
                // Add to total sum of all values
                totalSum += grid[row][col];
            }
        }

        // Third pass: Calculate remoteness sum
        // For each cell, remoteness = (totalSum - sum of its component)
        long long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Get sum of current cell's component
                long long currCompSum = compSum[uf.find(getIndex(n, row, col))];

                result += totalSum - currCompSum;
            }
        }
        return result;
    }

    // UnionFind class to track connected components
    class UnionFind {
    private:
        vector<int> parent;  // parent[i] = -1 means i is a root
        vector<int> rank;

    public:
        UnionFind(int n) {
            parent.resize(n * n, -1);
            rank.resize(n * n, 1);
        }

        // Find with path compression for better amortized performance
        int find(int index) {
            if (parent[index] == -1) return index;
            return parent[index] = find(parent[index]);
        }

        // Union by linking roots directly
        void unite(int idx1, int idx2) {
            int root1 = find(idx1);
            int root2 = find(idx2);

            if (root1 == root2) return;  // Already in same component

            // Make the root with the higher rank the parent of the other root
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    };

    // Converts 2D coordinates to 1D index
    int getIndex(int n, int row, int col) { return row * n + col; }

    // Checks if cell (row, col) is within grid bounds and not blocked
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        return row >= 0 && col >= 0 && row < n && col < n &&
               grid[row][col] != -1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Direction arrays for moving up, down, left, right
    private final int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    public long sumRemoteness(int[][] grid) {
        int n = grid.length;
        // Initialize Union-Find data structure with size n*n
        UnionFind uf = new UnionFind(n);

        // First pass: Connect all adjacent non-blocked cells into components
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                // Skip blocked cells
                if (grid[row][col] == -1) continue;

                // For each valid cell, check all 4 adjacent cells
                for (int[] d : dir) {
                    int newRow = d[0] + row;
                    int newCol = d[1] + col;
                    // If adjacent cell is valid, connect it to current cell
                    if (isValid(grid, newRow, newCol)) {
                        // Convert 2D coordinates to 1D index and union them
                        uf.union(
                            getIndex(n, row, col),
                            getIndex(n, newRow, newCol)
                        );
                    }
                }
            }
        }

        // Second pass: Calculate sum of values in each connected component
        long totalSum = 0;
        // Maps component root to its sum
        Map<Integer, Long> compSum = new HashMap<>();
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Find the root of current cell's component
                int parent = uf.find(getIndex(n, row, col));
                // Add current cell's value to its component sum
                compSum.put(
                    parent,
                    compSum.getOrDefault(parent, 0L) + grid[row][col]
                );
                // Add to total sum of all values
                totalSum += grid[row][col];
            }
        }

        // Third pass: Calculate remoteness sum
        // For each cell, remoteness = (totalSum - sum of its component)
        long result = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == -1) continue;

                // Get sum of current cell's component
                long currCompSum = compSum.get(uf.find(getIndex(n, row, col)));

                result += totalSum - currCompSum;
            }
        }
        return result;
    }

    // UnionFind class to track connected components
    private class UnionFind {

        int[] parent; // parent[i] = -1 means i is a root
        int[] rank;

        UnionFind(int n) {
            parent = new int[n * n];
            rank = new int[n * n];
            // Initialize all cells as individual components
            Arrays.fill(parent, -1);
            Arrays.fill(rank, 1);
        }

        // Find with path compression for better amortized performance
        int find(int index) {
            if (parent[index] == -1) return index;
            return parent[index] = find(parent[index]);
        }

        // Union by linking roots by rank
        void union(int idx1, int idx2) {
            int root1 = find(idx1);
            int root2 = find(idx2);

            if (root1 == root2) return; // Already in same component

            // Make the root with the higher rank the parent of the other root
            if (rank[root1] < rank[root2]) {
                parent[root1] = root2;
            } else if (rank[root1] > rank[root2]) {
                parent[root2] = root1;
            } else {
                parent[root2] = root1;
                rank[root1]++;
            }
        }
    }

    // Converts 2D coordinates to 1D index
    private int getIndex(int n, int row, int col) {
        return row * n + col;
    }

    // Checks if cell (row, col) is within grid bounds and not blocked
    private boolean isValid(int[][] grid, int row, int col) {
        int n = grid.length;
        return (
            row >= 0 && col >= 0 && row < n && col < n && grid[row][col] != -1
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def sumRemoteness(self, grid: list[list[int]]) -> int:
        # Direction arrays for moving up, down, left, right
        self.dir = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        n = len(grid)

        # Initialize Union-Find data structure with size n*n
        uf = self._UnionFind(n)

        # First pass: Connect all adjacent non-blocked cells into components
        for row in range(n):
            for col in range(n):
                # Skip blocked cells
                if grid[row][col] == -1:
                    continue

                # For each valid cell, check all 4 adjacent cells
                for di, dj in self.dir:
                    new_row, new_col = row + di, col + dj
                    # If adjacent cell is valid, connect it to current cell
                    if self._is_valid(grid, new_row, new_col):
                        # Convert 2D coordinates to 1D index and union them
                        uf.union(
                            self._get_index(n, row, col),
                            self._get_index(n, new_row, new_col),
                        )

        # Second pass: Calculate sum of values in each connected component
        comp_sum = {}  # Maps component root to its sum
        total_sum = 0

        for row in range(n):
            for col in range(n):
                if grid[row][col] == -1:
                    continue

                # Find the root of current cell's component
                parent = uf.find(self._get_index(n, row, col))
                # Add current cell's value to its component sum
                comp_sum[parent] = comp_sum.get(parent, 0) + grid[row][col]
                total_sum += grid[row][col]

        # Third pass: Calculate remoteness sum
        # For each cell, remoteness = (total_sum - sum of its component)
        result = sum(
            total_sum - comp_sum[uf.find(self._get_index(n, row, col))]
            for row in range(n)
            for col in range(n)
            if grid[row][col] != -1
        )

        return result

    class _UnionFind:
        def __init__(self, n: int):
            # Initialize all cells as individual components
            self.parent = [-1] * (n * n)
            self.rank = [1] * (n * n)

        def find(self, index: int) -> int:
            # Find with path compression for better performance
            if self.parent[index] == -1:
                return index
            self.parent[index] = self.find(self.parent[index])
            return self.parent[index]

        def union(self, idx1: int, idx2: int):
            # Union by linking roots directly
            root1 = self.find(idx1)
            root2 = self.find(idx2)

            if root1 == root2:  # Already in same component
                return

            # Make the root with the higher rank the parent of the other root
            if self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            elif self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

    def _get_index(self, n: int, row: int, col: int) -> int:
        # Converts 2D coordinates to 1D index
        return row * n + col

    def _is_valid(self, grid: list[list[int]], row: int, col: int) -> bool:
        # Checks if cell (row, col) is within grid bounds and not blocked
        n = len(grid)
        return 0 <= row < n and 0 <= col < n and grid[row][col] != -1
```

</details>
