# 709. To Lower Case

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/to-lower-case/)  
`String`

**Problem Link:** [LeetCode 709 - To Lower Case](https://leetcode.com/problems/to-lower-case/)

## Problem

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

### Example 1

```text
Input: s = "Hello"
Output: "hello"
```

### Example 2

```text
Input: s = "here"
Output: "here"
```

### Example 3

```text
Input: s = "LOVELY"
Output: "lovely"
```

## Constraints

- 1 <= s.length <= 100
- s consists of printable ASCII characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capitalize the Title](https://leetcode.com/problems/capitalize-the-title/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 709. To Lower Case

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| HashMap | Java, Python |
| Implementation of Python Function lower | Java, Python |

## Approach 1: HashMap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String toLowerCase(String s) {
        Map<Character, Character> h = new HashMap();
        String upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lower = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < 26; ++i) {
            h.put(upper.charAt(i), lower.charAt(i));
        }

        StringBuilder sb = new StringBuilder();
        for (char x : s.toCharArray()) {
            sb.append(h.containsKey(x) ? h.get(x) : x);
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def toLowerCase(self, s: str) -> str:
        upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        lower = "abcdefghijklmnopqrstuvwxyz"
        h = dict(zip(upper, lower))
        
        return ''.join([h[x] if x in h else x for x in s])
```

</details>

<br>

## Approach 2: Implementation of Python Function lower

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isUpper(char x) {
        return 'A' <= x && x <= 'Z';
    }

    public char toLower(char x) {
        return (char) ((int)x | 32);
    }

    public String toLowerCase(String s) {
        StringBuilder sb = new StringBuilder();
        for (char x : s.toCharArray()) {
            sb.append(isUpper(x) ? toLower(x) : x);
        }
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def toLowerCase(self, s: str) -> str: 
        is_upper = lambda x : 'A' <= x <= 'Z'
        to_lower = lambda x : chr(ord(x) | 32)
        
        return ''.join([to_lower(x) if is_upper(x) else x for x in s])
```

</details>
