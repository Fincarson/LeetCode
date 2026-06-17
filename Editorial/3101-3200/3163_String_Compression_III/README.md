# 3163. String Compression III

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/string-compression-iii/)  
`String`

**Problem Link:** [LeetCode 3163 - String Compression III](https://leetcode.com/problems/string-compression-iii/)

## Problem

Given a string word, compress it using the following algorithm:

- Begin with an empty string comp. While word is not empty, use the following operation:

		Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
		Append the length of the prefix followed by c to comp.

Return the string comp.

### Example 1

### Example 2

## Constraints

- 1 <= word.length <= 2 * 105
- word consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [String Compression](https://leetcode.com/problems/string-compression/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [String Compression II](https://leetcode.com/problems/string-compression-ii/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3163. String Compression III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: String Manipulation | C++, Java, Python3 |

## Approach: String Manipulation

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        // pos tracks our position in the input string
        int pos = 0;

        // Process until we reach end of string
        while (pos < word.length()) {
            int consecutiveCount = 0;

            char currentChar = word[pos];

            // Count consecutive occurrences (maximum 9)
            while (pos < word.length() && consecutiveCount < 9 &&
                   word[pos] == currentChar) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character to result
            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder("");

        // pos tracks our position in the input string
        int pos = 0;

        // Process until we reach end of string
        while (pos < word.length()) {
            int consecutiveCount = 0;

            char currentChar = word.charAt(pos);

            // Count consecutive occurrences (maximum 9)
            while (
                pos < word.length() &&
                consecutiveCount < 9 &&
                word.charAt(pos) == currentChar
            ) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character to result
            comp.append(consecutiveCount).append(currentChar);
        }

        return comp.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def compressedString(self, word: str) -> str:
        comp = []

        # pos tracks our position in the input string
        pos = 0

        # Process until we reach end of string
        while pos < len(word):
            consecutive_count = 0

            current_char = word[pos]

            # Count consecutive occurrences (maximum 9)
            while (
                pos < len(word)
                and consecutive_count < 9
                and word[pos] == current_char
            ):
                consecutive_count += 1
                pos += 1

            # Append count followed by character to the list
            comp.append(str(consecutive_count))
            comp.append(current_char)

        # Join the list into a single string for the final result
        return "".join(comp)
```

</details>
