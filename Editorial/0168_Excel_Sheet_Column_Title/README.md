# 168. Excel Sheet Column Title

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/excel-sheet-column-title/)  
`Math` `String`

**Problem Link:** [LeetCode 168 - Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

## Problem

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

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
Input: columnNumber = 1
Output: "A"
```

### Example 2

```text
Input: columnNumber = 28
Output: "AB"
```

### Example 3

```text
Input: columnNumber = 701
Output: "ZY"
```

## Constraints

- 1 <= columnNumber <= 231 - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Excel Sheet Column Number](https://leetcode.com/problems/excel-sheet-column-number/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Cells in a Range on an Excel Sheet](https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Design Spreadsheet](https://leetcode.com/problems/design-spreadsheet/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 168. Excel Sheet Column Title

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Convert | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Convert

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* convertToTitle(int columnNumber) {
    char* ans = calloc(1020, sizeof(char));
    int i = 0;
    while (columnNumber > 0) {
        columnNumber--;
        // Get the last character and append it at the end of string.
        ans[i++] = columnNumber % 26 + 'A';
        columnNumber = columnNumber / 26;
    }

    // Reverse it, as we appended characters in reverse order.
    int head = 0, tail = i - 1;
    while (head < tail) {
        char temp = ans[head];
        ans[head] = ans[tail];
        ans[tail] = temp;
        head++;
        tail--;
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;

        while (columnNumber) {
            columnNumber--;
            // Get the last character and append it at the end of string.
            ans = ans + (char)((columnNumber) % 26 + 'A');
            columnNumber = (columnNumber) / 26;
        }

        // Reverse it, as we appended characters in reverse order.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string ConvertToTitle(int columnNumber) {
        var ans = new StringBuilder();

        while (columnNumber > 0) {
            columnNumber--;
            // Get the last character and append it at the end of the string.
            ans.Append((char)((columnNumber % 26) + 'A'));
            columnNumber /= 26;
        }

        // Reverse it, as we appended characters in reverse order.
        char[] arr = ans.ToString().ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func convertToTitle(columnNumber int) string {
    ans := []byte{}

    for columnNumber > 0 {
        columnNumber--
        // Get the last character and append it at the end of string.
        ans = append(ans, byte((columnNumber%26)+'A'))
        columnNumber /= 26
    }

    // Reverse it, as we appended characters in reverse order.
    for i, j := 0, len(ans)-1; i < j; i, j = i+1, j-1 {
        ans[i], ans[j] = ans[j], ans[i]
    }

    return string(ans)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder ans = new StringBuilder();

        while (columnNumber > 0) {
            columnNumber--;
            // Get the last character and append it at the end of the string.
            ans.append((char) (((columnNumber) % 26) + 'A'));
            columnNumber = (columnNumber) / 26;
        }

        // Reverse it, as we appended characters in reverse order.
        return ans.reverse().toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var convertToTitle = function (columnNumber) {
    let ans = [];

    while (columnNumber > 0) {
        columnNumber--;
        // Get the last character and append it at the end of string.
        ans.push(String.fromCharCode((columnNumber % 26) + "A".charCodeAt(0)));
        columnNumber = Math.floor(columnNumber / 26);
    }

    // Reverse it, as we appended characters in reverse order.
    return ans.reverse().join("");
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ""
        while columnNumber > 0:
            columnNumber -= 1
            # Get the last character and append it at the end of string.
            ans += chr(columnNumber % 26 + ord("A"))
            columnNumber //= 26

        # Reverse it, as we appended characters in reverse order.
        return ans[::-1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function convertToTitle(columnNumber: number): string {
    let ans: string[] = [];

    while (columnNumber > 0) {
        columnNumber--;
        // Get the last character and append it at the end of string.
        ans.push(String.fromCharCode((columnNumber % 26) + "A".charCodeAt(0)));
        columnNumber = Math.floor(columnNumber / 26);
    }

    // Reverse it, as we appended characters in reverse order.
    return ans.reverse().join("");
}
```

</details>
