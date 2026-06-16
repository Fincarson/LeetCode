# 1684. Count the Number of Consistent Strings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/count-the-number-of-consistent-strings/)  
`Array` `Hash Table` `String` `Bit Manipulation` `Counting`

**Problem Link:** [LeetCode 1684 - Count the Number of Consistent Strings](https://leetcode.com/problems/count-the-number-of-consistent-strings/)

## Problem

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

### Example 1

```text
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
```

### Example 2

```text
Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
```

### Example 3

```text
Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
```

## Constraints

- 1 <= words.length <= 104
- 1 <= allowed.length <= 26
- 1 <= words[i].length <= 10
- The characters in allowed are distinct.
- words[i] and allowed contain only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Pairs Of Similar Strings](https://leetcode.com/problems/count-pairs-of-similar-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1684. Count the Number of Consistent Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Boolean Array | C++, Java, Python3 |
| Hash Set | C++, Java, Python3 |
| Bit Manipulation | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isWordConsistent = true;

            // Check each character in the current word
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word[i];
                bool isCharAllowed = false;

                // Check if the current character is in the allowed string
                for (int j = 0; j < allowed.length(); j++) {
                    if (allowed[j] == currentChar) {
                        isCharAllowed = true;
                        break;  // Character found, no need to continue
                                // searching
                    }
                }

                // If the character is not allowed, mark the word as
                // inconsistent
                if (!isCharAllowed) {
                    isWordConsistent = false;
                    break;  // No need to check remaining characters
                }
            }

            // If the word is consistent, increment the count
            if (isWordConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countConsistentStrings(String allowed, String[] words) {
        int consistentCount = 0;

        // Iterate through each word in the words array
        for (String word : words) {
            boolean isWordConsistent = true;

            // Check each character in the current word
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word.charAt(i);
                boolean isCharAllowed = false;

                // Check if the current character is in the allowed string
                for (int j = 0; j < allowed.length(); j++) {
                    if (allowed.charAt(j) == currentChar) {
                        isCharAllowed = true;
                        break; // Character found, no need to continue searching
                    }
                }

                // If the character is not allowed, mark the word as inconsistent
                if (!isCharAllowed) {
                    isWordConsistent = false;
                    break; // No need to check remaining characters
                }
            }

            // If the word is consistent, increment the count
            if (isWordConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        consistent_count = 0

        # Iterate through each word in the words list
        for word in words:
            is_word_consistent = True

            # Check each character in the current word
            for char in word:
                is_char_allowed = False

                # Check if the current character is in the allowed string
                for allowed_char in allowed:
                    if allowed_char == char:
                        is_char_allowed = True
                        break  # Character found, no need to continue searching

                # If the character is not allowed, mark the word as inconsistent
                if not is_char_allowed:
                    is_word_consistent = False
                    break  # No need to check remaining characters

            # If the word is consistent, increment the count
            if is_word_consistent:
                consistent_count += 1

        return consistent_count
```

</details>

<br>

## Approach 2: Boolean Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a vector to mark which characters are allowed
        vector<bool> isAllowed(26, false);

        // Mark all characters in 'allowed' as true in the isAllowed vector
        for (int i = 0; i < allowed.length(); i++) {
            isAllowed[allowed[i] - 'a'] = true;
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                // If any character is not allowed, mark as inconsistent and
                // break
                if (!isAllowed[word[i] - 'a']) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countConsistentStrings(String allowed, String[] words) {
        // Create a boolean array to mark which characters are allowed
        boolean[] isAllowed = new boolean[26];

        // Mark all characters in 'allowed' as true in the isAllowed array
        for (int i = 0; i < allowed.length(); i++) {
            isAllowed[allowed.charAt(i) - 'a'] = true;
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (String word : words) {
            boolean isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                // If any character is not allowed, mark as inconsistent and break
                if (!isAllowed[word.charAt(i) - 'a']) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        # Create a boolean list to mark which characters are allowed
        is_allowed = [False] * 26

        # Mark all characters in 'allowed' as True in the is_allowed list
        for char in allowed:
            is_allowed[ord(char) - ord("a")] = True

        consistent_count = 0

        # Iterate through each word in the words list
        for word in words:
            is_consistent = True

            # Check each character of the current word
            for char in word:
                # If any character is not allowed, mark as inconsistent and break
                if not is_allowed[ord(char) - ord("a")]:
                    is_consistent = False
                    break

            # If the word is consistent, increment the count
            if is_consistent:
                consistent_count += 1

        return consistent_count
```

</details>

<br>

## Approach 3: Hash Set

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Create a set to store the allowed characters
        unordered_set<char> allowedChars;

        // Populate the set with characters from the 'allowed' string
        for (int i = 0; i < allowed.length(); i++) {
            allowedChars.insert(allowed[i]);
        }

        int consistentCount = 0;

        // Iterate through each word in the 'words' array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word[i];

                // If the character is not in the allowedChars set, mark as
                // inconsistent and break
                if (allowedChars.find(currentChar) == allowedChars.end()) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        // Return the total count of consistent strings
        return consistentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countConsistentStrings(String allowed, String[] words) {
        // Create a set to store the allowed characters
        Set<Character> allowedChars = new HashSet<>();

        // Populate the set with characters from the 'allowed' string
        for (int i = 0; i < allowed.length(); i++) {
            allowedChars.add(allowed.charAt(i));
        }

        int consistentCount = 0;

        // Iterate through each word in the 'words' array
        for (String word : words) {
            boolean isConsistent = true;

            // Check each character of the current word
            for (int i = 0; i < word.length(); i++) {
                char currentChar = word.charAt(i);

                // If the character is not in the allowedChars set, mark as inconsistent and break
                if (!allowedChars.contains(currentChar)) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        // Return the total count of consistent strings
        return consistentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        # Create a set to store the allowed characters
        allowed_chars = set(allowed)

        consistent_count = 0

        # Iterate through each word in the 'words' list
        for word in words:
            # Check if all characters in the word are in allowed_chars
            if all(char in allowed_chars for char in word):
                consistent_count += 1

        # Return the total count of consistent strings
        return consistent_count
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
    int countConsistentStrings(string allowed, vector<string>& words) {
        // allowedBits will represent the bitmask of allowed characters
        int allowedBits = 0;

        // Set the corresponding bit for each character in allowed
        for (int i = 0; i < allowed.length(); i++) {
            allowedBits |= 1 << (allowed[i] - 'a');
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (string& word : words) {
            bool isConsistent = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {
                // Calculate the bit position for the current character
                int bit = (allowedBits >> (word[i] - 'a')) & 1;

                // If the bit is 0, the character is not allowed
                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int countConsistentStrings(String allowed, String[] words) {
        // allowedBits will represent the bitmask of allowed characters
        int allowedBits = 0;

        // Set the corresponding bit for each character in allowed
        for (int i = 0; i < allowed.length(); i++) {
            allowedBits |= 1 << (allowed.charAt(i) - 'a');
        }

        int consistentCount = 0;

        // Iterate through each word in the words array
        for (String word : words) {
            boolean isConsistent = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {
                // Calculate the bit position for the current character
                int bit = (allowedBits >> (word.charAt(i) - 'a')) & 1;

                // If the bit is 0, the character is not allowed
                if (bit == 0) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        # Create a bitmask representing the allowed characters
        allowed_bits = 0

        # Set the corresponding bit for each character in allowed
        for char in allowed:
            allowed_bits |= 1 << (ord(char) - ord("a"))

        consistent_count = 0

        # Iterate through each word in the words list
        for word in words:
            is_consistent = True

            # Check each character in the word
            for char in word:
                # Calculate the bit position for the current character
                bit = (allowed_bits >> (ord(char) - ord("a"))) & 1

                # If the bit is 0, the character is not allowed
                if not bit:
                    is_consistent = False
                    break

            # If the word is consistent, increment the count
            if is_consistent:
                consistent_count += 1

        return consistent_count
```

</details>
