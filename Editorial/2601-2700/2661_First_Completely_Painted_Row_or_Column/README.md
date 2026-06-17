# 2661. First Completely Painted Row or Column

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/first-completely-painted-row-or-column/)  
`Array` `Hash Table` `Matrix`

**Problem Link:** [LeetCode 2661 - First Completely Painted Row or Column](https://leetcode.com/problems/first-completely-painted-row-or-column/)

## Problem

You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

### Example 1

```text
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
```

### Example 2

```text
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
```

## Constraints

- m == mat.length
- n = mat[i].length
- arr.length == m * n
- 1 <= m, n <= 105
- 1 <= m * n <= 105
- 1 <= arr[i], mat[r][c] <= m * n
- All the integers of arr are unique.
- All the integers of mat are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if Every Row and Column Contains All Numbers](https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Difference Between Ones and Zeros in Row and Column](https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2661. First Completely Painted Row or Column

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute-Force | C++, Java, Python3 |
| Brute Force Optimized with Counting | C++, Java, Python3 |
| Reverse Mapping | C++, Java, Python3 |

## Approach 1: Brute-Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        unordered_map<int, pair<int, int>> numToPos;
        // Populate numToPos map by iterating over the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = numToPos[num];
            mat[row][col] = -mat[row][col];  // mark as seen

            // Check if the row or column is completely painted
            if (checkRow(row, mat) || checkColumn(col, mat)) {
                return i;
            }
        }

        return -1;  // This line will never be reached as per the problem
                    // statement
    }

