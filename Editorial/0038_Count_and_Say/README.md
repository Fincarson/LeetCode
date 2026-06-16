# 38. Count and Say

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-and-say/)  
`String`

**Problem Link:** [LeetCode 38 - Count and Say](https://leetcode.com/problems/count-and-say/)

## Problem

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

- countAndSay(1) = "1"
- countAndSay(n) is the run-length encoding of countAndSay(n - 1).

Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

### Example 1

### Example 2

## Constraints

- 1 <= n <= 30

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [String Compression](https://leetcode.com/problems/string-compression/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 38. Count and Say

## Overview

This section follows the official LeetCode editorial approach list and uses the official embedded playground snippets for the available languages.

| Approach | Languages |
|---|---|
| Straightforward | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Regular Expression | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Straightforward

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* countAndSay(int n) {
    char* currentString = (char*)malloc(sizeof(char) * 5000);
    strcpy(currentString, "1");
    for (int i = 2; i <= n; i++) {
        char* nextString = (char*)malloc(sizeof(char) * 5000);
        int k = 0;
        int ptr = 0;
        for (int j = 0; currentString[j] != '\0'; j = k) {
            while (currentString[k] != '\0' &&
                   currentString[k] == currentString[j])
                k++;
            int diff = k - j;
            sprintf(&nextString[ptr], "%d%c", diff, currentString[j]);
            while (nextString[ptr] != '\0') ptr++;
        }
        free(currentString);
        currentString = nextString;
    }
    return currentString;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string currentString = "1";
        for (int i = 2; i <= n; i++) {
            string nextString;
            for (int j = 0, k = 0; j < currentString.size(); j = k) {
                while (k < currentString.size() &&
                       currentString[k] == currentString[j])
                    k++;
                nextString += to_string(k - j) + currentString[j];
            }
            currentString = nextString;
        }
        return currentString;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string CountAndSay(int n) {
        string currentString = "1";
        for (int i = 2; i <= n; i++) {
            string nextString = "";
            for (int j = 0, k = 0; j < currentString.Length; j = k) {
                while (k < currentString.Length &&
                       currentString[k] == currentString[j])
                    k++;
                nextString += (k - j).ToString() + currentString[j];
            }

            currentString = nextString;
        }

        return currentString;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countAndSay(n int) string {
    currentString := "1"
    for i := 2; i <= n; i++ {
        nextString := ""
        for j, k := 0, 0; j < len(currentString); j = k {
            for k < len(currentString) && currentString[k] == currentString[j] {
                k++
            }
            next := fmt.Sprintf("%d%c", k-j, currentString[j])
            nextString += next
        }
        currentString = nextString
    }
    return currentString
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String countAndSay(int n) {
        String currentString = "1";
        for (int i = 2; i <= n; i++) {
            String nextString = "";
            for (int j = 0, k = 0; j < currentString.length(); j = k) {
                while (
                    k < currentString.length() &&
                    currentString.charAt(k) == currentString.charAt(j)
                ) k++;
                nextString += Integer.toString(k - j) + currentString.charAt(j);
            }
            currentString = nextString;
        }
        return currentString;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countAndSay = function (n) {
    let currentString = "1";
    for (let i = 2; i <= n; i++) {
        let nextString = "";
        for (let j = 0, k = 0; j < currentString.length; j = k) {
            while (
                k < currentString.length &&
                currentString.charAt(k) == currentString.charAt(j)
            )
                k++;
            nextString += (k - j).toString() + currentString.charAt(j);
        }
        currentString = nextString;
    }
    return currentString;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        current_string = "1"
        for _ in range(n - 1):
            next_string = ""
            j = 0
            k = 0
            while j < len(current_string):
                while (
                    k < len(current_string)
                    and current_string[k] == current_string[j]
                ):
                    k += 1
                next_string += str(k - j) + current_string[j]
                j = k
            current_string = next_string
        return current_string
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countAndSay(n: number): string {
    let currentString: string = "1";
    for (let i = 2; i <= n; i++) {
        let nextString: string = "";
        for (let j = 0, k = 0; j < currentString.length; j = k) {
            while (
                k < currentString.length &&
                currentString.charAt(k) == currentString.charAt(j)
            )
                k++;
            nextString += (k - j).toString() + currentString.charAt(j);
        }
        currentString = nextString;
    }
    return currentString;
}
```

</details>

<br>

## Approach 2: Regular Expression

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *countAndSay(int n) {
    char *s = (char *)malloc(5000 * sizeof(char));
    strcpy(s, "1");
    for (int i = 2; i <= n; i++) {
        char *t = (char *)malloc(5000 * sizeof(char));
        int k = 0;
        for (int j = 0; j < strlen(s);) {
            int count = 0;
            while (s[j] == s[j + count]) count++;
            t[k++] = (char)(count + '0');
            t[k++] = s[j];
            j += count;
        }
        t[k] = '\0';
        free(s);
        s = t;
    }
    return s;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countAndSay(int n) {
        regex e("(.)\\1*");
        string s = "1";
        for (int i = 2; i <= n; i++) {
            string t;
            for (sregex_iterator it = sregex_iterator(s.begin(), s.end(), e);
                 it != sregex_iterator(); it++) {
                t += to_string(it->str().size()) + it->str(1);
            }
            s = t;
        }
        return s;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string CountAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++) {
            StringBuilder current = new StringBuilder();
            for (int j = 0; j < s.Length; j++) {
                int count = 1;
                while (j < s.Length - 1 && s[j] == s[j + 1]) {
                    j++;
                    count++;
                }

                current.Append(count);
                current.Append(s[j]);
            }

            s = current.ToString();
        }

        return s;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func countAndSay(n int) string {
    s := "1"
    for i := 2; i <= n; i++ {
        t := ""
        count := 1
        for j := 1; j < len(s); j++ {
            if s[j] == s[j-1] {
                count++
            } else {
                t += strconv.Itoa(count) + string(s[j-1])
                count = 1
            }
        }
        t += strconv.Itoa(count) + string(s[len(s)-1])
        s = t
    }
    return s
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public String countAndSay(int n) {
        String currentString = "1";
        // pattern to match the repetitive digits
        Pattern pattern = Pattern.compile("(.)\\1*");
        for (int i = 1; i < n; ++i) {
            Matcher m = pattern.matcher(currentString);
            StringBuffer nextString = new StringBuffer();
            // each group contains identical and adjacent digits
            while (m.find()) {
                nextString.append(
                    m.group().length() + String.valueOf(m.group().charAt(0))
                );
            }
            // prepare for the next iteration
            currentString = nextString.toString();
        }
        return currentString;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var countAndSay = function (n) {
    let s = "1";
    for (let i = 2; i <= n; i++) {
        let t = "";
        const regex = /(.)\1*/g;
        let match;
        while ((match = regex.exec(s)) !== null) {
            t += match[0].length.toString() + match[1];
        }
        s = t;
    }
    return s;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        for _ in range(n - 1):
            # m.group(0) is the entire match, m.group(1) is its first digit
            s = re.sub(
                r"(.)\1*", lambda m: str(len(m.group(0))) + m.group(1), s
            )
        return s
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function countAndSay(n: number): string {
    let s = "1";
    for (let i = 2; i <= n; i++) {
        let t = "";
        const regex = /(.)\1*/g;
        let match: RegExpExecArray | null;
        while ((match = regex.exec(s)) !== null) {
            t += match[0].length.toString() + match[1];
        }
        s = t;
    }
    return s;
}
```

</details>
