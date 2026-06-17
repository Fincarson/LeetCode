# 3461. Check If Digits Are Equal in String After Operations I

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/)  
`Math` `String` `Simulation` `Combinatorics` `Number Theory`

**Problem Link:** [LeetCode 3461 - Check If Digits Are Equal in String After Operations I](https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/)

## Problem

You are given a string s consisting of digits. Perform the following operation repeatedly until the string has exactly two digits:

- For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the sum of the two digits modulo 10.
- Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.

Return true if the final two digits in s are the same; otherwise, return false.

### Example 1

### Example 2

## Constraints

- 3 <= s.length <= 100
- s consists of only digits.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3461. Check If Digits Are Equal in String After Operations I

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
bool hasSameDigits(char* s) {
    int n = strlen(s);
    char* arr = strdup(s);
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 0; j <= n - 1 - i; j++) {
            arr[j] = ((arr[j] - '0') + (arr[j + 1] - '0')) % 10 + '0';
        }
    }
    bool res = arr[0] == arr[1];
    free(arr);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j <= n - 1 - i; j++) {
                s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
            }
        }
        return s[0] == s[1];
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool HasSameDigits(string s) {
        int n = s.Length;
        char[] arr = s.ToCharArray();
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j <= n - 1 - i; j++) {
                arr[j] =
                    (char)(((arr[j] - '0') + (arr[j + 1] - '0')) % 10 + '0');
            }
        }
        return arr[0] == arr[1];
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func hasSameDigits(s string) bool {
	n := len(s)
	arr := []byte(s)
	for i := 1; i <= n-2; i++ {
		for j := 0; j <= n-1-i; j++ {
			arr[j] = byte(((int(arr[j]-'0') + int(arr[j+1]-'0')) % 10) + '0')
		}
	}
	return arr[0] == arr[1]
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public boolean hasSameDigits(String s) {
        int n = s.length();
        char[] sArray = s.toCharArray();
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 0; j <= n - 1 - i; j++) {
                int digit1 = sArray[j] - '0';
                int digit2 = sArray[j + 1] - '0';
                sArray[j] = (char) (((digit1 + digit2) % 10) + '0');
            }
        }
        return sArray[0] == sArray[1];
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var hasSameDigits = function (s) {
    let n = s.length;
    let arr = s.split("");
    for (let i = 1; i <= n - 2; i++) {
        for (let j = 0; j <= n - 1 - i; j++) {
            arr[j] = String((parseInt(arr[j]) + parseInt(arr[j + 1])) % 10);
        }
    }
    return arr[0] === arr[1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def hasSameDigits(self, s: str) -> bool:
        n = len(s)
        s_list = list(s)
        for i in range(1, n - 1):
            for j in range(n - i):
                digit1 = ord(s_list[j]) - ord("0")
                digit2 = ord(s_list[j + 1]) - ord("0")
                s_list[j] = chr(((digit1 + digit2) % 10) + ord("0"))
        return s_list[0] == s_list[1]
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function hasSameDigits(s: string): boolean {
    let n = s.length;
    let arr: string[] = s.split("");

    for (let i = 1; i <= n - 2; i++) {
        for (let j = 0; j <= n - 1 - i; j++) {
            arr[j] = String((parseInt(arr[j]) + parseInt(arr[j + 1])) % 10);
        }
    }
    return arr[0] === arr[1];
}
```

</details>
