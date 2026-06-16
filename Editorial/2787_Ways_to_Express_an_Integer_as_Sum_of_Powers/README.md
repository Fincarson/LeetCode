# 2787. Ways to Express an Integer as Sum of Powers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 2787 - Ways to Express an Integer as Sum of Powers](https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/)

## Problem

Given two positive integers n and x.

Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.

Since the result can be very large, return it modulo 109 + 7.

For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

### Example 1

```text
Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 32 + 12 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
```

### Example 2

```text
Input: n = 4, x = 1
Output: 2
Explanation: We can express n in the following ways:
- n = 41 = 4.
- n = 31 + 11 = 4.
```

## Constraints

- 1 <= n <= 300
- 1 <= x <= 5

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Perfect Squares](https://leetcode.com/problems/perfect-squares/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Target Sum](https://leetcode.com/problems/target-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2787. Ways to Express an Integer as Sum of Powers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfWays(int n, int x) {
    const int MOD = 1e9 + 7;
    long long dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        long long val = (long long)pow(i, x);
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= val) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD;
            }
        }
    }

    return dp[n][n];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfWays(int n, int x) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            long long val = pow(i, x);
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= val) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % mod;
                }
            }
        }
        return dp[n][n];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1_000_000_007;

    public int NumberOfWays(int n, int x) {
        long[,] dp = new long[n + 1, n + 1];
        dp[0, 0] = 1;
        for (int i = 1; i <= n; i++) {
            long val = (long)Math.Pow(i, x);
            for (int j = 0; j <= n; j++) {
                dp[i, j] = dp[i - 1, j];
                if (j >= val) {
                    dp[i, j] = (dp[i, j] + dp[i - 1, j - (int)val]) % MOD;
                }
            }
        }
        return (int)dp[n, n];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfWays(n int, x int) int {
	const mod = 1_000_000_007
	dp := make([][]int64, n+1)
	for i := range dp {
		dp[i] = make([]int64, n+1)
	}
	dp[0][0] = 1
	for i := 1; i <= n; i++ {
		val := int64(math.Pow(float64(i), float64(x)))
		for j := 0; j <= n; j++ {
			dp[i][j] = dp[i-1][j]
			if j >= int(val) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-int(val)]) % mod
			}
		}
	}
	return int(dp[n][n])
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    final int MOD = 1_000_000_007;

    public int numberOfWays(int n, int x) {
        long[][] dp = new long[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            long val = (long) Math.pow(i, x);
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= val) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - (int) val]) % MOD;
                }
            }
        }
        return (int) dp[n][n];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfWays = function (n, x) {
    const MOD = 1e9 + 7;
    const dp = Array.from({ length: n + 1 }, () => Array(n + 1).fill(0));
    dp[0][0] = 1;
    for (let i = 1; i <= n; i++) {
        const val = Math.pow(i, x);
        for (let j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= val) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD;
            }
        }
    }
    return dp[n][n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            val = i**x
            for j in range(n + 1):
                dp[i][j] = dp[i - 1][j]
                if j >= val:
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD
        return dp[n][n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfWays(n: number, x: number): number {
    const MOD = 1e9 + 7;
    const dp: number[][] = Array.from({ length: n + 1 }, () =>
        Array(n + 1).fill(0),
    );
    dp[0][0] = 1;
    for (let i = 1; i <= n; i++) {
        const val = Math.pow(i, x);
        for (let j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= val) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD;
            }
        }
    }
    return dp[n][n];
}
```

</details>
