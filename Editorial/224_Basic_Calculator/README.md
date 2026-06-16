# 224. Basic Calculator

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/basic-calculator/)  
`Math` `String` `Stack` `Recursion`

**Problem Link:** [LeetCode 224 - Basic Calculator](https://leetcode.com/problems/basic-calculator/)

## Problem

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

### Example 1

```text
Input: s = "1 + 1"
Output: 2
```

### Example 2

```text
Input: s = " 2-1 + 2 "
Output: 3
```

### Example 3

```text
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
```

## Constraints

- 1 <= s.length <= 3 * 105
- s consists of digits, '+', '-', '(', ')', and ' '.
- s represents a valid expression.
- '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
- '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
- There will be no two consecutive operators in the input.
- Every number and running calculation will fit in a signed 32-bit integer.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Basic Calculator II](https://leetcode.com/problems/basic-calculator-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Different Ways to Add Parentheses](https://leetcode.com/problems/different-ways-to-add-parentheses/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Expression Add Operators](https://leetcode.com/problems/expression-add-operators/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [The Score of Students Solving Math Expression](https://leetcode.com/problems/the-score-of-students-solving-math-expression/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Minimize Result by Adding Parentheses to Expression](https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 224. Basic Calculator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack and String Reversal | Java, Python3 |
| Stack and No String Reversal | Java, Python3 |

## Approach 1: Stack and String Reversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int evaluateExpr(Stack<Object> stack) {
        
        // If stack is empty or the expression starts with
        // a symbol, then append 0 to the stack.
        // i.e. [1, '-', 2, '-'] becomes [1, '-', 2, '-', 0]
        if (stack.empty() || !(stack.peek() instanceof Integer)) {
            stack.push(0);
        }

        int res = (int) stack.pop();

        // Evaluate the expression till we get corresponding ')'
        while (!stack.empty() && !((char) stack.peek() == ')')) {

            char sign = (char) stack.pop();

            if (sign == '+') {
                res += (int) stack.pop();
            } else {
                res -= (int) stack.pop();
            }
        }
        return res;
    }

    public int calculate(String s) {

        int operand = 0;
        int n = 0;
        Stack<Object> stack = new Stack<Object>();

        for (int i = s.length() - 1; i >= 0; i--) {

            char ch = s.charAt(i);

            if (Character.isDigit(ch)) {

                // Forming the operand - in reverse order.
                operand = (int) Math.pow(10, n) * (int) (ch - '0') + operand;
                n += 1;

            } else if (ch != ' ') {
                if (n != 0) {

                    // Save the operand on the stack
                    // As we encounter some non-digit.
                    stack.push(operand);
                    n = 0;
                    operand = 0;

                }
                if (ch == '(') {

                    int res = evaluateExpr(stack);
                    stack.pop();

                    // Append the evaluated result to the stack.
                    // This result could be of a sub-expression within the parenthesis.
                    stack.push(res);

                } else {
                    // For other non-digits just push onto the stack.
                    stack.push(ch);
                }
            }
        }

        //Push the last operand to stack, if any.
        if (n != 0) {
            stack.push(operand);
        }

        // Evaluate any left overs in the stack.
        return evaluateExpr(stack);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def evaluate_expr(self, stack):
        
        # If stack is empty or the expression starts with
        # a symbol, then append 0 to the stack.
        # i.e. [1, '-', 2, '-'] becomes [1, '-', 2, '-', 0]
        if not stack or type(stack[-1]) == str:
            stack.append(0)
            
        res = stack.pop()

        # Evaluate the expression till we get corresponding ')'
        while stack and stack[-1] != ')':
            sign = stack.pop()
            if sign == '+':
                res += stack.pop()
            else:
                res -= stack.pop()
        return res       

    def calculate(self, s: str) -> int:

        stack = []
        n, operand = 0, 0

        for i in range(len(s) - 1, -1, -1):
            ch = s[i]

            if ch.isdigit():

                # Forming the operand - in reverse order.
                operand = (10**n * int(ch)) + operand
                n += 1

            elif ch != " ":
                if n:
                    # Save the operand on the stack
                    # As we encounter some non-digit.
                    stack.append(operand)
                    n, operand = 0, 0

                if ch == '(':         
                    res = self.evaluate_expr(stack)
                    stack.pop()        

                    # Append the evaluated result to the stack.
                    # This result could be of a sub-expression within the parenthesis.
                    stack.append(res)

                # For other non-digits just push onto the stack.
                else:
                    stack.append(ch)

        # Push the last operand to stack, if any.
        if n:
            stack.append(operand)

        # Evaluate any left overs in the stack.
        return self.evaluate_expr(stack)
```

</details>

<br>

## Approach 2: Stack and No String Reversal

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int calculate(String s) {

        Stack<Integer> stack = new Stack<Integer>();
        int operand = 0;
        int result = 0; // For the on-going result
        int sign = 1;  // 1 means positive, -1 means negative

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);
            if (Character.isDigit(ch)) {

                // Forming operand, since it could be more than one digit
                operand = 10 * operand + (int) (ch - '0');

            } else if (ch == '+') {

                // Evaluate the expression to the left,
                // with result, sign, operand
                result += sign * operand;

                // Save the recently encountered '+' sign
                sign = 1;

                // Reset operand
                operand = 0;

            } else if (ch == '-') {

                result += sign * operand;
                sign = -1;
                operand = 0;

            } else if (ch == '(') {

                // Push the result and sign on to the stack, for later
                // We push the result first, then sign
                stack.push(result);
                stack.push(sign);

                // Reset operand and result, as if new evaluation begins for the new sub-expression
                sign = 1;
                result = 0;

            } else if (ch == ')') {

                // Evaluate the expression to the left
                // with result, sign and operand
                result += sign * operand;

                // ')' marks end of expression within a set of parenthesis
                // Its result is multiplied with sign on top of stack
                // as stack.pop() is the sign before the parenthesis
                result *= stack.pop();

                // Then add to the next operand on the top.
                // as stack.pop() is the result calculated before this parenthesis
                // (operand on stack) + (sign on stack * (result from parenthesis))
                result += stack.pop();

                // Reset the operand
                operand = 0;
            }
        }
        return result + (sign * operand);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def calculate(self, s: str) -> int:

        stack = []
        operand = 0
        res = 0 # For the on-going result
        sign = 1 # 1 means positive, -1 means negative  

        for ch in s:
            if ch.isdigit():

                # Forming operand, since it could be more than one digit
                operand = (operand * 10) + int(ch)

            elif ch == '+':

                # Evaluate the expression to the left,
                # with result, sign, operand
                res += sign * operand

                # Save the recently encountered '+' sign
                sign = 1

                # Reset operand
                operand = 0

            elif ch == '-':

                res += sign * operand
                sign = -1
                operand = 0

            elif ch == '(':

                # Push the result and sign on to the stack, for later
                # We push the result first, then sign
                stack.append(res)
                stack.append(sign)

                # Reset operand and result, as if new evaluation begins for the new sub-expression
                sign = 1
                res = 0

            elif ch == ')':

                # Evaluate the expression to the left
                # with result, sign and operand
                res += sign * operand

                # ')' marks end of expression within a set of parenthesis
                # Its result is multiplied with sign on top of stack
                # as stack.pop() is the sign before the parenthesis
                res *= stack.pop() # stack pop 1, sign

                # Then add to the next operand on the top.
                # as stack.pop() is the result calculated before this parenthesis
                # (operand on stack) + (sign on stack * (result from parenthesis))
                res += stack.pop() # stack pop 2, operand

                # Reset the operand
                operand = 0

        return res + sign * operand
```

</details>
