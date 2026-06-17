# 598. Range Addition II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/range-addition-ii/)  
`Array` `Math`

**Problem Link:** [LeetCode 598 - Range Addition II](https://leetcode.com/problems/range-addition-ii/)

## Problem

You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

Count and return the number of maximum integers in the matrix after performing all the operations.

### Example 1

```text
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
```

### Example 2

```text
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

### Example 3

```text
Input: m = 3, n = 3, ops = []
Output: 9
```

## Constraints

- 1 <= m, n <= 4 * 104
- 0 <= ops.length <= 104
- ops[i].length == 2
- 1 <= ai <= m
- 1 <= bi <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Range Addition](https://leetcode.com/problems/range-addition/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sum of Matrix After Queries](https://leetcode.com/problems/sum-of-matrix-after-queries/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 598. Range Addition II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Single Pass [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        int[][] arr = new int[m][n];
        for (int[] op: ops) {
            for (int i = 0; i < op[0]; i++) {
                for (int j = 0; j < op[1]; j++) {
                    arr[i][j] += 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == arr[0][0])
                    count++;
            }
        }
        return count;
    }
}
```

</details>

<br>

## Approach #2 Single Pass [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        for (int[] op: ops) {
            m = Math.min(m, op[0]);
            n = Math.min(n, op[1]);
        }
        return m * n;
    }
}
```

</details>
