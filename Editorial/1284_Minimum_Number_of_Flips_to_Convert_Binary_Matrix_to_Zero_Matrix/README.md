# 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)  
`Array` `Hash Table` `Bit Manipulation` `Breadth-First Search` `Matrix`

**Problem Link:** [LeetCode 1284 - Minimum Number of Flips to Convert Binary Matrix to Zero Matrix](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

## Problem

Given a m x n binary matrix mat. In one step, you can choose one cell and flip it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighbors if they share one edge.

Return the minimum number of steps required to convert mat to a zero matrix or -1 if you cannot.

A binary matrix is a matrix with all cells equal to 0 or 1 only.

A zero matrix is a matrix with all cells equal to 0.

### Example 1

```text
Input: mat = [[0,0],[0,1]]
Output: 3
Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.
```

### Example 2

```text
Input: mat = [[0]]
Output: 0
Explanation: Given matrix is a zero matrix. We do not need to change it.
```

### Example 3

```text
Input: mat = [[1,0,0],[1,0,0]]
Output: -1
Explanation: Given matrix cannot be a zero matrix.
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 3
- mat[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Operations to Remove Adjacent Ones in Matrix](https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Remove All Ones With Row and Column Flips](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Remove All Ones With Row and Column Flips II](https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Smart Enumeration | C++, Java |

## Approach 1: Smart Enumeration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    int better(int x, int y) { return x < 0 || (y >= 0 && y < x) ? y : x; }

    int dfs(const vector<vector<int>>& mat, vector<int>& operations) {
        if (operations.size() == mat[0].size()) {
            vector<int> changed = vector<int>(mat[0].size());
            vector<int> last_state = operations;
            int maybe = 0;
            for (const vector<int>& row : mat) {
                vector<int> state = changed;
                for (int j = 0; j < row.size(); ++j) {
                    state[j] ^= row[j];
                    if (last_state[j]) {
                        state[j] ^= 1;
                        if (j) {
                            state[j - 1] ^= 1;
                        }
                        if (j + 1 < row.size()) {
                            state[j + 1] ^= 1;
                        }
                        ++maybe;
                    }
                }
                changed = last_state;
                last_state = state;
            }
            for (int x : last_state) {
                if (x) {
                    return -1;
                }
            }
            return maybe;
        }
        operations.push_back(0);
        const int maybe1 = dfs(mat, operations);
        operations.back() = 1;
        const int maybe2 = dfs(mat, operations);
        operations.pop_back();
        return better(maybe1, maybe2);
    }

public:
    int minFlips(vector<vector<int>>& mat) {
        vector<int> operations;
        return dfs(mat, operations);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
    private int better(int x, int y) {
        return x < 0 || (y >= 0 && y < x)? y : x;
    }
    
    private int dfs(int[][] mat, List<Integer> operations) {
        if (operations.size() == mat[0].length) {
            int[] changed = new int[mat[0].length];
            int[] lastState = operations
                .stream()
                .mapToInt(Integer::intValue)
                .toArray();
            int maybe = 0;
            for (int[] row : mat) {
                int[] state = changed;
                for (int j = 0; j < row.length; ++j) {
                    state[j] ^= row[j];
                    if (lastState[j] == 1) {
                        state[j] ^= 1;
                        if (j > 0) {
                            state[j - 1] ^= 1;
                        }
                        if (j + 1 < row.length) {
                            state[j + 1] ^= 1;
                        }
                        ++maybe;
                    }
                }
                changed = lastState;
                lastState = state;
            }
            for (int x : lastState) {
                if (x == 1) {
                    return -1;
                }
            }
            return maybe;
        }
        operations.add(0);
        final int maybe1 = dfs(mat, operations);
        operations.set(operations.size() - 1, 1);
        final int maybe2 = dfs(mat, operations);
        operations.remove(operations.size() - 1);
        return better(maybe1, maybe2);
    }
    
    public int minFlips(int[][] mat) {
        return dfs(mat, new ArrayList<>());  
    }
}
```

</details>
