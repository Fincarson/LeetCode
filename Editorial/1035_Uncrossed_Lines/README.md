# 1035. Uncrossed Lines

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/uncrossed-lines/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 1035 - Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)

## Problem

You are given two integer arrays nums1 and nums2. We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

- nums1[i] == nums2[j], and
- the line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.

### Example 1

```text
Input: nums1 = [1,4,2], nums2 = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from nums1[1] = 4 to nums2[2] = 4 will intersect the line from nums1[2]=2 to nums2[1]=2.
```

### Example 2

```text
Input: nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
Output: 3
```

### Example 3

```text
Input: nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
Output: 2
```

## Constraints

- 1 <= nums1.length, nums2.length <= 500
- 1 <= nums1[i], nums2[j] <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Edit Distance](https://leetcode.com/problems/edit-distance/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1035. Uncrossed Lines

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming | C++, Java, Python |
| Iterative Dynamic Programming | C++, Java, Python |
| Dynamic Programming with Space Optimization | C++, Java, Python |

## Approach 1: Recursive Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& memo) {
        if (i <= 0 || j <= 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (nums1[i - 1] == nums2[j - 1]) {
            memo[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, memo);
        } else {
            memo[i][j] =
                max(solve(i, j - 1, nums1, nums2, memo), solve(i - 1, j, nums1, nums2, memo));
        }
        return memo[i][j];
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> memo(n1 + 1, vector<int>(n2 + 1, -1));

        return solve(n1, n2, nums1, nums2, memo);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int solve(int i, int j, int[] nums1, int[] nums2, int[][] memo) {
        if (i <= 0 || j <= 0) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (nums1[i - 1] == nums2[j - 1]) {
            memo[i][j] = 1 + solve(i - 1, j - 1, nums1, nums2, memo);
        } else {
            memo[i][j] =
                Math.max(solve(i, j - 1, nums1, nums2, memo), solve(i - 1, j, nums1, nums2, memo));
        }
        return memo[i][j];
    }

    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int[][] memo = new int[n1 + 1][n2 + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        return solve(n1, n2, nums1, nums2, memo);
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxUncrossedLines(self, nums1, nums2):
        n1 = len(nums1)
        n2 = len(nums2)

        memo = {}

        def solve(i, j):
            if i <= 0 or j <= 0:
                return 0

            if (i, j) in memo:
                return memo[(i, j)]

            if nums1[i - 1] == nums2[j - 1]:
                memo[(i, j)] = 1 + solve(i - 1, j - 1)
            else:
                memo[(i, j)] = max(solve(i - 1, j), solve(i, j - 1))
            return memo[(i, j)]

        return solve(n1, n2)
```

</details>

<br>

## Approach 2: Iterative Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int[][] dp = new int[n1+1][n2+1];

         for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n1][n2];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxUncrossedLines(self, nums1, nums2):
        n1 = len(nums1)
        n2 = len(nums2)
        
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]

        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])

        return dp[n1][n2]
```

</details>

<br>

## Approach 3: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> dp(n2 + 1), dpPrev(n2 + 1);

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = max(dp[j - 1], dpPrev[j]);
                }
            }
            dpPrev = dp;
        }

        return dp[n2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;

        int[] dp = new int[n2 + 1];
        int[] dpPrev = new int[n2 + 1];

         for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + dpPrev[j - 1];
                } else {
                    dp[j] = Math.max(dp[j - 1], dpPrev[j]);
                }
            }
            dpPrev = dp.clone();
        }

        return dp[n2];
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def maxUncrossedLines(self, nums1, nums2):
        n1 = len(nums1)
        n2 = len(nums2)
        
        dp = [0] * (n2 + 1)
        dpPrev = [0] * (n2 + 1)

        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[j] = 1 + dpPrev[j - 1]
                else:
                    dp[j] = max(dp[j - 1], dpPrev[j])
            dpPrev = dp[:]

        return dp[n2]
```

</details>
