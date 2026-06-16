# 3539. Find Sum of Array Product of Magical Sequences

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/)  
`Array` `Math` `Dynamic Programming` `Bit Manipulation` `Combinatorics` `Bitmask`

**Problem Link:** [LeetCode 3539 - Find Sum of Array Product of Magical Sequences](https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/)

## Problem

You are given two integers, m and k, and an integer array nums.

- seq has a size of m.
- 0 <= seq[i] < nums.length
- The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.

The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).

Return the sum of the array products for all valid magical sequences.

Since the answer may be large, return it modulo 109 + 7.

A set bit refers to a bit in the binary representation of a number that has a value of 1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= k <= m <= 30
- 1 <= nums.length <= 50
- 1 <= nums[i] <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Smallest Number With All Set Bits](https://leetcode.com/problems/smallest-number-with-all-set-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3539. Find Sum of Array Product of Magical Sequences

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
long long quickmul(long long x, long long y, long long mod) {
    long long res = 1, cur = x % mod;
    while (y) {
        if (y & 1) {
            res = res * cur % mod;
        }
        y >>= 1;
        cur = cur * cur % mod;
    }
    return res;
}

int magicalSum(int m, int k, int* nums, int numsSize) {
    const long long mod = 1000000007;
    long long* fac = (long long*)malloc((m + 1) * sizeof(long long));
    long long* ifac = (long long*)malloc((m + 1) * sizeof(long long));
    fac[0] = 1;
    for (int i = 1; i <= m; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[0] = 1;
    ifac[1] = 1;
    for (int i = 2; i <= m; i++) {
        ifac[i] = quickmul(i, mod - 2, mod);
    }
    for (int i = 2; i <= m; i++) {
        ifac[i] = ifac[i - 1] * ifac[i] % mod;
    }

    long long** numsPower = (long long**)malloc(numsSize * sizeof(long long*));
    for (int i = 0; i < numsSize; i++) {
        numsPower[i] = (long long*)malloc((m + 1) * sizeof(long long));
        numsPower[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
        }
    }

    long long**** f = (long long****)malloc(numsSize * sizeof(long long***));
    for (int i = 0; i < numsSize; i++) {
        f[i] = (long long***)malloc((m + 1) * sizeof(long long**));
        for (int j = 0; j <= m; j++) {
            f[i][j] = (long long**)malloc((m * 2 + 1) * sizeof(long long*));
            for (int p = 0; p <= m * 2; p++) {
                f[i][j][p] = (long long*)calloc((k + 1), sizeof(long long));
            }
        }
    }

    for (int j = 0; j <= m; j++) {
        f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
    }
    for (int i = 0; i + 1 < numsSize; i++) {
        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= m * 2; p++) {
                for (int q = 0; q <= k; q++) {
                    int q2 = p % 2 + q;
                    if (q2 > k) {
                        break;
                    }
                    for (int r = 0; r + j <= m; r++) {
                        int p2 = p / 2 + r;
                        f[i + 1][j + r][p2][q2] += f[i][j][p][q] *
                                                   numsPower[i + 1][r] % mod *
                                                   ifac[r] % mod;
                        f[i + 1][j + r][p2][q2] %= mod;
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int p = 0; p <= m * 2; p++) {
        for (int q = 0; q <= k; q++) {
            int bitcount = __builtin_popcount(p);
            if (bitcount + q == k) {
                res = (res + f[numsSize - 1][m][p][q] * fac[m] % mod) % mod;
            }
        }
    }
    return (int)res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long quickmul(long long x, long long y, long long mod) {
        long long res = 1, cur = x % mod;
        while (y) {
            if (y & 1) {
                res = res * cur % mod;
            }
            y >>= 1;
            cur = cur * cur % mod;
        }
        return res;
    };

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<long long> fac(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
        vector<long long> ifac(m + 1, 1);
        for (int i = 2; i <= m; i++) {
            ifac[i] = quickmul(i, mod - 2, mod);
        }
        for (int i = 2; i <= m; i++) {
            ifac[i] = ifac[i - 1] * ifac[i] % mod;
        }
        vector numsPower(n, vector<long long>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
            }
        }

        vector f(n,
                 vector(m + 1, vector(m * 2 + 1, vector<long long>(k + 1, 0))));
        for (int j = 0; j <= m; j++) {
            f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = p % 2 + q;
                        if (q2 > k) {
                            break;
                        }
                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            f[i + 1][j + r][p2][q2] += f[i][j][p][q] *
                                                       numsPower[i + 1][r] %
                                                       mod * ifac[r] % mod;
                            f[i + 1][j + r][p2][q2] %= mod;
                        }
                    }
                }
            }
        }
        long long res = 0;
        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (__builtin_popcount(p) + q == k) {
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod) % mod;
                }
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MagicalSum(int m, int k, int[] nums) {
        int n = nums.Length;
        const long mod = 1000000007;

        long[] fac = new long[m + 1];
        fac[0] = 1;
        for (int i = 1; i <= m; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }

        long[] ifac = new long[m + 1];
        ifac[0] = 1;
        ifac[1] = 1;
        for (int i = 2; i <= m; i++) {
            ifac[i] = QuickMul(i, mod - 2, mod);
        }
        for (int i = 2; i <= m; i++) {
            ifac[i] = ifac[i - 1] * ifac[i] % mod;
        }

        long[][] numsPower = new long [n][];
        for (int i = 0; i < n; i++) {
            numsPower[i] = new long[m + 1];
            numsPower[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
            }
        }

        long[][][][] f = new long [n][][][];
        for (int i = 0; i < n; i++) {
            f[i] = new long [m + 1][][];
            for (int j = 0; j <= m; j++) {
                f[i][j] = new long [m * 2 + 1][];
                for (int p = 0; p <= m * 2; p++) {
                    f[i][j][p] = new long[k + 1];
                }
            }
        }

        for (int j = 0; j <= m; j++) {
            f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
        }

        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = (p % 2) + q;
                        if (q2 > k) {
                            break;
                        }
                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            f[i + 1][j + r][p2][q2] += f[i][j][p][q] *
                                                       numsPower[i + 1][r] %
                                                       mod * ifac[r] % mod;
                            f[i + 1][j + r][p2][q2] %= mod;
                        }
                    }
                }
            }
        }

        long res = 0;
        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (BitOperations.PopCount((uint)p) + q == k) {
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod) % mod;
                }
            }
        }
        return (int)res;
    }

    private long QuickMul(long x, long y, long mod) {
        long res = 1, cur = x % mod;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = res * cur % mod;
            }
            y >>= 1;
            cur = cur * cur % mod;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func quickmul(x, y, mod int64) int64 {
    res, cur := int64(1), x % mod
    for y > 0 {
        if y & 1 == 1 {
            res = res * cur % mod
        }
        y >>= 1
        cur = cur * cur % mod
    }
    return res
}

