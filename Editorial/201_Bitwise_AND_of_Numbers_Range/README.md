# 201. Bitwise AND of Numbers Range

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/bitwise-and-of-numbers-range/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 201 - Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)

## Problem

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

### Example 1

```text
Input: left = 5, right = 7
Output: 4
```

### Example 2

```text
Input: left = 0, right = 0
Output: 0
```

### Example 3

```text
Input: left = 1, right = 2147483647
Output: 0
```

## Constraints

- 0 <= left <= right <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Nice Subarray](https://leetcode.com/problems/longest-nice-subarray/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 201. Bitwise AND of Numbers Range

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bit Shift | C++, Java, Python3 |
| Brian Kernighan's Algorithm | C++, Java, Python3 |

## Approach 1: Bit Shift

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // find the common 1-bits
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        // find the common 1-bits
        while (m < n) {
            m >>= 1;
            n >>= 1;
            ++shift;
        }
        return m << shift;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        shift = 0
        # find the common 1-bits
        while m < n:
            m = m >> 1
            n = n >> 1
            shift += 1
        return m << shift
```

</details>

<br>

## Approach 2: Brian Kernighan's Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // turn off rightmost 1-bit
            n = n & (n - 1);
        }
        return n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            // turn off rightmost 1-bit
            n = n & (n - 1);
        }
        return n;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:
        while m < n:
            # turn off rightmost 1-bit
            n = n & (n - 1)
        return n
```

</details>
