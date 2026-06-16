# 3202. Find the Maximum Length of Valid Subsequence II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 3202 - Find the Maximum Length of Valid Subsequence II](https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/)

## Problem

A subsequence sub of nums with length x is called valid if it satisfies:

- (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 103
- 1 <= nums[i] <= 107
- 1 <= k <= 103

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Length of the Longest Subsequence That Sums to Target](https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3202. Find the Maximum Length of Valid Subsequence II

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
int maximumLength(int* nums, int numsSize, int k) {
    int dp[k][k];
    memset(dp, 0, sizeof(dp));
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i] % k;
        for (int prev = 0; prev < k; prev++) {
            dp[prev][num] = dp[num][prev] + 1;
            if (dp[prev][num] > res) {
                res = dp[prev][num];
            }
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int num : nums) {
            num %= k;
            for (int prev = 0; prev < k; ++prev) {
                dp[prev][num] = dp[num][prev] + 1;
                res = max(res, dp[prev][num]);
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
    public int MaximumLength(int[] nums, int k) {
        int[,] dp = new int[k, k];
        int res = 0;
        foreach (int num in nums) {
            int mod = num % k;
            for (int prev = 0; prev < k; prev++) {
                dp[prev, mod] = dp[mod, prev] + 1;
                res = Math.Max(res, dp[prev, mod]);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumLength(nums []int, k int) int {
	dp := make([][]int, k)
	for i := range dp {
		dp[i] = make([]int, k)
	}
	res := 0
	for _, num := range nums {
		num %= k
		for prev := 0; prev < k; prev++ {
			dp[prev][num] = dp[num][prev] + 1
			res = max(res, dp[prev][num])
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumLength(int[] nums, int k) {
        int[][] dp = new int[k][k];
        int res = 0;
        for (int num : nums) {
            num %= k;
            for (int prev = 0; prev < k; prev++) {
                dp[prev][num] = dp[num][prev] + 1;
                res = Math.max(res, dp[prev][num]);
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumLength = function (nums, k) {
    const dp = Array.from({ length: k }, () => new Array(k).fill(0));
    let res = 0;
    for (const num of nums) {
        const mod = num % k;
        for (let prev = 0; prev < k; prev++) {
            dp[prev][mod] = dp[mod][prev] + 1;
            res = Math.max(res, dp[prev][mod]);
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp = [[0] * k for _ in range(k)]
        res = 0
        for num in nums:
            num %= k
            for prev in range(k):
                dp[prev][num] = dp[num][prev] + 1
                res = max(res, dp[prev][num])
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumLength(nums: number[], k: number): number {
    const dp: number[][] = Array.from({ length: k }, () =>
        new Array(k).fill(0),
    );
    let res = 0;
    for (const num of nums) {
        const mod = num % k;
        for (let prev = 0; prev < k; prev++) {
            dp[prev][mod] = dp[mod][prev] + 1;
            res = Math.max(res, dp[prev][mod]);
        }
    }
    return res;
}
```

</details>
