# 537. Complex Number Multiplication

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/complex-number-multiplication/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 537 - Complex Number Multiplication](https://leetcode.com/problems/complex-number-multiplication/)

## Problem

A complex number can be represented as a string on the form "real+imaginaryi" where:

- real is the real part and is an integer in the range [-100, 100].
- imaginary is the imaginary part and is an integer in the range [-100, 100].
- i2 == -1.

Given two complex numbers num1 and num2 as strings, return a string of the complex number that represents their multiplications.

### Example 1

```text
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
```

### Example 2

```text
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
```

## Constraints

- num1 and num2 are valid complex numbers.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 537. Complex Number Multiplication

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Simple Solution[Accepted] | Java |

## Approach #1 Simple Solution[Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {

    public String complexNumberMultiply(String a, String b) {
        String x[] = a.split("\\+|i");
        String y[] = b.split("\\+|i");
        int a_real = Integer.parseInt(x[0]);
        int a_img = Integer.parseInt(x[1]);
        int b_real = Integer.parseInt(y[0]);
        int b_img = Integer.parseInt(y[1]);
        return (a_real * b_real - a_img * b_img) + "+" + (a_real * b_img + a_img * b_real) + "i";

    }
}
```

</details>
