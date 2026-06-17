# 922. Sort Array By Parity II

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sort-array-by-parity-ii/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 922 - Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/)

## Problem

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

### Example 1

```text
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

### Example 2

```text
Input: nums = [2,3]
Output: [2,3]
```

## Constraints

- 2 <= nums.length <= 2 * 104
- nums.length is even.
- Half of the integers in nums are even.
- 0 <= nums[i] <= 1000

Follow Up: Could you solve it in-place?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Rearrange Array Elements by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Find the Number of K-Even Arrays](https://leetcode.com/problems/find-the-number-of-k-even-arrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 922. Sort Array By Parity II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pass | Java, Python |
| Read / Write Heads | Java, Python |

## Approach 1: Two Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int N = A.length;
        int[] ans = new int[N];

        int t = 0;
        for (int x: A) if (x % 2 == 0) {
            ans[t] = x;
            t += 2;
        }

        t = 1;
        for (int x: A) if (x % 2 == 1) {
            ans[t] = x;
            t += 2;
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
    def sortArrayByParityII(self, A):
        N = len(A)
        ans = [None] * N

        t = 0
        for i, x in enumerate(A):
            if x % 2 == 0:
                ans[t] = x
                t += 2

        t = 1
        for i, x in enumerate(A):
            if x % 2 == 1:
                ans[t] = x
                t += 2

        # We could have also used slice assignment:
        # ans[::2] = (x for x in A if x % 2 == 0)
        # ans[1::2] = (x for x in A if x % 2 == 1)

        return ans
```

</details>

<br>

## Approach 2: Read / Write Heads

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int j = 1;
        for (int i = 0; i < A.length; i += 2)
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1)
                    j += 2;

                // Swap A[i] and A[j]
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

        return A;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def sortArrayByParityII(self, A):
        j = 1
        for i in xrange(0, len(A), 2):
            if A[i] % 2:
                while A[j] % 2:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
```

</details>
