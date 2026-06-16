# 935. Knight Dialer

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/knight-dialer/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 935 - Knight Dialer](https://leetcode.com/problems/knight-dialer/)

## Problem

The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagram:

A chess knight can move as indicated in the chess diagram below:

We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).

Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.

### Example 1

```text
Input: n = 1
Output: 10
Explanation: We need to dial a number of length 1, so placing the knight over any numeric cell of the 10 cells is sufficient.
```

### Example 2

```text
Input: n = 2
Output: 20
Explanation: All the valid number we can dial are [04, 06, 16, 18, 27, 29, 34, 38, 40, 43, 49, 60, 61, 67, 72, 76, 81, 83, 92, 94]
```

### Example 3

```text
Input: n = 3131
Output: 136006598
Explanation: Please take care of the mod.
```

## Constraints

- 1 <= n <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 935. Knight Dialer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Space-Optimized Dynamic Programming | C++, Java, Python3 |
| Efficient Iteration On States | C++, Java, Python3 |
| Linear Algebra | C++, Python3 |

## Approach 1: Top-Down Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int MOD = 1e9 + 7;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    int knightDialer(int n) {
        this->n = n;
        memo = vector(n + 1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
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
    int[][] memo;
    int n;
    int MOD = (int) 1e9 + 7;
    int[][] jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    
    public int dp(int remain, int square) {
        if (remain == 0) {
            return 1;
        }
        
        if (memo[remain][square] != 0) {
            return memo[remain][square];
        }
        
        int ans = 0;
        for (int nextSquare : jumps[square]) {
            ans = (ans + dp(remain - 1, nextSquare)) % MOD;
        }
        
        memo[remain][square] = ans;
        return ans;
    }
    
    public int knightDialer(int n) {
        this.n = n;
        memo = new int[n + 1][10];
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp(n - 1, square)) % MOD;
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
    def knightDialer(self, n: int) -> int:
        @cache
        def dp(remain, square):
            if remain == 0:
                return 1
            
            ans = 0
            for next_square in jumps[square]:
                ans = (ans + dp(remain - 1, next_square)) % MOD
            
            return ans
        
        jumps = [
            [4, 6],
            [6, 8],
            [7, 9],
            [4, 8],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4]
        ]

        ans = 0
        MOD = 10 ** 9 + 7
        for square in range(10):
            ans = (ans + dp(n - 1, square)) % MOD
        
        return ans
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
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<vector<int>> dp(n, vector(10, 0));
        for (int square = 0; square < 10; square++) {
            dp[0][square] = 1;
        }

        for (int remain = 1; remain < n; remain++) {
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + dp[remain - 1][nextSquare]) % MOD;
                }

                dp[remain][square] = ans;
            }
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp[n - 1][square]) % MOD;
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
    public int knightDialer(int n) {
        int[][] jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };
        
        int MOD = (int) 1e9 + 7;
        int[][] dp = new int[n][10];
        for (int square = 0; square < 10; square++) {
            dp[0][square] = 1;
        }
        
        for (int remain = 1; remain < n; remain++) {
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + dp[remain - 1][nextSquare]) % MOD;
                }

                dp[remain][square] = ans;
            }
        }
        
        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + dp[n - 1][square]) % MOD;
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
    def knightDialer(self, n: int) -> int:
        jumps = [
            [4, 6],
            [6, 8],
            [7, 9],
            [4, 8],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4]
        ]
        
        MOD = 10 ** 9 + 7
        dp = [[0] * 10 for _ in range(n)]
        for square in range(10):
            dp[0][square] = 1

        for remain in range(1, n):
            for square in range(10):
                ans = 0
                for next_square in jumps[square]:
                    ans = (ans + dp[remain - 1][next_square]) % MOD
                
                dp[remain][square] = ans

        ans = 0
        for square in range(10):
            ans = (ans + dp[n - 1][square]) % MOD
        
        return ans
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
    int knightDialer(int n) {
        vector<vector<int>> jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = 1e9 + 7;
        vector<int> dp(10, 0);
        vector<int> prevDp(10, 1);

        for (int remain = 1; remain < n; remain++) {
            dp = vector(10, 0);
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + prevDp[nextSquare]) % MOD;
                }

                dp[square] = ans;
            }
            
            prevDp = dp;
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + prevDp[square]) % MOD;
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
    public int knightDialer(int n) {
        int[][] jumps = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {3, 9, 0},
            {},
            {1, 7, 0},
            {2, 6},
            {1, 3},
            {2, 4}
        };

        int MOD = (int) 1e9 + 7;
        int[] dp = new int[10];
        int[] prevDp = new int[10];
        Arrays.fill(prevDp, 1);

        for (int remain = 1; remain < n; remain++) {
            dp = new int[10];
            for (int square = 0; square < 10; square++) {
                int ans = 0;
                for (int nextSquare : jumps[square]) {
                    ans = (ans + prevDp[nextSquare]) % MOD;
                }

                dp[square] = ans;
            }

            prevDp = dp;
        }

        int ans = 0;
        for (int square = 0; square < 10; square++) {
            ans = (ans + prevDp[square]) % MOD;
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
    def knightDialer(self, n: int) -> int:
        jumps = [
            [4, 6],
            [6, 8],
            [7, 9],
            [4, 8],
            [3, 9, 0],
            [],
            [1, 7, 0],
            [2, 6],
            [1, 3],
            [2, 4]
        ]
        
        MOD = 10 ** 9 + 7
        dp = [0] * 10
        prev_dp = [1] * 10
        
        for remain in range(1, n):
            dp = [0] * 10
            for square in range(10):
                ans = 0
                for next_square in jumps[square]:
                    ans = (ans + prev_dp[next_square]) % MOD
                
                dp[square] = ans
                
            prev_dp = dp

        ans = 0
        for square in range(10):
            ans = (ans + prev_dp[square]) % MOD
        
        return ans
```

</details>

<br>

## Approach 4: Efficient Iteration On States

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        
        int A = 4;
        int B = 2;
        int C = 2;
        int D = 1;
        int MOD = 1e9 + 7;
        
        for (int i = 0; i < n - 1; i++) {
            int tempA = A;
            int tempB = B;
            int tempC = C;
            int tempD = D;
            
            A = ((2 * tempB) % MOD + (2 * tempC) % MOD) % MOD;
            B = tempA;
            C = (tempA + (2 * tempD) % MOD) % MOD;
            D = tempC;
        }
        
        int ans = (A + B) % MOD;
        ans = (ans + C) % MOD;
        return (ans + D) % MOD;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        
        int A = 4;
        int B = 2;
        int C = 2;
        int D = 1;
        int MOD = (int) 1e9 + 7;
        
        for (int i = 0; i < n - 1; i++) {
            int tempA = A;
            int tempB = B;
            int tempC = C;
            int tempD = D;
            
            A = ((2 * tempB) % MOD + (2 * tempC) % MOD) % MOD;
            B = tempA;
            C = (tempA + (2 * tempD) % MOD) % MOD;
            D = tempC;
        }
        
        int ans = (A + B) % MOD;
        ans = (ans + C) % MOD;
        return (ans + D) % MOD;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        
        A = 4
        B = 2
        C = 2
        D = 1
        MOD = 10 ** 9 + 7
        
        for _ in range(n - 1):
            A, B, C, D = (2 * (B + C)) % MOD, A, (A + 2 * D) % MOD, C 
        
        return (A + B + C + D) % MOD
```

</details>

<br>

## Approach 5: Linear Algebra

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int MOD = 1e9 + 7;
    
    int knightDialer(int n) {
        if (n == 1) {
            return 10;
        }
        
        vector<vector<long>> A = {
            {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
        };
        
        vector<vector<long>> v = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        
        n--;
        while (n > 0) {
            if ((n & 1) != 0) {
                v = multiply(v, A);
            }
            
            A = multiply(A, A);
            n >>= 1;
        }
        
        int ans = 0;
        for (long num : v[0]) {
            ans = (ans + num) % MOD;
        }
        
        return ans;
    }
    
    vector<vector<long>> multiply(vector<vector<long>>& A, vector<vector<long>>& B) {
        vector<vector<long>> result(A.size(), vector<long>(B[0].size(), 0));
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B[0].size(); j++) {
                for (int k = 0; k < B.size(); k++) {
                    result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        
        return result;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def knightDialer(self, n: int) -> int:
        if n == 1:
            return 10
        
        def multiply(A, B):
            result = [[0] * len(B[0]) for _ in range(len(A))]
            
            for i in range(len(A)):
                for j in range(len(B[0])):
                    for k in range(len(B)):
                        result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD
                        
            return result

        A = [
            [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
            [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
            [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
            [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
            [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
            [0, 0, 1, 0, 1, 0, 0, 0, 0, 0]
        ]
        
        v = [[1] * 10]
        MOD = 10 ** 9 + 7

        n -= 1
        while n:
            if n & 1:
                v = multiply(v, A)
            
            A = multiply(A, A)
            n >>= 1

        return sum(v[0]) % MOD
```

</details>
