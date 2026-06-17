# 1351. Count Negative Numbers in a Sorted Matrix

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)  
`Array` `Binary Search` `Matrix`

**Problem Link:** [LeetCode 1351 - Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

## Problem

Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

### Example 1

```text
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```

### Example 2

```text
Input: grid = [[3,2],[1,0]]
Output: 0
```

## Constraints

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- -100 <= grid[i][j] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Count of Positive Integer and Negative Integer](https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1351. Count Negative Numbers in a Sorted Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, JavaScript, Python3, TypeScript |
| Binary Search | C++, Java, JavaScript, Python3, TypeScript |
| Linear Traversal | C++, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        // Iterate on all elements of the matrix one by one.
        for (auto& row : grid) {
            for (auto& element : row) {
                // If the current element is negative, we count it.
                if (element < 0) {
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
    public int countNegatives(int[][] grid) {
        int count = 0;
        // Iterate on all elements of the matrix one by one.
        for (int[] row : grid) {
            for (int element : row) {
                // If the current element is negative, we count it.
                if (element < 0) {
                    count++;
                }
            }
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countNegatives = function(grid) {
    let count = 0;
    // Iterate on all elements of the matrix one by one.
    grid.forEach(row => {
        row.forEach(element => {
            // If the current element is negative, we count it.
            if (element < 0) {
                count++;
            }
        });
    });
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        # Iterate on all elements of the matrix one by one.
        for row in grid:
            for element in row:
                # If the current element is negative, we count it.
                if element < 0:
                    count += 1
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countNegatives(grid: number[][]): number {
    let count = 0;
    // Iterate on all elements of the matrix one by one.
    for (const row of grid) {
        for (const element of row) {
            // If the current element is negative, we count it.
            if (element < 0) {
                count++;
            }
        }
    }
    return count;
};
```

</details>

<br>

## Approach 2: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        // Iterate on all rows of the matrix one by one.
        for (auto& row : grid) {
            // Using binary search find the index of the first negative element.
            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            // 'index' points to the first negative element,
            // which means 'n - index' is the number of all negative elements.
            count += (n - index);
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
    public int countNegatives(int[][] grid) {
        int count = 0;
        int n = grid[0].length;
        // Iterate on all rows of the matrix one by one.
        for (int[] row : grid) {
            // Using binary search find the index
            // which has the first negative element.
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = (right + left) / 2;
                if (row[mid] < 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;  
                }
            }
            // 'left' points to the first negative element,
            // which means 'n - left' is the number of all negative elements.
            count += (n - left);
        }
        return count;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countNegatives = function(grid) {
    let count = 0;
    const n = grid[0].length;
    // Iterate on all rows of the matrix one by one.
    for (const row of grid) {
        // Using binary search find the index
        // which has the first negative element.
        let left = 0, right = n - 1;
        while (left <= right) {
            const mid = Math.floor((right + left) / 2);
            if (row[mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 'left' points to the first negative element,
        // which means 'n - left' is the number of all negative elements.
        count += n - left;
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid[0])
        # Iterate on all rows of the matrix one by one.
        for row in grid:
            # Using binary search find the index
            # which has the first negative element.
            left, right = 0, n - 1
            while left <= right:
                mid = (right + left) // 2
                if row[mid] < 0:
                    right = mid - 1
                else:
                    left = mid + 1
            # 'left' points to the first negative element,
            # which means 'n - left' is the number of all negative elements.
            count += (n - left)
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countNegatives(grid: number[][]): number {
    let count = 0;
    const n = grid[0].length;
    // Iterate on all rows of the matrix one by one.
    for (const row of grid) {
        // Using binary search find the index
        // which has the first negative element.
        let left = 0;
        let right = n - 1;
        while (left <= right) {
            const mid = Math.floor((right + left) / 2);
            if (row[mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // 'left' points to the first negative element,
        // which means 'n - left' is the number of all negative elements.
        count += n - left;
    }
    return count;
};
```

</details>

<br>

## Approach 3: Linear Traversal

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        int currRowNegativeIndex = n - 1;

        // Iterate on all rows of the matrix one by one.
        for (auto& row : grid) {
            // Decrease 'currRowNegativeIndex' so that it points to current row's last positive element.
            while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0) {
                currRowNegativeIndex--;
            }
            // 'currRowNegativeIndex' points to the last positive element,
            // which means 'n - (currRowNegativeIndex + 1)' is the number of all negative elements.
            count += (n - (currRowNegativeIndex + 1));
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
int count = 0;
    int n = grid[0].length;
    int currRowNegativeIndex = n - 1;

    // Iterate on all rows of the matrix one by one.
    for (int[] row : grid) {
        // Decrease 'currRowNegativeIndex' so that it points to current row's last positive element.
        while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0) {
            currRowNegativeIndex--;
        }
        // 'currRowNegativeIndex' points to the last positive element,
        // which means 'n - (currRowNegativeIndex + 1)' is the number of all negative elements.
        count += (n - (currRowNegativeIndex + 1));
    }
    return count;
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countNegatives = function(grid) {
    let count = 0;
    let n = grid[0].length;
    let currRowNegativeIndex = n - 1;

    // Iterate on all rows of the matrix one by one.
    for (let row of grid) {
        // Decrease 'currRowNegativeIndex' so that it points to current row's last positive element.
        while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0) {
            currRowNegativeIndex--;
        }
        // 'currRowNegativeIndex' points to the last positive element,
        // which means 'n - (currRowNegativeIndex + 1)' is the number of all negative elements.
        count += (n - (currRowNegativeIndex + 1));
    }
    return count;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        count = 0
        n = len(grid[0])
        currRowNegativeIndex = n - 1

        # Iterate on all rows of the matrix one by one.
        for row in grid:
            # Decrease 'currRowNegativeIndex' so that it points to current row's last positive element.
            while currRowNegativeIndex >= 0 and row[currRowNegativeIndex] < 0:
                currRowNegativeIndex -= 1
            # 'currRowNegativeIndex' points to the last positive element,
            # which means 'n - (currRowNegativeIndex + 1)' is the number of all negative elements.
            count += (n - (currRowNegativeIndex + 1))
        return count
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countNegatives(grid: number[][]): number {
    let count = 0;
    let n = grid[0].length;
    let currRowNegativeIndex = n - 1;

    // Iterate on all rows of the matrix one by one.
    for (let row of grid) {
        // Decrease 'currRowNegativeIndex' so that it points to current row's last positive element.
        while (currRowNegativeIndex >= 0 && row[currRowNegativeIndex] < 0) {
            currRowNegativeIndex--;
        }
        // 'currRowNegativeIndex' points to the last positive element,
        // which means 'n - (currRowNegativeIndex + 1)' is the number of all negative elements.
        count += (n - (currRowNegativeIndex + 1));
    }
    return count;
};
```

</details>
