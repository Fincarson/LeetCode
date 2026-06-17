# 434. Number of Segments in a String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/number-of-segments-in-a-string/)  
`String`

**Problem Link:** [LeetCode 434 - Number of Segments in a String](https://leetcode.com/problems/number-of-segments-in-a-string/)

## Problem

Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

### Example 1

```text
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
```

### Example 2

```text
Input: s = "Hello"
Output: 1
```

## Constraints

- 0 <= s.length <= 300
- s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
- The only space character in s is ' '.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 434. Number of Segments in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using Language Builtins [Accepted] | Java, Python |
| Approach #2 In-place [Accepted] | Java, Python |

## Approach #1 Using Language Builtins [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countSegments(String s) {
        String trimmed = s.trim();
        if (trimmed.equals("")) {
            return 0;
        }
        return trimmed.split("\\s+").length;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def countSegments(self, s):
        return len(s.split())
```

</details>

<br>

## Approach #2 In-place [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countSegments(String s) {
        int segmentCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }

        return segmentCount;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def countSegments(self, s):
        segment_count = 0

        for i in range(len(s)):
            if (i == 0 or s[i-1] == ' ') and s[i] != ' ':
                segment_count += 1

        return segment_count
```

</details>
