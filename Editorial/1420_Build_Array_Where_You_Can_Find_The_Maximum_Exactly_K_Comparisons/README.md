# 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)  
`Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 1420 - Build Array Where You Can Find The Maximum Exactly K Comparisons](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/)

## Problem

You are given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:

You should build the array arr which has the following properties:

- arr has exactly n integers.
- 1 <= arr[i] <= m where (0 <= i < n).
- After applying the mentioned algorithm to arr, the value search_cost is equal to k.

Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 109 + 7.

### Example 1

```text
Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
```

### Example 2

```text
Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisfy the mentioned conditions.
```

### Example 3

```text
Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
```

## Constraints

- 1 <= n <= 50
- 1 <= m <= 100
- 0 <= k <= n

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C++, Java, Python3 |
| A Different DP + Prefix Sums | Python3 |
| Space-Optimized Better DP | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int MOD = 1e9 + 7;
    int n;
    int m;
    
    int numOfArrays(int n, int m, int k) {
        memo = vector(n, vector(m + 1, vector(k + 1, -1)));
        this->n = n;
        this->m = m;
        return dp(0, 0, k);
    }
    
    int dp(int i, int maxSoFar, int remain) {
        if (i == n) {
            if (remain == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (remain < 0) {
            return 0;
        }
        
        if (memo[i][maxSoFar][remain] != -1) {
            return memo[i][maxSoFar][remain];
        }
        
        int ans = 0;
        for (int num = 1; num <= maxSoFar; num++) {
            ans = (ans + dp(i + 1, maxSoFar, remain)) % MOD;
        }

        for (int num = maxSoFar + 1; num <= m; num++) {
            ans = (ans + dp(i + 1, num, remain - 1)) % MOD;
        }
        
        memo[i][maxSoFar][remain] = ans;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][][] memo;
    int MOD = (int) 1e9 + 7;
    int n;
    int m;
    
    public int numOfArrays(int n, int m, int k) {
        memo = new int[n][m + 1][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }
        
        this.n = n;
        this.m = m;
        return dp(0, 0, k);
    }
    
    public int dp(int i, int maxSoFar, int remain) {
        if (i == n) {
            if (remain == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (remain < 0) {
            return 0;
        }
        
        if (memo[i][maxSoFar][remain] != -1) {
            return memo[i][maxSoFar][remain];
        }
        
        int ans = 0;
        for (int num = 1; num <= maxSoFar; num++) {
            ans = (ans + dp(i + 1, maxSoFar, remain)) % MOD;
        }

        for (int num = maxSoFar + 1; num <= m; num++) {
            ans = (ans + dp(i + 1, num, remain - 1)) % MOD;
        }
        
        memo[i][maxSoFar][remain] = ans;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        @cache
        def dp(i, max_so_far, remain):
            if i == n:
                if remain == 0:
                    return 1
                
                return 0
            
            ans = (max_so_far * dp(i + 1, max_so_far, remain)) % MOD
            for num in range(max_so_far + 1, m + 1):
                ans = (ans + dp(i + 1, num, remain - 1)) % MOD
                
            return ans
        
        MOD = 10 ** 9 + 7
        return dp(0, 0, k)
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector(m + 1, vector(k + 1, 0)));
        int MOD = 1e9 + 7;
        
        for (int num = 0; num < dp[0].size(); num++) {
            dp[n][num][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int maxSoFar = m; maxSoFar >= 0; maxSoFar--) {
                for (int remain = 0; remain <= k; remain++) {
                    int ans = 0;
                    for (int num = 1; num <= maxSoFar; num++) {
                        ans = (ans + dp[i + 1][maxSoFar][remain]) % MOD;
                    }
                    
                    if (remain > 0) {
                        for (int num = maxSoFar + 1; num <= m; num++) {
                            ans = (ans + dp[i + 1][num][remain - 1]) % MOD;
                        }
                    }
                    
                    dp[i][maxSoFar][remain] = ans;
                }
            }
        }

        return dp[0][0][k];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public int numOfArrays(int n, int m, int k) {    
        int[][][] dp = new int[n + 1][m + 1][k + 1];
        int MOD = (int) 1e9 + 7;
        
        for (int num = 0; num < dp[0].length; num++) {
            dp[n][num][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int maxSoFar = m; maxSoFar >= 0; maxSoFar--) {
                for (int remain = 0; remain <= k; remain++) {
                    int ans = 0;
                    for (int num = 1; num <= maxSoFar; num++) {
                        ans = (ans + dp[i + 1][maxSoFar][remain]) % MOD;
                    }
                    
                    if (remain > 0) {
                        for (int num = maxSoFar + 1; num <= m; num++) {
                            ans = (ans + dp[i + 1][num][remain - 1]) % MOD;
                        }
                    }
                    
                    dp[i][maxSoFar][remain] = ans;
                }
            }
        }

        return dp[0][0][k];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:    
        dp = [[[0] * (k + 1) for _ in range(m + 1)] for __ in range(n + 1)]
        MOD = 10 ** 9 + 7
        
        for num in range(len(dp[0])):
            dp[n][num][0] = 1
        
        for i in range(n - 1, -1, -1):
            for max_so_far in range(m, -1, -1):
                for remain in range(k + 1):
                    ans = (max_so_far * dp[i + 1][max_so_far][remain]) % MOD
    
                    if remain > 0:
                        for num in range(max_so_far + 1, m + 1):
                            ans = (ans + dp[i + 1][num][remain - 1]) % MOD
                        
                    dp[i][max_so_far][remain] = ans

        return dp[0][0][k]
```

