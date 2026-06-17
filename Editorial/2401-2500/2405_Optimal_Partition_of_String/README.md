# 2405. Optimal Partition of String

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/optimal-partition-of-string/)  
`Hash Table` `String` `Greedy`

**Problem Link:** [LeetCode 2405 - Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/)

## Problem

Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

### Example 1

```text
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
```

### Example 2

```text
Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").
```

## Constraints

- 1 <= s.length <= 105
- s consists of only English lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Longest Substring with At Least K Repeating Characters](https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Partition Labels](https://leetcode.com/problems/partition-labels/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Partition Array into Disjoint Intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Maximum Sum of Distinct Subarrays With Length K](https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2405. Optimal Partition of String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C++, Java, Python3 |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        int count = 1, substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }

        return count;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int partitionString(String s) {
        int[] lastSeen = new int[26];
        Arrays.fill(lastSeen, -1);
        int count = 1, substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s.charAt(i) - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s.charAt(i) - 'a'] = i;
        }

        return count;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionString(self, s: str) -> int:
        lastSeen = [-1]*26
        count = 1
        substringStarting = 0

        for i in range(len(s)):
            if lastSeen[ord(s[i]) - ord('a')] >= substringStarting:
                count += 1
                substringStarting = i
            lastSeen[ord(s[i]) - ord('a')] = i

        return count
```

</details>
