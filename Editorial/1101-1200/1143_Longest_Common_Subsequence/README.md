# 1143. Longest Common Subsequence

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-common-subsequence/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1143 - Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

## Problem

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both strings.

### Example 1

```text
Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
```

### Example 2

```text
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
```

### Example 3

```text
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
```

## Constraints

- 1 <= text1.length, text2.length <= 1000
- text1 and text2 consist of only lowercase English characters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Delete Operation for Two Strings](https://leetcode.com/problems/delete-operation-for-two-strings/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Shortest Common Supersequence ](https://leetcode.com/problems/shortest-common-supersequence/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Maximize Number of Subsequences in a String](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Subsequence With the Minimum Score](https://leetcode.com/problems/subsequence-with-the-minimum-score/) | ![Hard](../../../_Misc/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1143. Longest Common Subsequence

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Memoization | Java, Python3 |
| Improved Memoization | Java, Python3 |
| Dynamic Programming | Java, Python3 |
| Dynamic Programming with Space Optimization | Java, Python3 |

## Approach 1: Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
  private int[][] memo;
  private String text1;
  private String text2;
    
  public int longestCommonSubsequence(String text1, String text2) {
    // Make the memo big enough to hold the cases where the pointers
    // go over the edges of the strings.
    this.memo = new int[text1.length() + 1][text2.length() + 1];
    // We need to initialise the memo array to -1's so that we know
    // whether or not a value has been filled in. Keep the base cases
    // as 0's to simplify the later code a bit.
    for (int i = 0; i < text1.length(); i++) {
      for (int j = 0; j < text2.length(); j++) {
        this.memo[i][j] = -1;
      }
    }
    this.text1 = text1;
    this.text2 = text2;
    return memoSolve(0, 0);
  }

  private int memoSolve(int p1, int p2) {        
    // Check whether or not we've already solved this subproblem.
    // This also covers the base cases where p1 == text1.length
    // or p2 == text2.length.
    if (memo[p1][p2] != -1) {
      return memo[p1][p2];
    }

    // Option 1: we don't include text1[p1] in the solution.
    int option1 = memoSolve(p1 + 1, p2);

    // Option 2: We include text1[p1] in the solution, as long as
    // a match for it in text2 at or after p2 exists.
    int firstOccurence = text2.indexOf(text1.charAt(p1), p2);
    int option2 = 0;
    if (firstOccurence != -1) {
      option2 = 1 + memoSolve(p1 + 1, firstOccurence + 1);
    }

    // Add the best answer to the memo before returning it.
    memo[p1][p2] = Math.max(option1, option2);
    return memo[p1][p2];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from functools import lru_cache

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        @lru_cache(maxsize=None)
        def memo_solve(p1, p2):
            
            # Base case: If either string is now empty, we can't match
            # up anymore characters.
            if p1 == len(text1) or p2 == len(text2):
                return 0
            
            # Option 1: We don't include text1[p1] in the solution.
            option_1 = memo_solve(p1 + 1, p2)
            
            # Option 2: We include text1[p1] in the solution, as long as
            # a match for it in text2 at or after p2 exists.
            first_occurence = text2.find(text1[p1], p2)
            option_2 = 0
            if first_occurence != -1:
                option_2 = 1 + memo_solve(p1 + 1, first_occurence + 1)
            
            # Return the best option.
            return max(option_1, option_2)
                
        return memo_solve(0, 0)
```

</details>

<br>

## Approach 2: Improved Memoization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
  private int[][] memo;
  private String text1;
  private String text2;
    
  public int longestCommonSubsequence(String text1, String text2) {
    // Make the memo big enough to hold the cases where the pointers
    // go over the edges of the strings.
    this.memo = new int[text1.length() + 1][text2.length() + 1];
    // We need to initialise the memo array to -1's so that we know
    // whether or not a value has been filled in. Keep the base cases
    // as 0's to simplify the later code a bit.
    for (int i = 0; i < text1.length(); i++) {
      for (int j = 0; j < text2.length(); j++) {
        this.memo[i][j] = -1;
      }
    }
    this.text1 = text1;
    this.text2 = text2;
    return memoSolve(0, 0);
  }

  private int memoSolve(int p1, int p2) {        
    // Check whether or not we've already solved this subproblem.
    // This also covers the base cases where p1 == text1.length
    // or p2 == text2.length.
    if (memo[p1][p2] != -1) {
      return memo[p1][p2];
    }

    // Recursive cases.
    int answer = 0;
    if (text1.charAt(p1) == text2.charAt(p2)) {
      answer = 1 + memoSolve(p1 + 1, p2 + 1);
    } else {
      answer = Math.max(memoSolve(p1, p2 + 1), memoSolve(p1 + 1, p2));
    }
    
    // Add the best answer to the memo before returning it.
    memo[p1][p2] = answer;
    return memo[p1][p2];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from functools import lru_cache
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        @lru_cache(maxsize=None)
        def memo_solve(p1, p2):
            
            # Base case: If either string is now empty, we can't match
            # up anymore characters.
            if p1 == len(text1) or p2 == len(text2):
                return 0
            
            # Recursive case 1.
            if text1[p1] == text2[p2]:
                return 1 + memo_solve(p1 + 1, p2 + 1)
            
            # Recursive case 2.
            else:
                return max(memo_solve(p1, p2 + 1), memo_solve(p1 + 1, p2))
            
        return memo_solve(0, 0)
```

</details>

<br>

## Approach 3: Dynamic Programming

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
  public int longestCommonSubsequence(String text1, String text2) {    
    
    // Make a grid of 0's with text2.length() + 1 columns 
    // and text1.length() + 1 rows.
    int[][] dpGrid = new int[text1.length() + 1][text2.length() + 1];
        
    // Iterate up each column, starting from the last one.
    for (int col = text2.length() - 1; col >= 0; col--) {
      for (int row = text1.length() - 1; row >= 0; row--) {
        // If the corresponding characters for this cell are the same...
        if (text1.charAt(row) == text2.charAt(col)) {
          dpGrid[row][col] = 1 + dpGrid[row + 1][col + 1];
        // Otherwise they must be different...
        } else {
          dpGrid[row][col] = Math.max(dpGrid[row + 1][col], dpGrid[row][col + 1]);
        }
      }
    }
        
    // The original problem's answer is in dp_grid[0][0]. Return it.
    return dpGrid[0][0];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        # Make a grid of 0's with len(text2) + 1 columns 
        # and len(text1) + 1 rows.
        dp_grid = [[0] * (len(text2) + 1) for _ in range(len(text1) + 1)]
        
        # Iterate up each column, starting from the last one.
        for col in reversed(range(len(text2))):
            for row in reversed(range(len(text1))):
                # If the corresponding characters for this cell are the same...
                if text2[col] == text1[row]:
                    dp_grid[row][col] = 1 + dp_grid[row + 1][col + 1]
                # Otherwise they must be different...
                else:
                    dp_grid[row][col] = max(dp_grid[row + 1][col], dp_grid[row][col + 1])
        
        # The original problem's answer is in dp_grid[0][0]. Return it.
        return dp_grid[0][0]
```

</details>

<br>

## Approach 4: Dynamic Programming with Space Optimization

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    
  public int longestCommonSubsequence(String text1, String text2) {    
    
    // If text1 doesn't reference the shortest string, swap them.
    if (text2.length() < text1.length()) {
      String temp = text1;
      text1 = text2;
      text2 = temp;
    }
      
    // The previous column starts with all 0's and like before is 1
    // more than the length of the first word.
    int[] previous = new int[text1.length() + 1];
      
    // Iterate through each column, starting from the last one.
    for (int col = text2.length() - 1; col >= 0; col--) {
      // Create a new array to represent the current column.
      int[] current = new int[text1.length() + 1];  
      for (int row = text1.length() - 1; row >= 0; row--) {
        if (text1.charAt(row) == text2.charAt(col)) {
          current[row] = 1 + previous[row + 1];
        } else {
          current[row] = Math.max(previous[row], current[row + 1]);
        }
      }
      // The current column becomes the previous one.
      previous = current;
    }
        
    // The original problem's answer is in previous[0]. Return it.
    return previous[0];
  }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        
        # If text1 doesn't reference the shortest string, swap them.
        if len(text2) < len(text1):
            text1, text2 = text2, text1
        
        
        # The previous column starts with all 0's and like before is 1
        # more than the length of the first word.
        previous = [0] * (len(text1) + 1)
        
        # Iterate up each column, starting from the last one.
        for col in reversed(range(len(text2))):
            # Create a new array to represent the current column.
            current = [0] * (len(text1) + 1)
            for row in reversed(range(len(text1))):
                if text2[col] == text1[row]:
                    current[row] = 1 + previous[row + 1]
                else:
                    current[row] = max(previous[row], current[row + 1])
            # The current column becomes the previous one.
            previous = current
        
        # The original problem's answer is in previous[0]. Return it.
        return previous[0]
```

</details>
