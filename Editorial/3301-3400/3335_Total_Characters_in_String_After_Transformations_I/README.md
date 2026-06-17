# 3335. Total Characters in String After Transformations I

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/total-characters-in-string-after-transformations-i/)  
`Hash Table` `Math` `String` `Dynamic Programming` `Counting`

**Problem Link:** [LeetCode 3335 - Total Characters in String After Transformations I](https://leetcode.com/problems/total-characters-in-string-after-transformations-i/)

## Problem

You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

- If the character is 'z', replace it with the string "ab".
- Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.

Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

## Constraints

- 1 <= s.length <= 105
- s consists only of lowercase English letters.
- 1 <= t <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 3335. Total Characters in String After Transformations I

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Recurrence | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Recurrence

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int lengthAfterTransformations(char* s, int t) {
    int cnt[26] = {0};
    for (int i = 0; s[i]; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int round = 0; round < t; round++) {
        int nxt[26] = {0};
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + cnt[0]) % MOD;
        for (int i = 2; i < 26; i++) {
            nxt[i] = cnt[i - 1];
        }
        memcpy(cnt, nxt, sizeof(cnt));
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans = (ans + cnt[i]) % MOD;
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
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int MOD = 1000000007;

    public int LengthAfterTransformations(string s, int t) {
        int[] cnt = new int[26];
        foreach (char ch in s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            int[] nxt = new int[26];
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % MOD;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = nxt;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const mod = 1000000007

func lengthAfterTransformations(s string, t int) int {
	cnt := make([]int, 26)
	for _, ch := range s {
		cnt[ch-'a']++
	}
	for round := 0; round < t; round++ {
		nxt := make([]int, 26)
		nxt[0] = cnt[25]
		nxt[1] = (cnt[25] + cnt[0]) % mod
		for i := 2; i < 26; i++ {
			nxt[i] = cnt[i-1]
		}
		cnt = nxt
	}
	ans := 0
	for i := 0; i < 26; i++ {
		ans = (ans + cnt[i]) % mod
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int MOD = 1000000007;

    public int lengthAfterTransformations(String s, int t) {
        int[] cnt = new int[26];
        for (char ch : s.toCharArray()) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            int[] nxt = new int[26];
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % MOD;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = nxt;
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % MOD;
        }
        return ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var lengthAfterTransformations = function (s, t) {
    const MOD = 1000000007;
    let cnt = new Array(26).fill(0);
    for (const ch of s) {
        cnt[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
    }
    for (let round = 0; round < t; round++) {
        let nxt = new Array(26).fill(0);
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + cnt[0]) % MOD;
        for (let i = 2; i < 26; i++) {
            nxt[i] = cnt[i - 1];
        }
        cnt = nxt;
    }
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        ans = (ans + cnt[i]) % MOD;
    }
    return ans;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = 10**9 + 7
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - ord("a")] += 1
        for round in range(t):
            nxt = [0] * 26
            nxt[0] = cnt[25]
            nxt[1] = (cnt[25] + cnt[0]) % mod
            for i in range(2, 26):
                nxt[i] = cnt[i - 1]
            cnt = nxt
        ans = sum(cnt) % mod
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function lengthAfterTransformations(s: string, t: number): number {
    const MOD = 1000000007;
    let cnt: number[] = new Array(26).fill(0);
    for (const ch of s) {
        cnt[ch.charCodeAt(0) - "a".charCodeAt(0)]++;
    }
    for (let round = 0; round < t; round++) {
        let nxt: number[] = new Array(26).fill(0);
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + cnt[0]) % MOD;
        for (let i = 2; i < 26; i++) {
            nxt[i] = cnt[i - 1];
        }
        cnt = nxt;
    }
    let ans = 0;
    for (let i = 0; i < 26; i++) {
        ans = (ans + cnt[i]) % MOD;
    }
    return ans;
}
```

</details>
