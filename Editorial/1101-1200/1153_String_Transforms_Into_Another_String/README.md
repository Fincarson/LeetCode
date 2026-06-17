# 1153. String Transforms Into Another String

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/string-transforms-into-another-string/)  
`Hash Table` `String` `Graph Theory`

**Problem Link:** [LeetCode 1153 - String Transforms Into Another String](https://leetcode.com/problems/string-transforms-into-another-string/)

## Problem

Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

### Example 1

```text
Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
```

### Example 2

```text
Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
```

## Constraints

- 1 <= str1.length == str2.length <= 104
- str1 and str2 contain only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1153. String Transforms Into Another String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy + Hashing | C++, Java, Python3 |

## Approach 1: Greedy + Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) {
            return true;
        }
        
        unordered_map<char, char> conversionMappings;
        unordered_set<char> uniqueCharactersInStr2;
        
        // Make sure that no character in str1 is mapped to multiple characters in str2.
        for (int i = 0; i < str1.size(); i++) {
            if (conversionMappings.find(str1[i]) == conversionMappings.end()) {
                conversionMappings[str1[i]] = str2[i];
                uniqueCharactersInStr2.insert(str2[i]);
            } else if (conversionMappings[str1[i]] != str2[i]) {
                // this letter maps to 2 different characters, so str1 cannot transform into str2.
                return false;
            }
        }
        
        // No character in str1 maps to 2 or more different characters in str2 and there
        // is at least one temporary character that can be used to break any loops.
        if (uniqueCharactersInStr2.size() < 26) {
            return true;
        }
        
        // The conversion mapping forms one or more cycles and there are no temporary 
        // characters that we can use to break the loops, so str1 cannot transform into str2.
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean canConvert(String str1, String str2) {
        if (str1.equals(str2)) {
            return true;
        }
        
        Map<Character, Character> conversionMappings = new HashMap<>();
        Set<Character> uniqueCharactersInStr2 = new HashSet<>();
        
        // Make sure that no character in str1 is mapped to multiple characters in str2.
        for (int i = 0; i < str1.length(); i++) {
           if (!conversionMappings.containsKey(str1.charAt(i))) {
                conversionMappings.put(str1.charAt(i), str2.charAt(i));
                uniqueCharactersInStr2.add(str2.charAt(i));
            } else if (conversionMappings.get(str1.charAt(i)) != str2.charAt(i)) {
                // this letter maps to 2 different characters, so str1 cannot transform into str2.
                return false;
            }
        }
        
        // No character in str1 maps to 2 or more different characters in str2 and there
        // is at least one temporary character that can be used to break any loops.
        if (uniqueCharactersInStr2.size() < 26) {
            return true;
        }

        // The conversion mapping forms one or more cycles and there are no temporary 
        // characters that we can use to break the loops, so str1 cannot transform into str2.
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2:
            return True
        
        conversion_mappings = dict()
        unique_characters_in_str2 = set()
        
        # Make sure that no character in str1 is mapped to multiple characters in str2.
        for letter1, letter2 in zip(str1, str2):
            if letter1 not in conversion_mappings:
                conversion_mappings[letter1] = letter2
                unique_characters_in_str2.add(letter2)
            elif conversion_mappings[letter1] != letter2:
                # letter1 maps to 2 different characters, so str1 cannot transform into str2.
                return False
        
        
        if len(unique_characters_in_str2) < 26:
            # No character in str1 maps to 2 or more different characters in str2 and there
            # is at least one temporary character that can be used to break any loops.
            return True
        
        # The conversion mapping forms one or more cycles and there are no temporary 
        # characters that we can use to break the loops, so str1 cannot transform into str2.
        return False
```

</details>
