# 1072. Flip Columns For Maximum Number of Equal Rows

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)  
`Array` `Hash Table` `Matrix`

**Problem Link:** [LeetCode 1072 - Flip Columns For Maximum Number of Equal Rows](https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/)

## Problem

You are given an m x n binary matrix matrix.

You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

Return the maximum number of rows that have all values equal after some number of flips.

### Example 1

```text
Input: matrix = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.
```

### Example 2

```text
Input: matrix = [[0,1],[1,0]]
Output: 2
Explanation: After flipping values in the first column, both rows have equal values.
```

### Example 3

```text
Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping values in the first two columns, the last two rows have equal values.
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 300
- matrix[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1072. Flip Columns For Maximum Number of Equal Rows

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Hash Map | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int numCols = matrix[0].size();
        int maxIdenticalRows = 0;

        for (auto& currentRow : matrix) {
            // Create vector to store flipped version of current row
            vector<int> flippedRow(numCols);
            int identicalRowCount = 0;

            // Create flipped version of current row (0->1, 1->0)
            for (int col = 0; col < numCols; col++) {
                flippedRow[col] = 1 - currentRow[col];
            }

            // Check every row against current row and its flipped version
            for (auto& compareRow : matrix) {
                // If row matches either original or flipped pattern, increment
                // counter
                if (compareRow == currentRow || compareRow == flippedRow) {
                    identicalRowCount++;
                }
            }

            maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
        }

        return maxIdenticalRows;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int numCols = matrix[0].length;
        int maxIdenticalRows = 0;

        for (int[] currentRow : matrix) {
            // Create array to store flipped version of current row
            int[] flippedRow = new int[numCols];
            int identicalRowCount = 0;

            // Create flipped version of current row (0->1, 1->0)
            for (int col = 0; col < numCols; col++) {
                flippedRow[col] = 1 - currentRow[col];
            }

            // Check every row against current row and its flipped version
            for (int[] compareRow : matrix) {
                // If row matches either original or flipped pattern, increment counter
                if (
                    Arrays.equals(compareRow, currentRow) ||
                    Arrays.equals(compareRow, flippedRow)
                ) {
                    identicalRowCount++;
                }
            }

            maxIdenticalRows = Math.max(maxIdenticalRows, identicalRowCount);
        }

        return maxIdenticalRows;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        num_cols = len(matrix[0])
        max_identical_rows = 0

        for current_row in matrix:
            # Create flipped version using list comprehension
            flipped_row = [1 - x for x in current_row]

            # Count matching rows using list comprehension and sum
            identical_row_count = sum(
                1
                for compare_row in matrix
                if compare_row == current_row or compare_row == flipped_row
            )

            max_identical_rows = max(max_identical_rows, identical_row_count)

        return max_identical_rows
```

</details>

<br>

## Approach 2: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Map to store frequency of each pattern
        unordered_map<string, int> patternFrequency;

        for (auto& currentRow : matrix) {
            string patternBuilder = "";

            // Convert row to pattern relative to its first element
            for (int col = 0; col < currentRow.size(); col++) {
                // 'T' if current element matches first element, 'F' otherwise
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            // Convert pattern to string and update its frequency in map
            patternFrequency[patternBuilder]++;
        }

        // Find the pattern with maximum frequency
        int maxFrequency = 0;
        for (auto& entry : patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // Map to store frequency of each pattern
        Map<String, Integer> patternFrequency = new HashMap<>();

        for (int[] currentRow : matrix) {
            StringBuilder patternBuilder = new StringBuilder("");

            // Convert row to pattern relative to its first element
            for (int col = 0; col < currentRow.length; col++) {
                // 'T' if current element matches first element, 'F' otherwise
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder.append("T");
                } else {
                    patternBuilder.append("F");
                }
            }

            // Convert pattern to string and update its frequency in map
            String rowPattern = patternBuilder.toString();
            patternFrequency.put(
                rowPattern,
                patternFrequency.getOrDefault(rowPattern, 0) + 1
            );
        }

        // Find the pattern with maximum frequency
        int maxFrequency = 0;
        for (int frequency : patternFrequency.values()) {
            maxFrequency = Math.max(frequency, maxFrequency);
        }

        return maxFrequency;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        # Dictionary to store frequency of each pattern
        pattern_frequency = {}

        for current_row in matrix:
            # Convert row to pattern using list comprehension and join
            # 'T' if element matches first element, 'F' otherwise
            row_pattern = "".join(
                "T" if num == current_row[0] else "F" for num in current_row
            )

            # Update pattern frequency using dict.get() with default value
            pattern_frequency[row_pattern] = (
                pattern_frequency.get(row_pattern, 0) + 1
            )

        # Return maximum frequency using max() with default of 0
        return max(pattern_frequency.values(), default=0)
```

</details>
