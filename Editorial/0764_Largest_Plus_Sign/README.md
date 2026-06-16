# 764. Largest Plus Sign

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/largest-plus-sign/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 764 - Largest Plus Sign](https://leetcode.com/problems/largest-plus-sign/)

## Problem

You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

### Example 1

```text
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
```

### Example 2

```text
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
```

## Constraints

- 1 <= n <= 500
- 1 <= mines.length <= 5000
- 0 <= xi, yi < n
- All the pairs (xi, yi) are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximal Square](https://leetcode.com/problems/maximal-square/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 764. Largest Plus Sign

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Brute Force [Time Limit Exceeded] | Java, Python |
| Approach #2: Dynamic Programming [Accepted] | Java, Python |

## Approach #1: Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        Set<Integer> banned = new HashSet();
        for (int[] mine: mines)
            banned.add(mine[0] * N + mine[1]);
            
        int ans = 0;
        for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
            int k = 0;
            while (k <= r && r < N-k && k <= c && c < N-k &&
                    !banned.contains((r-k)*N + c) &&
                    !banned.contains((r+k)*N + c) &&
                    !banned.contains(r*N + c-k) &&
                    !banned.contains(r*N + c+k))
                k++;
            
            ans = Math.max(ans, k);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        banned = {tuple(mine) for mine in mines}
        ans = 0
        for r in xrange(N):
            for c in xrange(N):
                k = 0
                while (k <= r < N-k and k <= c < N-k and
                        (r-k, c) not in banned and
                        (r+k, c) not in banned and
                        (r, c-k) not in banned and
                        (r, c+k) not in banned):
                    k += 1
                ans = max(ans, k)
        return ans
```

</details>

<br>

## Approach #2: Dynamic Programming [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        Set<Integer> banned = new HashSet();
        int[][] dp = new int[N][N];
        
        for (int[] mine: mines)
            banned.add(mine[0] * N + mine[1]);
        int ans = 0, count;
        
        for (int r = 0; r < N; ++r) {
            count = 0;
            for (int c = 0; c < N; ++c) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = count;
            }
            
            count = 0;
            for (int c = N-1; c >= 0; --c) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
            }
        }
        
        for (int c = 0; c < N; ++c) {
            count = 0;
            for (int r = 0; r < N; ++r) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
            }
            
            count = 0;
            for (int r = N-1; r >= 0; --r) {
                count = banned.contains(r*N + c) ? 0 : count + 1;
                dp[r][c] = Math.min(dp[r][c], count);
                ans = Math.max(ans, dp[r][c]);
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        banned = {tuple(mine) for mine in mines}
        dp = [[0] * N for _ in xrange(N)]
        ans = 0
        
        for r in xrange(N):
            count = 0
            for c in xrange(N):
                count = 0 if (r,c) in banned else count+1
                dp[r][c] = count
            
            count = 0
            for c in xrange(N-1, -1, -1):
                count = 0 if (r,c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
        
        for c in xrange(N):
            count = 0
            for r in xrange(N):
                count = 0 if (r,c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
            
            count = 0
            for r in xrange(N-1, -1, -1):
                count = 0 if (r, c) in banned else count+1
                if count < dp[r][c]: dp[r][c] = count
                if dp[r][c] > ans: ans = dp[r][c]
        
        return ans
```

</details>
