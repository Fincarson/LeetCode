# 343. Integer Break

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/integer-break/)  
`Math` `Dynamic Programming`

**Problem Link:** [LeetCode 343 - Integer Break](https://leetcode.com/problems/integer-break/)

## Problem

Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

### Example 1

```text
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 Ãƒâ€” 1 = 1.
```

### Example 2

```text
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 Ãƒâ€” 3 Ãƒâ€” 4 = 36.
```

## Constraints

- 2 <= n <= 58

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximize Number of Nice Divisors](https://leetcode.com/problems/maximize-number-of-nice-divisors/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 343. Integer Break

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Mathematics | C++, Java, Python3 |
| Equation | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> memo;
    
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        memo = vector(n + 1, 0);
        return dp(n);
    }
    
    int dp(int num) {
        if (num <= 3) {
            return num;
        }
        
        if (memo[num] != 0) {
            return memo[num];
        }
        
        int ans = num;
        for (int i = 2; i < num; i++) {
            ans = max(ans, i * dp(num - i));
        }
        
        memo[num] = ans;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    int[] memo;
    
    public int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        memo = new int[n + 1];
        return dp(n);
    }
    
    public int dp(int num) {
        if (num <= 3) {
            return num;
        }
        
        if (memo[num] != 0) {
            return memo[num];
        }
        
        int ans = num;
        for (int i = 2; i < num; i++) {
            ans = Math.max(ans, i * dp(num - i));
        }
        
        memo[num] = ans;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        @cache
        def dp(num):
            if num <= 3:
                return num
            
            ans = num
            for i in range(2, num):
                ans = max(ans, i * dp(num - i))
            
            return ans

        if n <= 3:
            return n - 1
        
        return dp(n)
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
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        vector<int> dp(n + 1, 0);

        // Set base cases
        for (int i = 1; i <= 3; i++) {
            dp[i] = i;
        }
        
        for (int num = 4; num <= n; num++) {
            int ans = num;
            for (int i = 2; i < num; i++) {
                ans = max(ans, i * dp[num - i]);
            }
            
            dp[num] = ans;
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
    public int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        int[] dp = new int[n + 1];

        // Set base cases
        for (int i = 1; i <= 3; i++) {
            dp[i] = i;
        }
        
        for (int num = 4; num <= n; num++) {
            int ans = num;
            for (int i = 2; i < num; i++) {
                ans = Math.max(ans, i * dp[num - i]);
            }
            
            dp[num] = ans;
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
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        
        dp = [0] * (n + 1)

        # Set base cases
        for i in [1, 2, 3]:
            dp[i] = i
            
        for num in range(4, n + 1):
            ans = num
            for i in range(2, num):
                ans = max(ans, i * dp[num - i])
            
            dp[num] = ans
        
        return dp[n]
```

</details>

<br>

## Approach 3: Mathematics

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        
        ans = 1
        while n > 4:
            ans *= 3
            n -= 3
        
        return ans * n
```

</details>

<br>

## Approach 4: Equation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        
        if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        
        return pow(3, n / 3) * 2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        if (n % 3 == 0) {
            return (int) Math.pow(3, n / 3);
        }
        
        if (n % 3 == 1) {
            return (int) Math.pow(3, (n / 3 - 1)) * 4;
        }
        
        return (int) Math.pow(3, n / 3) * 2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def integerBreak(self, n: int) -> int:
        if n <= 3:
            return n - 1
        
        if n % 3 == 0:
            return 3 ** (n // 3)
        
        if n % 3 == 1:
            return 3 ** (n // 3 - 1) * 4
        
        return 3 ** (n // 3) * 2
```

</details>
