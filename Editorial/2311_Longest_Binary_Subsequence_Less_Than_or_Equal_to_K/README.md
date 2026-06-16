# 2311. Longest Binary Subsequence Less Than or Equal to K

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/)  
`String` `Dynamic Programming` `Greedy` `Memoization`

**Problem Link:** [LeetCode 2311 - Longest Binary Subsequence Less Than or Equal to K](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/)

## Problem

You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

- The subsequence can contain leading zeroes.
- The empty string is considered to be equal to 0.
- A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

### Example 1

```text
Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
```

### Example 2

```text
Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
```

## Constraints

- 1 <= s.length <= 1000
- s[i] is either '0' or '1'.
- 1 <= k <= 109

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Maximum Binary String After Change](https://leetcode.com/problems/maximum-binary-string-after-change/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2311. Longest Binary Subsequence Less Than or Equal to K

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
int longestSubsequence(char* s, int k) {
    int sm = 0;
    int cnt = 0;
    int bits = (int)(log2(k)) + 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char ch = s[len - 1 - i];
        if (ch == '1') {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = 32 - __builtin_clz(k);
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[s.size() - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public int LongestSubsequence(string s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = (int)(Math.Log(k, 2)) + 1;
        for (int i = 0; i < s.Length; i++) {
            char ch = s[s.Length - 1 - i];
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func longestSubsequence(s string, k int) int {
	sm := 0
	cnt := 0
	bits := bits.Len(uint(k))
	for i := 0; i < len(s); i++ {
		ch := s[len(s)-1-i]
		if ch == '1' {
			if i < bits && sm+(1<<i) <= k {
				sm += 1 << i
				cnt++
			}
		} else {
			cnt++
		}
	}
	return cnt
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public int longestSubsequence(String s, int k) {
        int sm = 0;
        int cnt = 0;
        int bits = (int) (Math.log(k) / Math.log(2)) + 1;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(s.length() - 1 - i);
            if (ch == '1') {
                if (i < bits && sm + (1 << i) <= k) {
                    sm += 1 << i;
                    cnt++;
                }
            } else {
                cnt++;
            }
        }
        return cnt;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var longestSubsequence = function (s, k) {
    let sm = 0;
    let cnt = 0;
    let bits = Math.log2(k) + 1;
    for (let i = 0; i < s.length; i++) {
        const ch = s[s.length - 1 - i];
        if (ch === "1") {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        sm = 0
        cnt = 0
        bits = k.bit_length()
        for i, ch in enumerate(s[::-1]):
            if ch == "1":
                if i < bits and sm + (1 << i) <= k:
                    sm += 1 << i
                    cnt += 1
            else:
                cnt += 1
        return cnt
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestSubsequence(s: string, k: number): number {
    let sm = 0;
    let cnt = 0;
    let bits = Math.log2(k) + 1;
    for (let i = 0; i < s.length; i++) {
        const ch = s[s.length - 1 - i];
        if (ch === "1") {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
}
```

</details>
