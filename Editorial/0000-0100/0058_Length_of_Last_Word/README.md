# 58. Length of Last Word

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/length-of-last-word/)  
`String`

**Problem Link:** [LeetCode 58 - Length of Last Word](https://leetcode.com/problems/length-of-last-word/)

## Problem

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

### Example 1

```text
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
```

### Example 2

```text
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
```

### Example 3

```text
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
```

## Constraints

- 1 <= s.length <= 104
- s consists of only English letters and spaces ' '.
- There will be at least one word in s.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 58. Length of Last Word

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| String Index Manipulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| One-loop Iteration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Built-in String Functions | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: String Index Manipulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lengthOfLastWord(char* s) {
    // trim the trailing spaces
    int p = strlen(s) - 1;
    while (p >= 0 && s[p] == ' ') {
        p--;
    }
    // compute the length of last word
    int length = 0;
    while (p >= 0 && s[p] != ' ') {
        p--;
        length++;
    }
    return length;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        // trim the trailing spaces
        int p = s.length() - 1;
        while (p >= 0 && s[p] == ' ') {
            p--;
        }
        // compute the length of last word
        int length = 0;
        while (p >= 0 && s[p] != ' ') {
            p--;
            length++;
        }
        return length;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLastWord(string s) {
        // trim the trailing spaces
        int p = s.Length - 1;
        while (p >= 0 && s[p] == ' ') {
            p--;
        }

        // compute the length of last word
        int length = 0;
        while (p >= 0 && s[p] != ' ') {
            p--;
            length++;
        }

        return length;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLastWord(s string) int {
    // trim the trailing spaces
    p := len(s) - 1
    for p >= 0 && s[p] == ' ' {
        p--
    }
    // compute the length of last word
    length := 0
    for p >= 0 && s[p] != ' ' {
        p--
        length++
    }
    return length
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLastWord(String s) {
        // trim the trailing spaces
        int p = s.length() - 1;
        while (p >= 0 && s.charAt(p) == ' ') {
            p--;
        }

        // compute the length of last word
        int length = 0;
        while (p >= 0 && s.charAt(p) != ' ') {
            p--;
            length++;
        }
        return length;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLastWord = function (s) {
    // trim the trailing spaces
    let p = s.length - 1;
    while (p >= 0 && s[p] === " ") {
        p--;
    }
    // compute the length of last word
    let length = 0;
    while (p >= 0 && s[p] !== " ") {
        p--;
        length++;
    }
    return length;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # trim the trailing spaces
        p = len(s) - 1
        while p >= 0 and s[p] == " ":
            p -= 1

        # compute the length of last word
        length = 0
        while p >= 0 and s[p] != " ":
            p -= 1
            length += 1
        return length
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLastWord(s: string): number {
    // trim the trailing spaces
    let p = s.length - 1;
    while (p >= 0 && s[p] === " ") {
        p--;
    }
    // compute the length of last word
    let length = 0;
    while (p >= 0 && s[p] !== " ") {
        p--;
        length++;
    }
    return length;
}
```

</details>

<br>

## Approach 2: One-loop Iteration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lengthOfLastWord(char* s) {
    int p = strlen(s), length = 0;
    while (p > 0) {
        p--;
        // we're in the middle of the last word
        if (s[p] != ' ') {
            length++;
        }
        // here is the end of last word
        else if (length > 0) {
            return length;
        }
    }
    return length;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int p = s.size(), length = 0;
        while (p > 0) {
            p--;
            // we're in the middle of the last word
            if (s[p] != ' ') {
                length++;
            }
            // here is the end of last word
            else if (length > 0) {
                return length;
            }
        }
        return length;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLastWord(string s) {
        int p = s.Length, length = 0;
        while (p > 0) {
            p--;
            // we're in the middle of the last word
            if (s[p] != ' ') {
                length++;
            }
            // here is the end of last word
            else if (length > 0) {
                return length;
            }
        }

        return length;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLastWord(s string) int {
    p, length := len(s), 0
    for p > 0 {
        p--
        // we're in the middle of the last word
        if s[p:p+1] != " " {
            length++
        } else if length > 0 { // here is the end of last word
            return length
        }
    }
    return length
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int p = s.length(), length = 0;
        while (p > 0) {
            p--;
            // we're in the middle of the last word
            if (s.charAt(p) != ' ') {
                length++;
            }
            // here is the end of last word
            else if (length > 0) {
                return length;
            }
        }
        return length;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLastWord = function (s) {
    var p = s.length,
        length = 0;
    while (p > 0) {
        p--;
        // we're in the middle of the last word
        if (s[p] !== " ") {
            length++;
        }
        // here is the end of last word
        else if (length > 0) {
            return length;
        }
    }
    return length;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        p, length = len(s), 0

        while p > 0:
            p -= 1
            # we're in the middle of the last word
            if s[p] != " ":
                length += 1
            # here is the end of last word
            elif length > 0:
                return length

        return length
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLastWord(s: string): number {
    var p = s.length,
        length = 0;
    while (p > 0) {
        p--;
        // we're in the middle of the last word
        if (s[p] !== " ") {
            length++;
        }
        // here is the end of last word
        else if (length > 0) {
            return length;
        }
    }
    return length;
}
```

</details>

<br>

## Approach 3: Built-in String Functions

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int lengthOfLastWord(char* s) {
    int count = 0;
    int len = strlen(s) - 1;
    // Discard the trailing spaces
    while (len >= 0 && s[len] == ' ') len--;
    // Iterate through the last word
    while (len >= 0 && s[len] != ' ') {
        count++;
        len--;
    }
    return count;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int lastIndex = s.size() - 1;
        // Discard the trailing spaces
        while (lastIndex >= 0 && s[lastIndex] == ' ') lastIndex--;
        // Iterate through the last word
        while (lastIndex >= 0 && s[lastIndex] != ' ') {
            count++;
            lastIndex--;
        }
        return count;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LengthOfLastWord(string s) {
        s = s.Trim();  // trim the trailing spaces in the string
        return s.Length - s.LastIndexOf(" ") - 1;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func lengthOfLastWord(s string) int {
    count := 0
    lastIndex := len(s) - 1
    // Discard the trailing spaces
    for lastIndex >= 0 && s[lastIndex] == ' ' {
        lastIndex--
    }
    // Iterate through the last word
    for lastIndex >= 0 && s[lastIndex] != ' ' {
        count++
        lastIndex--
    }
    return count
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim(); // trim the trailing spaces in the string
        return s.length() - s.lastIndexOf(" ") - 1;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthOfLastWord = function (s) {
    s = s.trim(); // trim the trailing spaces in the string
    return s.length - s.lastIndexOf(" ") - 1;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return 0 if not s or s.isspace() else len(s.split()[-1])
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthOfLastWord(s: string): number {
    s = s.trim(); // trim the trailing spaces in the string
    return s.length - s.lastIndexOf(" ") - 1;
}
```

</details>
