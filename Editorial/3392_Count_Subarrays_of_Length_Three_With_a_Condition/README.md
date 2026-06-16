# 3392. Count Subarrays of Length Three With a Condition

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/)  
`Array`

**Problem Link:** [LeetCode 3392 - Count Subarrays of Length Three With a Condition](https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/)

## Problem

Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

### Example 1

### Example 2

## Constraints

- 3 <= nums.length <= 100
- -100 <= nums[i] <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3392. Count Subarrays of Length Three With a Condition

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: One-Time Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: One-Time Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int countSubarrays(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 1; i < numsSize - 1; ++i) {
        if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
            ++ans;
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
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                ++ans;
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
    public int CountSubarrays(int[] nums) {
        int n = nums.Length;
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                ++ans;
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
func countSubarrays(nums []int) int {
	n := len(nums)
	ans := 0
	for i := 1; i < n-1; i++ {
		if nums[i] == (nums[i-1]+nums[i+1])*2 {
			ans++
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

    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                ++ans;
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
var countSubarrays = function (nums) {
    const n = nums.length;
    let ans = 0;
    for (let i = 1; i < n - 1; ++i) {
        if (nums[i] === (nums[i - 1] + nums[i + 1]) * 2) {
            ++ans;
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
    def countSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        for i in range(1, n - 1):
            if nums[i] == (nums[i - 1] + nums[i + 1]) * 2:
                ans += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countSubarrays(nums: number[]): number {
    const n = nums.length;
    let ans = 0;
    for (let i = 1; i < n - 1; ++i) {
        if (nums[i] === (nums[i - 1] + nums[i + 1]) * 2) {
            ++ans;
        }
    }
    return ans;
}
```

</details>
