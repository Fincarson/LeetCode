# 830. Positions of Large Groups

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/positions-of-large-groups/)  
`String`

**Problem Link:** [LeetCode 830 - Positions of Large Groups](https://leetcode.com/problems/positions-of-large-groups/)

## Problem

In a string s of lowercase letters, these letters form consecutive groups of the same character.

For example, a string like s = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z", and "yy".

A group is identified by an interval [start, end], where start and end denote the start and end indices (inclusive) of the group. In the above example, "xxxx" has the interval [3,6].

A group is considered large if it has 3 or more characters.

Return the intervals of every large group sorted in increasing order by start index.

### Example 1

```text
Input: s = "abbxxxxzzy"
Output: [[3,6]]
Explanation: "xxxx" is the only large group with start index 3 and end index 6.
```

### Example 2

```text
Input: s = "abc"
Output: []
Explanation: We have groups "a", "b", and "c", none of which are large groups.
```

### Example 3

```text
Input: s = "abcdddeeeeaabbbcd"
Output: [[3,5],[6,9],[12,14]]
Explanation: The large groups are "ddd", "eeee", and "bbb".
```

## Constraints

- 1 <= s.length <= 1000
- s contains lowercase English letters only.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Divide a String Into Groups of Size k](https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 830. Positions of Large Groups

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Two Pointer [Accepted] | Java, Python |

## Approach #1: Two Pointer [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> ans = new ArrayList();
        int i = 0, N = S.length(); // i is the start of each group
        for (int j = 0; j < N; ++j) {
            if (j == N-1 || S.charAt(j) != S.charAt(j+1)) {
                // Here, [i, j] represents a group.
                if (j-i+1 >= 3)
                    ans.add(Arrays.asList(new Integer[]{i, j}));
                i = j + 1;
            }
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
    def largeGroupPositions(self, S):
        ans = []
        i = 0 # The start of each group
        for j in xrange(len(S)):
            if j == len(S) - 1 or S[j] != S[j+1]:
                # Here, [i, j] represents a group.
                if j-i+1 >= 3:
                    ans.append([i, j])
                i = j+1
        return ans
```

</details>
