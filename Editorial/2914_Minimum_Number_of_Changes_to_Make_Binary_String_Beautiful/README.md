# 2914. Minimum Number of Changes to Make Binary String Beautiful

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/)  
`String`

**Problem Link:** [LeetCode 2914 - Minimum Number of Changes to Make Binary String Beautiful](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/)

## Problem

You are given a 0-indexed binary string s having an even length.

A string is beautiful if it's possible to partition it into one or more substrings such that:

- Each substring has an even length.
- Each substring contains only 1's or only 0's.

You can change any character in s to 0 or 1.

Return the minimum number of changes required to make the string s beautiful.

### Example 1

```text
Input: s = "1001"
Output: 2
Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
It can be proven that 2 is the minimum number of changes needed to make the string beautiful.
```

### Example 2

```text
Input: s = "10"
Output: 1
Explanation: We change s[1] to 1 to get string "11".
It can be seen that the string "11" is beautiful because we can partition it into "11".
It can be proven that 1 is the minimum number of changes needed to make the string beautiful.
```

### Example 3

```text
Input: s = "0000"
Output: 0
Explanation: We don't need to make any changes as the string "0000" is beautiful already.
```

## Constraints

- 2 <= s.length <= 105
- s has an even length.
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2914. Minimum Number of Changes to Make Binary String Beautiful

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C++, Java, Python3 |
| Greedy (Optimized) | C++, Java, Python3 |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minChanges(string s) {
        // Initialize with first character of string
        char currentChar = s[0];

        int consecutiveCount = 0;
        int minChangesRequired = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If current character matches the previous sequence
            if (s[i] == currentChar) {
                consecutiveCount++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (consecutiveCount % 2 == 0) {
                consecutiveCount = 1;
            }
            // If odd count, we need to change current character
            // to match previous sequence
            else {
                consecutiveCount = 0;
                minChangesRequired++;
            }

            // Update current character for next iteration
            currentChar = s[i];
        }

        return minChangesRequired;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minChanges(String s) {
        // Initialize with first character of string
        char currentChar = s.charAt(0);

        int consecutiveCount = 0;
        int minChangesRequired = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If current character matches the previous sequence
            if (s.charAt(i) == currentChar) {
                consecutiveCount++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (consecutiveCount % 2 == 0) {
                consecutiveCount = 1;
            }
            // If odd count, we need to change current character
            // to match previous sequence
            else {
                consecutiveCount = 0;
                minChangesRequired++;
            }

            // Update current character for next iteration
            currentChar = s.charAt(i);
        }

        return minChangesRequired;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minChanges(self, s: str) -> int:
        # Initialize with first character
        current_char = s[0]

        consecutive_count = 0
        min_changes_required = 0

        # Iterate through each character
        for char in s:
            # If current character matches the previous sequence
            if char == current_char:
                consecutive_count += 1
                continue

            # If we have even count of characters, start new sequence
            if consecutive_count % 2 == 0:
                consecutive_count = 1
            # If odd count, we need to change current character
            else:
                consecutive_count = 0
                min_changes_required += 1

            # Update current character for next iteration
            current_char = char

        return min_changes_required
```

</details>

<br>

## Approach 2: Greedy (Optimized)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minChanges(string s) {
        int minChangesRequired = 0;

        // Check pairs of characters (i, i+1) with step size 2
        for (int i = 0; i < s.length(); i += 2) {
            // If characters in current pair don't match,
            // we need one change to make them equal
            if (s[i] != s[i + 1]) {
                minChangesRequired++;
            }
        }

        return minChangesRequired;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minChanges(String s) {
        int minChangesRequired = 0;

        // Check pairs of characters (i, i+1) with step size 2
        for (int i = 0; i < s.length(); i += 2) {
            // If characters in current pair don't match,
            // we need one change to make them equal
            if (s.charAt(i) != s.charAt(i + 1)) {
                minChangesRequired++;
            }
        }

        return minChangesRequired;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minChanges(self, s: str) -> int:
        min_changes_required = 0

        # Check pairs of characters (i, i+1) with step size 2
        for i in range(0, len(s), 2):
            # If characters in current pair don't match,
            # we need one change to make them equal
            if s[i] != s[i + 1]:
                min_changes_required += 1
        return min_changes_required


"""
pythonic one liner:

class Solution:
    def minChanges(self, s: str) -> int:
        # Count changes needed for each unmatched pair
        return sum(s[i] != s[i + 1] for i in range(0, len(s), 2))
"""
```

</details>
