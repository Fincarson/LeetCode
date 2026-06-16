# 3343. Count Number of Balanced Permutations

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/count-number-of-balanced-permutations/)  
`Math` `String` `Dynamic Programming` `Combinatorics`

**Problem Link:** [LeetCode 3343 - Count Number of Balanced Permutations](https://leetcode.com/problems/count-number-of-balanced-permutations/)

## Problem

You are given a string num. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of the digits at odd indices.

Return the number of distinct permutations of num that are balanced.

Since the answer may be very large, return it modulo 109 + 7.

A permutation is a rearrangement of all the characters of a string.

### Example 1

### Example 2

### Example 3

## Constraints

- 2 <= num.length <= 80
- num consists of digits '0' to '9' only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3343. Count Number of Balanced Permutations

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

long long dfs(int pos, int curr, int oddCnt, int* cnt, int* psum, int target,
              long long*** memo, long long** comb, int maxOdd) {
    /* If the remaining positions cannot be legally filled, or if the sum of the
     * elements at the current odd positions is greater than the target value */
    if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
        return 0;
    }
    if (pos > 9) {
        return curr == target && oddCnt == 0;
    }
    if (memo[pos][curr][oddCnt] != -1) {
        return memo[pos][curr][oddCnt];
    }

    /* Even-numbered positions remaining to be filled */
    int evenCnt = psum[pos] - oddCnt;
    long long res = 0;
    int start = fmax(0, cnt[pos] - evenCnt);
    int end = fmin(cnt[pos], oddCnt);
    for (int i = start; i <= end; i++) {
        /* The current digit is filled with i positions at odd positions, and
         * cnt[pos] - i positions at even positions */
        long long ways = comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
        res = (res + ways *
                         dfs(pos + 1, curr + i * pos, oddCnt - i, cnt, psum,
                             target, memo, comb, maxOdd) %
                         MOD) %
              MOD;
    }
    memo[pos][curr][oddCnt] = res;
    return res;
}

int countBalancedPermutations(char* num) {
    int tot = 0, n = strlen(num);
    int cnt[10] = {0};
    for (int i = 0; i < n; i++) {
        int d = num[i] - '0';
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 != 0) {
        return 0;
    }

    int target = tot / 2;
    int maxOdd = (n + 1) / 2;

    /* Pre-calculate combinations */
    long long** comb = (long long**)malloc((maxOdd + 1) * sizeof(long long*));
    for (int i = 0; i <= maxOdd; i++) {
        comb[i] = (long long*)malloc((maxOdd + 1) * sizeof(long long));
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    int psum[11] = {0};
    for (int i = 9; i >= 0; i--) {
        psum[i] = psum[i + 1] + cnt[i];
    }
    /* Initialize memoization array */
    long long*** memo = (long long***)malloc(10 * sizeof(long long**));
    for (int i = 0; i < 10; i++) {
        memo[i] = (long long**)malloc((target + 1) * sizeof(long long*));
        for (int j = 0; j <= target; j++) {
            memo[i][j] = (long long*)malloc((maxOdd + 1) * sizeof(long long));
            for (int k = 0; k <= maxOdd; k++) {
                memo[i][j][k] = -1;
            }
        }
    }

    long long result = dfs(0, 0, maxOdd, cnt, psum, target, memo, comb, maxOdd);
    for (int i = 0; i <= maxOdd; i++) {
        free(comb[i]);
    }
    free(comb);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <= target; j++) {
            free(memo[i][j]);
        }
        free(memo[i]);
    }
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
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<int> psum(11);
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        long long memo[10][target + 1][maxOdd + 1];
        memset(memo, 0xff, sizeof(memo));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        function<long long(int, int, int)> dfs = [&](int pos, int curr,
                                                     int oddCnt) -> long long {
            /* If the remaining positions cannot be legally filled, or if the
             * sum of the elements at the current odd positions is greater than
             * the target value */
            if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
                return 0;
            }
            if (pos > 9) {
                return curr == target && oddCnt == 0;
            }
            if (memo[pos][curr][oddCnt] != -1) {
                return memo[pos][curr][oddCnt];
            }
            /* Even-numbered positions remaining to be filled */
            int evenCnt = psum[pos] - oddCnt;
            long long res = 0;
            for (int i = max(0, cnt[pos] - evenCnt); i <= min(cnt[pos], oddCnt);
                 i++) {
                /* The current digit is filled with i positions at odd
                 * positions, and cnt[pos] - i positions at even positions */
                long long ways =
                    comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i] % MOD;
                res = (res +
                       ways * dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) %
                      MOD;
            }
            memo[pos][curr][oddCnt] = res;
            return res;
        };

        return dfs(0, 0, maxOdd);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
