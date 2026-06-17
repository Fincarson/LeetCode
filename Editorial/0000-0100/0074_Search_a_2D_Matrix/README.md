# 74. Search a 2D Matrix

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/search-a-2d-matrix/)  
`Array` `Binary Search` `Matrix`

**Problem Link:** [LeetCode 74 - Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

## Problem

You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

### Example 1

```text
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

### Example 2

```text
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 100
- -104 <= matrix[i][j], target <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Split Message Based on Limit](https://leetcode.com/problems/split-message-based-on-limit/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 74. Search a 2D Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool searchMatrix(int** matrix, int matrixRowSize, int* matrixColSize,
                  int target) {
    if (matrixRowSize == 0) return false;
    int n = matrixColSize[0];
    int left = 0, right = matrixRowSize * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = (left + right) / 2;
        pivotElement = matrix[pivotIdx / n][pivotIdx % n];
        if (target == pivotElement)
            return true;
        else {
            if (target < pivotElement)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0)
        return false;

    int n = matrix[0].size();
    // binary search
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
      pivotIdx = (left + right) / 2;
      pivotElement = matrix[pivotIdx / n][pivotIdx % n];
      if (target == pivotElement)
          return true;
      else {
        if (target < pivotElement)
            right = pivotIdx - 1;
        else
            left = pivotIdx + 1;
      }
    }
    return false;
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool SearchMatrix(int[][] matrix, int target) {
        int m = matrix.Length;
        if (m == 0)
            return false;
        int n = matrix[0].Length;
        int left = 0, right = m * n - 1;
        int pivotIdx, pivotElement;
        while (left <= right) {
            pivotIdx = (left + right) / 2;
            pivotElement = matrix[pivotIdx / n][pivotIdx % n];
            if (target == pivotElement)
                return true;
            else {
                if (target < pivotElement)
                    right = pivotIdx - 1;
                else
                    left = pivotIdx + 1;
            }
        }

        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func searchMatrix(matrix [][]int, target int) bool {
    m := len(matrix)
    if m == 0 {
        return false
    }
    n := len(matrix[0])
    left, right := 0, m*n-1
    var pivotIdx, pivotElement int
    for left <= right {
        pivotIdx = (left + right) / 2
        pivotElement = matrix[pivotIdx/n][pivotIdx%n]
        if target == pivotElement {
            return true
        } else {
            if target < pivotElement {
                right = pivotIdx - 1
            } else {
                left = pivotIdx + 1
            }
        }
    }
    return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if (m == 0) return false;
        int n = matrix[0].length;

        // binary search
        int left = 0, right = m * n - 1;
        int pivotIdx, pivotElement;
        while (left <= right) {
            pivotIdx = (left + right) / 2;
            pivotElement = matrix[pivotIdx / n][pivotIdx % n];
            if (target == pivotElement) return true;
            else {
                if (target < pivotElement) right = pivotIdx - 1;
                else left = pivotIdx + 1;
            }
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var searchMatrix = function (matrix, target) {
    let m = matrix.length;
    if (m == 0) return false;
    let n = matrix[0].length;
    let left = 0,
        right = m * n - 1;
    let pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = Math.floor((left + right) / 2);
        pivotElement = matrix[Math.floor(pivotIdx / n)][pivotIdx % n];
        if (target == pivotElement) return true;
        else {
            if (target < pivotElement) right = pivotIdx - 1;
            else left = pivotIdx + 1;
        }
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])

        # binary search
        left, right = 0, m * n - 1
        while left <= right:
            pivot_idx = (left + right) // 2
            pivot_element = matrix[pivot_idx // n][pivot_idx % n]
            if target == pivot_element:
                return True
            else:
                if target < pivot_element:
                    right = pivot_idx - 1
                else:
                    left = pivot_idx + 1
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function searchMatrix(matrix: number[][], target: number): boolean {
    let m = matrix.length;
    if (m == 0) return false;
    let n = matrix[0].length;
    let left = 0,
        right = m * n - 1;
    let pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = Math.floor((left + right) / 2);
        pivotElement = matrix[Math.floor(pivotIdx / n)][pivotIdx % n];
        if (target == pivotElement) return true;
        else {
            if (target < pivotElement) right = pivotIdx - 1;
            else left = pivotIdx + 1;
        }
    }
    return false;
}
```

</details>