func magicalSum(m int, k int, nums []int) int {
    mod := int64(1000000007)
    fac := make([]int64, m + 1)
    fac[0] = 1
    for i := 1; i <= m; i++ {
        fac[i] = fac[i - 1] * int64(i) % mod
    }
    ifac := make([]int64, m+1)
    ifac[0] = 1
    ifac[1] = 1
    for i := 2; i <= m; i++ {
        ifac[i] = quickmul(int64(i), mod - 2, mod)
    }
    for i := 2; i <= m; i++ {
        ifac[i] = ifac[i - 1] * ifac[i] % mod
    }

    numsPower := make([][]int64, len(nums))
    for i := range nums {
        numsPower[i] = make([]int64, m + 1)
        numsPower[i][0] = 1
        for j := 1; j <= m; j++ {
            numsPower[i][j] = numsPower[i][j - 1] * int64(nums[i]) % mod
        }
    }

    f := make([][][][]int64, len(nums))
    for i := range nums {
        f[i] = make([][][]int64, m+1)
        for j := 0; j <= m; j++ {
            f[i][j] = make([][]int64, m * 2 + 1)
            for p := 0; p <= m * 2; p++ {
                f[i][j][p] = make([]int64, k + 1)
            }
        }
    }

    for j := 0; j <= m; j++ {
        f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod
    }
    for i := 0; i + 1 < len(nums); i++ {
        for j := 0; j <= m; j++ {
            for p := 0; p <= m * 2; p++ {
                for q := 0; q <= k; q++ {
                    q2 := p % 2 + q
                    if q2 > k {
                        break
                    }
                    for r := 0; r + j <= m; r++ {
                        p2 := p / 2 + r
                        f[i + 1][j + r][p2][q2] += f[i][j][p][q] * numsPower[i + 1][r] % mod * ifac[r] % mod
                        f[i + 1][j + r][p2][q2] %= mod
                    }
                }
            }
        }
    }

    res := int64(0)
    for p := 0; p <= m * 2; p++ {
        for q := 0; q <= k; q++ {
            if bits.OnesCount(uint(p)) + q == k {
                res = (res + f[len(nums) - 1][m][p][q] * fac[m] % mod) % mod
            }
        }
    }
    return int(res)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long quickmul(long x, long y, long mod) {
        long res = 1;
        long cur = x % mod;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * cur) % mod;
            }
            y >>= 1;
            cur = (cur * cur) % mod;
        }
        return res;
    }

    public int magicalSum(int m, int k, int[] nums) {
        int n = nums.length;
        long mod = 1000000007;
        long[] fac = new long[m + 1];
        fac[0] = 1;
        for (int i = 1; i <= m; i++) {
            fac[i] = (fac[i - 1] * i) % mod;
        }
        long[] ifac = new long[m + 1];
        ifac[0] = 1;
        ifac[1] = 1;
        for (int i = 2; i <= m; i++) {
            ifac[i] = quickmul(i, mod - 2, mod);
        }
        for (int i = 2; i <= m; i++) {
            ifac[i] = (ifac[i - 1] * ifac[i]) % mod;
        }
        long[][] numsPower = new long[n][m + 1];
        for (int i = 0; i < n; i++) {
            numsPower[i][0] = 1;
            for (int j = 1; j <= m; j++) {
                numsPower[i][j] = (numsPower[i][j - 1] * nums[i]) % mod;
            }
        }
        long[][][][] f = new long[n][m + 1][m * 2 + 1][k + 1];
        for (int j = 0; j <= m; j++) {
            f[0][j][j][0] = (numsPower[0][j] * ifac[j]) % mod;
        }
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int p = 0; p <= m * 2; p++) {
                    for (int q = 0; q <= k; q++) {
                        int q2 = (p % 2) + q;
                        if (q2 > k) {
                            break;
                        }
                        for (int r = 0; r + j <= m; r++) {
                            int p2 = p / 2 + r;
                            f[i + 1][j + r][p2][q2] +=
                                (((f[i][j][p][q] * numsPower[i + 1][r]) % mod) *
                                    ifac[r]) %
                                mod;
                            f[i + 1][j + r][p2][q2] %= mod;
                        }
                    }
                }
            }
        }
        long res = 0;
        for (int p = 0; p <= m * 2; p++) {
            for (int q = 0; q <= k; q++) {
                if (Integer.bitCount(p) + q == k) {
                    res = (res + ((f[n - 1][m][p][q] * fac[m]) % mod)) % mod;
                }
            }
        }
        return (int) res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var magicalSum = function (m, k, nums) {
    const n = nums.length;
    const mod = 1000000007n;

    const fac = new Array(m + 1).fill(1n);
    for (let i = 1; i <= m; i++) {
        fac[i] = (fac[i - 1] * BigInt(i)) % mod;
    }

    const ifac = new Array(m + 1).fill(1n);
    for (let i = 2; i <= m; i++) {
        ifac[i] = quickmul(BigInt(i), mod - 2n, mod);
    }
    for (let i = 2; i <= m; i++) {
        ifac[i] = (ifac[i - 1] * ifac[i]) % mod;
    }

    const numsPower = new Array(n);
    for (let i = 0; i < n; i++) {
        numsPower[i] = new Array(m + 1).fill(1n);
        for (let j = 1; j <= m; j++) {
            numsPower[i][j] = (numsPower[i][j - 1] * BigInt(nums[i])) % mod;
        }
    }

    const f = new Array(n);
    for (let i = 0; i < n; i++) {
        f[i] = new Array(m + 1);
        for (let j = 0; j <= m; j++) {
            f[i][j] = new Array(m * 2 + 1);
            for (let p = 0; p <= m * 2; p++) {
                f[i][j][p] = new Array(k + 1).fill(0n);
            }
        }
    }

    for (let j = 0; j <= m; j++) {
        f[0][j][j][0] = (numsPower[0][j] * ifac[j]) % mod;
    }

    for (let i = 0; i + 1 < n; i++) {
        for (let j = 0; j <= m; j++) {
            for (let p = 0; p <= m * 2; p++) {
                for (let q = 0; q <= k; q++) {
                    if (f[i][j][p][q] === 0n) {
                        continue;
                    }
                    const q2 = (p % 2) + q;
                    if (q2 > k) {
                        break;
                    }
                    for (let r = 0; r + j <= m; r++) {
                        const p2 = Math.floor(p / 2) + r;
                        if (p2 > m * 2) {
                            continue;
                        }
                        f[i + 1][j + r][p2][q2] =
                            (f[i + 1][j + r][p2][q2] +
                                ((((f[i][j][p][q] * numsPower[i + 1][r]) %
                                    mod) *
                                    ifac[r]) %
                                    mod)) %
                            mod;
                    }
                }
            }
        }
    }

    let res = 0n;
    for (let p = 0; p <= m * 2; p++) {
        for (let q = 0; q <= k; q++) {
            if (popCount(p) + q === k) {
                res = (res + ((f[n - 1][m][p][q] * fac[m]) % mod)) % mod;
            }
        }
    }
    return Number(res);
};

