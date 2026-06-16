# 1092. Shortest Common Supersequence 

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/shortest-common-supersequence/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1092 - Shortest Common Supersequence ](https://leetcode.com/problems/shortest-common-supersequence/)

## Problem

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

### Example 1

```text
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation:
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
```

### Example 2

```text
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
```

## Constraints

- 1 <= str1.length, str2.length <= 1000
- str1 and str2 consist of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Shortest String That Contains Three Strings](https://leetcode.com/problems/shortest-string-that-contains-three-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1092. Shortest Common Supersequence 

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Backtracking (Time Limit Exceeded) | C++, Java, Python3 |
| Memoization (Memory Limit Exceeded) | C++, Java, Python3 |
| Bottom-Up Dynamic Programming | C++, Java, Python3 |
| Most Optimal - Space Optimized Dynamic Programming | C++, Java, Python3 |

## Approach 1: Backtracking (Time Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        // Base case: both strings are empty
        if (str1.empty() && str2.empty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty()) {
            return str2;
        }

        if (str2.empty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0]) {
            return str1[0] +
                   shortestCommonSupersequence(str1.substr(1), str2.substr(1));
        } else {
            // Try both options: picking from str1 or str2, and choose the
            // shorter one
            string pickStr1 =
                str1[0] + shortestCommonSupersequence(str1.substr(1), str2);
            string pickStr2 =
                str2[0] + shortestCommonSupersequence(str1, str2.substr(1));

            return (pickStr1.length() < pickStr2.length()) ? pickStr1
                                                           : pickStr2;
        }
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        // Base case: both strings are empty
        if (str1.isEmpty() && str2.isEmpty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.isEmpty()) {
            return str2;
        }

        if (str2.isEmpty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1.charAt(0) == str2.charAt(0)) {
            return (
                str1.charAt(0) +
                shortestCommonSupersequence(
                    str1.substring(1),
                    str2.substring(1)
                )
            );
        } else {
            // Try both options: picking from str1 or str2, and choose the shorter one
            String pickStr1 =
                str1.charAt(0) +
                shortestCommonSupersequence(str1.substring(1), str2);
            String pickStr2 =
                str2.charAt(0) +
                shortestCommonSupersequence(str1, str2.substring(1));

            return (pickStr1.length() < pickStr2.length())
                ? pickStr1
                : pickStr2;
        }
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        # Base case: both strings are empty
        if not str1 and not str2:
            return ""

        # Base case: one string is empty, append the other string
        if not str1:
            return str2
        if not str2:
            return str1

        # If the first characters match, include it in the supersequence
        if str1[0] == str2[0]:
            return str1[0] + self.shortestCommonSupersequence(
                str1[1:], str2[1:]
            )
        else:
            # Try both options: picking from str1 or str2, and choose the shorter one
            pick_str1 = str1[0] + self.shortestCommonSupersequence(
                str1[1:], str2
            )
            pick_str2 = str2[0] + self.shortestCommonSupersequence(
                str1, str2[1:]
            )

            return pick_str1 if len(pick_str1) < len(pick_str2) else pick_str2
```

</details>

<br>

## Approach 2: Memoization (Memory Limit Exceeded)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        unordered_map<string, string> memo;
        return helper(str1, str2, memo);
    }

private:
    string helper(string str1, string str2,
                  unordered_map<string, string>& memo) {
        string memoKey = str1 + " " + str2;

        // Check if result is already computed
        if (memo.find(memoKey) != memo.end()) {
            return memo[memoKey];
        }

        // Base case: both strings are empty
        if (str1.empty() && str2.empty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.empty()) {
            return str2;
        }
        if (str2.empty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1[0] == str2[0]) {
            return memo[memoKey] =
                       str1[0] + helper(str1.substr(1), str2.substr(1), memo);
        }

        // Try both options: picking from str1 or str2, and choose the shorter
        // one
        string pickStr1 = str1[0] + helper(str1.substr(1), str2, memo);
        string pickStr2 = str2[0] + helper(str1, str2.substr(1), memo);

        return memo[memoKey] = (pickStr1.length() < pickStr2.length())
                                   ? pickStr1
                                   : pickStr2;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        Map<String, String> memo = new HashMap<>();
        return helper(str1, str2, memo);
    }

    private String helper(String str1, String str2, Map<String, String> memo) {
        String memoKey = str1 + " " + str2;

        // Check if result is already computed
        if (memo.containsKey(memoKey)) {
            return memo.get(memoKey);
        }

        // Base case: both strings are empty
        if (str1.isEmpty() && str2.isEmpty()) {
            return "";
        }

        // Base case: one string is empty, append the other string
        if (str1.isEmpty()) {
            return str2;
        }
        if (str2.isEmpty()) {
            return str1;
        }

        // If the first characters match, include it in the supersequence
        if (str1.charAt(0) == str2.charAt(0)) {
            String result =
                str1.charAt(0) +
                helper(str1.substring(1), str2.substring(1), memo);
            memo.put(memoKey, result);
            return result;
        }

        // Try both options: picking from str1 or str2, and choose the shorter one
        String pickStr1 =
            str1.charAt(0) + helper(str1.substring(1), str2, memo);
        String pickStr2 =
            str2.charAt(0) + helper(str1, str2.substring(1), memo);

        String result = (pickStr1.length() < pickStr2.length())
            ? pickStr1
            : pickStr2;
        memo.put(memoKey, result);
        return result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        memo = {}
        return self.helper(str1, str2, memo)

    def helper(self, str1: str, str2: str, memo: dict) -> str:
        memo_key = (str1, str2)
        # Check if result is already computed
        if memo_key in memo:
            return memo[memo_key]

        # Base case: both strings are empty
        if not str1 and not str2:
            return ""

        # Base case: one string is empty, append the other string
        if not str1:
            return str2
        if not str2:
            return str1

        # If the first characters match, include it in the supersequence
        if str1[0] == str2[0]:
            memo[memo_key] = str1[0] + self.helper(str1[1:], str2[1:], memo)
            return memo[memo_key]

        # Try both options: picking from str1 or str2, and choose the shorter one
        pick_str1 = str1[0] + self.helper(str1[1:], str2, memo)
        pick_str2 = str2[0] + self.helper(str1, str2[1:], memo)

        memo[memo_key] = (
            pick_str1 if len(pick_str1) < len(pick_str2) else pick_str2
        )
        return memo[memo_key]
```

