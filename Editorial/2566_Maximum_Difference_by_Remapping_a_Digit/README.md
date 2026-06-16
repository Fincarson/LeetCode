# 2566. Maximum Difference by Remapping a Digit

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/)  
`Math` `Greedy`

**Problem Link:** [LeetCode 2566 - Maximum Difference by Remapping a Digit](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/)

## Problem

You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

- When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
- Bob can remap a digit to itself, in which case num does not change.
- Bob can remap different digits for obtaining minimum and maximum values respectively.
- The resulting number after remapping can contain leading zeroes.

### Example 1

```text
Input: num = 11891
Output: 99009
Explanation:
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
```

### Example 2

```text
Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
```

## Constraints

- 1 <= num <= 108

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2566. Maximum Difference by Remapping a Digit

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int minMaxDifference(int num) {
    char s[16], t[16];
    sprintf(s, "%d", num);
    strcpy(t, s);
    int pos = 0;
    while (s[pos] != '\0' && s[pos] == '9') {
        pos++;
    }
    if (s[pos] != '\0') {
        char a = s[pos];
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == a) {
                s[i] = '9';
            }
        }
    }
    char b = t[0];
    for (int i = 0; t[i] != '\0'; i++) {
        if (t[i] == b) {
            t[i] = '0';
        }
    }
    return atoi(s) - atoi(t);
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');
        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }
        char b = t[0];
        replace(t.begin(), t.end(), b, '0');
        return stoi(s) - stoi(t);
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MinMaxDifference(int num) {
        string s = num.ToString();
        string t = s;
        int pos = 0;
        while (pos < s.Length && s[pos] == '9') {
            pos++;
        }
        if (pos < s.Length) {
            s = s.Replace(s[pos], '9');
        }
        t = t.Replace(t[0], '0');
        return int.Parse(s) - int.Parse(t);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func minMaxDifference(num int) int {
	s := strconv.Itoa(num)
	t := s
	pos := 0
	for pos < len(s) && s[pos] == '9' {
		pos++
	}
	if pos < len(s) {
		s = strings.ReplaceAll(s, string(s[pos]), "9")
	}
	t = strings.ReplaceAll(t, string(t[0]), "0")
	max, _ := strconv.Atoi(s)
	min, _ := strconv.Atoi(t)
	return max - min
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int minMaxDifference(int num) {
        String s = Integer.toString(num);
        String t = s;
        int pos = 0;
        while (pos < s.length() && s.charAt(pos) == '9') {
            pos++;
        }
        if (pos < s.length()) {
            s = s.replace(s.charAt(pos), '9');
        }
        t = t.replace(t.charAt(0), '0');
        return Integer.parseInt(s) - Integer.parseInt(t);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var minMaxDifference = function (num) {
    let s = num.toString();
    let t = s;
    let pos = 0;
    while (pos < s.length && s[pos] === "9") {
        pos++;
    }
    if (pos < s.length) {
        s = s.replace(new RegExp(s[pos], "g"), "9");
    }
    t = t.replace(new RegExp(t[0], "g"), "0");
    return parseInt(s) - parseInt(t);
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)
        t = s
        pos = 0
        while pos < len(s) and s[pos] == "9":
            pos += 1
        if pos < len(s):
            s = s.replace(s[pos], "9")
        t = t.replace(t[0], "0")
        return int(s) - int(t)
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function minMaxDifference(num: number): number {
    let s = num.toString();
    let t = s;
    let pos = 0;
    while (pos < s.length && s[pos] === "9") {
        pos++;
    }
    if (pos < s.length) {
        s = s.replace(new RegExp(s[pos], "g"), "9");
    }
    t = t.replace(new RegExp(t[0], "g"), "0");
    return parseInt(s) - parseInt(t);
}
```

</details>
