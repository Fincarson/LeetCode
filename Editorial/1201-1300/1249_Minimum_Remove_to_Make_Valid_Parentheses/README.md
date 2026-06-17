# 1249. Minimum Remove to Make Valid Parentheses

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)  
`String` `Stack`

**Problem Link:** [LeetCode 1249 - Minimum Remove to Make Valid Parentheses](https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/)

## Problem

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

### Example 1

```text
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

### Example 2

```text
Input: s = "a)b(c)d"
Output: "ab(c)d"
```

### Example 3

```text
Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either '(' , ')', or lowercase English letter.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Check if a Parentheses String Can Be Valid](https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1249. Minimum Remove to Make Valid Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using a Stack and String Builder | Java, Python3 |
| Two Pass String Builder | Java, Python3 |
| Shortened Two Pass String Builder | Java, Python3 |

## Approach 1: Using a Stack and String Builder

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String minRemoveToMakeValid(String s) {
        Set<Integer> indexesToRemove = new HashSet<>();
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } if (s.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    indexesToRemove.add(i);
                } else {
                    stack.pop();
                }
            }
        }
        // Put any indexes remaining on stack into the set.
        while (!stack.isEmpty()) indexesToRemove.add(stack.pop());
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!indexesToRemove.contains(i)) {
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        indexes_to_remove = set()
        stack = []
        for i, c in enumerate(s):
            if c not in "()":
                continue
            if c == "(":
                stack.append(i)
            elif not stack:
                indexes_to_remove.add(i)
            else:
                stack.pop()
        indexes_to_remove = indexes_to_remove.union(set(stack))
        string_builder = []
        for i, c in enumerate(s):
            if i not in indexes_to_remove:
                string_builder.append(c)
        return "".join(string_builder)
```

</details>

<br>

## Approach 2: Two Pass String Builder

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private StringBuilder removeInvalidClosing(CharSequence string, char open, char close) {
        StringBuilder sb = new StringBuilder();
        int balance = 0;
        for (int i = 0; i < string.length(); i++) {
            char c = string.charAt(i);
            if (c == open) {
                balance++;
            } if (c == close) {
                if (balance == 0) continue;
                balance--;
            }
            sb.append(c);
        }  
        return sb;
    }

    public String minRemoveToMakeValid(String s) {
        StringBuilder result = removeInvalidClosing(s, '(', ')');
        result = removeInvalidClosing(result.reverse(), ')', '(');
        return result.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:

        def delete_invalid_closing(string, open_symbol, close_symbol):
            sb = []
            balance = 0
            for c in string:
                if c == open_symbol:
                    balance += 1
                if c == close_symbol:
                    if balance == 0:
                        continue
                    balance -= 1
                sb.append(c)
            return "".join(sb)

        # Note that s[::-1] gets the reverse of s.
        s = delete_invalid_closing(s, "(", ")")
        s = delete_invalid_closing(s[::-1], ")", "(")
        return s[::-1]
```

</details>

<br>

## Approach 3: Shortened Two Pass String Builder

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String minRemoveToMakeValid(String s) {

        // Pass 1: Remove all invalid ")"
        StringBuilder sb = new StringBuilder();
        int openSeen = 0;
        int balance = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                openSeen++;
                balance++;
            } if (c == ')') {
                if (balance == 0) continue;
                balance--;
            }
            sb.append(c);
        }

        // Pass 2: Remove the rightmost "("
        StringBuilder result = new StringBuilder();
        int openToKeep = openSeen - balance;
        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c == '(') {
                openToKeep--;
                if (openToKeep < 0) continue;
            }
            result.append(c);
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        # Pass 1: Remove all invalid ")"
        first_pass_chars = []
        balance = 0
        open_seen = 0
        for c in s:
            if c == "(":
                balance += 1
                open_seen += 1
            if c == ")":
                if balance == 0:
                    continue
                balance -= 1
            first_pass_chars.append(c)

        # Pass 2: Remove the rightmost "("
        result = []
        open_to_keep = open_seen - balance
        for c in first_pass_chars:
            if c == "(":
                open_to_keep -= 1
                if open_to_keep < 0:
                    continue
            result.append(c)

        return "".join(result)
```

</details>
