# 387. First Unique Character in a String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/first-unique-character-in-a-string/)  
`Hash Table` `String` `Queue` `Counting`

**Problem Link:** [LeetCode 387 - First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string/)

## Problem

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 105
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [First Letter to Appear Twice](https://leetcode.com/problems/first-letter-to-appear-twice/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 387. First Unique Character in a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear time solution | Java, Python |

## Approach 1: Linear time solution

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> count = new HashMap<Character, Integer>();
        int n = s.length();
        // build hash map : character and how often it appears
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        
        // find the index
        for (int i = 0; i < n; i++) {
            if (count.get(s.charAt(i)) == 1) 
                return i;
        }
        return -1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def firstUniqChar(self, s: str) -> int:
        """
        :type s: str
        :rtype: int
        """
        # build hash map: character and how often it appears
        count = collections.Counter(s)
        
        # find the index
        for idx, ch in enumerate(s):
            if count[ch] == 1:
                return idx     
        return -1
```

</details>
