# 921. Minimum Add to Make Parentheses Valid

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)  
`String` `Stack` `Greedy`

**Problem Link:** [LeetCode 921 - Minimum Add to Make Parentheses Valid](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

## Problem

A parentheses string is valid if and only if:

- It is the empty string,
- It can be written as AB (A concatenated with B), where A and B are valid strings, or
- It can be written as (A), where A is a valid string.

You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

- For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".

Return the minimum number of moves required to make s valid.

### Example 1

```text
Input: s = "())"
Output: 1
```

### Example 2

```text
Input: s = "((("
Output: 3
```

## Constraints

- 1 <= s.length <= 1000
- s[i] is either '(' or ')'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Minimum Number of Swaps to Make the String Balanced](https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 921. Minimum Add to Make Parentheses Valid

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Open Bracket Counter | C++, Java, Python3 |

## Approach: Open Bracket Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                // If open bracket exists, match it with the closing one
                // If not, we need to add a open bracket.
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }

        // Add the remaining open brackets as closing brackets would be
        // required.
        return minAddsRequired + openBrackets;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minAddToMakeValid(String s) {
        int openBrackets = 0;
        int minAddsRequired = 0;

        for (char c : s.toCharArray()) {
            if (c == '(') {
                openBrackets++;
            } else {
                // If an open bracket exists, match it with the closing one
                // If not, we need to add an open bracket.
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    minAddsRequired++;
                }
            }
        }

        // Add the remaining open brackets as closing brackets would be required.
        return minAddsRequired + openBrackets;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open_brackets = 0
        min_adds_required = 0

        for c in s:
            if c == "(":
                open_brackets += 1
            else:
                if open_brackets > 0:
                    open_brackets -= 1
                else:
                    min_adds_required += 1

        # Add the remaining open brackets as closing brackets would be required.
        return min_adds_required + open_brackets
```

</details>
