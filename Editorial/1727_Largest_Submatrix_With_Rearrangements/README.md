# 1727. Largest Submatrix With Rearrangements

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)  
`Array` `Greedy` `Sorting` `Matrix`

**Problem Link:** [LeetCode 1727 - Largest Submatrix With Rearrangements](https://leetcode.com/problems/largest-submatrix-with-rearrangements/)

## Problem

You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

### Example 1

```text
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 4.
```

### Example 2

```text
Input: matrix = [[1,0,1,0,1]]
Output: 3
Explanation: You can rearrange the columns as shown above.
The largest submatrix of 1s, in bold, has an area of 3.
```

### Example 3

```text
Input: matrix = [[1,1,0],[1,0,1]]
Output: 2
Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
```

## Constraints

- m == matrix.length
- n == matrix[i].length
- 1 <= m * n <= 105
- matrix[i][j] is either 0 or 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1727. Largest Submatrix With Rearrangements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort By Height On Each Baseline Row | C++, Java, Python3 |
| Without Modifying Input | C++, Java, Python3 |
| No Sort | C++, Java, Python3 |

## Approach 1: Sort By Height On Each Baseline Row

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            
            vector<int> currRow = matrix[row];
            sort(currRow.begin(), currRow.end(), greater());
            for (int i = 0; i < n; i++) {
                ans = max(ans, currRow[i] * (i + 1));
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            
            int[] currRow = matrix[row].clone();
            Arrays.sort(currRow);
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, currRow[i] * (n - i));
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        ans = 0

        for row in range(m):
            for col in range(n):
                if matrix[row][col] != 0 and row > 0:
                    matrix[row][col] += matrix[row - 1][col]

            curr_row = sorted(matrix[row], reverse=True)
            for i in range(n):
                ans = max(ans, curr_row[i] * (i + 1))

        return ans
```

</details>

<br>

## Approach 2: Without Modifying Input

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prevRow = vector(n, 0);
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            vector<int> currRow = matrix[row];
            for (int col = 0; col < n; col++) {
                if (currRow[col] != 0) {
                    currRow[col] += prevRow[col];
                }
            }
            
            vector<int> sortedRow = currRow;
            sort(sortedRow.begin(), sortedRow.end(), greater());
            for (int i = 0; i < n; i++) {
                ans = max(ans, sortedRow[i] * (i + 1));
            }
            
            prevRow = currRow;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] prevRow = new int[n];
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            int[] currRow = matrix[row].clone();
            for (int col = 0; col < n; col++) {
                if (currRow[col] != 0) {
                    currRow[col] += prevRow[col];
                }
            }
            
            int[] sortedRow = currRow.clone();
            Arrays.sort(sortedRow);
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, sortedRow[i] * (n - i));
            }
            
            prevRow = currRow;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        prev_row = [0] * n
        ans = 0
        
        for row in range(m):
            curr_row = matrix[row][:]
            for col in range(n):
                if curr_row[col] != 0:
                    curr_row[col] += prev_row[col]

            sorted_row = sorted(curr_row, reverse=True)
            for i in range(n):
                ans = max(ans, sorted_row[i] * (i + 1))

            prev_row = curr_row

        return ans
```

</details>

<br>

## Approach 3: No Sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prevHeights;
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            vector<pair<int,int>> heights;
            vector<bool> seen = vector(n, false);
            
            for (auto [height, col] : prevHeights) {
                if (matrix[row][col] == 1) {
                    heights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }
            
            for (int col = 0; col < n; col++) {
                if (seen[col] == false && matrix[row][col] == 1) {
                    heights.push_back({1, col});
                }
            }
            
            for (int i = 0; i < heights.size(); i++) {
                ans = max(ans, heights[i].first * (i + 1));
            }
            
            prevHeights = heights;
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Pair<Integer,Integer>> prevHeights = new ArrayList();
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            List<Pair<Integer,Integer>> heights = new ArrayList();
            boolean[] seen = new boolean[n];
            
            for (Pair<Integer, Integer> pair : prevHeights) {
                int height = pair.getKey();
                int col = pair.getValue();
                if (matrix[row][col] == 1) {
                    heights.add(new Pair(height + 1, col));
                    seen[col] = true;
                }
            }
            
            for (int col = 0; col < n; col++) {
                if (seen[col] == false && matrix[row][col] == 1) {
                    heights.add(new Pair(1, col));
                }
            }
            
            for (int i = 0; i < heights.size(); i++) {
                ans = Math.max(ans, heights.get(i).getKey() * (i + 1));
            }

            prevHeights = heights;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        prev_heights = []
        ans = 0

        for row in range(m):
            heights = []
            seen = [False] * n
            
            for height, col in prev_heights:
                if matrix[row][col] == 1:
                    heights.append((height + 1, col))
                    seen[col] = True

            for col in range(n):
                if seen[col] == False and matrix[row][col] == 1:
                    heights.append((1, col))
            
            for i in range(len(heights)):
                ans = max(ans, heights[i][0] * (i + 1))
                
            prev_heights = heights

        return ans
```

</details>
