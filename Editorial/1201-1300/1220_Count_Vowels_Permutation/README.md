# 1220. Count Vowels Permutation

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-vowels-permutation/)  
`Dynamic Programming`

**Problem Link:** [LeetCode 1220 - Count Vowels Permutation](https://leetcode.com/problems/count-vowels-permutation/)

## Problem

Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

- Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
- Each vowel 'a' may only be followed by an 'e'.
- Each vowel 'e' may only be followed by an 'a' or an 'i'.
- Each vowel 'i' may not be followed by another 'i'.
- Each vowel 'o' may only be followed by an 'i' or a 'u'.
- Each vowel 'u' may only be followed by an 'a'.

Since the answer may be too large, return it modulo 10^9 + 7.

### Example 1

```text
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
```

### Example 2

```text
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
```

### Example 3

```text
Input: n = 5
Output: 68
```

## Constraints

- 1 <= n <= 2 * 10^4

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Number of Strings Which Can Be Rearranged to Contain Substring](https://leetcode.com/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1220. Count Vowels Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Dynamic Programming (Bottom-up) | Java, Python3 |
| Dynamic Programming (Bottom-up) with Optimized Space | Java, Python3 |
| Dynamic Programming (Top-down, Recursion) | Java, Python3 |

## Approach 1: Dynamic Programming (Bottom-up)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countVowelPermutation(int n) {

        long[] aVowelPermutationCount = new long[n];
        long[] eVowelPermutationCount = new long[n];
        long[] iVowelPermutationCount = new long[n];
        long[] oVowelPermutationCount = new long[n];
        long[] uVowelPermutationCount = new long[n];

        aVowelPermutationCount[0] = 1L;
        eVowelPermutationCount[0] = 1L;
        iVowelPermutationCount[0] = 1L;
        oVowelPermutationCount[0] = 1L;
        uVowelPermutationCount[0] = 1L;

        int MOD = 1000000007;


        for (int i = 1; i < n; i++) {
            aVowelPermutationCount[i] = (eVowelPermutationCount[i - 1] + iVowelPermutationCount[i - 1] + uVowelPermutationCount[i - 1]) % MOD;
            eVowelPermutationCount[i] = (aVowelPermutationCount[i - 1] + iVowelPermutationCount[i - 1]) % MOD;
            iVowelPermutationCount[i] = (eVowelPermutationCount[i - 1] + oVowelPermutationCount[i - 1]) % MOD;
            oVowelPermutationCount[i] = iVowelPermutationCount[i - 1] % MOD;
            uVowelPermutationCount[i] = (iVowelPermutationCount[i - 1] + oVowelPermutationCount[i - 1]) % MOD;
        }

        long result = 0L;

        result = (aVowelPermutationCount[n - 1] + eVowelPermutationCount[n - 1] + iVowelPermutationCount[n - 1] + oVowelPermutationCount[n - 1] + uVowelPermutationCount[n - 1]) % MOD;


        return (int)result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:

        a_vowel_permutation_count = [1] * n
        e_vowel_permutation_count = [1] * n
        i_vowel_permutation_count = [1] * n
        o_vowel_permutation_count = [1] * n
        u_vowel_permutation_count = [1] * n

        MOD = 10 ** 9 + 7

        for i in range(1, n):
            a_vowel_permutation_count[i] = (e_vowel_permutation_count[i - 1] + i_vowel_permutation_count[i - 1] + u_vowel_permutation_count[i - 1]) % MOD
            e_vowel_permutation_count[i] = (a_vowel_permutation_count[i - 1] + i_vowel_permutation_count[i - 1]) % MOD
            i_vowel_permutation_count[i] = (e_vowel_permutation_count[i - 1] + o_vowel_permutation_count[i - 1]) % MOD
            o_vowel_permutation_count[i] = (i_vowel_permutation_count[i - 1]) % MOD
            u_vowel_permutation_count[i] = (i_vowel_permutation_count[i - 1] + o_vowel_permutation_count[i - 1]) % MOD

        result = 0

        result = (a_vowel_permutation_count[n - 1] + e_vowel_permutation_count[n - 1] + \
                  i_vowel_permutation_count[n - 1] + o_vowel_permutation_count[n - 1] + \
                  u_vowel_permutation_count[n - 1]) % MOD

        return result
```

</details>

<br>

## Approach 2: Dynamic Programming (Bottom-up) with Optimized Space

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int countVowelPermutation(int n) {
        long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        int MOD = 1000000007;

        for (int i = 1; i < n; i++) {
            long aCountNew = (eCount + iCount + uCount) % MOD;
            long eCountNew = (aCount + iCount) % MOD;
            long iCountNew = (eCount + oCount) % MOD;
            long oCountNew = (iCount) % MOD;
            long uCountNew = (iCount + oCount) % MOD;
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
        long result = (aCount + eCount + iCount + oCount + uCount)  % MOD;
        return (int)result;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        # initialize the number of strings ending with a, e, i, o, u
        a_count = e_count = i_count = o_count = u_count = 1
        MOD = 10 ** 9 + 7

        for i in range(1, n):
            a_count_new = (e_count + i_count + u_count) % MOD
            e_count_new = (a_count + i_count) % MOD
            i_count_new = (e_count + o_count) % MOD
            o_count_new = (i_count) % MOD
            u_count_new = (i_count + o_count) % MOD

            # https://docs.python.org/3/reference/expressions.html#evaluation-order
            a_count, e_count, i_count, o_count, u_count = \
                a_count_new, e_count_new, i_count_new, o_count_new, u_count_new

        return (a_count + e_count + i_count + o_count + u_count) % MOD
```

</details>

<br>

## Approach 3: Dynamic Programming (Top-down, Recursion)

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    private long[][] memo;
    private int MOD = 1000000007;
    public int countVowelPermutation(int n) {
        // each row stands for the length of string
        // each column indicates the vowels
        // specifically, a: 0, e: 1, i: 2, o: 3, u: 4
        memo = new long[n][5];
        long result = 0;
        for (int i = 0; i < 5; i++){
            result = (result + vowelPermutationCount(n - 1, i)) % MOD;
        }
        return (int)result;
    }

    public long vowelPermutationCount(int i, int vowel) {
        if (memo[i][vowel] != 0) return memo[i][vowel];
        if (i == 0) {
            memo[i][vowel] = 1;
        } else {
            if (vowel == 0) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 1) + vowelPermutationCount(i - 1, 2) + vowelPermutationCount(i - 1, 4)) % MOD;
            } else if (vowel == 1) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 0) + vowelPermutationCount(i - 1, 2)) % MOD;
            } else if (vowel == 2) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 1) + vowelPermutationCount(i - 1, 3)) % MOD;
            } else if (vowel == 3) {
                memo[i][vowel] = vowelPermutationCount(i - 1, 2);
            } else if (vowel == 4) {
                memo[i][vowel] = (vowelPermutationCount(i - 1, 2) + vowelPermutationCount(i - 1, 3)) % MOD;
            }
        }
        return memo[i][vowel];
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countVowelPermutation(self, n: int) -> int:
        MOD = 10 ** 9 + 7
        @functools.cache
        def vowel_permutation_count(i, vowel):
            total = 1
            if i > 1:
                if vowel == 'a':
                    total = (vowel_permutation_count(i - 1, 'e') + vowel_permutation_count(i - 1, 'i') + vowel_permutation_count(i - 1, 'u')) % MOD
                elif vowel == 'e':
                    total = (vowel_permutation_count(i - 1, 'a') + vowel_permutation_count(i - 1, 'i')) % MOD
                elif vowel == 'i':
                    total = (vowel_permutation_count(i - 1, 'e') + vowel_permutation_count(i - 1, 'o')) % MOD
                elif vowel == 'o':
                    total = vowel_permutation_count(i - 1, 'i')
                else:
                    total = (vowel_permutation_count(i - 1, 'i') + vowel_permutation_count(i - 1, 'o')) % MOD
            return total

        return sum(vowel_permutation_count(n, vowel) for vowel in 'aeiou') % MOD
```

</details>
