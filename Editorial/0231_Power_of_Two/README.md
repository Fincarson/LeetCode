# 231. Power of Two

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/power-of-two/)  
`Math` `Bit Manipulation` `Recursion`

**Problem Link:** [LeetCode 231 - Power of Two](https://leetcode.com/problems/power-of-two/)

## Problem

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

### Example 1

```text
Input: n = 1
Output: true
Explanation: 20 = 1
```

### Example 2

```text
Input: n = 16
Output: true
Explanation: 24 = 16
```

### Example 3

```text
Input: n = 3
Output: false
```

## Constraints

- -231 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Power of Three](https://leetcode.com/problems/power-of-three/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Power of Four](https://leetcode.com/problems/power-of-four/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 231. Power of Two

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bitwise Operators: Get the Rightmost 1-bit | C, C++, Java, Python3 |
| Bitwise operators: Turn off the Rightmost 1-bit | C, C++, Java, Python3 |

## Approach 1: Bitwise Operators: Get the Rightmost 1-bit

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPowerOfTwo(int n) {
  if (n <= 0) return false;
  return (n & (-n)) == n;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return (n & (-n)) == n;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (-n)) == n;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        return n & (-n) == n
```

</details>

<br>

## Approach 2: Bitwise operators: Turn off the Rightmost 1-bit

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isPowerOfTwo(int n) {
  if (n <= 0) return false;
  return (n & (n - 1)) == 0;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
  public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
  }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public boolean isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        return n & (n - 1) == 0
```

</details>
