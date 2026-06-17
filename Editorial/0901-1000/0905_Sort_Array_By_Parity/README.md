# 905. Sort Array By Parity

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/sort-array-by-parity/)  
`Array` `Two Pointers` `Sorting`

**Problem Link:** [LeetCode 905 - Sort Array By Parity](https://leetcode.com/problems/sort-array-by-parity/)

## Problem

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

### Example 1

```text
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

### Example 2

```text
Input: nums = [0]
Output: [0]
```

## Constraints

- 1 <= nums.length <= 5000
- 0 <= nums[i] <= 5000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Array By Parity II](https://leetcode.com/problems/sort-array-by-parity-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Largest Number After Digit Swaps by Parity](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 905. Sort Array By Parity

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Sort | Java, Python |
| Two Pass | Java, Python |
| In-Place | Java, Python |

## Approach 1: Sort

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        Integer[] B = new Integer[A.length];
        for (int t = 0; t < A.length; ++t)
            B[t] = A[t];

        Arrays.sort(B, (a, b) -> Integer.compare(a%2, b%2));

        for (int t = 0; t < A.length; ++t)
            A[t] = B[t];
        return A;

        /* Alternative:
        return Arrays.stream(A)
                     .boxed()
                     .sorted((a, b) -> Integer.compare(a%2, b%2))
                     .mapToInt(i -> i)
                     .toArray();
        */
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def sortArrayByParity(self, A):
        A.sort(key = lambda x: x % 2)
        return A
```

</details>

<br>

## Approach 2: Two Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] ans = new int[A.length];
        int t = 0;

        for (int i = 0; i < A.length; ++i)
            if (A[i] % 2 == 0)
                ans[t++] = A[i];

        for (int i = 0; i < A.length; ++i)
            if (A[i] % 2 == 1)
                ans[t++] = A[i];

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def sortArrayByParity(self, A):
        return ([x for x in A if x % 2 == 0] +
                [x for x in A if x % 2 == 1])
```

</details>

<br>

## Approach 3: In-Place

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int i = 0, j = A.length - 1;
        while (i < j) {
            if (A[i] % 2 > A[j] % 2) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

            if (A[i] % 2 == 0) i++;
            if (A[j] % 2 == 1) j--;
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
    def sortArrayByParity(self, A):
        i, j = 0, len(A) - 1
        while i < j:
            if A[i] % 2 > A[j] % 2:
                A[i], A[j] = A[j], A[i]

            if A[i] % 2 == 0: i += 1
            if A[j] % 2 == 1: j -= 1

        return A
```

</details>
