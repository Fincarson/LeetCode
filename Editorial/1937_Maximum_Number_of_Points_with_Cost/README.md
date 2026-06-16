# 1937. Maximum Number of Points with Cost

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-points-with-cost/)  
`Array` `Dynamic Programming` `Matrix`

**Problem Link:** [LeetCode 1937 - Maximum Number of Points with Cost](https://leetcode.com/problems/maximum-number-of-points-with-cost/)

## Problem

You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

- x for x >= 0.
- -x for x < 0.

### Example 1

```text
Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
```

### Example 2

```text
Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.
```

## Constraints

- m == points.length
- n == points[r].length
- 1 <= m, n <= 105
- 1 <= m * n <= 105
- 0 <= points[r][c] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Minimize the Difference Between Target and Chosen Elements](https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1937. Maximum Number of Points with Cost

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | C++, Java, Python3 |
| Dynamic Programming (Optimized) | C++, Java, Python3 |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> previousRow(cols);

        // Initialize the first row
        for (int col = 0; col < cols; ++col) {
            previousRow[col] = points[0][col];
        }

        // Process each row
        for (int row = 0; row < rows - 1; ++row) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            vector<long long> currentRow(cols);

            // Calculate left-to-right maximum
            leftMax[0] = previousRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col - 1] - 1, previousRow[col]);
            }

            // Calculate right-to-left maximum
            rightMax[cols - 1] = previousRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col + 1] - 1, previousRow[col]);
            }

            // Calculate the current row's maximum points
            for (int col = 0; col < cols; ++col) {
                currentRow[col] =
                    points[row + 1][col] + max(leftMax[col], rightMax[col]);
            }

            // Update previousRow for the next iteration
            previousRow = currentRow;
        }

        // Find the maximum value in the last processed row
        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, previousRow[col]);
        }

        return maxPoints;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxPoints(int[][] points) {
        int rows = points.length, cols = points[0].length;
        long[] previousRow = new long[cols];

        // Initialize the first row
        for (int col = 0; col < cols; ++col) {
            previousRow[col] = points[0][col];
        }

        // Process each row
        for (int row = 0; row < rows - 1; ++row) {
            long[] leftMax = new long[cols];
            long[] rightMax = new long[cols];
            long[] currentRow = new long[cols];

            // Calculate left-to-right maximum
            leftMax[0] = previousRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = Math.max(leftMax[col - 1] - 1, previousRow[col]);
            }

            // Calculate right-to-left maximum
            rightMax[cols - 1] = previousRow[cols - 1];
            for (int col = cols - 2; col >= 0; --col) {
                rightMax[col] = Math.max(
                    rightMax[col + 1] - 1,
                    previousRow[col]
                );
            }

            // Calculate the current row's maximum points
            for (int col = 0; col < cols; ++col) {
                currentRow[col] = points[row + 1][col] +
                Math.max(leftMax[col], rightMax[col]);
            }

            // Update previousRow for the next iteration
            previousRow = currentRow;
        }

        // Find the maximum value in the last processed row
        long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = Math.max(maxPoints, previousRow[col]);
        }

        return maxPoints;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        rows, cols = len(points), len(points[0])
        previous_row = points[0]

        for row in range(1, rows):
            left_max = [0] * cols
            right_max = [0] * cols
            current_row = [0] * cols

            # Calculate left-to-right maximum
            left_max[0] = previous_row[0]
            for col in range(1, cols):
                left_max[col] = max(left_max[col - 1] - 1, previous_row[col])

            # Calculate right-to-left maximum
            right_max[-1] = previous_row[-1]
            for col in range(cols - 2, -1, -1):
                right_max[col] = max(right_max[col + 1] - 1, previous_row[col])

            # Calculate the current row's maximum points
            for col in range(cols):
                current_row[col] = points[row][col] + max(
                    left_max[col], right_max[col]
                )

            # Update previous_row for the next iteration
            previous_row = current_row

        # Find the maximum value in the last processed row
        return max(previous_row)
```

</details>

<br>

## Approach 2: Dynamic Programming (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int cols = points[0].size();
        vector<long long> previousRow(cols);

        for (auto& row : points) {
            // runningMax holds the maximum value generated in the previous
            // iteration of each loop
            long long runningMax = 0;

            // Left to right pass
            for (int col = 0; col < cols; ++col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                previousRow[col] = runningMax;
            }

            runningMax = 0;
            // Right to left pass
            for (int col = cols - 1; col >= 0; --col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                previousRow[col] = max(previousRow[col], runningMax) + row[col];
            }
        }

        // Find maximum points in the last row
        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, previousRow[col]);
        }

        return maxPoints;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxPoints(int[][] points) {
        int cols = points[0].length;
        long[] previousRow = new long[cols];

        for (int[] row : points) {
            // runningMax holds the maximum value generated in the previous iteration of each loop
            long runningMax = 0;

            // Left to right pass
            for (int col = 0; col < cols; ++col) {
                runningMax = Math.max(runningMax - 1, previousRow[col]);
                previousRow[col] = runningMax;
            }

            runningMax = 0;
            // Right to left pass
            for (int col = cols - 1; col >= 0; --col) {
                runningMax = Math.max(runningMax - 1, previousRow[col]);
                previousRow[col] = Math.max(previousRow[col], runningMax) +
                row[col];
            }
        }

        // Find maximum points in the last row
        long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = Math.max(maxPoints, previousRow[col]);
        }

        return maxPoints;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        cols = len(points[0])
        previous_row = [0] * cols

        for row in points:
            # running_max holds the maximum value generated in the previous iteration of each loop
            running_max = 0

            # Left to right pass
            for col in range(cols):
                running_max = max(running_max - 1, previous_row[col])
                previous_row[col] = running_max

            running_max = 0
            # Right to left pass
            for col in range(cols - 1, -1, -1):
                running_max = max(running_max - 1, previous_row[col])
                previous_row[col] = (
                    max(previous_row[col], running_max) + row[col]
                )

        # Find maximum points in the last row
        return max(previous_row)
```

</details>
