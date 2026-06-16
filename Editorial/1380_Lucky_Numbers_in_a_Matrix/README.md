# 1380. Lucky Numbers in a Matrix

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/lucky-numbers-in-a-matrix/)  
`Array` `Matrix`

**Problem Link:** [LeetCode 1380 - Lucky Numbers in a Matrix](https://leetcode.com/problems/lucky-numbers-in-a-matrix/)

## Problem

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

### Example 1

```text
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

### Example 2

```text
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

### Example 3

```text
Input: matrix = [[7,8],[1,2]]
Output: [7]
Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
```

## Constraints

- m == mat.length
- n == mat[i].length
- 1 <= n, m <= 50
- 1 <= matrix[i][j] <= 105.
- All elements in the matrix are distinct.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1380. Lucky Numbers in a Matrix

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Simulation | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        vector<int> rowMin;
        for (int i = 0; i < N; i++) {

            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin);
        }

        vector<int> colMax;
        for (int i = 0; i < M; i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            colMax.push_back(cMax);
        }

        vector<int> luckyNumbers;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNumbers.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int N = matrix.length, M = matrix[0].length;

        List<Integer> rowMin = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int rMin = Integer.MAX_VALUE;
            for (int j = 0; j < M; j++) {
                rMin = Math.min(rMin, matrix[i][j]);
            }
            rowMin.add(rMin);
        }

        List<Integer> colMax = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int cMax = Integer.MIN_VALUE;
            for (int j = 0; j < N; j++) {
                cMax = Math.max(cMax, matrix[j][i]);
            }
            colMax.add(cMax);
        }

        List<Integer> luckyNumbers = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == rowMin.get(i) && matrix[i][j] == colMax.get(j)) {
                    luckyNumbers.add(matrix[i][j]);
                }
            }
        }

        return luckyNumbers;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def luckyNumbers(self, matrix):
        N = len(matrix)
        M = len(matrix[0])

        rowMin = []
        for i in range(N):
            rMin = float('inf')
            for j in range(M):
                rMin = min(rMin, matrix[i][j])
            rowMin.append(rMin)

        colMax = []
        for i in range(M):
            cMax = float('-inf')
            for j in range(N):
                cMax = max(cMax, matrix[j][i])
            colMax.append(cMax)

        luckyNumbers = []
        for i in range(N):
            for j in range(M):
                if matrix[i][j] == rowMin[i] and matrix[i][j] == colMax[j]:
                    luckyNumbers.append(matrix[i][j])

        return luckyNumbers
```

</details>

<br>

## Approach 2: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();
        
        int rMinMax = INT_MIN;
        for (int i = 0; i < N; i++) {

            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        }
        
        int cMaxMin = INT_MAX;
        for (int i = 0; i < M; i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            cMaxMin = min(cMaxMin, cMax);
        }
        
        if (rMinMax == cMaxMin) {
            return {rMinMax};
        }
        
        return {};
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int N = matrix.length, M = matrix[0].length;

        int rMinMax = Integer.MIN_VALUE;
        for (int i = 0; i < N; i++) {
            int rMin = Integer.MAX_VALUE;
            for (int j = 0; j < M; j++) {
                rMin = Math.min(rMin, matrix[i][j]);
            }
            rMinMax = Math.max(rMinMax, rMin);
        }

        int cMaxMin = Integer.MAX_VALUE;
        for (int i = 0; i < M; i++) {
            int cMax = Integer.MIN_VALUE;
            for (int j = 0; j < N; j++) {
                cMax = Math.max(cMax, matrix[j][i]);
            }
            cMaxMin = Math.min(cMaxMin, cMax);
        }

        if (rMinMax == cMaxMin) {
            return new ArrayList<>(Arrays.asList(rMinMax));
        }

        return new ArrayList<>();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        N, M = len(matrix), len(matrix[0])

        r_min_max = float('-inf')
        for i in range(N):
            r_min = min(matrix[i])  
            r_min_max = max(r_min_max, r_min)

        c_max_min = float('inf')
        for i in range(M):
            c_max = max(matrix[j][i] for j in range(N))
            c_max_min = min(c_max_min, c_max)

        if r_min_max == c_max_min:
            return [r_min_max]
        else:
            return []
```

</details>
