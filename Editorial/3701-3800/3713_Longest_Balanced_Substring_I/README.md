# 3713. Longest Balanced Substring I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/longest-balanced-substring-i/)  
`Hash Table` `String` `Counting` `Enumeration`

**Problem Link:** [LeetCode 3713 - Longest Balanced Substring I](https://leetcode.com/problems/longest-balanced-substring-i/)

## Problem

You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= s.length <= 1000
- s consists of lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3713. Longest Balanced Substring I

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
int longestBalanced(char* s) {
    int n = strlen(s);
    int res = 0;
    int cnt[26];

    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        for (int j = i; j < n; j++) {
            bool flag = true;
            int c = s[j] - 'a';
            cnt[c]++;

            for (int k = 0; k < 26; k++) {
                if (cnt[k] > 0 && cnt[k] != cnt[c]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                int length = j - i + 1;
                if (length > res) {
                    res = length;
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
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        vector<int> cnt(26);
        for (int i = 0; i < n; i++) {
            fill(cnt.begin(), cnt.end(), 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;
                for (auto x : cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res = max(res, j - i + 1);
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
    public int LongestBalanced(string s) {
        int n = s.Length;
        int res = 0;
        int[] cnt = new int[26];

        for (int i = 0; i < n; i++) {
            Array.Fill(cnt, 0);
            for (int j = i; j < n; j++) {
                bool flag = true;
                int c = s[j] - 'a';
                cnt[c]++;

                foreach (int x in cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    res = Math.Max(res, j - i + 1);
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
func longestBalanced(s string) int {
	n := len(s)
	res := 0

	for i := 0; i < n; i++ {
		cnt := make([]int, 26)

		for j := i; j < n; j++ {
			c := s[j] - 'a'
			cnt[c]++
			flag := true

			for _, x := range cnt {
				if x > 0 && x != cnt[c] {
					flag = false
					break
				}
			}

			if flag && (j-i+1) > res {
				res = j - i + 1
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

    public int longestBalanced(String s) {
        int n = s.length();
        int res = 0;
        int[] cnt = new int[26];

        for (int i = 0; i < n; i++) {
            Arrays.fill(cnt, 0);
            for (int j = i; j < n; j++) {
                boolean flag = true;
                int c = s.charAt(j) - 'a';
                cnt[c]++;

                for (int x : cnt) {
                    if (x > 0 && x != cnt[c]) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    res = Math.max(res, j - i + 1);
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
var longestBalanced = function (s) {
    const n = s.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        const cnt = new Array(26).fill(0);

        for (let j = i; j < n; j++) {
            let flag = true;
            const c = s.charCodeAt(j) - 97;
            cnt[c]++;
            for (const x of cnt) {
                if (x > 0 && x !== cnt[c]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res = Math.max(res, j - i + 1);
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
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            cnt = defaultdict(int)
            for j in range(i, n):
                cnt[s[j]] += 1
                if len(set(cnt.values())) == 1:
                    res = max(res, j - i + 1)
        return res
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function longestBalanced(s: string): number {
    const n = s.length;
    let res = 0;

    for (let i = 0; i < n; i++) {
        const cnt: number[] = new Array(26).fill(0);

        for (let j = i; j < n; j++) {
            let flag = true;
            const c = s.charCodeAt(j) - 97;
            cnt[c]++;

            for (const x of cnt) {
                if (x > 0 && x !== cnt[c]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res = Math.max(res, j - i + 1);
            }
        }
    }
    return res;
}
```

</details>
