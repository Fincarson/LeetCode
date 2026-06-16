# 205. Isomorphic Strings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/isomorphic-strings/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 205 - Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

## Problem

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 5 * 104
- t.length == s.length
- s and t consist of any valid ascii character.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Word Pattern](https://leetcode.com/problems/word-pattern/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Find and Replace Pattern](https://leetcode.com/problems/find-and-replace-pattern/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 205. Isomorphic Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Character Mapping with Dictionary | C++, Java, Python3 |
| First occurence transformation | C++, Java, Python3 |

## Approach 1: Character Mapping with Dictionary

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mappingDictStoT[256] = {0};
        int mappingDictTtoS[256] = {0};

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            // Case 1: No mapping exists in either of the dictionaries
            if (mappingDictStoT[c1] == 0 && mappingDictTtoS[c2] == 0) {
                mappingDictStoT[c1] = c2;
                mappingDictTtoS[c2] = c1;
            }

            // Case 2: Either mapping doesn't exist in one of the dictionaries
            // or Mapping exists and it doesn't match in either of the
            // dictionaries or both
            else if (!(mappingDictStoT[c1] == c2 &&
                       mappingDictTtoS[c2] == c1)) {
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
    public boolean isIsomorphic(String s, String t) {
        int[] mappingDictStoT = new int[256];
        Arrays.fill(mappingDictStoT, -1);

        int[] mappingDictTtoS = new int[256];
        Arrays.fill(mappingDictTtoS, -1);

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);

            // Case 1: No mapping exists in either of the dictionaries
            if (mappingDictStoT[c1] == -1 && mappingDictTtoS[c2] == -1) {
                mappingDictStoT[c1] = c2;
                mappingDictTtoS[c2] = c1;
            }
            // Case 2: Either mapping doesn't exist in one of the dictionaries or Mapping exists and
            // it doesn't match in either of the dictionaries or both
            else if (
                !(mappingDictStoT[c1] == c2 && mappingDictTtoS[c2] == c1)
            ) {
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
    def isIsomorphic(self, s: str, t: str) -> bool:

        mapping_s_t = {}
        mapping_t_s = {}

        for c1, c2 in zip(s, t):

            # Case 1: No mapping exists in either of the dictionaries
            if (c1 not in mapping_s_t) and (c2 not in mapping_t_s):
                mapping_s_t[c1] = c2
                mapping_t_s[c2] = c1

            # Case 2: Either mapping doesn't exist in one of the dictionaries or Mapping exists and
            # it doesn't match in either of the dictionaries or both
            elif mapping_s_t.get(c1) != c2 or mapping_t_s.get(c2) != c1:
                return False

        return True
```

</details>

<br>

## Approach 2: First occurence transformation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string transformString(string s) {
        unordered_map<char, int> indexMapping;
        string str;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (indexMapping.find(c) == indexMapping.end()) {
                indexMapping[c] = i;
            }

            str.append(to_string(indexMapping[c]));
            str.append(" ");
        }
        return str;
    }

    bool isIsomorphic(string s, string t) {
        return transformString(s) == transformString(t);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private String transformString(String s) {
        Map<Character, Integer> indexMapping = new HashMap<>();
        StringBuilder builder = new StringBuilder();

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s.charAt(i);

            if (!indexMapping.containsKey(c1)) {
                indexMapping.put(c1, i);
            }

            builder.append(Integer.toString(indexMapping.get(c1)));
            builder.append(" ");
        }
        return builder.toString();
    }

    public boolean isIsomorphic(String s, String t) {
        return transformString(s).equals(transformString(t));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def transformString(self, s: str) -> str:
        index_mapping = {}
        new_str = []

        for i, c in enumerate(s):
            if c not in index_mapping:
                index_mapping[c] = i
            new_str.append(str(index_mapping[c]))

        return " ".join(new_str)

    def isIsomorphic(self, s: str, t: str) -> bool:
        return self.transformString(s) == self.transformString(t)
```

</details>
