# 1975. Maximum Matrix Sum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-matrix-sum/)  
`Array` `Greedy` `Matrix`

**Problem Link:** [LeetCode 1975 - Maximum Matrix Sum](https://leetcode.com/problems/maximum-matrix-sum/)

## Problem

You are given an n x n integer matrix. You can do the following operation any number of times:

- Choose any two adjacent elements of matrix and multiply each of them by -1.

Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

### Example 1

```text
Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
```

### Example 2

```text
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
```

## Constraints

- n == matrix.length == matrix[i].length
- 2 <= n <= 250
- -105 <= matrix[i][j] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1975. Maximum Matrix Sum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Journey From Minus to Plus | C++, Java, Python3 |

## Approach: Journey From Minus to Plus

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for (auto& row : matrix) {
            for (int val : row) {
                totalSum += abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxMatrixSum(int[][] matrix) {
        long totalSum = 0;
        int minAbsVal = Integer.MAX_VALUE;
        int negativeCount = 0;

        for (int[] row : matrix) {
            for (int val : row) {
                totalSum += Math.abs(val);
                if (val < 0) {
                    negativeCount++;
                }
                minAbsVal = Math.min(minAbsVal, Math.abs(val));
            }
        }

        // Adjust if the count of negative numbers is odd
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsVal;
        }

        return totalSum;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_sum = 0
        min_abs_val = float("inf")
        negative_count = 0

        for row in matrix:
            for val in row:
                total_sum += abs(val)
                if val < 0:
                    negative_count += 1
                min_abs_val = min(min_abs_val, abs(val))

        # Adjust if the count of negative numbers is odd
        if negative_count % 2 != 0:
            total_sum -= 2 * min_abs_val

        return total_sum
```

</details>
