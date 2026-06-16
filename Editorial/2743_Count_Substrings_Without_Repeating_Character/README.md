# 2743. Count Substrings Without Repeating Character

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-substrings-without-repeating-character/)  
`Hash Table` `String` `Sliding Window`

**Problem Link:** [LeetCode 2743 - Count Substrings Without Repeating Character](https://leetcode.com/problems/count-substrings-without-repeating-character/)

## Problem

You are given a string s consisting only of lowercase English letters. We call a substring special if it contains no character which has occurred at least twice (in other words, it does not contain a repeating character). Your task is to count the number of special substrings. For example, in the string "pop", the substring "po" is a special substring, however, "pop" is not special (since 'p' has occurred twice).

Return the number of special substrings.

A substring is a contiguous sequence of characters within a string. For example, "abc" is a substring of "abcd", but "acd" is not.

### Example 1

```text
Input: s = "abcd"
Output: 10
Explanation: Since each character occurs once, every substring is a special substring. We have 4 substrings of length one, 3 of length two, 2 of length three, and 1 substring of length four. So overall there are 4 + 3 + 2 + 1 = 10 special substrings.
```

### Example 2

```text
Input: s = "ooo"
Output: 3
Explanation: Any substring with a length of at least two contains a repeating character. So we have to count the number of substrings of length one, which is 3.
```

### Example 3

```text
Input: s = "abab"
Output: 7
Explanation: Special substrings are as follows (sorted by their start positions):
Special substrings of length 1: "a", "b", "a", "b"
Special substrings of length 2: "ab", "ba", "ab"
And it can be shown that there are no special substrings with a length of at least three. So the answer would be 4 + 3 = 7.
```

## Constraints

- 1 <= s.length <= 105
- s consists of lowercase English letters

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Complete Substrings](https://leetcode.com/problems/count-complete-substrings/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2743. Count Substrings Without Repeating Character

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Sliding Window | C++, Java, Python3 |

## Approach: Sliding Window

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int substringCount = 0;

        int start = 0;
        int freq[26] = {0};
        for (int end = 0; end < s.size(); end++) {
            freq[s[end] - 'a']++;

            while (freq[s[end] - 'a'] > 1) {
                freq[s[start] - 'a']--;
                start++;
            }

            substringCount += (end - start + 1);
        }

        return substringCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSpecialSubstrings(String s) {
        int substringCount = 0;

        int start = 0;
        int[] freq = new int[26];
        for (int end = 0; end < s.length(); end++) {
            freq[s.charAt(end) - 'a']++;

            while (freq[s.charAt(end) - 'a'] > 1) {
                freq[s.charAt(start) - 'a']--;
                start++;
            }

            substringCount += (end - start + 1);
        }

        return substringCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        substring_count = 0

        start = 0
        freq = [0] * 26
        for end in range(len(s)):
            freq[ord(s[end]) - ord("a")] += 1

            while freq[ord(s[end]) - ord("a")] > 1:
                freq[ord(s[start]) - ord("a")] -= 1
                start += 1

            substring_count += end - start + 1

        return substring_count
```

</details>
