# 476. Number Complement

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-complement/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 476 - Number Complement](https://leetcode.com/problems/number-complement/)

## Problem

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

- For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer num, return its complement.

### Example 1

```text
Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
```

### Example 2

```text
Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
```

## Constraints

- 1 <= num < 231

Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 476. Number Complement

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Flip Bit by Bit | Java, Python3 |
| Compute Bit Length and Construct 1-bit Bitmask | Java, Python3 |
| Built-in Functions to Construct 1-bit Bitmask | Java, Python3 |
| highestOneBit OpenJDK algorithm from Hacker's Delight | Java, Python3 |

## Approach 1: Flip Bit by Bit

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findComplement(int num) {
    int todo = num, bit = 1;
    while (todo != 0) {
      // flip the current bit
      num = num ^ bit;

      // prepare for the next run
      bit = bit << 1;
      todo = todo >> 1;
    }
    return num;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findComplement(self, num):
        todo, bit = num, 1
        while todo:
            # flip the current bit
            num = num ^ bit

            # prepare for the next run
            bit = bit << 1
            todo = todo >> 1
        return num
```

</details>

<br>

## Approach 2: Compute Bit Length and Construct 1-bit Bitmask

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findComplement(int num) {
    // n is a length of num in binary representation
    int n = (int)( Math.log(num) / Math.log(2) ) + 1;
    // The bitmask has the same length as num and contains only ones 1...1
    int bitmask = (1 << n) - 1;
    // Flip all bits
    return bitmask ^ num;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from math import log2
class Solution:
    def findComplement(self, num):
        # n is a length of num in binary representation
        n = floor(log2(num)) + 1
      
        # The bitmask has the same length as num and contains only ones 1...1
        bitmask = (1 << n) - 1

        # Flip all bits
        return bitmask ^ num
```

</details>

<br>

## Approach 3: Built-in Functions to Construct 1-bit Bitmask

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findComplement(int num) {
    return (Integer.highestOneBit(num) << 1) - num - 1;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findComplement(self, num):
        return (1 << num.bit_length()) - 1 - num
```

</details>

<br>

## Approach 4: highestOneBit OpenJDK algorithm from Hacker's Delight

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int findComplement(int num) {
    // bitmask has the same length as num and contains only ones 1...1
    int bitmask = num;
    bitmask |= (bitmask >> 1);
    bitmask |= (bitmask >> 2);
    bitmask |= (bitmask >> 4);
    bitmask |= (bitmask >> 8);
    bitmask |= (bitmask >> 16);
    // flip all bits 
    return bitmask ^ num;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findComplement(self, num):
        # bitmask has the same length as num and contains only ones 1...1
        bitmask = num
        bitmask |= (bitmask >> 1)
        bitmask |= (bitmask >> 2)
        bitmask |= (bitmask >> 4)
        bitmask |= (bitmask >> 8)
        bitmask |= (bitmask >> 16)
        # flip all bits
        return bitmask ^ num
```

</details>
