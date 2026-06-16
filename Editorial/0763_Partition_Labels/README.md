# 763. Partition Labels

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/partition-labels/)  
`Hash Table` `Two Pointers` `String` `Greedy`

**Problem Link:** [LeetCode 763 - Partition Labels](https://leetcode.com/problems/partition-labels/)

## Problem

You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

### Example 1

```text
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
```

### Example 2

```text
Input: s = "eccbbbbdec"
Output: [10]
```

## Constraints

- 1 <= s.length <= 500
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 763. Partition Labels

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Two Pointers | C++, Java, Python3 |
| Merge Intervals | C++, Java, Python3 |

## Approach 1: Two Pointers

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Stores the last index of each character in 's'
        vector<int> lastOccurrence(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        int partitionEnd = 0, partitionStart = 0;
        vector<int> partitionSizes;
        for (int i = 0; i < s.size(); ++i) {
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
            // End of the current partition
            if (i == partitionEnd) {
                partitionSizes.push_back(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partitionSizes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> partitionLabels(String s) {
        // Stores the last index of each character in 's'
        int[] lastOccurrence = new int[26];
        for (int i = 0; i < s.length(); ++i) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }

        int partitionEnd = 0, partitionStart = 0;
        List<Integer> partitionSizes = new ArrayList<>();
        for (int i = 0; i < s.length(); ++i) {
            partitionEnd = Math.max(
                partitionEnd,
                lastOccurrence[s.charAt(i) - 'a']
            );
            // End of the current partition
            if (i == partitionEnd) {
                partitionSizes.add(i - partitionStart + 1);
                partitionStart = i + 1;
            }
        }
        return partitionSizes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # Stores the last index of each character in 's'
        last_occurrence = [0] * 26
        for i, char in enumerate(s):
            last_occurrence[ord(char) - ord("a")] = i

        partition_end = 0
        partition_start = 0
        partition_sizes = []

        for i, char in enumerate(s):
            partition_end = max(
                partition_end, last_occurrence[ord(char) - ord("a")]
            )
            # End of the current partition
            if i == partition_end:
                partition_sizes.append(i - partition_start + 1)
                partition_start = i + 1

        return partition_sizes
```

</details>

<br>

## Approach 2: Merge Intervals

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitionSizes;
        int lastOccurrence[26] = {0}, firstOccurrence[26] = {0};
        int partitionStart = 0, partitionEnd = 0;

        // Store the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            // Store the first occurrence index of each character (if not set)
            if (!firstOccurrence[s[i] - 'a']) {
                firstOccurrence[s[i] - 'a'] = i;
            }

            // If we find a new partition start
            if (partitionEnd < firstOccurrence[s[i] - 'a']) {
                partitionSizes.push_back(partitionEnd - partitionStart + 1);
                partitionStart = i;
                partitionEnd = i;
            }

            // Update partition end boundary
            partitionEnd = max(partitionEnd, lastOccurrence[s[i] - 'a']);
        }

        // Add the last partition if it exists
        if (partitionEnd - partitionStart + 1 > 0) {
            partitionSizes.push_back(partitionEnd - partitionStart + 1);
        }

        return partitionSizes;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public List<Integer> partitionLabels(String s) {
        List<Integer> partitionSizes = new ArrayList<>();
        int[] lastOccurrence = new int[26];
        int[] firstOccurrence = new int[26];
        Arrays.fill(firstOccurrence, -1);

        int partitionStart = 0, partitionEnd = 0;

        // Store the last occurrence index of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            // Store the first occurrence index of each character (if not set)
            if (firstOccurrence[s.charAt(i) - 'a'] == -1) {
                firstOccurrence[s.charAt(i) - 'a'] = i;
            }

            // If we find a new partition start
            if (partitionEnd < firstOccurrence[s.charAt(i) - 'a']) {
                partitionSizes.add(partitionEnd - partitionStart + 1);
                partitionStart = i;
                partitionEnd = i;
            }

            // Update partition end boundary
            partitionEnd = Math.max(
                partitionEnd,
                lastOccurrence[s.charAt(i) - 'a']
            );
        }

        // Add the last partition if it exists
        if (partitionEnd - partitionStart + 1 > 0) {
            partitionSizes.add(partitionEnd - partitionStart + 1);
        }

        return partitionSizes;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        partition_sizes = []
        last_occurrence = [0] * 26
        first_occurrence = [-1] * 26

        partition_start, partition_end = 0, 0

        # Store the last occurrence index of each character
        for i, char in enumerate(s):
            last_occurrence[ord(char) - ord("a")] = i

        for i, char in enumerate(s):
            index = ord(char) - ord("a")

            # Store the first occurrence index of each character (if not set)
            if first_occurrence[index] == -1:
                first_occurrence[index] = i

            # If we find a new partition start
            if partition_end < first_occurrence[index]:
                partition_sizes.append(partition_end - partition_start + 1)
                partition_start = i
                partition_end = i

            # Update partition end boundary
            partition_end = max(partition_end, last_occurrence[index])

        # Add the last partition if it exists
        if partition_end - partition_start + 1 > 0:
            partition_sizes.append(partition_end - partition_start + 1)

        return partition_sizes
```

</details>
