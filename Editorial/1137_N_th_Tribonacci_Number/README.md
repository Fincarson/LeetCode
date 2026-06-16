# 1137. N-th Tribonacci Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/n-th-tribonacci-number/)  
`Math` `Dynamic Programming` `Memoization`

**Problem Link:** [LeetCode 1137 - N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/)

## Problem

The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

### Example 1

```text
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

### Example 2

```text
Input: n = 25
Output: 1389537
```

## Constraints

- 0 <= n <= 37
- The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1137. N-th Tribonacci Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Top Down) | C++, Java, Python3 |
| Dynamic Programming (Bottom Up) | C++, Java, Python3 |
| Better Dynamic Programming (Bottom Up) | C++, Java, Python |

## Approach 1: Dynamic Programming (Top Down)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    unordered_map<int, int> dp = {
        {0, 0},
        {1, 1},
        {2, 1}
    };
    
    int dfs(int i) {
        if (dp.count(i)) {
            return dp[i];
        }
        
        int answer = dfs(i - 1) + dfs(i - 2) + dfs(i - 3);
        dp[i] = answer;
        return answer;
    }
    
public:
    int tribonacci(int n) {
        return dfs(n);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    private Map<Integer, Integer> dp = new HashMap<>(){{
            put(0, 0);
            put(1, 1);
            put(2, 1);
    }};
    
    private int dfs(int i) {
        if (dp.containsKey(i)) {
            return dp.get(i);
        }
        
        int answer = dfs(i - 1) + dfs(i - 2) + dfs(i - 3);
        dp.put(i, answer);
        return answer;
    }
    
    public int tribonacci(int n) {
        return dfs(n);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tribonacci(self, n: int) -> int:
        dp = {0: 0, 1: 1, 2: 1}
        def dfs(i):
            if i in dp:
                return dp[i]
            dp[i] = dfs(i - 1) + dfs(i - 2) + dfs(i - 3)
            return dp[i]
        
        return dfs(n)
```

</details>

<br>

## Approach 2: Dynamic Programming (Bottom Up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return n > 0 ? 1 : 0;
        }
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int tribonacci(int n) {
        if (n < 3) {
            return n > 0 ? 1 : 0;
        }
        
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        
        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n else 0
        dp = [0] * (n + 1)
        dp[1] = dp[2] = 1
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]
        return dp[n]
```

</details>

<br>

## Approach 3: Better Dynamic Programming (Bottom Up)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if (n < 3) {
            return n > 0 ? 1 : 0;
        }
        
        int a = 0, b = 1, c = 1;
        
        for (int i = 0; i < n - 2; ++i) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        
        return c;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int tribonacci(int n) {
        if (n < 3) {
            return n > 0 ? 1 : 0;
        }
        
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < n - 2; ++i) {
            int tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        
        return c;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 3:
            return 1 if n else 0
        a, b, c = 0, 1, 1
        for _ in range(n - 2):
            a, b, c = b, c, a + b + c
        return c
```

</details>
