# 845. Longest Mountain in Array

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-mountain-in-array/)  
`Array` `Two Pointers` `Dynamic Programming` `Enumeration`

**Problem Link:** [LeetCode 845 - Longest Mountain in Array](https://leetcode.com/problems/longest-mountain-in-array/)

## Problem

You may recall that an array arr is a mountain array if and only if:

- arr.length >= 3
- There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:

		arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
		arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.

### Example 1

```text
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
```

### Example 2

```text
Input: arr = [2,2,2]
Output: 0
Explanation: There is no mountain.
```

## Constraints

- 1 <= arr.length <= 104
- 0 <= arr[i] <= 104

Follow up:

- Can you solve it using only one pass?
- Can you solve it in O(1) space?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Removals to Make Mountain Array](https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Find Good Days to Rob the Bank](https://leetcode.com/problems/find-good-days-to-rob-the-bank/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 845. Longest Mountain in Array

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Two Pointer [Accepted] | Java, Python |

## Approach #1: Two Pointer [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int longestMountain(int[] A) {
        int N = A.length;
        int ans = 0, base = 0;
        while (base < N) {
            int end = base;
            // if base is a left-boundary
            if (end + 1 < N && A[end] < A[end + 1]) {
                // set end to the peak of this potential mountain
                while (end + 1 < N && A[end] < A[end + 1]) end++;

                // if end is really a peak..
                if (end + 1 < N && A[end] > A[end + 1]) {
                    // set end to the right-boundary of mountain
                    while (end + 1 < N && A[end] > A[end + 1]) end++;
                    // record candidate answer
                    ans = Math.max(ans, end - base + 1);
                }
            }

            base = Math.max(end, base + 1);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def longestMountain(self, A):
        N = len(A)
        ans = base = 0

        while base < N:
            end = base
            if end + 1 < N and A[end] < A[end + 1]: #if base is a left-boundary
                #set end to the peak of this potential mountain
                while end+1 < N and A[end] < A[end+1]:
                    end += 1

                if end + 1 < N and A[end] > A[end + 1]: #if end is really a peak..
                    #set 'end' to right-boundary of mountain
                    while end+1 < N and A[end] > A[end+1]:
                        end += 1
                    #record candidate answer
                    ans = max(ans, end - base + 1)

            base = max(end, base + 1)

        return ans
```

</details>
