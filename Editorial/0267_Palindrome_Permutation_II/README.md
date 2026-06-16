# 267. Palindrome Permutation II

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/palindrome-permutation-ii/)  
`Hash Table` `String` `Backtracking`

**Problem Link:** [LeetCode 267 - Palindrome Permutation II](https://leetcode.com/problems/palindrome-permutation-ii/)

## Problem

Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.

### Example 1

```text
Input: s = "aabb"
Output: ["abba","baab"]
```

### Example 2

```text
Input: s = "abc"
Output: []
```

## Constraints

- 1 <= s.length <= 16
- s consists of only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Next Permutation](https://leetcode.com/problems/next-permutation/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Permutations II](https://leetcode.com/problems/permutations-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Palindrome Permutation](https://leetcode.com/problems/palindrome-permutation/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 267. Palindrome Permutation II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Brute Force [Time Limit Exceeded] | Java |
| Approach #2 Backtracking [Accepted] | Java |

## Approach #1 Brute Force [Time Limit Exceeded]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Set<String> set = new HashSet<>();

    public List<String> generatePalindromes(String s) {
        permute(s.toCharArray(), 0);
        return new ArrayList<String>(set);
    }

    public boolean isPalindrome(char[] s) {
        for (int i = 0; i < s.length; i++) {
            if (s[i] != s[s.length - 1 - i]) return false;
        }
        return true;
    }

    public void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    void permute(char[] s, int l) {
        if (l == s.length) {
            if (isPalindrome(s)) set.add(new String(s));
        } else {
            for (int i = l; i < s.length; i++) {
                swap(s, l, i);
                permute(s, l + 1);
                swap(s, l, i);
            }
        }
    }
}
```

</details>

<br>

## Approach #2 Backtracking [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    Set<String> set = new HashSet<>();

    public List<String> generatePalindromes(String s) {
        int[] map = new int[128];
        char[] st = new char[s.length() / 2];
        if (!canPermutePalindrome(s, map)) return new ArrayList<>();
        char ch = 0;
        int k = 0;
        for (int i = 0; i < map.length; i++) {
            if (map[i] % 2 == 1) ch = (char) i;
            for (int j = 0; j < map[i] / 2; j++) {
                st[k++] = (char) i;
            }
        }
        permute(st, 0, ch);
        return new ArrayList<String>(set);
    }

    public boolean canPermutePalindrome(String s, int[] map) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[s.charAt(i)]++;
            if (map[s.charAt(i)] % 2 == 0) count--;
            else count++;
        }
        return count <= 1;
    }

    public void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    void permute(char[] s, int l, char ch) {
        if (l == s.length) {
            set.add(
                new String(s) +
                (ch == 0 ? "" : ch) +
                new StringBuffer(new String(s)).reverse()
            );
        } else {
            for (int i = l; i < s.length; i++) {
                if (s[l] != s[i] || l == i) {
                    swap(s, l, i);
                    permute(s, l + 1, ch);
                    swap(s, l, i);
                }
            }
        }
    }
}
```

</details>
