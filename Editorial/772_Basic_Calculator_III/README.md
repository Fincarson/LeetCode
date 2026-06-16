# 772. Basic Calculator III

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/basic-calculator-iii/)  
`Math` `String` `Stack` `Recursion`

**Problem Link:** [LeetCode 772 - Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/)

## Problem

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

### Example 1

```text
Input: s = "1+1"
Output: 2
```

### Example 2

```text
Input: s = "6-4/2"
Output: 4
```

### Example 3

```text
Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
```

## Constraints

- 1 <= s <= 104
- s consists of digits, '+', '-', '*', '/', '(', and ')'.
- s is a valid expression.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Basic Calculator](https://leetcode.com/problems/basic-calculator/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Basic Calculator IV](https://leetcode.com/problems/basic-calculator-iv/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Build Binary Expression Tree From Infix Expression](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 772. Basic Calculator III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | Java, Python3 |
| Solve Isolated Expressions With Recursion | Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int evaluate(char operator, int x, int y) {
        if (operator == '+') {
            return x;
        } else if (operator == '-') {
            return -x;
        } else if (operator == '*') {
            return x * y;
        }
        
        return x / y;
    }
    
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int curr = 0;
        char previousOperator = '+';
        s += "@";
        
        for (char c: s.toCharArray()) {
            if (c == ' ') {
                continue;
            }
            
            if (Character.isDigit(c)) {
                curr = curr * 10 + Character.getNumericValue(c);
            } else {
                if (previousOperator == '*' || previousOperator == '/') {
                    stack.push(evaluate(previousOperator, stack.pop(), curr));
                } else {
                    stack.push(evaluate(previousOperator, curr, 0));
                }
                
                curr = 0;
                previousOperator = c;
            }
        }
        
        int ans = 0;
        for (int num: stack) {
            ans += num;
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
    def calculate(self, s: str) -> int:
        def evaluate(operator, x, y = 0):
            if operator == "+":
                return x
            if operator == "-":
                return -x
            if operator == "*":
                return x * y
            return int(x / y)
        
        stack = []
        curr = 0
        previous_operator = "+"
        s += "@"
        
        for c in s:
            if c == " ":
                continue
            if c.isdigit():
                curr = curr * 10 + int(c)
            else:
                if previous_operator in "*/":
                    stack.append(evaluate(previous_operator, stack.pop(), curr))
                else:
                    stack.append(evaluate(previous_operator, curr))
                
                curr = 0
                previous_operator = c

        return sum(stack)
```

</details>

<br>

## Approach 2: Solve Isolated Expressions With Recursion

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int evaluate(char operator, int x, int y) {
        if (operator == '+') {
            return x;
        } else if (operator == '-') {
            return -x;
        } else if (operator == '*') {
            return x * y;
        }
        
        return x / y;
    }
    
    private int solve(String s, int[] i) {
        Stack<Integer> stack = new Stack<>();
        int curr = 0;
        char previousOperator = '+';
        
        while (i[0] < s.length()) {
            char c = s.charAt(i[0]);
            if (c == '(') {
                i[0]++;
                curr = solve(s, i);
            } else if (Character.isDigit(c)) {
                curr = curr * 10 + Character.getNumericValue(c);
            } else {
                if (previousOperator == '*' || previousOperator == '/') {
                    stack.push(evaluate(previousOperator, stack.pop(), curr));
                } else {
                    stack.push(evaluate(previousOperator, curr, 0));
                }
                
                if (c == ')') {
                    break;
                }
                
                curr = 0;
                previousOperator = c;
            }
            
            i[0]++;
        }
        
        int ans = 0;
        for (int num: stack) {
            ans += num;
        }
        
        return ans;
    }
    
    public int calculate(String s) {
        s += "@";
        int[] i = new int[1];
        return solve(s, i);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def calculate(self, s: str) -> int:
        def evaluate(x, y, operator):
            if operator == "+":
                return x
            if operator == "-":
                return -x
            if operator == "*":
                return x * y
            return int(x / y)
        
        def solve(i):
            stack = []
            curr = 0
            previous_operator = "+"
            
            while i[0] < len(s):
                c = s[i[0]]
                if c == "(":
                    i[0] += 1
                    curr = solve(i)
                elif c.isdigit():
                    curr = curr * 10 + int(c)
                else:
                    if previous_operator in "*/":
                        stack.append(evaluate(stack.pop(), curr, previous_operator))
                    else:
                        stack.append(evaluate(curr, 0, previous_operator))
                     
                    if c == ")":
                        break
                    
                    curr = 0
                    previous_operator = c
                    
                i[0] += 1
            
            return sum(stack)

        s += "@"
        return solve([0])
```

</details>
