# 2503. Maximum Number of Points From Grid Queries

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/)  
`Array` `Two Pointers` `Breadth-First Search` `Union-Find` `Sorting` `Heap (Priority Queue)` `Matrix`

**Problem Link:** [LeetCode 2503 - Maximum Number of Points From Grid Queries](https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/)

## Problem

You are given an m x n integer matrix grid and an array queries of size k.

Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:

- If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
- Otherwise, you do not get any points, and you end this process.

After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.

Return the resulting array answer.

### Example 1

```text
Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
Output: [5,8,1]
Explanation: The diagrams above show which cells we visit to get points for each query.
```

### Example 2

```text
Input: grid = [[5,2,1],[1,1,2]], queries = [3]
Output: [0]
Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 2 <= m, n <= 1000
- 4 <= m * n <= 105
- k == queries.length
- 1 <= k <= 104
- 1 <= grid[i][j], queries[i] <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Escape the Spreading Fire](https://leetcode.com/problems/escape-the-spreading-fire/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2503. Maximum Number of Points From Grid Queries

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (TLE) | C++, Java, Python3 |
| Sorting Queries + Min-Heap Expansion | C++, Java, Python3 |
| Using Priority Queue with Binary Search | C++, Java, Python3 |
| Disjoint Set Union (Union-Find) | C++, Java, Python3 |

## Approach 1: Brute Force (TLE)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        // Directions for moving in 4 directions (right, down, left, up)
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Iterate through each query value
        for (int queryIndex = 0; queryIndex < queries.size(); queryIndex++) {
            int queryValue = queries[queryIndex];
            queue<pair<int, int>> bfsQueue;
            // Start BFS from the top-left corner
            bfsQueue.push({0, 0});
            vector<vector<bool>> visited(rowCount,
                                         vector<bool>(colCount, false));
            // Mark the starting cell as visited
            visited[0][0] = true;
            int points = 0;

            // BFS traversal
            while (!bfsQueue.empty()) {
                int queueSize = bfsQueue.size();
                while (queueSize--) {
                    auto [currentRow, currentCol] = bfsQueue.front();
                    bfsQueue.pop();

                    // If the current cell's value is greater than or equal to
                    // queryValue, stop expanding from here
                    if (grid[currentRow][currentCol] >= queryValue) continue;

                    // Count the valid cell
                    points++;

                    // Explore all four possible directions
                    for (auto [rowOffset, colOffset] : DIRECTIONS) {
                        int newRow = currentRow + rowOffset,
                            newCol = currentCol + colOffset;

                        // Ensure the new position is within bounds and has not
                        // been visited
                        if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                            newCol < colCount && !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue) {
                            bfsQueue.push({newRow, newCol});
                            // Mark the new cell as visited
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            // Store the result for the current query
            result[queryIndex] = points;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxPoints(int[][] grid, int[] queries) {
        int rowCount = grid.length, colCount = grid[0].length;
        int[] result = new int[queries.length];
        // Directions for moving in 4 directions (right, down, left, up)
        int[][] DIRECTIONS = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        // Iterate through each query value
        for (int queryIndex = 0; queryIndex < queries.length; queryIndex++) {
            int queryValue = queries[queryIndex];
            Queue<int[]> bfsQueue = new LinkedList<>();
            // Start BFS from the top-left corner
            bfsQueue.add(new int[] { 0, 0 });
            boolean[][] visited = new boolean[rowCount][colCount];
            // Mark the starting cell as visited
            visited[0][0] = true;
            int points = 0;

            // BFS traversal
            while (!bfsQueue.isEmpty()) {
                int queueSize = bfsQueue.size();
                for (int i = 0; i < queueSize; i++) {
                    int[] current = bfsQueue.poll();
                    int currentRow = current[0];
                    int currentCol = current[1];

                    // If the current cell's value is greater than or equal to
                    // queryValue, stop expanding from here
                    if (grid[currentRow][currentCol] >= queryValue) continue;

                    // Count the valid cell
                    points++;

                    // Explore all four possible directions
                    for (int[] direction : DIRECTIONS) {
                        int newRow = currentRow + direction[0];
                        int newCol = currentCol + direction[1];

                        // Ensure the new position is within bounds and has not
                        // been visited
                        if (
                            newRow >= 0 &&
                            newCol >= 0 &&
                            newRow < rowCount &&
                            newCol < colCount &&
                            !visited[newRow][newCol] &&
                            grid[newRow][newCol] < queryValue
                        ) {
                            bfsQueue.add(new int[] { newRow, newCol });
                            // Mark the new cell as visited
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
            // Store the result for the current query
            result[queryIndex] = points;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        row_count, col_count = len(grid), len(grid[0])
        result = [0] * len(queries)
        # Directions for moving in 4 directions (right, down, left, up)
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Iterate through each query value
        for queryIndex, queryValue in enumerate(queries):
            bfs_queue = deque([(0, 0)])
            visited = [[0] * col_count for _ in range(row_count)]
            # Mark the starting cell as visited
            visited[0][0] = 1
            points = 0

            # BFS traversal
            while bfs_queue:
                queue_size = len(bfs_queue)
                for _ in range(queue_size):
                    current_row, current_col = bfs_queue.popleft()

                    # If the current cell's value is greater than or equal to
                    # queryValue, stop expanding from here
                    if grid[current_row][current_col] >= queryValue:
                        continue

                    # Count the valid cell
                    points += 1

                    # Explore all four possible directions
                    for row_offset, col_offset in DIRECTIONS:
                        new_row = current_row + row_offset
                        new_col = current_col + col_offset

                        # Ensure the new position is within bounds and has not
                        # been visited
                        if (
                            0 <= new_row < row_count
                            and 0 <= new_col < col_count
                            and not visited[new_row][new_col]
                            and grid[new_row][new_col] < queryValue
                        ):
                            bfs_queue.append((new_row, new_col))
                            # Mark the new cell as visited
                            visited[new_row][new_col] = 1
                # Store the result for the current query
                result[queryIndex] = points
        return result
```

