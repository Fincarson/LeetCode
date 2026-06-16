# 1269. Number of Ways to Stay in the Same Place After Some Steps

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 1269 - Number of Ways to Stay in the Same Place After Some Steps](https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)

## Problem

You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

### Example 1

```text
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
```

### Example 2

```text
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay
```

### Example 3

```text
Input: steps = 4, arrLen = 2
Output: 8
```

## Constraints

- 1 <= steps <= 500
- 1 <= arrLen <= 106

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1269. Number of Ways to Stay in the Same Place After Some Steps

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int MOD = 1e9 + 7;
    int arrLen;
    
    int dp(int curr, int remain) {
        if (remain == 0) {
            if (curr == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1);
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }
    
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps);
        this->arrLen = arrLen;
        memo = vector(arrLen, vector(steps + 1, -1));
        return dp(0, steps);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[][] memo;
    int MOD = (int) 1e9 + 7;
    int arrLen;
    
    public int dp(int curr, int remain) {
        if (remain == 0) {
            if (curr == 0) {
                return 1;
            }
            
            return 0;
        }
        
        if (memo[curr][remain] != -1) {
            return memo[curr][remain];
        }

        int ans = dp(curr, remain - 1);
        if (curr > 0) {
            ans = (ans + dp(curr - 1, remain - 1)) % MOD;
        }
        
        if (curr < arrLen - 1) {
            ans = (ans + dp(curr + 1, remain - 1)) % MOD;
        }
        
        memo[curr][remain] = ans;
        return ans;
    }
    
    public int numWays(int steps, int arrLen) {
        arrLen = Math.min(arrLen, steps);
        this.arrLen = arrLen;
        memo = new int[arrLen][steps + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        
        return dp(0, steps);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        @cache
        def dp(curr, remain):
            if remain == 0:
                if curr == 0:
                    return 1
                
                return 0
            
            ans = dp(curr, remain - 1)
            if curr > 0:
                ans = (ans + dp(curr - 1, remain - 1)) % MOD
            
            if curr < arrLen - 1:
                ans = (ans + dp(curr + 1, remain - 1)) % MOD
                
            return ans
        
        MOD = 10 ** 9 + 7
        return dp(0, steps)
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
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(arrLen, vector(steps + 1, 0));
        dp[0][0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = dp[curr][remain - 1];
                
                if (curr > 0) {
                    ans = (ans + dp[curr - 1][remain - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + dp[curr + 1][remain - 1]) % MOD;
                }
                
                dp[curr][remain] = ans;
            }
        }
        
        return dp[0][steps];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numWays(int steps, int arrLen) {
        int MOD = (int) 1e9 + 7;
        arrLen = Math.min(arrLen, steps);
        int[][] dp = new int[arrLen][steps + 1];
        dp[0][0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = dp[curr][remain - 1];
                
                if (curr > 0) {
                    ans = (ans + dp[curr - 1][remain - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + dp[curr + 1][remain - 1]) % MOD;
                }
                
                dp[curr][remain] = ans;
            }
        }
        
        return dp[0][steps];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10 ** 9 + 7
        arrLen = min(arrLen, steps)
        dp = [[0] * (steps + 1) for _ in range(arrLen)]
        dp[0][0] = 1
        
        for remain in range(1, steps + 1):
            for curr in range(arrLen - 1, -1, -1):
                ans = dp[curr][remain - 1]
                
                if curr > 0:
                    ans = (ans + dp[curr - 1][remain - 1]) % MOD
                
                if curr < arrLen - 1:
                    ans = (ans + dp[curr + 1][remain - 1]) % MOD
                
                dp[curr][remain] = ans
        
        return dp[0][steps]
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
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        arrLen = min(arrLen, steps);
        vector<int> dp(arrLen, 0);
        vector<int> prevDp(arrLen, 0);
        prevDp[0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            dp = vector(arrLen, 0);
            
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = prevDp[curr];
                
                if (curr > 0) {
                    ans = (ans + prevDp[curr - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + prevDp[curr + 1]) % MOD;
                }
                
                dp[curr] = ans;
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numWays(int steps, int arrLen) {
        int MOD = (int) 1e9 + 7;
        arrLen = Math.min(arrLen, steps);
        int[] dp = new int[arrLen];
        int[] prevDp = new int[arrLen];
        prevDp[0] = 1;
        
        for (int remain = 1; remain <= steps; remain++) {
            dp = new int[arrLen];
            
            for (int curr = arrLen - 1; curr >= 0; curr--) {
                int ans = prevDp[curr];
                if (curr > 0) {
                    ans = (ans + prevDp[curr - 1]) % MOD;
                }
                
                if (curr < arrLen - 1) {
                    ans = (ans + prevDp[curr + 1]) % MOD;
                }
                
                dp[curr] = ans;
            }
            
            prevDp = dp;
        }
        
        return dp[0];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        MOD = 10 ** 9 + 7
        arrLen = min(arrLen, steps)
        dp = [0] * (arrLen)
        prevDp = [0] * (arrLen)
        prevDp[0] = 1
        
        for remain in range(1, steps + 1):
            dp = [0] * (arrLen)
            
            for curr in range(arrLen - 1, -1, -1):
                ans = prevDp[curr]
                
                if curr > 0:
                    ans = (ans + prevDp[curr - 1]) % MOD
                
                if curr < arrLen - 1:
                    ans = (ans + prevDp[curr + 1]) % MOD
                
                dp[curr] = ans
                
            prevDp = dp
        
        return dp[0]
```

</details>
