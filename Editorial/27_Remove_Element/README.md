# 27. Remove Element

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/remove-element/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 27 - Remove Element](https://leetcode.com/problems/remove-element/)

## Problem

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

Custom Judge:

The judge will test your solution with the following code:

```text
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

If all assertions pass, then your solution will be accepted.

### Example 1

```text
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### Example 2

```text
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

## Constraints

- 0 <= nums.length <= 100
- 0 <= nums[i] <= 50
- 0 <= val <= 100

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 27. Remove Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Pointers - when elements to remove are rare | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
// C
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.Length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func removeElement(nums []int, val int) int {
    i := 0
    for j := 0; j < len(nums); j++ {
        if nums[j] != val {
            nums[i] = nums[j]
            i++
        }
    }
    return i
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
// JavaScript
var removeElement = function (nums, val) {
    var i = 0;
    for (var j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# Python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i += 1
        return i
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
// TypeScript
function removeElement(nums: number[], val: number): number {
    let i = 0;
    for (let j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
```

</details>

<br>

## Approach 2: Two Pointers - when elements to remove are rare

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;
    int n = numsSize;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int i = 0;
        int n = nums.Length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }

        return n;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func removeElement(nums []int, val int) int {
    i := 0
    n := len(nums)
    for i < n {
        if nums[i] == val {
            nums[i] = nums[n-1]
            // reduce array size by one
            n--
        } else {
            i++
        }
    }
    return n
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int n = nums.length;
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var removeElement = function (nums, val) {
    let i = 0;
    let n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        n = len(nums)
        while i < n:
            if nums[i] == val:
                nums[i] = nums[n - 1]
                n -= 1
            else:
                i += 1
        return n
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function removeElement(nums: number[], val: number): number {
    let i = 0;
    let n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}
```

</details>
