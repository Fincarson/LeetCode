# 678. Valid Parenthesis String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/valid-parenthesis-string/)  
`String` `Dynamic Programming` `Stack` `Greedy`

**Problem Link:** [LeetCode 678 - Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/)

## Problem

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

### Example 1

```text
Input: s = "()"
Output: true
```

### Example 2

```text
Input: s = "(*)"
Output: true
```

### Example 3

```text
Input: s = "(*))"
Output: true
```

## Constraints

- 1 <= s.length <= 100
- s[i] is '(', ')' or '*'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Special Binary String](https://leetcode.com/problems/special-binary-string/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 678. Valid Parenthesis String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down Dynamic Programming - Memoization | C++, Java, Python3 |
| Bottom-Up Dynamic Programming - Tabulation | C++, Java, Python3 |
| Using Two Stacks | C++, Java, Python3 |
| Two Pointer | C++, Java, Python3 |

## Approach 1: Top-Down Dynamic Programming - Memoization

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public: 
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        return isValidString(0, 0, s, memo);
    }
private: 
    bool isValidString(int index, int openCount,
        const string & str, vector < vector < int >> & memo) {
        // If reached end of the string, check if all brackets are balanced
        if (index == str.size()) {
            return (openCount == 0);
        }

        // If already computed, return memoized result
        if (memo[index][openCount] != -1) {
            return memo[index][openCount];
        }

        bool isValid = false;
        // If encountering '*', try all possibilities
        if (str[index] == '*') {
            isValid |= isValidString(index + 1, openCount + 1, str, memo); // Treat '*' as '('
            if (openCount) {
                isValid |= isValidString(index + 1, openCount - 1, str, memo); // Treat '*' as ')'
            }
            isValid |= isValidString(index + 1, openCount, str, memo); // Treat '*' as empty
        } else {
            // Handle '(' and ')'
            if (str[index] == '(') {
                isValid = isValidString(index + 1, openCount + 1, str, memo); // Increment count for '('
            } else if (openCount) {
                isValid = isValidString(index + 1, openCount - 1, str, memo); // Decrement count for ')'
            }
        }

        // Memoize and return the result
        return memo[index][openCount] = isValid;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int[][] memo = new int[n][n];
        for (int[] row: memo) {
            Arrays.fill(row, -1);
        }
        return isValidString(0, 0, s, memo);
    }

    private boolean isValidString(int index, int openCount, String str, int[][] memo) {
        // If reached end of the string, check if all brackets are balanced
        if (index == str.length()) {
            return (openCount == 0);
        }
        // If already computed, return memoized result
        if (memo[index][openCount] != -1) {
            return memo[index][openCount] == 1;
        }
        boolean isValid = false;
        // If encountering '*', try all possibilities
        if (str.charAt(index) == '*') {
            isValid |= isValidString(index + 1, openCount + 1, str, memo); // Treat '*' as '('
            if (openCount > 0) {
                isValid |= isValidString(index + 1, openCount - 1, str, memo); // Treat '*' as ')'
            }
            isValid |= isValidString(index + 1, openCount, str, memo); // Treat '*' as empty
        } else {
            // Handle '(' and ')'
            if (str.charAt(index) == '(') {
                isValid = isValidString(index + 1, openCount + 1, str, memo); // Increment count for '('
            } else if (openCount > 0) {
                isValid = isValidString(index + 1, openCount - 1, str, memo); // Decrement count for ')'
            }
        }

        // Memoize and return the result
        memo[index][openCount] = isValid ? 1 : 0;
        return isValid;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        memo = [[-1] * n for _ in range(n)]
        return self.is_valid_string(0, 0, s, memo)

    def is_valid_string(self, index: int, open_count: int, s: str, memo: List[List[int]]) -> bool:
        # If reached end of the string, check if all brackets are balanced
        if index == len(s):
            return open_count == 0

        # If already computed, return memoized result
        if memo[index][open_count] != -1:
            return memo[index][open_count] == 1

        is_valid = False
        # If encountering '*', try all possibilities
        if s[index] == '*':
            is_valid |= self.is_valid_string(index + 1, open_count + 1, s, memo)  # Treat '*' as '('
            if open_count > 0:
                is_valid |= self.is_valid_string(index + 1, open_count - 1, s, memo)  # Treat '*' as ')'
            is_valid |= self.is_valid_string(index + 1, open_count, s, memo)  # Treat '*' as empty
        else:
            # Handle '(' and ')'
            if s[index] == '(':
                is_valid = self.is_valid_string(index + 1, open_count + 1, s, memo)  # Increment count for '('
            elif open_count > 0:
                is_valid = self.is_valid_string(index + 1, open_count - 1, s, memo)  # Decrement count for ')'

        # Memoize and return the result
        memo[index][open_count] = 1 if is_valid else 0
        return is_valid
```

</details>

<br>

## Approach 2: Bottom-Up Dynamic Programming - Tabulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        // dp[index][openBracket] represents if the substring starting from index i is valid with j opening brackets
        vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
        // base case: an empty string with 0 opening brackets is valid
        dp[n][0] = true;

        for (int index = n - 1; index >= 0; index--) {
            for (int openBracket = 0; openBracket <= n; openBracket++) {
                bool isValid = false;

                // '*' can represent '(' or ')' or '' (empty)
                if (s[index] == '*') {
                    isValid |= dp[index + 1][openBracket + 1]; // try '*' as '('

                    // opening brackets to use '*' as ')'
                    if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try '*' as ')'
                    }
                    isValid |= dp[index + 1][openBracket]; // ignore '*'
                } else {
                    // If the character is not '*', it can be '(' or ')'
                    if (s[index] == '(') {
                        isValid |= dp[index + 1][openBracket + 1]; // try '('
                    } else if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try ')'
                    }
                }
                dp[index][openBracket] = isValid;
            }
        }

        return dp[0][0]; // True if the entire string is valid with no excess opening brackets
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        // dp[i][j] represents if the substring starting from index i is valid with j opening brackets
        boolean[][] dp = new boolean[n + 1][n + 1];

        // base case: an empty string with 0 opening brackets is valid
        dp[n][0] = true;

        for (int index = n - 1; index >= 0; index--) {
            for (int openBracket = 0; openBracket < n; openBracket++) {
                boolean isValid = false;

                // '*' can represent '(' or ')' or '' (empty)
                if (s.charAt(index) == '*') {
                    isValid |= dp[index + 1][openBracket + 1]; // try '*' as '('
                    // opening brackets to use '*' as ')'
                    if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try '*' as ')'
                    }
                    isValid |= dp[index + 1][openBracket]; // ignore '*'
                } else {
                    // If the character is not '*', it can be '(' or ')'
                    if (s.charAt(index) == '(') {
                        isValid |= dp[index + 1][openBracket + 1]; // try '('
                    } else if (openBracket > 0) {
                        isValid |= dp[index + 1][openBracket - 1]; // try ')'
                    }
                }
                dp[index][openBracket] = isValid;
            }
        }

        return dp[0][0]; // check if the entire string is valid with no excess opening brackets
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        # dp[i][j] represents if the substring starting from index i is valid with j opening brackets
        dp = [[False] * (n + 1) for _ in range(n + 1)]

        # base case: an empty string with 0 opening brackets is valid
        dp[n][0] = True

        for index in range(n - 1, -1, -1):
            for open_bracket in range(n):
                is_valid = False

                # '*' can represent '(' or ')' or '' (empty)
                if s[index] == '*':
                    if open_bracket < n:
                        is_valid |= dp[index + 1][open_bracket + 1]  # try '*' as '('
                    # opening brackets to use '*' as ')'
                    if open_bracket > 0:
                        is_valid |= dp[index + 1][open_bracket - 1]  # try '*' as ')'
                    is_valid |= dp[index + 1][open_bracket]  # ignore '*'
                else:
                    # If the character is not '*', it can be '(' or ')'
                    if s[index] == '(':
                        is_valid |= dp[index + 1][open_bracket + 1]  # try '('
                    elif open_bracket > 0:
                        is_valid |= dp[index + 1][open_bracket - 1]  # try ')'
                dp[index][open_bracket] = is_valid

        return dp[0][0]  # check if the entire string is valid with no excess opening brackets
```

</details>

<br>

## Approach 3: Using Two Stacks

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openBrackets; // Stack to store indices of open brackets
        stack<int> asterisks; // Stack to store indices of asterisks

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            // If current character is an open bracket, push its index onto the stack
            if (ch == '(') {
                openBrackets.push(i);
                // If current character is an asterisk, push its index onto the stack
            } else if (ch == '*') {
                asterisks.push(i);
                // current character is a closing bracket ')'
            } else {
                // If there are open brackets available, use them to balance the closing bracket
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                    // If no open brackets are available, use an asterisk to balance the closing bracket
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                    // Unmatched ')' and no '*' to balance it.
                } else {
                    return false;
                }
            }
        }

        // Check if there are remaining open brackets and asterisks that can balance them
        while (!openBrackets.empty() && !asterisks.empty()) {
            // If an open bracket appears after an asterisk, it cannot be balanced, return false
            if (openBrackets.top() > asterisks.top()) {
                return false; // '*' before '(' which cannot be balanced.
            }
            openBrackets.pop();
            asterisks.pop();
        }

        // If all open brackets are matched and there are no unmatched open brackets left, return true
        return openBrackets.empty();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkValidString(String s) {
        // Stacks to store indices of open brackets and asterisks
        Stack<Integer> openBrackets = new Stack < > ();
        Stack<Integer> asterisks = new Stack < > ();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            // If current character is an open bracket, push its index onto the stack
            if (ch == '(') {
                openBrackets.push(i);
            }
            // If current character is an asterisk, push its index onto the stack
            else if (ch == '*') {
                asterisks.push(i);
                // current character is a closing bracket ')'
            } else {
                // If there are open brackets available, use them to balance the closing bracket
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                // If no open brackets are available, use an asterisk to balance the closing bracket
                } else if (!asterisks.isEmpty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }

        // Check if there are remaining open brackets and asterisks that can balance them
        while (!openBrackets.isEmpty() && !asterisks.isEmpty()) {
            // If an open bracket appears after an asterisk, it cannot be balanced, return false
            if (openBrackets.pop() > asterisks.pop()) {
                return false; // '*' before '(' which cannot be balanced.
            }
        }

        // If all open brackets are matched and there are no unmatched open brackets left, return true
        return openBrackets.isEmpty();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        # Stacks to store indices of open brackets and asterisks
        open_brackets = []
        asterisks = []

        for i, ch in enumerate(s):
            # If current character is an open bracket, push its index onto the stack
            if ch == "(":
                open_brackets.append(i)
            # If current character is an asterisk, push its index onto the stack
            elif ch == "*":
                asterisks.append(i)
            # current character is a closing bracket ')'
            else:
                # If there are open brackets available, use them to balance the closing bracket
                if open_brackets:
                    open_brackets.pop()
                elif asterisks:
                    # If no open brackets are available, use an asterisk to balance the closing bracket
                    asterisks.pop()
                else:
                    # nnmatched ')' and no '*' to balance it.
                    return False

        # Check if there are remaining open brackets and asterisks that can balance them
        while open_brackets and asterisks:
            # If an open bracket appears after an asterisk, it cannot be balanced, return false
            if open_brackets.pop() > asterisks.pop():
                return False  # '*' before '(' which cannot be balanced.

        # If all open brackets are matched and there are no unmatched open brackets left, return true
        return not open_brackets
```

</details>

<br>

## Approach 4: Two Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s[length - i] == ')' || s[length - i] == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkValidString(String s) {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;
        
        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++) {
            // Count open parentheses or asterisks
            if (s.charAt(i) == '(' || s.charAt(i) == '*') {
                openCount++;
            } else {
                openCount--;
            }
            
            // Count close parentheses or asterisks
            if (s.charAt(length - i) == ')' || s.charAt(length - i) == '*') {
                closeCount++;
            } else {
                closeCount--;
            }
            
            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0) {
                return false;
            }
        }
        
        // If open count and close count are both non-negative, the string is valid
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkValidString(self, s: str) -> bool:
        open_count = 0
        close_count = 0
        length = len(s) - 1
        
        # Traverse the string from both ends simultaneously
        for i in range(length + 1):
            # Count open parentheses or asterisks
            if s[i] == '(' or s[i] == '*':
                open_count += 1
            else:
                open_count -= 1
            
            # Count close parentheses or asterisks
            if s[length - i] == ')' or s[length - i] == '*':
                close_count += 1
            else:
                close_count -= 1
            
            # If at any point open count or close count goes negative, the string is invalid
            if open_count < 0 or close_count < 0:
                return False
        
        # If open count and close count are both non-negative, the string is valid
        return True
```

</details>
