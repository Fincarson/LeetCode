# 344. Reverse String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-string/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 344 - Reverse String](https://leetcode.com/problems/reverse-string/)

## Problem

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

### Example 1

```text
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

### Example 2

```text
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

## Constraints

- 1 <= s.length <= 105
- s[i] is a printable ascii character.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Reverse String II](https://leetcode.com/problems/reverse-string-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 344. Reverse String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion, In-Place, $$\mathcal{O}(N)$$ Space | Java, Python |
| Two Pointers, Iteration, $$\mathcal{O}(1)$$ Space | Java, Python |

## Approach 1: Recursion, In-Place, $$\mathcal{O}(N)$$ Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public void helper(char[] s, int left, int right) {
    if (left >= right) return;
    char tmp = s[left];
    s[left++] = s[right];
    s[right--] = tmp;
    helper(s, left, right);
  }

  public void reverseString(char[] s) {
    helper(s, 0, s.length - 1);
  }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def reverseString(self, s):
        def helper(left, right):
            if left < right:
                s[left], s[right] = s[right], s[left]
                helper(left + 1, right - 1)

        helper(0, len(s) - 1)
```

</details>

<br>

## Approach 2: Two Pointers, Iteration, $$\mathcal{O}(1)$$ Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def reverseString(self, s):
        left, right = 0, len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left, right = left + 1, right - 1
```

</details>
