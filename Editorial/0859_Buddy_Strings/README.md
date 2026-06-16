# 859. Buddy Strings

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/buddy-strings/)  
`Hash Table` `String`

**Problem Link:** [LeetCode 859 - Buddy Strings](https://leetcode.com/problems/buddy-strings/)

## Problem

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

### Example 1

```text
Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
```

### Example 2

```text
Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
```

### Example 3

```text
Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
```

## Constraints

- 1 <= s.length, goal.length <= 2 * 104
- s and goal consist of lowercase letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Determine if Two Strings Are Close](https://leetcode.com/problems/determine-if-two-strings-are-close/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Check if One String Swap Can Make Strings Equal](https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Make Number of Distinct Characters Equal](https://leetcode.com/problems/make-number-of-distinct-characters-equal/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 859. Buddy Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Solution | C++, Java, JavaScript, Python3 |

## Solution

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            // If we have 2 same characters in string 's',
            // we can swap them and still strings will remain equal.
            vector<int> frequency(26, 0);
            for (auto& ch : s) {
                frequency[ch - 'a'] += 1;
                if (frequency[ch - 'a'] == 2) {
                    return true;
                }
            }
            // Otherwise, if we swap any two characters it will make strings unequal.
            return false;
        }
        
        int firstIndex = -1;
        int secondIndex = -1;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i]) {
                if (firstIndex == -1) {
                    firstIndex = i;
                } else if (secondIndex == -1) {
                    secondIndex = i;
                } else {
                    // We have at least 3 indices with different characters,
                    // thus, we can never make strings equal with only one swap.
                    return false;
                }
            }
        }

        if (secondIndex == -1) {
            // We can't swap if character at only one index is different.
            return false;
        }
        
        // All characters of both the string are same except two indices.
        return s[firstIndex] == goal[secondIndex] && 
               s[secondIndex] == goal[firstIndex];
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean buddyStrings(String s, String goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        if (s.equals(goal)) {
            // If we have 2 same characters in string 's',
            // we can swap them and still the strings will remain equal.
            int[] frequency = new int[26];
            for (char ch : s.toCharArray()) {
                frequency[ch - 'a'] += 1;
                if (frequency[ch - 'a'] == 2) {
                    return true;
                }
            }
            // Otherwise, if we swap any two characters, it will make the strings unequal.
            return false;
        }
        
        int firstIndex = -1;
        int secondIndex = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != goal.charAt(i)) {
                if (firstIndex == -1) {
                    firstIndex = i;
                } else if (secondIndex == -1) {
                    secondIndex = i;
                } else {
                    // We have at least 3 indices with different characters,
                    // thus, we can never make the strings equal with only one swap.
                    return false;
                }
            }
        }

        if (secondIndex == -1) {
            // We can't swap if the character at only one index is different.
            return false;
        }
        
        // All characters of both strings are the same except two indices.
        return s.charAt(firstIndex) == goal.charAt(secondIndex) && 
               s.charAt(secondIndex) == goal.charAt(firstIndex);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var buddyStrings = function(s, goal) {
    if (s.length !== goal.length) {
        return false;
    }

    if (s === goal) {
        // If we have 2 same characters in string 's',
        // we can swap them and still the strings will remain equal.
        const frequency = Array(26).fill(0);
        for (const ch of s) {
            frequency[ch.charCodeAt() - 'a'.charCodeAt()] += 1;
            if (frequency[ch.charCodeAt() - 'a'.charCodeAt()] === 2) {
                return true;
            }
        }
        // Otherwise, if we swap any two characters, it will make the strings unequal.
        return false;
    }

    let firstIndex = -1;
    let secondIndex = -1;

    for (let i = 0; i < s.length; ++i) {
        if (s[i] !== goal[i]) {
            if (firstIndex === -1) {
                firstIndex = i;
            } else if (secondIndex === -1) {
                secondIndex = i;
            } else {
                // We have at least 3 indices with different characters,
                // thus, we can never make the strings equal with only one swap.
                return false;
            }
        }
    }

    if (secondIndex === -1) {
        // We can't swap if the character at only one index is different.
        return false;
    }

    // All characters of both strings are the same except two indices.
    return (s[firstIndex] === goal[secondIndex] && 
            s[secondIndex] === goal[firstIndex]);    
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        if s == goal:
            # If we have 2 same characters in string 's',
            # we can swap them and still the strings will remain equal.
            frequency = [0] * 26
            for ch in s:
                frequency[ord(ch) - ord('a')] += 1
                if frequency[ord(ch) - ord('a')] == 2:
                    return True
            # Otherwise, if we swap any two characters, it will make the strings unequal.
            return False

        firstIndex = -1
        secondIndex = -1

        for i in range(len(s)):
            if s[i] != goal[i]:
                if firstIndex == -1:
                    firstIndex = i
                elif secondIndex == -1:
                    secondIndex = i
                else:
                    # We have at least 3 indices with different characters,
                    # thus, we can never make the strings equal with only one swap.
                    return False

        if secondIndex == -1:
            # We can't swap if the character at only one index is different.
            return False

        # All characters of both strings are the same except two indices.
        return s[firstIndex] == goal[secondIndex] and s[secondIndex] == goal[firstIndex]
```

</details>
