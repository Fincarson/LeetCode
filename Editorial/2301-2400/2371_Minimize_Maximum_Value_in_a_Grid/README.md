# 2371. Minimize Maximum Value in a Grid

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/minimize-maximum-value-in-a-grid/)  
`Array` `Union-Find` `Graph Theory` `Topological Sort` `Sorting` `Matrix`

**Problem Link:** [LeetCode 2371 - Minimize Maximum Value in a Grid](https://leetcode.com/problems/minimize-maximum-value-in-a-grid/)

## Problem

You are given an m x n integer matrix grid containing distinct positive integers.

You have to replace each integer in the matrix with a positive integer satisfying the following conditions:

- The relative order of every two elements that are in the same row or column should stay the same after the replacements.
- The maximum number in the matrix after the replacements should be as small as possible.

The relative order stays the same if for all pairs of elements in the original matrix such that grid[r1][c1] > grid[r2][c2] where either r1 == r2 or c1 == c2, then it must be true that grid[r1][c1] > grid[r2][c2] after the replacements.

For example, if grid = [[2, 4, 5], [7, 3, 9]] then a good replacement could be either grid = [[1, 2, 3], [2, 1, 4]] or grid = [[1, 2, 3], [3, 1, 4]].

Return the resulting matrix. If there are multiple answers, return any of them.

### Example 1

```text
Input: grid = [[3,1],[2,5]]
Output: [[2,1],[1,2]]
Explanation: The above diagram shows a valid replacement.
The maximum number in the matrix is 2. It can be shown that no smaller value can be obtained.
```

### Example 2

```text
Input: grid = [[10]]
Output: [[1]]
Explanation: We replace the only number in the matrix with 1.
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 1 <= grid[i][j] <= 109
- grid consists of distinct integers.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Candy](https://leetcode.com/problems/candy/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2371. Minimize Maximum Value in a Grid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sorting | C++, Java, Python3 |
| Min-heap | C++, Java, Python3 |

## Approach 1: Sorting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();

        // Create a vector nums that stores the values of the matrix and their
        // indices.
        vector<tuple<int, int, int>> nums;

        // Create rows and cols to store the minimum values for every row and
        // column.
        vector<int> rows(row, 1);
        vector<int> cols(col, 1);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                nums.push_back(make_tuple(grid[i][j], i, j));
            }
        }
        sort(nums.begin(), nums.end());

        for (auto tup : nums) {
            int val, x, y;
            tie(val, x, y) = tup;
            // Find the maximum value of rows[x] and cols[y] till now and assign
            // it to val.
            val = max(rows[x], cols[y]);
            grid[x][y] = val;
            // Update the new maximum value in rows[x] and cols[y].
            rows[x] = cols[y] = val + 1;
        }
        return grid;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] minScore(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Create a list to store the values of the matrix and their indices.
        List<int[]> nums = new ArrayList<>();

        // Create arrays to store the minimum values for every row and column.
        int[] rowMax = new int[rows];
        int[] colMax = new int[cols];
        Arrays.fill(rowMax, 1);
        Arrays.fill(colMax, 1);

        // Populate the nums list with grid values and their positions.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                nums.add(new int[] { grid[i][j], i, j });
            }
        }

        // Sort nums by the grid values in ascending order.
        nums.sort((a, b) -> Integer.compare(a[0], b[0]));

        // Assign ranks to each cell based on the sorting.
        for (int[] num : nums) {
            int value = num[0];
            int x = num[1];
            int y = num[2];

            // Determine the new value as the max of the current row and column.
            int newValue = Math.max(rowMax[x], colMax[y]);
            grid[x][y] = newValue;

            // Update rowMax and colMax for the next values.
            rowMax[x] = newValue + 1;
            colMax[y] = newValue + 1;
        }

        return grid;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        row, col = len(grid), len(grid[0])

        nums = []
        # Create rows and cols to store the minimum values for every row and column.
        rows = [1 for i in range(row)]
        cols = [1 for i in range(col)]

        # Create a matrix nums that stores the values of the matrix and their indices.
        for i in range(row):
            for j in range(col):
                nums.append((grid[i][j], i, j))

        nums.sort()
        for tup in nums:
            _, i, j = tup
            # Find the maximum value of rows[i] and cols[j] till now and assign it to val.
            val = max(rows[i], cols[j])
            grid[i][j] = val
            # Update the new maximum value in rows[i] and cols[j].
            rows[i], cols[j] = val + 1, val + 1
        return grid
```

</details>

<br>

## Approach 2: Min-heap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        // Get size of the grid
        int rowSize = grid.size(), colSize = grid[0].size();

        // Initialize priority_queue to store elements with their values and
        // coordinates
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            min_heap;

        // Initialize arrays to keep track of maximum values assigned
        vector<int> rows(rowSize, 1);
        vector<int> cols(colSize, 1);

        // Populate the heap with all elements of the grid
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                min_heap.push(make_pair(grid[i][j], make_pair(i, j)));
            }
        }

        // Process elements in ascending order of their values
        while (!min_heap.empty()) {
            auto element = min_heap.top();

            // Extract additional data from element
            int value = element.first;
            int row = element.second.first;
            int col = element.second.second;

            min_heap.pop();

            // Determine the smallest assignable value based on rows and cols
            // constraints
            int val = max(rows[row], cols[col]);
            grid[row][col] = val;

            // Update rows and cols arrays with the next possible value for each
            // row and column
            rows[row] = val + 1;
            cols[col] = val + 1;
        }

        return grid;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] minScore(int[][] grid) {
        // Get size of the grid
        int rowSize = grid.length, colSize = grid[0].length;

        // Initialize PriorityQueue to store elements with their values and coordinates
        PriorityQueue<int[]> min_heap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );

        // Initialize arrays to keep track of maximum values assigned
        int[] rows = new int[rowSize];
        int[] cols = new int[colSize];
        for (int i = 0; i < rowSize; i++) rows[i] = 1;
        for (int j = 0; j < colSize; j++) cols[j] = 1;

        // Populate the heap with all elements of the grid
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                min_heap.offer(new int[] { grid[i][j], i, j });
            }
        }

        // Process elements in ascending order of their values
        while (!min_heap.isEmpty()) {
            int[] element = min_heap.poll();
            int value = element[0];
            int row = element[1];
            int col = element[2];

            // Determine the smallest assignable value based on rows and cols constraints
            int val = Math.max(rows[row], cols[col]);
            grid[row][col] = val;

            // Update rows and cols arrays with the next possible value for each row and column
            rows[row] = val + 1;
            cols[col] = val + 1;
        }

        return grid;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minScore(self, grid: List[List[int]]) -> List[List[int]]:
        row_size, col_size = len(grid), len(grid[0])

        # Min-heap to store elements with their values and coordinates
        min_heap = []
        # Initialize rows and cols arrays to keep track of maximum values assigned
        rows = [1] * row_size
        cols = [1] * col_size

        # Populate the min-heap with all elements of the grid
        for i in range(row_size):
            for j in range(col_size):
                heapq.heappush(min_heap, (grid[i][j], i, j))

        # Process elements in ascending order of their values
        while min_heap:
            _, i, j = heapq.heappop(min_heap)
            # Determine the smallest assignable value based on rows and cols constraints
            val = max(rows[i], cols[j])
            grid[i][j] = val
            # Update rows and cols arrays with the next possible value for each row and column
            rows[i] = val + 1
            cols[j] = val + 1

        return grid
```

</details>