</details>

<br>

## Approach 3: Bottom-Up Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        // Initialize the first row (when str1 is empty, the supersequence is
        // str2's prefix)
        vector<string> prevRow(str2Length + 1);
        for (int col = 0; col <= str2Length; col++) {
            prevRow[col] = str2.substr(0, col);
        }

        // Fill the DP table row by row
        for (int row = 1; row <= str1Length; row++) {
            // Initialize the first column (when str2 is empty, the
            // supersequence is str1's prefix)
            vector<string> currRow(str2Length + 1);
            currRow[0] = str1.substr(0, row);

            for (int col = 1; col <= str2Length; col++) {
                // If characters match, extend the supersequence from the
                // diagonal value
                if (str1[row - 1] == str2[col - 1]) {
                    currRow[col] = prevRow[col - 1] + str1[row - 1];
                } else {
                    // If characters do not match, choose the shorter
                    // supersequence From previous row (exclude current str1
                    // char)
                    string pickS1 = prevRow[col];
                    // From previous column (exclude current str2 char)
                    string pickS2 = currRow[col - 1];

                    currRow[col] = (pickS1.length() < pickS2.length())
                                       ? pickS1 + str1[row - 1]
                                       : pickS2 + str2[col - 1];
                }
            }
            // Move to the next row (update previous row reference)
            prevRow = currRow;
        }

        // Return the shortest common supersequence from the last cell
        return prevRow[str2Length];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        // Initialize the first row (when str1 is empty, the supersequence is str2's prefix)
        String[] prevRow = new String[str2Length + 1];
        for (int col = 0; col <= str2Length; col++) {
            prevRow[col] = str2.substring(0, col);
        }

        // Fill the DP table row by row
        for (int row = 1; row <= str1Length; row++) {
            // Initialize the first column (when str2 is empty, the supersequence is str1's prefix)
            String[] currRow = new String[str2Length + 1];
            currRow[0] = str1.substring(0, row);

            for (int col = 1; col <= str2Length; col++) {
                // If characters match, extend the supersequence from the diagonal value
                if (str1.charAt(row - 1) == str2.charAt(col - 1)) {
                    currRow[col] = prevRow[col - 1] + str1.charAt(row - 1);
                } else {
                    // If characters do not match, choose the shorter supersequence
                    // From previous row (exclude current str1 char)
                    String pickS1 = prevRow[col];
                    // From previous column (exclude current str2 char)
                    String pickS2 = currRow[col - 1];

                    currRow[col] = (pickS1.length() < pickS2.length())
                        ? pickS1 + str1.charAt(row - 1)
                        : pickS2 + str2.charAt(col - 1);
                }
            }
            // Move to the next row (update previous row reference)
            prevRow = currRow;
        }

        // Return the shortest common supersequence from the last cell
        return prevRow[str2Length];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        str1_length = len(str1)
        str2_length = len(str2)

        # Initialize the first row (when str1 is empty, the supersequence is str2's prefix)
        prev_row = [str2[0:col] for col in range(str2_length + 1)]

        # Fill the DP table row by row
        for row in range(1, str1_length + 1):
            # Initialize the first column (when str2 is empty, the supersequence is str1's prefix)
            curr_row = [str1[0:row]] + [None for _ in range(str2_length)]

            for col in range(1, str2_length + 1):
                # If characters match, extend the supersequence from the diagonal value
                if str1[row - 1] == str2[col - 1]:
                    curr_row[col] = prev_row[col - 1] + str1[row - 1]
                else:
                    # If characters do not match, choose the shorter supersequence
                    # From previous row (exclude current str1 char)
                    pick_s1 = prev_row[col]
                    # From previous column (exclude current str2 char)
                    pick_s2 = curr_row[col - 1]

                    curr_row[col] = (
                        pick_s1 + str1[row - 1]
                        if len(pick_s1) < len(pick_s2)
                        else pick_s2 + str2[col - 1]
                    )

            # Move to the next row (update previous row reference)
            prev_row = curr_row

        # Return the shortest common supersequence from the last cell
        return prev_row[str2_length]
