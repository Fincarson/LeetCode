# 371. Sum of Two Integers

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/sum-of-two-integers/)  
`Math` `Bit Manipulation`

**Problem Link:** [LeetCode 371 - Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)

## Problem

Given two integers a and b, return the sum of the two integers without using the operators + and -.

### Example 1

```text
Input: a = 1, b = 2
Output: 3
```

### Example 2

```text
Input: a = 2, b = 3
Output: 5
```

## Constraints

- -1000 <= a, b <= 1000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 371. Sum of Two Integers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Bit Manipulation: Easy and Language-Independent | Java, Python |
| Bit Manipulation: Short Language-Specific Solution | Java |

## Approach 1: Bit Manipulation: Easy and Language-Independent

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getSum(int a, int b) {
        int x = Math.abs(a), y = Math.abs(b);
        // ensure that abs(a) >= abs(b)
        if (x < y) return getSum(b, a);
        
        // abs(a) >= abs(b) --> 
        // a determines the sign
        int sign = a > 0 ? 1 : -1;
        
        if (a * b >= 0) {
            // sum of two positive integers x + y
            // where x > y
            
            // TODO  
            }    
        } else {
            // difference of two positive integers x - y
            // where x > y
            
            // TODO  
            }    
        }
        
        return x * sign;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def getSum(self, a: int, b: int) -> int:
        x, y = abs(a), abs(b)
        # ensure that abs(a) >= abs(b)
        if x < y:
            return self.getSum(b, a)
        
        # abs(a) >= abs(b) --> 
        # a determines the sign
        sign = 1 if a > 0 else -1
        
        if a * b >= 0:
            # sum of two positive integers x + y
            # where x > y
            
            # TODO
        else:
            # difference of two integers x - y
            # where x > y
            
            # TODO
        
        return x * sign
```

</details>

<br>

## Approach 2: Bit Manipulation: Short Language-Specific Solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int getSum(int a, int b) {
        while (b != 0) {
            int answer = a ^ b;
            int carry = (a & b) << 1;
            a = answer;
            b = carry;
        }
        
        return a;
    }
}
```

</details>
