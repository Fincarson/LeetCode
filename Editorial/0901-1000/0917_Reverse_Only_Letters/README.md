# 917. Reverse Only Letters

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/reverse-only-letters/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 917 - Reverse Only Letters](https://leetcode.com/problems/reverse-only-letters/)

## Problem

Given a string s, reverse the string according to the following rules:

- All the characters that are not English letters remain in the same position.
- All the English letters (lowercase or uppercase) should be reversed.

Return s after reversing it.

### Example 1

```text
Input: s = "ab-cd"
Output: "dc-ba"
```

### Example 2

```text
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

### Example 3

```text
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

## Constraints

- 1 <= s.length <= 100
- s consists of characters with ASCII values in the range [33, 122].
- s does not contain '\"' or '\\'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Faulty Keyboard](https://leetcode.com/problems/faulty-keyboard/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Reverse Letters Then Special Characters in a String](https://leetcode.com/problems/reverse-letters-then-special-characters-in-a-string/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 917. Reverse Only Letters

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack of Letters | Java, Python |
| Reverse Pointer | Java, Python |

## Approach 1: Stack of Letters

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        Stack<Character> letters = new Stack();
        for (char c: S.toCharArray())
            if (Character.isLetter(c))
                letters.push(c);

        StringBuilder ans = new StringBuilder();
        for (char c: S.toCharArray()) {
            if (Character.isLetter(c))
                ans.append(letters.pop());
            else
                ans.append(c);
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reverseOnlyLetters(self, S):
        letters = [c for c in S if c.isalpha()]
        ans = []
        for c in S:
            if c.isalpha():
                ans.append(letters.pop())
            else:
                ans.append(c)
        return "".join(ans)
```

</details>

<br>

## Approach 2: Reverse Pointer

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String reverseOnlyLetters(String S) {
        StringBuilder ans = new StringBuilder();
        int j = S.length() - 1;
        for (int i = 0; i < S.length(); ++i) {
            if (Character.isLetter(S.charAt(i))) {
                while (!Character.isLetter(S.charAt(j)))
                    j--;
                ans.append(S.charAt(j--));
            } else {
                ans.append(S.charAt(i));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python</strong></summary>

```python
class Solution(object):
    def reverseOnlyLetters(self, S):
        ans = []
        j = len(ans) - 1
        for i, x in enumerate(S):
            if x.isalpha():
                while not S[j].isalpha():
                    j -= 1
                ans.append(S[j])
                j -= 1
            else:
                ans.append(x)
        
        return "".join(ans)
```

</details>