using System;

public class Solution {
    private const long MOD = 1_000_000_007;
    private long[,,] memo;
    private int[] cnt;
    private int[] psum;
    private int target;
    private long[,] comb;

    public int CountBalancedPermutations(string num) {
        int tot = 0, n = num.Length;
        cnt = new int[10];
        foreach (char ch in num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        target = tot / 2;
        int maxOdd = (n + 1) / 2;

        /* Pre-calculate combinations */
        comb = new long[maxOdd + 1, maxOdd + 1];
        for (int i = 0; i <= maxOdd; i++) {
            comb[i, i] = comb[i, 0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i, j] = (comb[i - 1, j] + comb[i - 1, j - 1]) % MOD;
            }
        }

        psum = new int[11];
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        memo = new long[10, target + 1, maxOdd + 1];
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j <= target; j++) {
                for (int k = 0; k <= maxOdd; k++) {
                    memo[i, j, k] = -1;
                }
            }
        }

        return (int)Dfs(0, 0, maxOdd);
    }

    private long Dfs(int pos, int curr, int oddCnt) {
        /* If the remaining positions cannot be legally filled, or if the sum of
         * the elements at the current odd positions is greater than the target
         * value */
        if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
            return 0;
        }
        if (pos > 9) {
            return (curr == target && oddCnt == 0) ? 1 : 0;
        }
        if (memo[pos, curr, oddCnt] != -1) {
            return memo[pos, curr, oddCnt];
        }
        /* Even-numbered positions remaining to be filled */
        int evenCnt = psum[pos] - oddCnt;
        long res = 0;
        for (int i = Math.Max(0, cnt[pos] - evenCnt);
             i <= Math.Min(cnt[pos], oddCnt); i++) {
            /* The current digit is filled with i positions at odd positions,
             * and cnt[pos] - i positions at even positions */
            long ways = comb[oddCnt, i] * comb[evenCnt, cnt[pos] - i] % MOD;
            res =
                (res + ways * Dfs(pos + 1, curr + i * pos, oddCnt - i) % MOD) %
                MOD;
        }
        memo[pos, curr, oddCnt] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1_000_000_007

