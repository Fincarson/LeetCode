# 88. Merge Sorted Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/merge-sorted-array/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 88 - Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

## Problem

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

### Example 1

```text
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

### Example 2

```text
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
```

### Example 3

```text
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

## Constraints

- nums1.length == m + n
- nums2.length == n
- 0 <= m, n <= 200
- 1 <= m + n <= 200
- -109 <= nums1[i], nums2[j] <= 109

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Take K of Each Character From Left and Right](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 88. Merge Sorted Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Merge and sort | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Three Pointers (Start From the Beginning) | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Three Pointers (Start From the End) | C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Merge and sort

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
// C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
// C#

public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }

        Array.Sort(nums1);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
// Golang
func merge(nums1 []int, m int, nums2 []int, n int) {
    for i := 0; i < n; i++ {
        nums1[i+m] = nums2[i]
    }
    sort.Ints(nums1)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for (int i = 0; i < n; i++) {
            nums1[i + m] = nums2[i];
        }
        Arrays.sort(nums1);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
//JavaScript
var merge = function (nums1, m, nums2, n) {
    // Write the elements of num2 into the end of nums1.
    for (let i = 0; i < n; i++) {
        nums1[i + m] = nums2[i];
    }
    // Sort nums1 array in-place.
    nums1.sort((a, b) => a - b);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Write the elements of num2 into the end of nums1.
        for i in range(n):
            nums1[i + m] = nums2[i]

        # Sort nums1 list in-place.
        nums1.sort()
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
//TypeScript
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    // Write the elements of num2 into the end of nums1.
    for (let i = 0; i < n; i++) {
        nums1[i + m] = nums2[i];
    }
    // Sort nums1 array in-place.
    nums1.sort((a, b) => a - b);
}
```

</details>

<br>

## Approach 2: Three Pointers (Start From the Beginning)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Make a copy of the first m elements of nums1.
        vector<int> nums1Copy(nums1.begin(), nums1.begin() + m);
        // Read pointers for nums1Copy and nums2 respectively.
        int p1 = 0;
        int p2 = 0;
        // Compare elements from nums1Copy and nums2 and write the smallest to
        // nums1.
        for (int p = 0; p < m + n; p++) {
            // We also need to ensure that p1 and p2 aren't over the boundaries
            // of their respective arrays.
            if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
                nums1[p] = nums1Copy[p1++];
            } else {
                nums1[p] = nums2[p2++];
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        // Make a copy of the first m elements of nums1.
        int[] nums1Copy = new int[m];
        Array.Copy(nums1, 0, nums1Copy, 0, m);
        // Read pointers for nums1Copy and nums2 respectively.
        int p1 = 0;
        int p2 = 0;
        // Compare elements from nums1Copy and nums2 and write the smallest to
        // nums1.
        for (int p = 0; p < m + n; p++) {
            // We also need to ensure that p1 and p2 aren't over the boundaries
            // of their respective arrays.
            if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
                nums1[p] = nums1Copy[p1++];
            } else {
                nums1[p] = nums2[p2++];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func merge(nums1 []int, m int, nums2 []int, n int) {
    // Make a copy of the first m elements of nums1.
    nums1Copy := append([]int(nil), nums1[:m]...)
    // Read pointers for nums1Copy and nums2 respectively.
    p1 := 0
    p2 := 0
    // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
    for p := 0; p < m+n; p++ {
        // We also need to ensure that p1 and p2 aren't over the boundaries
        // of their respective arrays.
        if p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2]) {
            nums1[p] = nums1Copy[p1]
            p1++
        } else {
            nums1[p] = nums2[p2]
            p2++
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Make a copy of the first m elements of nums1.
        int[] nums1Copy = new int[m];
        for (int i = 0; i < m; i++) {
            nums1Copy[i] = nums1[i];
        }

        // Read pointers for nums1Copy and nums2 respectively.
        int p1 = 0;
        int p2 = 0;

        // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
        for (int p = 0; p < m + n; p++) {
            // We also need to ensure that p1 and p2 aren't over the boundaries
            // of their respective arrays.
            if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
                nums1[p] = nums1Copy[p1++];
            } else {
                nums1[p] = nums2[p2++];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var merge = function (nums1, m, nums2, n) {
    // Make a copy of the first m elements of nums1.
    let nums1Copy = nums1.slice(0, m);
    // Read pointers for nums1Copy and nums2 respectively.
    let p1 = 0;
    let p2 = 0;
    // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
    for (let p = 0; p < m + n; p++) {
        // We also need to ensure that p1 and p2 aren't over the boundaries
        // of their respective arrays.
        if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
            nums1[p] = nums1Copy[p1++];
        } else {
            nums1[p] = nums2[p2++];
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Make a copy of the first m elements of nums1.
        nums1_copy = nums1[:m]

        # Read pointers for nums1Copy and nums2 respectively.
        p1 = 0
        p2 = 0

        # Compare elements from nums1Copy and nums2 and write the smallest to nums1.
        for p in range(n + m):
            # We also need to ensure that p1 and p2 aren't over the boundaries
            # of their respective arrays.
            if p2 >= n or (p1 < m and nums1_copy[p1] <= nums2[p2]):
                nums1[p] = nums1_copy[p1]
                p1 += 1
            else:
                nums1[p] = nums2[p2]
                p2 += 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    // Make a copy of the first m elements of nums1.
    let nums1Copy: number[] = nums1.splice(0, m);
    // Read pointers for nums1Copy and nums2 respectively.
    let p1: number = 0;
    let p2: number = 0;
    // Compare elements from nums1Copy and nums2 and write the smallest to nums1.
    for (let p = 0; p < m + n; p++) {
        // We also need to ensure that p1 and p2 aren't over the boundaries
        // of their respective arrays.
        if (p2 >= n || (p1 < m && nums1Copy[p1] < nums2[p2])) {
            nums1[p] = nums1Copy[p1++];
        } else {
            nums1[p] = nums2[p2++];
        }
    }
}
```

</details>

<br>

## Approach 3: Three Pointers (Start From the End)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Set p1 and p2 to point to the end of their respective arrays.
        int p1 = m - 1;
        int p2 = n - 1;
        // And move p backward through the array, each time writing
        // the largest value pointed at by p1 or p2.
        for (int p = m + n - 1; p >= 0; p--) {
            if (p2 < 0) {
                break;
            }
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        // Set p1 and p2 to point to the end of their respective arrays.
        int p1 = m - 1;
        int p2 = n - 1;
        // And move p backward through the array, each time writing
        // the largest value pointed at by p1 or p2.
        for (int p = m + n - 1; p >= 0; p--) {
            if (p2 < 0) {
                break;
            }

            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func merge(nums1 []int, m int, nums2 []int, n int) {
    // Set p1 and p2 to point to the end of their respective arrays.
    p1 := m - 1
    p2 := n - 1
    // And move p backward through the array, each time writing
    // the largest value pointed at by p1 or p2.
    for p := m + n - 1; p >= 0; p-- {
        if p2 < 0 {
            break
        }
        if p1 >= 0 && nums1[p1] > nums2[p2] {
            nums1[p] = nums1[p1]
            p1--
        } else {
            nums1[p] = nums2[p2]
            p2--
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Set p1 and p2 to point to the end of their respective arrays.
        int p1 = m - 1;
        int p2 = n - 1;

        // And move p backward through the array, each time writing
        // the largest value pointed at by p1 or p2.
        for (int p = m + n - 1; p >= 0; p--) {
            if (p2 < 0) {
                break;
            }
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1--];
            } else {
                nums1[p] = nums2[p2--];
            }
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var merge = function (nums1, m, nums2, n) {
    // Set p1 and p2 to point to the end of their respective arrays.
    let p1 = m - 1;
    let p2 = n - 1;
    // And move p backward through the array, each time writing
    // the largest value pointed at by p1 or p2.
    for (let p = m + n - 1; p >= 0; p--) {
        if (p2 < 0) {
            break;
        }
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1--];
        } else {
            nums1[p] = nums2[p2--];
        }
    }
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """

        # Set p1 and p2 to point to the end of their respective arrays.
        p1 = m - 1
        p2 = n - 1

        # And move p backward through the array, each time writing
        # the largest value pointed at by p1 or p2.
        for p in range(n + m - 1, -1, -1):
            if p2 < 0:
                break
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function merge(nums1: number[], m: number, nums2: number[], n: number): void {
    // Set p1 and p2 to point to the end of their respective arrays.
    let p1 = m - 1;
    let p2 = n - 1;
    // And move p backward through the array, each time writing
    // the largest value pointed at by p1 or p2.
    for (let p = m + n - 1; p >= 0; p--) {
        if (p2 < 0) {
            break;
        }
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1--];
        } else {
            nums1[p] = nums2[p2--];
        }
    }
}
```

</details>
