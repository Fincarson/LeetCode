# 2770. Maximum Number of Jumps to Reach the Last Index

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 2770 - Maximum Number of Jumps to Reach the Last Index](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/)

## Problem

You are given a 0-indexed array nums of n integers and an integer target.

You are initially positioned at index 0. In one step, you can jump from index i to any index j such that:

- 0 <= i < j < n
- -target <= nums[j] - nums[i] <= target

Return the maximum number of jumps you can make to reach index n - 1.

If there is no way to reach index n - 1, return -1.

### Example 1

```text
Input: nums = [1,3,6,4,1,2], target = 2
Output: 3
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1.
- Jump from index 1 to index 3.
- Jump from index 3 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 3 jumps. Hence, the answer is 3.
```

### Example 2

```text
Input: nums = [1,3,6,4,1,2], target = 3
Output: 5
Explanation: To go from index 0 to index n - 1 with the maximum number of jumps, you can perform the following jumping sequence:
- Jump from index 0 to index 1.
- Jump from index 1 to index 2.
- Jump from index 2 to index 3.
- Jump from index 3 to index 4.
- Jump from index 4 to index 5.
It can be proven that there is no other jumping sequence that goes from 0 to n - 1 with more than 5 jumps. Hence, the answer is 5.
```

### Example 3

```text
Input: nums = [1,3,6,4,1,2], target = 0
Output: -1
Explanation: It can be proven that there is no jumping sequence that goes from 0 to n - 1. Hence, the answer is -1.
```

## Constraints