func countBalancedPermutations(num string) int {
	tot, n := 0, len(num)
	cnt := make([]int, 10)
	for _, ch := range num {
		d := int(ch - '0')
		cnt[d]++
		tot += d
	}
	if tot%2 != 0 {
		return 0
	}

	target := tot / 2
	maxOdd := (n + 1) / 2
	/* Pre-calculate combinations */
	comb := make([][]int, maxOdd+1)
	for i := range comb {
		comb[i] = make([]int, maxOdd+1)
		comb[i][i], comb[i][0] = 1, 1
		for j := 1; j < i; j++ {
			comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD
		}
	}

	psum := make([]int, 11)
	for i := 9; i >= 0; i-- {
		psum[i] = psum[i+1] + cnt[i]
	}

	memo := make([][][]int, 10)
	for i := range memo {
		memo[i] = make([][]int, target+1)
		for j := range memo[i] {
			memo[i][j] = make([]int, maxOdd+1)
			for k := range memo[i][j] {
				memo[i][j][k] = -1
			}
		}
	}

	var dfs func(pos, curr, oddCnt int) int
	dfs = func(pos, curr, oddCnt int) int {
		/* If the remaining positions cannot be legally filled, or if the sum of the elements at the current odd positions is greater than the target value */
		if oddCnt < 0 || psum[pos] < oddCnt || curr > target {
			return 0
		}
		if pos > 9 {
			if curr == target && oddCnt == 0 {
				return 1
			}
			return 0
		}
		if memo[pos][curr][oddCnt] != -1 {
			return memo[pos][curr][oddCnt]
		}
		/* Even-numbered positions remaining to be filled */
		evenCnt := psum[pos] - oddCnt
		res := 0
		start := max(0, cnt[pos]-evenCnt)
		end := min(cnt[pos], oddCnt)
		for i := start; i <= end; i++ {
			/* The current digit is filled with i positions at odd positions, and cnt[pos] - i positions at even positions */
			ways := comb[oddCnt][i] * comb[evenCnt][cnt[pos]-i] % MOD
			res = (res + ways*dfs(pos+1, curr+i*pos, oddCnt-i)%MOD) % MOD
		}
		memo[pos][curr][oddCnt] = res
		return res
	}

	return dfs(0, 0, maxOdd)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final long MOD = 1_000_000_007;
    private long[][][] memo;
    private int[] cnt;
    private int[] psum;
    private int target;
    private long[][] comb;

    public int countBalancedPermutations(String num) {
        int tot = 0, n = num.length();
        cnt = new int[10];
        for (char ch : num.toCharArray()) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        target = tot / 2;
        int maxOdd = (n + 1) / 2;

        /* Pre-calculate combinations */
        comb = new long[maxOdd + 1][maxOdd + 1];
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        psum = new int[11];
        for (int i = 9; i >= 0; i--) {
            psum[i] = psum[i + 1] + cnt[i];
        }

        memo = new long[10][target + 1][maxOdd + 1];
        for (long[][] arr2 : memo) {
            for (long[] arr1 : arr2) {
                Arrays.fill(arr1, -1);
            }
        }

        return (int) dfs(0, 0, maxOdd);
    }

    private long dfs(int pos, int curr, int oddCnt) {
        /* If the remaining positions cannot be legally filled, or if the sum of the elements at the current odd positions is greater than the target value */
        if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
            return 0;
        }
        if (pos > 9) {
            return curr == target && oddCnt == 0 ? 1 : 0;
        }
        if (memo[pos][curr][oddCnt] != -1) {
            return memo[pos][curr][oddCnt];
        }
        /* Even-numbered positions remaining to be filled */
        int evenCnt = psum[pos] - oddCnt;
        long res = 0;
        for (
            int i = Math.max(0, cnt[pos] - evenCnt);
            i <= Math.min(cnt[pos], oddCnt);
            i++
        ) {
            /* The current digit is filled with i positions at odd positions, and cnt[pos] - i positions at even positions */
            long ways = (comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i]) % MOD;
            res =
                (res +
                    ((ways * dfs(pos + 1, curr + i * pos, oddCnt - i)) % MOD)) %
                MOD;
        }
        memo[pos][curr][oddCnt] = res;
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = BigInt(1e9 + 7);

