# 2464. Minimum Subarrays in a Valid Split

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/)  
`Array` `Math` `Dynamic Programming` `Number Theory`

**Problem Link:** [LeetCode 2464 - Minimum Subarrays in a Valid Split](https://leetcode.com/problems/minimum-subarrays-in-a-valid-split/)

## Problem

You are given an integer array nums.

Splitting of an integer array nums into subarrays is valid if:

- the greatest common divisor of the first and last elements of each subarray is greater than 1, and
- each element of nums belongs to exactly one subarray.

Return the minimum number of subarrays in a valid subarray splitting of nums. If a valid subarray splitting is not possible, return -1.

Note that:

- The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
- A subarray is a contiguous non-empty part of an array.

### Example 1

```text
Input: nums = [2,6,3,4,3]
Output: 2
Explanation: We can create a valid split in the following way: [2,6] | [3,4,3].
- The starting element of the 1st subarray is 2 and the ending is 6. Their greatest common divisor is 2, which is greater than 1.
- The starting element of the 2nd subarray is 3 and the ending is 3. Their greatest common divisor is 3, which is greater than 1.
It can be proved that 2 is the minimum number of subarrays that we can obtain in a valid split.
```

### Example 2

```text
Input: nums = [3,5]
Output: 2
Explanation: We can create a valid split in the following way: [3] | [5].
- The starting element of the 1st subarray is 3 and the ending is 3. Their greatest common divisor is 3, which is greater than 1.
- The starting element of the 2nd subarray is 5 and the ending is 5. Their greatest common divisor is 5, which is greater than 1.
It can be proved that 2 is the minimum number of subarrays that we can obtain in a valid split.
```

### Example 3

```text
Input: nums = [1,2,1]
Output: -1
Explanation: It is impossible to create valid split.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Split Into Subarrays With GCD Greater Than One](https://leetcode.com/problems/minimum-split-into-subarrays-with-gcd-greater-than-one/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2464. Minimum Subarrays in a Valid Split

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming | C, C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
const int INF = 1e9;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int validSubarraySplit(int* nums, int numsSize) {
    int dp[numsSize + 1];
    for (int i = 1; i <= numsSize; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        for (int j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = (dp[i] < dp[j - 1] + 1) ? dp[i] : dp[j - 1] + 1;
            }
        }
    }
    return (dp[numsSize] == INF) ? -1 : dp[numsSize];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static constexpr int INF = 1e9;
    int validSubarraySplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (__gcd(nums[i - 1], nums[j - 1]) > 1) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const INF = 1e9

func validSubarraySplit(nums []int) int {
	n := len(nums)
	dp := make([]int, n+1)
	for i := 0; i <= n; i++ {
		dp[i] = INF
	}
	dp[0] = 0
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			if gcd(nums[i-1], nums[j-1]) > 1 {
				dp[i] = min(dp[i], dp[j-1]+1)
			}
		}
	}
	if dp[n] == INF {
		return -1
	}
	return dp[n]
}

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static final int INF = 1000000000;

    public int validSubarraySplit(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                    dp[i] = Math.min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }

    public static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const INF = 1e9;

function gcd(a, b) {
    if (b === 0) return a;
    return gcd(b, a % b);
}

var validSubarraySplit = function (nums) {
    const n = nums.length;
    const dp = new Array(n + 1).fill(INF);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = Math.min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] === INF ? -1 : dp[n];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def validSubarraySplit(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [inf] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                if math.gcd(nums[i - 1], nums[j - 1]) > 1:
                    dp[i] = min(dp[i], dp[j - 1] + 1)
        return -1 if dp[n] == inf else dp[n]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const INF: number = 1e9;

function gcd(a: number, b: number): number {
    if (b === 0) return a;
    return gcd(b, a % b);
}

function validSubarraySplit(nums: number[]): number {
    const n: number = nums.length;
    const dp: number[] = new Array(n + 1).fill(INF);
    dp[0] = 0;
    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            if (gcd(nums[i - 1], nums[j - 1]) > 1) {
                dp[i] = Math.min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n] === INF ? -1 : dp[n];
}
```

</details>
