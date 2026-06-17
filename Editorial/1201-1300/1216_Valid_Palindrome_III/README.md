# 1216. Valid Palindrome III

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/valid-palindrome-iii/)  
`String` `Dynamic Programming`

**Problem Link:** [LeetCode 1216 - Valid Palindrome III](https://leetcode.com/problems/valid-palindrome-iii/)

## Problem

Given a string s and an integer k, return true if s is a k-palindrome.

A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

### Example 1

```text
Input: s = "abcdeca", k = 2
Output: true
Explanation: Remove 'b' and 'e' characters.
```

### Example 2

```text
Input: s = "abbababa", k = 1
Output: true
```

## Constraints

- 1 <= s.length <= 1000
- s consists of only lowercase English letters.
- 1 <= k <= s.length

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Valid Palindrome II](https://leetcode.com/problems/valid-palindrome-ii/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Valid Palindrome IV](https://leetcode.com/problems/valid-palindrome-iv/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1216. Valid Palindrome III

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Top-Down DP (2D) | C++, Java |
| Bottom-Up DP (2D) | C++, Java |
| Bottom-Up DP (1D) | C++, Java |

## Approach 1: Top-Down DP (2D)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    int isValidPalindrome(string &s, int i, int j) {

        // Base case, only 1 letter remaining.
        if (i == j)
            return 0;

        // Base case 2, only 2 letters remaining.
        if (i == j - 1)
            return s[i] != s[j];

        // Return the precomputed value if exists.
        if (memo[i][j] != -1)
            return memo[i][j];

        // Case 1: Character at `i` equals character at `j`
        if (s[i] == s[j])
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);

        // Case 2: Character at `i` does not equal character at `j`.
        // Either delete character at `i` or delete character at `j`
        // and try to match the two pointers using recursion.
        // We need to take the minimum of the two results and add 1
        // representing the cost of deletion.
        return memo[i][j] = 1 + min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
    bool isValidPalindrome(string s, int k) {
        memo.resize(s.length(), vector<int>(s.length(), -1));

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return isValidPalindrome(s, 0, s.length() - 1) <= k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Integer memo[][];
    int isValidPalindrome(String s, int i, int j) {

        // Base case, only 1 letter remaining.
        if (i == j)
            return 0;

        // Base case 2, only 2 letters remaining.
        if (i == j - 1)
            return s.charAt(i) != s.charAt(j) ? 1 : 0;

        //Return the precomputed value if exists.
        if (memo[i][j] != null)
            return memo[i][j];

        // Case 1: Character at `i` equals character at `j`
        if (s.charAt(i) == s.charAt(j))
            return memo[i][j] = isValidPalindrome(s, i + 1, j - 1);

        // Case 2: Character at `i` does not equal character at `j`.
        // Either delete character at `i` or delete character at `j`
        // and try to match the two pointers using recursion.
        // We need to take the minimum of the two results and add 1
        // representing the cost of deletion.
        return memo[i][j] = 1 + Math.min(isValidPalindrome(s, i + 1, j), isValidPalindrome(s, i, j - 1));
    }
public boolean isValidPalindrome(String s, int k) {
        memo = new Integer[s.length()][s.length()];

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return isValidPalindrome(s, 0, s.length() - 1) <= k;
    }
};
```

</details>

<br>

## Approach 2: Bottom-Up DP (2D)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> memo(s.length(), vector<int>(s.length(), 0));

        // Generate all combinations of `i` and `j` in the correct order.
        for (int i = s.length() - 2; i >= 0; i--)
            for (int j = i + 1; j < s.length(); j++) {

                // Case 1: Character at `i` equals character at `j`
                if (s[i] == s[j])
                    memo[i][j] = memo[i + 1][j - 1];

                // Case 2: Character at `i` does not equal character at `j`.
                // Either delete character at `i` or delete character at `j`
                // and try to match the two pointers using recursion.
                // We need to take the minimum of the two results and add 1
                // representing the cost of deletion.
                else
                    memo[i][j] = 1 + min(memo[i + 1][j], memo[i][j - 1]);
            }

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return memo[0][s.length() - 1] <= k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
public boolean isValidPalindrome(String s, int k) {
        int memo[][] = new int[s.length()][s.length()];

        // Generate all combinations of `i` and `j` in the correct order.
        for (int i = s.length() - 2; i >= 0; i--)
            for (int j = i + 1; j < s.length(); j++) {
                // Case 1: Character at `i` equals character at `j`
                if (s.charAt(i) == s.charAt(j))
                    memo[i][j] = memo[i + 1][j - 1];

                // Case 2: Character at `i` does not equal character at `j`.
                // Either delete character at `i` or delete character at `j`
                // and try to match the two pointers using recursion.
                // We need to take the minimum of the two results and add 1
                // representing the cost of deletion.
                else
                    memo[i][j] = 1 + Math.min(memo[i + 1][j], memo[i][j - 1]);
            }

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return memo[0][s.length() - 1] <= k;
    }
};
```

