# 646. Maximum Length of Pair Chain

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-length-of-pair-chain/)  
`Array` `Dynamic Programming` `Greedy` `Sorting`

**Problem Link:** [LeetCode 646 - Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)

## Problem

You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

### Example 1

```text
Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
```

### Example 2

```text
Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
```

## Constraints

- n == pairs.length
- 1 <= n <= 1000
- -1000 <= lefti < righti <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Non-decreasing Subsequences](https://leetcode.com/problems/non-decreasing-subsequences/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Non-decreasing Subarray From Two Arrays](https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 646. Maximum Length of Pair Chain

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Dynamic Programming | C++, Java, Python3 |
| Iterative Dynamic Programming | C++, Java, Python3 |
| Greedy | C++, Java, Python3 |

## Approach 1: Recursive Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestPairChain(int i, vector<vector<int>>& pairs, int& n, vector<int>& memo) {
        if (memo[i] != 0) {
            return memo[i];
        }
        memo[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (pairs[i][1] < pairs[j][0]) {
                memo[i] = max(memo[i], 1 + longestPairChain(j, pairs, n, memo));
            }
        }
        return memo[i];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> memo(n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, longestPairChain(i, pairs, n, memo));
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
    private int longestPairChain(int i, int[][] pairs, int n, int[] memo) {
        if (memo[i] != 0) {
            return memo[i];
        }
        memo[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (pairs[i][1] < pairs[j][0]) {
                memo[i] = Math.max(memo[i], 1 + longestPairChain(j, pairs, n, memo));
            }
        }
        return memo[i];
    }

    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int[] memo = new int[n];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, longestPairChain(i, pairs, n, memo));
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
    def longestPairChain(self, i: int, pairs: List[List[int]], n: int, memo: List[int]) -> int:
        if memo[i] != 0:
            return memo[i]
        memo[i] = 1
        for j in range(i + 1, n):
            if pairs[i][1] < pairs[j][0]:
                memo[i] = max(memo[i], 1 + self.longestPairChain(j, pairs, n, memo))
        return memo[i]

    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        pairs.sort()
        memo = [0] * n

        ans = 0
        for i in range(n):
            ans = max(ans, self.longestPairChain(i, pairs, n, memo))
        return ans
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
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
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
    public int findLongestChain(int[][] pairs) {
        int n = pairs.length;
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        int ans = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (pairs[i][1] < pairs[j][0]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            ans = Math.max(ans, dp[i]);
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
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        pairs.sort()
        dp = [1] * n
        ans = 1

        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                if pairs[i][1] < pairs[j][0]:
                    dp[i] = max(dp[i], 1 + dp[j])
            ans = max(ans, dp[i])
        return ans
```

</details>

<br>

## Approach 3: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort pairs in ascending order based on the second element.
        sort(pairs.begin(), pairs.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
        int curr = INT_MIN, ans = 0;

        for (const auto& pair : pairs) {
            if (pair[0] > curr) {
                ans++;
                curr = pair[1];
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
    public int findLongestChain(int[][] pairs) {
        // Sort pairs in ascending order based on the second element.
        Arrays.sort(pairs, (a, b) -> a[1] - b[1]);
        int curr = Integer.MIN_VALUE;
        int ans = 0;

        for (int[] pair : pairs) {
            if (pair[0] > curr) {
                ans++;
                curr = pair[1];
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
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        # Sort pairs in ascending order based on the second element.
        pairs.sort(key=lambda x: x[1])
        curr = float('-inf')
        ans = 0

        for pair in pairs:
            if pair[0] > curr:
                ans += 1
                curr = pair[1]
        return ans
```

</details>
