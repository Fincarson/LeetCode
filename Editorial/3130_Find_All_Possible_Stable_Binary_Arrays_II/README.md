# 3130. Find All Possible Stable Binary Arrays II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)  
`Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 3130 - Find All Possible Stable Binary Arrays II](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/)

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

- 1 <= zero, one, limit <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Contiguous Array](https://leetcode.com/problems/contiguous-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3130. Find All Possible Stable Binary Arrays II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Dynamic Programming | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Memoization Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int*** createMemo(int zero, int one) {
    int*** memo = malloc((zero + 1) * sizeof(int**));
    for (int i = 0; i <= zero; ++i) {
        memo[i] = malloc((one + 1) * sizeof(int*));
        for (int j = 0; j <= one; ++j) {
            memo[i][j] = malloc(2 * sizeof(int));
            memo[i][j][0] = -1;
            memo[i][j][1] = -1;
        }
    }
    return memo;
}

void freeMemo(int zero, int one, int*** memo) {
    for (int i = 0; i <= zero; ++i) {
        for (int j = 0; j <= one; ++j) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
    free(memo);
}

int dp(int zero, int one, int lastBit, int limit, int*** memo) {
    if (zero == 0) {
        return (lastBit == 0 || one > limit) ? 0 : 1;
    } else if (one == 0) {
        return (lastBit == 1 || zero > limit) ? 0 : 1;
    }
    if (memo[zero][one][lastBit] == -1) {
        int res = 0;
        if (lastBit == 0) {
            res = (dp(zero - 1, one, 0, limit, memo) +
                   dp(zero - 1, one, 1, limit, memo)) %
                  MOD;
            if (zero > limit) {
                res = (res - dp(zero - limit - 1, one, 1, limit, memo) + MOD) %
                      MOD;
            }
        } else {
            res = (dp(zero, one - 1, 0, limit, memo) +
                   dp(zero, one - 1, 1, limit, memo)) %
                  MOD;
            if (one > limit) {
                res = (res - dp(zero, one - limit - 1, 0, limit, memo) + MOD) %
                      MOD;
            }
        }
        memo[zero][one][lastBit] = res % MOD;
    }
    return memo[zero][one][lastBit];
}

int numberOfStableArrays(int zero, int one, int limit) {
    int*** memo = createMemo(zero, one);
    int result =
        (dp(zero, one, 0, limit, memo) + dp(zero, one, 1, limit, memo)) % MOD;
    freeMemo(zero, one, memo);
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
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> memo(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));

        function<int(int, int, int)> dp = [&](int zero, int one,
                                              int lastBit) -> int {
            if (zero == 0) {
                return (lastBit == 0 || one > limit) ? 0 : 1;
            } else if (one == 0) {
                return (lastBit == 1 || zero > limit) ? 0 : 1;
            }

            if (memo[zero][one][lastBit] == -1) {
                int res = 0;
                if (lastBit == 0) {
                    res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % mod;
                    if (zero > limit) {
                        res = (res - dp(zero - limit - 1, one, 1) + mod) % mod;
                    }
                } else {
                    res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % mod;
                    if (one > limit) {
                        res = (res - dp(zero, one - limit - 1, 0) + mod) % mod;
                    }
                }
                memo[zero][one][lastBit] = res % mod;
            }
            return memo[zero][one][lastBit];
        };

        return (dp(zero, one, 0) + dp(zero, one, 1)) % mod;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    const int MOD = 1000000007;
    int[][][] memo;
    int limit;

    public int NumberOfStableArrays(int zero, int one, int limit) {
        this.memo = new int [zero + 1][][];
        for (int i = 0; i <= zero; i++) {
            memo[i] = new int [one + 1][];
            for (int j = 0; j <= one; j++) {
                memo[i][j] = new int[2];
                Array.Fill(memo[i][j], -1);
            }
        }
        this.limit = limit;
        return (DP(zero, one, 0) + DP(zero, one, 1)) % MOD;
    }

    public int DP(int zero, int one, int lastBit) {
        if (zero == 0) {
            return (lastBit == 0 || one > limit) ? 0 : 1;
        } else if (one == 0) {
            return (lastBit == 1 || zero > limit) ? 0 : 1;
        }

        if (memo[zero][one][lastBit] == -1) {
            int res = 0;
            if (lastBit == 0) {
                res = (DP(zero - 1, one, 0) + DP(zero - 1, one, 1)) % MOD;
                if (zero > limit) {
                    res = (res - DP(zero - limit - 1, one, 1) + MOD) % MOD;
                }
            } else {
                res = (DP(zero, one - 1, 0) + DP(zero, one - 1, 1)) % MOD;
                if (one > limit) {
                    res = (res - DP(zero, one - limit - 1, 0) + MOD) % MOD;
                }
            }
            memo[zero][one][lastBit] = res % MOD;
        }
        return memo[zero][one][lastBit];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1000000007

func numberOfStableArrays(zero int, one int, limit int) int {
	memo := make([][][]int, zero+1)
	for i := range memo {
		memo[i] = make([][]int, one+1)
		for j := range memo[i] {
			memo[i][j] = []int{-1, -1}
		}
	}

	var dp func(int, int, int) int
	dp = func(zero, one, lastBit int) int {
		if zero == 0 {
			if lastBit == 0 || one > limit {
				return 0
			} else {
				return 1
			}
		} else if one == 0 {
			if lastBit == 1 || zero > limit {
				return 0
			} else {
				return 1
			}
		}

		if memo[zero][one][lastBit] == -1 {
			res := 0
			if lastBit == 0 {
				res = (dp(zero-1, one, 0) + dp(zero-1, one, 1)) % MOD
				if zero > limit {
					res = (res - dp(zero-limit-1, one, 1) + MOD) % MOD
				}
			} else {
				res = (dp(zero, one-1, 0) + dp(zero, one-1, 1)) % MOD
				if one > limit {
					res = (res - dp(zero, one-limit-1, 0) + MOD) % MOD
				}
			}
			memo[zero][one][lastBit] = res % MOD
		}
		return memo[zero][one][lastBit]
	}

	return (dp(zero, one, 0) + dp(zero, one, 1)) % MOD
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static final int MOD = 1000000007;
    int[][][] memo;
    int limit;

    public int numberOfStableArrays(int zero, int one, int limit) {
        this.memo = new int[zero + 1][one + 1][2];
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }
        this.limit = limit;
        return (dp(zero, one, 0) + dp(zero, one, 1)) % MOD;
    }

    public int dp(int zero, int one, int lastBit) {
        if (zero == 0) {
            return (lastBit == 0 || one > limit) ? 0 : 1;
        } else if (one == 0) {
            return (lastBit == 1 || zero > limit) ? 0 : 1;
        }

        if (memo[zero][one][lastBit] == -1) {
            int res = 0;
            if (lastBit == 0) {
                res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % MOD;
                if (zero > limit) {
                    res = (res - dp(zero - limit - 1, one, 1) + MOD) % MOD;
                }
            } else {
                res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % MOD;
                if (one > limit) {
                    res = (res - dp(zero, one - limit - 1, 0) + MOD) % MOD;
                }
            }
            memo[zero][one][lastBit] = res % MOD;
        }
        return memo[zero][one][lastBit];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1000000007;

var numberOfStableArrays = function (zero, one, limit) {
    const memo = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [-1, -1]),
    );

    function dp(zero, one, lastBit) {
        if (zero === 0) {
            return lastBit === 0 || one > limit ? 0 : 1;
        } else if (one === 0) {
            return lastBit === 1 || zero > limit ? 0 : 1;
        }

        if (memo[zero][one][lastBit] === -1) {
            let res = 0;
            if (lastBit === 0) {
                res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % MOD;
                if (zero > limit) {
                    res = (res - dp(zero - limit - 1, one, 1) + MOD) % MOD;
                }
            } else {
                res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % MOD;
                if (one > limit) {
                    res = (res - dp(zero, one - limit - 1, 0) + MOD) % MOD;
                }
            }
            memo[zero][one][lastBit] = res % MOD;
        }
        return memo[zero][one][lastBit];
    }

    return (dp(zero, one, 0) + dp(zero, one, 1)) % MOD;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10**9 + 7

        @cache
        def dp(zero, one, lastBit):
            if zero == 0:
                if lastBit == 0 or one > limit:
                    return 0
                else:
                    return 1
            elif one == 0:
                if lastBit == 1 or zero > limit:
                    return 0
                else:
                    return 1
            if lastBit == 0:
                res = dp(zero - 1, one, 0) + dp(zero - 1, one, 1)
                if zero > limit:
                    res -= dp(zero - limit - 1, one, 1)
            else:
                res = dp(zero, one - 1, 0) + dp(zero, one - 1, 1)
                if one > limit:
                    res -= dp(zero, one - limit - 1, 0)
            return res % mod

        res = (dp(zero, one, 0) + dp(zero, one, 1)) % mod
        dp.cache_clear()
        return res
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
    const memo: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [-1, -1]),
    );

    function dp(zero: number, one: number, lastBit: number): number {
        if (zero === 0) {
            return lastBit === 0 || one > limit ? 0 : 1;
        } else if (one === 0) {
            return lastBit === 1 || zero > limit ? 0 : 1;
        }

        if (memo[zero][one][lastBit] === -1) {
            let res = 0;
            if (lastBit === 0) {
                res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % MOD;
                if (zero > limit) {
                    res = (res - dp(zero - limit - 1, one, 1) + MOD) % MOD;
                }
            } else {
                res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % MOD;
                if (one > limit) {
                    res = (res - dp(zero, one - limit - 1, 0) + MOD) % MOD;
                }
            }
            memo[zero][one][lastBit] = res % MOD;
        }
        return memo[zero][one][lastBit];
    }

    return (dp(zero, one, 0) + dp(zero, one, 1)) % MOD;
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int numberOfStableArrays(int zero, int one, int limit) {
    int dp[zero + 1][one + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= zero; i++) {
        for (int j = 0; j <= one; j++) {
            for (int lastBit = 0; lastBit <= 1; lastBit++) {
                if (i == 0) {
                    if (lastBit == 0 || j > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (j == 0) {
                    if (lastBit == 1 || i > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (lastBit == 0) {
                    dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                    if (i > limit) {
                        dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                    }
                } else {
                    dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                    if (j > limit) {
                        dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                    }
                }
                dp[i][j][lastBit] %= MOD;
                if (dp[i][j][lastBit] < 0) {
                    dp[i][j][lastBit] += MOD;
                }
            }
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    constexpr static int MOD = 1000000007;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(
            zero + 1, vector<vector<int>>(one + 1, vector<int>(2)));
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                for (int lastBit = 0; lastBit <= 1; lastBit++) {
                    if (i == 0) {
                        if (lastBit == 0 || j > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (j == 0) {
                        if (lastBit == 1 || i > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (lastBit == 0) {
                        dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                        if (i > limit) {
                            dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                        }
                    } else {
                        dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                        if (j > limit) {
                            dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                        }
                    }
                    dp[i][j][lastBit] %= MOD;
                    if (dp[i][j][lastBit] < 0) {
                        dp[i][j][lastBit] += MOD;
                    }
                }
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1000000007;
        int[][][] dp = new int [zero + 1][][];
        for (int i = 0; i <= zero; i++) {
            dp[i] = new int [one + 1][];
            for (int j = 0; j <= one; j++) {
                dp[i][j] = new int[2];
                for (int lastBit = 0; lastBit <= 1; lastBit++) {
                    if (i == 0) {
                        if (lastBit == 0 || j > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (j == 0) {
                        if (lastBit == 1 || i > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (lastBit == 0) {
                        dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                        if (i > limit) {
                            dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                        }
                    } else {
                        dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                        if (j > limit) {
                            dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                        }
                    }
                    dp[i][j][lastBit] %= MOD;
                    if (dp[i][j][lastBit] < 0) {
                        dp[i][j][lastBit] += MOD;
                    }
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1000000007

func numberOfStableArrays(zero int, one int, limit int) int {
	dp := make([][][]int, zero+1)
	for i := range dp {
		dp[i] = make([][]int, one+1)
		for j := range dp[i] {
			dp[i][j] = make([]int, 2)
		}
	}

	for i := 0; i <= zero; i++ {
		for j := 0; j <= one; j++ {
			for lastBit := 0; lastBit <= 1; lastBit++ {
				if i == 0 {
					if lastBit == 0 || j > limit {
						dp[i][j][lastBit] = 0
					} else {
						dp[i][j][lastBit] = 1
					}
				} else if j == 0 {
					if lastBit == 1 || i > limit {
						dp[i][j][lastBit] = 0
					} else {
						dp[i][j][lastBit] = 1
					}
				} else if lastBit == 0 {
					dp[i][j][lastBit] = dp[i-1][j][0] + dp[i-1][j][1]
					if i > limit {
						dp[i][j][lastBit] -= dp[i-limit-1][j][1]
					}
				} else {
					dp[i][j][lastBit] = dp[i][j-1][0] + dp[i][j-1][1]
					if j > limit {
						dp[i][j][lastBit] -= dp[i][j-limit-1][0]
					}
				}
				dp[i][j][lastBit] %= MOD
				if dp[i][j][lastBit] < 0 {
					dp[i][j][lastBit] += MOD
				}
			}
		}
	}

	return (dp[zero][one][0] + dp[zero][one][1]) % MOD
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfStableArrays(int zero, int one, int limit) {
        final int MOD = 1000000007;
        int[][][] dp = new int[zero + 1][one + 1][2];
        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {
                for (int lastBit = 0; lastBit <= 1; lastBit++) {
                    if (i == 0) {
                        if (lastBit == 0 || j > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (j == 0) {
                        if (lastBit == 1 || i > limit) {
                            dp[i][j][lastBit] = 0;
                        } else {
                            dp[i][j][lastBit] = 1;
                        }
                    } else if (lastBit == 0) {
                        dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                        if (i > limit) {
                            dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                        }
                    } else {
                        dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                        if (j > limit) {
                            dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                        }
                    }
                    dp[i][j][lastBit] %= MOD;
                    if (dp[i][j][lastBit] < 0) {
                        dp[i][j][lastBit] += MOD;
                    }
                }
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1000000007;

var numberOfStableArrays = function (zero, one, limit) {
    let dp = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {
            for (let lastBit = 0; lastBit <= 1; lastBit++) {
                if (i === 0) {
                    if (lastBit === 0 || j > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (j === 0) {
                    if (lastBit === 1 || i > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (lastBit === 0) {
                    dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                    if (i > limit) {
                        dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                    }
                } else {
                    dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                    if (j > limit) {
                        dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                    }
                }
                dp[i][j][lastBit] %= MOD;
                if (dp[i][j][lastBit] < 0) {
                    dp[i][j][lastBit] += MOD;
                }
            }
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
        mod = 10**9 + 7

        dp = [[[0, 0] for _ in range(one + 1)] for _ in range(zero + 1)]
        for i in range(zero + 1):
            for j in range(one + 1):
                for lastBit in range(2):
                    if i == 0:
                        if lastBit == 0 or j > limit:
                            dp[i][j][lastBit] = 0
                        else:
                            dp[i][j][lastBit] = 1
                    elif j == 0:
                        if lastBit == 1 or i > limit:
                            dp[i][j][lastBit] = 0
                        else:
                            dp[i][j][lastBit] = 1
                    elif lastBit == 0:
                        dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1]
                        if i > limit:
                            dp[i][j][lastBit] -= dp[i - limit - 1][j][1]
                    else:
                        dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1]
                        if j > limit:
                            dp[i][j][lastBit] -= dp[i][j - limit - 1][0]
                    dp[i][j][lastBit] %= mod
        return (dp[-1][-1][0] + dp[-1][-1][1]) % mod
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
    let dp: number[][][] = Array.from({ length: zero + 1 }, () =>
        Array.from({ length: one + 1 }, () => [0, 0]),
    );

    for (let i = 0; i <= zero; i++) {
        for (let j = 0; j <= one; j++) {
            for (let lastBit = 0; lastBit <= 1; lastBit++) {
                if (i === 0) {
                    if (lastBit === 0 || j > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (j === 0) {
                    if (lastBit === 1 || i > limit) {
                        dp[i][j][lastBit] = 0;
                    } else {
                        dp[i][j][lastBit] = 1;
                    }
                } else if (lastBit === 0) {
                    dp[i][j][lastBit] = dp[i - 1][j][0] + dp[i - 1][j][1];
                    if (i > limit) {
                        dp[i][j][lastBit] -= dp[i - limit - 1][j][1];
                    }
                } else {
                    dp[i][j][lastBit] = dp[i][j - 1][0] + dp[i][j - 1][1];
                    if (j > limit) {
                        dp[i][j][lastBit] -= dp[i][j - limit - 1][0];
                    }
                }
                dp[i][j][lastBit] %= MOD;
                if (dp[i][j][lastBit] < 0) {
                    dp[i][j][lastBit] += MOD;
                }
            }
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
}
```

</details>
