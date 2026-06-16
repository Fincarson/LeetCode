# 1957. Delete Characters to Make Fancy String

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)  
`String`

**Problem Link:** [LeetCode 1957 - Delete Characters to Make Fancy String](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)

## Problem

A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

### Example 1

```text
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
```

### Example 2

```text
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
```

### Example 3

```text
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
```

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Find Maximum Removals From Source String](https://leetcode.com/problems/find-maximum-removals-from-source-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1957. Delete Characters to Make Fancy String

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Insert characters in a new string | C++, Java, Python3 |
| In-Place Two-Pointer Approach | C++, Java, Python3 |

## Approach 1: Insert characters in a new string

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int frequency = 1;
        string ans = "";
        ans.push_back(s[0]);

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == prev) {
                frequency++;
            } else {
                prev = s[i];
                frequency = 1;
            }

            if (frequency < 3) ans.push_back(s[i]);
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String makeFancyString(String s) {
        char prev = s.charAt(0);
        int frequency = 1;
        StringBuilder ans = new StringBuilder();
        ans.append(s.charAt(0));
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == prev) {
                // If the current character is equal to the previous character, increment the
                // frequency.
                frequency++;
            } else {
                // Otherwise, we can restart the frequency counter with 1, and store the current
                // character's value in prev.
                prev = s.charAt(i);
                frequency = 1;
            }
            // If the frequency counter has value less than 3, add the character to the
            // answer string.
            if (frequency < 3) ans.append(s.charAt(i));
        }
        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeFancyString(self, s: str) -> str:

        prev = s[0]
        frequency = 1
        ans = s[0]

        for i in range(1, len(s)):
            if s[i] == prev:
                frequency += 1
            else:
                prev = s[i]
                frequency = 1

            if frequency < 3:
                ans += s[i]

        return ans
```

</details>

<br>

## Approach 2: In-Place Two-Pointer Approach

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string makeFancyString(string s) {
        // If size of string is less than 3, return it.
        if (s.length() < 3) {
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); ++i) {
            // If the current character is not equal to the previously inserted
            // two characters, then we can add it to the string.
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
                s[j++] = s[i];
            }
        }

        // Resize the string to the number of characters added in the string,
        // given by j.
        s.resize(j);
        return s;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String makeFancyString(String s) {
        // If the size of the string is less than 3, return it.
        if (s.length() < 3) {
            return s;
        }

        StringBuilder sb = new StringBuilder();
        // Start by appending the first two characters to StringBuilder.
        sb.append(s.charAt(0)).append(s.charAt(1));

        // Iterate from the 3rd character onwards.
        for (int i = 2; i < s.length(); ++i) {
            // If the current character is not equal to the previously inserted
            // two characters, then we can add it to the StringBuilder.
            if (
                s.charAt(i) != sb.charAt(sb.length() - 1) ||
                s.charAt(i) != sb.charAt(sb.length() - 2)
            ) {
                sb.append(s.charAt(i));
            }
        }

        // Convert StringBuilder back to String and return.
        return sb.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def makeFancyString(self, s: str) -> str:
        # If size of string is less than 3, return it.
        if len(s) < 3:
            return s

        # Convert the string to a list for mutability.
        s_list = list(s)
        j = 2

        # Iterate through the string from index 2.
        for i in range(2, len(s)):
            # If the current character is not equal to the previously inserted
            # two characters, then we can add it to the result.
            if s_list[i] != s_list[j - 1] or s_list[i] != s_list[j - 2]:
                s_list[j] = s_list[i]
                j += 1

        # Resize the list to the number of valid characters and join it back into a string.
        return "".join(s_list[:j])
```

</details>
