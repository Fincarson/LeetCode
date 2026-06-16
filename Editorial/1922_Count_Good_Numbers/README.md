# 1922. Count Good Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-good-numbers/)  
`Math` `Recursion`

**Problem Link:** [LeetCode 1922 - Count Good Numbers](https://leetcode.com/problems/count-good-numbers/)

## Problem

A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

- For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

### Example 1

```text
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
```

### Example 2

```text
Input: n = 4
Output: 400
```

### Example 3

```text
Input: n = 50
Output: 564908303
```

## Constraints

- 1 <= n <= 1015

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count the Number of Arrays with K Matching Adjacent Elements](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1922. Count Good Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Fast Exponentiation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Fast Exponentiation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

// use fast exponentiation to calculate x^y % mod
long long quickmul(int x, long long y) {
    long long ret = 1;
    long long mul = x;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (ret * mul) % MOD;
        }
        mul = (mul * mul) % MOD;
        y /= 2;
    }
    return ret;
}

int countGoodNumbers(long long n) {
    return (int)(quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % MOD);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countGoodNumbers(long long n) {
        // use fast exponentiation to calculate x^y % mod
        auto quickmul = [](int x, long long y) -> int {
            int ret = 1, mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (long long)ret * mul % mod;
                }
                mul = (long long)mul * mul % mod;
                y /= 2;
            }
            return ret;
        };

        return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    long mod = 1000000007;

    public int CountGoodNumbers(long n) {
        return (int)(Quickmul(5, (n + 1) / 2) * Quickmul(4, n / 2) % mod);
    }

    // use fast exponentiation to calculate x^y % mod
    public long Quickmul(int x, long y) {
        long ret = 1;
        long mul = x;
        while (y > 0) {
            if (y % 2 == 1) {
                ret = ret * mul % mod;
            }
            mul = mul * mul % mod;
            y /= 2;
        }

        return ret;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countGoodNumbers(n int64) int {
	mod := int64(1000000007)

	// use fast exponentiation to calculate x^y % mod
	quickmul := func(x, y int64) int64 {
		ret := int64(1)
		mul := x
		for y > 0 {
			if y%2 == 1 {
				ret = ret * mul % mod
			}
			mul = mul * mul % mod
			y /= 2
		}
		return ret
	}

	return int(quickmul(5, (n+1)/2) * quickmul(4, n/2) % mod)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    long mod = 1000000007;

    public int countGoodNumbers(long n) {
        return (int) ((quickmul(5, (n + 1) / 2) * quickmul(4, n / 2)) % mod);
    }

    // use fast exponentiation to calculate x^y % mod
    public long quickmul(int x, long y) {
        long ret = 1;
        long mul = x;
        while (y > 0) {
            if (y % 2 == 1) {
                ret = (ret * mul) % mod;
            }
            mul = (mul * mul) % mod;
            y /= 2;
        }

        return ret;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countGoodNumbers = function (n) {
    const mod = 1000000007n;

    // use fast exponentiation to calculate x^y % mod
    function quickmul(x, y) {
        let ret = 1n;
        let mul = x;
        while (y > 0) {
            if (y % 2n === 1n) {
                ret = (ret * mul) % mod;
            }
            mul = (mul * mul) % mod;
            y = y / 2n;
        }
        return ret;
    }

    return Number(
        (quickmul(5n, BigInt(n + 1) / 2n) * quickmul(4n, BigInt(n) / 2n)) % mod,
    );
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        mod = 10**9 + 7

        # use fast exponentiation to calculate x^y % mod
        def quickmul(x: int, y: int) -> int:
            ret, mul = 1, x
            while y > 0:
                if y % 2 == 1:
                    ret = ret * mul % mod
                mul = mul * mul % mod
                y //= 2
            return ret

        return quickmul(5, (n + 1) // 2) * quickmul(4, n // 2) % mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countGoodNumbers(n: number): number {
    const mod: bigint = 1000000007n;

    // use fast exponentiation to calculate x^y % mod
    function quickmul(x: bigint, y: bigint): bigint {
        let ret: bigint = 1n;
        let mul: bigint = x;
        while (y > 0n) {
            if (y % 2n === 1n) {
                ret = (ret * mul) % mod;
            }
            mul = (mul * mul) % mod;
            y = y / 2n;
        }
        return ret;
    }

    return Number(
        (quickmul(5n, BigInt(n + 1) / 2n) * quickmul(4n, BigInt(n) / 2n)) % mod,
    );
}
```

</details>
