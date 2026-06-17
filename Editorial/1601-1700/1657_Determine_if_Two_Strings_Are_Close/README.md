# 1657. Determine if Two Strings Are Close

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/determine-if-two-strings-are-close/)  
`Hash Table` `String` `Sorting` `Counting`

**Problem Link:** [LeetCode 1657 - Determine if Two Strings Are Close](https://leetcode.com/problems/determine-if-two-strings-are-close/)

## Problem

Two strings are considered close if you can attain one from the other using the following operations:

- Operation 1: Swap any two existing characters.

		For example, abcde -> aecdb
- Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.

		For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)

You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

### Example 1

```text
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
```

### Example 2

```text
Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
```

### Example 3

```text
Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
```

## Constraints

- 1 <= word1.length, word2.length <= 105
- word1 and word2 contain only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Buddy Strings](https://leetcode.com/problems/buddy-strings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Minimum Swaps to Make Strings Equal](https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Minimum Number of Steps to Make Two Strings Anagram](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1657. Determine if Two Strings Are Close

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using HashMap | C++, Java, Python3 |

## Approach 1: Using HashMap

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;

        unordered_map<char, int> word1Map;
        unordered_map<char, int> word2Map;
        vector<char> word1KeySet, word2KeySet, word1FrequencyList,
            word2FrequencyList;
        for (char c : word1) {
            word1Map[c - 'a'] = word1Map[c - 'a'] + 1;
        }
        for (char c : word2) {
            word2Map[c - 'a'] = word2Map[c - 'a'] + 1;
        }
        for (auto keyValuePair : word1Map) {
            word1KeySet.push_back(keyValuePair.first);
            word1FrequencyList.push_back(keyValuePair.second);
        }
        for (auto keyValuePair : word2Map) {
            word2KeySet.push_back(keyValuePair.first);
            word2FrequencyList.push_back(keyValuePair.second);
        }
        sort(word1KeySet.begin(), word1KeySet.end());
        sort(word2KeySet.begin(), word2KeySet.end());

        if (word1KeySet != word2KeySet) return false;

        sort(word1FrequencyList.begin(), word1FrequencyList.end());
        sort(word2FrequencyList.begin(), word2FrequencyList.end());

        return word1FrequencyList == word2FrequencyList;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean closeStrings(String word1, String word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        Map<Character, Integer> word1Map = new HashMap<>();
        Map<Character, Integer> word2Map = new HashMap<>();
        for (char c : word1.toCharArray()) {
            word1Map.put(c, word1Map.getOrDefault(c, 0) + 1);
        }
        for (char c : word2.toCharArray()) {
            word2Map.put(c, word2Map.getOrDefault(c, 0) + 1);
        }
        if (!word1Map.keySet().equals(word2Map.keySet())) {
            return false;
        }
        List<Integer> word1FrequencyList = new ArrayList<>(word1Map.values());
        List<Integer> word2FrequencyList = new ArrayList<>(word2Map.values());
        Collections.sort(word1FrequencyList);
        Collections.sort(word2FrequencyList);
        return word1FrequencyList.equals(word2FrequencyList);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        word1_elem_freq = Counter(word1)
        word2_elem_freq = Counter(word2)

        return set(word1_elem_freq) == set(word2_elem_freq) and sorted(word1_elem_freq.values()) == sorted(word2_elem_freq.values())
```

</details>
