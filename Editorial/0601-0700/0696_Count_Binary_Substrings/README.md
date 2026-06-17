# 696. Count Binary Substrings

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/count-binary-substrings/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 696 - Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/)

## Problem

Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

### Example 1

```text
Input: s = "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
Notice that some of these substrings repeat and are counted the number of times they occur.
Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
```

### Example 2

```text
Input: s = "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Number of Substrings With Fixed Ratio](https://leetcode.com/problems/number-of-substrings-with-fixed-ratio/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Substrings With Dominant Ones](https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 696. Count Binary Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Group By Character [Accepted] | Python3 |
| Approach #2: Linear Scan [Accepted] | Python3 |

## Approach #1: Group By Character [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def countBinarySubstrings(self, s):
        groups = [1]
        for i in xrange(1, len(s)):
            if s[i-1] != s[i]:
                groups.append(1)
            else:
                groups[-1] += 1

        ans = 0
        for i in xrange(1, len(groups)):
            ans += min(groups[i-1], groups[i])
        return ans
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def countBinarySubstrings(self, s):
        groups = [len(list(v)) for _, v in itertools.groupby(s)]
        return sum(min(a, b) for a, b in zip(groups, groups[1:]))
```

</details>

<br>

## Approach #2: Linear Scan [Accepted]

### Implementation

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution(object):
    def countBinarySubstrings(self, s):
        ans, prev, cur = 0, 0, 1
        for i in xrange(1, len(s)):
            if s[i-1] != s[i]:
                ans += min(prev, cur)
                prev, cur = cur, 1
            else:
                cur += 1

        return ans + min(prev, cur)
```

</details>
