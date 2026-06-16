# 227. Basic Calculator II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/basic-calculator-ii/)  
`Math` `String` `Stack`

**Problem Link:** [LeetCode 227 - Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/)

## Problem

Given a string s which represents an expression, evaluate this expression and return its value.

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

### Example 1

```text
Input: s = "3+2*2"
Output: 7
```

### Example 2

```text
Input: s = " 3/2 "
Output: 1
```

### Example 3

```text
Input: s = " 3+5 / 2 "
Output: 5
```

## Constraints

- 1 <= s.length <= 3 * 105
- s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
- s represents a valid expression.
- All the integers in the expression are non-negative integers in the range [0, 231 - 1].
- The answer is guaranteed to fit in a 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Evaluate Valid Expressions](https://leetcode.com/problems/evaluate-valid-expressions/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 227. Basic Calculator II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Stack | C++, Java |
| Optimised Approach without the stack | C++, Java |

## Approach 1: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp

class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0) return 0;
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (stack.size() != 0) {
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int calculate(String s) {

        if (s == null || s.isEmpty()) return 0;
        int len = s.length();
        Stack<Integer> stack = new Stack<Integer>();
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; i++) {
            char currentChar = s.charAt(i);
            if (Character.isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!Character.isDigit(currentChar) && !Character.isWhitespace(currentChar) || i == len - 1) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                }
                else if (operation == '+') {
                    stack.push(currentNumber);
                }
                else if (operation == '*') {
                    stack.push(stack.pop() * currentNumber);
                }
                else if (operation == '/') {
                    stack.push(stack.pop() / currentNumber);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
}
```

</details>

<br>

## Approach 2: Optimised Approach without the stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } else if (sign == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (sign == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int calculate(String s) {
        if (s == null || s.isEmpty()) return 0;
        int length = s.length();
        int currentNumber = 0, lastNumber = 0, result = 0;
        char operation = '+';
        for (int i = 0; i < length; i++) {
            char currentChar = s.charAt(i);
            if (Character.isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if (!Character.isDigit(currentChar) && !Character.isWhitespace(currentChar) || i == length - 1) {
                if (operation == '+' || operation == '-') {
                    result += lastNumber;
                    lastNumber = (operation == '+') ? currentNumber : -currentNumber;
                } else if (operation == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else if (operation == '/') {
                    lastNumber = lastNumber / currentNumber;
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;
    }
}
```

</details>
