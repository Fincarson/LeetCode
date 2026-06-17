# 3228. Maximum Number of Operations to Move Ones to the End

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/)  
`String` `Greedy` `Counting`

**Problem Link:** [LeetCode 3228 - Maximum Number of Operations to Move Ones to the End](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/)

## Problem

You are given a binary string s.

You can perform the following operation on the string any number of times:

- Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
- Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".

Return the maximum number of operations that you can perform.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3228. Maximum Number of Operations to Move Ones to the End

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Greedy + Counting | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Greedy + Counting

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int maxOperations(char* s) {
    int countOne = 0;
    int ans = 0;
    int i = 0;
    int len = strlen(s);

    while (i < len) {
        if (s[i] == '0') {
            while (i + 1 < len && s[i + 1] == '0') {
                i++;
            }
            ans += countOne;
        } else {
            countOne++;
        }
        i++;
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
    int maxOperations(string s) {
        int countOne = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while ((i + 1) < s.length() && s[i + 1] == '0') {
                    i++;
                }
                ans += countOne;
            } else {
                countOne++;
            }
        }
        return ans;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int MaxOperations(string s) {
        int countOne = 0;
        int ans = 0;
        int i = 0;
        while (i < s.Length) {
            if (s[i] == '0') {
                while (i + 1 < s.Length && s[i + 1] == '0') {
                    i++;
                }
                ans += countOne;
            } else {
                countOne++;
            }
            i++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func maxOperations(s string) int {
	countOne := 0
	ans := 0
	i := 0
	for i < len(s) {
		if s[i] == '0' {
			for i+1 < len(s) && s[i+1] == '0' {
				i++
			}
			ans += countOne
		} else {
			countOne++
		}
		i++
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {

    public int maxOperations(String s) {
        int countOne = 0;
        int ans = 0;
        int i = 0;
        while (i < s.length()) {
            if (s.charAt(i) == '0') {
                while (i + 1 < s.length() && s.charAt(i + 1) == '0') {
                    i++;
                }
                ans += countOne;
            } else {
                countOne++;
            }
            i++;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var maxOperations = function (s) {
    let countOne = 0;
    let ans = 0;
    let i = 0;
    while (i < s.length) {
        if (s[i] === "0") {
            while (i + 1 < s.length && s[i + 1] === "0") {
                i++;
            }
            ans += countOne;
        } else {
            countOne++;
        }
        i++;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def maxOperations(self, s: str) -> int:
        count_one = 0
        ans = 0
        i = 0
        while i < len(s):
            if s[i] == "0":
                while i + 1 < len(s) and s[i + 1] == "0":
                    i += 1
                ans += count_one
            else:
                count_one += 1
            i += 1
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function maxOperations(s: string): number {
    let countOne: number = 0;
    let ans: number = 0;
    let i: number = 0;
    while (i < s.length) {
        if (s[i] === "0") {
            while (i + 1 < s.length && s[i + 1] === "0") {
                i++;
            }
            ans += countOne;
        } else {
            countOne++;
        }
        i++;
    }
    return ans;
}
```

</details>
