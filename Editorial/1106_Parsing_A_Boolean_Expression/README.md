# 1106. Parsing A Boolean Expression

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/parsing-a-boolean-expression/)  
`String` `Stack` `Recursion`

**Problem Link:** [LeetCode 1106 - Parsing A Boolean Expression](https://leetcode.com/problems/parsing-a-boolean-expression/)

## Problem

A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

- 't' that evaluates to true.
- 'f' that evaluates to false.
- '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
- '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
- '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.

Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

### Example 1

```text
Input: expression = "&(|(f))"
Output: false
Explanation:
First, evaluate |(f) --> f. The expression is now "&(f)".
Then, evaluate &(f) --> f. The expression is now "f".
Finally, return false.
```

### Example 2

```text
Input: expression = "|(f,f,f,t)"
Output: true
Explanation: The evaluation of (false OR false OR false OR true) is true.
```

### Example 3

```text
Input: expression = "!(&(f,t))"
Output: true
Explanation:
First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
Then, evaluate !(f) --> NOT false --> true. We return true.
```

## Constraints

- 1 <= expression.length <= 2 * 104
- expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1106. Parsing A Boolean Expression

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| String Manipulation | C++, Java, Python3 |
| Recursive | C++, Java, Python3 |
| Using Stack | C++, Java, Python3 |
| Optimized Stack | C++, Java, Python3 |

## Approach 1: String Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        // Repeatedly simplify the expression by evaluating subexpressions
        while (expression.length() > 1) {
            int start = expression.find_last_of("!&|");
            int end = expression.find(')', start);
            string subExpr = expression.substr(start, end - start + 1);
            char result = evaluateSubExpr(subExpr);
            expression.replace(start, end - start + 1, 1,
                               result);  // Replace with evaluated result
        }
        return expression[0] == 't';
    }

