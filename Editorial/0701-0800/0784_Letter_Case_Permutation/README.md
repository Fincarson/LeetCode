# 784. Letter Case Permutation

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/letter-case-permutation/)  
`String` `Backtracking` `Bit Manipulation`

**Problem Link:** [LeetCode 784 - Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)

## Problem

Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

### Example 1

```text
Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
```

### Example 2

```text
Input: s = "3z4"
Output: ["3z4","3Z4"]
```

## Constraints

- 1 <= s.length <= 12
- s consists of lowercase English letters, uppercase English letters, and digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Subsets](https://leetcode.com/problems/subsets/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Brace Expansion](https://leetcode.com/problems/brace-expansion/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 784. Letter Case Permutation

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach #1: Recursion [Accepted] | Java, Python |
| Approach #2: Binary Mask [Accepted] | Java, Python |
| Approach #3: Built-In Library Function [Accepted] | Python |

## Approach #1: Recursion [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> letterCasePermutation(String S) {
        List<StringBuilder> ans = new ArrayList();
        ans.add(new StringBuilder());

        for (char c: S.toCharArray()) {
            int n = ans.size();
            if (Character.isLetter(c)) {
                for (int i = 0; i < n; ++i) {
                    ans.add(new StringBuilder(ans.get(i)));
                    ans.get(i).append(Character.toLowerCase(c));
                    ans.get(n+i).append(Character.toUpperCase(c));
                }
            } else {
                for (int i = 0; i < n; ++i)
                    ans.get(i).append(c);
            }
        }

        List<String> finalans = new ArrayList();
        for (StringBuilder sb: ans)
            finalans.add(sb.toString());
        return finalans;
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def letterCasePermutation(self, S):
        ans = [[]]

        for char in S:
            n = len(ans)
            if char.isalpha():
                for i in xrange(n):
                    ans.append(ans[i][:])
                    ans[i].append(char.lower())
                    ans[n+i].append(char.upper())
            else:
                for i in xrange(n):
                    ans[i].append(char)

        return map("".join, ans)
```

</details>

<br>

## Approach #2: Binary Mask [Accepted]

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public List<String> letterCasePermutation(String S) {
        int B = 0;
        for (char c: S.toCharArray())
            if (Character.isLetter(c))
                B++;

        List<String> ans = new ArrayList();

        for (int bits = 0; bits < 1<<B; bits++) {
            int b = 0;
            StringBuilder word = new StringBuilder();
            for (char letter: S.toCharArray()) {
                if (Character.isLetter(letter)) {
                    if (((bits >> b++) & 1) == 1)
                        word.append(Character.toLowerCase(letter));
                    else
                        word.append(Character.toUpperCase(letter));
                } else {
                    word.append(letter);
                }
            }

            ans.add(word.toString());
        }

        return ans;

    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def letterCasePermutation(self, S):
        B = sum(letter.isalpha() for letter in S)
        ans = []

        for bits in xrange(1 << B):
            b = 0
            word = []
            for letter in S:
                if letter.isalpha():
                    if (bits >> b) & 1:
                        word.append(letter.lower())
                    else:
                        word.append(letter.upper())

                    b += 1
                else:
                    word.append(letter)

            ans.append("".join(word))
        return ans
```

</details>

<br>

## Approach #3: Built-In Library Function [Accepted]

### Implementation

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def letterCasePermutation(self, S):
        f = lambda x: (x.lower(), x.upper()) if x.isalpha() else x
        return map("".join, itertools.product(*map(f, S)))
```

</details>
