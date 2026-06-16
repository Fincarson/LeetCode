# 186. Reverse Words in a String II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/reverse-words-in-a-string-ii/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 186 - Reverse Words in a String II](https://leetcode.com/problems/reverse-words-in-a-string-ii/)

## Problem

Given a character array s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by a single space.

Your code must solve the problem in-place, i.e. without allocating extra space.

### Example 1

```text
Input: s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
```

### Example 2

```text
Input: s = ["a"]
Output: ["a"]
```

## Constraints

- 1 <= s.length <= 105
- s[i] is an English letter (uppercase or lowercase), digit, or space ' '.
- There is at least one word in s.
- s does not contain leading or trailing spaces.
- All the words in s are guaranteed to be separated by a single space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Rotate Array](https://leetcode.com/problems/rotate-array/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 186. Reverse Words in a String II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Reverse the Whole String and Then Reverse Each Word | C++, Java, Python3 |

## Approach 1: Reverse the Whole String and Then Reverse Each Word

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:

    // Summary: Reverse entire string. Then reverse each word within the string.
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());

        // 'start' points to the beginning of the current word
        // 'end' points to the position just after the current word
        int start = 0, end = 0;
        int n = s.size();

        while (start < n) {

            // Move 'right' to the position just after the current word
            while (end < n && s[end] != ' ')
                end++;

            // Note: in C++, reverse() operates on [start, end)
            // In other words, the leftmost element is included, while the rightmost element is not
            reverse(s.begin() + start, s.begin() + end);

            // Move 'start' and 'end' to the beginning of the next word
            end++;
            start = end;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public void reverse(char[] s, int left, int right) {
        while (left < right) {
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }

    public void reverseEachWord(char[] s) {
        int n = s.length;
        int start = 0, end = 0;

        while (start < n) {
            // go to the end of the word
            while (end < n && s[end] != ' ') ++end;
            // reverse the word
            reverse(s, start, end - 1);
            // move to the next word
            start = end + 1;
            ++end;
        }
    }

    public void reverseWords(char[] s) {
        // reverse the whole string
        reverse(s, 0, s.length - 1);

        // reverse each word
        reverseEachWord(s);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverse(self, l: List[str], left: int, right: int) -> None:
        while left < right:
            l[left], l[right] = l[right], l[left]
            left, right = left + 1, right - 1

    def reverse_each_word(self, l: List[str]) -> None:
        n = len(l)
        start = end = 0

        while start < n:
            # go to the end of the word
            while end < n and l[end] != ' ':
                end += 1
            # reverse the word
            self.reverse(l, start, end - 1)
            # move to the next word
            start = end + 1
            end += 1
            
    def reverseWords(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # reverse the whole string
        self.reverse(s, 0, len(s) - 1)
        
        # reverse each word
        self.reverse_each_word(s)
```

</details>
