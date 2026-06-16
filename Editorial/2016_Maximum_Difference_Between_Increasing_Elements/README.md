# 2016. Maximum Difference Between Increasing Elements

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)  
`Array`

**Problem Link:** [LeetCode 2016 - Maximum Difference Between Increasing Elements](https://leetcode.com/problems/maximum-difference-between-increasing-elements/)

## Problem

Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

### Example 1

```text
Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
```

### Example 2

```text
Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
```

### Example 3

```text
Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.
```

## Constraints

- n == nums.length
- 2 <= n <= 1000
- 1 <= nums[i] <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Two Furthest Houses With Different Colors](https://leetcode.com/problems/two-furthest-houses-with-different-colors/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2016. Maximum Difference Between Increasing Elements

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Prefix Minimum Value | C, C++, C#, Go, Java, JavaScript, Python3 |

## Approach: Prefix Minimum Value

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumDifference(int* nums, int numsSize) {
    int ans = -1, premin = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > premin) {
            ans = MAX(ans, nums[i] - premin);
        } else {
            premin = nums[i];
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
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
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
    public int MaximumDifference(int[] nums) {
        int n = nums.Length;
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = Math.Max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maximumDifference(nums []int) int {
	ans := -1
	for i, preMin := 1, nums[0]; i < len(nums); i++ {
		if nums[i] > preMin {
			ans = max(ans, nums[i]-preMin)
		} else {
			preMin = nums[i]
		}
	}
	return ans
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maximumDifference(int[] nums) {
        int n = nums.length;
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = Math.max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maximumDifference = function (nums) {
    const n = nums.length;
    let ans = -1,
        premin = nums[0];
    for (let i = 1; i < n; ++i) {
        if (nums[i] > premin) {
            ans = Math.max(ans, nums[i] - premin);
        } else {
            premin = nums[i];
        }
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        n = len(nums)
        ans, premin = -1, nums[0]

        for i in range(1, n):
            if nums[i] > premin:
                ans = max(ans, nums[i] - premin)
            else:
                premin = nums[i]

        return ans
```

</details>
