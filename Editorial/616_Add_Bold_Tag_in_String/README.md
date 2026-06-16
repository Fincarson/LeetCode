# 616. Add Bold Tag in String

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/add-bold-tag-in-string/)  
`Array` `Hash Table` `String` `Trie` `String Matching`

**Problem Link:** [LeetCode 616 - Add Bold Tag in String](https://leetcode.com/problems/add-bold-tag-in-string/)

## Problem

You are given a string s and an array of strings words.

You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words.

- If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag.
- If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.

### Example 1

```text
Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Explanation: The two strings of words are substrings of s as following: "abcxyz123".
We add <b> before each substring and </b> after each substring.
```

### Example 2

```text
Input: s = "aaabbb", words = ["aa","b"]
Output: "<b>aaabbb</b>"
Explanation:
"aa" appears as a substring two times: "aaabbb" and "aaabbb".
"b" appears as a substring three times: "aaabbb", "aaabbb", and "aaabbb".
We add <b> before each substring and </b> after each substring: "<b>a<b>a</b>a</b><b>b</b><b>b</b><b>b</b>".
Since the first two <b>'s overlap, we merge them: "<b>aaa</b><b>b</b><b>b</b><b>b</b>".
Since now the four <b>'s are consecutive, we merge them: "<b>aaabbb</b>".
```

## Constraints

- 1 <= s.length <= 1000
- 0 <= words.length <= 100
- 1 <= words[i].length <= 1000
- s and words[i] consist of English letters and digits.
- All the values of words are unique.

Note: This question is the same as 758. Bold Words in String.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Tag Validator](https://leetcode.com/problems/tag-validator/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 616. Add Bold Tag in String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Mark Bold Characters | C++, Java, Python3 |

## Approach: Mark Bold Characters

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
int n = s.size();
vector<bool> bold(n);

for (string word: words) {
    if (word.size() > n) {
        continue;
    }
    
    for (int i = 0; i <= n - word.size(); i++) {
        if (s.substr(i, word.size()) == word) {
            for (int j = i; j < i + word.size(); j++) {
                bold[j] = true;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
int n = s.length();
boolean[] bold = new boolean[n];

for (String word: words) {
    for (int i = 0; i <= n - word.length(); i++) {
        if (s.substring(i, i + word.length()).equals(word)) {
            for (int j = i; j < i + word.length(); j++) {
                bold[j] = true;
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
bold = [False] * len(s)

for word in words:
    for i in range(len(s) - len(word) + 1):
        if s[i:i + len(word)] == word:
            for j in range(i, i + len(word)):
                bold[j] = True
```

</details>
