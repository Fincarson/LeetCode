# 1015. Smallest Integer Divisible by K

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/smallest-integer-divisible-by-k/)  
`Hash Table` `Math`

**Problem Link:** [LeetCode 1015 - Smallest Integer Divisible by K](https://leetcode.com/problems/smallest-integer-divisible-by-k/)

## Problem

Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

### Example 1

```text
Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.
```

### Example 2

```text
Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.
```

### Example 3

```text
Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
```

## Constraints

- 1 <= k <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1015. Smallest Integer Divisible by K

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Checking Loop | Java, Python3 |

## Approach: Checking Loop

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int smallestRepunitDivByK(int K) {
        int remainder = 0;
        for (int length_N = 1; length_N <= K; length_N++) {
            remainder = (remainder * 10 + 1) % K;
            if (remainder == 0) {
                return length_N;
            }
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def smallestRepunitDivByK(self, K: int) -> int:
        remainder = 0
        for length_N in range(1,K+1):
            remainder = (remainder*10+1) % K
            if remainder == 0:
                return length_N
        return -1
```

</details>