- 2 <= nums.length == n <= 1000
- -109 <= nums[i] <= 109
- 0 <= target <= 2 * 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Jump Game II](https://leetcode.com/problems/jump-game-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Frog Jump](https://leetcode.com/problems/frog-jump/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Jump Game III](https://leetcode.com/problems/jump-game-iii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game IV](https://leetcode.com/problems/jump-game-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimum Jumps to Reach Home](https://leetcode.com/problems/minimum-jumps-to-reach-home/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Jump Game VII](https://leetcode.com/problems/jump-game-vii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2770. Maximum Number of Jumps to Reach the Last Index

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
int dfs(int i, int* nums, int n, int target, int* memo) {
    if (i == n - 1) {
        return 0;
    }
    if (memo[i] != INT_MIN) {
        return memo[i];
    }

    int res = INT_MIN;
    for (int j = i + 1; j < n; j++) {
        if (abs(nums[i] - nums[j]) <= target) {
            res = fmax(res, dfs(j, nums, n, target, memo) + 1);
        }
    }
    memo[i] = res;
    return res;
}

int maximumJumps(int* nums, int numsSize, int target) {
    int* memo = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        memo[i] = INT_MIN;
    }

    int ans = dfs(0, nums, numsSize, target, memo);
    free(memo);
    return ans < 0 ? -1 : ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> memo(n, INT_MIN);

        function<int(int)> dfs = [&](int i) -> int {
            if (i == n - 1) {
                return 0;
            }
            if (memo[i] != INT_MIN) {
                return memo[i];
            }
            int res = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (abs(nums[i] - nums[j]) <= target) {
                    res = max(res, dfs(j) + 1);
                }
            }
            return memo[i] = res;
        };

        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximumJumps(int[] nums, int target) {
        int n = nums.Length;
        int[] memo = new int[n];
        Array.Fill(memo, int.MinValue);

        Func<int, int> dfs = null;
        dfs = (i) => {
            if (i == n - 1) {
                return 0;
            }
            if (memo[i] != int.MinValue) {
                return memo[i];
            }
            int res = int.MinValue;
            for (int j = i + 1; j < n; j++) {
                if (Math.Abs(nums[i] - nums[j]) <= target) {
                    res = Math.Max(res, dfs(j) + 1);
                }
            }
            return memo[i] = res;
        };

        int ans = dfs(0);
        return ans < 0 ? -1 : ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumJumps(nums []int, target int) int {
	n := len(nums)
	memo := make([]int, n)
	for i := range memo {
		memo[i] = math.MinInt32
	}

	var dfs func(int) int
	dfs = func(i int) int {
		if i == n-1 {
			return 0
		}
		if memo[i] != math.MinInt32 {
			return memo[i]
		}

		res := math.MinInt32
		for j := i + 1; j < n; j++ {
			if abs(nums[i]-nums[j]) <= target {
				res = max(res, dfs(j)+1)
			}
		}
		memo[i] = res
		return res
	}

	ans := dfs(0)
	if ans < 0 {
		return -1
	}
	return ans
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] memo = new int[n];
        Arrays.fill(memo, Integer.MIN_VALUE);

        int ans = dfs(0, nums, target, memo);
        return ans < 0 ? -1 : ans;
    }

    private int dfs(int i, int[] nums, int target, int[] memo) {
        int n = nums.length;
        if (i == n - 1) {
            return 0;
        }
        if (memo[i] != Integer.MIN_VALUE) {
            return memo[i];
        }
        int res = Integer.MIN_VALUE;
        for (int j = i + 1; j < n; j++) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                res = Math.max(res, dfs(j, nums, target, memo) + 1);
            }
        }
        return memo[i] = res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumJumps = function (nums, target) {
    const n = nums.length;
    const memo = new Array(n).fill(Number.MIN_SAFE_INTEGER);

    const dfs = (i) => {
        if (i === n - 1) {
            return 0;
        }
        if (memo[i] !== Number.MIN_SAFE_INTEGER) {
            return memo[i];
        }

        let res = Number.MIN_SAFE_INTEGER;
        for (let j = i + 1; j < n; j++) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                res = Math.max(res, dfs(j) + 1);
            }
        }
        memo[i] = res;
        return res;
    };

    const ans = dfs(0);
    return ans < 0 ? -1 : ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        @cache
        def dfs(i: int):
            if i == len(nums) - 1:
                return 0

            res = -inf
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) <= target:
                    res = max(res, dfs(j) + 1)
            return res

        ans = dfs(0)
        return -1 if ans < 0 else ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumJumps(nums: number[], target: number): number {
    const n: number = nums.length;
    const memo: number[] = new Array(n).fill(Number.MIN_SAFE_INTEGER);

    const dfs = (i: number): number => {
        if (i === n - 1) {
            return 0;
        }
        if (memo[i] !== Number.MIN_SAFE_INTEGER) {
            return memo[i];
        }

        let res: number = Number.MIN_SAFE_INTEGER;
        for (let j: number = i + 1; j < n; j++) {
            if (Math.abs(nums[i] - nums[j]) <= target) {
                res = Math.max(res, dfs(j) + 1);
            }
        }
        memo[i] = res;
        return res;
    };

    const ans: number = dfs(0);
    return ans < 0 ? -1 : ans;
}
```

</details>

<br>

## Approach 2: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maximumJumps(int* nums, int numsSize, int target) {
    int* dp = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        dp[i] = INT_MIN;
    }
    dp[0] = 0;

    for (int i = 1; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(nums[j] - nums[i]) <= target) {
                if (dp[j] != INT_MIN) {
                    dp[i] = fmax(dp[i], dp[j] + 1);
                }
            }
        }
    }

    int result = dp[numsSize - 1] < 0 ? -1 : dp[numsSize - 1];
    free(dp);
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (abs(nums[j] - nums[i]) <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] < 0 ? -1 : dp[n - 1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaximumJumps(int[] nums, int target) {
        int n = nums.Length;
        int[] dp = new int[n];
        Array.Fill(dp, int.MinValue);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (Math.Abs(nums[j] - nums[i]) <= target) {
                    dp[i] = Math.Max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] < 0 ? -1 : dp[n - 1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumJumps(nums []int, target int) int {
	n := len(nums)
	dp := make([]int, n)
	for i := range dp {
		dp[i] = math.MinInt32
	}
	dp[0] = 0

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if abs(nums[j]-nums[i]) <= target {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
	}

	if dp[n-1] < 0 {
		return -1
	}
	return dp[n-1]
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumJumps(int[] nums, int target) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (Math.abs(nums[j] - nums[i]) <= target) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] < 0 ? -1 : dp[n - 1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumJumps = function (nums, target) {
    const n = nums.length;
    const dp = new Array(n).fill(Number.MIN_SAFE_INTEGER);
    dp[0] = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (Math.abs(nums[j] - nums[i]) <= target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1] < 0 ? -1 : dp[n - 1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from typing import List


class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        dp = [float("-inf")] * n
        dp[0] = 0

        for i in range(1, n):
            for j in range(i):
                if abs(nums[j] - nums[i]) <= target:
                    dp[i] = max(dp[i], dp[j] + 1)

        return -1 if dp[n - 1] < 0 else dp[n - 1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maximumJumps(nums: number[], target: number): number {
    const n: number = nums.length;
    const dp: number[] = new Array(n).fill(Number.MIN_SAFE_INTEGER);
    dp[0] = 0;

    for (let i: number = 1; i < n; i++) {
        for (let j: number = 0; j < i; j++) {
            if (Math.abs(nums[j] - nums[i]) <= target) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
    }

    return dp[n - 1] < 0 ? -1 : dp[n - 1];
}
```

</details>