</details>

<br>

## Approach 2: Sorting Queries + Min-Heap Expansion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        vector<int> result(queries.size(), 0);
        // Directions for movement (right, down, left, up)
        vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Store queries along with their original indices to restore order
        // later
        vector<pair<int, int>> sortedQueries;
        for (int index = 0; index < queries.size(); index++) {
            sortedQueries.push_back({queries[index], index});
        }
        // Sort queries by value in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Min-heap (priority queue) to process cells in increasing order of
        // value
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            minHeap;
        vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
        // Keeps track of the number of cells processed
        int totalPoints = 0;
        // Start from the top-left cell
        minHeap.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        // Process queries in sorted order
        for (auto [queryValue, queryIndex] : sortedQueries) {
            // Expand the cells that are smaller than the current query value
            while (!minHeap.empty() && minHeap.top().first < queryValue) {
                auto [cellValue, position] = minHeap.top();
                minHeap.pop();
                int currentRow = position.first, currentCol = position.second;
                // Increment count of valid cells
                totalPoints++;

                // Explore all four possible directions
                for (auto [rowOffset, colOffset] : DIRECTIONS) {
                    int newRow = currentRow + rowOffset,
                        newCol = currentCol + colOffset;

                    // Check if the new cell is within bounds and not visited
                    if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                        newCol < colCount && !visited[newRow][newCol]) {
                        minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                        // Mark as visited
                        visited[newRow][newCol] = true;
                    }
                }
            }
            // Store the result for this query
            result[queryIndex] = totalPoints;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[] maxPoints(int[][] grid, int[] queries) {
        int rowCount = grid.length, colCount = grid[0].length;
        int[] result = new int[queries.length];
        // Directions for movement (right, down, left, up)
        int[][] DIRECTIONS = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        // Store queries along with their original indices to restore order
        // later
        int[][] sortedQueries = new int[queries.length][2];
        for (int index = 0; index < queries.length; index++) {
            sortedQueries[index][0] = queries[index];
            sortedQueries[index][1] = index;
        }
        // Sort queries by value in ascending order
        Arrays.sort(sortedQueries, (a, b) -> a[0] - b[0]);

        // Min-heap (priority queue) to process cells in increasing order of
        // value
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );
        boolean[][] visited = new boolean[rowCount][colCount];
        // Keeps track of the number of cells processed
        int totalPoints = 0;
        // Start from the top-left cell
        minHeap.add(new int[] { grid[0][0], 0, 0 });
        visited[0][0] = true;

        // Process queries in sorted order
        for (int[] query : sortedQueries) {
            int queryValue = query[0], queryIndex = query[1];
            // Expand the cells that are smaller than the current query value
            while (!minHeap.isEmpty() && minHeap.peek()[0] < queryValue) {
                int[] top = minHeap.poll();
                int cellValue = top[0], currentRow = top[1], currentCol =
                    top[2];
                // Increment count of valid cells
                totalPoints++;

                // Explore all four possible directions
                for (int[] dir : DIRECTIONS) {
                    int newRow = currentRow + dir[0], newCol =
                        currentCol + dir[1];

                    // Check if the new cell is within bounds and not visited
                    if (
                        newRow >= 0 &&
                        newCol >= 0 &&
                        newRow < rowCount &&
                        newCol < colCount &&
                        !visited[newRow][newCol]
                    ) {
                        minHeap.add(
                            new int[] { grid[newRow][newCol], newRow, newCol }
                        );
                        // Mark as visited
                        visited[newRow][newCol] = true;
                    }
                }
            }
            // Store the result for this query
            result[queryIndex] = totalPoints;
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from queue import PriorityQueue


class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        row_count, col_count = len(grid), len(grid[0])
        result = [0] * len(queries)
        # Directions for movement (right, down, left, up)
        DIRECTIONS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        # Store queries along with their original indices to restore order
        # later
        sorted_queries = sorted([(val, idx) for idx, val in enumerate(queries)])

        # Min-heap (priority queue) to process cells in increasing order of
        # value
        min_heap = PriorityQueue()
        visited = [[False] * col_count for _ in range(row_count)]
        # Keeps track of the number of cells processed
        total_points = 0
        # Start from the top-left cell
        min_heap.put((grid[0][0], 0, 0))
        visited[0][0] = True

        # Process queries in sorted order
        for query_value, query_index in sorted_queries:
            # Expand the cells that are smaller than the current query value
            while not min_heap.empty() and min_heap.queue[0][0] < query_value:
                cellValue, current_row, current_col = min_heap.get()

                # Increment count of valid cells
                total_points += 1

                # Explore all four possible directions
                for row_offset, col_offset in DIRECTIONS:
                    new_row, new_col = (
                        current_row + row_offset,
                        current_col + col_offset,
                    )

                    # Check if the new cell is within bounds and not visited
                    if (
                        new_row >= 0
                        and new_col >= 0
                        and new_row < row_count
                        and new_col < col_count
                        and not visited[new_row][new_col]
                    ):
                        min_heap.put((grid[new_row][new_col], new_row, new_col))
                        # Mark as visited
                        visited[new_row][new_col] = True
            # Store the result for this query
            result[query_index] = total_points

        return result
```

</details>

<br>

## Approach 3: Using Priority Queue with Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static constexpr int DIRECTIONS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int queryCount = queries.size();
        vector<int> result(queryCount);
        int rowCount = grid.size();
        int colCount = grid[0].size();

        int totalCells = rowCount * colCount;
        vector<int> thresholdForMaxPoints(totalCells + 1);

        vector<vector<int>> minValueToReach(rowCount,
                                            vector<int>(colCount, INT_MAX));

        minValueToReach[0][0] = grid[0][0];

        // Min-heap for processing cells in increasing order of their maximum
        // encountered value.
        priority_queue<array<int, 3>, vector<array<int, 3>>,
                       greater<array<int, 3>>>
            minHeap;
        minHeap.push({grid[0][0], 0, 0});
        int visitedCells = 0;

        // Dijkstra's algorithm to compute minValueToReach for each cell
        while (!minHeap.empty()) {
            array<int, 3> current = minHeap.top();
            minHeap.pop();

            // Store the value required to reach `visitedCells` points.
            thresholdForMaxPoints[++visitedCells] = current[0];

            // Explore all possible directions.
            for (const auto& direction : DIRECTIONS) {
                int newRow = current[1] + direction[0];
                int newCol = current[2] + direction[1];

                // Check if the new position is within bounds and not visited
                // before.
                if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                    newCol < colCount &&
                    minValueToReach[newRow][newCol] == INT_MAX) {
                    // The max value encountered on the path to this cell.
                    minValueToReach[newRow][newCol] =
                        max(current[0], grid[newRow][newCol]);

                    // Add the cell to the heap for further exploration.
                    minHeap.push(
                        {minValueToReach[newRow][newCol], newRow, newCol});
                }
            }
        }

        // Use binary search to determine the maximum number of points that can
        // be collected for each query.
        for (int i = 0; i < queryCount; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;

            // Find the rightmost number of points we can collect before
            // exceeding the query threshold.
            while (left < right) {
                int mid = left + (right - left + 1) / 2;
                if (thresholdForMaxPoints[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            // Return `left`.
            result[i] = left;
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Directions for movement (down, up, right, left)
    public static final int[][] DIRECTIONS = {
        { 1, 0 },
        { -1, 0 },
        { 0, 1 },
        { 0, -1 },
    };

    public int[] maxPoints(int[][] grid, int[] queries) {
        int queryCount = queries.length;
        int[] result = new int[queryCount];
        int rowCount = grid.length;
        int colCount = grid[0].length;

        int totalCells = rowCount * colCount;
        // Stores the minimum query value needed to reach `i` points.
        int[] thresholdForMaxPoints = new int[totalCells + 1];

        // `minValueToReach[i][j]` keeps track of the maximum value encountered
        // to reach cell (i, j), including itself.
        int[][] minValueToReach = new int[rowCount][colCount];

        // Initialize the minValueToReach array with a high value.
        for (int[] row : minValueToReach) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        // Start from the top-left cell.
        minValueToReach[0][0] = grid[0][0];

        // Min-heap for processing cells in increasing order of their maximum
        // encountered value.
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) ->
            Integer.compare(a[2], b[2])
        );
        minHeap.offer(new int[] { 0, 0, grid[0][0] });
        int visitedCells = 0;

        // Dijkstra's algorithm to compute minValueToReach for each cell
        while (!minHeap.isEmpty()) {
            int[] current = minHeap.poll();
            // Store the value required to reach `visitedCells` points.
            thresholdForMaxPoints[++visitedCells] = current[2];
            // Explore all possible directions.
            for (int[] direction : DIRECTIONS) {
                int newRow = current[0] + direction[0];
                int newCol = current[1] + direction[1];

                // Check if the new position is within bounds and not visited
                // before.
                if (
                    newRow >= 0 &&
                    newRow < rowCount &&
                    newCol >= 0 &&
                    newCol < colCount &&
                    minValueToReach[newRow][newCol] == Integer.MAX_VALUE
                ) {
                    // The max value encountered on the path to this cell.
                    minValueToReach[newRow][newCol] = Math.max(
                        current[2],
                        grid[newRow][newCol]
                    );

                    // Add the cell to the heap for further exploration.
                    minHeap.offer(
                        new int[] {
                            newRow,
                            newCol,
                            minValueToReach[newRow][newCol],
                        }
                    );
                }
            }
        }

        // Use binary search to determine the maximum number of points that can
        // be collected for each query.
        for (int i = 0; i < queryCount; i++) {
            int threshold = queries[i];
            int left = 0, right = totalCells;

            // Find the rightmost number of points we can collect before
            // exceeding the query threshold.
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if (thresholdForMaxPoints[mid] < threshold) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }

            // Return `left`.
            result[i] = left;
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from queue import PriorityQueue


class Solution:

    DIRECTIONS = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    def maxPoints(self, grid, queries):
        query_count = len(queries)
        result = [0] * query_count
        row_count = len(grid)
        col_count = len(grid[0])
        total_cells = row_count * col_count

        threshold_for_max_points = [0] * (total_cells + 1)
        min_value_to_reach = [
            [float("inf")] * col_count for _ in range(row_count)
        ]

        min_value_to_reach[0][0] = grid[0][0]

        # Min-heap for processing cells in increasing order of their maximum
        # encountered value.
        min_heap = PriorityQueue()
        min_heap.put((grid[0][0], 0, 0))
        visited_cells = 0

        # Dijkstra's algorithm to compute minValueToReach for each cell
        while not min_heap.empty():
            current = min_heap.get()

            # Store the value required to reach `visitedCells` points.
            threshold_for_max_points[visited_cells + 1] = current[0]
            visited_cells += 1

            # Explore all possible directions.
            for direction in self.DIRECTIONS:
                new_row, new_col = (
                    current[1] + direction[0],
                    current[2] + direction[1],
                )

                # Check if the new position is within bounds and not visited
                # before.
                if (
                    0 <= new_row < row_count
                    and 0 <= new_col < col_count
                    and min_value_to_reach[new_row][new_col] == float("inf")
                ):
                    # The max value encountered on the path to this cell.
                    min_value_to_reach[new_row][new_col] = max(
                        current[0], grid[new_row][new_col]
                    )

                    # Add the cell to the heap for further exploration.
                    min_heap.put(
                        (min_value_to_reach[new_row][new_col], new_row, new_col)
                    )

        # Use binary search to determine the maximum number of points that can
        # be collected for each query.
        for i in range(query_count):
            threshold = queries[i]
            left, right = 0, total_cells

            # Find the rightmost number of points we can collect before
            # exceeding the query threshold.
            while left < right:
                mid = left + (right - left + 1) // 2

                if threshold_for_max_points[mid] < threshold:
                    left = mid
                else:
                    right = mid - 1

            # Return `left`.
            result[i] = left

        return result
```

</details>

<br>

## Approach 4: Disjoint Set Union (Union-Find)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// Represents a cell in the grid with row index, column index, and value
class Cell {
public:
    int row;
    int col;
    int value;
    Cell(int r, int c, int v) : row(r), col(c), value(v) {}
};

// Represents a query with its original index and value
class Query {
public:
    int index;
    int value;
    Query(int i, int v) : index(i), value(v) {}
};

bool operator<(const Query& a, const Query& b) { return a.value < b.value; }

bool operator<(const Cell& a, const Cell& b) { return a.value < b.value; }

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;

public:
    // Initialize all parents to -1 (disjoint sets) and each component starts
    // with size 1
    UnionFind(int n) : parent(vector<int>(n, -1)), size(vector<int>(n, 1)) {}

    // Find with path compression
    int find(int node) {
        // If negative, it's the root
        if (parent[node] < 0) {
            return node;
        }
        // Path compression
        return parent[node] = find(parent[node]);
    }

    // Union by size (merge smaller tree into larger tree)
    bool union_nodes(int nodeA, int nodeB) {
        int rootA = find(nodeA);
        int rootB = find(nodeB);
        // Already connected
        if (rootA == rootB) {
            return false;
        }
        if (size[rootA] > size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        return true;
    }

    // Get the size of the component containing a given node
    int getSize(int node) { return size[find(node)]; }
};

// Right, Left, Down, Up
const vector<int> ROW_DIRECTIONS = {0, 0, 1, -1};
// Corresponding column moves
const vector<int> COL_DIRECTIONS = {1, -1, 0, 0};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rowCount = grid.size(), colCount = grid[0].size();
        int totalCells = rowCount * colCount;

        // Store queries with their original indices to maintain result order
        vector<Query> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back(Query(i, queries[i]));
        }
        // Sort queries in ascending order
        sort(sortedQueries.begin(), sortedQueries.end());

        // Store all grid cells and sort them by value
        vector<Cell> sortedCells;
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                sortedCells.push_back(Cell(row, col, grid[row][col]));
            }
        }
        // Sort cells by value
        sort(sortedCells.begin(), sortedCells.end());

        // Union-Find to track connected components
        UnionFind uf = UnionFind(totalCells);
        vector<int> result(queries.size());
        int cellIndex = 0;

        // Process queries in sorted order
        for (Query query : sortedQueries) {
            // Process cells whose values are smaller than the current query
            // value
            while (cellIndex < totalCells &&
                   sortedCells[cellIndex].value < query.value) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                // Convert 2D position to 1D index
                int cellId = row * colCount + col;

                // Merge the current cell with its adjacent cells that have
                // already been processed
                for (int direction = 0; direction < 4; direction++) {
                    int newRow = row + ROW_DIRECTIONS[direction];
                    int newCol = col + COL_DIRECTIONS[direction];

                    // Check if the new cell is within bounds and its value is
                    // smaller than the query value
                    if (newRow >= 0 && newRow < rowCount && newCol >= 0 &&
                        newCol < colCount &&
                        grid[newRow][newCol] < query.value) {
                        uf.union_nodes(cellId, newRow * colCount + newCol);
                    }
                }
                cellIndex++;
            }
            // Get the size of the connected component containing the top-left
            // cell (0,0)
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Represents a cell in the grid with row index, column index, and value
    record Cell(int row, int col, int value) {}

    // Represents a query with its original index and value
    record Query(int index, int value) {}

    // Right, Left, Down, Up
    private static final int[] ROW_DIRECTIONS = { 0, 0, 1, -1 };
    // Corresponding column moves
    private static final int[] COL_DIRECTIONS = { 1, -1, 0, 0 };

    public int[] maxPoints(int[][] grid, int[] queries) {
        int rowCount = grid.length, colCount = grid[0].length;
        int totalCells = rowCount * colCount;

        // Store queries with their original indices to maintain result order
        Query[] sortedQueries = new Query[queries.length];
        for (int i = 0; i < queries.length; i++) {
            sortedQueries[i] = new Query(i, queries[i]);
        }
        // Sort queries in ascending order
        Arrays.sort(sortedQueries, (a, b) -> Integer.compare(a.value, b.value));

        // Store all grid cells and sort them by value
        Cell[] sortedCells = new Cell[totalCells];
        for (int row = 0; row < rowCount; row++) {
            for (int col = 0; col < colCount; col++) {
                sortedCells[row * colCount + col] = new Cell(
                    row,
                    col,
                    grid[row][col]
                );
            }
        }
        // Sort cells by value
        Arrays.sort(sortedCells, (a, b) -> Integer.compare(a.value, b.value));

        // Union-Find to track connected components
        UnionFind uf = new UnionFind(totalCells);
        int[] result = new int[queries.length];
        int cellIndex = 0;

        // Process queries in sorted order
        for (Query query : sortedQueries) {
            // Process cells whose values are smaller than the current query value
            while (
                cellIndex < totalCells &&
                sortedCells[cellIndex].value < query.value
            ) {
                int row = sortedCells[cellIndex].row;
                int col = sortedCells[cellIndex].col;
                // Convert 2D position to 1D index
                int cellId = row * colCount + col;

                // Merge the current cell with its adjacent cells that have already been
                // processed
                for (int direction = 0; direction < 4; direction++) {
                    int newRow = row + ROW_DIRECTIONS[direction];
                    int newCol = col + COL_DIRECTIONS[direction];

                    // Check if the new cell is within bounds and its value is smaller than the
                    // query value
                    if (
                        newRow >= 0 &&
                        newRow < rowCount &&
                        newCol >= 0 &&
                        newCol < colCount &&
                        grid[newRow][newCol] < query.value
                    ) {
                        uf.union(cellId, newRow * colCount + newCol);
                    }
                }
                cellIndex++;
            }
            // Get the size of the connected component containing the top-left cell (0,0)
            result[query.index] = query.value > grid[0][0] ? uf.getSize(0) : 0;
        }
        return result;
    }
}

