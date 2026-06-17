# 1768. Merge Strings Alternately

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/merge-strings-alternately/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 1768 - Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)

## Problem

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

### Example 1

```text
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
```

### Example 2

```text
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
```

### Example 3

```text
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d
```

## Constraints

- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Zigzag Iterator](https://leetcode.com/problems/zigzag-iterator/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Additions to Make Valid String](https://leetcode.com/problems/minimum-additions-to-make-valid-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1768. Merge Strings Alternately

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, Java, Python3 |
| One Pointer | C++, Java, Python3 |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i < m) {
                result.push_back(word1[i++]);
            }
            if (j < n) {
                result.push_back(word2[j++]);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        StringBuilder result = new StringBuilder();
        int i = 0, j = 0;

        while (i < m || j < n) {
            if (i < m) {
                result.append(word1.charAt(i++));
            }
            if (j < n) {
                result.append(word2.charAt(j++));
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def mergeAlternately(self, word1, word2):
        m = len(word1)
        n = len(word2)
        i = 0
        j = 0
        result = []

        while i < m or j < n:
            if i < m:
                result += word1[i]
                i += 1
            if j < n:
                result += word2[j]
                j += 1

        return "".join(result)
```

</details>

<br>

## Approach 2: One Pointer

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";

        for (int i = 0; i < max(m, n); i++) {
            if (i < m) {
                result.push_back(word1[i]);
            }
            if (i < n) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < Math.max(m, n); i++) {
            if (i < m) {
                result.append(word1.charAt(i));
            }
            if (i < n) {
                result.append(word2.charAt(i));
            }
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def mergeAlternately(self, word1, word2):
        result = []
        n = max(len(word1), len(word2))
        for i in range(n):
            if i < len(word1):
                result += word1[i]
            if i < len(word2):
                result += word2[i]

        return "".join(result)
```

</details>
