# 3689. Maximum Total Subarray Value I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/maximum-total-subarray-value-i/)  
`Array` `Greedy`

**Problem Link:** [LeetCode 3689 - Maximum Total Subarray Value I](https://leetcode.com/problems/maximum-total-subarray-value-i/)

## Problem

You are given an integer array nums of length n and an integer k.

You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact same subarray (same l and r) can be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.

### Example 1

### Example 2

## Constraints

- 1 <= n == nums.length <= 5 * 10​​​​​​​4
- 0 <= nums[i] <= 109
- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3689. Maximum Total Subarray Value I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long maxTotalValue(int* nums, int numsSize, int k) {
    int m1 = INT_MAX, m2 = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        m1 = fmin(m1, nums[i]);
        m2 = fmax(m2, nums[i]);
    }
    return (long long)(m2 - m1) * k;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m1 = INT_MAX, m2 = INT_MIN;
        for (int x : nums) {
            m1 = min(m1, x);
            m2 = max(m2, x);
        }
        return (long long)(m2 - m1) * k;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public long MaxTotalValue(int[] nums, int k) {
        int m1 = int.MaxValue, m2 = int.MinValue;
        foreach (int x in nums) {
            m1 = Math.Min(m1, x);
            m2 = Math.Max(m2, x);
        }
        return (long)(m2 - m1) * k;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxTotalValue(nums []int, k int) int64 {
	m1, m2 := math.MaxInt, math.MinInt
	for _, x := range nums {
		m1 = min(m1, x)
		m2 = max(m2, x)
	}
	return int64(m2-m1) * int64(k)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long maxTotalValue(int[] nums, int k) {
        int m1 = Integer.MAX_VALUE;
        int m2 = Integer.MIN_VALUE;
        for (int x : nums) {
            m1 = Math.min(m1, x);
            m2 = Math.max(m2, x);
        }
        return (long) (m2 - m1) * k;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxTotalValue = function (nums, k) {
    let m1 = Infinity,
        m2 = -Infinity;
    for (const x of nums) {
        m1 = Math.min(m1, x);
        m2 = Math.max(m2, x);
    }
    return (m2 - m1) * k;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        m1 = min(nums)
        m2 = max(nums)
        return (m2 - m1) * k
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxTotalValue(nums: number[], k: number): number {
    let m1 = Infinity,
        m2 = -Infinity;
    for (const x of nums) {
        m1 = Math.min(m1, x);
        m2 = Math.max(m2, x);
    }
    return (m2 - m1) * k;
}
```

</details>