</details>

<br>

## Approach 3: Bottom-Up DP (1D)

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<int> memo(s.length(), 0);

        // To store the previous required values from memo.
        int temp, prev;

        // Generate all combinations of `i` and `j` in the correct order.
        for (int i = s.length() - 2; i >= 0; i--) {
            // 'prev' stores the value at memo[i+1][j-1];
            prev = 0;
            for (int j = i + 1; j < s.length(); j++) {
                // Store the value of memo[i+1][j] temporarily.
                temp = memo[j];

                // Case 1: Character at `i` equals character at `j`
                if (s[i] == s[j])
                    memo[j] = prev;

                // Case 2: Character at `i` does not equal character at `j`.
                // Either delete character at `i` or delete character at `j`
                // and try to match the two pointers using recursion.
                // We need to take the minimum of the two results and add 1
                // representing the cost of deletion.
                else

                    // memo[j] will contain the value for memo[i+1][j]
                    // memo[j-1] will contain the value for memo[i][j-1]
                    memo[j] = 1 + min(memo[j], memo[j - 1]);

                // Copy the value of memo[i+1][j] to `prev`
                // For the next iteration when j=j+1
                // `prev` will hold the value memo[i+1][j-1];
                prev = temp;
            }
        }

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return memo[s.length() - 1] <= k;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
public boolean isValidPalindrome(String s, int k) {
        int memo[] = new int[s.length()];

        // To store the previous required values from memo.
        int temp, prev;

        // Generate all combinations of `i` and `j` in the correct order.
        for (int i = s.length() - 2; i >= 0; i--) {
            // 'prev' stores the value at memo[i+1][j-1];
            prev = 0;
            for (int j = i + 1; j < s.length(); j++) {
                // Store the value of memo[i+1][j] temporarily.
                temp = memo[j];

                // Case 1: Character at `i` equals character at `j`
                if (s.charAt(i) == s.charAt(j))
                    memo[j] = prev;

                // Case 2: Character at `i` does not equal character at `j`.
                // Either delete character at `i` or delete character at `j`
                // and try to match the two pointers using recursion.
                // We need to take the minimum of the two results and add 1
                // representing the cost of deletion.
                else

                    // memo[j] will contain the value for memo[i+1][j]
                    // memo[j-1] will contain the value for memo[i][j-1]
                    memo[j] = 1 + Math.min(memo[j], memo[j - 1]);

                // Copy the value of memo[i+1][j] to `prev`
                // For the next iteration when j=j+1
                // `prev` will hold the value memo[i+1][j-1];
                prev = temp;
            }
        }

        // Return true if the minimum cost to create a palindrome by only deleting the letters
        // is less than or equal to `k`.
        return memo[s.length() - 1] <= k;
    }
};
```

</details>
