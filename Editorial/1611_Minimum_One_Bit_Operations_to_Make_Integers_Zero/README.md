# 1611. Minimum One Bit Operations to Make Integers Zero

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)  
`Math` `Dynamic Programming` `Bit Manipulation` `Recursion` `Memoization`

**Problem Link:** [LeetCode 1611 - Minimum One Bit Operations to Make Integers Zero](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)

## Problem

Given an integer n, you must transform it into 0 using the following operations any number of times:

- Change the rightmost (0th) bit in the binary representation of n.
- Change the ith bit in the binary representation of n if the (i-1)th bit is set to 1 and the (i-2)th through 0th bits are set to 0.

Return the minimum number of operations to transform n into 0.

### Example 1

```text
Input: n = 3
Output: 2
Explanation: The binary representation of 3 is "11".
"11" -> "01" with the 2nd operation since the 0th bit is 1.
"01" -> "00" with the 1st operation.
```

### Example 2

```text
Input: n = 6
Output: 4
Explanation: The binary representation of 6 is "110".
"110" -> "010" with the 2nd operation since the 1st bit is 1 and 0th through 0th bits are 0.
"010" -> "011" with the 1st operation.
"011" -> "001" with the 2nd operation since the 0th bit is 1.
"001" -> "000" with the 1st operation.
```

## Constraints

- 0 <= n <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Operations to Make Array Continuous](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Apply Bitwise Operations to Make Strings Equal](https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1611. Minimum One Bit Operations to Make Integers Zero

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Math and Recursion | C++, Java, Python3 |
| Iteration | C++, Java, Python3 |
| Gray Code | C++, Java, Python3 |

## Approach 1: Math and Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int f(int k) {
    if (k == 0) {
        return 1;
    }
    
    return 2 * f(k - 1) + 1;
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
int f(int k) {
    if (k == 0) {
        return 1;
    }
    
    return 2 * f(k - 1) + 1;
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
def f(k):
    if k == 0:
        return 1
    
    return 2 * f(k - 1) + 1
```

</details>

<br>

## Approach 2: Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;
        
        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }
            
            mask <<= 1;
            k++;
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumOneBitOperations(int n) {
        int ans = 0;
        int k = 0;
        int mask = 1;
        
        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k + 1)) - 1 - ans;
            }
            
            mask <<= 1;
            k++;
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans = 0
        k = 0
        mask = 1
        
        while mask <= n:
            if n & mask:
                ans = (1 << (k + 1)) - 1 - ans
                
            mask <<= 1
            k += 1
        
        return ans
```

</details>

<br>

## Approach 3: Gray Code

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = n;
        ans ^= ans >> 16;
        ans ^= ans >> 8;
        ans ^= ans >> 4;
        ans ^= ans >> 2;
        ans ^= ans >> 1;
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minimumOneBitOperations(int n) {
        int ans = n;
        ans ^= ans >> 16;
        ans ^= ans >> 8;
        ans ^= ans >> 4;
        ans ^= ans >> 2;
        ans ^= ans >> 1;
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        ans = n
        ans ^= ans >> 16
        ans ^= ans >> 8
        ans ^= ans >> 4
        ans ^= ans >> 2
        ans ^= ans >> 1
        return ans
```

</details>
