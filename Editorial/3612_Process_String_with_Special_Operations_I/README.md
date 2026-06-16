# 3612. Process String with Special Operations I

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/process-string-with-special-operations-i/)  
`String` `Simulation`

**Problem Link:** [LeetCode 3612 - Process String with Special Operations I](https://leetcode.com/problems/process-string-with-special-operations-i/)

## Problem

You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

- If the letter is a lowercase English letter append it to result.
- A '*' removes the last character from result, if it exists.
- A '#' duplicates the current result and appends it to itself.
- A '%' reverses the current result.

Return the final string result after processing all characters in s.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 20
- s consists of only lowercase English letters and special characters *, #, and %.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3612. Process String with Special Operations I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Simulation | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Simulation

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char* processStr(const char* s) {
    size_t cap = 16;
    size_t len = 0;
    char* res = malloc(cap);
    if (!res) return NULL;
    res[0] = '\0';
    for (const char* p = s; *p; ++p) {
        char c = *p;
        if (c == '*') {
            if (len) {
                len--;
                res[len] = '\0';
            }
        } else if (c == '#') {
            size_t need = len * 2 + 1;
            if (need > cap) {
                while (cap < need) cap *= 2;
                res = realloc(res, cap);
                if (!res) return NULL;
            }
            memcpy(res + len, res, len);
            len *= 2;
            res[len] = '\0';
        } else if (c == '%') {
            for (size_t i = 0; i < len / 2; ++i) {
                char t = res[i];
                res[i] = res[len - 1 - i];
                res[len - 1 - i] = t;
            }
            res[len] = '\0';
        } else {
            if (len + 2 > cap) {
                while (cap < len + 2) cap *= 2;
                res = realloc(res, cap);
                if (!res) return NULL;
            }
            res[len++] = c;
            res[len] = '\0';
        }
    }
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for (auto it : s) {
            if (it == '*') {
                if (result.size()) {
                    result.pop_back();
                }
            } else if (it == '#') {
                result += result;
            } else if (it == '%') {
                result = string(result.rbegin(), result.rend());
            } else {
                result += it;
            }
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
    public string ProcessStr(string s) {
        var result = new StringBuilder();
        foreach (var ch in s) {
            if (ch == '*') {
                if (result.Length > 0)
                    result.Length--;
            } else if (ch == '#') {
                result.Append(result.ToString());
            } else if (ch == '%') {
                var arr = result.ToString().ToCharArray();
                Array.Reverse(arr);
                result = new StringBuilder(new string(arr));
            } else {
                result.Append(ch);
            }
        }
        return result.ToString();
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func processStr(s string) string {
	var result []rune
	for _, ch := range s {
		switch ch {
		case '*':
			if len(result) > 0 {
				result = result[:len(result)-1]
			}
		case '#':
			copyPart := make([]rune, len(result))
			copy(copyPart, result)
			result = append(result, copyPart...)
		case '%':
			for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
				result[i], result[j] = result[j], result[i]
			}
		default:
			result = append(result, ch)
		}
	}
	return string(result)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public String processStr(String s) {
        StringBuilder result = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                if (result.length() > 0) result.deleteCharAt(
                    result.length() - 1
                );
            } else if (ch == '#') {
                result.append(result.toString());
            } else if (ch == '%') {
                result.reverse();
            } else {
                result.append(ch);
            }
        }
        return result.toString();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function processStr(s) {
    let result = [];
    for (const ch of s) {
        if (ch === "*") {
            if (result.length) result.pop();
        } else if (ch === "#") {
            result = result.concat(result);
        } else if (ch === "%") {
            result.reverse();
        } else {
            result.push(ch);
        }
    }
    return result.join("");
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def processStr(self, s: str) -> str:
        result = []
        for ch in s:
            if ch == "*":
                if result:
                    result.pop()
            elif ch == "#":
                result += result.copy()
            elif ch == "%":
                result = result[::-1]
            else:
                result.append(ch)
        return "".join(result)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
export function processStr(s: string): string {
    const result: string[] = [];
    for (const ch of s) {
        if (ch === "*") {
            if (result.length) result.pop();
        } else if (ch === "#") {
            result.push(...result.slice());
        } else if (ch === "%") {
            result.reverse();
        } else {
            result.push(ch);
        }
    }
    return result.join("");
}
```

</details>
