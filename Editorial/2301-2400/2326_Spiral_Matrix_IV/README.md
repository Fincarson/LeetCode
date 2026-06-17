# 2326. Spiral Matrix IV

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/spiral-matrix-iv/)  
`Array` `Linked List` `Matrix` `Simulation`

**Problem Link:** [LeetCode 2326 - Spiral Matrix IV](https://leetcode.com/problems/spiral-matrix-iv/)

## Problem

You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

### Example 1

```text
Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
```

### Example 2

```text
Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
```

## Constraints

- 1 <= m, n <= 105
- 1 <= m * n <= 105
- The number of nodes in the list is in the range [1, m * n].
- 0 <= Node.val <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Spiral Matrix III](https://leetcode.com/problems/spiral-matrix-iii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2326. Spiral Matrix IV

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C++, Java, Python3 |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Store the east, south, west, north movements in a matrix.
        int i = 0, j = 0, cur_d = 0,
            movement[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> res(m, vector<int>(n, -1));

        for (; head != nullptr; head = head->next) {
            res[i][j] = head->val;
            int newi = i + movement[cur_d][0], newj = j + movement[cur_d][1];

            // If we bump into an edge or an already filled cell, change the
            // direction.
            if (min(newi, newj) < 0 || newi >= m || newj >= n ||
                res[newi][newj] != -1)
                cur_d = (cur_d + 1) % 4;
            i += movement[cur_d][0];
            j += movement[cur_d][1];
        }

        return res;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int[][] spiralMatrix(int m, int n, ListNode head) {
        // Store the east, south, west, north movements in a matrix.
        int i = 0, j = 0, cur_d = 0, movement[][] = {
            { 0, 1 },
            { 1, 0 },
            { 0, -1 },
            { -1, 0 },
        };
        int[][] res = new int[m][n];
        for (int[] row : res) {
            Arrays.fill(row, -1);
        }

        while (head != null) {
            res[i][j] = head.val;
            int newi = i + movement[cur_d][0], newj = j + movement[cur_d][1];

            // If we bump into an edge or an already filled cell, change the
            // direction.
            if (
                Math.min(newi, newj) < 0 ||
                newi >= m ||
                newj >= n ||
                res[newi][newj] != -1
            ) cur_d = (cur_d + 1) % 4;
            i += movement[cur_d][0];
            j += movement[cur_d][1];

            head = head.next;
        }

        return res;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def spiralMatrix(self, m: int, n: int, head: "ListNode") -> List[List[int]]:
        # Store the east, south, west, north movements in a matrix.
        i = 0
        j = 0
        cur_d = 0
        movement = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        res = [[-1 for _ in range(n)] for _ in range(m)]

        while head is not None:
            res[i][j] = head.val
            newi = i + movement[cur_d][0]
            newj = j + movement[cur_d][1]

            # If we bump into an edge or an already filled cell, change the
            # direction.
            if (
                min(newi, newj) < 0
                or newi >= m
                or newj >= n
                or res[newi][newj] != -1
            ):
                cur_d = (cur_d + 1) % 4
            i += movement[cur_d][0]
            j += movement[cur_d][1]

            head = head.next

        return res
```

</details>