class UnionFind {

    private final int[] parent;
    private final int[] size;

    public UnionFind(int n) {
        parent = new int[n];
        size = new int[n];
        // Initialize all parents to -1 (disjoint sets)
        Arrays.fill(parent, -1);
        // Each component starts with size 1
        Arrays.fill(size, 1);
    }

    // Find with path compression
    public int find(int node) {
        // If negative, it's the root
        if (parent[node] < 0) return node;
        // Path compression
        return parent[node] = find(parent[node]);
    }

    // Union by size (merge smaller tree into larger tree)
    public boolean union(int nodeA, int nodeB) {
        int rootA = find(nodeA), rootB = find(nodeB);
        // Already connected
        if (rootA == rootB) return false;

        if (size[rootA] > size[rootB]) {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        } else {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        return true;
    }

    // Get the size of the component containing a given node
    public int getSize(int node) {
        return size[find(node)];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Cell:
    def __init__(self, row, col, value):
        self.row = row
        self.col = col
        self.value = value


class Query:
    def __init__(self, index, value):
        self.index = index
        self.value = value


class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.size = [1] * n

    def find(self, node):
        if self.parent[node] < 0:
            return node
        return self.find(self.parent[node])

    def union(self, nodeA, nodeB):
        rootA = self.find(nodeA)
        rootB = self.find(nodeB)
        if rootA == rootB:
            return False

        if self.size[rootA] > self.size[rootB]:
            self.parent[rootB] = rootA
            self.size[rootA] += self.size[rootB]
        else:
            self.parent[rootA] = rootB
            self.size[rootB] += self.size[rootA]
        return True

    def get_size(self, node):
        return self.size[self.find(node)]


class Solution:
    ROW_DIRECTIONS = [0, 0, 1, -1]  # Right, Left, Down, Up
    COL_DIRECTIONS = [1, -1, 0, 0]  # Corresponding column moves

    def maxPoints(self, grid, queries):
        row_count, col_count = len(grid), len(grid[0])
        total_cells = row_count * col_count

        sorted_queries = [
            Query(i, val) for i, val in enumerate(queries)
        ]  # Store queries with their original indices to maintain result order
        sorted_queries.sort(
            key=lambda x: x.value
        )  # Sort queries in ascending order

        sorted_cells = [
            Cell(row, col, grid[row][col])
            for row in range(row_count)
            for col in range(col_count)
        ]  # Store all grid cells and sort them by value
        sorted_cells.sort(key=lambda x: x.value)  # Sort cells by value

        uf = UnionFind(total_cells)
        result = [0] * len(queries)

        cell_index = 0
        for query in sorted_queries:  # Process queries in sorted order
            while (
                cell_index < total_cells
                and sorted_cells[cell_index].value < query.value
            ):  # Process cells whose values are smaller than the current query value
                row = sorted_cells[cell_index].row
                col = sorted_cells[cell_index].col
                cell_id = (
                    row * col_count + col
                )  # Convert 2D position to 1D index

                for direction in range(
                    4
                ):  # Merge the current cell with its adjacent cells that have already been processed
                    new_row = row + Solution.ROW_DIRECTIONS[direction]
                    new_col = col + Solution.COL_DIRECTIONS[direction]
                    if (
                        0 <= new_row < row_count
                        and 0 <= new_col < col_count
                        and grid[new_row][new_col] < query.value
                    ):
                        uf.union(cell_id, new_row * col_count + new_col)

                cell_index += 1

            result[query.index] = (
                uf.get_size(0) if query.value > grid[0][0] else 0
            )  # Get the size of the component containing the top-left cell (0,0)

        return result
```

</details>
