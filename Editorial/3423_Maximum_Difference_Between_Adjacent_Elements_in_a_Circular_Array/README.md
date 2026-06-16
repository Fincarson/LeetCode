# 3423. Maximum Difference Between Adjacent Elements in a Circular Array

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/)  
`Array`

**Problem Link:** [LeetCode 3423 - Maximum Difference Between Adjacent Elements in a Circular Array](https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/)

## Problem

Given a circular array nums, find the maximum absolute difference between adjacent elements.

Note: In a circular array, the first and last elements are adjacent.

### Example 1

### Example 2

## Constraints

- 2 <= nums.length <= 100
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

# Editorial - 3423. Maximum Difference Between Adjacent Elements in a Circular Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traversal | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traversal

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxAdjacentDistance(int* nums, int numsSize) {
    int res = abs(nums[0] - nums[numsSize - 1]);
    for (int i = 0; i < numsSize - 1; ++i) {
        res = fmax(res, abs(nums[i] - nums[i + 1]));
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
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int res = abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, abs(nums[i] - nums[i + 1]));
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
    public int MaxAdjacentDistance(int[] nums) {
        int n = nums.Length;
        int res = Math.Abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            res = Math.Max(res, Math.Abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxAdjacentDistance(nums []int) int {
	n := len(nums)
	res := int(math.Abs(float64(nums[0] - nums[n-1])))
	for i := 0; i < n-1; i++ {
		res = int(math.Max(float64(res), math.Abs(float64(nums[i]-nums[i+1]))))
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxAdjacentDistance(int[] nums) {
        int n = nums.length;
        int res = Math.abs(nums[0] - nums[n - 1]);
        for (int i = 0; i < n - 1; ++i) {
            res = Math.max(res, Math.abs(nums[i] - nums[i + 1]));
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxAdjacentDistance = function (nums) {
    const n = nums.length;
    let res = Math.abs(nums[0] - nums[n - 1]);
    for (let i = 0; i < n - 1; i++) {
        res = Math.max(res, Math.abs(nums[i] - nums[i + 1]));
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        res = abs(nums[0] - nums[n - 1])
        for i in range(n - 1):
            res = max(res, abs(nums[i] - nums[i + 1]))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxAdjacentDistance(nums: number[]): number {
    const n = nums.length;
    let res = Math.abs(nums[0] - nums[n - 1]);
    for (let i = 0; i < n - 1; i++) {
        res = Math.max(res, Math.abs(nums[i] - nums[i + 1]));
    }
    return res;
}
```

</details>
