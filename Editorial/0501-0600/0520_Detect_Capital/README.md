# 520. Detect Capital

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/detect-capital/)  
`String`

**Problem Link:** [LeetCode 520 - Detect Capital](https://leetcode.com/problems/detect-capital/)

## Problem

We define the usage of capitals in a word to be right when one of the following cases holds:

- All letters in this word are capitals, like "USA".
- All letters in this word are not capitals, like "leetcode".
- Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

### Example 1

```text
Input: word = "USA"
Output: true
```

### Example 2

```text
Input: word = "FlaG"
Output: false
```

## Constraints

- 1 <= word.length <= 100
- word consists of lowercase and uppercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Capitalize the Title](https://leetcode.com/problems/capitalize-the-title/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Count the Number of Special Characters II](https://leetcode.com/problems/count-the-number-of-special-characters-ii/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count the Number of Special Characters I](https://leetcode.com/problems/count-the-number-of-special-characters-i/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 520. Detect Capital

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Character by Character | Java, Python3 |
| Regex | Java, Python3 |

## Approach 1: Character by Character

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int n = word.length();

        boolean match1 = true, match2 = true, match3 = true;

        // case 1: All capital
        for (int i = 0; i < n; i++) {
            if (!Character.isUpperCase(word.charAt(i))) {
                match1 = false;
                break;
            }
        }
        if (match1) {
            return true;
        }

        // case 2: All not capital
        for (int i = 0; i < n; i++) {
            if (!Character.isLowerCase(word.charAt(i))) {
                match2 = false;
                break;
            }
        }
        if (match2) {
            return true;
        }

        // case 3: All not capital except first
        if (!Character.isUpperCase(word.charAt(0))) {
            match3 = false;
        }
        if (match3) {
            for (int i = 1; i < n; i++) {
                if (!Character.isLowerCase(word.charAt(i))) {
                    match3 = false;
                    break;
                }
            }
        }
        if (match3) {
            return true;
        }

        // if not matching
        return false;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        n = len(word)
            
        match1, match2, match3 = True, True, True

        # case 1: All capital
        for i in range(n):
            if not word[i].isupper():
                match1 = False
                break
        if match1:
            return True

        # case 2: All not capital
        for i in range(n):
            if word[i].isupper():
                match2 = False
                break
        if match2:
            return True

        # case 3: All not capital except first
        if not word[0].isupper():
            match3 = False
        if match3:
            for i in range(1, n):
                if word[i].isupper():
                    match3 = False
                    break
        if match3:
            return True

        # if not matching
        return False
```

</details>

<br>

## Approach 2: Regex

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        return word.matches("[A-Z]*|.[a-z]*");
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
import re

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        return re.fullmatch(r"[A-Z]*|.[a-z]*", word)
```

</details>
