# 2022. Convert 1D Array Into 2D Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/convert-1d-array-into-2d-array/)  
`Array` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2022 - Convert 1D Array Into 2D Array](https://leetcode.com/problems/convert-1d-array-into-2d-array/)

## Problem

You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

### Example 1

```text
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]
Explanation: The constructed 2D array should contain 2 rows and 2 columns.
The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
```

### Example 2

```text
Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]
Explanation: The constructed 2D array should contain 1 row and 3 columns.
Put all three elements in original into the first row of the constructed 2D array.
```

### Example 3

```text
Input: original = [1,2], m = 1, n = 1
Output: []
Explanation: There are 2 elements in original.
It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
```

## Constraints

- 1 <= original.length <= 5 * 104
- 1 <= original[i] <= 105
- 1 <= m, n <= 4 * 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2022. Convert 1D Array Into 2D Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Math | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.size()) {
            // If not, return an empty array
            return {};
        }

        // Initialize the result 2D array with m rows and n columns
        vector<vector<int>> resultArray(m, vector<int>(n));

        // Initialize a counter to track the current index in the original array
        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Assign the current element from original array to the 2D
                // array
                resultArray[i][j] = original[index];
                // Move to the next element in the original array
                index++;
            }
        }

        return resultArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.length) {
            // If not, return an empty array
            return new int[0];
        }

        // Initialize the result 2D array with m rows and n columns
        int resultArray[][] = new int[m][n];

        // Initialize a counter to track the current index in the original array
        int index = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Assign the current element from original array to the 2D array
                resultArray[i][j] = original[index];
                // Move to the next element in the original array
                index++;
            }
        }

        return resultArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def construct2DArray(
        self, original: list[int], m: int, n: int
    ) -> list[list[int]]:
        # Check if it is possible to form an m x n 2D array
        if m * n != len(original):
            # If not, return an empty array
            return []

        # Initialize the result 2D array with m rows and n columns
        result_array = [[0] * n for _ in range(m)]

        # Initialize an index to track the current position in the original array
        index = 0

        for i in range(m):
            for j in range(n):
                # Assign the current element from the original array to the 2D array
                result_array[i][j] = original[index]
                # Move to the next element in the original array
                index += 1

        return result_array
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.size()) {
            // If not, return an empty array
            return {};
        }

        // Initialize the result 2D array with m rows and n columns
        vector<vector<int>> resultArray(m, vector<int>(n));

        // Fill the 2D array with elements from the original array
        for (int i = 0; i < original.size(); i++) {
            resultArray[i / n][i % n] = original[i];
        }

        return resultArray;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if it is possible to form an m x n 2D array
        if (m * n != original.length) {
            // If not, return an empty array
            return new int[0];
        }

        // Initialize the result 2D array with m rows and n columns
        int[][] resultArray = new int[m][n];

        // Fill the 2D array with elements from the original array
        for (int i = 0; i < original.length; i++) {
            resultArray[i / n][i % n] = original[i];
        }

        return resultArray;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def construct2DArray(
        self, original: list[int], m: int, n: int
    ) -> list[list[int]]:
        # Check if it is possible to form an m x n 2D array
        if m * n != len(original):
            # If not, return an empty array
            return []

        # Initialize the result 2D array with m rows and n columns
        result_array = [[0] * n for _ in range(m)]

        # Fill the 2D array with elements from the original array
        for i in range(len(original)):
            row, col = divmod(i, n)  # quotient, remainder of i / n
            result_array[row][col] = original[i]

        return result_array
```

</details>
