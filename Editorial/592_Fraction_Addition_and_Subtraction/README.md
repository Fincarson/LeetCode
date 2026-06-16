# 592. Fraction Addition and Subtraction

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/fraction-addition-and-subtraction/)  
`Math` `String` `Simulation`

**Problem Link:** [LeetCode 592 - Fraction Addition and Subtraction](https://leetcode.com/problems/fraction-addition-and-subtraction/)

## Problem

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

### Example 1

```text
Input: expression = "-1/2+1/2"
Output: "0/1"
```

### Example 2

```text
Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
```

### Example 3

```text
Input: expression = "1/3-1/2"
Output: "-1/6"
```

## Constraints

- The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
- Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
- The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
- The number of given fractions will be in the range [1, 10].
- The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Solve the Equation](https://leetcode.com/problems/solve-the-equation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 592. Fraction Addition and Subtraction

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Manual Parsing + Common Denominator | C++, Java, Python3 |
| Approach 2 - Parsing with Regular Expressions | C++, Java, Python3 |

## Approach 1: Manual Parsing + Common Denominator

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while (i < expression.size()) {
            int currNum = 0;
            int currDenom = 0;

            bool isNegative = false;

            // check for sign
            if (expression[i] == '-' || expression[i] == '+') {
                if (expression[i] == '-') {
                    isNegative = true;
                }
                // move to next character
                i++;
            }

            // build numerator
            while (isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            if (isNegative) currNum *= -1;

            // skip divisor
            i++;

            // build denominator
            while (i < expression.size() && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDenom = currDenom * 10 + val;
                i++;
            }

            // add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = abs(FindGCD(num, denom));

        // reduce fractions
        num /= gcd;
        denom /= gcd;

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String fractionAddition(String expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while (i < expression.length()) {
            int currNum = 0;
            int currDenom = 0;

            boolean isNegative = false;

            // check for sign
            if (expression.charAt(i) == '-' || expression.charAt(i) == '+') {
                if (expression.charAt(i) == '-') {
                    isNegative = true;
                }
                // move to next character
                i++;
            }

            // build numerator
            while (Character.isDigit(expression.charAt(i))) {
                int val = expression.charAt(i) - '0';
                currNum = currNum * 10 + val;
                i++;
            }

            if (isNegative) currNum *= -1;

            //skip divisor
            i++;

            // build denominator
            while (
                i < expression.length() &&
                Character.isDigit(expression.charAt(i))
            ) {
                int val = expression.charAt(i) - '0';
                currDenom = currDenom * 10 + val;
                i++;
            }

            // add fractions together using common denominator
            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = Math.abs(FindGCD(num, denom));

        // reduce fractions
        num /= gcd;
        denom /= gcd;

        return num + "/" + denom;
    }

    private int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def fractionAddition(self, expression):
        num = 0
        denom = 1

        i = 0
        while i < len(expression):
            curr_num = 0
            curr_denom = 0

            is_negative = False

            # check for sign
            if expression[i] == "-" or expression[i] == "+":
                if expression[i] == "-":
                    is_negative = True
                # move to next character
                i += 1

            # build numerator
            while i < len(expression) and expression[i].isdigit():
                val = int(expression[i])
                curr_num = curr_num * 10 + val
                i += 1

            if is_negative:
                curr_num *= -1

            # skip divisor
            i += 1

            # build denominator
            while i < len(expression) and expression[i].isdigit():
                val = int(expression[i])
                curr_denom = curr_denom * 10 + val
                i += 1

            # add fractions together using common denominator
            num = num * curr_denom + curr_num * denom
            denom = denom * curr_denom

        gcd = abs(self._find_gcd(num, denom))

        # reduce fractions
        num //= gcd
        denom //= gcd

        return f"{num}/{denom}"

    def _find_gcd(self, a, b):
        if a == 0:
            return b
        return self._find_gcd(b % a, a)
```

</details>

<br>

## Approach 2 - Parsing with Regular Expressions

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        // separate expression into signed numbers
        vector<string> nums;
        int i = 0;
        if (expression[0] != '-') expression = '+' + expression;
        while (i < expression.size()) {
            int j = i + 1;
            while (j < expression.size() && expression[j] != '+' &&
                   expression[j] != '-') {
                j++;
            }
            nums.push_back(expression.substr(i, j - i));
            i = j;
        }

        for (int i = 0; i < nums.size(); ++i) {
            size_t pos = nums[i].find('/');
            int currNum = stoi(nums[i].substr(1, pos - 1));
            if (nums[i][0] == '-') currNum = -currNum;
            int currDenom = stoi(nums[i].substr(pos + 1));

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;

            int gcd = abs(FindGCD(num, denom));

            num /= gcd;
            denom /= gcd;
        }

        return to_string(num) + "/" + to_string(denom);
    }

private:
    int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String fractionAddition(String expression) {
        int num = 0;
        int denom = 1;

        // separate expression into signed numbers
        String[] nums = expression.split("/|(?=[-+])");

        for (int i = 0; i < nums.length; i += 2) {
            int currNum = Integer.valueOf(nums[i]);
            int currDenom = Integer.valueOf(nums[i + 1]);

            num = num * currDenom + currNum * denom;
            denom = denom * currDenom;
        }

        int gcd = Math.abs(FindGCD(num, denom));

        num /= gcd;
        denom /= gcd;

        return num + "/" + denom;
    }

    private int FindGCD(int a, int b) {
        if (a == 0) return b;
        return FindGCD(b % a, a);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import re


class Solution:
    def fractionAddition(self, expression: str) -> str:
        num = 0
        denom = 1

        # separate expression into signed numbers
        nums = re.split("/|(?=[-+])", expression)
        nums = list(filter(None, nums))

        for i in range(0, len(nums), 2):
            curr_num = int(nums[i])
            curr_denom = int(nums[i + 1])

            num = num * curr_denom + curr_num * denom
            denom = denom * curr_denom

        gcd = abs(self._find_gcd(num, denom))

        num //= gcd
        denom //= gcd

        return str(num) + "/" + str(denom)

    def _find_gcd(self, a: int, b: int) -> int:
        if a == 0:
            return b
        return self._find_gcd(b % a, a)
```

</details>
