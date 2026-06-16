# 869. Reordered Power of 2

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reordered-power-of-2/)  
`Hash Table` `Math` `Sorting` `Counting` `Enumeration`

**Problem Link:** [LeetCode 869 - Reordered Power of 2](https://leetcode.com/problems/reordered-power-of-2/)

## Problem

You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a power of two.

### Example 1

```text
Input: n = 1
Output: true
```

### Example 2

```text
Input: n = 10
Output: false
```

## Constraints

- 1 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 869. Reordered Power of 2

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Permutations | Java, Python |
| Counting | Java, Python |

## Approach 1: Permutations

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean reorderedPowerOf2(int N) {
        // Build eg. N = 128 -> A = [1, 2, 8]
        String S = Integer.toString(N);
        int[] A = new int[S.length()];
        for (int i = 0; i < S.length(); ++i)
            A[i] = S.charAt(i) - '0';
        return permutations(A, 0);
    }

    // Return true if A represents a valid power of 2
    public boolean isPowerOfTwo(int[] A) {
        if (A[0] == 0) return false;  // no leading zero

        // Build eg. A = [1, 2, 8] -> N = 128
        int N = 0;
        for (int x: A)
            N = 10 * N + x;

        // Remove the largest power of 2
        while (N > 0 && ((N & 1) == 0))
            N >>= 1;

        // Check that there are no other factors besides 2
        return N == 1;
    }

    /**
     * Returns true if some permutation of (A[start], A[start+1], ...)
     * can result in A representing a power of 2.
     */
    public boolean permutations(int[] A, int start) {
        if (start == A.length)
            return isPowerOfTwo(A);

        // Choose some index i from [start, A.length - 1]
        // to be placed into position A[start].
        for (int i = start; i < A.length; ++i) {
            // Place A[start] with value A[i].
            swap(A, start, i);

            // For each such placement of A[start], if a permutation
            // of (A[start+1], A[start+2], ...) can result in A
            // representing a power of 2, return true.
            if (permutations(A, start + 1))
                return true;

            // Restore the array to the state it was in before
            // A[start] was placed with value A[i].
            swap(A, start, i);
        }

        return false;
    }

    public void swap(int[] A, int i, int j) {
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reorderedPowerOf2(self, N):
        """
        Let's work through an example like N = 128.
        In the last line, 'for cand in itertools.permutations(str(N))' will
        iterate through the six possibilities cand = ('1', '2', '8'),
        cand = ('1', '8', '2'), cand = ('2', '1', '8'), and so on.

        The check cand[0] != '0' is a check that the candidate permutation
        does not have a leading zero.

        The check bin(int("".join(cand))).count('1') == 1 is a check that cand
        represents a power of 2: namely, that the number of ones in its binary
        representation is 1.
        """
        return any(cand[0] != '0' and bin(int("".join(cand))).count('1') == 1
                   for cand in itertools.permutations(str(N)))
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean reorderedPowerOf2(int N) {
        int[] A = count(N);
        for (int i = 0; i < 31; ++i)
            if (Arrays.equals(A, count(1 << i)))
                return true;
        return false;
    }

    // Returns the count of digits of N
    // Eg. N = 112223334, returns [0,2,3,3,1,0,0,0,0,0]
    public int[] count(int N) {
        int[] ans = new int[10];
        while (N > 0) {
            ans[N % 10]++;
            N /= 10;
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
    def reorderedPowerOf2(self, N):
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << b))
                   for b in xrange(31))
```

</details>
