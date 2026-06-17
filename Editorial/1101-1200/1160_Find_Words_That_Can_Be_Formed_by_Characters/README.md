# 1160. Find Words That Can Be Formed by Characters

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)  
`Array` `Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 1160 - Find Words That Can Be Formed by Characters](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)

## Problem

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once for each word in words).

Return the sum of lengths of all good strings in words.

### Example 1

```text
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
```

### Example 2

```text
Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
```

## Constraints

- 1 <= words.length <= 1000
- 1 <= words[i].length, chars.length <= 100
- words[i] and chars consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Ransom Note](https://leetcode.com/problems/ransom-note/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Rearrange Characters to Make Target String](https://leetcode.com/problems/rearrange-characters-to-make-target-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1160. Find Words That Can Be Formed by Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Count With Hash Map | C++, Java, Python3 |
| Count With Array | C++, Java, Python3 |

## Approach 1: Count With Hash Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> counts;
        for (char c : chars) {
            counts[c]++;
        }
        
        int ans = 0;
        for (string word : words) {
            unordered_map<char, int> wordCount;
            for (char c : word) {
                wordCount[c]++;
            }
            
            bool good = true;
            for (auto& [c, freq] : wordCount) {
                if (counts[c] < freq) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans += word.size();
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
    public int countCharacters(String[] words, String chars) {
        Map<Character, Integer> counts = new HashMap();
        for (Character c : chars.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }
        
        int ans = 0;
        for (String word : words) {
            Map<Character, Integer> wordCount = new HashMap();
            for (Character c : word.toCharArray()) {
                wordCount.put(c, wordCount.getOrDefault(c, 0) + 1);
            }
            
            boolean good = true;
            for (Character c : wordCount.keySet()) {
                if (counts.getOrDefault(c, 0) < wordCount.get(c)) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans += word.length();
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
    def countCharacters(self, words: List[str], chars: str) -> int:
        counts = defaultdict(int)
        for c in chars:
            counts[c] += 1
        
        ans = 0
        for word in words:
            word_count = defaultdict(int)
            for c in word:
                word_count[c] += 1
            
            good = True
            for c, freq in word_count.items():
                if counts[c] < freq:
                    good = False
                    break
            
            if good:
                ans += len(word)
            
        return ans
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
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);
        for (char c : chars) {
            counts[c - 'a']++;
        }
        
        int ans = 0;
        for (string word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }
            
            bool good = true;
            for (int i = 0; i < 26; i++) {
                if (counts[i] < wordCount[i]) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans += word.size();
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
    public int countCharacters(String[] words, String chars) {
        int[] counts = new int[26];
        for (Character c : chars.toCharArray()) {
            counts[c - 'a']++;
        }
        
        int ans = 0;
        for (String word : words) {
            int[] wordCount = new int[26];
            for (Character c : word.toCharArray()) {
                wordCount[c - 'a']++;
            }
            
            boolean good = true;
            for (int i = 0; i < 26; i++) {
                if (counts[i] < wordCount[i]) {
                    good = false;
                    break;
                }
            }
            
            if (good) {
                ans += word.length();
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
    def countCharacters(self, words: List[str], chars: str) -> int:
        counts = [0] * 26
        for c in chars:
            counts[ord(c) - ord("a")] += 1
        
        ans = 0
        for word in words:
            word_count = [0] * 26
            for c in word:
                word_count[ord(c) - ord("a")] += 1
            
            good = True
            for i in range(26):
                if counts[i] < word_count[i]:
                    good = False
                    break
            
            if good:
                ans += len(word)
            
        return ans
```

</details>
