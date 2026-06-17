# 3110. Score of a String

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/score-of-a-string/)  
`String`

**Problem Link:** [LeetCode 3110 - Score of a String](https://leetcode.com/problems/score-of-a-string/)

## Problem

You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.

### Example 1

### Example 2

## Constraints

- 2 <= s.length <= 100
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3110. Score of a String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Linear Iteration | C++, Java, Python3 |

## Approach: Linear Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        // Iterate over all indices from 0 to the second-to-last index
        // Calculate and accumulate the absolute difference of ASCII values
        // between adjacent characters
        for (int i = 0; i < s.size() - 1; ++i) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int scoreOfString(String s) {
        int score = 0;
        // Iterate over all indices from 0 to the second-to-last index
        // Calculate and accumulate the absolute difference of ASCII values
        // between adjacent characters
        for (int i = 0; i < s.length() - 1; i++) {
            score += Math.abs(s.charAt(i) - s.charAt(i + 1));
        }
        return score;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def scoreOfString(self, s: str) -> int:
        score = 0
        # Iterate over all indices from 0 to the second-to-last index
        # Calculate and accumulate the absolute difference of ASCII values
        # between adjacent characters
        for i in range(len(s) - 1):
            score += abs(ord(s[i]) - ord(s[i + 1]))
        return score
```

</details>
