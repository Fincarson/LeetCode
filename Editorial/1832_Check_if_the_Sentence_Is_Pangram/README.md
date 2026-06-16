# 1832. Check if the Sentence Is Pangram

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 1832 - Check if the Sentence Is Pangram](https://leetcode.com/problems/check-if-the-sentence-is-pangram/)

## Problem

A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

### Example 1

```text
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
```

### Example 2

```text
Input: sentence = "leetcode"
Output: false
```

## Constraints

- 1 <= sentence.length <= 1000
- sentence consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1832. Check if the Sentence Is Pangram

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Find letters one by one | C++, Java, Python3 |
| Set | C++, Java, Python3 |
| Use Array as Counter | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python |

## Approach 1: Find letters one by one

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // We iterate over 'sentence' for 26 times, one for each letter 'currChar'.
        for (int i = 0; i < 26; ++i) {
            char currChar = 'a' + i;
            
            // If 'sentence' doesn't contain currChar, it is not a pangram.
            if (sentence.find(currChar) == string::npos)
                return false;
        }
        
        // If we manage to find all 26 letters, it is a pangram.
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        // We iterate over 'sentence' for 26 times, one for each letter 'currChar'.
        for (int i = 0; i < 26; ++i) {
            char currChar = (char)('a' + i);

            // If 'sentence' doesn't contain currChar, it is not a pangram.
            if (sentence.indexOf(currChar) == -1)
                return false;
        }
        
        // If we manage to find all 26 letters, it is a pangram.
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # We iterate over 'sentence' for 26 times, one for each letter 'curr_char'.
        for i in range(26):
            curr_char = chr(ord('a') + i)

            # If 'sentence' doesn't contain 'curr_char', it is not a pangram.
            if sentence.find(curr_char) == -1:
                return False
        
        # If we manage to find all 26 letters, it is a pangram.
        return True
```

</details>

<br>

## Approach 2: Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Add every letter of 'sentence' to hash set 'seen'.
        unordered_set<char> seen(sentence.begin(), sentence.end());
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        // Empty set 'seen'.
        Set<Character> seen = new HashSet<>();
        
        // Iterate over 'sentence' add every letter to 'seen'.
        for (char currChar : sentence.toCharArray())
            seen.add(currChar);
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # Add every letter of 'sentence' to hash set 'seen'.
        seen = set(sentence)
        
        # If the size of 'seen' is 26, then 'sentence' is a pangram.
        return len(seen) == 26
```

</details>

<br>

## Approach 3: Use Array as Counter

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Array 'seen' of size 26.
        array<bool, 26> seen{};

        // For every letter 'currChar', we find its ASCII code, 
        // and update value at the mapped index as true.
        for (auto currChar : sentence)
            seen[currChar - 'a'] = true;
        
        // Once we finish iterating, check if 'seen' contains false.
        for (auto status : seen)
            if (!status)
                return false;
        return true;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        // Array 'seen' of size 26.
        boolean[] seen = new boolean[26];
        
        // For every letter 'currChar', we find its ASCII code, 
        // and update value at the mapped index as true.
        for (char currChar : sentence.toCharArray())
            seen[currChar - 'a'] = true;
        
        // Once we finish iterating, check if 'seen' contains false.
        for (boolean status : seen)
            if (!status)
                return false;
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # Array 'seen' of size 26.
        seen = [False] * 26

        # For every letter 'currChar', we find its ASCII code, 
        # and update value at the mapped index as true.
        for curr_char in sentence:
            seen[ord(curr_char) - ord('a')] = True
        
        # Once we finish iterating, check if 'seen' contains false.
        for status in seen:
            if not status:
                return False
        return True
```

</details>

<br>

## Approach 4: Bit Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Initialize seen = 0 since we start with no letter.
        int seen = 0;
        
        // Iterate over 'sentence'.
        for (auto currChar : sentence) {
            // Map each 'currChar' to its index using its ASCII code.
            int mappedIndex = currChar - 'a';

            // 'currBit' represents the bit for 'currChar'.
            int currBit = 1 << mappedIndex;

            // Use 'OR' operation since we only add its bit for once.
            seen |= currBit;
        }
        
        // Once we finish iterating, check if 'seen' contains 26 bits of 1.
        return seen == (1 << 26) - 1;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean checkIfPangram(String sentence) {
        // Initialize seen = 0 since we start with no letter.
        int seen = 0;
        
        // Iterate over 'sentence'.
        for (char currChar : sentence.toCharArray()) {
            // Map each 'currChar' to its index using its ASCII code.
            int mappedIndex = ch - 'a';

            // 'currBit' represents the bit for 'currChar'.
            int currBit = 1 << mappedIndex;

            // Use 'OR' operation since we only add its bit for once.
            seen |= currBit;
        }
        
        // Once we finish iterating, check if 'seen' contains 26 bits of 1.
        return seen == (1 << 26) - 1;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        # Initialize seen = 0 since we start with no letter.
        seen = 0
        
        # Iterate over 'sentence'.
        for curr_char in sentence:
            # Map each 'curr_char' to its index using its ASCII code.
            mapped_index = ord(curr_char) - ord('a')

            # 'curr_bit' represents the bit for 'curr_char'.
            curr_bit = 1 << mapped_index 

            # Use 'OR' operation since we only add its bit for once.
            seen |= curr_bit
        
        # Once we finish iterating, check if 'seen' contains 26 bits of 1.
        return seen == (1 << 26) - 1
```

</details>
