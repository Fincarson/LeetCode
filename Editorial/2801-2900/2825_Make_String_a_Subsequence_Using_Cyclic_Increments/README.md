# 2825. Make String a Subsequence Using Cyclic Increments

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 2825 - Make String a Subsequence Using Cyclic Increments](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/)

## Problem

You are given two 0-indexed strings str1 and str2.

In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.

Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.

Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

### Example 1

```text
Input: str1 = "abc", str2 = "ad"
Output: true
Explanation: Select index 2 in str1.
Increment str1[2] to become 'd'.
Hence, str1 becomes "abd" and str2 is now a subsequence. Therefore, true is returned.
```

### Example 2

```text
Input: str1 = "zc", str2 = "ad"
Output: true
Explanation: Select indices 0 and 1 in str1.
Increment str1[0] to become 'a'.
Increment str1[1] to become 'd'.
Hence, str1 becomes "ad" and str2 is now a subsequence. Therefore, true is returned.
```

### Example 3

```text
Input: str1 = "ab", str2 = "d"
Output: false
Explanation: In this example, it can be shown that it is impossible to make str2 a subsequence of str1 using the operation at most once.
Therefore, false is returned.
```

## Constraints

- 1 <= str1.length <= 105
- 1 <= str2.length <= 105
- str1 and str2 consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Is Subsequence](https://leetcode.com/problems/is-subsequence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2825. Make String a Subsequence Using Cyclic Increments

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Brute Force (Time Limit Exceeded) | C++, Java, Python3 |
| Optimized Single Pass (Two Pointer) | C++, Java, Python3 |

## Approach 1: Brute Force (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int lengthStr1 = str1.length();

        // Try all possible combinations of character increments
        for (int mask = 0; mask < (1 << lengthStr1); mask++) {
            string temp = str1;

            // Apply increments based on current mask
            for (int str1Index = 0; str1Index < lengthStr1; str1Index++) {
                if (mask & (1 << str1Index)) {
                    temp[str1Index] = getNextChar(temp[str1Index]);
                }
            }

            // Check if str2 is a subsequence of the modified string
            if (isSubsequence(temp, str2)) {
                return true;
            }
        }

        return false;
    }

private:
    // Helper function to get the next character cyclically
    char getNextChar(char str1Char) {
        return str1Char == 'z' ? 'a' : str1Char + 1;
    }

    // Helper function to check if str2 is a subsequence of str1
    bool isSubsequence(string& str1, string& str2) {
        int str1Index = 0, str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        // Traverse through both strings using a while loop
        while (str1Index < lengthStr1 && str2Index < lengthStr2) {
            if (str1[str1Index] == str2[str2Index]) {
                str2Index++;
            }
            str1Index++;
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canMakeSubsequence(String str1, String str2) {
        int lengthStr1 = str1.length();

        // Try all possible combinations of character increments
        for (int mask = 0; mask < (1 << lengthStr1); mask++) {
            StringBuilder temp = new StringBuilder(str1);

            // Apply increments based on current mask
            for (int str1Index = 0; str1Index < lengthStr1; str1Index++) {
                if ((mask & (1 << str1Index)) != 0) {
                    temp.setCharAt(
                        str1Index,
                        getNextChar(temp.charAt(str1Index))
                    );
                }
            }

            // Check if str2 is a subsequence of the modified string
            if (isSubsequence(temp.toString(), str2)) {
                return true;
            }
        }

        return false;
    }

    // Helper function to get the next character cyclically
    private char getNextChar(char str1Char) {
        return str1Char == 'z' ? 'a' : (char) (str1Char + 1);
    }

    // Helper function to check if str2 is a subsequence of str1
    private boolean isSubsequence(String str1, String str2) {
        int str1Index = 0, str2Index = 0;
        int lengthStr1 = str1.length(), lengthStr2 = str2.length();

        // Traverse through both strings using a while loop
        while (str1Index < lengthStr1 && str2Index < lengthStr2) {
            if (str1.charAt(str1Index) == str2.charAt(str2Index)) {
                str2Index++;
            }
            str1Index++;
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:

    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        length_str1 = len(str1)

        # Try all possible combinations of character increments
        for mask in range(1 << length_str1):
            temp = list(str1)
            # Apply increments based on current mask
            for str1_index in range(length_str1):
                if (mask & (1 << str1_index)) != 0:
                    temp[str1_index] = self._get_next_char(temp[str1_index])
            # Check if str2 is a subsequence of the modified string
            if self._is_subsequence("".join(temp), str2):
                return True

        return False

    # Helper function to get the next character cyclically
    def _get_next_char(self, str1Char: str) -> str:
        return "a" if str1Char == "z" else chr(ord(str1Char) + 1)

    # Helper function to check if str2 is a subsequence of str1
    def _is_subsequence(self, str1: str, str2: str) -> bool:
        str1_index, str2_index = 0, 0
        length_str1, length_str2 = len(str1), len(str2)

        # Traverse through both strings using a while loop
        while str1_index < length_str1 and str2_index < length_str2:
            if str1[str1_index] == str2[str2_index]:
                str2_index += 1
            str1_index += 1

        # Check if all characters in str2 were matched
        return str2_index == length_str2
```

</details>

<br>

## Approach 2: Optimized Single Pass (Two Pointer)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int str2Index = 0;
        int lengthStr1 = str1.size(), lengthStr2 = str2.size();

        // Traverse through both strings using a for loop
        for (int str1Index = 0;
             str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index) {
            // Check if characters match, or if str1[str1Index] can be
            // incremented to str2[str2Index]
            if (str1[str1Index] == str2[str2Index] ||
                (str1[str1Index] + 1 == str2[str2Index]) ||
                (str1[str1Index] - 25 == str2[str2Index])) {
                // If match found, move to next character in str2
                str2Index++;
            }
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canMakeSubsequence(String str1, String str2) {
        int str2Index = 0;
        int lengthStr1 = str1.length(), lengthStr2 = str2.length();

        // Traverse through both strings using a for loop
        for (
            int str1Index = 0;
            str1Index < lengthStr1 && str2Index < lengthStr2;
            ++str1Index
        ) {
            // Check if characters match, or if str1[str1Index] can be incremented to str2[str2Index]
            if (
                str1.charAt(str1Index) == str2.charAt(str2Index) ||
                (str1.charAt(str1Index) + 1 == str2.charAt(str2Index)) ||
                (str1.charAt(str1Index) - 25 == str2.charAt(str2Index))
            ) {
                // If match found, move to next character in str2
                str2Index++;
            }
        }
        // Check if all characters in str2 were matched
        return str2Index == lengthStr2;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        str2_index = 0
        length_str1, length_str2 = len(str1), len(str2)

        # Traverse through both strings using a for loop
        for str1_index in range(length_str1):
            if str2_index < length_str2 and (
                str1[str1_index] == str2[str2_index]
                or ord(str1[str1_index]) + 1 == ord(str2[str2_index])
                or ord(str1[str1_index]) - 25 == ord(str2[str2_index])
            ):
                # If match found, move to next character in str2
                str2_index += 1

        # Check if all characters in str2 were matched
        return str2_index == length_str2
```

</details>
