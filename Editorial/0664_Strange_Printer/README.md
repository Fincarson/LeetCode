# 664. Strange Printer

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/strange-printer/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 664 - Strange Printer](https://leetcode.com/problems/strange-printer/)

## Problem

There is a strange printer with the following two special properties:

- The printer can only print a sequence of the same character each time.
- At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.

Given a string s, return the minimum number of turns the printer needed to print it.

### Example 1

```text
Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
```

### Example 2

```text
Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
```

## Constraints

- 1 <= s.length <= 100
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Remove Boxes](https://leetcode.com/problems/remove-boxes/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Strange Printer II](https://leetcode.com/problems/strange-printer-ii/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 664. Strange Printer

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top Down Dynamic Programming (Memoization) | C++, Java, Python3 |
| Bottom Up Dynamic Programming (Tabulation) | C++, Java, Python3 |

## Approach 1: Top Down Dynamic Programming (Memoization)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int strangePrinter(string s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.length();
        // Initialize memoization array
        vector<vector<int>> memo(n, vector<int>(n, -1));
        // Start the recursive process
        return minimumTurns(0, n - 1, s, memo);
    }

private:
    int minimumTurns(int start, int end, string& s, vector<vector<int>>& memo) {
        // Base case: empty string requires 0 turns
        if (start > end) {
            return 0;
        }

        // If result is memoized, return it
        if (memo[start][end] != -1) {
            return memo[start][end];
        }

        // Initialize with worst case: print each character separately
        int minTurns = 1 + minimumTurns(start + 1, end, s, memo);

        // Try to optimize by finding matching characters
        for (int k = start + 1; k <= end; k++) {
            if (s[k] == s[start]) {
                // If match found, try splitting the problem
                int turnsWithMatch = minimumTurns(start, k - 1, s, memo) +
                                     minimumTurns(k + 1, end, s, memo);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        // Memoize and return the result
        return memo[start][end] = minTurns;
    }

    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int strangePrinter(String s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.length();
        // Initialize memoization array
        Integer[][] memo = new Integer[n][n];
        // Start the recursive process
        return minimumTurns(0, n - 1, s, memo);
    }

    private int minimumTurns(int start, int end, String s, Integer[][] memo) {
        // Base case: empty string requires 0 turns
        if (start > end) {
            return 0;
        }

        // If result is memoized, return it
        if (memo[start][end] != null) {
            return memo[start][end];
        }

        // Initialize with worst case: print each character separately
        int minTurns = 1 + minimumTurns(start + 1, end, s, memo);

        // Try to optimize by finding matching characters
        for (int k = start + 1; k <= end; k++) {
            if (s.charAt(k) == s.charAt(start)) {
                // If match found, try splitting the problem
                int turnsWithMatch =
                    minimumTurns(start, k - 1, s, memo) +
                    minimumTurns(k + 1, end, s, memo);
                minTurns = Math.min(minTurns, turnsWithMatch);
            }
        }

        // Memoize and return the result
        return memo[start][end] = minTurns;
    }

    private String removeDuplicates(String s) {
        StringBuilder uniqueChars = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            char currentChar = s.charAt(i);
            uniqueChars.append(currentChar);
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s.charAt(i) == currentChar) {
                i++;
            }
        }
        return uniqueChars.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strangePrinter(self, s: str) -> int:
        # Preprocess the string to remove consecutive duplicate characters
        s = "".join(char for char, _ in itertools.groupby(s))

        memo = {}

        def _minimum_turns(start, end) -> int:
            # Base case: empty string requires 0 turns
            if start > end:
                return 0

            # If result is memoized, return it
            if (start, end) in memo:
                return memo[(start, end)]

            # Initialize with worst case: print each character separately
            min_turns = 1 + _minimum_turns(start + 1, end)

            # Try to optimize by finding matching characters
            for k in range(start + 1, end + 1):
                if s[k] == s[start]:
                    # If match found, try splitting the problem
                    turns_with_match = _minimum_turns(
                        start, k - 1
                    ) + _minimum_turns(k + 1, end)
                    min_turns = min(min_turns, turns_with_match)

            # Memoize and return the result
            memo[(start, end)] = min_turns
            return min_turns

        # Start the recursive process
        return _minimum_turns(0, len(s) - 1)
```

</details>

<br>

## Approach 2: Bottom Up Dynamic Programming (Tabulation)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int strangePrinter(string s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);
        int n = s.length();

        // dp[i][j] represents the minimum number of turns to print s[i] to s[j]
        vector<vector<int>> minTurns(n, vector<int>(n, 0));

        // Initialize base case
        for (int i = 0; i < n; i++) {
            // It takes 1 turn to print a single character
            minTurns[i][i] = 1;
        }

        // Fill the dp table
        for (int length = 2; length <= n; length++) {
            for (int start = 0; start + length - 1 < n; start++) {
                int end = start + length - 1;

                // Initialize with worst case: print each character separately
                minTurns[start][end] = length;

                // Try all possible splits and find the minimum
                for (int split = 0; split < length - 1; split++) {
                    int totalTurns = minTurns[start][start + split] +
                                     minTurns[start + split + 1][end];

                    // If the characters at the split and end match, we can save
                    // one turn
                    if (s[start + split] == s[end]) {
                        totalTurns--;
                    }

                    minTurns[start][end] =
                        min(minTurns[start][end], totalTurns);
                }
            }
        }

        // Return the minimum turns needed to print the entire string
        return minTurns[0][n - 1];
    }

private:
    string removeDuplicates(string& s) {
        string uniqueChars;
        int i = 0;
        while (i < s.length()) {
            char currentChar = s[i];
            uniqueChars += currentChar;
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s[i] == currentChar) {
                i++;
            }
        }
        return uniqueChars;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int strangePrinter(String s) {
        // Preprocess the string to remove consecutive duplicate characters
        s = removeDuplicates(s);

        int n = s.length();

        // dp[i][j] represents the minimum number of turns to print s[i] to s[j]
        int[][] minTurns = new int[n][n];

        // Initialize base case
        for (int i = 0; i < n; i++) {
            // It takes 1 turn to print a single character
            minTurns[i][i] = 1;
        }

        // Fill the dp table
        for (int length = 2; length <= n; length++) {
            for (int start = 0; start + length - 1 < n; start++) {
                int end = start + length - 1;

                // Initialize with worst case: print each character separately
                minTurns[start][end] = length;

                // Try all possible splits and find the minimum
                for (int split = 0; split < length - 1; split++) {
                    int totalTurns =
                        minTurns[start][start + split] +
                        minTurns[start + split + 1][end];

                    // If the characters at the split and end match, we can save one turn
                    if (s.charAt(start + split) == s.charAt(end)) {
                        totalTurns--;
                    }

                    minTurns[start][end] = Math.min(
                        minTurns[start][end],
                        totalTurns
                    );
                }
            }
        }

        // Return the minimum turns needed to print the entire string
        return minTurns[0][n - 1];
    }

    private String removeDuplicates(String s) {
        StringBuilder uniqueChars = new StringBuilder();
        int i = 0;
        while (i < s.length()) {
            char currentChar = s.charAt(i);
            uniqueChars.append(currentChar);
            // Skip all consecutive occurrences of the current character
            while (i < s.length() && s.charAt(i) == currentChar) {
                i++;
            }
        }
        return uniqueChars.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def strangePrinter(self, s: str) -> int:
        # Preprocess the string to remove consecutive duplicate characters
        s = "".join(char for char, _ in itertools.groupby(s))
        n = len(s)

        # min_turns[i][j] represents the minimum number of turns to print s[i] to s[j]
        min_turns = [[0] * n for _ in range(n)]

        # Initialize base case
        for i in range(n):
            # It takes 1 turn to print a single character
            min_turns[i][i] = 1

        # Fill the dp table
        for length in range(2, n + 1):
            for start in range(n - length + 1):
                end = start + length - 1

                # Initialize with worst case: print each character separately
                min_turns[start][end] = length

                # Try all possible splits and find the minimum
                for split in range(length - 1):
                    total_turns = (
                        min_turns[start][start + split]
                        + min_turns[start + split + 1][end]
                    )

                    # If the characters at the split and end match, we can save one turn
                    if s[start + split] == s[end]:
                        total_turns -= 1

                    min_turns[start][end] = min(
                        min_turns[start][end], total_turns
                    )

        # Return the minimum turns needed to print the entire string
        return min_turns[0][n - 1] if n > 0 else 0
```

</details>
