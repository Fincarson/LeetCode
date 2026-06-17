# 2116. Check if a Parentheses String Can Be Valid

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)  
`String` `Stack` `Greedy`

**Problem Link:** [LeetCode 2116 - Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/)

## Problem

A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,

- If locked[i] is '1', you cannot change s[i].
- But if locked[i] is '0', you can change s[i] to either '(' or ')'.

Return true if you can make s a valid parentheses string. Otherwise, return false.

### Example 1

```text
Input: s = "))()))", locked = "010100"
Output: true
Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
```

### Example 2

```text
Input: s = "()()", locked = "0000"
Output: true
Explanation: We do not need to make any changes because s is already valid.
```

### Example 3

```text
Input: s = ")", locked = "0"
Output: false
Explanation: locked permits us to change s[0].
Changing s[0] to either '(' or ')' will not make s valid.
```

### Example 4

```text
Input: s = "(((())(((())", locked = "111111010111"
Output: true
Explanation: locked permits us to change s[6] and s[8].
We change s[6] and s[8] to ')' to make s valid.
```

## Constraints

- n == s.length == locked.length
- 1 <= n <= 105
- s[i] is either '(' or ')'.
- locked[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [ Check if There Is a Valid Parentheses String Path](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2116. Check if a Parentheses String Can Be Valid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Constant Space | C++, Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.size();
        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }

        stack<int> openBrackets, unlocked;

        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < length; i++) {
            if (locked[i] == '0') {
                unlocked.push(i);
            } else if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining open brackets with unlocked characters
        while (!openBrackets.empty() && !unlocked.empty() &&
               openBrackets.top() < unlocked.top()) {
            openBrackets.pop();
            unlocked.pop();
        }

        if (!openBrackets.empty()) {
            return false;
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canBeValid(String s, String locked) {
        int length = s.length();

        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }

        Stack<Integer> openBrackets = new Stack<>();
        Stack<Integer> unlocked = new Stack<>();

        // Iterate through the string to handle '(' and ')'
        for (int i = 0; i < length; i++) {
            if (locked.charAt(i) == '0') {
                unlocked.push(i);
            } else if (s.charAt(i) == '(') {
                openBrackets.push(i);
            } else if (s.charAt(i) == ')') {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!unlocked.empty()) {
                    unlocked.pop();
                } else {
                    return false;
                }
            }
        }

        // Match remaining open brackets with unlocked characters
        while (
            !openBrackets.empty() &&
            !unlocked.empty() &&
            openBrackets.peek() < unlocked.peek()
        ) {
            openBrackets.pop();
            unlocked.pop();
        }

        if (!openBrackets.empty()) {
            return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeValid(self, s, locked):
        length = len(s)

        # If length of string is odd, return false.
        if length % 2 == 1:
            return False

        open_brackets = []
        unlocked = []

        # Iterate through the string to handle '(' and ')'
        for i in range(length):
            if locked[i] == "0":
                unlocked.append(i)
            elif s[i] == "(":
                open_brackets.append(i)
            elif s[i] == ")":
                if open_brackets:
                    open_brackets.pop()
                elif unlocked:
                    unlocked.pop()
                else:
                    return False

        # Match remaining open brackets and the unlocked characters
        while open_brackets and unlocked and open_brackets[-1] < unlocked[-1]:
            open_brackets.pop()
            unlocked.pop()

        if open_brackets:
            return False

        return True
```

</details>

<br>

## Approach 2: Constant Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int length = s.size();
        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }
        int openBrackets = 0, unlocked = 0;
        // Iterate through the string to handle '(' and ')'.
        for (int i = 0; i < length; i++) {
            if (locked[i] == '0') {
                unlocked++;
            } else if (s[i] == '(') {
                openBrackets++;
            } else if (s[i] == ')') {
                if (openBrackets > 0) {
                    openBrackets--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }
        // Match remaining open brackets with unlocked characters.
        int balance = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                balance--;
                unlocked--;
            } else if (s[i] == '(') {
                balance++;
                openBrackets--;
            } else if (s[i] == ')') {
                balance--;
            }
            if (balance > 0) {
                return false;
            }
        }

        if (openBrackets > 0) {
            return false;
        }

        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canBeValid(String s, String locked) {
        int length = s.length();

        // If length of string is odd, return false.
        if (length % 2 == 1) {
            return false;
        }
        int openBrackets = 0;
        int unlocked = 0;

        // Iterate through the string to handle '(' and ')'.
        for (int i = 0; i < length; i++) {
            if (locked.charAt(i) == '0') {
                unlocked++;
            } else if (s.charAt(i) == '(') {
                openBrackets++;
            } else if (s.charAt(i) == ')') {
                if (openBrackets > 0) {
                    openBrackets--;
                } else if (unlocked > 0) {
                    unlocked--;
                } else {
                    return false;
                }
            }
        }

        // Match remaining open brackets with unlocked characters.
        int balance = 0;
        for (int i = length - 1; i >= 0; i--) {
            if (locked.charAt(i) == '0') {
                balance--;
                unlocked--;
            } else if (s.charAt(i) == '(') {
                balance++;
                openBrackets--;
            } else if (s.charAt(i) == ')') {
                balance--;
            }
            if (balance > 0) {
                return false;
            }
        }

        if (openBrackets > 0) {
            return false;
        }

        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        length = len(s)
        # If length of string is odd, return false.
        if length % 2 == 1:
            return False
        open_brackets = 0
        unlocked_count = 0
        # Iterate through the string to handle '(' and ')'.
        for i in range(length):
            if locked[i] == "0":
                unlocked_count += 1
            elif s[i] == "(":
                open_brackets += 1
            elif s[i] == ")":
                if open_brackets > 0:
                    open_brackets -= 1
                elif unlocked_count > 0:
                    unlocked_count -= 1
                else:
                    return False

        # Match remaining open brackets with unlocked characters.
        balance_count = 0
        for i in range(length - 1, -1, -1):
            if locked[i] == "0":
                balance_count -= 1
                unlocked_count -= 1
            elif s[i] == "(":
                balance_count += 1
                open_brackets -= 1
            elif s[i] == ")":
                balance_count -= 1
            if balance_count > 0:
                return False

        if open_brackets > 0:
            return False

        return True
```

</details>
