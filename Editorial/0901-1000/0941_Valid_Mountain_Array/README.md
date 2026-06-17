# 941. Valid Mountain Array

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/valid-mountain-array/)  
`Array`

**Problem Link:** [LeetCode 941 - Valid Mountain Array](https://leetcode.com/problems/valid-mountain-array/)

## Problem

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:

		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

### Example 1

```text
Input: arr = [2,1]
Output: false
```

### Example 2

```text
Input: arr = [3,5,5]
Output: false
```

### Example 3

```text
Input: arr = [0,3,2,1]
Output: true
```

## Constraints

- 1 <= arr.length <= 104
- 0 <= arr[i] <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Beautiful Towers I](https://leetcode.com/problems/beautiful-towers-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 941. Valid Mountain Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One Pass | Java, Python |

## Approach 1: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int N = A.length;
        int i = 0;

        // walk up
        while (i+1 < N && A[i] < A[i+1])
            i++;

        // peak can't be first or last
        if (i == 0 || i == N-1)
            return false;

        // walk down
        while (i+1 < N && A[i] > A[i+1])
            i++;

        return i == N-1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def validMountainArray(self, A):
        N = len(A)
        i = 0

        # walk up
        while i+1 < N and A[i] < A[i+1]:
            i += 1

        # peak can't be first or last
        if i == 0 or i == N-1:
            return False

        # walk down
        while i+1 < N and A[i] > A[i+1]:
            i += 1

        return i == N-1
```

</details>