const popCount = (x) => {
    let count = 0;
    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
};

const quickmul = (x, y, mod) => {
    let res = 1n;
    let cur = x % mod;
    while (y > 0) {
        if ((y & 1n) == 1n) {
            res = (res * cur) % mod;
        }
        y >>= 1n;
        cur = (cur * cur) % mod;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def quickmul(self, x: int, y: int, mod: int) -> int:
        res, cur = 1, x % mod
        while y:
            if y & 1:
                res = res * cur % mod
            y >>= 1
            cur = cur * cur % mod
        return res

    def magicalSum(self, m: int, k: int, nums: List[int]) -> int:
        n = len(nums)
        mod = 10**9 + 7

        fac = [1] * (m + 1)
        for i in range(1, m + 1):
            fac[i] = fac[i - 1] * i % mod

        ifac = [1] * (m + 1)
        for i in range(2, m + 1):
            ifac[i] = self.quickmul(i, mod - 2, mod)
        for i in range(2, m + 1):
            ifac[i] = ifac[i - 1] * ifac[i] % mod

        numsPower = [[1] * (m + 1) for _ in range(n)]
        for i in range(n):
            for j in range(1, m + 1):
                numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod

        f = [
            [[[0] * (k + 1) for _ in range(m * 2 + 1)] for _ in range(m + 1)]
            for _ in range(n)
        ]

        for j in range(m + 1):
            f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod

        for i in range(n - 1):
            for j in range(m + 1):
                for p in range(m * 2 + 1):
                    for q in range(k + 1):
                        if f[i][j][p][q] == 0:
                            continue
                        q2 = (p % 2) + q
                        if q2 > k:
                            break
                        for r in range(m - j + 1):
                            p2 = (p // 2) + r
                            if p2 > m * 2:
                                continue
                            f[i + 1][j + r][p2][q2] = (
                                f[i + 1][j + r][p2][q2]
                                + f[i][j][p][q]
                                * numsPower[i + 1][r]
                                % mod
                                * ifac[r]
                                % mod
                            ) % mod

        res = 0
        for p in range(m * 2 + 1):
            for q in range(k + 1):
                if bin(p).count("1") + q == k:
                    res = (res + f[n - 1][m][p][q] * fac[m] % mod) % mod
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function magicalSum(m: number, k: number, nums: number[]): number {
    const n = nums.length;
    const mod = 1000000007n;

    const fac: bigint[] = new Array(m + 1).fill(1n);
    for (let i = 1; i <= m; i++) {
        fac[i] = (fac[i - 1] * BigInt(i)) % mod;
    }

    const ifac: bigint[] = new Array(m + 1).fill(1n);
    for (let i = 2; i <= m; i++) {
        ifac[i] = quickmul(BigInt(i), mod - 2n, mod);
    }
    for (let i = 2; i <= m; i++) {
        ifac[i] = (ifac[i - 1] * ifac[i]) % mod;
    }

    const numsPower: bigint[][] = new Array(n);
    for (let i = 0; i < n; i++) {
        numsPower[i] = new Array(m + 1).fill(1n);
        for (let j = 1; j <= m; j++) {
            numsPower[i][j] = (numsPower[i][j - 1] * BigInt(nums[i])) % mod;
        }
    }

    const f: bigint[][][][] = new Array(n);
    for (let i = 0; i < n; i++) {
        f[i] = new Array(m + 1);
        for (let j = 0; j <= m; j++) {
            f[i][j] = new Array(m * 2 + 1);
            for (let p = 0; p <= m * 2; p++) {
                f[i][j][p] = new Array(k + 1).fill(0n);
            }
        }
    }

    for (let j = 0; j <= m; j++) {
        f[0][j][j][0] = (numsPower[0][j] * ifac[j]) % mod;
    }

    for (let i = 0; i + 1 < n; i++) {
        for (let j = 0; j <= m; j++) {
            for (let p = 0; p <= m * 2; p++) {
                for (let q = 0; q <= k; q++) {
                    if (f[i][j][p][q] === 0n) {
                        continue;
                    }
                    const q2 = (p % 2) + q;
                    if (q2 > k) {
                        break;
                    }
                    for (let r = 0; r + j <= m; r++) {
                        const p2 = Math.floor(p / 2) + r;
                        if (p2 > m * 2) {
                            break;
                        }
                        f[i + 1][j + r][p2][q2] =
                            (f[i + 1][j + r][p2][q2] +
                                ((((f[i][j][p][q] * numsPower[i + 1][r]) %
                                    mod) *
                                    ifac[r]) %
                                    mod)) %
                            mod;
                    }
                }
            }
        }
    }

    let res = 0n;
    for (let p = 0; p <= m * 2; p++) {
        for (let q = 0; q <= k; q++) {
            if (bitCount(p) + q === k) {
                res = (res + ((f[n - 1][m][p][q] * fac[m]) % mod)) % mod;
            }
        }
    }
    return Number(res);
}

function quickmul(x: bigint, y: bigint, mod: bigint): bigint {
    let res = 1n;
    let cur = x % mod;
    while (y > 0n) {
        if (y & 1n) {
            res = (res * cur) % mod;
        }
        y >>= 1n;
        cur = (cur * cur) % mod;
    }
    return res;
}

function bitCount(n: number): number {
    let count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
```

</details>
