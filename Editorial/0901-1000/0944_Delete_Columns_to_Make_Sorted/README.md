# 944. Delete Columns to Make Sorted

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/delete-columns-to-make-sorted/)  
`Array` `String`

**Problem Link:** [LeetCode 944 - Delete Columns to Make Sorted](https://leetcode.com/problems/delete-columns-to-make-sorted/)

## Problem

You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid.

- For example, strs = ["abc", "bce", "cae"] can be arranged as follows:

```text
abc
bce
cae
```

You want to delete the columns that are not sorted lexicographically. In the above example (0-indexed), columns 0 ('a', 'b', 'c') and 2 ('c', 'e', 'e') are sorted, while column 1 ('b', 'c', 'a') is not, so you would delete column 1.

Return the number of columns that you will delete.

### Example 1

```text
Input: strs = ["cba","daf","ghi"]
Output: 1
Explanation: The grid looks as follows:
  cba
  daf
  ghi
Columns 0 and 2 are sorted, but column 1 is not, so you only need to delete 1 column.
```

### Example 2

```text
Input: strs = ["a","b"]
Output: 0
Explanation: The grid looks as follows:
  a
  b
Column 0 is the only column and is sorted, so you will not delete any columns.
```

### Example 3

```text
Input: strs = ["zyx","wvu","tsr"]
Output: 3
Explanation: The grid looks as follows:
  zyx
  wvu
  tsr
All 3 columns are not sorted, so you will delete all 3.
```

## Constraints

- n == strs.length
- 1 <= n <= 100
- 1 <= strs[i].length <= 1000
- strs[i] consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 944. Delete Columns to Make Sorted

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Matrix Traversing | C++, Java |

## Approach 1: Matrix Traversing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // String length.
        int K = strs[0].size();
        
        // Variable to store the count of columns to be deleted.
        int answer = 0;
        // Iterate over each index in the string.
        for (int col = 0; col < K; col++) {
            // Iterate over the strings.
            for (int row = 1; row < strs.size(); row++) {
                // Characters should be in increasing order, 
                // If not, increment the counter.
                if (strs[row][col] < strs[row - 1][col]) {
                    answer++;
                    break;
                }
            }
        }
        
        return answer;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int minDeletionSize(String[] strs) {
        // String length.
        int K = strs[0].length();

        // Variable to store the count of columns to be deleted.
        int answer = 0;
        // Iterate over each index in the string.
        for (int col = 0; col < K; col++) {
            // Iterate over the strings.
            for (int row = 1; row < strs.length; row++) {
                // Characters should be in increasing order, 
                // If not, increment the counter.
                if (strs[row].charAt(col) < strs[row - 1].charAt(col)) {
                    answer++;
                    break;
                }
            }
        }

        return answer;
    }
}
```

</details>
