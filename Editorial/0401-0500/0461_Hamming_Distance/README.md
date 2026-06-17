# 461. Hamming Distance

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/hamming-distance/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 461 - Hamming Distance](https://leetcode.com/problems/hamming-distance/)

## Problem

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

### Example 1

```text
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       Ã¢â€ â€˜   Ã¢â€ â€˜
The above arrows point to positions where the corresponding bits are different.
```

### Example 2

```text
Input: x = 3, y = 1
Output: 1
```

## Constraints

- 0 <= x, y <= 231 - 1

Note: This question is the same as  2220: Minimum Bit Flips to Convert Number.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 461. Hamming Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Built-in BitCounting Functions | Java, Python |
| Bit Shift | Java, Python |
| Brian Kernighan's Algorithm | Java, Python |

## Approach 1: Built-in BitCounting Functions

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int hammingDistance(int x, int y) {
        return Integer.bitCount(x ^ y); 
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')
```

</details>

<br>

## Approach 2: Bit Shift

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int hammingDistance(int x, int y) {
    int xor = x ^ y;
    int distance = 0;
    while (xor != 0) {
      if (xor % 2 == 1)
        distance += 1;
      xor = xor >> 1;
    }
    return distance;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        xor = x ^ y
        distance = 0
        while xor:
            # mask out the rest bits
            if xor & 1:
                distance += 1
            xor = xor >> 1
        return distance
```

</details>

<br>

## Approach 3: Brian Kernighan's Algorithm

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int hammingDistance(int x, int y) {
    int xor = x ^ y;
    int distance = 0;
    while (xor != 0) {
      distance += 1;
      // remove the rightmost bit of '1'
      xor = xor & (xor - 1);
    }
    return distance;
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def hammingDistance(self, x, y):
        xor = x ^ y
        distance = 0
        while xor:
            distance += 1
            # remove the rightmost bit of '1'
            xor = xor & (xor - 1)
        return distance
```

</details>
