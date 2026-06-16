# 795. Number of Subarrays with Bounded Maximum

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)  
`Array` `Two Pointers`

**Problem Link:** [LeetCode 795 - Number of Subarrays with Bounded Maximum](https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/)

## Problem

Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.

### Example 1

```text
Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
```

### Example 2

```text
Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
```

## Constraints

- 1 <= nums.length <= 105
- 0 <= nums[i] <= 109
- 0 <= left <= right <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Subarrays With Median K](https://leetcode.com/problems/count-subarrays-with-median-k/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Find the Number of Subarrays Where Boundary Elements Are Maximum](https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 795. Number of Subarrays with Bounded Maximum

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Counting [Accepted] | Java, Python |

## Approach #1: Counting [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        return count(A, R) - count(A, L-1);
    }

    public int count(int[] A, int bound) {
        int ans = 0, cur = 0;
        for (int x: A) {
            cur = x <= bound ? cur + 1 : 0;
            ans += cur;
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
    def numSubarrayBoundedMax(self, A, L, R):
        def count(bound):
            ans = cur = 0
            for x in A :
                cur = cur + 1 if x <= bound else 0
                ans += cur
            return ans

        return count(R) - count(L - 1)
```

</details>
