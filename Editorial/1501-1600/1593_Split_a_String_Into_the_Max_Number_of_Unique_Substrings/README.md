# 1593. Split a String Into the Max Number of Unique Substrings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)  
`Hash Table` `String` `Backtracking`

**Problem Link:** [LeetCode 1593 - Split a String Into the Max Number of Unique Substrings](https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/)

## Problem

Given a string s, return the maximum number of unique substrings that the given string can be split into.

You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.

A substring is a contiguous sequence of characters within a string.

### Example 1

```text
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
```

### Example 2

```text
Input: s = "aba"
Output: 2
Explanation: One way to split maximally is ['a', 'ba'].
```

### Example 3

```text
Input: s = "aa"
Output: 1
Explanation: It is impossible to split the string any further.
```

## Constraints

- 1 <= s.length <= 16
- s contains only lower case English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1593. Split a String Into the Max Number of Unique Substrings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking | C++, Java, Python3 |
| Backtracking with Pruning | C++, Java, Python3 |

## Approach 1: Backtracking

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        // Base case: If we reach the end of the string, return 0 (no more
        // substrings to add)
        if (start == s.size()) return 0;

        int maxCount = 0;

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            // If the substring is unique
            if (seen.find(substring) == seen.end()) {
                // Add the substring to the seen set
                seen.insert(substring);
                // Recursively count unique substrings from the next position
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                // Backtrack: remove the substring from the seen set
                seen.erase(substring);
            }
        }
        return maxCount;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxUniqueSplit(String s) {
        Set<String> seen = new HashSet<>();
        return backtrack(s, 0, seen);
    }

    private int backtrack(String s, int start, Set<String> seen) {
        // Base case: If we reach the end of the string, return 0 (no more substrings to add)
        if (start == s.length()) return 0;

        int maxCount = 0;

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.length(); ++end) {
            String substring = s.substring(start, end);
            // If the substring is unique
            if (!seen.contains(substring)) {
                // Add the substring to the seen set
                seen.add(substring);
                // Recursively count unique substrings from the next position
                maxCount = Math.max(maxCount, 1 + backtrack(s, end, seen));
                // Backtrack: remove the substring from the seen set
                seen.remove(substring);
            }
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
    def maxUniqueSplit(self, s: str) -> int:
        seen = set()
        return self.backtrack(s, 0, seen)

    def backtrack(self, s, start, seen):
        if start == len(s):
            return 0

        max_count = 0

        for end in range(start + 1, len(s) + 1):
            sub_string = s[start:end]
            if sub_string not in seen:
                seen.add(sub_string)
                max_count = max(max_count, 1 + self.backtrack(s, end, seen))
                seen.remove(sub_string)

        return max_count
```

</details>

<br>

## Approach 2: Backtracking with Pruning

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount;
    }

private:
    void backtrack(const string& s, int start, unordered_set<string>& seen,
                   int count, int& maxCount) {
        // Prune: If the current count plus remaining characters can't exceed
        // maxCount, return
        if (count + (s.size() - start) <= maxCount) return;

        // Base case: If we reach the end of the string, update maxCount
        if (start == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            // If the substring is unique
            if (seen.find(substring) == seen.end()) {
                // Add the substring to the seen set
                seen.insert(substring);
                // Recursively count unique substrings from the next position
                backtrack(s, end, seen, count + 1, maxCount);
                // Backtrack: remove the substring from the seen set
                seen.erase(substring);
            }
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int maxUniqueSplit(String s) {
        Set<String> seen = new HashSet<>();
        int[] maxCount = new int[1];
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount[0];
    }

    private void backtrack(
        String s,
        int start,
        Set<String> seen,
        int count,
        int[] maxCount
    ) {
        // Prune: If the current count plus remaining characters can't exceed maxCount, return
        if (count + (s.length() - start) <= maxCount[0]) return;

        // Base case: If we reach the end of the string, update maxCount
        if (start == s.length()) {
            maxCount[0] = Math.max(maxCount[0], count);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.length(); ++end) {
            String substring = s.substring(start, end);
            // If the substring is unique
            if (!seen.contains(substring)) {
                // Add the substring to the seen set
                seen.add(substring);
                // Recursively count unique substrings from the next position
                backtrack(s, end, seen, count + 1, maxCount);
                // Backtrack: remove the substring from the seen set
                seen.remove(substring);
            }
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        seen = set()
        max_count = [0]
        self.backtrack(s, 0, seen, 0, max_count)
        return max_count[0]

    def backtrack(
        self, s: str, start: int, seen: set, count: int, max_count: list
    ) -> None:
        if count + (len(s) - start) <= max_count[0]:
            return
        if start == len(s):
            max_count[0] = max(max_count[0], count)
            return
        for end in range(start + 1, len(s) + 1):
            sub_string = s[start:end]
            if sub_string not in seen:
                seen.add(sub_string)
                self.backtrack(s, end, seen, count + 1, max_count)
                seen.remove(sub_string)
        return
```

</details>
