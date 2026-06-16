# 1121. Divide Array Into Increasing Sequences

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/divide-array-into-increasing-sequences/)  
`Array` `Counting`

**Problem Link:** [LeetCode 1121 - Divide Array Into Increasing Sequences](https://leetcode.com/problems/divide-array-into-increasing-sequences/)

## Problem

Given an integer array nums sorted in non-decreasing order and an integer k, return true if this array can be divided into one or more disjoint increasing subsequences of length at least k, or false otherwise.

### Example 1

```text
Input: nums = [1,2,2,3,3,4,4], k = 3
Output: true
Explanation: The array can be divided into two subsequences [1,2,3,4] and [2,3,4] with lengths at least 3 each.
```

### Example 2

```text
Input: nums = [5,6,6,7,8], k = 3
Output: false
Explanation: There is no way to divide the array using the conditions required.
```

## Constraints

- 1 <= k <= nums.length <= 105
- 1 <= nums[i] <= 105
- nums is sorted in non-decreasing order.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1121. Divide Array Into Increasing Sequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Maximum Value | C, C++, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Maximum Value

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canDivideIntoSubsequences(int* nums, int numsSize, int k) {
    int pre = nums[0], cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        if (n == pre) {
            cnt++;
        } else {
            pre = n;
            cnt = 1;
        }
        if (cnt * k > numsSize) {
            return 0;
        }
    }
    return 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int pre = nums[0], cnt = 0;
        for (int n : nums) {
            if (n == pre)
                ++cnt;
            else {
                pre = n;
                cnt = 1;
            }
            if (cnt * k > nums.size()) return false;
        }
        return true;
    }
};
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canDivideIntoSubsequences(nums []int, k int) bool {
	if k == 1 {
		return true
	}
	pre := nums[0]
	cnt := 0
	for i := 0; i < len(nums); i++ {
		if pre == nums[i] {
			cnt++
		} else {
			if cnt*k > len(nums) {
				return false
			}
			pre = nums[i]
			cnt = 1
		}
	}
	return cnt*k <= len(nums)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canDivideIntoSubsequences(int[] nums, int k) {
        int pre = nums[0];
        int cnt = 0;
        for (int n : nums) {
            if (n == pre) {
                cnt++;
            } else {
                pre = n;
                cnt = 1;
            }
            if (cnt * k > nums.length) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canDivideIntoSubsequences = function (nums, k) {
    let pre = nums[0],
        cnt = 0;
    for (let n of nums) {
        if (n === pre) {
            cnt++;
        } else {
            pre = n;
            cnt = 1;
        }
        if (cnt * k > nums.length) {
            return false;
        }
    }
    return true;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canDivideIntoSubsequences(self, nums: List[int], k: int) -> bool:
        pre = nums[0]
        cnt = 0
        for n in nums:
            if pre == n:
                cnt += 1
            else:
                pre = n
                cnt = 1
            if cnt * k > len(nums):
                return False
        return True
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canDivideIntoSubsequences(nums: number[], k: number): boolean {
    let pre = nums[0],
        cnt = 0;
    for (let n of nums) {
        if (n === pre) {
            cnt++;
        } else {
            pre = n;
            cnt = 1;
        }
        if (cnt * k > nums.length) {
            return false;
        }
    }
    return true;
}
```

</details>
