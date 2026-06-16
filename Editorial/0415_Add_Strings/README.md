# 415. Add Strings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/add-strings/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 415 - Add Strings](https://leetcode.com/problems/add-strings/)

## Problem

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

### Example 1

```text
Input: num1 = "11", num2 = "123"
Output: "134"
```

### Example 2

```text
Input: num1 = "456", num2 = "77"
Output: "533"
```

### Example 3

```text
Input: num1 = "0", num2 = "0"
Output: "0"
```

## Constraints

- 1 <= num1.length, num2.length <= 104
- num1 and num2 consist of only digits.
- num1 and num2 don't have any leading zeros except for the zero itself.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 415. Add Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Elementary Math | Java, Python3 |

## Approach 1: Elementary Math

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder();

        int carry = 0;
        int p1 = num1.length() - 1;
        int p2 = num2.length() - 1;
        while (p1 >= 0 || p2 >= 0) {
            int x1 = p1 >= 0 ? num1.charAt(p1) - '0' : 0;
            int x2 = p2 >= 0 ? num2.charAt(p2) - '0' : 0;
            int value = (x1 + x2 + carry) % 10;
            carry = (x1 + x2 + carry) / 10;
            res.append(value);
            p1--;
            p2--;    
        }
        
        if (carry != 0)
            res.append(carry);
        
        return res.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = []

        carry = 0
        p1 = len(num1) - 1
        p2 = len(num2) - 1
        while p1 >= 0 or p2 >= 0:
            x1 = ord(num1[p1]) - ord('0') if p1 >= 0 else 0
            x2 = ord(num2[p2]) - ord('0') if p2 >= 0 else 0
            value = (x1 + x2 + carry) % 10
            carry = (x1 + x2 + carry) // 10
            res.append(value)
            p1 -= 1
            p2 -= 1
        
        if carry:
            res.append(carry)
        
        return ''.join(str(x) for x in res[::-1])
```

</details>
