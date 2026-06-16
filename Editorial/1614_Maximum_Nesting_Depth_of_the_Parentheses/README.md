# 1614. Maximum Nesting Depth of the Parentheses

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)  
`String` `Stack`

**Problem Link:** [LeetCode 1614 - Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

## Problem

Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 100
- s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
- It is guaranteed that parentheses expression s is a VPS.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Nesting Depth of Two Valid Parentheses Strings](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1614. Maximum Nesting Depth of the Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Counter variable | C++, Java, Python3 |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;

        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                st.pop();
            }
            
            ans = max(ans, (int)st.size());
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDepth(String s) {
        int ans = 0;

        Stack<Character> st = new Stack<Character>();
        for (Character c : s.toCharArray()) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                st.pop();
            }
            
            ans = Math.max(ans, st.size());
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
    def maxDepth(self, s: str) -> int:
        ans, st = 0, []
        for c in s:
            if c == '(':
                st.append(c)
            elif c == ')':
                st.pop()
            ans = max(ans, len(st))
        return ans
```

</details>

<br>

## Approach 2: Counter variable

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int openBrackets = 0;

        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }
            
            ans = max(ans, openBrackets);
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxDepth(String s) {
        int ans = 0;
        int openBrackets = 0;

        for (Character c : s.toCharArray()) {
            if (c == '(') {
                openBrackets++;
            } else if (c == ')') {
                openBrackets--;
            }

            ans = Math.max(ans, openBrackets);
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
    def maxDepth(self, s: str) -> int:
        ans, openBrackets = 0, 0
        for c in s:
            if c == '(':
                openBrackets += 1
            elif c == ')':
                openBrackets -= 1
            ans = max(ans, openBrackets)
        return ans
```

</details>
