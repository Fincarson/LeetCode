# 557. Reverse Words in a String III

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-words-in-a-string-iii/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 557 - Reverse Words in a String III](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

## Problem

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

### Example 1

```text
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

### Example 2

```text
Input: s = "Mr Ding"
Output: "rM gniD"
```

## Constraints

- 1 <= s.length <= 5 * 104
- s contains printable ASCII characters.
- s does not contain any leading or trailing spaces.
- There is at least one word in s.
- All the words in s are separated by a single space.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Reverse String II](https://leetcode.com/problems/reverse-string-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 557. Reverse Words in a String III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Traverse and Reverse each character one by one | C++, Java, Python3 |
| Using Two Pointers | C++, Java, Python3 |

## Approach 1: Traverse and Reverse each character one by one

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string result;
        int lastSpaceIndex = -1;
        for (int strIndex = 0; strIndex < s.length(); strIndex++) {
            if ((strIndex == s.length() - 1) || s[strIndex] == ' ') {
                int reverseStrIndex =
                    (strIndex == s.length() - 1) ? strIndex : strIndex - 1;
                for (; reverseStrIndex > lastSpaceIndex; reverseStrIndex--) {
                    result += s[reverseStrIndex];
                }
                if (strIndex != s.length() - 1) {
                    result += ' ';
                }
                lastSpaceIndex = strIndex;
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

    public String reverseWords(String s) {
        StringBuilder result = new StringBuilder();
        int lastSpaceIndex = -1;
        for (int strIndex = 0; strIndex < s.length(); strIndex++) {
            if ((strIndex == s.length() - 1) || s.charAt(strIndex) == ' ') {
                int reverseStrIndex = (strIndex == s.length() - 1) ? strIndex : strIndex - 1;
                for (; reverseStrIndex > lastSpaceIndex; reverseStrIndex--) {
                    result.append(s.charAt(reverseStrIndex));
                }
                if (strIndex != s.length() - 1) {
                    result.append(' ');
                }
                lastSpaceIndex = strIndex;
            }
        }
        return new String(result);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        result = []
        last_space_index = -1

        for str_index in range(len(s)):
            if str_index == len(s) - 1 or s[str_index] == ' ':
                reverse_str_index = str_index if str_index == len(s) - 1 else str_index - 1
                while reverse_str_index > last_space_index:
                    result.append(s[reverse_str_index])
                    reverse_str_index -= 1
                if str_index != len(s) - 1:
                    result.append(' ')
                last_space_index = str_index

        return ''.join(result)
```

</details>

<br>

## Approach 2: Using Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int lastSpaceIndex = -1;
        int len = (int)s.size();
        for (int strIndex = 0; strIndex <= len; strIndex++) {
            if (strIndex == len || s[strIndex] == ' ') {
                int startIndex = lastSpaceIndex + 1;
                int endIndex = strIndex - 1;
                while (startIndex < endIndex) {
                    char temp = s[startIndex];
                    s[startIndex] = s[endIndex];
                    s[endIndex] = temp;
                    startIndex++;
                    endIndex--;
                }
                lastSpaceIndex = strIndex;
            }
        }
        return s;
    };
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String reverseWords(String s) {
        int lastSpaceIndex = -1;
        char[] chArray = s.toCharArray();
        int len = s.length();
        for (int strIndex = 0; strIndex <= len; strIndex++) {
            if (strIndex == len || chArray[strIndex] == ' ') {
                int startIndex = lastSpaceIndex + 1;
                int endIndex = strIndex - 1;
                while (startIndex < endIndex) {
                    char temp = chArray[startIndex];
                    chArray[startIndex] = chArray[endIndex];
                    chArray[endIndex] = temp;
                    startIndex++;
                    endIndex--;
                }
                lastSpaceIndex = strIndex;
            }
        }
        return new String(chArray);
    }

}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split()
        reversed_str = ''
        for word in words:
            reversed_str += word[::-1] + ' '
        return reversed_str.strip()
```

</details>
