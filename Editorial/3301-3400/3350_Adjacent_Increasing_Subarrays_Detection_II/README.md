# 3350. Adjacent Increasing Subarrays Detection II

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 3350 - Adjacent Increasing Subarrays Detection II](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/)

## Problem

Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent subarrays of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:

- Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
- The subarrays must be adjacent, meaning b = a + k.

Return the maximum possible value of k.

A subarray is a contiguous non-empty sequence of elements within an array.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 2 * 105
- -109 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3350. Adjacent Increasing Subarrays Detection II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxIncreasingSubarrays(int* nums, int numsSize) {
    int cnt = 1, precnt = 0, ans = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        int min_val = precnt < cnt ? precnt : cnt;
        ans = ans > min_val ? ans : min_val;
        ans = ans > cnt / 2 ? ans : cnt / 2;
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
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
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
    public int MaxIncreasingSubarrays(IList<int> nums) {
        int n = nums.Count;
        int cnt = 1, precnt = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = Math.Max(ans, Math.Min(precnt, cnt));
            ans = Math.Max(ans, cnt / 2);
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxIncreasingSubarrays(nums []int) int {
	n := len(nums)
	cnt, precnt, ans := 1, 0, 0
	for i := 1; i < n; i++ {
		if nums[i] > nums[i-1] {
			cnt++
		} else {
			precnt = cnt
			cnt = 1
		}
		ans = max(ans, min(precnt, cnt))
		ans = max(ans, cnt/2)
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxIncreasingSubarrays(List<Integer> nums) {
        int n = nums.size();
        int cnt = 1;
        int precnt = 0;
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (nums.get(i) > nums.get(i - 1)) {
                ++cnt;
            } else {
                precnt = cnt;
                cnt = 1;
            }
            ans = Math.max(ans, Math.min(precnt, cnt));
            ans = Math.max(ans, cnt / 2);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxIncreasingSubarrays = function (nums) {
    const n = nums.length;
    let cnt = 1,
        precnt = 0,
        ans = 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        ans = Math.max(ans, Math.min(precnt, cnt));
        ans = Math.max(ans, Math.floor(cnt / 2));
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        cnt, precnt, ans = 1, 0, 0
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                cnt += 1
            else:
                precnt, cnt = cnt, 1
            ans = max(ans, min(precnt, cnt))
            ans = max(ans, cnt // 2)
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxIncreasingSubarrays(nums: number[]): number {
    const n = nums.length;
    let cnt = 1,
        precnt = 0,
        ans = 0;
    for (let i = 1; i < n; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        ans = Math.max(ans, Math.min(precnt, cnt));
        ans = Math.max(ans, Math.floor(cnt / 2));
    }
    return ans;
}
```

</details>
