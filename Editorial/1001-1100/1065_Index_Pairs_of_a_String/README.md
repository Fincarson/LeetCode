# 1065. Index Pairs of a String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/index-pairs-of-a-string/)  
`Array` `String` `Trie` `Sorting`

**Problem Link:** [LeetCode 1065 - Index Pairs of a String](https://leetcode.com/problems/index-pairs-of-a-string/)

## Problem

Given a string text and an array of strings words, return an array of all index pairs [i, j] so that the substring text[i...j] is in words.

Return the pairs [i, j] in sorted order (i.e., sort them by their first coordinate, and in case of ties sort them by their second coordinate).

### Example 1

```text
Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
```

### Example 2

```text
Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
```

## Constraints

- 1 <= text.length <= 100
- 1 <= words.length <= 20
- 1 <= words[i].length <= 50
- text and words[i] consist of lowercase English letters.
- All the strings of words are unique.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1065. Index Pairs of a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        unordered_set<string> wordsSet(words.begin(), words.end());
        vector<vector<int>> ans;
        for (int i = 0; i < text.size(); i++) {
            for (int j = i; j < text.size(); j++) {
                if (wordsSet.count(text.substr(i, j - i + 1))) {
                    ans.push_back({i, j});
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
    public int[][] indexPairs(String text, String[] words) {
        List<int[]> result = new ArrayList();
        Set<String> wordsSet = Arrays.stream(words).collect(Collectors.toSet());
        for (int i = 0; i < text.length(); i++) {
            for (int j = i; j < text.length(); j++) {
                if (wordsSet.contains(text.substring(i, j + 1))) {
                    result.add(new int[] {i, j});
                }
            }
        }
        int[][] ans = new int[result.size()][];
        ans = result.toArray(ans);
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
        words = set(words)
        ans = []
        for i in range(len(text)):
            for j in range(i, len(text)):
                if text[i:j + 1] in words:
                    ans.append([i, j])
        return ans
```

</details>
