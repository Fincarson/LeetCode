# 3653. XOR After Range Multiplication Queries I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/)  
`Array` `Divide and Conquer` `Simulation` `Prefix Sum`

**Problem Link:** [LeetCode 3653 - XOR After Range Multiplication Queries I](https://leetcode.com/problems/xor-after-range-multiplication-queries-i/)

## Problem

You are given an integer array nums of length n and a 2D integer array queries of size q, where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

- Set idx = li.
- While idx <= ri:

		Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
		Set idx += ki.

Return the bitwise XOR of all elements in nums after processing all queries.

### Example 1

### Example 2

## Constraints

- 1 <= n == nums.length <= 103
- 1 <= nums[i] <= 109
- 1 <= q == queries.length <= 103
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

# Editorial - 3653. XOR After Range Multiplication Queries I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize,
                    int* queriesColSize) {
    for (int idx = 0; idx < queriesSize; idx++) {
        int l = queries[idx][0];
        int r = queries[idx][1];
        int k = queries[idx][2];
        int v = queries[idx][3];

        for (int i = l; i <= r; i += k) {
            nums[i] = (int)((int64_t)nums[i] * v % MOD);
        }
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
    static const int mod = 1e9 + 7;

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = 1ll * nums[i] * v % mod;
            }
        }
        int res = 0;
        for (auto x : nums) {
            res ^= x;
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

    public int XorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.Length;
        foreach (var q in queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (int)((long)nums[i] * v % MOD);
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
func xorAfterQueries(nums []int, queries [][]int) int {
	const mod = 1_000_000_007

	for _, q := range queries {
		l, r, k, v := q[0], q[1], q[2], q[3]
		for i := l; i <= r; i += k {
			nums[i] = int((int64(nums[i]) * int64(v)) % mod)
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

    public int xorAfterQueries(int[] nums, int[][] queries) {
        int n = nums.length;
        for (int[] q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            for (int i = l; i <= r; i += k) {
                nums[i] = (int) (((long) nums[i] * v) % MOD);
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
var xorAfterQueries = function (nums, queries) {
    const MOD = 1e9 + 7;

    for (const q of queries) {
        const [l, r, k, v] = q;
        for (let i = l; i <= r; i += k) {
            nums[i] = Number((BigInt(nums[i]) * BigInt(v)) % BigInt(MOD));
        }
    }

    let res = 0;
    for (const x of nums) {
        res ^= x;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    MOD = 10**9 + 7

    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        for l, r, k, v in queries:
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % self.MOD

        res = 0
        for x in nums:
            res ^= x

        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function xorAfterQueries(nums: number[], queries: number[][]): number {
    const MOD = 1e9 + 7;
    for (const q of queries) {
        const [l, r, k, v] = q;
        for (let i = l; i <= r; i += k) {
            nums[i] = Number((BigInt(nums[i]) * BigInt(v)) % BigInt(MOD));
        }
    }

    let res = 0;
    for (const x of nums) {
        res ^= x;
    }
    return res;
}
```

</details>
