# 972. Equal Rational Numbers

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/equal-rational-numbers/)  
`Math` `String`

**Problem Link:** [LeetCode 972 - Equal Rational Numbers](https://leetcode.com/problems/equal-rational-numbers/)

## Problem

Given two strings s and t, each of which represents a non-negative rational number, return true if and only if they represent the same number. The strings may use parentheses to denote the repeating part of the rational number.

A rational number can be represented using up to three parts: <IntegerPart>, <NonRepeatingPart>, and a <RepeatingPart>. The number will be represented in one of the following three ways:

- <IntegerPart>

		For example, 12, 0, and 123.
- <IntegerPart><.><NonRepeatingPart>

		For example, 0.5, 1., 2.12, and 123.0001.
- <IntegerPart><.><NonRepeatingPart><(><RepeatingPart><)>

		For example, 0.1(6), 1.(9), 123.00(1212).

The repeating portion of a decimal expansion is conventionally denoted within a pair of round brackets. For example:

- 1/6 = 0.16666666... = 0.1(6) = 0.1666(6) = 0.166(66).

### Example 1

```text
Input: s = "0.(52)", t = "0.5(25)"
Output: true
Explanation: Because "0.(52)" represents 0.52525252..., and "0.5(25)" represents 0.52525252525..... , the strings represent the same number.
```

### Example 2

```text
Input: s = "0.1666(6)", t = "0.166(66)"
Output: true
```

### Example 3

```text
Input: s = "0.9(9)", t = "1."
Output: true
Explanation: "0.9(9)" represents 0.999999999... repeated forever, which equals 1.  [See this link for an explanation.]
"1." represents the number 1, which is formed correctly: (IntegerPart) = "1" and (NonRepeatingPart) = "".
```

## Constraints

- Each part consists only of digits.
- The <IntegerPart> does not have leading zeros (except for the zero itself).
- 1 <= <IntegerPart>.length <= 4
- 0 <= <NonRepeatingPart>.length <= 4
- 1 <= <RepeatingPart>.length <= 4

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 972. Equal Rational Numbers

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Fraction Class | Java, Python |

## Approach 1: Fraction Class

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isRationalEqual(String S, String T) {
        Fraction f1 = convert(S);
        Fraction f2 = convert(T);
        return f1.n == f2.n && f1.d == f2.d;
    }

    public Fraction convert(String S) {
        int state = 0; //whole, decimal, repeating
        Fraction ans = new Fraction(0, 1);
        int decimal_size = 0;

        for (String part: S.split("[.()]")) {
            state++;
            if (part.isEmpty()) continue;
            long x = Long.valueOf(part);
            int sz = part.length();

            if (state == 1) { // whole
                 ans.iadd(new Fraction(x, 1));
            } else if (state == 2) { // decimal
                 ans.iadd(new Fraction(x, (long) Math.pow(10, sz)));
                 decimal_size = sz;
            } else { // repeating
                 long denom = (long) Math.pow(10, decimal_size);
                 denom *= (long) (Math.pow(10, sz) - 1);
                 ans.iadd(new Fraction(x, denom));
            }
        }
        return ans;
    }
}

class Fraction {
    long n, d;
    Fraction(long n, long d) {
        long g = gcd(n, d);
        this.n = n / g;
        this.d = d / g;
    }

    public void iadd(Fraction other) {
        long numerator = this.n * other.d + this.d * other.n;
        long denominator = this.d * other.d;
        long g = Fraction.gcd(numerator, denominator);
        this.n = numerator / g;
        this.d = denominator / g;
    }

    static long gcd(long x, long y) {
        return x != 0 ? gcd(y % x, x) : y;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
from fractions import Fraction

class Solution(object):
    def isRationalEqual(self, S, T):
        def convert(S):
            if '.' not in S:
                return Fraction(int(S), 1)
            i = S.index('.')
            ans = Fraction(int(S[:i]), 1)
            S = S[i+1:]
            if '(' not in S:
                if S:
                    ans += Fraction(int(S), 10 ** len(S))
                return ans

            i = S.index('(')
            if i:
                ans += Fraction(int(S[:i]), 10 ** i)
            S = S[i+1:-1]
            j = len(S)
            ans += Fraction(int(S), 10**i * (10**j - 1))
            return ans

        return convert(S) == convert(T)
```

</details>
