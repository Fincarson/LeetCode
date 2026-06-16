# 171. Excel Sheet Column Number

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/excel-sheet-column-number/)  
`Math` `String`

**Problem Link:** [LeetCode 171 - Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/)

## Problem

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

```text
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
```

### Example 1

```text
Input: columnTitle = "A"
Output: 1
```

### Example 2

```text
Input: columnTitle = "AB"
Output: 28
```

### Example 3

```text
Input: columnTitle = "ZY"
Output: 701
```

## Constraints

- 1 <= columnTitle.length <= 7
- columnTitle consists only of uppercase English letters.
- columnTitle is in the range ["A", "FXSHRXW"].

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Cells in a Range on an Excel Sheet](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 171. Excel Sheet Column Number

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Right to Left | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Left to Right | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Right to Left

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int titleToNumber(char* s) {
    int i, result = 0, n = strlen(s);

    for (i = 0; i < n; i++) {
        result *= 26;
        result += (s[i] - 64);  // Decimal 65 in ASCII corresponds to char 'A',
                                // but we need it to be '1' for A.
    }

    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;

        // Decimal 65 in ASCII corresponds to char 'A'
        map<char, int> alpha_map;
        for (int i = 0; i < 26; i++) alpha_map[char(i + 65)] = i + 1;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char cur_char = s[n - 1 - i];
            result += (alpha_map[cur_char] * (pow(26, i)));
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TitleToNumber(string s) {
        int result = 0;

        Dictionary<Char, int> alpha_map = new Dictionary<Char, int>();
        for (int i = 0; i < 26; i++) {
            // Decimal 65 in ASCII corresponds to char 'A'
            Char c = Convert.ToChar(i + 65);
            alpha_map[c] = i + 1;
        }

        int n = s.Length;
        for (int i = 0; i < n; i++) {
            char cur_char = s[n - 1 - i];
            result += (alpha_map[cur_char] * ((int)Math.Pow(26, i)));
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func titleToNumber(s string) int {
    result := 0

    alpha_map := make(map[rune]int)
    for i := 0; i < 26; i++ {
        // Decimal 65 in ASCII corresponds to char 'A'
        alpha_map[rune(i+65)] = i + 1
    }

    n := len(s)
    for i := 0; i < n; i++ {
        cur_char := rune(s[n-1-i])
        result += (alpha_map[cur_char] * (pow(26, i)))
    }
    return result
}

// Helper function since Go does not have a built-in power function
func pow(x int, y int) int {
    result := 1
    for i := 0; i < y; i++ {
        result *= x
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int titleToNumber(String s) {
        int result = 0;

        Map<Character, Integer> alpha_map = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            int c = i + 65; // Decimal 65 in ASCII corresponds to char 'A'
            alpha_map.put((char) c, i + 1);
        }

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char cur_char = s.charAt(n - 1 - i);
            result += (alpha_map.get(cur_char) * (Math.pow(26, i)));
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var titleToNumber = function (s) {
    let result = 0;

    const alpha_map = {};
    for (let i = 0; i < 26; i++) {
        // Decimal 65 in ASCII corresponds to char 'A'
        alpha_map[String.fromCharCode(i + 65)] = i + 1;
    }

    const n = s.length;
    for (let i = 0; i < n; i++) {
        let cur_char = s[n - 1 - i];
        result += alpha_map[cur_char] * Math.pow(26, i);
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def titleToNumber(self, s: str) -> int:
        result = 0

        # Decimal 65 in ASCII corresponds to char 'A'
        alpha_map = {chr(i + 65): i + 1 for i in range(26)}

        n = len(s)
        for i in range(n):
            cur_char = s[n - 1 - i]
            result += alpha_map[cur_char] * (26**i)
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function titleToNumber(s: string): number {
    let result: number = 0;

    const alpha_map: { [key: string]: number } = {};
    for (let i: number = 0; i < 26; i++) {
        // Decimal 65 in ASCII corresponds to char 'A'
        alpha_map[String.fromCharCode(i + 65)] = i + 1;
    }

    const n: number = s.length;
    for (let i: number = 0; i < n; i++) {
        const cur_char: string = s[n - 1 - i];
        result += alpha_map[cur_char] * Math.pow(26, i);
    }
    return result;
}
```

</details>

<br>

## Approach 2: Left to Right

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int titleToNumber(char* s) {
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        result = result * 26;
        // In C, subtracting characters is subtracting ASCII values of
        // characters
        result += (s[i] - 'A' + 1);
    }
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            result = result * 26;
            // In C++, subtracting characters is subtracting ASCII values of
            // characters
            result += (s[i] - 'A' + 1);
        }
        return result;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int TitleToNumber(string s) {
        int result = 0;
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            result = result * 26;
            // In C#, subtracting characters is subtracting ASCII values of characters
            result += (s[i] - 'A' + 1);
        }

        return result;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func titleToNumber(s string) int {
    result := 0
    n := len(s)
    for i := 0; i < n; i++ {
        result = result * 26
        // In Go, subtracting runes is subtracting ASCII values of characters
        result += (int(s[i]) - int('A') + 1)
    }
    return result
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int titleToNumber(String s) {
        int result = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            result = result * 26;
            // In Java, subtracting characters is subtracting ASCII values of characters
            result += (s.charAt(i) - 'A' + 1);
        }
        return result;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var titleToNumber = function (s) {
    let result = 0;
    let n = s.length;
    for (let i = 0; i < n; i++) {
        result = result * 26;
        // In JavaScript, subtracting characters is subtracting ASCII values of characters
        result += s.charCodeAt(i) - "A".charCodeAt(0) + 1;
    }
    return result;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def titleToNumber(self, s: str) -> int:
        result = 0
        n = len(s)
        for i in range(n):
            result = result * 26
            result += ord(s[i]) - ord("A") + 1
        return result
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function titleToNumber(s: string): number {
    let result = 0;
    let n = s.length;
    for (let i = 0; i < n; i++) {
        result = result * 26;
        // In Typescript, subtracting characters is subtracting ASCII values of characters
        result += s.charCodeAt(i) - "A".charCodeAt(0) + 1;
    }
    return result;
}
```

</details>
