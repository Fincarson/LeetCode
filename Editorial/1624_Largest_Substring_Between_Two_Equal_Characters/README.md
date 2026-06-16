# 1624. Largest Substring Between Two Equal Characters

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 1624 - Largest Substring Between Two Equal Characters](https://leetcode.com/problems/largest-substring-between-two-equal-characters/)

## Problem

Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.

A substring is a contiguous sequence of characters within a string.

### Example 1

```text
Input: s = "aa"
Output: 0
Explanation: The optimal substring here is an empty substring between the two 'a's.
```

### Example 2

```text
Input: s = "abca"
Output: 2
Explanation: The optimal substring here is "bc".
```

### Example 3

```text
Input: s = "cbzxy"
Output: -1
Explanation: There are no characters that appear twice in s.
```

## Constraints

- 1 <= s.length <= 300
- s contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1624. Largest Substring Between Two Equal Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Hash Map | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for (int left = 0; left < s.size(); left++) {
            for (int right = left + 1; right < s.size(); right++) {
                if (s[left] == s[right]) {
                    ans = max(ans, right - left - 1);
                }
            }
        }
        
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int ans = -1;
        for (int left = 0; left < s.length(); left++) {
            for (int right = left + 1; right < s.length(); right++) {
                if (s.charAt(left) == s.charAt(right)) {
                    ans = Math.max(ans, right - left - 1);
                }
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        ans = -1
        
        for left in range(len(s)):
            for right in range(left + 1, len(s)):
                if s[left] == s[right]:
                    ans = max(ans, right - left - 1)
        
        return ans
```

</details>

<br>

## Approach 2: Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> firstIndex;
        int ans = -1;
        
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex.find(s[i]) != firstIndex.end()) {
                ans = max(ans, i - firstIndex[s[i]] - 1);
            } else {
                firstIndex[s[i]] = i;
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        Map<Character, Integer> firstIndex = new HashMap();
        int ans = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (firstIndex.containsKey(s.charAt(i))) {
                ans = Math.max(ans, i - firstIndex.get(s.charAt(i)) - 1);
            } else {
                firstIndex.put(s.charAt(i), i);
            }
        }
        
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        first_index = {}
        ans = -1
        
        for i in range(len(s)):
            if s[i] in first_index:
                ans = max(ans, i - first_index[s[i]] - 1)
            else:
                first_index[s[i]] = i

        return ans
```

</details>
