# 70. Climbing Stairs

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/climbing-stairs/)  
`Math` `Dynamic Programming` `Memoization`

**Problem Link:** [LeetCode 70 - Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)

## Problem

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### Example 1

```text
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
```

### Example 2

```text
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```

## Constraints

- 1 <= n <= 45

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Rounds to Complete All Tasks](https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Number of Ways to Place Houses](https://leetcode.com/problems/count-number-of-ways-to-place-houses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Ways to Reach a Position After Exactly k Steps](https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Frog Jump II](https://leetcode.com/problems/frog-jump-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find Number of Ways to Reach the K-th Stair](https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [The Number of Ways to Make the Sum](https://leetcode.com/problems/the-number-of-ways-to-make-the-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 70. Climbing Stairs

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursion with Memoization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Fibonacci Number | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binets Method | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Fibonacci Formula | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int climb_Stairs(int i, int n) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}
int climbStairs(int n) { return climb_Stairs(0, n); }
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int climbStairs(int n) { return climb_Stairs(0, n); }
    int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int ClimbStairs(int n) {
        return Climb_Stairs(0, n);
    }

    public int Climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        return Climb_Stairs(i + 1, n) + Climb_Stairs(i + 2, n);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Go
func climbStairs(n int) int {
    return climb_Stairs(0, n)
}

func climb_Stairs(i int, n int) int {
    if i > n {
        return 0
    }
    if i == n {
        return 1
    }
    return climb_Stairs(i+1, n) + climb_Stairs(i+2, n)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        return climb_Stairs(0, n);
    }

    public int climb_Stairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var climbStairs = function (n) {
    return climb_Stairs(0, n);
};
var climb_Stairs = function (i, n) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def climbStairs(self, n: int) -> int:
        return self.climb_Stairs(0, n)

    def climb_Stairs(self, i: int, n: int) -> int:
        if i > n:
            return 0
        if i == n:
            return 1
        return self.climb_Stairs(i + 1, n) + self.climb_Stairs(i + 2, n)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function climbStairs(n: number): number {
    return climb_Stairs(0, n);
}
function climb_Stairs(i: number, n: number): number {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    return climb_Stairs(i + 1, n) + climb_Stairs(i + 2, n);
}
```

</details>

<br>

## Approach 2: Recursion with Memoization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int climb_Stairs(int i, int n, int memo[]) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0) {
        return memo[i];
    }
    memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
    return memo[i];
}
int climbStairs(int n) {
    int *memo = calloc(n + 1, sizeof(int));
    int result = climb_Stairs(0, n, memo);
    free(memo);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo(n + 1, 0);
        return climb_Stairs(0, n, memo);
    }
    int climb_Stairs(int i, int n, vector<int> &memo) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int ClimbStairs(int n) {
        int[] memo = new int[n + 1];
        return Climb_Stairs(0, n, memo);
    }

    public int Climb_Stairs(int i, int n, int[] memo) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if (memo[i] > 0) {
            return memo[i];
        }

        memo[i] = Climb_Stairs(i + 1, n, memo) + Climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func climbStairs(n int) int {
    memo := make([]int, n+1)
    return climb_Stairs(0, n, memo)
}

func climb_Stairs(i int, n int, memo []int) int {
    if i > n {
        return 0
    }
    if i == n {
        return 1
    }
    if memo[i] > 0 {
        return memo[i]
    }
    memo[i] = climb_Stairs(i+1, n, memo) + climb_Stairs(i+2, n, memo)
    return memo[i]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[n + 1];
        return climb_Stairs(0, n, memo);
    }

    public int climb_Stairs(int i, int n, int memo[]) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        if (memo[i] > 0) {
            return memo[i];
        }
        memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
        return memo[i];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var climbStairs = function (n) {
    let memo = new Array(n + 1).fill(0);
    return climb_Stairs(0, n, memo);
};
var climb_Stairs = function (i, n, memo) {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0) {
        return memo[i];
    }
    memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
    return memo[i];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n + 1)
        return self.climb_Stairs(0, n, memo)

    def climb_Stairs(self, i: int, n: int, memo: List[int]) -> int:
        if i > n:
            return 0
        if i == n:
            return 1
        if memo[i] > 0:
            return memo[i]
        memo[i] = self.climb_Stairs(i + 1, n, memo) + self.climb_Stairs(
            i + 2, n, memo
        )
        return memo[i]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function climbStairs(n: number): number {
    let memo: number[] = new Array(n + 1).fill(0);
    return climb_Stairs(0, n, memo);
}
function climb_Stairs(i: number, n: number, memo: number[]): number {
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0) {
        return memo[i];
    }
    memo[i] = climb_Stairs(i + 1, n, memo) + climb_Stairs(i + 2, n, memo);
    return memo[i];
}
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int dp[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int ClimbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func climbStairs(n int) int {
    if n == 1 {
        return 1
    }
    dp := make([]int, n+1)
    dp[1] = 1
    dp[2] = 2
    for i := 3; i <= n; i++ {
        dp[i] = dp[i-1] + dp[i-2]
    }
    return dp[n]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
//JavaScript
var climbStairs = function (n) {
    if (n == 1) {
        return 1;
    }
    let dp = new Array(n + 1).fill(0);
    dp[1] = 1;
    dp[2] = 2;
    for (let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [0 for _ in range(n + 1)]
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
//TypeScript
function climbStairs(n: number): number {
    if (n == 1) {
        return 1;
    }
    let dp: number[] = new Array(n + 1).fill(0);
    dp[1] = 1;
    dp[2] = 2;
    for (let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

</details>

<br>

## Approach 4: Fibonacci Number

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int climbStairs(int n) {
    if (n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int ClimbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }

        return second;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func climbStairs(n int) int {
    if n == 1 {
        return 1
    }
    first := 1
    second := 2
    for i := 3; i <= n; i++ {
        third := first + second
        first = second
        second = third
    }
    return second
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var climbStairs = function (n) {
    if (n == 1) {
        return 1;
    }
    let first = 1;
    let second = 2;
    for (let i = 3; i <= n; i++) {
        let third = first + second;
        first = second;
        second = third;
    }
    return second;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        first = 1
        second = 2
        for i in range(3, n + 1):
            third = first + second
            first = second
            second = third
        return second
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function climbStairs(n: number): number {
    if (n == 1) {
        return 1;
    }
    let first = 1;
    let second = 2;
    for (let i = 3; i <= n; i++) {
        let third = first + second;
        first = second;
        second = third;
    }
    return second;
}
```

