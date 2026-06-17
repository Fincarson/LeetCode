# 1790. Check if One String Swap Can Make Strings Equal

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)  
`Hash Table` `String` `Counting`

**Problem Link:** [LeetCode 1790 - Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/)

## Problem

You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

### Example 1

```text
Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
```

### Example 2

```text
Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
```

### Example 3

```text
Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
```

## Constraints

- 1 <= s1.length, s2.length <= 100
- s1.length == s2.length
- s1 and s2 consist of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Buddy Strings](https://leetcode.com/problems/buddy-strings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Make Number of Distinct Characters Equal](https://leetcode.com/problems/make-number-of-distinct-characters-equal/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Almost Equal Pairs I](https://leetcode.com/problems/count-almost-equal-pairs-i/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1790. Check if One String Swap Can Make Strings Equal

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Frequency Map + Check Differences | C++, Java, Python3 |
| Only Check Differences | C++, Java, Python3 |

## Approach 1: Frequency Map + Check Differences

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int s1FrequencyMap[26] = {0};
        int s2FrequencyMap[26] = {0};
        int numDiffs = 0;

        for (int i = 0; i < s1.size(); i++) {
            char s1Char = s1[i];
            char s2Char = s2[i];

            if (s1Char != s2Char) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two
                // strings equal
                if (numDiffs > 2) return false;
            }

            // increment frequencies
            s1FrequencyMap[s1Char - 'a']++;
            s2FrequencyMap[s2Char - 'a']++;
        }

        // check if frequencies are equal
        for (int i = 0; i < 26; i++) {
            if (s1FrequencyMap[i] != s2FrequencyMap[i]) return false;
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

    public boolean areAlmostEqual(String s1, String s2) {
        if (s1.equals(s2)) {
            return true;
        }
        char[] s1FrequencyMap = new char[26];
        char[] s2FrequencyMap = new char[26];
        int numDiffs = 0;

        for (int i = 0; i < s1.length(); i++) {
            char s1Char = s1.charAt(i);
            char s2Char = s2.charAt(i);

            if (s1Char != s2Char) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two strings equal
                if (numDiffs > 2) return false;
            }

            // increment frequencies
            s1FrequencyMap[s1Char - 'a']++;
            s2FrequencyMap[s2Char - 'a']++;
        }

        // check if frequencies are equal
        return Arrays.equals(s1FrequencyMap, s2FrequencyMap);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        s1_frequency_map = [0] * 26
        s2_frequency_map = [0] * 26
        num_diffs = 0

        for i in range(len(s1)):
            s1_char = s1[i]
            s2_char = s2[i]

            if s1_char != s2_char:
                num_diffs += 1
                # num_diffs is more than 2, one string swap will not make two strings equal
                if num_diffs > 2:
                    return False

            # increment frequencies
            s1_frequency_map[ord(s1_char) - ord("a")] += 1
            s2_frequency_map[ord(s2_char) - ord("a")] += 1

        # check if frequencies are equal
        return s1_frequency_map == s2_frequency_map
```

</details>

<br>

## Approach 2: Only Check Differences

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two
                // strings equal
                if (numDiffs > 2)
                    return false;
                else if (numDiffs == 1) {
                    // store the index of first difference
                    firstIndexDiff = i;
                } else {
                    // store the index of second difference
                    secondIndexDiff = i;
                }
            }
        }
        // check if swap is possible
        return s1[firstIndexDiff] == s2[secondIndexDiff] &&
               s1[secondIndexDiff] == s2[firstIndexDiff];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean areAlmostEqual(String s1, String s2) {
        int firstIndexDiff = 0;
        int secondIndexDiff = 0;
        int numDiffs = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                numDiffs++;
                // numDiffs is more than 2, one string swap will not make two strings equal
                if (numDiffs > 2) return false;
                else if (numDiffs == 1) {
                    // store the index of first difference
                    firstIndexDiff = i;
                } else {
                    // store the index of second difference
                    secondIndexDiff = i;
                }
            }
        }
        // check if swap is possible
        return (
            s1.charAt(firstIndexDiff) == s2.charAt(secondIndexDiff) &&
            s1.charAt(secondIndexDiff) == s2.charAt(firstIndexDiff)
        );
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        first_index_diff = 0
        second_index_diff = 0
        num_diffs = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                num_diffs += 1
                # num_diffs is more than 2, one string swap will not make two strings equal
                if num_diffs > 2:
                    return False
                elif num_diffs == 1:
                    # store the index of first difference
                    first_index_diff = i
                else:
                    # store the index of second difference
                    second_index_diff = i
        # check if swap is possible
        return (
            s1[first_index_diff] == s2[second_index_diff]
            and s1[second_index_diff] == s2[first_index_diff]
        )
```

</details>
