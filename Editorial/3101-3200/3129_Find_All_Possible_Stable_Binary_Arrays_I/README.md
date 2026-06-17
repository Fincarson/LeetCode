# 3129. Find All Possible Stable Binary Arrays I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)  
`Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 3129 - Find All Possible Stable Binary Arrays I](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/)

## Problem

You are given 3 positive integers num_zeros, num_ones, and limit.

A binary array arr is called stable if:

- The number of occurrences of 0 in arr is exactly num_zeros.
- The number of occurrences of 1 in arr is exactly num_ones.
- Each subarray of arr with a size greater than limit must contain at least one occurrence of both 0 and 1.

Return an integer denoting the total number of stable binary arrays.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= zero, one, limit <= 200

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3129. Find All Possible Stable Binary Arrays I

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
#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    long long dp[zero + 1][one + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= (zero < limit ? zero : limit); ++i) {
        dp[i][0][0] = 1;
    }
    for (int j = 0; j <= (one < limit ? one : limit); ++j) {
        dp[0][j][1] = 1;
    }
    for (int i = 1; i <= zero; ++i) {
        for (int j = 1; j <= one; ++j) {
            if (i > limit) {
                dp[i][j][0] =
                    dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            }
            dp[i][j][0] = (dp[i][j][0] % MOD + MOD) % MOD;
            if (j > limit) {
                dp[i][j][1] =
                    dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
            } else {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
            }
            dp[i][j][1] = (dp[i][j][1] % MOD + MOD) % MOD;
        }
    }
    int result = (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(
            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));
        long long mod = 1e9 + 7;
        for (int i = 0; i <= min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                if (i > limit) {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] -
                                  dp[i - limit - 1][j][1];
                } else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
                if (j > limit) {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] -
                                  dp[i][j - limit - 1][0];
                } else {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumberOfStableArrays(int zero, int one, int limit) {
        const long MOD = 1000000007;
        long[][][] dp = new long [zero + 1][][];
        for (int i = 0; i <= zero; i++) {
            dp[i] = new long [one + 1][];
            for (int j = 0; j <= one; j++) {
                dp[i][j] = new long[2];
            }
        }
        for (int i = 0; i <= Math.Min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= Math.Min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                if (i > limit) {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] -
                                  dp[i - limit - 1][j][1];
                } else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = (dp[i][j][0] % MOD + MOD) % MOD;
                if (j > limit) {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] -
                                  dp[i][j - limit - 1][0];
                } else {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }
                dp[i][j][1] = (dp[i][j][1] % MOD + MOD) % MOD;
            }
        }
        return (int)((dp[zero][one][0] + dp[zero][one][1]) % MOD);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfStableArrays(zero int, one int, limit int) int {
    dp := make([][][2]int, zero + 1)
    mod := int(1e9 + 7)
    for i := 0; i <= zero; i++ {
        dp[i] = make([][2]int, one + 1)
    }
    for i := 0; i <= min(zero, limit); i++ {
        dp[i][0][0] = 1
    }
    for j := 0; j <= min(one, limit); j++ {
        dp[0][j][1] = 1
    }
    for i := 1; i <= zero; i++ {
        for j := 1; j <= one; j++ {
            if i > limit {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1]
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1]
            }
            dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod
            if j > limit {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0]
            } else {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0]
            }
            dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod
        }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % mod
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfStableArrays(int zero, int one, int limit) {
        final long MOD = 1000000007;
        long[][][] dp = new long[zero + 1][one + 1][2];
        for (int i = 0; i <= Math.min(zero, limit); i++) {
            dp[i][0][0] = 1;
        }
        for (int j = 0; j <= Math.min(one, limit); j++) {
            dp[0][j][1] = 1;
        }
        for (int i = 1; i <= zero; i++) {
            for (int j = 1; j <= one; j++) {
                if (i > limit) {
                    dp[i][j][0] =
                        dp[i - 1][j][0] +
                        dp[i - 1][j][1] -
                        dp[i - limit - 1][j][1];
                } else {
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
                }
                dp[i][j][0] = ((dp[i][j][0] % MOD) + MOD) % MOD;
                if (j > limit) {
                    dp[i][j][1] =
                        dp[i][j - 1][1] +
                        dp[i][j - 1][0] -
                        dp[i][j - limit - 1][0];
                } else {
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
                }
                dp[i][j][1] = ((dp[i][j][1] % MOD) + MOD) % MOD;
            }
        }
        return (int) ((dp[zero][one][0] + dp[zero][one][1]) % MOD);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1000000007;

var numberOfStableArrays = function (zero, one, limit) {
    const dp = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 0; i <= Math.min(zero, limit); i++) {
        dp[i][0][0] = 1;
    }
    for (let j = 0; j <= Math.min(one, limit); j++) {
        dp[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            if (i > limit) {
                dp[i][j][0] =
                    dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            }
            dp[i][j][0] = ((dp[i][j][0] % MOD) + MOD) % MOD;
            if (j > limit) {
                dp[i][j][1] =
                    dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
            } else {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
            }
            dp[i][j][1] = ((dp[i][j][1] % MOD) + MOD) % MOD;
        }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        dp = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        mod = int(1e9 + 7)
        for i in range(min(zero, limit) + 1):
            dp[i][0][0] = 1
        for j in range(min(one, limit) + 1):
            dp[0][j][1] = 1
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                if i > limit:
                    dp[i][j][0] = (
                        dp[i - 1][j][0]
                        + dp[i - 1][j][1]
                        - dp[i - limit - 1][j][1]
                    )
                else:
                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1]
                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod
                if j > limit:
                    dp[i][j][1] = (
                        dp[i][j - 1][1]
                        + dp[i][j - 1][0]
                        - dp[i][j - limit - 1][0]
                    )
                else:
                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0]
                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod
        return (dp[zero][one][0] + dp[zero][one][1]) % mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1000000007;

function numberOfStableArrays(
    zero: number,
    one: number,
    limit: number,
): number {
    const dp: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 0; i <= Math.min(zero, limit); i++) {
        dp[i][0][0] = 1;
    }
    for (let j = 0; j <= Math.min(one, limit); j++) {
        dp[0][j][1] = 1;
    }

    for (let i = 1; i <= zero; i++) {
        for (let j = 1; j <= one; j++) {
            if (i > limit) {
                dp[i][j][0] =
                    dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            }
            dp[i][j][0] = ((dp[i][j][0] % MOD) + MOD) % MOD;
            if (j > limit) {
                dp[i][j][1] =
                    dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
            } else {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
            }
            dp[i][j][1] = ((dp[i][j][1] % MOD) + MOD) % MOD;
        }
    }
    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
```

</details>
