# 3655. XOR After Range Multiplication Queries II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/)  
`Array` `Divide and Conquer` `Prefix Sum`

**Problem Link:** [LeetCode 3655 - XOR After Range Multiplication Queries II](https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/)

## Problem

You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

- Set idx = li.
- While idx <= ri:

		Update: nums[idx] = (nums[idx] * vi) % (109 + 7).
		Set idx += ki.

Return the bitwise XOR of all elements in nums after processing all queries.

### Example 1

### Example 2

## Constraints

- 1 <= n == nums.length <= 105
- 1 <= nums[i] <= 109
- 1 <= q == queries.length <= 105​​​​​​​
- queries[i] = [li, ri, ki, vi]
- 0 <= li <= ri < n
- 1 <= ki <= n
- 1 <= vi <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3655. XOR After Range Multiplication Queries II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Square Root Decomposition + Difference Array | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Square Root Decomposition + Difference Array

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int pow_mod(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return (int)res;
}

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize,
                    int* queriesColSize) {
    int n = numsSize;
    int T = (int)sqrt(n);
    int*** groups = (int***)malloc(T * sizeof(int**));
    int* groupCounts = (int*)calloc(T, sizeof(int));
    int* groupCapacities = (int*)calloc(T, sizeof(int));

    for (int i = 0; i < T; i++) {
        groupCapacities[i] = 10;
        groups[i] = (int**)malloc(groupCapacities[i] * sizeof(int*));
    }

    for (int idx = 0; idx < queriesSize; idx++) {
        int l = queries[idx][0], r = queries[idx][1];
        int k = queries[idx][2], v = queries[idx][3];

        if (k < T) {
            if (groupCounts[k] >= groupCapacities[k]) {
                groupCapacities[k] *= 2;
                groups[k] = (int**)realloc(groups[k],
                                           groupCapacities[k] * sizeof(int*));
            }
            int* q = (int*)malloc(3 * sizeof(int));
            q[0] = l;
            q[1] = r;
            q[2] = v;
            groups[k][groupCounts[k]++] = q;
        } else {
            for (int i = l; i <= r; i += k) {
                nums[i] = (int)((long long)nums[i] * v % MOD);
            }
        }
    }

    long long* dif = (long long*)calloc(n + T, sizeof(long long));
    for (int k = 1; k < T; k++) {
        if (groupCounts[k] == 0) {
            continue;
        }
        for (int i = 0; i < n + T; i++) {
            dif[i] = 1;
        }
        for (int g = 0; g < groupCounts[k]; g++) {
            int l = groups[k][g][0];
            int r = groups[k][g][1];
            int v = groups[k][g][2];

            dif[l] = dif[l] * v % MOD;
            int R = ((r - l) / k + 1) * k + l;
            dif[R] = dif[R] * pow_mod(v, MOD - 2) % MOD;
        }

        for (int i = k; i < n; i++) {
            dif[i] = dif[i] * dif[i - k] % MOD;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = (int)((long long)nums[i] * dif[i] % MOD);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < groupCounts[i]; j++) {
            free(groups[i][j]);
        }
        free(groups[i]);
    }
    free(groups);
    free(groupCounts);
    free(groupCapacities);
    free(dif);

    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    const int mod = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y) {
        ll res = 1;
        for (; y; y >>= 1) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
        }
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int T = sqrt(n);
        vector<vector<vector<int>>> groups(T);
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) {
                groups[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = 1ll * nums[i] * v % mod;
                }
            }
        }

        vector<ll> dif(n + T);
        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) {
                continue;
            }
            fill(dif.begin(), dif.end(), 1);
            for (auto& q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % mod;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * pow(v, mod - 2) % mod;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % mod;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = 1ll * nums[i] * dif[i] % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res ^ nums[i];
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
    private const int MOD = 1_000_000_007;

    private int Pow(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            y >>= 1;
        }
        return (int)res;
    }

    public int XorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.Length;
        int T = (int)Math.Sqrt(n);

        List<List<int[]>> groups = new List<List<int[]>>(T);
        for (int i = 0; i < T; i++) {
            groups.Add(new List<int[]>());
        }

        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k < T) {
                groups[k].Add(new int[] { l, r, v });
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int)((long)nums[i] * v % MOD);
                }
            }
        }

        long[] dif = new long[n + T];
        for (int k = 1; k < T; k++) {
            if (groups[k].Count == 0) {
                continue;
            }
            Array.Fill(dif, 1L);
            foreach (var q in groups[k]) {
                int l = q[0], r = q[1], v = q[2];
                dif[l] = dif[l] * v % MOD;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = dif[R] * Pow(v, MOD - 2) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = dif[i] * dif[i - k] % MOD;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = (int)((long)nums[i] * dif[i] % MOD);
            }
        }

        int res = 0;
        foreach (int x in nums) {
            res ^= x;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const mod = 1_000_000_007

func pow(x, y int64) int {
	res := int64(1)
	for y > 0 {
		if y&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		y >>= 1
	}
	return int(res)
}

func xorAfterQueries(nums []int, queries [][]int) int {
	n := len(nums)
	T := int(math.Sqrt(float64(n)))

	groups := make([][][]int, T)
	for i := 0; i < T; i++ {
		groups[i] = make([][]int, 0)
	}

	for _, q := range queries {
		l, r, k, v := q[0], q[1], q[2], q[3]
		if k < T {
			groups[k] = append(groups[k], []int{l, r, v})
		} else {
			for i := l; i <= r; i += k {
				nums[i] = int((int64(nums[i]) * int64(v)) % mod)
			}
		}
	}

	dif := make([]int64, n+T)
	for k := 1; k < T; k++ {
		if len(groups[k]) == 0 {
			continue
		}
		for i := range dif {
			dif[i] = 1
		}
		for _, q := range groups[k] {
			l, r, v := q[0], q[1], q[2]
			dif[l] = dif[l] * int64(v) % mod
			R := ((r-l)/k+1)*k + l
			dif[R] = dif[R] * int64(pow(int64(v), mod-2)) % mod
		}

		for i := k; i < n; i++ {
			dif[i] = dif[i] * dif[i-k] % mod
		}
		for i := 0; i < n; i++ {
			nums[i] = int((int64(nums[i]) * dif[i]) % mod)
		}
	}

	res := 0
	for _, x := range nums {
		res ^= x
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1_000_000_007;

    private int pow(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }
        return (int) res;
    }

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        int T = (int) Math.sqrt(n);
        List<List<int[]>> groups = new ArrayList<>(T);
        for (int i = 0; i < T; i++) {
            groups.add(new ArrayList<>());
        }

        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            if (k < T) {
                groups.get(k).add(new int[] { l, r, v });
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (int) (((long) nums[i] * v) % MOD);
                }
            }
        }

        long[] dif = new long[n + T];
        for (int k = 1; k < T; k++) {
            if (groups.get(k).isEmpty()) {
                continue;
            }
            Arrays.fill(dif, 1);
            for (int[] q : groups.get(k)) {
                int l = q[0];
                int r = q[1];
                int v = q[2];
                dif[l] = (dif[l] * v) % MOD;
                int R = ((r - l) / k + 1) * k + l;
                dif[R] = (dif[R] * pow(v, MOD - 2)) % MOD;
            }

            for (int i = k; i < n; i++) {
                dif[i] = (dif[i] * dif[i - k]) % MOD;
            }
            for (int i = 0; i < n; i++) {
                nums[i] = (int) (((long) nums[i] * dif[i]) % MOD);
            }
        }

        int res = 0;
        for (int x : nums) {
            res ^= x;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1_000_000_007n;

const pow = (x, y) => {
    let res = 1n;
    for (; y > 0n; y >>= 1n) {
        if (y & 1n) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
    }
    return res;
};

var xorAfterQueries = function (nums, queries) {
    const n = nums.length;
    const T = Math.floor(Math.sqrt(n));
    const groups = Array.from({ length: T }, () => []);

    for (const [l, r, k, v] of queries) {
        if (k < T) {
            groups[k].push([l, r, BigInt(v)]);
        } else {
            for (let i = l; i <= r; i += k) {
                nums[i] = Number((BigInt(nums[i]) * BigInt(v)) % MOD);
            }
        }
    }

    const dif = new BigInt64Array(n + T);
    for (let k = 1; k < T; k++) {
        if (groups[k].length === 0) {
            continue;
        }
        dif.fill(1n);
        for (let [l, r, v] of groups[k]) {
            dif[l] = (dif[l] * BigInt(v)) % MOD;
            const R = Math.floor((r - l) / k + 1) * k + l;
            dif[R] = (dif[R] * pow(BigInt(v), MOD - 2n)) % MOD;
        }

        for (let i = k; i < n; i++) {
            dif[i] = (dif[i] * dif[i - k]) % MOD;
        }
        for (let i = 0; i < n; i++) {
            nums[i] = Number((BigInt(nums[i]) * dif[i]) % MOD);
        }
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        res = res ^ nums[i];
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = 10**9 + 7
        n = len(nums)
        T = int(n**0.5)

        groups = [[] for _ in range(T)]
        for l, r, k, v in queries:
            if k < T:
                groups[k].append((l, r, v))
            else:
                for i in range(l, r + 1, k):
                    nums[i] = nums[i] * v % mod

        dif = [1] * (n + T)
        for k in range(1, T):
            if not groups[k]:
                continue
            dif[:] = [1] * len(dif)
            for l, r, v in groups[k]:
                dif[l] = dif[l] * v % mod
                R = ((r - l) // k + 1) * k + l
                dif[R] = dif[R] * pow(v, mod - 2, mod) % mod

            for i in range(k, n):
                dif[i] = dif[i] * dif[i - k] % mod
            for i in range(n):
                nums[i] = nums[i] * dif[i] % mod

        res = 0
        for x in nums:
            res ^= x
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1_000_000_007n;

const pow = (x: bigint, y: bigint) => {
    let res = 1n;
    for (; y > 0n; y >>= 1n) {
        if (y & 1n) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
    }
    return res;
};

function xorAfterQueries(nums: number[], queries: number[][]): number {
    const n = nums.length;
    const T = Math.floor(Math.sqrt(n));
    const groups = Array.from<unknown, Array<[number, number, bigint]>>(
        { length: T },
        () => [],
    );

    for (const [l, r, k, v] of queries) {
        if (k < T) {
            groups[k].push([l, r, BigInt(v)]);
        } else {
            for (let i = l; i <= r; i += k) {
                nums[i] = Number((BigInt(nums[i]) * BigInt(v)) % MOD);
            }
        }
    }

    const dif = new BigInt64Array(n + T);
    for (let k = 1; k < T; k++) {
        if (groups[k].length === 0) {
            continue;
        }
        dif.fill(1n);
        for (let [l, r, v] of groups[k]) {
            dif[l] = (dif[l] * BigInt(v)) % MOD;
            const R = Math.floor((r - l) / k + 1) * k + l;
            dif[R] = (dif[R] * pow(BigInt(v), MOD - 2n)) % MOD;
        }

        for (let i = k; i < n; i++) {
            dif[i] = (dif[i] * dif[i - k]) % MOD;
        }
        for (let i = 0; i < n; i++) {
            nums[i] = Number((BigInt(nums[i]) * dif[i]) % MOD);
        }
    }

    let res = 0;
    for (let i = 0; i < n; i++) {
        res = res ^ nums[i];
    }
    return res;
}
```

</details>
