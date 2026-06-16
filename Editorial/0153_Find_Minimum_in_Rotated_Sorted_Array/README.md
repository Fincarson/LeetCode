# 153. Find Minimum in Rotated Sorted Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 153 - Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

## Problem

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

### Example 1

```text
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
```

### Example 2

```text
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
```

### Example 3

```text
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times.
```

## Constraints

- n == nums.length
- 1 <= n <= 5000
- -5000 <= nums[i] <= 5000
- All the integers of nums are unique.
- nums is sorted and rotated between 1 and n times.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 153. Find Minimum in Rotated Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findMin(int* nums, int numsSize) {
    // If the list has just one element then return that element.
    if (numsSize == 1) {
        return nums[0];
    }

    // Initializing left and right pointers.
    int left = 0, right = numsSize - 1;

    // If the last element is greater than the first element then there is no
    // rotation. E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array. Hence the
    // smallest element is first element. A[0]
    if (nums[right] > nums[0]) {
        return nums[0];
    }

    // Binary search way
    while (right >= left) {
        // Find the mid element
        int mid = left + (right - left) / 2;

        // If the mid element is greater than its next element then mid+1
        // element is the smallest This point would be the point of change. From
        // higher to lower value.
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        // If the mid element is lesser than its previous element then mid
        // element is the smallest
        if (mid > 0 && nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }

        // If the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still
        // dealing with elements greater than nums[0]
        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            // If nums[0] is greater than the mid value then this means the
            // smallest value is somewhere to the left
            right = mid - 1;
        }
    }

    return -1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        // If the list has just one element then return that element.
        if (nums.size() == 1) {
            return nums[0];
        }

        // Initializing left and right pointers.
        int left = 0, right = nums.size() - 1;

        // If the last element is greater than the first element then there is
        // no rotation. E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array. Hence
        // the smallest element is first element. A[0]
        if (nums[right] > nums[0]) {
            return nums[0];
        }

        // Binary search way
        while (right >= left) {
            // Find the mid element
            int mid = left + (right - left) / 2;

            // If the mid element is greater than its next element then mid+1
            // element is the smallest This point would be the point of change.
            // From higher to lower value.
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // If the mid element is lesser than its previous element then mid
            // element is the smallest
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // If the mid elements value is greater than the 0th element this
            // means the least value is still somewhere to the right as we are
            // still dealing with elements greater than nums[0]
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                // If nums[0] is greater than the mid value then this means the
                // smallest value is somewhere to the left
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindMin(int[] nums) {
        // If the list has just one element then return that element.
        if (nums.Length == 1) {
            return nums[0];
        }

        // Initializing left and right pointers.
        int left = 0, right = nums.Length - 1;

        // If the last element is greater than the first element then there is no rotation.
        // E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        // Hence the smallest element is first element. A[0]
        if (nums[right] > nums[0]) {
            return nums[0];
        }

        // Binary search way
        while (right >= left) {
            // Find the mid element
            int mid = left + (right - left) / 2;

            // If the mid element is greater than its next element then mid+1 element is the smallest
            // This point would be the point of change. From higher to lower value.
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // If the mid element is lesser than its previous element then mid element is the smallest
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // If the mid elements value is greater than the 0th element this means
            // the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                // If nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
                right = mid - 1;
            }
        }

        return Int32.MaxValue;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findMin(nums []int) int {
    // If the list has just one element then return that element.
    if len(nums) == 1 {
        return nums[0]
    }

    // Initializing left and right pointers.
    left := 0
    right := len(nums) - 1

    // If the last element is greater than the first element then there is no rotation.
    // E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
    // Hence the smallest element is first element. A[0]
    if nums[right] > nums[0] {
        return nums[0]
    }

    // Binary search way
    for right >= left {
        // Find the mid element
        mid := left + (right-left)/2

        // If the mid element is greater than its next element then mid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        if nums[mid] > nums[mid+1] {
            return nums[mid+1]
        }

        // If the mid element is lesser than its previous element then mid element is the smallest
        if mid > 0 && nums[mid-1] > nums[mid] {
            return nums[mid]
        }

        // If the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
        if nums[mid] > nums[0] {
            left = mid + 1
        } else {
            // If nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            right = mid - 1
        }
    }

    return -1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findMin(int[] nums) {
        // If the list has just one element then return that element.
        if (nums.length == 1) {
            return nums[0];
        }

        // initializing left and right pointers.
        int left = 0, right = nums.length - 1;

        // if the last element is greater than the first element then there is no
        // rotation.
        // e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        // Hence the smallest element is first element. A[0]
        if (nums[right] > nums[0]) {
            return nums[0];
        }

        // Binary search way
        while (right >= left) {
            // Find the mid element
            int mid = left + (right - left) / 2;

            // if the mid element is greater than its next element then mid+1 element is the
            // smallest
            // This point would be the point of change. From higher to lower value.
            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            // if the mid element is lesser than its previous element then mid element is
            // the smallest
            if (nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }

            // if the mid elements value is greater than the 0th element this means
            // the least value is still somewhere to the right as we are still dealing with
            // elements
            // greater than nums[0]
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                // if nums[0] is greater than the mid value then this means the smallest value
                // is somewhere to
                // the left
                right = mid - 1;
            }
        }
        return Integer.MAX_VALUE;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findMin = function (nums) {
    // If the list has just one element then return that element.
    if (nums.length == 1) {
        return nums[0];
    }

    // initializing left and right pointers.
    let left = 0,
        right = nums.length - 1;

    // if the last element is greater than the first element then there is no rotation.
    // e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
    // Hence the smallest element is first element. A[0]
    if (nums[right] > nums[0]) {
        return nums[0];
    }

    // Binary search way
    while (right >= left) {
        // Find the mid element
        let mid = left + Math.floor((right - left) / 2);

        // if the mid element is greater than its next element then mid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        // if the mid element is lesser than its previous element then mid element is the smallest
        if (nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }

        // if the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with
        // elements greater than nums[0]
        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            // if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            right = mid - 1;
        }
    }

    return Number.MAX_VALUE;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        # If the list has just one element then return that element.
        if len(nums) == 1:
            return nums[0]

        # left pointer
        left = 0
        # right pointer
        right = len(nums) - 1

        # if the last element is greater than the first element then there is no rotation.
        # e.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
        # Hence the smallest element is first element. A[0]
        if nums[right] > nums[0]:
            return nums[0]

        # Binary search way
        while right >= left:
            # Find the mid element
            mid = left + (right - left) // 2
            # if the mid element is greater than its next element then mid+1 element is the smallest
            # This point would be the point of change. From higher to lower value.
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            # if the mid element is lesser than its previous element then mid element is the smallest
            if nums[mid - 1] > nums[mid]:
                return nums[mid]

            # if the mid elements value is greater than the 0th element this means
            # the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
            if nums[mid] > nums[0]:
                left = mid + 1
            # if nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            else:
                right = mid - 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findMin(nums: number[]): number {
    // If the list has just one element then return that element.
    if (nums.length == 1) {
        return nums[0];
    }

    // Initializing left and right pointers.
    let left = 0,
        right = nums.length - 1;

    // If the last element is greater than the first element then there is no rotation.
    // E.g. 1 < 2 < 3 < 4 < 5 < 7. Already sorted array.
    // Hence the smallest element is first element. A[0]
    if (nums[right] > nums[0]) {
        return nums[0];
    }

    // Binary search way
    while (right >= left) {
        // Find the mid element
        let mid = left + Math.floor((right - left) / 2);

        // If the mid element is greater than its next element then mid+1 element is the smallest
        // This point would be the point of change. From higher to lower value.
        if (nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        }

        // If the mid element is lesser than its previous element then mid element is the smallest
        if (nums[mid - 1] > nums[mid]) {
            return nums[mid];
        }

        // If the mid elements value is greater than the 0th element this means
        // the least value is still somewhere to the right as we are still dealing with elements greater than nums[0]
        if (nums[mid] > nums[0]) {
            left = mid + 1;
        } else {
            // If nums[0] is greater than the mid value then this means the smallest value is somewhere to the left
            right = mid - 1;
        }
    }

    return Number.MAX_VALUE;
}
```

</details>
