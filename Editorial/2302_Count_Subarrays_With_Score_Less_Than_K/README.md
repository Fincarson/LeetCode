# 2302. Count Subarrays With Score Less Than K

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/)  
`Array` `Binary Search` `Sliding Window` `Prefix Sum`

**Problem Link:** [LeetCode 2302 - Count Subarrays With Score Less Than K](https://leetcode.com/problems/count-subarrays-with-score-less-than-k/)

## Problem

The score of an array is defined as the product of its sum and its length.

- For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.

Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

### Example 1

```text
Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3.
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
```

### Example 2

```text
Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105
- 1 <= k <= 1015

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Subarray Product Less Than K](https://leetcode.com/problems/subarray-product-less-than-k/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2302. Count Subarrays With Score Less Than K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
long long countSubarrays(int *nums, int numsSize, long long k) {
    int n = numsSize;
    long long res = 0, total = 0;
    for (int i = 0, j = 0; j < n; j++) {
        total += nums[j];
        while (i <= j && total * (j - i + 1) >= k) {
            total -= nums[i];
            i++;
        }
        res += j - i + 1;
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
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
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
    public long CountSubarrays(int[] nums, long k) {
        int n = nums.Length;
        long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countSubarrays(nums []int, k int64) int64 {
	n := len(nums)
	res, total := int64(0), int64(0)
	for i, j := 0, 0; j < n; j++ {
		total += int64(nums[j])
		for i <= j && total*int64(j-i+1) >= k {
			total -= int64(nums[i])
			i++
		}
		res += int64(j - i + 1)
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        long res = 0, total = 0;
        for (int i = 0, j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total * (j - i + 1) >= k) {
                total -= nums[i];
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countSubarrays = function (nums, k) {
    let n = nums.length;
    let res = 0,
        total = 0;
    for (let i = 0, j = 0; j < n; j++) {
        total += nums[j];
        while (i <= j && total * (j - i + 1) >= k) {
            total -= nums[i];
            i++;
        }
        res += j - i + 1;
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        n = len(nums)
        res, total = 0, 0
        i = 0
        for j in range(n):
            total += nums[j]
            while i <= j and total * (j - i + 1) >= k:
                total -= nums[i]
                i += 1
            res += j - i + 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countSubarrays(nums: number[], k: number): number {
    let n = nums.length;
    let res = 0,
        total = 0;
    for (let i = 0, j = 0; j < n; j++) {
        total += nums[j];
        while (i <= j && total * (j - i + 1) >= k) {
            total -= nums[i];
            i++;
        }
        res += j - i + 1;
    }
    return res;
}
```

</details>
