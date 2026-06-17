# 3640. Trionic Array II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/trionic-array-ii/)  
`Array` `Dynamic Programming`

**Problem Link:** [LeetCode 3640 - Trionic Array II](https://leetcode.com/problems/trionic-array-ii/)

## Problem

You are given an integer array nums of length n.

A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

- nums[l...p] is strictly increasing,
- nums[p...q] is strictly decreasing,
- nums[q...r] is strictly increasing.

Return the maximum sum of any trionic subarray in nums.

### Example 1

### Example 2

## Constraints

- 4 <= n = nums.length <= 105
- -109 <= nums[i] <= 109
- It is guaranteed that at least one trionic subarray exists.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3640. Trionic Array II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Grouped Loop | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Grouped Loop

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maxSumTrionic(int* nums, int numsSize) {
    int n = numsSize;
    int p, q, j;
    long long max_sum, sum, res;
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        j = i + 1;
        res = 0;
        // first segment
        for (; j < n && nums[j - 1] < nums[j]; j++);
        p = j - 1;
        if (p == i) {
            continue;
        }
        // second segment
        res += nums[p] + nums[p - 1];
        for (; j < n && nums[j - 1] > nums[j]; j++) {
            res += nums[j];
        }
        q = j - 1;
        if (q == p || q == n - 1 || (j < n && nums[j] <= nums[q])) {
            i = q;
            continue;
        }
        // third segment
        res += nums[q + 1];
        // find the maximum sum of the third segment
        max_sum = 0;
        sum = 0;
        for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
            sum += nums[k];
            max_sum = fmaxl(max_sum, sum);
        }
        res += max_sum;
        // find the maximum sum of the first segment
        max_sum = 0;
        sum = 0;
        for (int k = p - 2; k >= i; k--) {
            sum += nums[k];
            max_sum = fmaxl(max_sum, sum);
        }
        res += max_sum;
        // update answer
        if (res > ans) {
            ans = res;
        }
        i = q - 1;
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int p, q, j;
        long long max_sum, sum, res;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;
            // first segment
            for (; j < n && nums[j - 1] < nums[j]; j++);
            p = j - 1;
            if (p == i) {
                continue;
            }
            // second segment
            res += nums[p] + nums[p - 1];
            for (; j < n && nums[j - 1] > nums[j]; j++) {
                res += nums[j];
            }
            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }
            // third segment
            res += nums[q + 1];
            // find the maximum sum of the third segment
            max_sum = 0;
            sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            // find the maximum sum of the first segment
            max_sum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            // update answer
            ans = max(ans, res);
            i = q - 1;
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaxSumTrionic(int[] nums) {
        int n = nums.Length;
        int p, q, j;
        long max_sum, sum, res;
        long ans = long.MinValue;
        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;
            // first segment
            for (; j < n && nums[j - 1] < nums[j]; j++);
            p = j - 1;
            if (p == i) {
                continue;
            }
            // second segment
            res += nums[p] + nums[p - 1];
            for (; j < n && nums[j - 1] > nums[j]; j++) {
                res += nums[j];
            }
            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }
            // third segment
            res += nums[q + 1];
            // find the maximum sum of the third segment
            max_sum = 0;
            sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                max_sum = Math.Max(max_sum, sum);
            }
            res += max_sum;
            // find the maximum sum of the first segment
            max_sum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                max_sum = Math.Max(max_sum, sum);
            }
            res += max_sum;
            // update answer
            ans = Math.Max(ans, res);
            i = q - 1;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSumTrionic(nums []int) int64 {
	n := len(nums)
	var p, q, j int
	var max_sum, sum, res int64
	ans := int64(math.MinInt64)
	for i := 0; i < n; i++ {
		j = i + 1
		res = 0
		// first segment
		for ; j < n && nums[j-1] < nums[j]; j++ {
		}
		p = j - 1
		if p == i {
			continue
		}
		// second segment
		res += int64(nums[p] + nums[p-1])
		for ; j < n && nums[j-1] > nums[j]; j++ {
			res += int64(nums[j])
		}
		q = j - 1
		if q == p || q == n-1 || (j < n && nums[j] <= nums[q]) {
			i = q
			continue
		}
		// third segment
		res += int64(nums[q+1])
		// find the maximum sum of the third segment
		max_sum = 0
		sum = 0
		for k := q + 2; k < n && nums[k] > nums[k-1]; k++ {
			sum += int64(nums[k])
			if sum > max_sum {
				max_sum = sum
			}
		}
		res += max_sum
		// find the maximum sum of the first segment
		max_sum = 0
		sum = 0
		for k := p - 2; k >= i; k-- {
			sum += int64(nums[k])
			if sum > max_sum {
				max_sum = sum
			}
		}
		res += max_sum
		// update answer
		if res > ans {
			ans = res
		}
		i = q - 1
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxSumTrionic(int[] nums) {
        int n = nums.length;
        long ans = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int j = i + 1;
            long res = 0;

            // first segment: increasing segment
            while (j < n && nums[j - 1] < nums[j]) {
                j++;
            }
            int p = j - 1;

            if (p == i) {
                continue;
            }

            // second segment: decreasing segment
            res += nums[p] + nums[p - 1];
            while (j < n && nums[j - 1] > nums[j]) {
                res += nums[j];
                j++;
            }
            int q = j - 1;

            if (q == p || q == n - 1 || (j < n && nums[j] <= nums[q])) {
                i = q;
                continue;
            }

            // third segment: increasing segment
            res += nums[q + 1];

            // find the maximum sum of the third segment
            long maxSum = 0;
            long sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                maxSum = Math.max(maxSum, sum);
            }
            res += maxSum;

            // find the maximum sum of the first segment
            maxSum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                maxSum = Math.max(maxSum, sum);
            }
            res += maxSum;

            // update answer
            ans = Math.max(ans, res);
            i = q - 1;
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSumTrionic = function (nums) {
    const n = nums.length;
    let ans = -Infinity;

    for (let i = 0; i < n; i++) {
        let j = i + 1;
        let res = 0;

        // first segment: increasing segment
        while (j < n && nums[j - 1] < nums[j]) {
            j++;
        }
        const p = j - 1;

        if (p === i) {
            continue;
        }

        // second segment: decreasing segment
        res += nums[p] + nums[p - 1];
        while (j < n && nums[j - 1] > nums[j]) {
            res += nums[j];
            j++;
        }
        const q = j - 1;

        if (q === p || q === n - 1 || (j < n && nums[j] <= nums[q])) {
            i = q;
            continue;
        }

        // third segment: increasing segment
        res += nums[q + 1];

        // find the maximum sum of the third segment
        let maxSum = 0;
        let sum = 0;
        for (let k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
            sum += nums[k];
            maxSum = Math.max(maxSum, sum);
        }
        res += maxSum;

        // find the maximum sum of the first segment
        maxSum = 0;
        sum = 0;
        for (let k = p - 2; k >= i; k--) {
            sum += nums[k];
            maxSum = Math.max(maxSum, sum);
        }
        res += maxSum;

        // update answer
        ans = Math.max(ans, res);
        i = q - 1;
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        n = len(nums)
        ans = float("-inf")
        i = 0

        while i < n:
            j = i + 1
            res = 0

            # first segment: increasing segment
            while j < n and nums[j - 1] < nums[j]:
                j += 1
            p = j - 1

            if p == i:  # Ã¦Â²Â¡Ã¦Å“â€°Ã¦Å“â€°Ã¦â€¢Ë†Ã§Å¡â€žincreasing segment
                i += 1
                continue

            # second segment: decreasing segment
            res += nums[p] + nums[p - 1]
            while j < n and nums[j - 1] > nums[j]:
                res += nums[j]
                j += 1
            q = j - 1

            if q == p or q == n - 1 or (j < n and nums[j] <= nums[q]):
                i = q
                continue

            # third segment: increasing segment
            res += nums[q + 1]

            # find the maximum sum of the third segment
            max_sum = 0
            curr_sum = 0
            k = q + 2
            while k < n and nums[k] > nums[k - 1]:
                curr_sum += nums[k]
                max_sum = max(max_sum, curr_sum)
                k += 1
            res += max_sum

            # find the maximum sum of the first segment
            max_sum = 0
            curr_sum = 0
            for k in range(p - 2, i - 1, -1):
                curr_sum += nums[k]
                max_sum = max(max_sum, curr_sum)
            res += max_sum

            # update answer
            ans = max(ans, res)
            i = q

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSumTrionic(nums: number[]): number {
    const n = nums.length;
    let p: number, q: number, j: number;
    let max_sum: number, sum: number, res: number;
    let ans: number = -Infinity;
    for (let i = 0; i < n; i++) {
        j = i + 1;
        res = 0;
        //first segment
        for (; j < n && nums[j - 1] < nums[j]; j++);
        p = j - 1;
        if (p === i) {
            continue;
        }
        //second segment
        res += nums[p] + nums[p - 1];
        for (; j < n && nums[j - 1] > nums[j]; j++) {
            res += nums[j];
        }
        q = j - 1;
        if (q === p || q === n - 1 || (j < n && nums[j] <= nums[q])) {
            i = q;
            continue;
        }
        //third segment
        res += nums[q + 1];
        //find the maximum sum of the third segment
        max_sum = 0;
        sum = 0;
        for (let k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
            sum += nums[k];
            max_sum = Math.max(max_sum, sum);
        }
        res += max_sum;
        //find the maximum sum of the first segment
        max_sum = 0;
        sum = 0;
        for (let k = p - 2; k >= i; k--) {
            sum += nums[k];
            max_sum = Math.max(max_sum, sum);
        }
        res += max_sum;
        //update answer
        ans = Math.max(ans, res);
        i = q - 1;
    }
    return ans;
}
```

</details>
