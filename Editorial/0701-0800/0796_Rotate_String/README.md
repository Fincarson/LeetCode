# 796. Rotate String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/rotate-string/)  
`String` `String Matching`

**Problem Link:** [LeetCode 796 - Rotate String](https://leetcode.com/problems/rotate-string/)

## Problem

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

- For example, if s = "abcde", then it will be "bcdea" after one shift.

### Example 1

```text
Input: s = "abcde", goal = "cdeab"
Output: true
```

### Example 2

```text
Input: s = "abcde", goal = "abced"
Output: false
```

## Constraints

- 1 <= s.length, goal.length <= 100
- s and goal consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 796. Rotate String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force | C++, Java, Python3 |
| Concatenation Check | C++, Java, Python3 |
| KMP Algorithm | C++, Java, Python3 |

## Approach 1: Brute Force

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int length = s.length();

        // Try all possible rotations of the string
        for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            // Perform one rotation
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal) return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;
        int length = s.length();
        char[] sChars = s.toCharArray();

        // Try all possible rotations of the string
        for (int rotationCount = 0; rotationCount < length; ++rotationCount) {
            // Perform one rotation
            sChars = rotateOnce(sChars);
            if (new String(sChars).equals(goal)) return true;
        }
        return false;
    }

    private char[] rotateOnce(char[] arr) {
        char firstChar = arr[0];
        System.arraycopy(arr, 1, arr, 0, arr.length - 1);
        arr[arr.length - 1] = firstChar;
        return arr;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        length = len(s)

        # Try all possible rotations of the string
        for _ in range(length):
            # Perform one rotation
            s = s[1:] + s[0]
            if s == goal:
                return True
        return False
```

</details>

<br>

## Approach 2: Concatenation Check

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths are different
        if (s.length() != goal.length()) return false;

        // Create a new string by concatenating 's' with itself
        string doubledString = s + s;

        // Use find to search for 'goal' in 'doubledString'
        // If find returns an index that is less than the
        // length of doubledString, 'goal' is a substring
        return doubledString.find(goal) < doubledString.length();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean rotateString(String s, String goal) {
        // Check if the lengths are different
        if (s.length() != goal.length()) return false;

        // Create a new string by concatenating 's' with itself
        String doubledString = s + s;

        // Use contains to search for 'goal' in 'doubledString'
        // If contains return true, 'goal' is a substring
        return doubledString.contains(goal);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # Check if the lengths are different
        if len(s) != len(goal):
            return False

        # Create a new string by concatenating 's' with itself
        doubled_string = s + s

        # Use find to search for 'goal' in 'doubledString'
        # If find returns an index that is not -1
        # then 'goal' is a substring
        return doubled_string.find(goal) != -1
```

</details>

<br>

## Approach 3: KMP Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        // Check if the lengths of both strings are different; if so, they can't
        // be rotations
        if (s.length() != goal.length()) return false;

        // Concatenate 's' with itself to create a new string containing all
        // possible rotations
        string doubledString = s + s;

        // Perform KMP substring search to check if 'goal' is a substring of
        // 'doubledString'
        return kmpSearch(doubledString, goal);
    }

private:
    bool kmpSearch(string& text, string& pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        vector<int> lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.size(), patternLength = pattern.size();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            // If there's a mismatch after some matches, use the LPS array to
            // skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }
        // Pattern not found in text
        return false;
    }

    vector<int> computeLPS(string& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern[index] == pattern[length]) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean rotateString(String s, String goal) {
        // Check if the lengths of both strings are different; if so, they can't be rotations
        if (s.length() != goal.length()) return false;

        // Concatenate 's' with itself to create a new string containing all possible rotations
        String doubledString = s + s;

        // Perform KMP substring search to check if 'goal' is a substring of 'doubledString'
        return kmpSearch(doubledString, goal);
    }

    private boolean kmpSearch(String text, String pattern) {
        // Precompute the LPS (Longest Prefix Suffix) array for the pattern
        int[] lps = computeLPS(pattern);
        int textIndex = 0, patternIndex = 0;
        int textLength = text.length(), patternLength = pattern.length();

        // Loop through the text to find the pattern
        while (textIndex < textLength) {
            // If characters match, move both indices forward
            if (text.charAt(textIndex) == pattern.charAt(patternIndex)) {
                textIndex++;
                patternIndex++;
                // If we've matched the entire pattern, return true
                if (patternIndex == patternLength) return true;
            }
            // If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
            else if (patternIndex > 0) {
                patternIndex = lps[patternIndex - 1];
            }
            // If no matches, move to the next character in text
            else {
                textIndex++;
            }
        }
        // Pattern not found in text
        return false;
    }

    private int[] computeLPS(String pattern) {
        int patternLength = pattern.length();
        int[] lps = new int[patternLength];
        int length = 0, index = 1;

        // Build the LPS array
        while (index < patternLength) {
            // If characters match, increment length and set lps value
            if (pattern.charAt(index) == pattern.charAt(length)) {
                length++;
                lps[index++] = length;
            }
            // If there's a mismatch, update length using the previous LPS value
            else if (length > 0) {
                length = lps[length - 1];
            }
            // No match and length is zero
            else {
                lps[index++] = 0;
            }
        }
        return lps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # Check if the lengths of both strings are different; if so, they can't be rotations
        if len(s) != len(goal):
            return False

        # Concatenate 's' with itself to create a new string containing all possible rotations
        doubled_string = s + s

        # Perform KMP substring search to check if 'goal' is a substring of 'doubled_string'
        return self.kmp_search(doubled_string, goal)

    def kmp_search(self, text: str, pattern: str) -> bool:
        # Precompute the LPS (Longest Prefix Suffix) array for the pattern
        lps = self.compute_lps(pattern)
        text_index = pattern_index = 0
        text_length = len(text)
        pattern_length = len(pattern)

        # Loop through the text to find the pattern
        while text_index < text_length:
            # If characters match, move both indices forward
            if text[text_index] == pattern[pattern_index]:
                text_index += 1
                pattern_index += 1
                # If we've matched the entire pattern, return true
                if pattern_index == pattern_length:
                    return True
            # If there's a mismatch after some matches, use the LPS array to skip unnecessary comparisons
            elif pattern_index > 0:
                pattern_index = lps[pattern_index - 1]
            # If no matches, move to the next character in text
            else:
                text_index += 1
        # Pattern not found in text
        return False

    def compute_lps(self, pattern: str) -> list:
        pattern_length = len(pattern)
        lps = [0] * pattern_length
        length = 0
        index = 1

        # Build the LPS array
        while index < pattern_length:
            # If characters match, increment length and set lps value
            if pattern[index] == pattern[length]:
                length += 1
                lps[index] = length
                index += 1
            # If there's a mismatch, update length using the previous LPS value
            elif length > 0:
                length = lps[length - 1]
            # No match and length is zero
            else:
                lps[index] = 0
                index += 1

        return lps
```

</details>