```

</details>

<br>

## Approach 4: Most Optimal - Space Optimized Dynamic Programming

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        // Initialize the base cases
        // When str2 is empty, the supersequence is str1 itself
        // (length = row index)
        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        // When str1 is empty, the supersequence is str2 itself
        // (length = col index)
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    // If characters match,
                    // inherit the length from the diagonal + 1
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    // If characters do not match,
                    // take the minimum length option + 1
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                // If characters match, take it from diagonal
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                // If str1’s character is part of the supersequence, move up
                supersequence += str1[row - 1];
                row--;
            } else {
                // If str2’s character is part of the supersequence, move left
                supersequence += str2[col - 1];
                col--;
            }
        }

        // Append any remaining characters
        // If there are leftover characters in str1
        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        // If there are leftover characters in str2
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        // Reverse the built sequence to get the correct order
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String shortestCommonSupersequence(String str1, String str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        int[][] dp = new int[str1Length + 1][str2Length + 1];

        // Initialize the base cases
        // When str2 is empty, the supersequence is str1 itself (length = row index)
        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        // When str1 is empty, the supersequence is str2 itself (length = col index)
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1.charAt(row - 1) == str2.charAt(col - 1)) {
                    // If characters match, inherit the length from the diagonal +1
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    // If characters do not match, take the minimum length option +1
                    dp[row][col] =
                        Math.min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        StringBuilder supersequence = new StringBuilder();
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1.charAt(row - 1) == str2.charAt(col - 1)) {
                // If characters match, take it from diagonal
                supersequence.append(str1.charAt(row - 1));
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                // If str1’s character is part of the supersequence, move up
                supersequence.append(str1.charAt(row - 1));
                row--;
            } else {
                // If str2’s character is part of the supersequence, move left
                supersequence.append(str2.charAt(col - 1));
                col--;
            }
        }

        // Append any remaining characters
        // If there are leftover characters in str1
        while (row > 0) {
            supersequence.append(str1.charAt(row - 1));
            row--;
        }
        // If there are leftover characters in str2
        while (col > 0) {
            supersequence.append(str2.charAt(col - 1));
            col--;
        }

        // Reverse the built sequence to get the correct order
        return supersequence.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        str1_length = len(str1)
        str2_length = len(str2)

        dp = [
            [0 for _ in range(str2_length + 1)] for _ in range(str1_length + 1)
        ]

        # Initialize the base cases
        # When str2 is empty, the supersequence is str1 itself (length = row index)
        for row in range(str1_length + 1):
            dp[row][0] = row

        # When str1 is empty, the supersequence is str2 itself (length = col index)
        for col in range(str2_length + 1):
            dp[0][col] = col

        # Fill the DP table
        for row in range(1, str1_length + 1):
            for col in range(1, str2_length + 1):
                if str1[row - 1] == str2[col - 1]:
                    # If characters match, inherit the length from the diagonal +1
                    dp[row][col] = dp[row - 1][col - 1] + 1
                else:
                    # If characters do not match, take the minimum length option +1
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1

        super_sequence = []
        row, col = str1_length, str2_length

        while row > 0 and col > 0:
            if str1[row - 1] == str2[col - 1]:
                # If characters match, take it from diagonal
                super_sequence.append(str1[row - 1])
                row -= 1
                col -= 1
            elif dp[row - 1][col] < dp[row][col - 1]:
                # If str1’s character is part of the supersequence, move up
                super_sequence.append(str1[row - 1])
                row -= 1
            else:
                # If str2’s character is part of the supersequence, move left
                super_sequence.append(str2[col - 1])
                col -= 1

        # Append any remaining characters
        # If there are leftover characters in str1
        while row > 0:
            super_sequence.append(str1[row - 1])
            row -= 1
        # If there are leftover characters in str2
        while col > 0:
            super_sequence.append(str2[col - 1])
            col -= 1

        # Reverse the built sequence to get the correct order
        return "".join(super_sequence[::-1])
```

</details>
