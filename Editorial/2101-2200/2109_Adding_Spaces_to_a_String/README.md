# 2109. Adding Spaces to a String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/adding-spaces-to-a-string/)  
`Array` `Two Pointers` `String` `Simulation`

**Problem Link:** [LeetCode 2109 - Adding Spaces to a String](https://leetcode.com/problems/adding-spaces-to-a-string/)

## Problem

You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.

- For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".

Return the modified string after the spaces have been added.

### Example 1

```text
Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation:
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.
```

### Example 2

```text
Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"
Explanation:
The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
We then place spaces before those characters.
```

### Example 3

```text
Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
Explanation:
We are also able to place spaces before the first character of the string.
```

## Constraints

- 1 <= s.length <= 3 * 105
- s consists only of lowercase and uppercase English letters.
- 1 <= spaces.length <= 3 * 105
- 0 <= spaces[i] <= s.length - 1
- All the values of spaces are strictly increasing.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2109. Adding Spaces to a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Built-in Functions | C++, Java, Python3 |
| Two-Pointer Technique | C++, Java, Python3 |

## Approach 1: Using Built-in Functions

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // Stream to dynamically construct the string
        stringstream result;
        int spaceIndex = 0;

        for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
            if (spaceIndex < spaces.size() &&
                stringIndex == spaces[spaceIndex]) {
                // Insert space at the correct position
                result << ' ';
                ++spaceIndex;
            }
            // Append the current character
            result << s[stringIndex];
        }
        // Convert the stream to a string
        return result.str();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String addSpaces(String s, int[] spaces) {
        // StringBuilder for efficient string construction
        StringBuilder result = new StringBuilder();
        int spaceIndex = 0;

        for (int stringIndex = 0; stringIndex < s.length(); stringIndex++) {
            if (
                spaceIndex < spaces.length && stringIndex == spaces[spaceIndex]
            ) {
                // Insert space at the correct position
                result.append(' ');
                spaceIndex++;
            }
            // Append the current character
            result.append(s.charAt(stringIndex));
        }
        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        # List to store characters (more efficient than string concatenation)
        result = []
        space_index = 0

        for string_index in range(len(s)):
            if (
                space_index < len(spaces)
                and string_index == spaces[space_index]
            ):
                # Insert space at the correct position
                result.append(" ")
                space_index += 1

            # Append the current character
            result.append(s[string_index])

        # Join all characters into final string
        return "".join(result)
```

</details>

<br>

## Approach 2: Two-Pointer Technique

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        // Pre-allocate space for efficiency
        result.reserve(s.size() + spaces.size());

        int spaceIndex = 0;
        for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
            if (spaceIndex < spaces.size() &&
                stringIndex == spaces[spaceIndex]) {
                // Insert space at the correct position
                result += ' ';
                ++spaceIndex;
            }
            // Append the current character
            result += s[stringIndex];
        }

        return result;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String addSpaces(String s, int[] spaces) {
        StringBuilder result = new StringBuilder();
        // Pre-allocate space for efficiency
        result.ensureCapacity(s.length() + spaces.length);

        int spaceIndex = 0;
        for (int stringIndex = 0; stringIndex < s.length(); ++stringIndex) {
            if (
                spaceIndex < spaces.length && stringIndex == spaces[spaceIndex]
            ) {
                // Insert space at the correct position
                result.append(' ');
                ++spaceIndex;
            }
            // Append the current character
            result.append(s.charAt(stringIndex));
        }

        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = []
        # Pre-allocate approximate space for efficiency
        result = [None] * (len(s) + len(spaces))

        space_index = 0
        string_index = 0

        for char_index in range(len(s)):
            if space_index < len(spaces) and char_index == spaces[space_index]:
                # Insert space at the correct position
                result[string_index] = " "
                string_index += 1
                space_index += 1

            # Append the current character
            result[string_index] = s[char_index]
            string_index += 1

        # Join the list into a string and return only the used portion
        return "".join(result[:string_index])
```

</details>