</details>

<br>

## Approach 3: Space-Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<int>> dp(vector(m + 1, vector(k + 1, 0)));
        vector<vector<int>> prevDp(vector(m + 1, vector(k + 1, 0)));
        int MOD = 1e9 + 7;
        
        for (int num = 0; num < dp.size(); num++) {
            prevDp[num][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            dp = vector(m + 1, vector(k + 1, 0));
            for (int maxSoFar = m; maxSoFar >= 0; maxSoFar--) {
                for (int remain = 0; remain <= k; remain++) {
                    int ans = 0;
                    for (int num = 1; num <= maxSoFar; num++) {
                        ans = (ans + prevDp[maxSoFar][remain]) % MOD;
                    }
                    
                    if (remain > 0) {
                        for (int num = maxSoFar + 1; num <= m; num++) {
                            ans = (ans + prevDp[num][remain - 1]) % MOD;
                        }
                    }
                    
                    dp[maxSoFar][remain] = ans;
                }
            }
            
            prevDp = dp;
        }

        return dp[0][k];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {    
    public int numOfArrays(int n, int m, int k) {    
        int[][] dp = new int[m + 1][k + 1];
        int[][] prevDp = new int[m + 1][k + 1];
        int MOD = (int) 1e9 + 7;
        
        for (int num = 0; num < dp.length; num++) {
            prevDp[num][0] = 1;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            dp = new int[m + 1][k + 1];
            for (int maxSoFar = m; maxSoFar >= 0; maxSoFar--) {
                for (int remain = 0; remain <= k; remain++) {
                    int ans = 0;
                    for (int num = 1; num <= maxSoFar; num++) {
                        ans = (ans + prevDp[maxSoFar][remain]) % MOD;
                    }
                    
                    if (remain > 0) {
                        for (int num = maxSoFar + 1; num <= m; num++) {
                            ans = (ans + prevDp[num][remain - 1]) % MOD;
                        }
                    }
                    
                    dp[maxSoFar][remain] = ans;
                }
            }
            
            prevDp = dp;
        }

        return dp[0][k];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:    
        dp = [[0] * (k + 1) for _ in range(m + 1)]
        prev_dp = [[0] * (k + 1) for _ in range(m + 1)]
        MOD = 10 ** 9 + 7
        
        for num in range(len(prev_dp)):
            prev_dp[num][0] = 1
        
        for i in range(n - 1, -1, -1):
            dp = [[0] * (k + 1) for _ in range(m + 1)]
            for max_so_far in range(m, -1, -1):
                for remain in range(k + 1):
                    ans = (max_so_far * prev_dp[max_so_far][remain]) % MOD
    
                    if remain > 0:
                        for num in range(max_so_far + 1, m + 1):
                            ans = (ans + prev_dp[num][remain - 1]) % MOD
                        
                    dp[max_so_far][remain] = ans
                    
            prev_dp = dp

        return dp[0][k]
```

</details>

<br>

## Approach 4: A Different DP + Prefix Sums

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        # @cache memoizes the function for us
        @cache
        def dp(i, max_num, cost):
            if i == 1:
                return cost == 1
            
            # current number was not a new maximum
            ans = (max_num * dp(i - 1, max_num, cost)) % MOD
            
            # current number was a new maximum
            for num in range(1, max_num):
                ans = (ans + dp(i - 1, num, cost - 1)) % MOD
            
            return ans
            
        MOD = 10 ** 9 + 7
        ans = 0
        
        for num in range(1, m + 1):
            ans = (ans + dp(n, num, k)) % MOD
            
        return ans
```

</details>

<br>

## Approach 5: Space-Optimized Better DP

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[m + 1][k + 1];
        long long prefix[m + 1][k + 1];
        long long prevDp[m + 1][k + 1];
        long long prevPrefix[m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        memset(prefix, 0, sizeof(prefix));
        memset(prevDp, 0, sizeof(prevDp));
        memset(prevPrefix, 0, sizeof(prevPrefix));
        int MOD = 1e9 + 7;
        
        for (int num = 1; num <= m; num++) {
            dp[num][1] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                memset(dp, 0, sizeof(dp));
            }
            
            memset(prefix, 0, sizeof(prefix));
            
            for (int maxNum = 1; maxNum <= m; maxNum++) {
                for (int cost = 1; cost <= k; cost++) {
                    long long ans = (maxNum * prevDp[maxNum][cost]) % MOD;
                    ans = (ans + prevPrefix[maxNum - 1][cost - 1]) % MOD;

                    dp[maxNum][cost] += ans;
                    dp[maxNum][cost] %= MOD;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]);
                    prefix[maxNum][cost] %= MOD;
                }
            }
            
            // Can't reassign long long[][] in C++, need to manually override
            for (int maxNum = 0; maxNum <= m; maxNum++) {
                for (int cost = 0; cost <= k; cost++) {
                    prevDp[maxNum][cost] = dp[maxNum][cost];
                    prevPrefix[maxNum][cost] = prefix[maxNum][cost];
                }
            }
        }
        
        return prefix[m][k];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numOfArrays(int n, int m, int k) {
        long[][] dp = new long[m + 1][k + 1];
        long[][] prefix = new long[m + 1][k + 1];
        long[][] prevDp = new long[m + 1][k + 1];
        long[][] prevPrefix = new long[m + 1][k + 1];
        int MOD = (int) 1e9 + 7;
        
        for (int num = 1; num <= m; num++) {
            dp[num][1] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                dp = new long[m + 1][k + 1];
            }
            
            prefix = new long[m + 1][k + 1];
            
            for (int maxNum = 1; maxNum <= m; maxNum++) {
                for (int cost = 1; cost <= k; cost++) {
                    long ans = (maxNum * prevDp[maxNum][cost]) % MOD;
                    ans = (ans + prevPrefix[maxNum - 1][cost - 1]) % MOD;

                    dp[maxNum][cost] += ans;
                    dp[maxNum][cost] %= MOD;
                    
                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + dp[maxNum][cost]);
                    prefix[maxNum][cost] %= MOD;
                }
            }
            
            prevDp = dp;
            prevPrefix = prefix;
        }
        
        return (int) prefix[m][k];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(m + 1)]
        prefix = [[0] * (k + 1) for _ in range(m + 1)]
        prevDp = [[0] * (k + 1) for _ in range(m + 1)]
        prevPrefix = [[0] * (k + 1) for _ in range(m + 1)]
        MOD = 10 ** 9 + 7
        
        for num in range(1, m + 1):
            dp[num][1] = 1

        for i in range(1, n + 1):
            if i > 1:
                dp = [[0] * (k + 1) for _ in range(m + 1)]

            prefix = [[0] * (k + 1) for _ in range(m + 1)]
            for max_num in range(1, m + 1):
                for cost in range(1, k + 1):                    
                    ans = (max_num * prevDp[max_num][cost]) % MOD
                    ans = (ans + prevPrefix[max_num - 1][cost - 1]) % MOD

                    dp[max_num][cost] += ans
                    dp[max_num][cost] %= MOD
                    
                    prefix[max_num][cost] = (prefix[max_num - 1][cost] + dp[max_num][cost]) % MOD
                    
            prevDp = dp
            prevPrefix = prefix

        return prefix[m][k]
```

</details>
