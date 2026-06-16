# 1513. Number of Substrings With Only 1s

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/number-of-substrings-with-only-1s/)  
`Math` `String`

**Problem Link:** [LeetCode 1513 - Number of Substrings With Only 1s](https://leetcode.com/problems/number-of-substrings-with-only-1s/)

## Problem

Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

### Example 1

```text
Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
```

### Example 2

```text
Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
```

### Example 3

```text
Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
```

## Constraints

- 1 <= s.length <= 105
- s[i] is either '0' or '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Number of Homogenous Substrings](https://leetcode.com/problems/count-number-of-homogenous-substrings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Count Vowel Substrings of a String](https://leetcode.com/problems/count-vowel-substrings-of-a-string/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1513. Number of Substrings With Only 1s

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Traverse The String To Find The Longest Substring | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Traverse The String To Find The Longest Substring

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numSub(char* s) {
    const int MODULO = 1000000007;
    long total = 0;
    long consecutive = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '0') {
            total += consecutive * (consecutive + 1) / 2;
            total %= MODULO;
            consecutive = 0;
        } else {
            consecutive++;
        }
    }
    total += consecutive * (consecutive + 1) / 2;
    total %= MODULO;
    return (int)total;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    static constexpr int P = int(1E9) + 7;

    int numSub(string s) {
        int p = 0;
        long long ans = 0;
        while (p < s.size()) {
            if (s[p] == '0') {
                ++p;
                continue;
            }
            int cnt = 0;
            while (p < s.size() && s[p] == '1') {
                ++cnt;
                ++p;
            }
            ans = ans + (1LL + (long long)cnt) * cnt / 2;
            ans = ans % P;
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
    public int NumSub(string s) {
        const int MODULO = 1000000007;
        long total = 0;
        long consecutive = 0;
        foreach (char c in s) {
            if (c == '0') {
                total += consecutive * (consecutive + 1) / 2;
                total %= MODULO;
                consecutive = 0;
            } else {
                consecutive++;
            }
        }
        total += consecutive * (consecutive + 1) / 2;
        total %= MODULO;
        return (int)total;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numSub(s string) int {
	const MODULO = 1000000007
	total := 0
	consecutive := 0
	for _, c := range s {
		if c == '0' {
			total += consecutive * (consecutive + 1) / 2
			total %= MODULO
			consecutive = 0
		} else {
			consecutive++
		}
	}
	total += consecutive * (consecutive + 1) / 2
	total %= MODULO
	return total
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numSub(String s) {
        final int MODULO = 1000000007;
        long total = 0;
        int length = s.length();
        long consecutive = 0;
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            if (c == '0') {
                total += (consecutive * (consecutive + 1)) / 2;
                total %= MODULO;
                consecutive = 0;
            } else {
                consecutive++;
            }
        }
        total += (consecutive * (consecutive + 1)) / 2;
        total %= MODULO;
        return (int) total;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numSub = function (s) {
    const MODULO = 1000000007;
    let total = 0;
    let consecutive = 0;
    for (const c of s) {
        if (c === "0") {
            total += (consecutive * (consecutive + 1)) / 2;
            total %= MODULO;
            consecutive = 0;
        } else {
            consecutive++;
        }
    }
    total += (consecutive * (consecutive + 1)) / 2;
    total %= MODULO;
    return total;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numSub(self, s: str) -> int:
        total, consecutive = 0, 0
        length = len(s)
        for i in range(length):
            if s[i] == "0":
                total += consecutive * (consecutive + 1) // 2
                consecutive = 0
            else:
                consecutive += 1

        total += consecutive * (consecutive + 1) // 2
        total %= 10**9 + 7
        return total
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numSub(s: string): number {
    const MODULO = 1000000007;
    let total = 0;
    let consecutive = 0;
    for (const c of s) {
        if (c === "0") {
            total += (consecutive * (consecutive + 1)) / 2;
            total %= MODULO;
            consecutive = 0;
        } else {
            consecutive++;
        }
    }
    total += (consecutive * (consecutive + 1)) / 2;
    total %= MODULO;
    return total;
}
```

</details>
