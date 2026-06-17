# 821. Shortest Distance to a Character

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/shortest-distance-to-a-character/)  
`Array` `Two Pointers` `String`

**Problem Link:** [LeetCode 821 - Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/)

## Problem

Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

### Example 1

```text
Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
```

### Example 2

```text
Input: s = "aaab", c = "b"
Output: [3,2,1,0]
```

## Constraints

- 1 <= s.length <= 104
- s[i] and c are lowercase English letters.
- It is guaranteed that c occurs at least once in s.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Check Distances Between Same Letters](https://leetcode.com/problems/check-distances-between-same-letters/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 821. Shortest Distance to a Character

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Min Array [Accepted] | Java, Python |

## Approach #1: Min Array [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int[] shortestToChar(String S, char C) {
        int N = S.length();
        int[] ans = new int[N];
        int prev = Integer.MIN_VALUE / 2;

        for (int i = 0; i < N; ++i) {
            if (S.charAt(i) == C) prev = i;
            ans[i] = i - prev;
        }

        prev = Integer.MAX_VALUE / 2;
        for (int i = N-1; i >= 0; --i) {
            if (S.charAt(i) == C) prev = i;
            ans[i] = Math.min(ans[i], prev - i);
        }

        return ans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def shortestToChar(self, S, C):
        prev = float('-inf')
        ans = []
        for i, x in enumerate(S):
            if x == C: prev = i
            ans.append(i - prev)

        prev = float('inf')
        for i in xrange(len(S) - 1, -1, -1):
            if S[i] == C: prev = i
            ans[i] = min(ans[i], prev - i)

        return ans
```

</details>
