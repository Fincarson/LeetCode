# 1910. Remove All Occurrences of a Substring

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)  
`String` `Stack` `Simulation`

**Problem Link:** [LeetCode 1910 - Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)

## Problem

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

- Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

### Example 1

```text
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
```

### Example 2

```text
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
```

## Constraints

- 1 <= s.length <= 1000
- 1 <= part.length <= 1000
- s​​​​​​ and part consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Deletions on a String](https://leetcode.com/problems/maximum-deletions-on-a-string/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1910. Remove All Occurrences of a Substring

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Iteration | C++, Java, Python3 |
| Stack | C++, Java, Python3 |
| Knuth-Morris-Pratt (KMP) Algorithm | C++, Java, Python3 |

## Approach 1: Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Continue removing occurrences of 'part' as long as it exists in 's'
        while (s.find(part) != string::npos) {
            // Find the index of the leftmost occurrence of 'part'
            size_t part_start_index = s.find(part);

            // Remove the substring 'part' from 's' by concatenating the
            // segments before and after 'part'
            s = s.substr(0, part_start_index) +
                s.substr(part_start_index + part.length());
        }
        // Return the updated string after all occurrences are removed
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String removeOccurrences(String s, String part) {
        // Continue removing occurrences of 'part' as long as it exists in 's'
        while (s.contains(part)) {
            // Find the index of the leftmost occurrence of 'part'
            int partStartIndex = s.indexOf(part);

            // Remove the substring 'part' from 's' by concatenating the segments before and after 'part'
            s =
                s.substring(0, partStartIndex) +
                s.substring(partStartIndex + part.length());
        }
        // Return the updated string after all occurrences are removed
        return s;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # Continue removing occurrences of 'part' as long as it exists in 's'
        while part in s:
            # Find the index of the leftmost occurrence of 'part'
            part_start_index = s.find(part)

            # Remove the substring 'part' by concatenating segments before and after 'part'
            s = s[:part_start_index] + s[part_start_index + len(part) :]

        # Return the updated string after all occurrences are removed
        return s
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char> stk;
        int strLength = s.length();
        int partLength = part.length();

        // Iterate through each character in the string
        for (int index = 0; index < strLength; index++) {
            // Push current character to stack
            stk.push(s[index]);

            // If stack size is greater than or equal to the part length, check
            // for match
            if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; j++) {
                    stk.pop();
                }
            }
        }

        // Convert stack to string with correct order
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }

