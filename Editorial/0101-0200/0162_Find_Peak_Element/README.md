# 162. Find Peak Element

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-peak-element/)  
`Array` `Binary Search`

**Problem Link:** [LeetCode 162 - Find Peak Element](https://leetcode.com/problems/find-peak-element/)

## Problem

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -Ã¢Ë†Å¾. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

### Example 1

```text
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```

### Example 2

```text
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

## Constraints

- 1 <= nums.length <= 1000
- -231 <= nums[i] <= 231 - 1
- nums[i] != nums[i + 1] for all valid i.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Find a Peak Element II](https://leetcode.com/problems/find-a-peak-element-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Pour Water Between Buckets to Make Water Levels Equal](https://leetcode.com/problems/pour-water-between-buckets-to-make-water-levels-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Hills and Valleys in an Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Peaks](https://leetcode.com/problems/find-the-peaks/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 162. Find Peak Element

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Scan | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Recursive Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Iterative Binary Search | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Linear Scan

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findPeakElement(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return numsSize - 1;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return nums.size() - 1;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindPeakElement(int[] nums) {
        for (int i = 0; i < nums.Length - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }

        return nums.Length - 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findPeakElement(nums []int) int {
    for i := 0; i < len(nums)-1; i++ {
        if nums[i] > nums[i+1] {
            return i
        }
    }
    return len(nums) - 1
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findPeakElement(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) return i;
        }
        return nums.length - 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findPeakElement = function (nums) {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return nums.length - 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findPeakElement(self, nums):
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                return i
        return len(nums) - 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findPeakElement(nums: number[]): number {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return nums.length - 1;
}
```

</details>

<br>

## Approach 2: Recursive Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int search(int* nums, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
    return search(nums, mid + 1, r);
}

int findPeakElement(int* nums, int numsSize) {
    return search(nums, 0, numsSize - 1);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }

private:
    int search(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindPeakElement(int[] nums) {
        return Search(nums, 0, nums.Length - 1);
    }

    public int Search(int[] nums, int l, int r) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return Search(nums, l, mid);
        return Search(nums, mid + 1, r);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findPeakElement(nums []int) int {
    return search(nums, 0, len(nums)-1)
}

func search(nums []int, l int, r int) int {
    if l == r {
        return l
    }
    mid := (l + r) / 2
    if nums[mid] > nums[mid+1] {
        return search(nums, l, mid)
    }
    return search(nums, mid+1, r)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findPeakElement(int[] nums) {
        return search(nums, 0, nums.length - 1);
    }

    public int search(int[] nums, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findPeakElement = function (nums) {
    return search(nums, 0, nums.length - 1);
};

var search = function (nums, l, r) {
    if (l == r) return l;
    let mid = Math.floor((l + r) / 2);
    if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
    return search(nums, mid + 1, r);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        return self.search(nums, 0, len(nums) - 1)

    def search(self, nums: List[int], l: int, r: int) -> int:
        if l == r:
            return l
        mid = (l + r) // 2
        if nums[mid] > nums[mid + 1]:
            return self.search(nums, l, mid)
        return self.search(nums, mid + 1, r)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findPeakElement(nums: number[]): number {
    return search(nums, 0, nums.length - 1);
}

function search(nums: number[], l: number, r: number): number {
    if (l == r) return l;
    let mid = Math.floor((l + r) / 2);
    if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
    return search(nums, mid + 1, r);
}
```

</details>

<br>

## Approach 3: Iterative Binary Search

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int findPeakElement(int* nums, int numsSize) {
    int l = 0, r = numsSize - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int FindPeakElement(int[] nums) {
        int l = 0, r = nums.Length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func findPeakElement(nums []int) int {
    l := 0
    r := len(nums) - 1
    for l < r {
        mid := (l + r) / 2
        if nums[mid] > nums[mid+1] {
            r = mid
        } else {
            l = mid + 1
        }
    }
    return l
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var findPeakElement = function (nums) {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        let mid = Math.floor((l + r) / 2);
        if (nums[mid] > nums[mid + 1]) r = mid;
        else l = mid + 1;
    }
    return l;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[mid + 1]:
                r = mid
            else:
                l = mid + 1
        return l
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findPeakElement(nums: number[]): number {
    let l = 0,
        r = nums.length - 1;
    while (l < r) {
        let mid = Math.floor((l + r) / 2);
        if (nums[mid] > nums[mid + 1]) r = mid;
        else l = mid + 1;
    }
    return l;
}
```

</details>
