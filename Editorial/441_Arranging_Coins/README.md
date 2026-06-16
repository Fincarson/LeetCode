# 441. Arranging Coins

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/arranging-coins/)  
`Math` `Binary Search`

**Problem Link:** [LeetCode 441 - Arranging Coins](https://leetcode.com/problems/arranging-coins/)

## Problem

You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

### Example 1

```text
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
```

### Example 2

```text
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
```

## Constraints

- 1 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 441. Arranging Coins

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Binary Search | Java, Python |
| Math | Java, Python |

## Approach 1: Binary Search

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int arrangeCoins(int n) {
    long left = 0, right = n;
    long k, curr;
    while (left <= right) {
      k = left + (right - left) / 2;
      curr = k * (k + 1) / 2;

      if (curr == n) return (int)k;

      if (n < curr) {
        right = k - 1;
      } else {
        left = k + 1;
      }
    }
    return (int)right;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        left, right = 0, n
        while left <= right:
            k = (right + left) // 2
            curr = k * (k + 1) // 2
            if curr == n:
                return k
            if n < curr:
                right = k - 1
            else:
                left = k + 1
        return right
```

</details>

<br>

## Approach 2: Math

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int arrangeCoins(int n) {
    return (int)(Math.sqrt(2 * (long)n + 0.25) - 0.5);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def arrangeCoins(self, n: int) -> int:
        return (int)((2 * n + 0.25)**0.5 - 0.5)
```

</details>
