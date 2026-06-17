# 960. Delete Columns to Make Sorted III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/)  
`Array` `String` `Dynamic Programming`

**Problem Link:** [LeetCode 960 - Delete Columns to Make Sorted III](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/)

## Problem

You are given an array of n strings strs, all of the same length.

We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

Suppose we chose a set of deletion indices answer such that after deletions, the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]), and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.

### Example 1

```text
Input: strs = ["babca","bbazb"]
Output: 3
Explanation: After deleting columns 0, 1, and 4, the final array is strs = ["bc", "az"].
Both these rows are individually in lexicographic order (ie. strs[0][0] <= strs[0][1] and strs[1][0] <= strs[1][1]).
Note that strs[0] > strs[1] - the array strs is not necessarily in lexicographic order.
```

### Example 2

```text
Input: strs = ["edcba"]
Output: 4
Explanation: If we delete less than 4 columns, the only row will not be lexicographically sorted.
```

### Example 3

```text
Input: strs = ["ghi","def","abc"]
Output: 0
Explanation: All rows are already lexicographically sorted.
```

## Constraints

- n == strs.length
- 1 <= n <= 100
- 1 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters.

-

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 960. Delete Columns to Make Sorted III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming | Java, Python |

## Approach 1: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDeletionSize(String[] A) {
        int W = A[0].length();
        int[] dp = new int[W];
        Arrays.fill(dp, 1);
        for (int i = W-2; i >= 0; --i)
            search: for (int j = i+1; j < W; ++j) {
                for (String row: A)
                    if (row.charAt(i) > row.charAt(j))
                        continue search;

                dp[i] = Math.max(dp[i], 1 + dp[j]);
            }

        int kept = 0;
        for (int x: dp)
            kept = Math.max(kept, x);
        return W - kept;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def minDeletionSize(self, A):
        W = len(A[0])
        dp = [1] * W
        for i in xrange(W-2, -1, -1):
            for j in xrange(i+1, W):
                if all(row[i] <= row[j] for row in A):
                    dp[i] = max(dp[i], 1 + dp[j])

        return W - max(dp)
```

</details>