var countBalancedPermutations = function (num) {
    let tot = 0,
        n = num.length;
    const cnt = new Array(10).fill(0);
    for (const ch of num) {
        const d = parseInt(ch);
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 !== 0) {
        return 0;
    }

    const target = tot / 2;
    const maxOdd = Math.floor((n + 1) / 2);

    /* Pre-calculate combinations */
    const comb = new Array(maxOdd + 1);
    for (let i = 0; i <= maxOdd; i++) {
        comb[i] = new Array(maxOdd + 1).fill(0n);
        comb[i][i] = comb[i][0] = 1n;
        for (let j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    const psum = new Array(11).fill(0);
    for (let i = 9; i >= 0; i--) {
        psum[i] = psum[i + 1] + cnt[i];
    }

    const memo = new Array(10);
    for (let i = 0; i < 10; i++) {
        memo[i] = new Array(target + 1);
        for (let j = 0; j <= target; j++) {
            memo[i][j] = new Array(maxOdd + 1).fill(-1n);
        }
    }

    function dfs(pos, curr, oddCnt) {
        /* If the remaining positions cannot be legally filled, or if the sum of the elements at the current odd positions is greater than the target value */
        if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
            return 0n;
        }
        if (pos > 9) {
            return curr === target && oddCnt === 0 ? 1n : 0n;
        }
        if (memo[pos][curr][oddCnt] !== -1n) {
            return memo[pos][curr][oddCnt];
        }

        /* Even-numbered positions remaining to be filled */
        const evenCnt = psum[pos] - oddCnt;
        let res = 0n;
        const start = Math.max(0, cnt[pos] - evenCnt);
        const end = Math.min(cnt[pos], oddCnt);
        for (let i = start; i <= end; i++) {
            /* The current digit is filled with i positions at odd positions, and cnt[pos] - i positions at even positions */
            const ways = (comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i]) % MOD;
            res =
                (res +
                    ((ways * dfs(pos + 1, curr + i * pos, oddCnt - i)) % MOD)) %
                MOD;
        }
        memo[pos][curr][oddCnt] = res;
        return res;
    }

    return Number(dfs(0, 0, maxOdd));
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        MOD = 10**9 + 7
        num = list(map(int, num))
        tot = sum(num)
        if tot % 2 != 0:
            return 0
        target = tot // 2
        cnt = Counter(num)
        n = len(num)
        maxOdd = (n + 1) // 2
        psum = [0] * 11
        for i in range(9, -1, -1):
            psum[i] = psum[i + 1] + cnt[i]

        @cache
        def dfs(pos, curr, oddCnt):
            # If the remaining positions cannot complete a legal placement, or the sum of the elements in the current odd positions is greater than the target value
            if oddCnt < 0 or psum[pos] < oddCnt or curr > target:
                return 0
            if pos > 9:
                return int(curr == target and oddCnt == 0)
            evenCnt = (
                psum[pos] - oddCnt
            )  # Even-numbered positions remaining to be filled
            res = 0
            for i in range(
                max(0, cnt[pos] - evenCnt), min(cnt[pos], oddCnt) + 1
            ):
                # Place i of the current number at odd positions, and cnt[pos] - i at even positions
                ways = comb(oddCnt, i) * comb(evenCnt, cnt[pos] - i) % MOD
                res += ways * dfs(pos + 1, curr + i * pos, oddCnt - i)
            return res % MOD

        return dfs(0, 0, maxOdd)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = BigInt(1e9 + 7);

function countBalancedPermutations(num: string): number {
    let tot = 0;
    const n = num.length;
    const cnt: number[] = new Array(10).fill(0);
    for (const ch of num) {
        const d = parseInt(ch);
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 !== 0) {
        return 0;
    }

    const target = Math.floor(tot / 2);
    const maxOdd = Math.floor((n + 1) / 2);

    /* Pre-calculate combinations */
    const comb: bigint[][] = new Array(maxOdd + 1);
    for (let i = 0; i <= maxOdd; i++) {
        comb[i] = new Array(maxOdd + 1).fill(0n);
        comb[i][i] = comb[i][0] = 1n;
        for (let j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    const psum: number[] = new Array(11).fill(0);
    for (let i = 9; i >= 0; i--) {
        psum[i] = psum[i + 1] + cnt[i];
    }
    const memo: bigint[][][] = new Array(10);
    for (let i = 0; i < 10; i++) {
        memo[i] = new Array(target + 1);
        for (let j = 0; j <= target; j++) {
            memo[i][j] = new Array(maxOdd + 1).fill(-1n);
        }
    }

    const dfs = (pos: number, curr: number, oddCnt: number): bigint => {
        /* If the remaining positions cannot be legally filled, or if the sum of the elements at the current odd positions is greater than the target value */
        if (oddCnt < 0 || psum[pos] < oddCnt || curr > target) {
            return 0n;
        }
        if (pos > 9) {
            return curr === target && oddCnt === 0 ? 1n : 0n;
        }
        if (memo[pos][curr][oddCnt] !== -1n) {
            return memo[pos][curr][oddCnt];
        }

        /* Even-numbered positions remaining to be filled */
        const evenCnt = psum[pos] - oddCnt;
        let res = 0n;
        const start = Math.max(0, cnt[pos] - evenCnt);
        const end = Math.min(cnt[pos], oddCnt);
        for (let i = start; i <= end; i++) {
            /* The current digit is filled with i positions at odd positions, and cnt[pos] - i positions at even positions */
            const ways = (comb[oddCnt][i] * comb[evenCnt][cnt[pos] - i]) % MOD;
            res =
                (res +
                    ((ways * dfs(pos + 1, curr + i * pos, oddCnt - i)) % MOD)) %
                MOD;
        }
        memo[pos][curr][oddCnt] = res;
        return res;
    };

    return Number(dfs(0, 0, maxOdd));
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

int countBalancedPermutations(char* num) {
    int tot = 0, n = strlen(num);
    int cnt[10] = {0};
    for (int i = 0; i < n; i++) {
        int d = num[i] - '0';
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 != 0) {
        return 0;
    }

    int target = tot / 2;
    int maxOdd = (n + 1) / 2;
    long long comb[maxOdd + 1][maxOdd + 1];
    long long f[target + 1][maxOdd + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= maxOdd; i++) {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    f[0][0] = 1;
    int psum = 0, totSum = 0;
    for (int i = 0; i <= 9; i++) {
        /* Sum of the number of the first i digits */
        psum += cnt[i];
        /* Sum of the first i numbers */
        totSum += i * cnt[i];
        for (int oddCnt = fmin(psum, maxOdd);
             oddCnt >= fmax(0, psum - (n - maxOdd)); oddCnt--) {
            /* The number of bits that need to be filled in even numbered
             * positions */
            int evenCnt = psum - oddCnt;
            for (int curr = fmin(totSum, target);
                 curr >= fmax(0, totSum - target); curr--) {
                long long res = 0;
                for (int j = fmax(0, cnt[i] - evenCnt);
                     j <= fmin(cnt[i], oddCnt) && i * j <= curr; j++) {
                    /* The current digit is filled with j positions at odd
                     * positions, and cnt[i] - j positions at even positions */
                    long long ways =
                        comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                    res =
                        (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                }
                f[curr][oddCnt] = res % MOD;
            }
        }
    }

    return f[target][maxOdd];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    int countBalancedPermutations(string num) {
        int tot = 0, n = num.size();
        vector<int> cnt(10);
        for (char ch : num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        vector<vector<long long>> comb(maxOdd + 1,
                                       vector<long long>(maxOdd + 1));
        vector<vector<long long>> f(target + 1, vector<long long>(maxOdd + 1));
        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
            /* Sum of the first i numbers */
            totSum += i * cnt[i];
            for (int oddCnt = min(psum, maxOdd);
                 oddCnt >= max(0, psum - (n - maxOdd)); oddCnt--) {
                /* The number of bits that need to be filled in even numbered
                 * positions */
                int evenCnt = psum - oddCnt;
                for (int curr = min(totSum, target);
                     curr >= max(0, totSum - target); curr--) {
                    long long res = 0;
                    for (int j = max(0, cnt[i] - evenCnt);
                         j <= min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        /* The current digit is filled with j positions at odd
                         * positions, and cnt[i] - j positions at even positions
                         */
                        long long ways =
                            comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) %
                              MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return f[target][maxOdd];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const long MOD = 1_000_000_007;

    public int CountBalancedPermutations(string num) {
        int tot = 0, n = num.Length;
        int[] cnt = new int[10];
        foreach (char ch in num) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        long[,] comb = new long[maxOdd + 1, maxOdd + 1];
        long[,] f = new long[target + 1, maxOdd + 1];

        for (int i = 0; i <= maxOdd; i++) {
            comb[i, i] = comb[i, 0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i, j] = (comb[i - 1, j] + comb[i - 1, j - 1]) % MOD;
            }
        }

        f[0, 0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
            /* Sum of the first i numbers */
            totSum += i * cnt[i];
            for (int oddCnt = Math.Min(psum, maxOdd);
                 oddCnt >= Math.Max(0, psum - (n - maxOdd)); oddCnt--) {
                /* The number of bits that need to be filled in even numbered
                 * positions */
                int evenCnt = psum - oddCnt;
                for (int curr = Math.Min(totSum, target);
                     curr >= Math.Max(0, totSum - target); curr--) {
                    long res = 0;
                    for (int j = Math.Max(0, cnt[i] - evenCnt);
                         j <= Math.Min(cnt[i], oddCnt) && i * j <= curr; j++) {
                        /* The current digit is filled with j positions at odd
                         * positions, and cnt[i] - j positions at even positions
                         */
                        long ways =
                            comb[oddCnt, j] * comb[evenCnt, cnt[i] - j] % MOD;
                        res = (res + ways * f[curr - i * j, oddCnt - j] % MOD) %
                              MOD;
                    }
                    f[curr, oddCnt] = res % MOD;
                }
            }
        }

        return (int)f[target, maxOdd];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const MOD = 1_000_000_007

func countBalancedPermutations(num string) int {
    tot, n := 0, len(num)
    cnt := make([]int, 10)
    for _, ch := range num {
        d := int(ch - '0')
        cnt[d]++
        tot += d
    }
    if tot % 2 != 0 {
        return 0
    }

    target := tot / 2
    maxOdd := (n + 1) / 2
    comb := make([][]int, maxOdd + 1)
    for i := range comb {
        comb[i] = make([]int, maxOdd + 1)
        comb[i][i], comb[i][0] = 1, 1
        for j := 1; j < i; j++ {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD
        }
    }

    f := make([][]int, target + 1)
    for i := range f {
        f[i] = make([]int, maxOdd + 1)
    }
    f[0][0] = 1

    psum, totSum := 0, 0
    for i := 0; i <= 9; i++ {
        /* Sum of the number of the first i digits */
        psum += cnt[i]
        /* Sum of the first i numbers */
        totSum += i * cnt[i]
        for oddCnt := min(psum, maxOdd); oddCnt >= max(0, psum- (n - maxOdd)); oddCnt-- {
            /* The number of bits that need to be filled in even numbered positions */
            evenCnt := psum - oddCnt
            for curr := min(totSum, target); curr >= max(0, totSum - target); curr-- {
                res := 0
                for j := max(0, cnt[i] - evenCnt); j <= min(cnt[i], oddCnt) && i * j <= curr; j++ {
                    /* The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions */
                    ways := comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD
                    res = (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD
                }
                f[curr][oddCnt] = res % MOD
            }
        }
    }

    return f[target][maxOdd]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final long MOD = 1_000_000_007;

    public int countBalancedPermutations(String num) {
        int tot = 0, n = num.length();
        int[] cnt = new int[10];
        for (char ch : num.toCharArray()) {
            int d = ch - '0';
            cnt[d]++;
            tot += d;
        }
        if (tot % 2 != 0) {
            return 0;
        }

        int target = tot / 2;
        int maxOdd = (n + 1) / 2;
        long[][] comb = new long[maxOdd + 1][maxOdd + 1];
        long[][] f = new long[target + 1][maxOdd + 1];

        for (int i = 0; i <= maxOdd; i++) {
            comb[i][i] = comb[i][0] = 1;
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
            }
        }

        f[0][0] = 1;
        int psum = 0, totSum = 0;
        for (int i = 0; i <= 9; i++) {
            /* Sum of the number of the first i digits */
            psum += cnt[i];
            /* Sum of the first i numbers */
            totSum += i * cnt[i];
            for (
                int oddCnt = Math.min(psum, maxOdd);
                oddCnt >= Math.max(0, psum - (n - maxOdd));
                oddCnt--
            ) {
                /* The number of bits that need to be filled in even numbered positions */
                int evenCnt = psum - oddCnt;
                for (
                    int curr = Math.min(totSum, target);
                    curr >= Math.max(0, totSum - target);
                    curr--
                ) {
                    long res = 0;
                    for (
                        int j = Math.max(0, cnt[i] - evenCnt);
                        j <= Math.min(cnt[i], oddCnt) && i * j <= curr;
                        j++
                    ) {
                        /* The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions */
                        long ways =
                            (comb[oddCnt][j] * comb[evenCnt][cnt[i] - j]) % MOD;
                        res =
                            (res +
                                ((ways * f[curr - i * j][oddCnt - j]) % MOD)) %
                            MOD;
                    }
                    f[curr][oddCnt] = res % MOD;
                }
            }
        }

        return (int) f[target][maxOdd];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = BigInt(1e9 + 7);

var countBalancedPermutations = function (num) {
    let tot = 0;
    const n = num.length;
    const cnt = new Array(10).fill(0);
    for (const ch of num) {
        const d = parseInt(ch);
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 !== 0) {
        return 0;
    }

    const target = tot / 2;
    const maxOdd = Math.floor((n + 1) / 2);
    const comb = new Array(maxOdd + 1);
    for (let i = 0; i <= maxOdd; i++) {
        comb[i] = new Array(maxOdd + 1).fill(0n);
        comb[i][i] = comb[i][0] = 1n;
        for (let j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    const f = new Array(Number(target) + 1);
    for (let i = 0; i <= Number(target); i++) {
        f[i] = new Array(maxOdd + 1).fill(0n);
    }
    f[0][0] = 1n;

    let psum = 0,
        totSum = 0;
    for (let i = 0; i <= 9; i++) {
        /* Sum of the number of the first i digits */
        psum += cnt[i];
        /* Sum of the first i numbers */
        totSum += i * cnt[i];
        for (
            let oddCnt = Math.min(psum, maxOdd);
            oddCnt >= Math.max(0, psum - (n - maxOdd));
            oddCnt--
        ) {
            /* The number of bits that need to be filled in even numbered positions */
            const evenCnt = psum - oddCnt;
            for (
                let curr = Math.min(totSum, target);
                curr >= Math.max(0, totSum - target);
                curr--
            ) {
                let res = 0n;
                for (
                    let j = Math.max(0, cnt[i] - evenCnt);
                    j <= Math.min(cnt[i], oddCnt) && i * j <= curr;
                    j++
                ) {
                    /* The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions */
                    const ways =
                        (comb[oddCnt][j] * comb[evenCnt][cnt[i] - j]) % MOD;
                    res =
                        (res + ((ways * f[curr - i * j][oddCnt - j]) % MOD)) %
                        MOD;
                }
                f[curr][oddCnt] = res % MOD;
            }
        }
    }

    return Number(f[target][maxOdd]);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        MOD = 10**9 + 7
        tot, n = 0, len(num)
        cnt = [0] * 10
        for ch in num:
            d = int(ch)
            cnt[d] += 1
            tot += d
        if tot % 2 != 0:
            return 0

        target = tot // 2
        max_odd = (n + 1) // 2
        f = [[0] * (max_odd + 1) for _ in range(target + 1)]
        f[0][0] = 1
        psum = tot_sum = 0
        for i in range(10):
            # Sum of the number of the first i digits
            psum += cnt[i]
            # Sum of the first i numbers
            tot_sum += i * cnt[i]
            for odd_cnt in range(
                min(psum, max_odd), max(0, psum - (n - max_odd)) - 1, -1
            ):
                # The number of bits that need to be filled in even numbered positions
                even_cnt = psum - odd_cnt
                for curr in range(
                    min(tot_sum, target), max(0, tot_sum - target) - 1, -1
                ):
                    res = 0
                    for j in range(
                        max(0, cnt[i] - even_cnt), min(cnt[i], odd_cnt) + 1
                    ):
                        if i * j > curr:
                            break
                        # The current digit is filled with j positions at odd positions, and cnt[i] - j positions at even positions
                        ways = (
                            comb(odd_cnt, j) * comb(even_cnt, cnt[i] - j) % MOD
                        )
                        res = (
                            res + ways * f[curr - i * j][odd_cnt - j] % MOD
                        ) % MOD
                    f[curr][odd_cnt] = res % MOD

        return f[target][max_odd]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = BigInt(1e9 + 7);

function countBalancedPermutations(num: string): number {
    let tot = 0;
    const n = num.length;
    const cnt: number[] = new Array(10).fill(0);
    for (const ch of num) {
        const d = parseInt(ch);
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 !== 0) {
        return 0;
    }

    const target = tot / 2;
    const maxOdd = Math.floor((n + 1) / 2);
    const comb: bigint[][] = new Array(maxOdd + 1);
    for (let i = 0; i <= maxOdd; i++) {
        comb[i] = new Array(maxOdd + 1).fill(0n);
        comb[i][i] = comb[i][0] = 1n;
        for (let j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
    const f: bigint[][] = new Array(Number(target) + 1);
    for (let i = 0; i <= Number(target); i++) {
        f[i] = new Array(maxOdd + 1).fill(0n);
    }
    f[0][0] = 1n;

    let psum = 0,
        totSum = 0;
    for (let i = 0; i <= 9; i++) {
        /* Sum of the number of the first i digits */
        psum += cnt[i];
        /* Sum of the first i numbers */
        totSum += i * cnt[i];
        for (
            let oddCnt = Math.min(psum, maxOdd);
            oddCnt >= Math.max(0, psum - (n - maxOdd));
            oddCnt--
        ) {
            /* The number of bits that need to be filled in even numbered positions */
            const evenCnt = psum - oddCnt;
            for (
                let curr = Math.min(totSum, target);
                curr >= Math.max(0, totSum - target);
                curr--
            ) {
                let res = 0n;
                for (
                    let j = Math.max(0, cnt[i] - evenCnt);
                    j <= Math.min(cnt[i], oddCnt) && i * j <= curr;
                    j++
                ) {
                    /* The current digit is filled with i positions at odd positions, and cnt[i] - j positions at even positions */
                    const ways =
                        (comb[oddCnt][j] * comb[evenCnt][cnt[i] - j]) % MOD;
                    res =
                        (res + ((ways * f[curr - i * j][oddCnt - j]) % MOD)) %
                        MOD;
                }
                f[curr][oddCnt] = res % MOD;
            }
        }
    }

    return Number(f[target][maxOdd]);
}
```

</details>
