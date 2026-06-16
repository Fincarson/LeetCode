# 1189. Maximum Number of Balloons

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-number-of-balloons/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 1189 - Maximum Number of Balloons](https://leetcode.com/problems/maximum-number-of-balloons/)

## Problem

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

### Example 1

```text
Input: text = "nlaebolko"
Output: 1
```

### Example 2

```text
Input: text = "loonbalxballpoon"
Output: 2
```

### Example 3

```text
Input: text = "leetcode"
Output: 0
```

## Constraints

- 1 <= text.length <= 104
- text consists of lower case English letters only.

Note: This question is the same as  2287: Rearrange Characters to Make Target String.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1189. Maximum Number of Balloons

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Counting Characters | C++, Java |
| Generalized Solution using an Array | C++, Java, Python3 |

## Approach 1: Counting Characters

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0;

        // Count the frequencey of all the five characters
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == 'b') {
                bCount++;
            } else if (text[i] == 'a') {
                aCount++;
            } else if (text[i] == 'l') {
                lCount++;
            } else if (text[i] == 'o') {
                oCount++;
            } else if (text[i] == 'n') {
                nCount++;
            }
        }

        // Find the potential of each character.
        // Except for 'l' and 'o' the potential is equal to the frequency.
        lCount = lCount / 2;
        oCount = oCount / 2;

        // Find the bottleneck.
        return min({bCount, aCount, lCount, oCount, nCount});
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxNumberOfBalloons(String text) {
        int bCount = 0, aCount = 0, lCount = 0, oCount = 0, nCount = 0;

        // Count the frequencey of all the five characters
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == 'b') {
                bCount++;
            } else if (text.charAt(i) == 'a') {
                aCount++;
            } else if (text.charAt(i) == 'l') {
                lCount++;
            } else if (text.charAt(i) == 'o') {
                oCount++;
            } else if (text.charAt(i) == 'n') {
                nCount++;
            }
        }

        // Find the potential of each character.
        // Except for 'l' and 'o' the potential is equal to the frequency.
        lCount = lCount / 2;
        oCount = oCount / 2;

        // Find the bottleneck.
        return Math.min(bCount, Math.min(aCount, Math.min(lCount, Math.min(oCount, nCount))));
    }
}
```

</details>

<br>

## Approach 2: Generalized Solution using an Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int findMaxNumberofPattern(string text, string pattern) {
        int n = text.length(), m = pattern.length(), answer = INT_MAX;
        int freqInText[26] = {0}, freqInPattern[26] = {0};

        // Frequency of characters in text.
        for (int i = 0; i < n; i++) {
            freqInText[text[i] - 'a']++;
        }
        // Frequency of characters in pattern.
        for (int i = 0; i < m; i++) {
            freqInPattern[pattern[i] - 'a']++;
        }

        // Compare the maximum string that can be produced
        // considering one character at a time.
        for (int i = 0; i < 26; i++) {
            // Do not divide by zero.
            if (freqInPattern[i]) {
                answer = min(answer, freqInText[i] / freqInPattern[i]);
            }
        }

        return answer;
    }

    int maxNumberOfBalloons(string text) {
        // Any string made up of lowercase English letters.
        string pattern = "balloon";
        return findMaxNumberofPattern(text, pattern);
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private int findMaxNumberofPattern(String text, String pattern) {
        int n = text.length(), m = pattern.length(), answer = Integer.MAX_VALUE;
        int freqInText[] = new int[26];
        int freqInPattern[] = new int[26];

        // Frequency of characters in text.
        for (int i = 0; i < n; i++) {
            freqInText[text.charAt(i) - 'a']++;
        }
        // Frequency of characters in pattern.
        for (int i = 0; i < m; i++) {
            freqInPattern[pattern.charAt(i) - 'a']++;
        }

        // Compare the maximum string that can be produced
        // considering one character at a time.
        for (int i = 0; i < 26; i++) {
            // Do not divide by zero.
            if (freqInPattern[i] > 0) {
                answer = Math.min(answer, freqInText[i] / freqInPattern[i]);
            }
        }

        return answer;
    }

    public int maxNumberOfBalloons(String text) {
        // Any string made up of lowercase English letters.
        String pattern = "balloon";
        return findMaxNumberofPattern(text, pattern);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        pattern_str = 'balloon'
        pattern_elem_freq = Counter(pattern_str)
        text_elem_freq = Counter(text)
        max_pattern_count = math.inf

        for char in pattern_str:
            max_pattern_count = min(max_pattern_count, text_elem_freq[char] // pattern_elem_freq[char])

        return max_pattern_count
```

</details>
