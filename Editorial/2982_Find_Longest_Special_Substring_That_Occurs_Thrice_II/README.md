# 2982. Find Longest Special Substring That Occurs Thrice II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/)  
`Hash Table` `String` `Binary Search` `Sliding Window` `Counting`

**Problem Link:** [LeetCode 2982 - Find Longest Special Substring That Occurs Thrice II](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/)

## Problem

You are given a string s that consists of lowercase English letters.

A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.

Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.

A substring is a contiguous non-empty sequence of characters within a string.

### Example 1

```text
Input: s = "aaaa"
Output: 2
Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
It can be shown that the maximum length achievable is 2.
```

### Example 2

```text
Input: s = "abcdef"
Output: -1
Explanation: There exists no special substring which occurs at least thrice. Hence return -1.
```

### Example 3

```text
Input: s = "abcaba"
Output: 1
Explanation: The longest special substring which occurs thrice is "a": substrings "abcaba", "abcaba", and "abcaba".
It can be shown that the maximum length achievable is 1.
```

## Constraints

- 3 <= s.length <= 5 * 105
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2982. Find Longest Special Substring That Occurs Thrice II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashing | C++, Java, Python3 |
| Store the Three Maximum Substring Lengths | C++, Java, Python3 |

## Approach 1: Hashing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> frequency(26, vector<int>(s.size() + 1, 0));
        char previousCharacter = s[0];
        int substringLength = 1;

        frequency[s[0] - 'a'][1] = 1;
        int ans = -1;

        for (int charIdx = 1; charIdx < s.size(); charIdx++) {
            char currentCharacter = s[charIdx];
            // If the current character is equal to the previous character, add
            // it to the mapping and increment the substring length.
            if (currentCharacter == previousCharacter) {
                substringLength++;
                int count = 1;
                frequency[currentCharacter - 'a'][substringLength] += 1;
            } else {
                // Otherwise, reset substring length to 1.
                previousCharacter = currentCharacter;
                substringLength = 1;
                frequency[currentCharacter - 'a'][1] += 1;
            }
        }

        // Calculate the cumulative sum from the end for every character and
        // find the maximum possible answer.
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int len = s.size() - 1; len >= 1; len--) {
                frequency[charIdx][len] += frequency[charIdx][len + 1];
                if (frequency[charIdx][len] >= 3) {
                    ans = max(ans, len);
                    break;
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

    public int maximumLength(String s) {
        int[][] frequency = new int[26][s.length() + 1];
        char previousCharacter = s.charAt(0);
        int substringLength = 1;

        frequency[s.charAt(0) - 'a'][1] = 1;
        int ans = -1;

        for (int charIdx = 1; charIdx < s.length(); charIdx++) {
            char currentCharacter = s.charAt(charIdx);
            // If the current character is equal to the previous character, add it to the
            // mapping and increment the substring length.
            if (currentCharacter == previousCharacter) {
                substringLength++;
                int count = 1;
                frequency[currentCharacter - 'a'][substringLength] += 1;
            } else {
                // Otherwise, reset substring length to 1.
                previousCharacter = currentCharacter;
                substringLength = 1;
                frequency[currentCharacter - 'a'][1] += 1;
            }
        }

        // Calculate the cumulative sum from the end for every character and find the
        // maximum possible answer.
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int len = s.length() - 1; len >= 1; len--) {
                frequency[charIdx][len] += frequency[charIdx][len + 1];
                if (frequency[charIdx][len] >= 3) {
                    ans = Math.max(ans, len);
                    break;
                }
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
    def maximumLength(self, s: str) -> int:
        frequency = [[0] * (len(s) + 1) for _ in range(26)]
        previous_character = s[0]
        substring_length = 1
        frequency[ord(s[0]) - ord("a")][1] = 1

        ans = -1
        for char_idx in range(1, len(s)):
            current_character = s[char_idx]
            if current_character == previous_character:
                substring_length += 1
                frequency[ord(current_character) - ord("a")][
                    substring_length
                ] += 1
            else:
                previous_character = current_character
                substring_length = 1
                frequency[ord(current_character) - ord("a")][1] += 1

        for char_idx in range(26):
            for length in range(len(s) - 1, 0, -1):
                frequency[char_idx][length] += frequency[char_idx][length + 1]
                if frequency[char_idx][length] >= 3:
                    ans = max(ans, length)
                    break

        return ans
```

</details>

<br>

## Approach 2: Store the Three Maximum Substring Lengths

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int& min(int& a, int& b, int& c) {
        return a < (b < c ? b : c) ? a : b < c ? b : c;
    }
    int maximumLength(string s) {
        int substringLength = 0, ans = -1;
        char previousCharacter;
        vector<vector<int>> substringLengths(26, vector<int>(3, -1));
        for (char character : s) {
            if (character == previousCharacter) {
                substringLength++;
            } else {
                substringLength = 1;
                previousCharacter = character;
            }
            // Replace the minimum frequency with the current length, if it is
            // greater.
            int& minLength = min(substringLengths[character - 'a'][0],
                                 substringLengths[character - 'a'][1],
                                 substringLengths[character - 'a'][2]);
            if (substringLength > minLength) minLength = substringLength;
        }

        // Find the character with the maximum value of its minimum frequency.
        for (char character = 'a'; character <= 'z'; character++)
            ans = max(ans, min(substringLengths[character - 'a'][0],
                               substringLengths[character - 'a'][1],
                               substringLengths[character - 'a'][2]));
        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Method to return the minimum of three values
    public int min(int a, int b, int c) {
        return a < Math.min(b, c) ? a : Math.min(b, c);
    }

    public int maximumLength(String s) {
        int substringLength = 0, ans = -1;
        char previousCharacter = '\0';
        int[][] substringLengths = new int[26][3];

        // Initialize the substringLengths array to -1
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            for (int lenIdx = 0; lenIdx < 3; lenIdx++) {
                substringLengths[charIdx][lenIdx] = -1;
            }
        }

        for (char character : s.toCharArray()) {
            if (character == previousCharacter) {
                substringLength++;
            } else {
                substringLength = 1;
                previousCharacter = character;
            }

            // Replace the minimum frequency with the current length if it is greater
            int index = character - 'a';
            int minLength = min(
                substringLengths[index][0],
                substringLengths[index][1],
                substringLengths[index][2]
            );
            if (substringLength > minLength) {
                if (substringLengths[index][0] == minLength) {
                    substringLengths[index][0] = substringLength;
                } else if (substringLengths[index][1] == minLength) {
                    substringLengths[index][1] = substringLength;
                } else {
                    substringLengths[index][2] = substringLength;
                }
            }
        }

        // Find the character with the maximum value of its minimum frequency
        for (int charIdx = 0; charIdx < 26; charIdx++) {
            ans = Math.max(
                ans,
                min(
                    substringLengths[charIdx][0],
                    substringLengths[charIdx][1],
                    substringLengths[charIdx][2]
                )
            );
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
    def maximumLength(self, s: str) -> int:
        substring_length = 0
        ans = -1
        previous_character = ""
        substring_lengths = [[-1, -1, -1] for _ in range(26)]
        for character in s:
            if character == previous_character:
                substring_length += 1
            else:
                substring_length = 1
                previous_character = character

            # Replace the minimum frequency with the current length, if it is
            # greater.
            min_length = min(substring_lengths[ord(character) - ord("a")])
            if substring_length > min_length:
                substring_lengths[ord(character) - ord("a")][
                    substring_lengths[ord(character) - ord("a")].index(
                        min_length
                    )
                ] = substring_length

        # Find the character with the maximum value of its minimum frequency.
        for char_idx in range(26):
            ans = max(ans, min(substring_lengths[char_idx]))

        return ans
```

</details>
