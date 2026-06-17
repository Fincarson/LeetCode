# 1446. Consecutive Characters

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/consecutive-characters/)  
`String`

**Problem Link:** [LeetCode 1446 - Consecutive Characters](https://leetcode.com/problems/consecutive-characters/)

## Problem

The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

### Example 1

```text
Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
```

### Example 2

```text
Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
```

## Constraints

- 1 <= s.length <= 500
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Max Consecutive Ones](https://leetcode.com/problems/max-consecutive-ones/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Check if an Array Is Consecutive](https://leetcode.com/problems/check-if-an-array-is-consecutive/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Substring of One Repeating Character](https://leetcode.com/problems/longest-substring-of-one-repeating-character/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Minimum Number of Chairs in a Waiting Room](https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1446. Consecutive Characters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: One Pass | Java, Python3 |

## Approach #1: One Pass

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int maxPower(String s) {
        int count = 0;
        int maxCount = 0;
        char previous = ' ';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == previous) {
                // if same as previous one, increase the count
                count++;
            } else {
                // else, reset the count
                count = 1;
                previous = c;
            }
            maxCount = Math.max(maxCount, count);
        }
        return maxCount;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxPower(self, s: str) -> int:
        count = 0
        max_count = 0
        previous = None
        for c in s:
            if c == previous:
                # if same as previous one, increase the count
                count += 1
            else:
                # else, reset the count
                previous = c
                count = 1
            max_count = max(max_count, count)
        return max_count
```

</details>
