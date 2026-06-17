# 896. Monotonic Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/monotonic-array/)  
`Array`

**Problem Link:** [LeetCode 896 - Monotonic Array](https://leetcode.com/problems/monotonic-array/)

## Problem

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

### Example 1

```text
Input: nums = [1,2,2,3]
Output: true
```

### Example 2

```text
Input: nums = [6,5,4,4]
Output: true
```

### Example 3

```text
Input: nums = [1,3,2]
Output: false
```

## Constraints

- 1 <= nums.length <= 105
- -105 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Hills and Valleys in an Array](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Count of Monotonic Pairs I](https://leetcode.com/problems/find-the-count-of-monotonic-pairs-i/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 896. Monotonic Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pass | Java, Python |
| One Pass | Java, Python |
| One Pass (Simple Variant) | Java, Python |

## Approach 1: Two Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        return increasing(A) || decreasing(A);
    }

    public boolean increasing(int[] A) {
        for (int i = 0; i < A.length - 1; ++i)
            if (A[i] > A[i+1]) return false;
        return true;
    }

    public boolean decreasing(int[] A) {
        for (int i = 0; i < A.length - 1; ++i)
            if (A[i] < A[i+1]) return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isMonotonic(self, A):
        return (all(A[i] <= A[i+1] for i in xrange(len(A) - 1)) or
                all(A[i] >= A[i+1] for i in xrange(len(A) - 1)))
```

</details>

<br>

## Approach 2: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        int store = 0;
        for (int i = 0; i < A.length - 1; ++i) {
            int c = Integer.compare(A[i], A[i+1]);
            if (c != 0) {
                if (c != store && store != 0)
                    return false;
                store = c;
            }
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isMonotonic(self, A):
        store = 0
        for i in xrange(len(A) - 1):
            c = cmp(A[i], A[i+1])
            if c:
                if c != store != 0:
                    return False
                store = c
        return True
```

</details>

<br>

## Approach 3: One Pass (Simple Variant)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        boolean increasing = true;
        boolean decreasing = true;
        for (int i = 0; i < A.length - 1; ++i) {
            if (A[i] > A[i+1])
                increasing = false;
            if (A[i] < A[i+1])
                decreasing = false;
        }

        return increasing || decreasing;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def isMonotonic(self, A):
        increasing = decreasing = True

        for i in xrange(len(A) - 1):
            if A[i] > A[i+1]:
                increasing = False
            if A[i] < A[i+1]:
                decreasing = False

        return increasing or decreasing
```

</details>
