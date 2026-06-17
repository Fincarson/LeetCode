# 2017. Grid Game

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/grid-game/)  
`Array` `Matrix` `Prefix Sum`

**Problem Link:** [LeetCode 2017 - Grid Game](https://leetcode.com/problems/grid-game/)

## Problem

You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.

The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.

### Example 1

```text
Input: grid = [[2,5,4],[1,5,1]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 0 + 4 + 0 = 4 points.
```

### Example 2

```text
Input: grid = [[3,3,1],[8,5,2]]
Output: 4
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 3 + 1 + 0 = 4 points.
```

### Example 3

```text
Input: grid = [[1,3,1,15],[1,3,3,1]]
Output: 7
Explanation: The optimal path taken by the first robot is shown in red, and the optimal path taken by the second robot is shown in blue.
The cells visited by the first robot are set to 0.
The second robot will collect 0 + 1 + 3 + 3 + 0 = 7 points.
```

## Constraints

- grid.length == 2
- n == grid[r].length
- 1 <= n <= 5 * 104
- 1 <= grid[r][c] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Penalty for a Shop](https://leetcode.com/problems/minimum-penalty-for-a-shop/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2017. Grid Game

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix and Suffix Sum | C++, Java, Python3 |

## Approach: Prefix and Suffix Sum

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long gridGame(int[][] grid) {
        // Calculate the sum of all the elements for the first row
        long firstRowSum = 0;
        for (int num : grid[0]) {
            firstRowSum += num;
        }
        long secondRowSum = 0;
        long minimumSum = Long.MAX_VALUE;
        for (int turnIndex = 0; turnIndex < grid[0].length; ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = Math.min(
                minimumSum,
                Math.max(firstRowSum, secondRowSum)
            );
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        first_row_sum = sum(grid[0])
        second_row_sum = 0
        minimum_sum = float("inf")
        for turn_index in range(len(grid[0])):
            first_row_sum -= grid[0][turn_index]
            # Find the minimum maximum value out of first_row_sum and
            # second_row_sum.
            minimum_sum = min(minimum_sum, max(first_row_sum, second_row_sum))
            second_row_sum += grid[1][turn_index]
        return minimum_sum
```

</details>
