# 392. Is Subsequence

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/is-subsequence/)  
`Two Pointers` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 392 - Is Subsequence](https://leetcode.com/problems/is-subsequence/)

## Problem

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

### Example 1

```text
Input: s = "abc", t = "ahbgdc"
Output: true
```

### Example 2

```text
Input: s = "axc", t = "ahbgdc"
Output: false
```

## Constraints

- 0 <= s.length <= 100
- 0 <= t.length <= 104
- s and t consist only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest Way to Form String](https://leetcode.com/problems/shortest-way-to-form-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Append Characters to String to Make Subsequence](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Make String a Subsequence Using Cyclic Increments](https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 392. Is Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Divide and Conquer with Greedy | Java, Python3 |
| Two-Pointers | Java, Python3 |
| Greedy Match with Character Indices Hashmap | Java, Python3 |
| Dynamic Programming | Java, Python3 |

## Approach 1: Divide and Conquer with Greedy

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    String source, target;
    Integer leftBound, rightBound;

    private boolean rec_isSubsequence(int leftIndex, int rightIndex) {
        // base cases
        if (leftIndex == leftBound)
            return true;
        if (rightIndex == rightBound)
            return false;

        // consume both strings or just the target string
        if (source.charAt(leftIndex) == target.charAt(rightIndex))
            ++leftIndex;
        ++rightIndex;

        return rec_isSubsequence(leftIndex, rightIndex);
    }

    public boolean isSubsequence(String s, String t) {
        this.source = s;
        this.target = t;
        this.leftBound = s.length();
        this.rightBound = t.length();

        return rec_isSubsequence(0, 0);
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        LEFT_BOUND, RIGHT_BOUND = len(s), len(t)

        def rec_isSubsequence(left_index, right_index):
            # base cases
            if left_index == LEFT_BOUND:
                return True
            if right_index == RIGHT_BOUND:
                return False
            # consume both strings or just the target string
            if s[left_index] == t[right_index]:
                left_index += 1
            right_index += 1

            return rec_isSubsequence(left_index, right_index)

        return rec_isSubsequence(0, 0)
```

</details>

<br>

## Approach 2: Two-Pointers

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubsequence(String s, String t) {
        Integer leftBound = s.length(), rightBound = t.length();
        Integer pLeft = 0, pRight = 0;

        while (pLeft < leftBound && pRight < rightBound) {
            // move both pointers or just the right pointer
            if (s.charAt(pLeft) == t.charAt(pRight)) {
                pLeft += 1;
            }
            pRight += 1;
        }
        return pLeft == leftBound;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        LEFT_BOUND, RIGHT_BOUND = len(s), len(t)

        p_left = p_right = 0
        while p_left < LEFT_BOUND and p_right < RIGHT_BOUND:
            # move both pointers or just the right pointer
            if s[p_left] == t[p_right]:
                p_left += 1
            p_right += 1

        return p_left == LEFT_BOUND
```

</details>

<br>

## Approach 3: Greedy Match with Character Indices Hashmap

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubsequence(String s, String t) {

        // precomputation, build the hashmap out of the target string
        HashMap<Character, List<Integer>> letterIndicesTable = new HashMap<>();
        for (int i = 0; i < t.length(); ++i) {
            if (letterIndicesTable.containsKey(t.charAt(i)))
                letterIndicesTable.get(t.charAt(i)).add(i);
            else {
                ArrayList<Integer> indices = new ArrayList<Integer>();
                indices.add(i);
                letterIndicesTable.put(t.charAt(i), indices);
            }
        }

        Integer currMatchIndex = -1;
        for (char letter : s.toCharArray()) {
            if (!letterIndicesTable.containsKey(letter))
                return false; // no match, early exit

            boolean isMatched = false;
            // greedy match with linear search
            for (Integer matchIndex : letterIndicesTable.get(letter)) {
                if (currMatchIndex < matchIndex) {
                    currMatchIndex = matchIndex;
                    isMatched = true;
                    break;
                }
            }

            if (!isMatched)
                return false;
        }

        // consume all characters in the source string
        return true;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:

        letter_indices_table = defaultdict(list)
        for index, letter in enumerate(t):
            letter_indices_table[letter].append(index)

        curr_match_index = -1
        for letter in s:
            if letter not in letter_indices_table:
                return False  # no match at all, early exit

            # greedy match with binary search
            indices_list = letter_indices_table[letter]
            match_index = bisect.bisect_right(indices_list, curr_match_index)
            if match_index != len(indices_list):
                curr_match_index = indices_list[match_index]
            else:
                return False # no suitable match found, early exit

        return True
```

</details>

<br>

## Approach 4: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean isSubsequence(String s, String t) {

        Integer sourceLen = s.length(), targetLen = t.length();
        // the source string is empty
        if (sourceLen == 0)
            return true;

        int[][] dp = new int[sourceLen + 1][targetLen + 1];
        // DP calculation, we fill the matrix column by column, bottom up
        for (int col = 1; col <= targetLen; ++col) {
            for (int row = 1; row <= sourceLen; ++row) {
                if (s.charAt(row - 1) == t.charAt(col - 1))
                    // find another match
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                else
                    // retrieve the maximal result from previous prefixes
                    dp[row][col] = Math.max(dp[row][col - 1], dp[row - 1][col]);
            }
            // check if we can consume the entire source string,
            // with the current prefix of the target string.
            if (dp[sourceLen][col] == sourceLen)
                return true;
        }

        // matching failure
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        source_len, target_len = len(s), len(t)

        # the source string is empty
        if source_len == 0:
            return True

        # matrix to store the history of matches/deletions
        dp = [ [0] * (target_len + 1) for _ in range(source_len + 1)]

        # DP compute, we fill the matrix column by column, bottom up
        for col in range(1, target_len + 1):
            for row in range(1, source_len + 1):
                if s[row - 1] == t[col - 1]:
                    # find another match
                    dp[row][col] = dp[row - 1][col - 1] + 1
                else:
                    # retrieve the maximal result from previous prefixes
                    dp[row][col] = max(dp[row][col - 1], dp[row - 1][col])

            # check if we can consume the entire source string,
            #   with the current prefix of the target string.
            if dp[source_len][col] == source_len:
                return True

        return False
```

</details>
