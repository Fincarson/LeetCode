# 249. Group Shifted Strings

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/group-shifted-strings/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 249 - Group Shifted Strings](https://leetcode.com/problems/group-shifted-strings/)

## Problem

Perform the following shift operations on a string:

- Right shift: Replace every letter with the successive letter of the English alphabet, where 'z' is replaced by 'a'. For example, "abc" can be right-shifted to "bcd" or "xyz" can be right-shifted to "yza".
- Left shift: Replace every letter with the preceding letter of the English alphabet, where 'a' is replaced by 'z'. For example, "bcd" can be left-shifted to "abc" or "yza" can be left-shifted to "xyz".

We can keep shifting the string in both directions to form an endless shifting sequence.

- For example, shift "abc" to form the sequence: ... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> .... <-> "zab" <-> "abc" <-> ...

You are given an array of strings strings, group together all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

### Example 1

### Example 2

## Constraints

- 1 <= strings.length <= 200
- 1 <= strings[i].length <= 50
- strings[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Group Anagrams](https://leetcode.com/problems/group-anagrams/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Find Maximum Number of String Pairs](https://leetcode.com/problems/find-maximum-number-of-string-pairs/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 249. Group Shifted Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashing | C++, Java, Python3 |

## Approach 1: Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char shiftLetter(char letter, int shift) {
        return (letter - shift + 26) % 26 + 'a';
    }
    
    // Create a hash value
    string getHash(string& s) {
        // Calculate the number of shifts to make the first character to be 'a'
        int shift = s[0];
        string hashKey;
        
        for (char letter : s) {
            hashKey += shiftLetter(letter, shift);
        }
        
        return hashKey;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mapHashToList;
        
        // Create a hash_value (hashKey) for each string and append the string
        // to the list of hash values i.e. mapHashToList["abc"] = ["abc", "bcd"]
        for (string str : strings) {
            string hashKey = getHash(str);
            mapHashToList[hashKey].push_back(str);
        }
        
        // Iterate over the map, and add the values to groups
        vector<vector<string>> groups;
        for (auto it : mapHashToList) {
            groups.push_back(it.second);
        }
        
        return groups;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    char shiftLetter(char letter, int shift) {
        return (char) ((letter - shift + 26) % 26 + 'a');
    }
    
    // Create a hash value
    String getHash(String s) {
        char[] chars = s.toCharArray();
        
        // Calculate the number of shifts to make the first character to be 'a'
        int shift = chars[0];
        for (int i = 0; i < chars.length; i++) {
            chars[i] = shiftLetter(chars[i], shift);
        }
        
        String hashKey = String.valueOf(chars);
        return hashKey;
    }
    
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> mapHashToList = new HashMap<>();
        
        // Create a hash_value (hashKey) for each string and append the string
        // to the list of hash values i.e. mapHashToList["abc"] = ["abc", "bcd"]
        for (String str : strings) {
            String hashKey = getHash(str);
            if (mapHashToList.get(hashKey) == null) {
                mapHashToList.put(hashKey, new ArrayList<>());
            } 
            mapHashToList.get(hashKey).add(str);
        }
        
        // Iterate over the map, and add the values to groups
        List<List<String>> groups = new ArrayList<>();
        for (List<String> group : mapHashToList.values()) {
            groups.add(group);
        }
        
        return groups;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        
        def shift_letter(letter: str, shift: int):
            return chr((ord(letter) - shift) % 26 + ord('a'))
        
        # Create a hash value
        def get_hash(string: str):
            # Calculate the number of shifts to make the first character to be 'a'
            shift = ord(string[0])
            return ''.join(shift_letter(letter, shift) for letter in string)
        
        # Create a hash_value (hashKey) for each string and append the string
        # to the list of hash values i.e. mapHashToList["abc"] = ["abc", "bcd"]
        groups = collections.defaultdict(list)
        for string in strings:
            hash_key = get_hash(string)
            groups[hash_key].append(string)
        
        # Return a list of all of the grouped strings
        return list(groups.values())
```

</details>
