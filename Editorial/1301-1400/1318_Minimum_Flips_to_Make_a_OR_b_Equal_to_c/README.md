# 1318. Minimum Flips to Make a OR b Equal to c

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)  
`Bit Manipulation`

**Problem Link:** [LeetCode 1318 - Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)

## Problem

Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

### Example 1

```text
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
```

### Example 2

```text
Input: a = 4, b = 2, c = 7
Output: 1
```

### Example 3

```text
Input: a = 1, b = 2, c = 3
Output: 0
```

## Constraints

- 1 <= a <= 10^9
- 1 <= b <= 10^9
- 1 <= c <= 10^9

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Bit Flips to Convert Number](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1318. Minimum Flips to Make a OR b Equal to c

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bit Manipulation | C++, Java, Python3 |
| Count the Number of Set Bits Using Built-in Function | C++, Java, Python3 |

## Approach 1: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                answer += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                answer += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        answer = 0
        while a or b or c:
            if c & 1:
                answer += 0 if ((a & 1) or (b & 1)) else 1
            else:
                answer += (a & 1) + (b & 1)
            a >>= 1
            b >>= 1
            c >>= 1
        return answer
```

</details>

<br>

## Approach 2: Count the Number of Set Bits Using Built-in Function

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + __builtin_popcount(a & b & ((a | b) ^ c));
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        return Integer.bitCount((a | b) ^ c) + Integer.bitCount(a & b & ((a | b) ^ c));   
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
# In 3.9 or earlier
class Solution:
    # In 3.9 or earlier
    def minFlips(self, a: int, b: int, c: int) -> int:
        return bin((a | b) ^ c).count("1") + bin(a & b & ((a | b) ^ c)).count("1")

    # In 3.10 or later
    def minFlips(self, a: int, b: int, c: int) -> int:
        return ((a | b) ^ c).bit_count() + (a & b & ((a | b) ^ c)).bit_count()
```

</details>
