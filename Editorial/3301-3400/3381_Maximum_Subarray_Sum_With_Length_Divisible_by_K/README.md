# 3381. Maximum Subarray Sum With Length Divisible by K

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/)  
`Array` `Hash Table` `Prefix Sum`

**Problem Link:** [LeetCode 3381 - Maximum Subarray Sum With Length Divisible by K](https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/)

## Problem

You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= k <= nums.length <= 2 * 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subarray Sums Divisible by K](https://leetcode.com/problems/subarray-sums-divisible-by-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3381. Maximum Subarray Sum With Length Divisible by K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Sum | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Prefix Sum

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long prefixSum = 0;
    long long maxSum = LONG_MIN;
    long long* kSum = (long long*)malloc(sizeof(long long) * k);
    for (int i = 0; i < k; i++) {
        kSum[i] = LLONG_MAX / 2;
    }
    kSum[k - 1] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum += nums[i];
        if (prefixSum - kSum[i % k] > maxSum) {
            maxSum = prefixSum - kSum[i % k];
        }
        if (prefixSum < kSum[i % k]) {
            kSum[i % k] = prefixSum;
        }
    }
    free(kSum);
    return maxSum;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long prefixSum = 0, maxSum = LONG_LONG_MIN;
        vector<long long> kSum(k, LONG_LONG_MAX / 2);
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaxSubarraySum(int[] nums, int k) {
        int n = nums.Length;
        long prefixSum = 0;
        long maxSum = long.MinValue;
        long[] kSum = new long[k];
        for (int i = 0; i < k; i++) {
            kSum[i] = long.MaxValue / 2;
        }
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = Math.Max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = Math.Min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxSubarraySum(nums []int, k int) int64 {
	n := len(nums)
	prefixSum := int64(0)
	maxSum := int64(math.MinInt64)
	kSum := make([]int64, k)
	for i := 0; i < k; i++ {
		kSum[i] = math.MaxInt64 / 2
	}
	kSum[k-1] = 0
	for i := 0; i < n; i++ {
		prefixSum += int64(nums[i])
		if prefixSum-kSum[i%k] > maxSum {
			maxSum = prefixSum - kSum[i%k]
		}
		if prefixSum < kSum[i%k] {
			kSum[i%k] = prefixSum
		}
	}
	return maxSum
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long prefixSum = 0;
        long maxSum = Long.MIN_VALUE;
        long[] kSum = new long[k];
        for (int i = 0; i < k; i++) {
            kSum[i] = Long.MAX_VALUE / 2;
        }
        kSum[k - 1] = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            maxSum = Math.max(maxSum, prefixSum - kSum[i % k]);
            kSum[i % k] = Math.min(kSum[i % k], prefixSum);
        }
        return maxSum;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxSubarraySum = function (nums, k) {
    let n = nums.length;
    let prefixSum = 0;
    let maxSum = -Number.MAX_SAFE_INTEGER;
    let kSum = Array(k).fill(Number.MAX_SAFE_INTEGER / 2);
    kSum[k - 1] = 0;
    for (let i = 0; i < n; i++) {
        prefixSum += nums[i];
        maxSum = Math.max(maxSum, prefixSum - kSum[i % k]);
        kSum[i % k] = Math.min(kSum[i % k], prefixSum);
    }
    return maxSum;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefixSum = 0
        maxSum = -sys.maxsize
        kSum = [sys.maxsize // 2] * k
        kSum[k - 1] = 0
        for i in range(n):
            prefixSum += nums[i]
            maxSum = max(maxSum, prefixSum - kSum[i % k])
            kSum[i % k] = min(kSum[i % k], prefixSum)
        return maxSum
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxSubarraySum(nums: number[], k: number): number {
    let n = nums.length;
    let prefixSum = 0;
    let maxSum = -Number.MAX_SAFE_INTEGER;
    let kSum: number[] = Array(k).fill(Number.MAX_SAFE_INTEGER / 2);
    kSum[k - 1] = 0;
    for (let i = 0; i < n; i++) {
        prefixSum += nums[i];
        maxSum = Math.max(maxSum, prefixSum - kSum[i % k]);
        kSum[i % k] = Math.min(kSum[i % k], prefixSum);
    }
    return maxSum;
}
```

</details>
