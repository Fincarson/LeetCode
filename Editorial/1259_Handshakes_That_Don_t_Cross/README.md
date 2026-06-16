# 1259. Handshakes That Don't Cross

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/handshakes-that-dont-cross/)  
`Math` `Dynamic Programming`

**Problem Link:** [LeetCode 1259 - Handshakes That Don't Cross](https://leetcode.com/problems/handshakes-that-dont-cross/)

## Problem

You are given an even number of people numPeople that stand around a circle and each person shakes hands with someone else so that there are numPeople / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since the answer could be very large, return it modulo 109 + 7.

### Example 1

```text
Input: numPeople = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].
```

### Example 2

```text
Input: numPeople = 6
Output: 5
```

## Constraints

- 2 <= numPeople <= 1000
- numPeople is even.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1259. Handshakes That Don't Cross

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Top-Down Dynamic Programming (Memoization) | C++, Java, Python3 |
| Catalan Numbers | C++, Java, Python3 |

## Approach 1: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    const static int m = 1'000'000'007;

public:
    int numberOfWays(int numPeople) {
        vector<int> dp(numPeople / 2 + 1);
        dp[0] = 1;
        for (int i = 1; i <= numPeople / 2; i++) {
            for (int j = 0; j < i; j++) {
                (dp[i] += (long long)dp[j] * dp[i - j - 1] % m) %= m;
            }
        }
        return dp[numPeople / 2];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int m = 1000000007;

    public int numberOfWays(int numPeople) {
        int[] dp = new int[numPeople / 2 + 1];
        dp[0] = 1;
        for (int i = 1; i <= numPeople / 2; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += (long) dp[j] * dp[i - j - 1] % m;
                dp[i] %= m;
            }
        }
        return dp[numPeople / 2];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1000000007
        dp = [0] * (numPeople // 2 + 1)
        dp[0] = 1
        for i in range(1, numPeople // 2 + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - j - 1]
                dp[i] %= m
        return dp[numPeople // 2]
```

</details>

<br>

## Approach 2: Top-Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    const static int m = 1'000'000'007;

public:
    int numberOfWays(int numPeople) {
        vector<int> dp(numPeople / 2 + 1, -1);
        dp[0] = 1;
        
        function<int(int)> calculateDP = [&](int i) -> int {
            if (dp[i] != -1) {
                return dp[i];
            }
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                (dp[i] += (long long)calculateDP(j) * calculateDP(i - j - 1) % m) %= m;
            }
            return dp[i];
        };
        
        return calculateDP(numPeople / 2);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int m = 1000000007;
    int[] dp;

    public int numberOfWays(int numPeople) {
        dp = new int[numPeople / 2 + 1];
        Arrays.fill(dp, -1);
        dp[0] = 1;
        return calculateDP(numPeople / 2);
    }

    private int calculateDP(int i) {
        if (dp[i] != -1) {
            return dp[i];
        }
        dp[i] = 0;
        for (int j = 0; j < i; j++) {
            dp[i] += (long) calculateDP(j) * calculateDP(i - j - 1) % m;
            dp[i] %= m;
        }
        return dp[i];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1000000007
        dp = [-1] * (numPeople // 2 + 1)
        dp[0] = 1

        def calculate_dp(i):
            if dp[i] != -1:
                return dp[i]
            dp[i] = 0
            for j in range(i):
                dp[i] += calculate_dp(j) * calculate_dp(i - j - 1)
            dp[i] %= m
            return dp[i]

        return calculate_dp(numPeople // 2)
```

</details>

<br>

## Approach 3: Catalan Numbers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    const int m = 1'000'000'007;
    int mul(int a, int b) { return (long long)a * b % m; }

public:
    int numberOfWays(int numPeople) {
        int n = numPeople / 2;
        vector<int> inv(n + 2);
        inv[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            int k = m / i, r = m % i;
            inv[i] = m - mul(k, inv[r]);
        }
        int C = 1;
        for (int i = 0; i < n; i++) {
            C = mul(mul(2 * (2 * i + 1), inv[i + 2]), C);
        }
        return C;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private static int m = 1000000007;

    private int mul(int a, int b) {
        return (int) ((long) a * b % m);
    }

    public int numberOfWays(int numPeople) {
        int n = numPeople / 2;
        int[] inv = new int[numPeople / 2 + 2];
        inv[1] = 1;
        for (int i = 2; i < n + 2; i++) {
            int k = m / i, r = m % i;
            inv[i] = m - mul(k, inv[r]);
        }
        int C = 1;
        for (int i = 0; i < n; i++) {
            C = mul(mul(2 * (2 * i + 1), inv[i + 2]), C);
        }
        return C;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, numPeople: int) -> int:
        m = 1000000007
        n = numPeople // 2
        inv = [None] * (n+2)
        inv[1] = 1
        for i in range(2, n+2):
            k = m // i
            r = m % i
            inv[i] = m - k * inv[r] % m
        C = 1
        for i in range(n):
            C = 2 * (2 * i + 1) * inv[i + 2] * C % m
        return C
```

</details>
