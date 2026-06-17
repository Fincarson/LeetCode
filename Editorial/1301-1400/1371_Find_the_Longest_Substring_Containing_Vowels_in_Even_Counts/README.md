# 1371. Find the Longest Substring Containing Vowels in Even Counts

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)  
`Hash Table` `String` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1371 - Find the Longest Substring Containing Vowels in Even Counts](https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/)

## Problem

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

### Example 1

```text
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
```

### Example 2

```text
Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
```

### Example 3

```text
Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
```

## Constraints

- 1 <= s.length <= 5 x 10^5
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

# Editorial - 1371. Find the Longest Substring Containing Vowels in Even Counts

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Bitmasking | C++, Java, Python3 |

## Approach: Bitmasking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixXOR = 0;
        // Store the masks of all letters in an array.
        int characterMap[26] = {0};
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;
        // Initialize mp to store the previous index with this prefixXOR value.
        vector<int> mp(32, -1);
        int longestSubstring = 0;

        for (int i = 0; i < s.length(); i++) {
            // If the current character is a vowel, find it's prefix XOR and add
            // it in the map.
            prefixXOR ^= characterMap[s[i] - 'a'];
            if (mp[prefixXOR] == -1 and prefixXOR != 0) mp[prefixXOR] = i;

            // If the value of prefixXOR exists in the map, find the longest
            // subarray.
            longestSubstring = max(longestSubstring, i - mp[prefixXOR]);
        }

        return longestSubstring;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int findTheLongestSubstring(String s) {
        int prefixXOR = 0;
        int[] characterMap = new int[26];
        characterMap['a' - 'a'] = 1;
        characterMap['e' - 'a'] = 2;
        characterMap['i' - 'a'] = 4;
        characterMap['o' - 'a'] = 8;
        characterMap['u' - 'a'] = 16;
        int[] mp = new int[32];
        for (int i = 0; i < 32; i++) mp[i] = -1;
        int longestSubstring = 0;
        for (int i = 0; i < s.length(); i++) {
            prefixXOR ^= characterMap[s.charAt(i) - 'a'];
            if (mp[prefixXOR] == -1 && prefixXOR != 0) mp[prefixXOR] = i;
            longestSubstring = Math.max(longestSubstring, i - mp[prefixXOR]);
        }
        return longestSubstring;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        prefixXOR = 0
        characterMap = [0] * 26
        characterMap[ord("a") - ord("a")] = 1
        characterMap[ord("e") - ord("a")] = 2
        characterMap[ord("i") - ord("a")] = 4
        characterMap[ord("o") - ord("a")] = 8
        characterMap[ord("u") - ord("a")] = 16
        mp = [-1] * 32
        longestSubstring = 0
        for i in range(len(s)):
            prefixXOR ^= characterMap[ord(s[i]) - ord("a")]
            if mp[prefixXOR] == -1 and prefixXOR != 0:
                mp[prefixXOR] = i
            longestSubstring = max(longestSubstring, i - mp[prefixXOR])
        return longestSubstring
```

</details>
