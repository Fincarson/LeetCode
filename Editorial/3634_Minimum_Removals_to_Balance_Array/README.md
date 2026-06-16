# 3634. Minimum Removals to Balance Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-removals-to-balance-array/)  
`Array` `Binary Search` `Sliding Window` `Sorting`

**Problem Link:** [LeetCode 3634 - Minimum Removals to Balance Array](https://leetcode.com/problems/minimum-removals-to-balance-array/)

## Problem

You are given an integer array nums and an integer k.

An array is considered balanced if the value of its maximum element is at most k times the minimum element.

You may remove any number of elements from nums​​​​​​​ without making it empty.

Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 109
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

# Editorial - 3634. Minimum Removals to Balance Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sorting + Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Sorting + Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int ans = numsSize;
    int right = 0;

    for (int left = 0; left < numsSize; left++) {
        while (right < numsSize &&
               (long long)nums[right] <= (long long)nums[left] * k) {
            right++;
        }
        int current = numsSize - (right - left);
        if (current < ans) {
            ans = current;
        }
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
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = n, right = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n &&
                   nums[right] <= static_cast<long long>(nums[left]) * k) {
                ++right;
            }
            ans = min(ans, n - (right - left));
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
    public int MinRemoval(int[] nums, int k) {
        int n = nums.Length;
        Array.Sort(nums);

        int ans = n;
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= (long)nums[left] * k) {
                right++;
            }
            ans = Math.Min(ans, n - (right - left));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minRemoval(nums []int, k int) int {
	n := len(nums)
	sort.Ints(nums)

	ans := n
	right := 0

	for left := 0; left < n; left++ {
		for right < n && int64(nums[right]) <= int64(nums[left])*int64(k) {
			right++
		}
		current := n - (right - left)
		if current < ans {
			ans = current
		}
	}

	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);

        int ans = n;
        int right = 0;

        for (int left = 0; left < n; left++) {
            while (right < n && nums[right] <= (long) nums[left] * k) {
                right++;
            }
            ans = Math.min(ans, n - (right - left));
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minRemoval = function (nums, k) {
    const n = nums.length;
    nums.sort((a, b) => a - b);

    let ans = n;
    let right = 0;

    for (let left = 0; left < n; left++) {
        while (right < n && nums[right] <= nums[left] * k) {
            right++;
        }
        ans = Math.min(ans, n - (right - left));
    }

    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minRemoval(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        ans = n
        right = 0
        for left in range(n):
            while right < n and nums[right] <= nums[left] * k:
                right += 1
            ans = min(ans, n - (right - left))

        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minRemoval(nums: number[], k: number): number {
    const n = nums.length;
    nums.sort((a, b) => a - b);

    let ans = n;
    let right = 0;
    for (let left = 0; left < n; left++) {
        while (right < n && nums[right] <= nums[left] * k) {
            right++;
        }
        ans = Math.min(ans, n - (right - left));
    }

    return ans;
}
```

</details>