private:
    // Helper function to check if the top of the stack matches the 'part'
    bool checkMatch(stack<char>& stk, string& part, int partLength) {
        stack<char> temp = stk;

        // Iterate through part from right to left
        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
            // If current stack top doesn't match expected character
            if (temp.top() != part[partIndex]) {
                return false;
            }
            temp.pop();
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

    public String removeOccurrences(String s, String part) {
        Stack<Character> stk = new Stack<>();
        int strLength = s.length();
        int partLength = part.length();

        // Iterate through each character in the string
        for (int index = 0; index < strLength; index++) {
            // Push current character to stack
            stk.push(s.charAt(index));

            // If stack size is greater than or equal to the part length, check for match
            if (stk.size() >= partLength && checkMatch(stk, part, partLength)) {
                // Pop the characters matching 'part' from the stack
                for (int j = 0; j < partLength; j++) {
                    stk.pop();
                }
            }
        }

        // Convert stack to string with correct order
        StringBuilder result = new StringBuilder();
        while (!stk.isEmpty()) {
            result.append(stk.pop());
        }
        result.reverse();

        return result.toString();
    }

    // Helper function to check if the top of the stack matches the 'part'
    private boolean checkMatch(
        Stack<Character> stk,
        String part,
        int partLength
    ) {
        Stack<Character> temp = new Stack<>();
        temp.addAll(stk); // Copy the stack to avoid modifying the original

        // Iterate through part from right to left
        for (int partIndex = partLength - 1; partIndex >= 0; partIndex--) {
            // If current stack top doesn't match expected character
            if (temp.isEmpty() || temp.peek() != part.charAt(partIndex)) {
                return false;
            }
            temp.pop();
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
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        part_length = len(part)

        # Iterate through each character in the string
        for char in s:
            # Push current character to stack
            stack.append(char)

            # If stack size is greater than or equal to the part length, check for match
            if len(stack) >= part_length and self._check_match(
                stack, part, part_length
            ):
                # Pop the characters matching 'part' from the stack
                for _ in range(part_length):
                    stack.pop()

        # Convert stack to string with correct order
        return "".join(stack)

    # Helper function to check if the top of the stack matches the 'part'
    def _check_match(self, stack: list, part: str, part_length: int) -> bool:
        # Compare the top 'part_length' elements of the stack with 'part'
        return "".join(stack[-part_length:]) == part
```

</details>

<br>

## Approach 3: Knuth-Morris-Pratt (KMP) Algorithm

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string removeOccurrences(string s, string part) {
        // Precompute KMP longest prefix-suffix array for the pattern
        vector<int> kmpLPS = computeLongestPrefixSuffix(part);

        // Using stack to track characters and support pattern matching
        stack<char> charStack;

        // Array to store pattern matching indices during traversal
        vector<int> patternIndexes(s.length() + 1, 0);

        for (int strIndex = 0, patternIndex = 0; strIndex < s.length();
             strIndex++) {
            char currentChar = s[strIndex];
            charStack.push(currentChar);

            if (currentChar == part[patternIndex]) {
                // Track the next pattern index when characters match
                patternIndexes[charStack.size()] = ++patternIndex;

                if (patternIndex == part.length()) {
                    // Remove entire matched pattern from stack
                    int remainingLength = part.length();
                    while (remainingLength != 0) {
                        charStack.pop();
                        remainingLength--;
                    }

                    // Restore pattern index for next potential match
                    patternIndex = charStack.empty()
                                       ? 0
                                       : patternIndexes[charStack.size()];
                }
            } else {
                if (patternIndex != 0) {
                    // Backtrack pattern matching using KMP LPS
                    strIndex--;
                    patternIndex = kmpLPS[patternIndex - 1];
                    charStack.pop();
                } else {
                    // Reset pattern index tracking when no match is possible
                    patternIndexes[charStack.size()] = 0;
                }
            }
        }

        // Convert remaining stack characters to result string
        string result = "";
        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }

private:
    vector<int> computeLongestPrefixSuffix(string pattern) {
        // Array to store the longest proper prefix which is also a suffix
        vector<int> lps(pattern.length(), 0);

        // Initialize tracking variables for prefix and current position
        for (int current = 1, prefixLength = 0; current < pattern.length();) {
            // If characters match, extend the prefix length
            if (pattern[current] == pattern[prefixLength]) {
                // Store the length of matching prefix
                lps[current] = ++prefixLength;
                current++;
            }
            // If characters don't match and we're not at the start of the
            // pattern
            else if (prefixLength != 0) {
                // Backtrack to the previous longest prefix-suffix
                prefixLength = lps[prefixLength - 1];
            }
            // If no match and no prefix to backtrack
            else {
                // No prefix-suffix match found
                lps[current] = 0;
                current++;
            }
        }

        // Return the computed longest prefix-suffix array
        return lps;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String removeOccurrences(String s, String part) {
        // Precompute KMP longest prefix-suffix array for the pattern
        int[] kmpLPS = computeLongestPrefixSuffix(part);

        // Using stack to track characters and support pattern matching
        Stack<Character> charStack = new Stack<>();

        // Array to store pattern matching indices during traversal
        int[] patternIndexes = new int[s.length() + 1];

        for (
            int strIndex = 0, patternIndex = 0;
            strIndex < s.length();
            strIndex++
        ) {
            char currentChar = s.charAt(strIndex);
            charStack.push(currentChar);

            if (currentChar == part.charAt(patternIndex)) {
                // Track the next pattern index when characters match
                patternIndexes[charStack.size()] = ++patternIndex;

                if (patternIndex == part.length()) {
                    // Remove entire matched pattern from stack
                    int remainingLength = part.length();
                    while (remainingLength != 0) {
                        charStack.pop();
                        remainingLength--;
                    }

                    // Restore pattern index for next potential match
                    patternIndex = charStack.isEmpty()
                        ? 0
                        : patternIndexes[charStack.size()];
                }
            } else {
                if (patternIndex != 0) {
                    // Backtrack pattern matching using KMP LPS
                    strIndex--;
                    patternIndex = kmpLPS[patternIndex - 1];
                    charStack.pop();
                } else {
                    // Reset pattern index tracking when no match is possible
                    patternIndexes[charStack.size()] = 0;
                }
            }
        }

        // Convert remaining stack characters to result string
        StringBuilder result = new StringBuilder();
        while (!charStack.isEmpty()) {
            result.append(charStack.pop());
        }

        return result.reverse().toString();
    }

    private int[] computeLongestPrefixSuffix(String pattern) {
        // Array to store the longest proper prefix which is also a suffix
        int[] lps = new int[pattern.length()];

        // Initialize tracking variables for prefix and current position
        for (int current = 1, prefixLength = 0; current < pattern.length();) {
            // If characters match, extend the prefix length
            if (pattern.charAt(current) == pattern.charAt(prefixLength)) {
                // Store the length of matching prefix
                lps[current] = ++prefixLength;
                current++;
            }
            // If characters don't match and we're not at the start of the pattern
            else if (prefixLength != 0) {
                // Backtrack to the previous longest prefix-suffix
                prefixLength = lps[prefixLength - 1];
            }
            // If no match and no prefix to backtrack
            else {
                // No prefix-suffix match found
                lps[current] = 0;
                current++;
            }
        }

        // Return the computed longest prefix-suffix array
        return lps;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        # Precompute KMP longest prefix-suffix array for the pattern
        kmp_lps = self._compute_longest_prefix_suffix(part)

        # Using list as a stack to track characters and support pattern matching
        char_stack = []

        # Array to store pattern matching indices during traversal
        pattern_indexes = [0] * (len(s) + 1)

        str_index = 0
        pattern_index = 0
        while str_index < len(s):
            current_char = s[str_index]
            char_stack.append(current_char)

            if current_char == part[pattern_index]:
                # Track the next pattern index when characters match
                pattern_indexes[len(char_stack)] = pattern_index + 1
                pattern_index += 1

                if pattern_index == len(part):
                    # Remove entire matched pattern from stack
                    for _ in range(len(part)):
                        char_stack.pop()

                    # Restore pattern index for next potential match
                    pattern_index = (
                        0
                        if not char_stack
                        else pattern_indexes[len(char_stack)]
                    )
            else:
                if pattern_index != 0:
                    # Backtrack pattern matching using KMP LPS
                    str_index -= 1
                    pattern_index = kmp_lps[pattern_index - 1]
                    char_stack.pop()
                else:
                    # Reset pattern index tracking when no match is possible
                    pattern_indexes[len(char_stack)] = 0

            str_index += 1

        # Convert remaining stack characters to result string
        return "".join(char_stack)

    def _compute_longest_prefix_suffix(self, pattern: str) -> list:
        # Array to store the longest proper prefix which is also a suffix
        lps = [0] * len(pattern)

        # Initialize tracking variables for prefix and current position
        current = 1
        prefix_length = 0
        while current < len(pattern):
            # If characters match, extend the prefix length
            if pattern[current] == pattern[prefix_length]:
                # Store the length of matching prefix
                prefix_length += 1
                lps[current] = prefix_length
                current += 1

            # If characters don't match and we're not at the start of the pattern
            elif prefix_length != 0:
                # Backtrack to the previous longest prefix-suffix
                prefix_length = lps[prefix_length - 1]

            # If no match and no prefix to backtrack
            else:
                # No prefix-suffix match found
                lps[current] = 0
                current += 1

        # Return the computed longest prefix-suffix array
        return lps
```

</details>
