# 868. Binary Gap

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/binary-gap/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 868 - Binary Gap](https://leetcode.com/problems/binary-gap/)

## Problem

Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.

Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.

### Example 1

```text
Input: n = 22
Output: 2
Explanation: 22 in binary is "10110".
The first adjacent pair of 1's is "10110" with a distance of 2.
The second adjacent pair of 1's is "10110" with a distance of 1.
The answer is the largest of these two distances, which is 2.
Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.
```

### Example 2

```text
Input: n = 8
Output: 0
Explanation: 8 in binary is "1000".
There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.
```

### Example 3

```text
Input: n = 5
Output: 2
Explanation: 5 in binary is "101".
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

# Editorial - 868. Binary Gap

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Store Indexes | Java, Python |
| One Pass | Java, Python |

## Approach 1: Store Indexes

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int binaryGap(int N) {
        int[] A = new int[32];
        int t = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) != 0)
                A[t++] = i;

        int ans = 0;
        for (int i = 0; i < t - 1; ++i)
            ans = Math.max(ans, A[i+1] - A[i]);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def binaryGap(self, N):
        A = [i for i in xrange(32) if (N >> i) & 1]
        if len(A) < 2: return 0
        return max(A[i+1] - A[i] for i in xrange(len(A) - 1))
```

</details>

<br>

## Approach 2: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int binaryGap(int N) {
        int last = -1, ans = 0;
        for (int i = 0; i < 32; ++i)
            if (((N >> i) & 1) > 0) {
                if (last >= 0)
                    ans = Math.max(ans, i - last);
                last = i;
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
    def binaryGap(self, N):
        last = None
        ans = 0
        for i in xrange(32):
            if (N >> i) & 1:
                if last is not None:
                    ans = max(ans, i - last)
                last = i
        return ans
```

</details>
