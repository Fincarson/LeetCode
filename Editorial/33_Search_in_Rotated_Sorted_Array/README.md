# 33. Search in Rotated Sorted Array

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/search-in-rotated-sorted-array/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 33 - Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Problem

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

### Example 1

```text
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

### Example 2

```text
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

### Example 3

```text
Input: nums = [1], target = 0
Output: -1
```

## Constraints

- 1 <= nums.length <= 5000
- -104 <= nums[i] <= 104
- All values of nums are unique.
- nums is an ascending array that is possibly rotated.
- -104 <= target <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Pour Water Between Buckets to Make Water Levels Equal](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 33. Search in Rotated Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Find Pivot Index + Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Find Pivot Index + Binary Search with Shift | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Find Pivot Index + Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int binarySearch(int* nums, int leftBoundary, int rightBoundary, int target) {
    int left = leftBoundary, right = rightBoundary;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target) {
    int n = numsSize;
    int left = 0, right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // Binary search over elements on the pivot element's left
    int answer = binarySearch(nums, 0, left - 1, target);
    if (answer != -1) {
        return answer;
    }
    // Binary search over elements on the pivot element's right
    return binarySearch(nums, left, n - 1, target);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // Binary search over elements on the pivot element's left
        int answer = binarySearch(nums, 0, left - 1, target);
        if (answer != -1) {
            return answer;
        }
        // Binary search over elements on the pivot element's right
        return binarySearch(nums, left, n - 1, target);
    }
    // Binary search over an inclusive range [left_boundary ~ right_boundary]
    int binarySearch(vector<int>& nums, int leftBoundary, int rightBoundary,
                     int target) {
        int left = leftBoundary, right = rightBoundary;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
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
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Binary search over elements on the pivot element's left
        int answer = BinarySearch(nums, 0, left - 1, target);
        if (answer != -1) {
            return answer;
        }

        // Binary search over elements on the pivot element's right
        return BinarySearch(nums, left, n - 1, target);
    }

    // Binary search over an inclusive range [left_boundary ~ right_boundary]
    private int BinarySearch(int[] nums, int left_boundary, int right_boundary,
                             int target) {
        int left = left_boundary, right = right_boundary;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func search(nums []int, target int) int {
    n := len(nums)
    left, right := 0, n-1
    // Find the index of the pivot element (the smallest element)
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] > nums[n-1] {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    binarySearch := func(left_boundary int, right_boundary int, target int) int {
        left, right := left_boundary, right_boundary
        for left <= right {
            mid := (left + right) / 2
            if nums[mid] == target {
                return mid
            } else if nums[mid] > target {
                right = mid - 1
            } else {
                left = mid + 1
            }
        }
        return -1
    }
    // Binary search over elements on the pivot element's left
    if answer := binarySearch(0, left-1, target); answer != -1 {
        return answer
    }
    // Binary search over elements on the pivot element's right
    return binarySearch(left, n-1, target)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;

        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Binary search over elements on the pivot element's left
        int answer = binarySearch(nums, 0, left - 1, target);
        if (answer != -1) {
            return answer;
        }

        // Binary search over elements on the pivot element's right
        return binarySearch(nums, left, n - 1, target);
    }

    // Binary search over an inclusive range [left_boundary ~ right_boundary]
    private int binarySearch(
        int[] nums,
        int leftBoundary,
        int rightBoundary,
        int target
    ) {
        int left = leftBoundary, right = rightBoundary;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var search = function (nums, target) {
    let n = nums.length;
    let left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    function binarySearch(left_boundary, right_boundary, target) {
        let left = left_boundary,
            right = right_boundary;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    // Binary search over elements on the pivot element's left
    let answer = binarySearch(0, left - 1, target);
    if (answer != -1) {
        return answer;
    }
    // Binary search over elements on the pivot element's right
    return binarySearch(left, n - 1, target);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1

        # Find the index of the pivot element (the smallest element)
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1

        # Binary search over an inclusive range [left_boundary ~ right_boundary]
        def binarySearch(left_boundary, right_boundary, target):
            left, right = left_boundary, right_boundary
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            return -1

        # Binary search over elements on the pivot element's left
        if (answer := binarySearch(0, left - 1, target)) != -1:
            return answer

        # Binary search over elements on the pivot element's right
        return binarySearch(left, n - 1, target)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function search(nums: number[], target: number): number {
    let n = nums.length;
    let left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    function binarySearch(
        left_boundary: number,
        right_boundary: number,
        target: number,
    ): number {
        let left = left_boundary,
            right = right_boundary;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
    // Binary search over elements on the pivot element's left
    let answer = binarySearch(0, left - 1, target);
    if (answer != -1) {
        return answer;
    }
    // Binary search over elements on the pivot element's right
    return binarySearch(left, n - 1, target);
}
```

</details>

<br>

## Approach 2: Find Pivot Index + Binary Search with Shift

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[numsSize - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, numsSize, left, target);
}
// Shift elements in a circular manner, with the pivot element at index 0.
// Then perform a regular binary search
int shiftedBinarySearch(int* nums, int numsSize, int pivot, int target) {
    int shift = numsSize - pivot;
    int left = (pivot + shift) % numsSize;
    int right = (pivot - 1 + shift) % numsSize;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[(mid - shift + numsSize) % numsSize] == target) {
            return (mid - shift + numsSize) % numsSize;
        } else if (nums[(mid - shift + numsSize) % numsSize] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return shiftedBinarySearch(nums, left, target);
    }
    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    int shiftedBinarySearch(vector<int>& nums, int pivot, int target) {
        int n = nums.size();
        int shift = n - pivot;
        int left = (pivot + shift) % n;
        int right = (pivot - 1 + shift) % n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
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
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ShiftedBinarySearch(nums, left, target);
    }

    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    private int ShiftedBinarySearch(int[] nums, int pivot, int target) {
        int n = nums.Length;
        int shift = n - pivot;
        int left = (pivot + shift) % n;
        int right = (pivot - 1 + shift) % n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func search(nums []int, target int) int {
    n := len(nums)
    left, right := 0, n-1
    // Find the index of the pivot element (the smallest element)
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] > nums[n-1] {
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    return shiftedBinarySearch(nums, left, target)
}

// Shift elements in a circular manner, with the pivot element at index 0.
// Then perform a regular binary search
func shiftedBinarySearch(nums []int, pivot int, target int) int {
    n := len(nums)
    shift := n - pivot
    left := (pivot + shift) % n
    right := (pivot - 1 + shift) % n
    for left <= right {
        mid := (left + right) / 2
        if nums[(mid-shift+n)%n] == target {
            return (mid - shift + n) % n
        } else if nums[(mid-shift+n)%n] > target {
            right = mid - 1
        } else {
            left = mid + 1
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
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;

        // Find the index of the pivot element (the smallest element)
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[n - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return shiftedBinarySearch(nums, left, target);
    }

    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    private int shiftedBinarySearch(int[] nums, int pivot, int target) {
        int n = nums.length;
        int shift = n - pivot;
        int left = (pivot + shift) % n;
        int right = (pivot - 1 + shift) % n;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var search = function (nums, target) {
    var n = nums.length;
    var left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        var mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, left, target);
    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    function shiftedBinarySearch(nums, pivot, target) {
        var n = nums.length;
        var shift = n - pivot;
        var left = (pivot + shift) % n;
        var right = (pivot - 1 + shift) % n;
        while (left <= right) {
            var mid = Math.floor((left + right) / 2);
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1

        # Find the index of the pivot element (the smallest element)
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] > nums[-1]:
                left = mid + 1
            else:
                right = mid - 1

        # Shift elements in circular manner, with the pivot element at index 0.
        # Then perform a regular binary search
        def shiftedBinarySearch(pivot_index, target):
            shift = n - pivot_index
            left, right = (pivot_index + shift) % n, (
                pivot_index - 1 + shift
            ) % n

            while left <= right:
                mid = (left + right) // 2
                if nums[(mid - shift) % n] == target:
                    return (mid - shift) % n
                elif nums[(mid - shift) % n] > target:
                    right = mid - 1
                else:
                    left = mid + 1
            return -1

        return shiftedBinarySearch(left, target)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function search(nums: number[], target: number): number {
    let n = nums.length;
    let left = 0,
        right = n - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] > nums[n - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, left, target);
    // Shift elements in a circular manner, with the pivot element at index 0.
    // Then perform a regular binary search
    function shiftedBinarySearch(
        nums: number[],
        pivot: number,
        target: number,
    ): number {
        let n = nums.length;
        let shift = n - pivot;
        let left = (pivot + shift) % n;
        let right = (pivot - 1 + shift) % n;
        while (left <= right) {
            let mid = Math.floor((left + right) / 2);
            if (nums[(mid - shift + n) % n] == target) {
                return (mid - shift + n) % n;
            } else if (nums[(mid - shift + n) % n] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
}
```

</details>

<br>

## Approach 3: One Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        // Case 1: find target
        if (nums[mid] == target) return mid;
        // Case 2: Subarray on mid's left is sorted
        else if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        // Case 3: Subarray on mid's right is sorted
        else {
            if (target <= nums[right] && target > nums[mid])
                left = mid + 1;
            else
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
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Case 1: Find target
            if (nums[mid] == target) {
                return mid;
            }
            // Case 2: Subarray on mid's left is sorted
            else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Case 3: Subarray on mid's right is sorted
            else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
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
    public int Search(int[] nums, int target) {
        int n = nums.Length;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Case 1: find target
            if (nums[mid] == target) {
                return mid;
            }
            // Case 2: subarray on mid's left is sorted
            else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Case 3: subarray on mid's right is sorted
            else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func search(nums []int, target int) int {
    n := len(nums)
    left, right := 0, n-1
    for left <= right {
        mid := left + (right-left)/2
        // Case 1: find target
        if nums[mid] == target {
            return mid
        }
        // Case 2: subarray on mid's left is sorted
        if nums[mid] >= nums[left] {
            if target >= nums[left] && target < nums[mid] {
                right = mid - 1
            } else {
                left = mid + 1
            }
        } else {
            // Case 3: subarray on mid's right is sorted
            if nums[mid] <= nums[right] {
                if target <= nums[right] && target > nums[mid] {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
            }
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
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Case 1: find target
            if (nums[mid] == target) {
                return mid;
            }
            // Case 2: subarray on mid's left is sorted
            else if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Case 3: subarray on mid's right is sorted
            else {
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var search = function (nums, target) {
    let n = nums.length;
    let left = 0,
        right = n - 1;
    while (left <= right) {
        let mid = left + (((right - left) / 2) | 0);
        // Case 1: find target
        if (nums[mid] == target) return mid;
        // Case 2: Subarray on mid's left is sorted
        else if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        // Case 3: Subarray on mid's right is sorted
        else {
            if (target <= nums[right] && target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left, right = 0, n - 1
        while left <= right:
            mid = left + (right - left) // 2

            # Case 1: find target
            if nums[mid] == target:
                return mid

            # Case 2: subarray on mid's left is sorted
            elif nums[mid] >= nums[left]:
                if target >= nums[left] and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            # Case 3: subarray on mid's right is sorted.
            else:
                if target <= nums[right] and target > nums[mid]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function search(nums: number[], target: number): number {
    let n: number = nums.length;
    let left: number = 0,
        right: number = n - 1;
    while (left <= right) {
        let mid: number = left + (((right - left) / 2) | 0);
        // Case 1: find target
        if (nums[mid] == target) return mid;
        // Case 2: Subarray on mid's left is sorted
        else if (nums[mid] >= nums[left]) {
            if (target >= nums[left] && target < nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        // Case 3: Subarray on mid's right is sorted
        else {
            if (target <= nums[right] && target > nums[mid]) left = mid + 1;
            else right = mid - 1;
        }
    }
    return -1;
}
```

</details>
