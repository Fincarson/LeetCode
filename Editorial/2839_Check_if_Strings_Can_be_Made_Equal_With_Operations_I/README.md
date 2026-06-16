# 2839. Check if Strings Can be Made Equal With Operations I

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)  
`String`

**Problem Link:** [LeetCode 2839 - Check if Strings Can be Made Equal With Operations I](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/)

## Problem

You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

- Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.

Return true if you can make the strings s1 and s2 equal, and false otherwise.

### Example 1

```text
Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: We can do the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
```

### Example 2

```text
Input: s1 = "abcd", s2 = "dacb"
Output: false
Explanation: It is not possible to make the two strings equal.
```

## Constraints

- s1.length == s2.length == 4
- s1 and s2 consist only of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2839. Check if Strings Can be Made Equal With Operations I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Case Analysis | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Case Analysis

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
bool canBeEqual(char* s1, char* s2) {
    if (strcmp(s1, s2) == 0) {
        return true;
    } else if (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] &&
               s1[3] == s2[1]) {
        return true;
    } else if (s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] &&
               s1[3] == s2[1]) {
        return true;
    } else if (s1[1] == s2[1] && s1[3] == s2[3] && s1[0] == s2[2] &&
               s1[2] == s2[0]) {
        return true;
    }
    return false;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        } else if (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] &&
                   s1[3] == s2[1]) {
            return true;
        } else if (s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] &&
                   s1[3] == s2[1]) {
            return true;
        } else if (s1[1] == s2[1] && s1[3] == s2[3] && s1[0] == s2[2] &&
                   s1[2] == s2[0]) {
            return true;
        }
        return false;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public bool CanBeEqual(string s1, string s2) {
        if (s1 == s2) {
            return true;
        } else if (s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] &&
                   s1[3] == s2[1]) {
            return true;
        } else if (s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] &&
                   s1[3] == s2[1]) {
            return true;
        } else if (s1[1] == s2[1] && s1[3] == s2[3] && s1[0] == s2[2] &&
                   s1[2] == s2[0]) {
            return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func canBeEqual(s1 string, s2 string) bool {
	if s1 == s2 {
		return true
	} else if s1[0] == s2[2] && s1[2] == s2[0] && s1[1] == s2[3] && s1[3] == s2[1] {
		return true
	} else if s1[0] == s2[0] && s1[2] == s2[2] && s1[1] == s2[3] && s1[3] == s2[1] {
		return true
	} else if s1[1] == s2[1] && s1[3] == s2[3] && s1[0] == s2[2] && s1[2] == s2[0] {
		return true
	}
	return false
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public boolean canBeEqual(String s1, String s2) {
        if (s1.equals(s2)) {
            return true;
        } else if (
            s1.charAt(0) == s2.charAt(2) &&
            s1.charAt(2) == s2.charAt(0) &&
            s1.charAt(1) == s2.charAt(3) &&
            s1.charAt(3) == s2.charAt(1)
        ) {
            return true;
        } else if (
            s1.charAt(0) == s2.charAt(0) &&
            s1.charAt(2) == s2.charAt(2) &&
            s1.charAt(1) == s2.charAt(3) &&
            s1.charAt(3) == s2.charAt(1)
        ) {
            return true;
        } else if (
            s1.charAt(1) == s2.charAt(1) &&
            s1.charAt(3) == s2.charAt(3) &&
            s1.charAt(0) == s2.charAt(2) &&
            s1.charAt(2) == s2.charAt(0)
        ) {
            return true;
        }
        return false;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var canBeEqual = function (s1, s2) {
    if (s1 === s2) {
        return true;
    } else if (
        s1[0] === s2[2] &&
        s1[2] === s2[0] &&
        s1[1] === s2[3] &&
        s1[3] === s2[1]
    ) {
        return true;
    } else if (
        s1[0] === s2[0] &&
        s1[2] === s2[2] &&
        s1[1] === s2[3] &&
        s1[3] === s2[1]
    ) {
        return true;
    } else if (
        s1[1] === s2[1] &&
        s1[3] === s2[3] &&
        s1[0] === s2[2] &&
        s1[2] === s2[0]
    ) {
        return true;
    }
    return false;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def canBeEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2:
            return True
        elif (
            s1[0] == s2[2]
            and s1[2] == s2[0]
            and s1[1] == s2[3]
            and s1[3] == s2[1]
        ):
            return True
        elif (
            s1[0] == s2[0]
            and s1[2] == s2[2]
            and s1[1] == s2[3]
            and s1[3] == s2[1]
        ):
            return True
        elif (
            s1[1] == s2[1]
            and s1[3] == s2[3]
            and s1[0] == s2[2]
            and s1[2] == s2[0]
        ):
            return True
        return False
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function canBeEqual(s1: string, s2: string): boolean {
    if (s1 === s2) {
        return true;
    } else if (
        s1[0] === s2[2] &&
        s1[2] === s2[0] &&
        s1[1] === s2[3] &&
        s1[3] === s2[1]
    ) {
        return true;
    } else if (
        s1[0] === s2[0] &&
        s1[2] === s2[2] &&
        s1[1] === s2[3] &&
        s1[3] === s2[1]
    ) {
        return true;
    } else if (
        s1[1] === s2[1] &&
        s1[3] === s2[3] &&
        s1[0] === s2[2] &&
        s1[2] === s2[0]
    ) {
        return true;
    }
    return false;
}
```

</details>
