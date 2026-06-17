# 1009. Complement of Base 10 Integer

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/complement-of-base-10-integer/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 1009 - Complement of Base 10 Integer](https://leetcode.com/problems/complement-of-base-10-integer/)

## Problem

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

- For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer n, return its complement.

### Example 1

```text
Input: n = 5
Output: 2
Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
```

### Example 2

```text
Input: n = 7
Output: 0
Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
```

### Example 3

```text
Input: n = 10
Output: 5
Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
```

## Constraints

- 0 <= n < 109

Note: This question is the same as 476: https://leetcode.com/problems/number-complement/

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1009. Complement of Base 10 Integer

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
  public int bitwiseComplement(int N) {
    if (N == 0) return 1;
    int todo = N, bit = 1;
    while (todo != 0) {
      // Flip THE current bit
      N = N ^ bit;
      // Prepare for the next run
      bit = bit << 1;
      todo = todo >> 1;
    }
    return N;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        todo, bit = N, 1
        while todo:
            # Flip the current bit
            N = N ^ bit
            # prepare for the next run
            bit = bit << 1
            todo = todo >> 1
        return N
```

</details>

<br>

## Approach 2: Compute Bit Length and Construct 1-bit Bitmask

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int bitwiseComplement(int N) {
    // l is a length of N in binary representation
    int l = (int)( Math.log(N) / Math.log(2) ) + 1;
    // bitmask has the same length as num and contains only ones 1...1
    int bitmask = (1 << l) - 1;
    //Flip all bits
    return bitmask ^ N;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from math import log2
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        # l is a length of N in binary representation
        l = floor(log2(N)) + 1        
        # bitmask has the same length as N and contains only ones 1...1
        bitmask = (1 << l) - 1
        # Flip all bits
        return bitmask ^ N
```

</details>

<br>

## Approach 3: Built-in Functions to Construct 1-bit Bitmask

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int bitwiseComplement(int N) {
    return N == 0 ? 1 : (Integer.highestOneBit(N) << 1) - N - 1;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        return (1 << N.bit_length()) - 1 - N if N else 1
```

</details>

<br>

## Approach 4: highestOneBit OpenJDK algorithm from Hacker's Delight

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public int bitwiseComplement(int N) {
    if (N == 0) return 1;
    // bitmask has the same length as N and contains only ones 1...1
    int bitmask = N;
    bitmask |= (bitmask >> 1);
    bitmask |= (bitmask >> 2);
    bitmask |= (bitmask >> 4);
    bitmask |= (bitmask >> 8);
    bitmask |= (bitmask >> 16);
    // flip all bits 
    return bitmask ^ N;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        if N == 0:
            return 1
        # bitmask has the same length as N and contains only ones 1...1
        bitmask = N
        bitmask |= (bitmask >> 1)
        bitmask |= (bitmask >> 2)
        bitmask |= (bitmask >> 4)
        bitmask |= (bitmask >> 8)
        bitmask |= (bitmask >> 16)
        # flip all bits
        return bitmask ^ N
```

</details>
