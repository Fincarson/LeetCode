# 484. Find Permutation

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/find-permutation/)  
`Array` `String` `Stack` `Greedy`

**Problem Link:** [LeetCode 484 - Find Permutation](https://leetcode.com/problems/find-permutation/)

## Problem

A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s of length n - 1 where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the lexicographically smallest permutation perm and return it.

### Example 1

```text
Input: s = "I"
Output: [1,2]
Explanation: [1,2] is the only legal permutation that can represented by s, where the number 1 and 2 construct an increasing relationship.
```

### Example 2

```text
Input: s = "DI"
Output: [2,1,3]
Explanation: Both [2,1,3] and [3,1,2] can be represented as "DI", but since we want to find the smallest lexicographical permutation, you should return [2,1,3]
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either 'I' or 'D'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Using a Robot to Print the Lexicographically Smallest String](https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 484. Find Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1 Using Stack [Accepted] | Java |
| Approach #2 Reversing the subarray [Accepted] | Java |
| Approach #3 Two pointers [Accepted] | Java |

## Approach #1 Using Stack [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java

public class Solution {
    public int[] findPermutation(String s) {
        int[] res = new int[s.length() + 1];
        Stack < Integer > stack = new Stack < > ();
        int j = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (s.charAt(i - 1) == 'I') {
                stack.push(i);
                while (!stack.isEmpty())
                    res[j++] = stack.pop();
            } else
                stack.push(i);
        }
        stack.push(s.length() + 1);
        while (!stack.isEmpty())
            res[j++] = stack.pop();
        return res;
    }
}
```

</details>

<br>

## Approach #2 Reversing the subarray [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findPermutation(String s) {
        int[] res = new int[s.length() + 1];
        for (int i = 0; i < res.length; i++)
            res[i] = i + 1;
        int i = 1;
        while (i <= s.length()) {
            int j = i;
            while (i <= s.length() && s.charAt(i - 1) == 'D')
                i++;
            reverse(res, j - 1, i);
            i++;
        }
        return res;
    }
    public void reverse(int[] a, int start, int end) {
        for (int i = 0; i < (end - start) / 2; i++) {
            int temp = a[i + start];
            a[i + start] = a[end - i - 1];
            a[end - i - 1] = temp;
        }
    }
}
```

</details>

<br>

## Approach #3 Two pointers [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    public int[] findPermutation(String s) {
        int[] res = new int[s.length() + 1];
        res[0]=1;
        int i = 1;
        while (i <= s.length()) {
            res[i]=i+1;
            int j = i;
            if(s.charAt(i-1)=='D')
            {
                while (i <= s.length() && s.charAt(i - 1) == 'D')
                    i++;
                for (int k = j - 1, c = i; k <= i - 1; k++, c--) {
                    res[k] = c;
                }
            }
            else
                i++;
        }
        return res;
    }
}
```

</details>
