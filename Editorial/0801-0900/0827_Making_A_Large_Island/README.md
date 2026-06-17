# 827. Making A Large Island

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/making-a-large-island/)  
`Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix`

**Problem Link:** [LeetCode 827 - Making A Large Island](https://leetcode.com/problems/making-a-large-island/)

## Problem

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

### Example 1

```text
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

### Example 2

```text
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

### Example 3

```text
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

## Constraints

- n == grid.length
- n == grid[i].length
- 1 <= n <= 500
- grid[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 827. Making A Large Island

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using DFS | C++, Java, Python3 |
| Using Disjoint Set Union (DSU) | C++, Java, Python3 |

## Approach 1: Using DFS

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                      int currentColumn) {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int largestIsland(int[][] grid) {
        Map<Integer, Integer> islandSizes = new HashMap<>();
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.length; ++currentRow) {
            for (
                int currentColumn = 0;
                currentColumn < grid[0].length;
                ++currentColumn
            ) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes.put(
                        islandId,
                        exploreIsland(grid, islandId, currentRow, currentColumn)
                    );
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.isEmpty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes.get(islandId) == grid.length * grid[0].length)
                ? islandSizes.get(islandId)
                : islandSizes.get(islandId) + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting island size
        for (int currentRow = 0; currentRow < grid.length; ++currentRow) {
            for (
                int currentColumn = 0;
                currentColumn < grid[0].length;
                ++currentColumn
            ) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    Set<Integer> neighboringIslands = new HashSet<>();

                    // Check down
                    if (
                        currentRow + 1 < grid.length &&
                        grid[currentRow + 1][currentColumn] > 1
                    ) {
                        neighboringIslands.add(
                            grid[currentRow + 1][currentColumn]
                        );
                    }

                    // Check up
                    if (
                        currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1
                    ) {
                        neighboringIslands.add(
                            grid[currentRow - 1][currentColumn]
                        );
                    }

                    // Check right
                    if (
                        currentColumn + 1 < grid[0].length &&
                        grid[currentRow][currentColumn + 1] > 1
                    ) {
                        neighboringIslands.add(
                            grid[currentRow][currentColumn + 1]
                        );
                    }

                    // Check left
                    if (
                        currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1
                    ) {
                        neighboringIslands.add(
                            grid[currentRow][currentColumn - 1]
                        );
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes.get(id);
                    }

                    maxIslandSize = Math.max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }

    private int exploreIsland(
        int[][] grid,
        int islandId,
        int currentRow,
        int currentColumn
    ) {
        if (
            currentRow < 0 ||
            currentRow >= grid.length ||
            currentColumn < 0 ||
            currentColumn >= grid[0].length ||
            grid[currentRow][currentColumn] != 1
        ) return 0;

        grid[currentRow][currentColumn] = islandId;
        return (
            1 +
            exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
            exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
            exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
            exploreIsland(grid, islandId, currentRow, currentColumn - 1)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        island_sizes = {}
        island_id = 2

        # Step 1: Mark all islands and calculate their sizes
        for current_row in range(len(grid)):
            for current_column in range(len(grid[0])):
                if grid[current_row][current_column] == 1:
                    island_sizes[island_id] = self.explore_island(
                        grid, island_id, current_row, current_column
                    )
                    island_id += 1

        # If there are no islands, return 1
        if not island_sizes:
            return 1

        # If the entire grid is one island, return its size or size +
        if len(island_sizes) == 1:
            island_id -= 1
            return (
                island_sizes[island_id]
                if island_sizes[island_id] == len(grid) * len(grid[0])
                else island_sizes[island_id] + 1
            )

        max_island_size = 1

        # Step 2: Try converting every 0 to 1 and calculate the resulting island size
        for current_row in range(len(grid)):
            for current_column in range(len(grid[0])):
                if grid[current_row][current_column] == 0:
                    current_island_size = 1
                    neighboring_islands = set()

                    # Check down
                    if (
                        current_row + 1 < len(grid)
                        and grid[current_row + 1][current_column] > 1
                    ):
                        neighboring_islands.add(
                            grid[current_row + 1][current_column]
                        )

                    # Check up
                    if (
                        current_row - 1 >= 0
                        and grid[current_row - 1][current_column] > 1
                    ):
                        neighboring_islands.add(
                            grid[current_row - 1][current_column]
                        )

                    # Check right
                    if (
                        current_column + 1 < len(grid[0])
                        and grid[current_row][current_column + 1] > 1
                    ):
                        neighboring_islands.add(
                            grid[current_row][current_column + 1]
                        )

                    # Check left
                    if (
                        current_column - 1 >= 0
                        and grid[current_row][current_column - 1] > 1
                    ):
                        neighboring_islands.add(
                            grid[current_row][current_column - 1]
                        )

                    # Sum the sizes of all unique neighboring islands
                    for island_id in neighboring_islands:
                        current_island_size += island_sizes[island_id]
                    max_island_size = max(max_island_size, current_island_size)

        return max_island_size

    def explore_island(
        self,
        grid: List[List[int]],
        island_id: int,
        current_row: int,
        current_column: int,
    ) -> int:
        if (
            current_row < 0
            or current_row >= len(grid)
            or current_column < 0
            or current_column >= len(grid[0])
            or grid[current_row][current_column] != 1
        ):
            return 0

        grid[current_row][current_column] = island_id

        return (
            1
            + self.explore_island(
                grid, island_id, current_row + 1, current_column
            )
            + self.explore_island(
                grid, island_id, current_row - 1, current_column
            )
            + self.explore_island(
                grid, island_id, current_row, current_column + 1
            )
            + self.explore_island(
                grid, island_id, current_row, current_column - 1
            )
        )
```

</details>

<br>

## Approach 2: Using Disjoint Set Union (DSU)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;

    // Constructor to initialize DSU with `n` elements
    DisjointSet(int n) {
        parent.resize(n);
        islandSize.resize(n);
        for (int node = 0; node < n; node++) {
            // Each node is its own parent initially with size 1
            parent[node] = node;
            islandSize[node] = 1;
        }
    }

    // Function to find the root of a node with path compression
    int findRoot(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node]);
    }

    // Function to union two sets based on size
    void unionNodes(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        // Already in the same set
        if (rootA == rootB) return;

        // Union by size: Attach the smaller island to the larger one
        if (islandSize[rootA] < islandSize[rootB]) {
            // Attach rootA to rootB
            parent[rootA] = rootB;
            // Update size of rootB's island
            islandSize[rootB] += islandSize[rootA];
        } else {
            // Attach rootB to rootA
            parent[rootB] = rootA;
            // Update size of rootA's island
            islandSize[rootA] += islandSize[rootB];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        // Initialize DSU for the entire grid
        DisjointSet ds(rows * columns);

        // Direction vectors for traversing up, down, left, and right
        vector<int> rowDirections = {1, -1, 0, 0};
        vector<int> columnDirections = {0, 0, 1, -1};

        // Step 1: Union adjacent `1`s in the grid
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 1) {
                    // Flatten 2D index to 1D
                    int currentNode = (columns * currentRow) + currentColumn;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is also `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        int maxIslandSize = 0;
        // Flag to check if there are any zeros in the grid
        bool hasZero = false;
        // To store unique roots for a `0`'s neighbors
        unordered_set<int> uniqueRoots;

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 0) {
                    hasZero = true;
                    // Start with the flipped `0`
                    int currentIslandSize = 1;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            int root = ds.findRoot(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }

                    // Clear the set for the next `0`
                    uniqueRoots.clear();

                    // Update the result with the largest island size found
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        if (!hasZero) return rows * columns;

        return maxIslandSize;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class DisjointSet {

    public int[] parent;
    public int[] islandSize;

    // Constructor to initialize DSU with `n` elements
    public DisjointSet(int n) {
        parent = new int[n];
        islandSize = new int[n];
        for (int node = 0; node < n; node++) {
            // Each node is its own parent initially with size 1
            parent[node] = node;
            islandSize[node] = 1;
        }
    }

    // Function to find the root of a node with path compression
    public int findRoot(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node]); // Path compression
    }

    // Function to union two sets based on size
    public void unionNodes(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        // Already in the same set
        if (rootA == rootB) return;

        // Union by size: Attach the smaller island to the larger one
        if (islandSize[rootA] < islandSize[rootB]) {
            // Attach rootA to rootB
            parent[rootA] = rootB;
            // Update size of rootB's island
            islandSize[rootB] += islandSize[rootA];
        } else {
            // Attach rootB to rootA
            parent[rootB] = rootA;
            // Update size of rootA's island
            islandSize[rootA] += islandSize[rootB];
        }
    }
}

class Solution {

    public int largestIsland(int[][] grid) {
        int rows = grid.length;
        int columns = grid[0].length;

        // Initialize DSU for the entire grid
        DisjointSet ds = new DisjointSet(rows * columns);

        // Direction vectors for traversing up, down, left, and right
        int[] rowDirections = { 1, -1, 0, 0 };
        int[] columnDirections = { 0, 0, 1, -1 };

        // Step 1: Union adjacent `1`s in the grid
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (
                int currentColumn = 0;
                currentColumn < columns;
                currentColumn++
            ) {
                if (grid[currentRow][currentColumn] == 1) {
                    // Flatten 2D index to 1D
                    int currentNode = (columns * currentRow) + currentColumn;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is also `1`
                        if (
                            neighborRow >= 0 &&
                            neighborRow < rows &&
                            neighborColumn >= 0 &&
                            neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1
                        ) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        int maxIslandSize = 0;
        // Flag to check if there are any zeros in the grid
        boolean hasZero = false;
        // To store unique roots for a `0`'s neighbors
        Set<Integer> uniqueRoots = new HashSet<>();

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (
                int currentColumn = 0;
                currentColumn < columns;
                currentColumn++
            ) {
                if (grid[currentRow][currentColumn] == 0) {
                    hasZero = true;
                    // Start with the flipped `0`
                    int currentIslandSize = 1;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is `1`
                        if (
                            neighborRow >= 0 &&
                            neighborRow < rows &&
                            neighborColumn >= 0 &&
                            neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1
                        ) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            int root = ds.findRoot(neighborNode);
                            uniqueRoots.add(root);
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }

                    // Clear the set for the next `0`
                    uniqueRoots.clear();

                    // Update the result with the largest island size found
                    maxIslandSize = Math.max(maxIslandSize, currentIslandSize);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        if (!hasZero) return rows * columns;

        return maxIslandSize;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class DisjointSet:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.island_size = [1] * n

    # Function to find the root of a node with path compression
    def find_root(self, node: int) -> int:

        if self.parent[node] == node:
            return node

        self.parent[node] = self.find_root(self.parent[node])
        return self.parent[node]

    # Function to union two sets based on size
    def union_nodes(self, node_a: int, node_b: int):

        root_a = self.find_root(node_a)
        root_b = self.find_root(node_b)

        # Already in the same set
        if root_a == root_b:
            return

        # Union by size: Attach the smaller island to the larger one
        if self.island_size[root_a] < self.island_size[root_b]:
            # Attach root_a to root_b
            self.parent[root_a] = root_b
            # Update size of root_b's island
            self.island_size[root_b] += self.island_size[root_a]
        else:
            # Attach root_b to root_a
            self.parent[root_b] = root_a
            # Update size of root_a's island
            self.island_size[root_a] += self.island_size[root_b]


class Solution:
    def largestIsland(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        columns = len(grid[0])

        # Initialize DSU for the entire grid
        ds = DisjointSet(rows * columns)

        # Direction vectors for traversing up, down, left, and right
        row_directions = [1, -1, 0, 0]
        column_directions = [0, 0, 1, -1]

        # Step 1: Union adjacent `1`s in the grid
        for current_row in range(rows):
            for current_column in range(columns):
                if grid[current_row][current_column] == 1:

                    # Flatten 2D index to 1D
                    current_node = (columns * current_row) + current_column

                    for direction in range(4):
                        neighbor_row = current_row + row_directions[direction]
                        neighbor_column = (
                            current_column + column_directions[direction]
                        )

                        # Check bounds and ensure the neighbor is also `1`
                        if (
                            0 <= neighbor_row < rows
                            and 0 <= neighbor_column < columns
                            and grid[neighbor_row][neighbor_column] == 1
                        ):
                            neighbor_node = (
                                columns * neighbor_row + neighbor_column
                            )

                            ds.union_nodes(current_node, neighbor_node)

        # Step 2: Calculate the maximum possible island size
        max_island_size = 0

        # Flag to check if there are any zeros in the grid
        has_zero = False

        # To store unique roots for a `0`'s neighbors
        unique_roots = set()

        for current_row in range(rows):
            for current_column in range(columns):
                if grid[current_row][current_column] == 0:
                    has_zero = True

                    # Start with the flipped `0`
                    current_island_size = 1

                    for direction in range(4):
                        neighbor_row = current_row + row_directions[direction]
                        neighbor_column = (
                            current_column + column_directions[direction]
                        )

                        # Check bounds and ensure the neighbor is `1`
                        if (
                            0 <= neighbor_row < rows
                            and 0 <= neighbor_column < columns
                            and grid[neighbor_row][neighbor_column] == 1
                        ):
                            neighbor_node = (
                                columns * neighbor_row + neighbor_column
                            )

                            root = ds.find_root(neighbor_node)
                            unique_roots.add(root)

                    # Sum up the sizes of unique neighboring islands
                    for root in unique_roots:
                        current_island_size += ds.island_size[root]

                    # Clear the set for the next `0`
                    unique_roots.clear()

                    # Update the result with the largest island size found
                    max_island_size = max(max_island_size, current_island_size)

        # If there are no zeros, the largest island is the entire grid
        if not has_zero:
            return rows * columns
        return max_island_size
```

</details>
