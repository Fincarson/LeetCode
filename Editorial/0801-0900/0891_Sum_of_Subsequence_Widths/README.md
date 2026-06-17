# 891. Sum of Subsequence Widths

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/sum-of-subsequence-widths/)  
`Array` `Math` `Sorting`

**Problem Link:** [LeetCode 891 - Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths/)

## Problem

The width of a sequence is the difference between the maximum and minimum elements in the sequence.

Given an array of integers nums, return the sum of the widths of all the non-empty subsequences of nums. Since the answer may be very large, return it modulo 109 + 7.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

### Example 1

```text
Input: nums = [2,1,3]
Output: 6
Explanation: The subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
The sum of these widths is 6.
```

### Example 2

```text
Input: nums = [2]
Output: 0
```

## Constraints

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 891. Sum of Subsequence Widths

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Mathematical | Java, Python |

## Approach 1: Mathematical

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int sumSubseqWidths(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;
        Arrays.sort(A);

        long[] pow2 = new long[N];
        pow2[0] = 1;
        for (int i = 1; i < N; ++i)
            pow2[i] = pow2[i-1] * 2 % MOD;

        long ans = 0;
        for (int i = 0; i < N; ++i)
            ans = (ans + (pow2[i] - pow2[N-1-i]) * A[i]) % MOD;

        return (int) ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def sumSubseqWidths(self, A):
        MOD = 10**9 + 7
        N = len(A)
        A.sort()

        pow2 = [1]
        for i in xrange(1, N):
            pow2.append(pow2[-1] * 2 % MOD)

        ans = 0
        for i, x in enumerate(A):
            ans = (ans + (pow2[i] - pow2[N-1-i]) * x) % MOD
        return ans
```

</details>
