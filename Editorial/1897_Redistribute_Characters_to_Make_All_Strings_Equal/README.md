# 1897. Redistribute Characters to Make All Strings Equal

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 1897 - Redistribute Characters to Make All Strings Equal](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/)

## Problem

You are given an array of strings words (0-indexed).

In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].

Return true if you can make every string in words equal using any number of operations, and false otherwise.

### Example 1

```text
Input: words = ["abc","aabc","bc"]
Output: true
Explanation: Move the first 'a' in words[1] to the front of words[2],
to make words[1] = "abc" and words[2] = "abc".
All the strings are now equal to "abc", so return true.
```

### Example 2

```text
Input: words = ["ab","a"]
Output: false
Explanation: It is impossible to make all the strings equal using the operation.
```

## Constraints

- 1 <= words.length <= 100
- 1 <= words[i].length <= 100
- words[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1897. Redistribute Characters to Make All Strings Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count Character Frequencies | C++, Java, Python3 |
| Count With Array | C++, Java, Python3 |

## Approach 1: Count Character Frequencies

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> counts;
        for (string word : words) {
            for (char c : word) {
                counts[c]++;
            }
        }
        
        int n = words.size();
        for (auto& [key, val] : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean makeEqual(String[] words) {
        Map<Character, Integer> counts = new HashMap();
        for (String word : words) {
            for (char c : word.toCharArray()) {
                counts.put(c, counts.getOrDefault(c, 0) + 1);
            }
        }
        
        int n = words.length;
        for (Character c : counts.keySet()) {
            int val = counts.get(c);
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        counts = defaultdict(int)
        for word in words:
            for c in word:
                counts[c] += 1
        
        n = len(words)
        for val in counts.values():
            if val % n != 0:
                return False
        
        return True
```

</details>

<br>

## Approach 2: Count With Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> counts(26, 0);
        for (string word : words) {
            for (char c : word) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.size();
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean makeEqual(String[] words) {
        int[] counts = new int[26];
        for (String word : words) {
            for (char c : word.toCharArray()) {
                counts[c - 'a']++;
            }
        }
        
        int n = words.length;
        for (int val : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        counts = [0] * 26
        for word in words:
            for c in word:
                counts[ord(c) - ord('a')] += 1
        
        n = len(words)
        for val in counts:
            if val % n != 0:
                return False

        return True
```

</details>