private:
    bool checkRow(int row, vector<vector<int>>& mat) {
        // Return true if row is completely seen
        for (int col = 0; col < mat[0].size(); col++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }

    bool checkColumn(int col, vector<vector<int>>& mat) {
        // Return true if col is completely seen
        for (int row = 0; row < mat.size(); row++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int numRows = mat.length, numCols = mat[0].length;
        Map<Integer, Pair<Integer, Integer>> numToPos = new HashMap<>();
        // Populate the numToPos map by iterating over the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos.put(value, new Pair(row, col));
            }
        }

        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            Pair<Integer, Integer> pos = numToPos.get(num);
            int row = pos.getKey();
            int col = pos.getValue();
            mat[row][col] = -mat[row][col]; // mark as seen

            // Check if the row or column is completely painted
            if (checkRow(row, mat) || checkColumn(col, mat)) {
                return i;
            }
        }

        return -1; // This line will never be reached as per the problem statement
    }

    private boolean checkRow(int row, int[][] mat) {
        // Return true if row is completely seen
        for (int col = 0; col < mat[0].length; col++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }

    private boolean checkColumn(int col, int[][] mat) {
        // Return true if col is completely seen
        for (int row = 0; row < mat.length; row++) {
            if (mat[row][col] > 0) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def firstCompleteIndex(self, arr, mat):
        num_rows, num_cols = len(mat), len(mat[0])
        num_to_pos = {}
        # Populate the num_to_pos map by iterating over the matrix
        for row in range(num_rows):
            for col in range(num_cols):
                value = mat[row][col]
                num_to_pos[value] = (row, col)

        for i in range(len(arr)):
            num = arr[i]
            row, col = num_to_pos[num]
            mat[row][col] = -mat[row][col]  # mark as seen

            # Check if the row or column is completely painted
            if self._check_row(row, mat) or self._check_column(col, mat):
                return i

        # This line will never be reached as per the problem statement
        return -1

    def _check_row(self, row, mat):
        # Return true if row is completely seen
        for col in range(len(mat[0])):
            if mat[row][col] > 0:
                return False
        return True

    def _check_column(self, col, mat):
        # Return true if col is completely seen
        for row in range(len(mat)):
            if mat[row][col] > 0:
                return False
        return True
```

</details>

<br>

## Approach 2: Brute Force Optimized with Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int numRows = mat.size(), numCols = mat[0].size();
        vector<int> rowCount(numRows), colCount(numCols);
        unordered_map<int, pair<int, int>> numToPos;

        // Create a map to store the position of each number in the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos[value] = {row, col};
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            auto [row, col] = numToPos[num];

            // Increment the count for the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            // Check if the row or column is completely painted
            if (rowCount[row] == numCols || colCount[col] == numRows) {
                return i;
            }
        }

        return -1;  // This line will never be reached as per the problem
                    // statement
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int firstCompleteIndex(int[] arr, int[][] mat) {
        int numRows = mat.length;
        int numCols = mat[0].length;
        int[] rowCount = new int[numRows];
        int[] colCount = new int[numCols];
        Map<Integer, int[]> numToPos = new HashMap<>();

        // Create a map to store the position of each number in the matrix
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                int value = mat[row][col];
                numToPos.put(value, new int[] { row, col });
            }
        }

        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int[] pos = numToPos.get(num);
            int row = pos[0];
            int col = pos[1];

            // Increment the count for the corresponding row and column
            rowCount[row]++;
            colCount[col]++;

            // Check if the row or column is completely painted
            if (rowCount[row] == numCols || colCount[col] == numRows) {
                return i;
            }
        }

        return -1; // This line will never be reached as per the problem statement
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        num_rows, num_cols = len(mat), len(mat[0])
        row_count, col_count = [0] * num_rows, [0] * num_cols
        num_to_pos = {}

        # Create a map to store the position of each number in the matrix
        for row in range(num_rows):
            for col in range(num_cols):
                num_to_pos[mat[row][col]] = [row, col]

        for i in range(len(arr)):
            num = arr[i]
            row, col = num_to_pos[num]

            # Increment the count for the corresponding row and column
            row_count[row] += 1
            col_count[col] += 1

            # Check if the row or column is completely painted
            if row_count[row] == num_cols or col_count[col] == num_rows:
                return i

        # This line will never be reached as per the problem statement
        return -1
```

</details>

<br>

## Approach 3: Reverse Mapping

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Map to store the index of each number in the arr
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i;
        }

        int result = INT_MAX;
        int numRows = mat.size();
        int numCols = mat[0].size();

        // Check for the earliest row to be completely painted
        for (int row = 0; row < numRows; row++) {
            // Tracks the greatest index in this column
            int lastElementIndex = INT_MIN;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this row is fully
            // painted
            result = min(result, lastElementIndex);
        }

        // Check for the earliest column to be completely painted
        for (int col = 0; col < numCols; col++) {
            // Tracks the greatest index in this column
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this column is fully
            // painted
            result = min(result, lastElementIndex);
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

    public int firstCompleteIndex(int[] arr, int[][] mat) {
        // Map to store the index of each number in the arr
        Map<Integer, Integer> numToIndex = new HashMap<Integer, Integer>();
        for (int i = 0; i < arr.length; i++) {
            numToIndex.put(arr[i], i);
        }

        int result = Integer.MAX_VALUE;
        int numRows = mat.length;
        int numCols = mat[0].length;

        // Check for the earliest row to be completely painted
        for (int row = 0; row < numRows; row++) {
            // Tracks the greatest index in this row
            int lastElementIndex = Integer.MIN_VALUE;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex.get(mat[row][col]);
                lastElementIndex = Math.max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this row is fully painted
            result = Math.min(result, lastElementIndex);
        }

        // Check for the earliest column to be completely painted
        for (int col = 0; col < numCols; col++) {
            int lastElementIndex = Integer.MIN_VALUE;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex.get(mat[row][col]);
                lastElementIndex = Math.max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this column is fully painted
            result = Math.min(result, lastElementIndex);
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
    def firstCompleteIndex(self, arr, mat):
        # Map to store the index of each number in the arr
        num_to_index = {}
        for i in range(len(arr)):
            num_to_index[arr[i]] = i

        result = float("inf")
        num_rows, num_cols = len(mat), len(mat[0])

        # Check for the earliest row to be completely painted
        for row in range(num_rows):
            # Tracks the greatest index in this row
            last_element_index = float("-inf")
            for col in range(num_cols):
                index_val = num_to_index[mat[row][col]]
                last_element_index = max(last_element_index, index_val)

            # Update result with the minimum index where this row is fully painted
            result = min(result, last_element_index)

        # Check for the earliest column to be completely painted
        for col in range(num_cols):
            last_element_index = float("-inf")
            for row in range(num_rows):
                index_val = num_to_index[mat[row][col]]
                last_element_index = max(last_element_index, index_val)

            # Update result with the minimum index where this column is fully painted
            result = min(result, last_element_index)

        return result
```

</details>
