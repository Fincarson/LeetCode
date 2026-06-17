# 191. Number of 1 Bits

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-of-1-bits/)  
`Divide and Conquer` `Bit Manipulation`

**Problem Link:** [LeetCode 191 - Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)

## Problem

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Bits](https://leetcode.com/problems/reverse-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Power of Two](https://leetcode.com/problems/power-of-two/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Counting Bits](https://leetcode.com/problems/counting-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Binary Watch](https://leetcode.com/problems/binary-watch/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Hamming Distance](https://leetcode.com/problems/hamming-distance/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Prime Number of Set Bits in Binary Representation](https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Convert Date to Binary](https://leetcode.com/problems/convert-date-to-binary/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 191. Number of 1 Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Loop and Flip | Java |
| Bit Manipulation | Java |

## Approach 1: Loop and Flip

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
```

</details>

<br>

## Approach 2: Bit Manipulation

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int hammingWeight(int n) {
    int sum = 0;
    while (n != 0) {
        sum++;
        n &= (n - 1);
    }
    return sum;
}
```

</details>
