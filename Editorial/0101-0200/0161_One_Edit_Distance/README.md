# 161. One Edit Distance

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/one-edit-distance/)  
`Two Pointers` `String`

**Problem Link:** [LeetCode 161 - One Edit Distance](https://leetcode.com/problems/one-edit-distance/)

## Problem

Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

- Insert exactly one character into s to get t.
- Delete exactly one character from s to get t.
- Replace exactly one character of s with a different character to get t.

### Example 1

```text
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
```

### Example 2

```text
Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
```

## Constraints

- 0 <= s.length, t.length <= 104
- s and t consist of lowercase letters, uppercase letters, and digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Edit Distance](https://leetcode.com/problems/edit-distance/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 161. One Edit Distance

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| One pass algorithm | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: One pass algorithm

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool isOneEditDistance(char* s, char* t) {
    int ns = strlen(s);
    int nt = strlen(t);

    // Ensure that s is shorter than t.
    if (ns > nt) return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance
    // if the length diff is more than 1.
    if (nt - ns > 1) return false;

    for (int i = 0; i < ns; i++)
        if (s[i] != t[i])
            // if strings have the same length
            if (ns == nt) return strcmp(s + i + 1, t + i + 1) == 0;
            // If strings have different lengths
            else
                return strcmp(s + i, t + i + 1) == 0;

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return (ns + 1 == nt);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size();
        int nt = t.size();

        // Ensure that s is shorter than t.
        if (ns > nt) return isOneEditDistance(t, s);

        // The strings are NOT one edit away distance
        // if the length diff is more than 1.
        if (nt - ns > 1) return false;

        for (int i = 0; i < ns; i++)
            if (s[i] != t[i])
                // if strings have the same length
                if (ns == nt) return s.substr(i + 1) == t.substr(i + 1);
                // If strings have different lengths
                else
                    return s.substr(i) == t.substr(i + 1);

        // If there are no diffs in ns distance
        // The strings are one edit away only if
        // t has one more character.
        return (ns + 1 == nt);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool IsOneEditDistance(string s, string t) {
        int ns = s.Length;
        int nt = t.Length;

        // Ensure that s is shorter than t.
        if (ns > nt)
            return IsOneEditDistance(t, s);

        // The strings are NOT one edit away from distance  
        // if the length diff is more than 1.
        if (nt - ns > 1)
            return false;

        for (int i = 0; i < ns; i++)
            if (s[i] != t[i])
                // If strings have the same length
                if (ns == nt)
                    return s.Substring(i + 1) == t.Substring(i + 1);
                // If strings have different lengths
                else
                    return s.Substring(i) == t.Substring(i + 1);

        // If there are no diffs in ns distance
        // The strings are one edit away only if
        // t has one more character. 
        return ns + 1 == nt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func isOneEditDistance(s string, t string) bool {
    ns := len(s)
    nt := len(t)

    // Ensure that s is shorter than t.
    if ns > nt {
        return isOneEditDistance(t, s)
    }

    // The strings are NOT one edit away from distance
    // if the length diff is more than 1.
    if nt-ns > 1 {
        return false
    }

    for i := 0; i < ns; i++ {
        if s[i] != t[i] {
            // If strings have the same length
            if ns == nt {
                return s[i+1:] == t[i+1:]
            } else { // If strings have different lengths
                return s[i:] == t[i+1:]
            }
        }
    }

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return ns+1 == nt
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public boolean isOneEditDistance(String s, String t) {
        int ns = s.length();
        int nt = t.length();

        // Ensure that s is shorter than t.
        if (ns > nt) return isOneEditDistance(t, s);

        // The strings are NOT one edit away distance
        // if the length diff is more than 1.
        if (nt - ns > 1) return false;

        for (int i = 0; i < ns; i++) {
            if (s.charAt(i) != t.charAt(i)) {
                if (ns == nt) {
                    // if strings have the same length
                    return s.substring(i + 1).equals(t.substring(i + 1));
                } else {
                    // If strings have different lengths
                    return s.substring(i).equals(t.substring(i + 1));
                }
            }
        }

        // If there are no diffs in ns distance
        // The strings are one edit away only if
        // t has one more character.
        return (ns + 1 == nt);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var isOneEditDistance = function (s, t) {
    let ns = s.length;
    let nt = t.length;

    // Ensure that s is shorter than t.
    if (ns > nt) return isOneEditDistance(t, s);

    // The strings are NOT one edit away distance
    // if the length diff is more than 1.
    if (nt - ns > 1) return false;

    for (let i = 0; i < ns; i++)
        if (s[i] != t[i])
            if (ns == nt)
                // if strings have the same length
                return s.slice(i + 1) === t.slice(i + 1);
            // If strings have different lengths
            else return s.slice(i) === t.slice(i + 1);

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return ns + 1 === nt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def isOneEditDistance(self, s: "str", t: "str") -> "bool":
        ns, nt = len(s), len(t)

        # Ensure that s is shorter than t.
        if ns > nt:
            return self.isOneEditDistance(t, s)

        # The strings are NOT one edit away from distance
        # if the length diff is more than 1.
        if nt - ns > 1:
            return False

        for i in range(ns):
            if s[i] != t[i]:
                # If strings have the same length
                if ns == nt:
                    return s[i + 1 :] == t[i + 1 :]
                # If strings have different lengths
                else:
                    return s[i:] == t[i + 1 :]

        # If there are no diffs in ns distance
        # The strings are one edit away only if
        # t has one more character.
        return ns + 1 == nt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function isOneEditDistance(s: string, t: string): boolean {
    let ns: number = s.length;
    let nt: number = t.length;

    // Ensure that s is shorter than t.
    if (ns > nt) return isOneEditDistance(t, s);

    // The strings are NOT one edit away from distance
    // if the length diff is more than 1.
    if (nt - ns > 1) return false;

    for (let i = 0; i < ns; i++)
        if (s[i] != t[i])
            if (ns == nt)
                // If strings have the same length
                return s.slice(i + 1) === t.slice(i + 1);
            // If strings have different lengths
            else return s.slice(i) === t.slice(i + 1);

    // If there are no diffs in ns distance
    // The strings are one edit away only if
    // t has one more character.
    return ns + 1 === nt;
}
```

</details>
