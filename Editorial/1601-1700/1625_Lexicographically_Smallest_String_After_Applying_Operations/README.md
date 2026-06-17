# 1625. Lexicographically Smallest String After Applying Operations

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/)  
`String` `Depth-First Search` `Breadth-First Search` `Enumeration`

**Problem Link:** [LeetCode 1625 - Lexicographically Smallest String After Applying Operations](https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/)

## Problem

You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

- Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
- Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".

Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

### Example 1

```text
Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
Add:    "5121"
Rotate: "2151"
Add:    "2050"Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹
There is no way to obtain a string that is lexicographically smaller than "2050".
```

### Example 2

```text
Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Add:    "42"
Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Rotate: "24"Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹Ã¢â‚¬â€¹
There is no way to obtain a string that is lexicographically smaller than "24".
```

### Example 3

```text
Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".
```

## Constraints

- 2 <= s.length <= 100
- s.length is even.
- s consists of digits from 0 to 9 only.
- 1 <= a <= 9
- 1 <= b <= s.length - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Lexicographically Smallest String After Substring Operation](https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Lexicographically Smallest String After a Swap](https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 1625. Lexicographically Smallest String After Applying Operations

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
char* findLexSmallestString(char* s, int a, int b) {
    int n = strlen(s);
    int vis[n];
    memset(vis, 0, sizeof(vis));
    char* res = (char*)calloc(sizeof(char), n + 1);
    strcpy(res, s);
    // double the length of s for convenience in extracting the rotated string t
    char str[2 * n + 1];
    sprintf(str, "%s%s", s, s);
    for (int i = 0; vis[i] == 0; i = (i + b) % n) {
        vis[i] = 1;
        for (int j = 0; j < 10; j++) {
            int k_limit = b % 2 == 0 ? 0 : 9;
            for (int k = 0; k <= k_limit; k++) {
                // before each accumulation, re-truncate t
                char t[n + 1];
                strncpy(t, str + i, n);
                t[n] = '\0';
                for (int p = 1; p < n; p += 2) {
                    t[p] = '0' + (t[p] - '0' + j * a) % 10;
                }
                for (int p = 0; p < n; p += 2) {
                    t[p] = '0' + (t[p] - '0' + k * a) % 10;
                }
                if (strcmp(t, res) < 0) {
                    strcpy(res, t);
                }
            }
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
    string findLexSmallestString(string s, int a, int b) {
        int n = s.size();
        vector<int> vis(n);
        string res = s;
        // double the length of s for convenience in extracting the rotated
        // string t
        s = s + s;
        for (int i = 0; vis[i] == 0; i = (i + b) % n) {
            vis[i] = 1;
            for (int j = 0; j < 10; j++) {
                int k_limit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= k_limit; k++) {
                    // before each accumulation, re-truncate t
                    string t = s.substr(i, n);
                    for (int p = 1; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + j * a) % 10;
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = '0' + (t[p] - '0' + k * a) % 10;
                    }
                    res = min(res, t);
                }
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
    public string FindLexSmallestString(string s, int a, int b) {
        int n = s.Length;
        bool[] vis = new bool[n];
        string res = s;
        // double the length of s for convenience in extracting the rotated
        // string t
        s = s + s;
        for (int i = 0; !vis[i]; i = (i + b) % n) {
            vis[i] = true;
            for (int j = 0; j < 10; j++) {
                int kLimit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= kLimit; k++) {
                    // before each accumulation, re-truncate t
                    char[] t = s.Substring(i, n).ToCharArray();
                    for (int p = 1; p < n; p += 2) {
                        t[p] = (char)('0' + (t[p] - '0' + j * a) % 10);
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = (char)('0' + (t[p] - '0' + k * a) % 10);
                    }
                    string tStr = new string(t);
                    if (tStr.CompareTo(res) < 0) {
                        res = tStr;
                    }
                }
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
func findLexSmallestString(s string, a int, b int) string {
	n := len(s)
	vis := make([]bool, n)
	res := s
	// double the length of s for convenience in extracting the rotated string t
	s = s + s
	for i := 0; !vis[i]; i = (i + b) % n {
		vis[i] = true
		for j := 0; j < 10; j++ {
			kLimit := 0
			if b%2 != 0 {
				kLimit = 9
			}
			for k := 0; k <= kLimit; k++ {
				// before each accumulation, re-truncate t
				t := []byte(s[i : i+n])
				for p := 1; p < n; p += 2 {
					t[p] = '0' + byte((int(t[p]-'0')+j*a)%10)
				}
				for p := 0; p < n; p += 2 {
					t[p] = '0' + byte((int(t[p]-'0')+k*a)%10)
				}
				tStr := string(t)
				if tStr < res {
					res = tStr
				}
			}
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

    public String findLexSmallestString(String s, int a, int b) {
        int n = s.length();
        boolean[] vis = new boolean[n];
        String res = s;
        // double the length of s for convenience in extracting the rotated string t
        s = s + s;
        for (int i = 0; !vis[i]; i = (i + b) % n) {
            vis[i] = true;
            for (int j = 0; j < 10; j++) {
                int kLimit = b % 2 == 0 ? 0 : 9;
                for (int k = 0; k <= kLimit; k++) {
                    // before each accumulation, re-truncate t
                    char[] t = s.substring(i, i + n).toCharArray();
                    for (int p = 1; p < n; p += 2) {
                        t[p] = (char) ('0' + ((t[p] - '0' + j * a) % 10));
                    }
                    for (int p = 0; p < n; p += 2) {
                        t[p] = (char) ('0' + ((t[p] - '0' + k * a) % 10));
                    }
                    String tStr = new String(t);
                    if (tStr.compareTo(res) < 0) {
                        res = tStr;
                    }
                }
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
var findLexSmallestString = function (s, a, b) {
    const n = s.length;
    const vis = new Array(n).fill(false);
    let res = s;
    // double the length of s for convenience in extracting the rotated string t
    s = s + s;
    for (let i = 0; !vis[i]; i = (i + b) % n) {
        vis[i] = true;
        for (let j = 0; j < 10; j++) {
            let kLimit = b % 2 === 0 ? 0 : 9;
            for (let k = 0; k <= kLimit; k++) {
                // before each accumulation, re-truncate t
                const t = [...s.slice(i, i + n)];
                for (let p = 1; p < n; p += 2) {
                    t[p] = String.fromCharCode(
                        "0".charCodeAt() +
                            ((t[p].charCodeAt() - "0".charCodeAt() + j * a) %
                                10),
                    );
                }
                for (let p = 0; p < n; p += 2) {
                    t[p] = String.fromCharCode(
                        "0".charCodeAt() +
                            ((t[p].charCodeAt() - "0".charCodeAt() + k * a) %
                                10),
                    );
                }
                const tStr = t.join("");
                if (tStr < res) {
                    res = tStr;
                }
            }
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
    def findLexSmallestString(self, s: str, a: int, b: int) -> str:
        n = len(s)
        vis = [False] * n
        res = s
        # double the length of s for convenience in extracting the rotated string t
        s = s + s
        i = 0
        while not vis[i]:
            vis[i] = True
            for j in range(10):
                k_limit = 0 if b % 2 == 0 else 9
                for k in range(k_limit + 1):
                    # before each accumulation, re-truncate t
                    t = list(s[i : i + n])
                    for p in range(1, n, 2):
                        t[p] = str((int(t[p]) + j * a) % 10)
                    for p in range(0, n, 2):
                        t[p] = str((int(t[p]) + k * a) % 10)
                    t_str = "".join(t)
                    if t_str < res:
                        res = t_str
            i = (i + b) % n
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function findLexSmallestString(s: string, a: number, b: number): string {
    const n = s.length;
    const vis = new Array(n).fill(false);
    let res = s;
    // double the length of s for convenience in extracting the rotated string t
    s = s + s;
    for (let i = 0; !vis[i]; i = (i + b) % n) {
        vis[i] = true;
        for (let j = 0; j < 10; j++) {
            let kLimit = b % 2 === 0 ? 0 : 9;
            for (let k = 0; k <= kLimit; k++) {
                // before each accumulation, re-truncate t
                const t = [...s.slice(i, i + n)];
                for (let p = 1; p < n; p += 2) {
                    t[p] = String.fromCharCode(
                        "0".charCodeAt(0) +
                            ((t[p].charCodeAt(0) - "0".charCodeAt(0) + j * a) %
                                10),
                    );
                }
                for (let p = 0; p < n; p += 2) {
                    t[p] = String.fromCharCode(
                        "0".charCodeAt(0) +
                            ((t[p].charCodeAt(0) - "0".charCodeAt(0) + k * a) %
                                10),
                    );
                }
                const tStr = t.join("");
                if (tStr < res) {
                    res = tStr;
                }
            }
        }
    }
    return res;
}
```

</details>
