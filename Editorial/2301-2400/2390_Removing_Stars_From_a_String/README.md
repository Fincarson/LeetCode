# 2390. Removing Stars From a String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/removing-stars-from-a-string/)  
`String` `Stack` `Simulation`

**Problem Link:** [LeetCode 2390 - Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/)

## Problem

You are given a string s, which contains stars *.

In one operation, you can:

- Choose a star in s.
- Remove the closest non-star character to its left, as well as remove the star itself.

Return the string after all stars have been removed.

Note:

- The input will be generated such that the operation is always possible.
- It can be shown that the resulting string will always be unique.

### Example 1

```text
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
```

### Example 2

```text
Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters and stars *.
- The operation above can be performed on s.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Remove All Adjacent Duplicates In String](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2390. Removing Stars From a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | C++, Java, Python3 |
| Strings | C++, Java |
| Two Pointers | C++, Java |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        string answer = "";
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String removeStars(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                st.pop();
            } else {
                st.push(s.charAt(i));
            }
        }

        StringBuilder answer = new StringBuilder();
        while (!st.isEmpty()) {
            answer.append(st.pop());
        }

        return answer.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeStars(self, s):
        st = []
        for i in range(0, len(s)):
            if s[i] == '*':
                st.pop()
            else:
                st.append(s[i])

        return ''.join(st)
```

</details>

<br>

## Approach 2: Strings

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeStars(string s) {
        string answer = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                answer.pop_back();
            } else {
                answer.push_back(s[i]);
            }
        }
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String removeStars(String s) {
        int j = 0;
        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                answer.deleteCharAt(answer.length() - 1);
            } else {
                answer.append(s.charAt(i));
            }
        }
        return answer.toString();
    }
}
```

</details>

<br>

## Approach 3: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeStars(string s) {
        vector<char> ch(s.size());
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                j--;
            } else {
                ch[j++] = s[i];
            }
        }

        string answer = "";
        for (int i = 0; i < j; i++) {
            answer.push_back(ch[i]);
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String removeStars(String s) {
        char[] ch = new char[s.length()];
        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '*') {
                j--;
            } else {
                ch[j++] = c;
            }
        }

        StringBuilder answer = new StringBuilder();
        for (int i = 0; i < j; i++) {
            answer.append(ch[i]);
        }

        return answer.toString();
    }
}
```

</details>