private:
    char evaluateSubExpr(const string& subExpr) {
        // Extract the operator and the enclosed values
        char op = subExpr[0];
        string values = subExpr.substr(2, subExpr.length() - 3);

        // Apply logical operations based on the operator
        if (op == '!') return values[0] == 't' ? 'f' : 't';
        if (op == '&') return values.find('f') != string::npos ? 'f' : 't';
        if (op == '|') return values.find('t') != string::npos ? 't' : 'f';

        return 'f';  // This point should never be reached
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean parseBoolExpr(String expression) {
        // Repeatedly simplify the expression by evaluating subexpressions
        while (expression.length() > 1) {
            int start = Math.max(
                expression.lastIndexOf('!'),
                Math.max(
                    expression.lastIndexOf('&'),
                    expression.lastIndexOf('|')
                )
            );
            int end = expression.indexOf(')', start);
            String subExpr = expression.substring(start, end + 1);
            char result = evaluateSubExpr(subExpr);
            expression = expression.substring(0, start) +
            result +
            expression.substring(end + 1);
        }
        return expression.charAt(0) == 't';
    }

    private char evaluateSubExpr(String subExpr) {
        // Extract the operator and the enclosed values
        char op = subExpr.charAt(0);
        String values = subExpr.substring(2, subExpr.length() - 1);
        // Apply logical operations based on the operator
        if (op == '!') return values.charAt(0) == 't' ? 'f' : 't';
        if (op == '&') return values.contains("f") ? 'f' : 't';
        if (op == '|') return values.contains("t") ? 't' : 'f';
        return 'f'; // This point should never be reached
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        # Repeatedly simplify the expression by evaluating subexpressions
        while len(expression) > 1:
            start = max(
                expression.rfind("!"),
                expression.rfind("&"),
                expression.rfind("|"),
            )
            end = expression.find(")", start)
            sub_expr = expression[start : end + 1]
            result = self._evaluate_sub_expr(sub_expr)
            expression = expression[:start] + result + expression[end + 1 :]

        return expression == "t"

    def _evaluate_sub_expr(self, sub_expr: str) -> str:
        # Extract the operator and the enclosed values
        op = sub_expr[0]
        values = sub_expr[2:-1]

        # Apply logical operations based on the operator
        if op == "!":
            return "f" if values == "t" else "t"
        if op == "&":
            return "f" if "f" in values else "t"
        if op == "|":
            return "t" if "t" in values else "f"

        return "f"  # This point should never be reached
```

</details>

<br>

## Approach 2: Recursive

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression, index);
    }

private:
    // Recursively parse and evaluate the boolean expression
    bool evaluate(string& expr, int& index) {
        char currChar = expr[index++];

        // Base cases: true ('t') or false ('f')
        if (currChar == 't') return true;
        if (currChar == 'f') return false;

        // Handle NOT operation '!(...)'
        if (currChar == '!') {
            index++;  // Skip '('
            bool result = !evaluate(expr, index);
            index++;  // Skip ')'
            return result;
        }

        // Handle AND '&(...)' and OR '|(...)'
        vector<bool> values;
        index++;  // Skip '('
        while (expr[index] != ')') {
            if (expr[index] != ',') {
                values.push_back(evaluate(
                    expr, index));  // Collect results of subexpressions
            } else {
                index++;  // Skip commas
            }
        }
        index++;  // Skip ')'

        // Manual AND operation: returns false if any value is false
        if (currChar == '&') {
            for (bool v : values) {
                if (!v) return false;
            }
            return true;
        }

        // Manual OR operation: returns true if any value is true
        if (currChar == '|') {
            for (bool v : values) {
                if (v) return true;
            }
            return false;
        }

        return false;  // This point should never be reached
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    int index = 0;

    public boolean parseBoolExpr(String expression) {
        return evaluate(expression);
    }

    // Recursively parse and evaluate the boolean expression
    private boolean evaluate(String expr) {
        char currChar = expr.charAt(index++);

        // Base cases: true ('t') or false ('f')
        if (currChar == 't') return true;
        if (currChar == 'f') return false;

        // Handle NOT operation '!(...)'
        if (currChar == '!') {
            index++; // Skip '('
            boolean result = !evaluate(expr);
            index++; // Skip ')'
            return result;
        }

        // Handle AND '&(...)' and OR '|(...)'
        List<Boolean> values = new ArrayList<>();
        index++; // Skip '('
        while (expr.charAt(index) != ')') {
            if (expr.charAt(index) != ',') {
                values.add(evaluate(expr)); // Collect results of subexpressions
            } else {
                index++; // Skip commas
            }
        }
        index++; // Skip ')'

        // Manual AND operation: returns false if any value is false
        if (currChar == '&') {
            for (Boolean v : values) {
                if (!v) return false;
            }
            return true;
        }

        // Manual OR operation: returns true if any value is true
        if (currChar == '|') {
            for (Boolean v : values) {
                if (v) return true;
            }
            return false;
        }

        return false; // This point should never be reached
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        index = [
            0
        ]  # using a list because python variables are pass by object reference
        return self._evaluate(expression, index)

    # Recursively parse and evaluate the boolean expression
    def _evaluate(self, expr: str, index: list) -> bool:
        curr_char = expr[index[0]]
        index[0] += 1

        # Base cases: true ('t') or false ('f')
        if curr_char == "t":
            return True
        if curr_char == "f":
            return False

        # Handle NOT operation '!(...)'
        if curr_char == "!":
            index[0] += 1  # skip '('
            result = not self._evaluate(expr, index)
            index[0] += 1  # skip ')'
            return result

        # Handle AND '&(...)' and OR '|(...)'
        values = []
        index[0] += 1  # skip '('
        while expr[index[0]] != ")":
            if expr[index[0]] != ",":
                values.append(
                    self._evaluate(expr, index)
                )  # collect results of subexpressions
            else:
                index[0] += 1  # skip commas
        index[0] += 1  # skip ')'

        # Manual AND operation: returns false if any value is false
        if curr_char == "&":
            return all(values)

        # Manual OR operation: returns true if any value is true
        if curr_char == "|":
            return any(values)

        return False  # this point should never be reached
```

</details>

<br>

## Approach 3: Using Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        // Traverse the entire expression
        for (char currChar : expression) {
            if (currChar == ')') {
                vector<char> values;

                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator

                // Evaluate the subexpression and push the result back
                char result = evaluateSubExpr(op, values);
                st.push(result);
            } else if (currChar != ',') {
                st.push(currChar);  // Push non-comma characters into the stack
            }
        }

        // Final result is on the top of the stack
        return st.top() == 't';
    }

private:
    // Evaluates a subexpression based on the operator and list of values
    char evaluateSubExpr(char op, vector<char>& values) {
        if (op == '!') return values[0] == 't' ? 'f' : 't';

        // AND: return 'f' if any value is 'f', otherwise return 't'
        if (op == '&') {
            for (char value : values) {
                if (value == 'f') return 'f';
            }
            return 't';
        }

        // OR: return 't' if any value is 't', otherwise return 'f'
        if (op == '|') {
            for (char value : values) {
                if (value == 't') return 't';
            }
            return 'f';
        }

        return 'f';  // This point should never be reached
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();

        // Traverse the entire expression
        for (char currChar : expression.toCharArray()) {
            if (currChar == ')') {
                ArrayList<Character> values = new ArrayList<>();

                // Gather all values inside the parentheses
                while (st.peek() != '(') {
                    values.add(st.pop());
                }
                st.pop(); // Remove '('
                char op = st.pop(); // Remove the operator

                // Evaluate the subexpression and push the result back
                char result = evaluateSubExpr(op, values);
                st.push(result);
            } else if (currChar != ',') {
                st.push(currChar); // Push non-comma characters into the stack
            }
        }

        // Final result is on the top of the stack
        return st.peek() == 't';
    }

    // Evaluates a subexpression based on the operator and list of values
    private char evaluateSubExpr(char op, ArrayList<Character> values) {
        if (op == '!') return values.get(0) == 't' ? 'f' : 't';

        // AND: return 'f' if any value is 'f', otherwise return 't'
        if (op == '&') {
            for (char value : values) {
                if (value == 'f') return 'f';
            }
            return 't';
        }

        // OR: return 't' if any value is 't', otherwise return 'f'
        if (op == '|') {
            for (char value : values) {
                if (value == 't') return 't';
            }
            return 'f';
        }

        return 'f'; // This point should never be reached
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        st = deque()

        # Traverse the entire expression
        for curr_char in expression:
            if curr_char == ")":
                values = []

                # Gather all values inside the parentheses
                while st[-1] != "(":
                    values.append(st.pop())
                st.pop()  # Remove '('
                op = st.pop()  # Remove the operator

                # Evaluate the subexpression and push the result back
                result = self._evaluate_sub_expr(op, values)
                st.append(result)
            elif curr_char != ",":
                st.append(curr_char)  # Push non-comma characters into the stack

        # Final result is on the top of the stack
        return st[-1] == "t"

    # Evaluates a subexpression based on the operator and list of values
    def _evaluate_sub_expr(self, op, values):
        if op == "!":
            return "f" if values[0] == "t" else "t"

        # AND: return 'f' if any value is 'f', otherwise return 't'
        if op == "&":
            for value in values:
                if value == "f":
                    return "f"
            return "t"

        # OR: return 't' if any value is 't', otherwise return 'f'
        if op == "|":
            for value in values:
                if value == "t":
                    return "t"
            return "f"

        return "f"  # This point should never be reached
```

</details>

<br>

## Approach 4: Optimized Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        // Traverse through the expression
        for (char currChar : expression) {
            if (currChar == ',' || currChar == '(')
                continue;  // Skip commas and open parentheses

            // Push operators and boolean values to the stack
            if (currChar == 't' || currChar == 'f' || currChar == '!' ||
                currChar == '&' || currChar == '|') {
                st.push(currChar);
            }
            // Handle closing parentheses and evaluate the subexpression
            else if (currChar == ')') {
                bool hasTrue = false, hasFalse = false;

                // Process the values inside the parentheses
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char topValue = st.top();
                    st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                // Pop the operator and evaluate the subexpression
                char op = st.top();
                st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        // The final result is at the top of the stack
        return st.top() == 't';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean parseBoolExpr(String expression) {
        Stack<Character> st = new Stack<>();

        // Traverse through the expression
        for (char currChar : expression.toCharArray()) {
            if (currChar == ',' || currChar == '(') continue; // Skip commas and open parentheses

            // Push operators and boolean values to the stack
            if (
                currChar == 't' ||
                currChar == 'f' ||
                currChar == '!' ||
                currChar == '&' ||
                currChar == '|'
            ) {
                st.push(currChar);
            }
            // Handle closing parentheses and evaluate the subexpression
            else if (currChar == ')') {
                boolean hasTrue = false, hasFalse = false;

                // Process the values inside the parentheses
                while (
                    st.peek() != '!' && st.peek() != '&' && st.peek() != '|'
                ) {
                    char topValue = st.pop();
                    if (topValue == 't') hasTrue = true;
                    if (topValue == 'f') hasFalse = true;
                }

                // Pop the operator and evaluate the subexpression
                char op = st.pop();
                if (op == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (op == '&') {
                    st.push(hasFalse ? 'f' : 't');
                } else {
                    st.push(hasTrue ? 't' : 'f');
                }
            }
        }

        // The final result is at the top of the stack
        return st.peek() == 't';
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def parseBoolExpr(self, expression: str) -> bool:
        st = deque()

        # Traverse through the expression
        for curr_char in expression:
            if curr_char == "," or curr_char == "(":
                curr_char  # Skip commas and open parentheses

            # Push operators and boolean values to the stack
            if curr_char in ["t", "f", "!", "&", "|"]:
                st.append(curr_char)

            # Handle closing parentheses and evaluate the subexpression
            elif curr_char == ")":
                has_true = False
                has_false = False

                # Process the values inside the parentheses
                while st[-1] not in ["!", "&", "|"]:
                    top_value = st.pop()
                    if top_value == "t":
                        has_true = True
                    elif top_value == "f":
                        has_false = True

                # Pop the operator and evaluate the subexpression
                op = st.pop()
                if op == "!":
                    st.append("t" if not has_true else "f")
                elif op == "&":
                    st.append("f" if has_false else "t")
                else:
                    st.append("t" if has_true else "f")

        # The final result is at the top of the stack
        return st[-1] == "t"
```

</details>
