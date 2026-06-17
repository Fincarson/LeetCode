# 154. Find Minimum in Rotated Sorted Array II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 154 - Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

## Problem

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

- [4,5,6,7,0,1,4] if it was rotated 4 times.
- [0,1,4,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

### Example 1

```text
Input: nums = [1,3,5]
Output: 1
```

### Example 2

```text
Input: nums = [2,2,2,0,1]
Output: 0
```

## Constraints

- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- nums is sorted and rotated between 1 and n times.

Follow up: This problem is similar to Find Minimum in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 154. Find Minimum in Rotated Sorted Array II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Variant of Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Variant of Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize - 1;

    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high])
            high = pivot;
        else if (nums[pivot] > nums[high])
            low = pivot + 1;
        else
            high -= 1;
    }
    return nums[low];
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
                high = pivot;
            else if (nums[pivot] > nums[high])
                low = pivot + 1;
            else
                high -= 1;
        }
        return nums[low];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindMin(int[] nums) {
        int low = 0, high = nums.Length - 1;

        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high])
                high = pivot;
            else if (nums[pivot] > nums[high])
                low = pivot + 1;
            else
                high -= 1;
        }

        return nums[low];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findMin(nums []int) int {
    low, high := 0, len(nums)-1

    for low < high {
        pivot := low + (high-low)/2
        if nums[pivot] < nums[high] {
            high = pivot
        } else if nums[pivot] > nums[high] {
            low = pivot + 1
        } else {
            high -= 1
        }
    }
    return nums[low]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMin(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) high = pivot;
            else if (nums[pivot] > nums[high]) low = pivot + 1;
            else high -= 1;
        }
        return nums[low];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMin = function (nums) {
    let low = 0,
        high = nums.length - 1;

    while (low < high) {
        let pivot = low + Math.floor((high - low) / 2);
        if (nums[pivot] < nums[high]) high = pivot;
        else if (nums[pivot] > nums[high]) low = pivot + 1;
        else high -= 1;
    }
    return nums[low];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while high > low:
            pivot = low + (high - low) // 2
            # risk of overflow: pivot = (low + high) // 2
            # Case 1):
            if nums[pivot] < nums[high]:
                high = pivot
                # alternative: high = pivot - 1
                # too aggressive to move the `high` index,
                # it won't work for the test case of [3, 1, 3]
            # Case 2):
            elif nums[pivot] > nums[high]:
                low = pivot + 1
            # Case 3):
            else:
                high -= 1
        # the 'low' and 'high' index converge to the inflection point.
        return nums[low]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMin(nums: number[]): number {
    let low = 0,
        high = nums.length - 1;

    while (low < high) {
        let pivot = low + Math.floor((high - low) / 2);
        if (nums[pivot] < nums[high]) high = pivot;
        else if (nums[pivot] > nums[high]) low = pivot + 1;
        else high -= 1;
    }
    return nums[low];
}
```

</details>
