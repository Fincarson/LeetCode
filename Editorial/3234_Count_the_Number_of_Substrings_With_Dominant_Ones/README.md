# 3234. Count the Number of Substrings With Dominant Ones

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/)  
`String` `Enumeration`

**Problem Link:** [LeetCode 3234 - Count the Number of Substrings With Dominant Ones](https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/)

## Problem

You are given a binary string s.

Return the number of substrings with dominant ones.

A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 4 * 104
- s consists only of characters '0' and '1'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3234. Count the Number of Substrings With Dominant Ones

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Enumeration | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Enumeration

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
int numberOfSubstrings(char* s) {
    int n = strlen(s);
    int* pre = (int*)malloc((n + 1) * sizeof(int));
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || (i > 0 && s[i - 1] == '0')) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt0 = s[i - 1] == '0' ? 1 : 0;
        int j = i;
        while (j > 0 && cnt0 * cnt0 <= n) {
            int cnt1 = (i - pre[j]) - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                int add = j - pre[j];
                if (cnt1 - cnt0 * cnt0 + 1 < add) {
                    add = cnt1 - cnt0 * cnt0 + 1;
                }
                res += add;
            }
            j = pre[j];
            cnt0++;
        }
    }
    free(pre);
    return res;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pre(n + 1);
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int NumberOfSubstrings(string s) {
        int n = s.Length;
        int[] pre = new int[n + 1];
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0' ? 1 : 0;
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += Math.Min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func numberOfSubstrings(s string) int {
	n := len(s)
	pre := make([]int, n+1)
	pre[0] = -1
	for i := 0; i < n; i++ {
		if i == 0 || (i > 0 && s[i-1] == '0') {
			pre[i+1] = i
		} else {
			pre[i+1] = pre[i]
		}
	}
	res := 0
	for i := 1; i <= n; i++ {
		cnt0 := 0
		if s[i-1] == '0' {
			cnt0 = 1
		}
		j := i
		for j > 0 && cnt0*cnt0 <= n {
			cnt1 := (i - pre[j]) - cnt0
			if cnt0*cnt0 <= cnt1 {
				add := j - pre[j]
				if cnt1-cnt0*cnt0+1 < add {
					add = cnt1 - cnt0*cnt0 + 1
				}
				res += add
			}
			j = pre[j]
			cnt0++
		}
	}
	return res
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] pre = new int[n + 1];
        pre[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s.charAt(i - 1) == '0')) {
                pre[i + 1] = i;
            } else {
                pre[i + 1] = pre[i];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s.charAt(i - 1) == '0' ? 1 : 0;
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pre[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    res += Math.min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pre[j];
                cnt0++;
            }
        }
        return res;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var numberOfSubstrings = function (s) {
    const n = s.length;
    const pre = new Array(n + 1);
    pre[0] = -1;
    for (let i = 0; i < n; i++) {
        if (i === 0 || (i > 0 && s[i - 1] === "0")) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }
    let res = 0;
    for (let i = 1; i <= n; i++) {
        let cnt0 = s[i - 1] === "0" ? 1 : 0;
        let j = i;
        while (j > 0 && cnt0 * cnt0 <= n) {
            const cnt1 = i - pre[j] - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                res += Math.min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
            }
            j = pre[j];
            cnt0++;
        }
    }
    return res;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        pre = [-1] * (n + 1)
        for i in range(n):
            if i == 0 or s[i - 1] == "0":
                pre[i + 1] = i
            else:
                pre[i + 1] = pre[i]

        res = 0
        for i in range(1, n + 1):
            cnt0 = 1 if s[i - 1] == "0" else 0
            j = i
            while j > 0 and cnt0 * cnt0 <= n:
                cnt1 = (i - pre[j]) - cnt0
                if cnt0 * cnt0 <= cnt1:
                    res += min(j - pre[j], cnt1 - cnt0 * cnt0 + 1)
                j = pre[j]
                cnt0 += 1
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function numberOfSubstrings(s: string): number {
    const n = s.length;
    const pre: number[] = new Array(n + 1);
    pre[0] = -1;
    for (let i = 0; i < n; i++) {
        if (i === 0 || (i > 0 && s[i - 1] === "0")) {
            pre[i + 1] = i;
        } else {
            pre[i + 1] = pre[i];
        }
    }
    let res = 0;
    for (let i = 1; i <= n; i++) {
        let cnt0 = s[i - 1] === "0" ? 1 : 0;
        let j = i;
        while (j > 0 && cnt0 * cnt0 <= n) {
            const cnt1 = i - pre[j] - cnt0;
            if (cnt0 * cnt0 <= cnt1) {
                res += Math.min(j - pre[j], cnt1 - cnt0 * cnt0 + 1);
            }
            j = pre[j];
            cnt0++;
        }
    }
    return res;
}
```

</details>
