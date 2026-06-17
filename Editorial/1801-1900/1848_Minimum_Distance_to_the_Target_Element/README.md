# 1848. Minimum Distance to the Target Element

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/minimum-distance-to-the-target-element/)  
`Array`

**Problem Link:** [LeetCode 1848 - Minimum Distance to the Target Element](https://leetcode.com/problems/minimum-distance-to-the-target-element/)

## Problem

Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.

### Example 1

```text
Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
```

### Example 2

```text
Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
```

### Example 3

```text
Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
```

## Constraints

- 1 <= nums.length <= 1000
- 1 <= nums[i] <= 104
- 0 <= start < nums.length
- target is in nums.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1848. Minimum Distance to the Target Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int getMinDistance(int* nums, int numsSize, int target, int start) {
    int res = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            res = fmin(res, abs(i - start));
        }
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
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                res = min(res, abs(i - start));
            }
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
    public int GetMinDistance(int[] nums, int target, int start) {
        int res = nums.Length;
        for (int i = 0; i < nums.Length; i++) {
            if (nums[i] == target) {
                res = Math.Min(res, Math.Abs(i - start));
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func getMinDistance(nums []int, target int, start int) int {
	res := len(nums)
	for i, num := range nums {
		if num == target {
			distance := int(math.Abs(float64(i - start)))
			res = min(res, distance)
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int getMinDistance(int[] nums, int target, int start) {
        int res = nums.length;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                res = Math.min(res, Math.abs(i - start));
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var getMinDistance = function (nums, target, start) {
    let res = nums.length;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) {
            res = Math.min(res, Math.abs(i - start));
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        res = len(nums)
        for i, num in enumerate(nums):
            if num == target:
                res = min(res, abs(i - start))
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function getMinDistance(nums: number[], target: number, start: number): number {
    let res = nums.length;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === target) {
            res = Math.min(res, Math.abs(i - start));
        }
    }
    return res;
}
```

</details>
