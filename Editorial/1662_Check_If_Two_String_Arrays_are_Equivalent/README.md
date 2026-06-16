# 1662. Check If Two String Arrays are Equivalent

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)  
`Array` `String`

**Problem Link:** [LeetCode 1662 - Check If Two String Arrays are Equivalent](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)

## Problem

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

### Example 1

```text
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.
```

### Example 2

```text
Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
Output: false
```

### Example 3

```text
Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
Output: true
```

## Constraints

- 1 <= word1.length, word2.length <= 103
- 1 <= word1[i].length, word2[i].length <= 103
- 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
- word1[i] and word2[i] consist of lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check if an Original String Exists Given Two Encoded Strings](https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1662. Check If Two String Arrays are Equivalent

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Connecting | C++, Java, Python3 |

## Approach 1: Connecting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1 = accumulate(word1.begin(), word1.end(), string{});
        string string2 = accumulate(word2.begin(), word2.end(), string{});
        return string1 == string2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        return (String.join("", word1)).equals(String.join("", word2));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)
```

</details>