</details>

<br>

## Approach 5: Binets Method

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
/* C */
int64_t mult(int64_t a, int64_t b) { return a * b; }
int64_t** multiply(int64_t** a, int64_t** b) {
    int64_t** c = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) c[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = mult(a[i][0], b[0][j]) + mult(a[i][1], b[1][j]);
    return c;
}
int64_t** pow_matrix(int64_t** a, int n) {
    int64_t** ret = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) ret[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    ret[0][0] = 1;
    ret[0][1] = 0;
    ret[1][0] = 0;
    ret[1][1] = 1;
    while (n > 0) {
        if ((n & 1) == 1) ret = multiply(ret, a);
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}
int climbStairs(int n) {
    int64_t** q = (int64_t**)malloc(2 * sizeof(int64_t*));
    for (int i = 0; i < 2; i++) q[i] = (int64_t*)malloc(2 * sizeof(int64_t));
    q[0][0] = 1;
    q[0][1] = 1;
    q[1][0] = 1;
    q[1][1] = 0;
    int64_t** res = pow_matrix(q, n);
    return (int)res[0][0];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<vector<long long>> A = {{1, 1}, {1, 0}};
        vector<vector<long long>> res = binaryPow(A, n - 1);
        return res[0][0] + res[0][1];
    }

private:
    vector<vector<long long>> binaryPow(vector<vector<long long>> &A, int n) {
        vector<vector<long long>> ret = {{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) ret = multiply(ret, A);
            A = multiply(A, A);
            n >>= 1;
        }
        return ret;
    }
    vector<vector<long long>> multiply(vector<vector<long long>> &A,
                                       vector<vector<long long>> &B) {
        vector<vector<long long>> C(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
/* C# */

public class Solution {
    public int ClimbStairs(int n) {
        int[][] q = new int [2][] { new int[2] { 1, 1 }, new int[2] { 1, 0 } };
        int[][] res = Pow(q, n);
        return res[0][0];
    }

    public int[][] Pow(int[][] a, int n) {
        int[][] ret =
            new int [2][] { new int[2] { 1, 0 }, new int[2] { 0, 1 } };
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = Multiply(ret, a);
            }

            n >>= 1;
            a = Multiply(a, a);
        }

        return ret;
    }

    public int[][] Multiply(int[][] a, int[][] b) {
        int[][] c = new int [2][] { new int[2] { 0, 0 }, new int[2] { 0, 0 } };
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }

        return c;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
/* Golang */
func climbStairs(n int) int {
    q := [][]int{{1, 1}, {1, 0}}
    res := pow(q, n)
    return res[0][0]
}

func pow(a [][]int, n int) [][]int {
    ret := [][]int{{1, 0}, {0, 1}}
    for n > 0 {
        if (n & 1) == 1 {
            ret = multiply(ret, a)
        }
        n >>= 1
        a = multiply(a, a)
    }
    return ret
}

func multiply(a [][]int, b [][]int) [][]int {
    c := make([][]int, 2)
    for i := range c {
        c[i] = make([]int, 2)
    }
    for i := 0; i < 2; i++ {
        for j := 0; j < 2; j++ {
            c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
        }
    }
    return c
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        int[][] q = { { 1, 1 }, { 1, 0 } };
        int[][] res = pow(q, n);
        return res[0][0];
    }

    public int[][] pow(int[][] a, int n) {
        int[][] ret = { { 1, 0 }, { 0, 1 } };
        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    public int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var climbStairs = function (n) {
    let q = [
        [1, 1],
        [1, 0],
    ];
    let res = pow(q, n);
    return res[0][0];
};
var pow = function (a, n) {
    let ret = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if ((n & 1) == 1) {
            ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
};
var multiply = function (a, b) {
    let c = [
        [0, 0],
        [0, 0],
    ];
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def climbStairs(self, n: int) -> int:
        q = [[1, 1], [1, 0]]
        res = self.pow(q, n)
        return res[0][0]

    def pow(self, a: [[int]], n: int) -> [[int]]:
        ret = [[1, 0], [0, 1]]
        while n > 0:
            if (n & 1) == 1:
                ret = self.multiply(ret, a)
            n >>= 1
            a = self.multiply(a, a)
        return ret

    def multiply(self, a: [[int]], b: [[int]]) -> [[int]]:
        c = [[0, 0], [0, 0]]
        for i in range(2):
            for j in range(2):
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]
        return c
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
/* TypeScript */
function climbStairs(n: number): number {
    let q: number[][] = [
        [1, 1],
        [1, 0],
    ];
    let res: number[][] = pow(q, n);
    return res[0][0];
}
function pow(a: number[][], n: number): number[][] {
    let ret: number[][] = [
        [1, 0],
        [0, 1],
    ];
    while (n > 0) {
        if ((n & 1) == 1) {
            ret = multiply(ret, a);
        }
        n >>= 1;
        a = multiply(a, a);
    }
    return ret;
}
function multiply(a: number[][], b: number[][]): number[][] {
    let c: number[][] = [
        [0, 0],
        [0, 0],
    ];
    for (let i = 0; i < 2; i++) {
        for (let j = 0; j < 2; j++) {
            c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return c;
}
```

</details>

<br>

## Approach 6: Fibonacci Formula

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int climbStairs(int n) {
    double sqrt5 = sqrt(5);
    double phi = (1 + sqrt5) / 2;
    double psi = (1 - sqrt5) / 2;
    return (int)((pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        return (int)((pow(phi, n + 1) - pow(psi, n + 1)) / sqrt5);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int ClimbStairs(int n) {
        double sqrt5 = Math.Sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        return (int)((Math.Pow(phi, n + 1) - Math.Pow(psi, n + 1)) / sqrt5);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func climbStairs(n int) int {
    if n <= 1 {
        return 1
    }
    if n == 2 {
        return 2
    }
    oneStepBefore := 2
    twoStepsBefore := 1
    allWays := 0
    for i := 2; i < n; i++ {
        allWays = oneStepBefore + twoStepsBefore
        twoStepsBefore = oneStepBefore
        oneStepBefore = allWays
    }
    return allWays
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int climbStairs(int n) {
        double sqrt5 = Math.sqrt(5);
        double phi = (1 + sqrt5) / 2;
        double psi = (1 - sqrt5) / 2;
        return (int) ((Math.pow(phi, n + 1) - Math.pow(psi, n + 1)) / sqrt5);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var climbStairs = function (n) {
    var sqrt5 = Math.sqrt(5);
    var phi = (1 + sqrt5) / 2;
    var psi = (1 - sqrt5) / 2;
    return Math.floor((Math.pow(phi, n + 1) - Math.pow(psi, n + 1)) / sqrt5);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python 3
class Solution:
    def climbStairs(self, n: int) -> int:
        sqrt5 = 5**0.5
        phi = (1 + sqrt5) / 2
        psi = (1 - sqrt5) / 2
        return int((phi ** (n + 1) - psi ** (n + 1)) / sqrt5)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function climbStairs(n: number): number {
    let sqrt5 = Math.sqrt(5);
    let phi = (1 + sqrt5) / 2;
    let psi = (1 - sqrt5) / 2;
    return Math.floor((Math.pow(phi, n + 1) - Math.pow(psi, n + 1)) / sqrt5);
}
```

</details>
