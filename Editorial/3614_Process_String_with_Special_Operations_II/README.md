# 3614. Process String with Special Operations II

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/process-string-with-special-operations-ii/)  
`String` `Simulation`

**Problem Link:** [LeetCode 3614 - Process String with Special Operations II](https://leetcode.com/problems/process-string-with-special-operations-ii/)

## Problem

You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

You are also given an integer k.

Build a new string result by processing s according to the following rules from left to right:

- If the letter is a lowercase English letter append it to result.
- A '*' removes the last character from result, if it exists.
- A '#' duplicates the current result and appends it to itself.
- A '%' reverses the current result.

Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 105
- s consists of only lowercase English letters and special characters '*', '#', and '%'.
- 0 <= k <= 1015
- The length of result after processing s will not exceed 1015.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3614. Process String with Special Operations II

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
char processStr(char* s, long long k) {
    long long len = 0;
    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++) {
        char c = s[i];
        if (c == '*') {
            if (len > 0) {
                len--;
            }
        } else if (c == '#') {
            len *= 2;
        } else if (c == '%') {
            ;
        } else {
            len++;
        }
    }
    if (k + 1 > len) {
        return '.';
    }
    for (long long i = (long long)n - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '*') {
            len++;
        } else if (c == '#') {
            if (k + 1 > (len + 1) / 2) {
                k -= len / 2;
            }
            len = (len + 1) / 2;
        } else if (c == '%') {
            k = len - k - 1;
        } else {
            if (k + 1 == len) {
                return c;
            }
            len--;
        }
    }
    return '.';
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char processStr(string s, long long k) {
        long long len = 0;
        for (auto c : s) {
            if (c == '*') {
                if (len) {
                    len--;
                }
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                continue;
            } else {
                len++;
            }
        }
        if (k + 1 > len) {
            return '.';
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                len++;
            } else if (s[i] == '#') {
                if (k + 1 > (len + 1) / 2) {
                    k -= len / 2;
                }
                len = (len + 1) / 2;
            } else if (s[i] == '%') {
                k = len - k - 1;
            } else {
                if (k + 1 == len) {
                    return s[i];
                } else {
                    len--;
                }
            }
        }
        return '.';
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public char ProcessStr(string s, long k) {
        long len = 0;
        foreach (char c in s) {
            switch (c) {
                case '*':
                    if (len > 0) {
                        len--;
                    }
                    break;
                case '#':
                    len *= 2;
                    break;
                case '%':
                    break;
                default:
                    len++;
                    break;
            }
        }
        if (k + 1 > len) {
            return '.';
        }
        for (int i = s.Length - 1; i >= 0; i--) {
            char c = s[i];
            switch (c) {
                case '*':
                    len++;
                    break;
                case '#':
                    if (k + 1 > (len + 1) / 2) {
                        k -= len / 2;
                    }
                    len = (len + 1) / 2;
                    break;
                case '%':
                    k = len - k - 1;
                    break;
                default:
                    if (k + 1 == len) {
                        return c;
                    }
                    len--;
                    break;
            }
        }
        return '.';
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func processStr(s string, k int64) byte {
	var length int64
	for i := 0; i < len(s); i++ {
		switch s[i] {
		case '*':
			if length > 0 {
				length--
			}
		case '#':
			length *= 2
		case '%':
			// no length change
		default:
			length++
		}
	}
	if k+1 > length {
		return '.'
	}
	for i := len(s) - 1; i >= 0; i-- {
		switch s[i] {
		case '*':
			length++
		case '#':
			if k+1 > (length+1)/2 {
				k -= length / 2
			}
			length = (length + 1) / 2
		case '%':
			k = length - k - 1
		default:
			if k+1 == length {
				return s[i]
			}
			length--
		}
	}
	return '.'
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char processStr(String s, long k) {
        long len = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch (c) {
                case '*':
                    if (len > 0) {
                        len--;
                    }
                    break;
                case '#':
                    len *= 2;
                    break;
                case '%':
                    break;
                default:
                    len++;
                    break;
            }
        }
        if (k + 1 > len) {
            return '.';
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            switch (c) {
                case '*':
                    len++;
                    break;
                case '#':
                    if (k + 1 > (len + 1) / 2) {
                        k -= len / 2;
                    }
                    len = (len + 1) / 2;
                    break;
                case '%':
                    k = len - k - 1;
                    break;
                default:
                    if (k + 1 == len) {
                        return c;
                    }
                    len--;
                    break;
            }
        }
        return '.';
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
function processStr(s, k) {
    let len = 0;
    for (const c of s) {
        if (c === "*") {
            if (len > 0) {
                len--;
            }
        } else if (c === "#") {
            len *= 2;
        } else if (c === "%") {
            // no change
        } else {
            len++;
        }
    }
    if (k + 1 > len) {
        return ".";
    }
    for (let i = s.length - 1; i >= 0; i--) {
        const c = s[i];
        if (c === "*") {
            len++;
        } else if (c === "#") {
            if (k + 1 > (len + 1) / 2) {
                k -= Math.floor(len / 2);
            }
            len = Math.floor((len + 1) / 2);
        } else if (c === "%") {
            k = len - k - 1;
        } else {
            if (k + 1 === len) {
                return c;
            }
            len--;
        }
    }
    return ".";
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def processStr(self, s: str, k: int) -> str:
        length = 0
        for c in s:
            if c == "*":
                if length:
                    length -= 1
            elif c == "#":
                length *= 2
            elif c == "%":
                pass
            else:
                length += 1
        if k + 1 > length:
            return "."
        for c in reversed(s):
            if c == "*":
                length += 1
            elif c == "#":
                if k + 1 > (length + 1) // 2:
                    k -= length // 2
                length = (length + 1) // 2
            elif c == "%":
                k = length - k - 1
            else:
                if k + 1 == length:
                    return c
                length -= 1
        return "."
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function processStr(s: string, k: number): string {
    let len = 0;
    for (const c of s) {
        if (c === "*") {
            if (len > 0) {
                len--;
            }
        } else if (c === "#") {
            len *= 2;
        } else if (c === "%") {
            // no change
        } else {
            len++;
        }
    }
    if (k + 1 > len) {
        return ".";
    }
    for (let i = s.length - 1; i >= 0; i--) {
        const c = s[i];
        if (c === "*") {
            len++;
        } else if (c === "#") {
            if (k + 1 > (len + 1) / 2) {
                k -= Math.floor(len / 2);
            }
            len = Math.floor((len + 1) / 2);
        } else if (c === "%") {
            k = len - k - 1;
        } else {
            if (k + 1 === len) {
                return c;
            }
            len--;
        }
    }
    return ".";
}
```

</details>
