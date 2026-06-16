# 856. Score of Parentheses

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/score-of-parentheses/)  
`String` `Stack`

**Problem Link:** [LeetCode 856 - Score of Parentheses](https://leetcode.com/problems/score-of-parentheses/)

## Problem

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

- "()" has score 1.
- AB has score A + B, where A and B are balanced parentheses strings.
- (A) has score 2 * A, where A is a balanced parentheses string.

### Example 1

```text
Input: s = "()"
Output: 1
```

### Example 2

```text
Input: s = "(())"
Output: 2
```

### Example 3

```text
Input: s = "()()"
Output: 2
```

## Constraints

- 2 <= s.length <= 50
- s consists of only '(' and ')'.
- s is a balanced parentheses string.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 856. Score of Parentheses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide and Conquer | Java, Python |
| Stack | Java, Python |
| Count Cores | Java, Python |

## Approach 1: Divide and Conquer

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int scoreOfParentheses(String S) {
        return F(S, 0, S.length());
    }

    public int F(String S, int i, int j) {
        //Score of balanced string S[i:j]
        int ans = 0, bal = 0;

        // Split string into primitives
        for (int k = i; k < j; ++k) {
            bal += S.charAt(k) == '(' ? 1 : -1;
            if (bal == 0) {
                if (k - i == 1) ans++;
                else ans += 2 * F(S, i+1, k);
                i = k+1;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def scoreOfParentheses(self, S):
        def F(i, j):
            #Score of balanced string S[i:j]
            ans = bal = 0

            #Split string into primitives
            for k in xrange(i, j):
                bal += 1 if S[k] == '(' else -1
                if bal == 0:
                    if k - i == 1:
                        ans += 1
                    else:
                        ans += 2 * F(i+1, k)
                    i = k+1

            return ans

        return F(0, len(S))
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public int scoreOfParentheses(String S) {
    Stack<Integer> stack = new Stack();
    stack.push(0); // The score of the current frame

    for (char c: S.toCharArray()) {
        if (c == '(')
            stack.push(0);
        else {
            int v = stack.pop();
            int w = stack.pop();
            stack.push(w + Math.max(2 * v, 1));
        }
    }

    return stack.pop();
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def scoreOfParentheses(self, S):
        stack = [0] #The score of the current frame

        for x in S:
            if x == '(':
                stack.append(0)
            else:
                v = stack.pop()
                stack[-1] += max(2 * v, 1)

        return stack.pop()
```

</details>

<br>

## Approach 3: Count Cores

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int scoreOfParentheses(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == '(') {
                bal++;
            } else {
                bal--;
                if (S.charAt(i-1) == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def scoreOfParentheses(self, S):
        ans = bal = 0
        for i, x in enumerate(S):
            if x == '(':
                bal += 1
            else:
                bal -= 1
                if S[i-1] == '(':
                    ans += 1 << bal
        return ans
```

</details>
