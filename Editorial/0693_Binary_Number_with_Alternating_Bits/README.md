# 693. Binary Number with Alternating Bits

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/binary-number-with-alternating-bits/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 693 - Binary Number with Alternating Bits](https://leetcode.com/problems/binary-number-with-alternating-bits/)

## Problem

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

### Example 1

```text
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101
```

### Example 2

```text
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.
```

### Example 3

```text
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
```

## Constraints

- 1 <= n <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 693. Binary Number with Alternating Bits

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Convert to String [Accepted] | Java, Python3 |
| Approach #2: Divide By Two [Accepted] | Java, Python3 |

## Approach #1: Convert to String [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        String bits = Integer.toBinaryString(n);
        for (int i = 0; i < bits.length() - 1; i++) {
            if (bits.charAt(i) == bits.charAt(i+1)) {
                return false;
            }
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def hasAlternatingBits(self, n):
        bits = bin(n)
        return all(bits[i] != bits[i+1]
                   for i in range(len(bits) - 1))
```

</details>

<br>

## Approach #2: Divide By Two [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean hasAlternatingBits(int n) {
        int cur = n % 2;
        n /= 2;
        while (n > 0) {
            if (cur == n % 2) return false;
            cur = n % 2;
            n /= 2;
        }
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def hasAlternatingBits(self, n):
        n, cur = divmod(n, 2)
        while n:
            if cur == n % 2: return False
            n, cur = divmod(n, 2)
        return True
```

</details>
