# 1930. Unique Length-3 Palindromic Subsequences

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)  
`Hash Table` `String` `Bit Manipulation` `Prefix Sum`

**Problem Link:** [LeetCode 1930 - Unique Length-3 Palindromic Subsequences](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

## Problem

Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, "ace" is a subsequence of "abcde".

### Example 1

```text
Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
```

### Example 2

```text
Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
```

### Example 3

```text
Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
```

## Constraints

- 3 <= s.length <= 105
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Palindromic Subsequences](https://leetcode.com/problems/count-palindromic-subsequences/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1930. Unique Length-3 Palindromic Subsequences

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Letters In-Between | C++, Java, Python3 |
| Pre-Compute First and Last Indices | C++, Java, Python3 |

## Approach 1: Count Letters In-Between

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
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
    public int countPalindromicSubsequence(String s) {
        Set<Character> letters = new HashSet();
        for (Character c: s.toCharArray()) {
            letters.add(c);
        }
        
        int ans = 0;
        for (Character letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.length(); k++) {
                if (s.charAt(k) == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            Set<Character> between = new HashSet();
            for (int k = i + 1; k < j; k++) {
                between.add(s.charAt(k));
            }
            
            ans += between.size();
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
    def countPalindromicSubsequence(self, s: str) -> int:
        letters = set(s)
        ans = 0
        
        for letter in letters:
            i, j = s.index(letter), s.rindex(letter)
            between = set()
            
            for k in range(i + 1, j):
                between.add(s[k])
            
            ans += len(between)

        return ans
```

</details>

<br>

## Approach 2: Pre-Compute First and Last Indices

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first = vector(26, -1);
        vector<int> last = vector(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            unordered_set<char> between;
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
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
    public int countPalindromicSubsequence(String s) {
        int[] first = new int[26];
        int[] last = new int[26];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);
        
        for (int i = 0; i < s.length(); i++) {
            int curr = s.charAt(i) - 'a';
            if (first[curr] == - 1) {
                first[curr] = i;
            }
            
            last[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (first[i] == -1) {
                continue;
            }
            
            Set<Character> between = new HashSet();
            for (int j = first[i] + 1; j < last[i]; j++) {
                between.add(s.charAt(j));
            }
            
            ans += between.size();
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
    def countPalindromicSubsequence(self, s: str) -> int:
        first = [-1] * 26
        last = [-1] * 26
        
        for i in range(len(s)):
            curr = ord(s[i]) - ord("a")
            if first[curr] == -1:
                first[curr] = i
            
            last[curr] = i
        
        ans = 0
        for i in range(26):
            if first[i] == -1:
                continue
                
            between = set()
            for j in range(first[i] + 1, last[i]):
                between.add(s[j])
            
            ans += len(between)

        return ans
```

</details>
