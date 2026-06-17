# 521. Longest Uncommon Subsequence I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/longest-uncommon-subsequence-i/)  
`String`

**Problem Link:** [LeetCode 521 - Longest Uncommon Subsequence I](https://leetcode.com/problems/longest-uncommon-subsequence-i/)

## Problem

Given two strings a and b, return the length of the longest uncommon subsequence between a and b. If no such uncommon subsequence exists, return -1.

An uncommon subsequence between two strings is a string that is a subsequence of exactly one of them.

### Example 1

```text
Input: a = "aba", b = "cdc"
Output: 3
Explanation: One longest uncommon subsequence is "aba" because "aba" is a subsequence of "aba" but not "cdc".
Note that "cdc" is also a longest uncommon subsequence.
```

### Example 2

```text
Input: a = "aaa", b = "bbb"
Output: 3
Explanation: The longest uncommon subsequences are "aaa" and "bbb".
```

### Example 3

```text
Input: a = "aaa", b = "aaa"
Output: -1
Explanation: Every subsequence of string a is also a subsequence of string b. Similarly, every subsequence of string b is also a subsequence of string a. So the answer would be -1.
```

## Constraints

- 1 <= a.length, b.length <= 100
- a and b consist of lower-case English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Uncommon Subsequence II](https://leetcode.com/problems/longest-uncommon-subsequence-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 521. Longest Uncommon Subsequence I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Maximum Length | C++, Java, Python3 |

## Approach: Maximum Length

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) {
            return -1;
        } else {
            return max(a.length(), b.length());
        }    
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int findLUSlength(String a, String b) {
        if (a.equals(b)) {
            return -1;
        } else {
            return Math.max(a.length(), b.length());
        }  
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        if a == b:
            return -1
        else:
            return max(len(a), len(b))
```

</details>
