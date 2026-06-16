# 2083. Substrings That Begin and End With the Same Letter

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)  
`Hash Table` `Math` `String` `Counting` `Prefix Sum`

**Problem Link:** [LeetCode 2083 - Substrings That Begin and End With the Same Letter](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/)

## Problem

You are given a 0-indexed string s consisting of only lowercase English letters. Return the number of substrings in s that begin and end with the same character.

A substring is a contiguous non-empty sequence of characters within a string.

### Example 1

```text
Input: s = "abcba"
Output: 7
Explanation:
The substrings of length 1 that start and end with the same letter are: "a", "b", "c", "b", and "a".
The substring of length 3 that starts and ends with the same letter is: "bcb".
The substring of length 5 that starts and ends with the same letter is: "abcba".
```

### Example 2

```text
Input: s = "abacad"
Output: 9
Explanation:
The substrings of length 1 that start and end with the same letter are: "a", "b", "a", "c", "a", and "d".
The substrings of length 3 that start and end with the same letter are: "aba" and "aca".
The substring of length 5 that starts and ends with the same letter is: "abaca".
```

### Example 3

```text
Input: s = "a"
Output: 1
Explanation:
The substring of length 1 that starts and ends with the same letter is: "a".
```

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Good Pairs](https://leetcode.com/problems/number-of-good-pairs/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Pairs in Two Arrays](https://leetcode.com/problems/count-pairs-in-two-arrays/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Unique Substrings With Equal Digit Frequency](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2083. Substrings That Begin and End With the Same Letter

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Prefix Count | C++, Java, Python3 |
| Counting | C++, Java, Python3 |

## Approach 1: Prefix Count

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        // Number of substrings can exceed the integer range
        long long answer = 0;
        vector<long long> prefixCount(26, 0);

        for (int i = 0; i < s.size(); i++) {
            // Increment the number of times we encountered the current letter
            // so far.
            prefixCount[s[i] - 'a']++;

            // Current letter can be paired with all the occurrences of it that
            // comes before, including itself, to form a valid substring.
            answer += prefixCount[s[i] - 'a'];
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long numberOfSubstrings(String s) {
        int n = s.length();
        // Number of substrings can exceed the integer range
        long answer = 0;
        long[] prefixCount = new long[26];

        for (int i = 0; i < s.length(); i++) {
            // Increment the number of times we encountered the current letter
            // so far.
            prefixCount[s.charAt(i) - 'a']++;

            // Current letter can be paired with all the occurrences of it that
            // comes before, including itself, to form a valid substring.
            answer += prefixCount[s.charAt(i) - 'a'];
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        answer = 0
        prefix_count = [0] * 26

        for i in range(len(s)):
            # Increment the number of times we encountered the current letter so far.
            prefix_count[ord(s[i]) - ord("a")] += 1

            # Current letter can be paired with all the occurrences of it that
            # comes before, including itself, to form a valid substring.
            answer += prefix_count[ord(s[i]) - ord("a")]

        return answer
```

</details>

<br>

## Approach 2: Counting

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    long long numberOfSubstrings(string s) {
        long long answer = 0;
        vector<long long> frequencyCount(26, 0);

        // Count the frequency of each character in the string.
        for (char ch : s) {
            frequencyCount[ch - 'a']++;
        }

        // Calculate the total number of valid substrings.
        for (long long currentCount : frequencyCount) {
            // Using (currentCount + 1) choose 2 to calculate valid substrings
            // for the current letter.
            answer += ((currentCount + 1) * currentCount) / 2;
        }

        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public long numberOfSubstrings(String s) {
        long answer = 0;
        long[] frequencyCount = new long[26];

        // Count the frequency of each character in the string.
        for (char ch : s.toCharArray()) {
            frequencyCount[ch - 'a']++;
        }

        // Calculate the total number of valid substrings.
        for (long currentCount : frequencyCount) {
            // Using (currentCount + 1) choose 2 to calculate valid substrings
            // for the current letter.
            answer += ((currentCount + 1) * currentCount) / 2;
        }

        return answer;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        answer = 0
        frequency_count = [0] * 26

        # Count the frequency of each character in the string.
        for ch in s:
            frequency_count[ord(ch) - ord("a")] += 1

        # Calculate the total number of valid substrings.
        for current_count in frequency_count:
            # Using (current_count + 1) choose 2 to calculate valid substrings
            # for the current letter.
            answer += ((current_count + 1) * current_count) // 2

        return answer
```

</details>
