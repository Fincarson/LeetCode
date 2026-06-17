# 3333. Find the Original Typed String II

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/find-the-original-typed-string-ii/)  
`String` `Dynamic Programming` `Prefix Sum`

**Problem Link:** [LeetCode 3333 - Find the Original Typed String II](https://leetcode.com/problems/find-the-original-typed-string-ii/)

## Problem

Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= word.length <= 5 * 105
- word consists only of lowercase English letters.
- 1 <= k <= 2000

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Keyboard Row](https://leetcode.com/problems/keyboard-row/) | ![Easy](../../../_Misc/Badges/Easy.svg) |
| [Faulty Keyboard](https://leetcode.com/problems/faulty-keyboard/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3333. Find the Original Typed String II

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Dynamic Programming + Prefix Sum Optimization | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Dynamic Programming + Prefix Sum Optimization

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
#define MOD 1000000007

int possibleStringCount(char* word, int k) {
    int n = strlen(word);
    int cnt = 1;
    int freq[n];
    memset(freq, 0, sizeof(int) * n);
    int freqSize = 0;
    for (int i = 1; i < n; ++i) {
        if (word[i] == word[i - 1]) {
            ++cnt;
        } else {
            freq[freqSize++] = cnt;
            cnt = 1;
        }
    }
    freq[freqSize++] = cnt;

    long ans = 1;
    for (int i = 0; i < freqSize; ++i) {
        ans = ans * freq[i] % MOD;
    }

    if (freqSize >= k) {
        return (int)ans;
    }

    int f[k], g[k], f_new[k], g_new[k];

    for (int i = 0; i < k; ++i) {
        g[i] = 1;
    }
    for (int i = 0; i < freqSize; ++i) {
        memset(f_new, 0, sizeof(int) * k);
        for (int j = 1; j < k; ++j) {
            f_new[j] = g[j - 1];
            if (j - freq[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + MOD) % MOD;
            }
        }
        memset(g_new, 0, sizeof(int) * k);
        g_new[0] = f_new[0];
        for (int j = 1; j < k; ++j) {
            g_new[j] = (g_new[j - 1] + f_new[j]) % MOD;
        }
        memcpy(f, f_new, sizeof(int) * k);
        memcpy(g, g_new, sizeof(int) * k);
    }

    int result = (ans - g[k - 1] + MOD) % MOD;
    return result;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size(), cnt = 1;
        vector<int> freq;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        int ans = 1;
        for (int o : freq) {
            ans = static_cast<long long>(ans) * o % mod;
        }

        if (freq.size() >= k) {
            return ans;
        }

        vector<int> f(k), g(k, 1);
        for (int i = 0; i < freq.size(); ++i) {
            vector<int> f_new(k);
            for (int j = 1; j < k; ++j) {
                f_new[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
                }
            }
            vector<int> g_new(k);
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = move(f_new);
            g = move(g_new);
        }
        return (ans - g[k - 1] + mod) % mod;
    }

private:
    static const int mod = 1000000007;
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    private const int mod = 1000000007;

    public int PossibleStringCount(string word, int k) {
        int n = word.Length;
        int cnt = 1;
        List<int> freq = new List<int>();

        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                ++cnt;
            } else {
                freq.Add(cnt);
                cnt = 1;
            }
        }
        freq.Add(cnt);
        long ans = 1;
        foreach (int o in freq) {
            ans = ans * o % mod;
        }
        if (freq.Count >= k) {
            return (int)ans;
        }

        int[] f = new int[k];
        int[] g = new int[k];

        Array.Fill(g, 1);
        for (int i = 0; i < freq.Count; ++i) {
            int[] f_new = new int[k];
            for (int j = 1; j < k; ++j) {
                f_new[j] = g[j - 1];
                if (j - freq[i] - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
                }
            }

            int[] g_new = new int[k];
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }

            f = f_new;
            g = g_new;
        }

        return (int)((ans - g[k - 1] + mod) % mod);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const mod = 1000000007

func possibleStringCount(word string, k int) int {
	n := len(word)
	cnt := 1
	var freq []int

	for i := 1; i < n; i++ {
		if word[i] == word[i-1] {
			cnt++
		} else {
			freq = append(freq, cnt)
			cnt = 1
		}
	}
	freq = append(freq, cnt)

	ans := 1
	for _, o := range freq {
		ans = ans * o % mod
	}

	if len(freq) >= k {
		return ans
	}

	f := make([]int, k)
	g := make([]int, k)

	for i := range g {
		g[i] = 1
	}

	for i := 0; i < len(freq); i++ {
		f_new := make([]int, k)
		for j := 1; j < k; j++ {
			f_new[j] = g[j-1]
			if j-freq[i]-1 >= 0 {
				f_new[j] = (f_new[j] - g[j-freq[i]-1] + mod) % mod
			}
		}
		g_new := make([]int, k)
		g_new[0] = f_new[0]
		for j := 1; j < k; j++ {
			g_new[j] = (g_new[j-1] + f_new[j]) % mod
		}
		f, g = f_new, g_new
	}

	return (ans - g[k-1] + mod) % mod
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    private static final int mod = 1000000007;

    public int possibleStringCount(String word, int k) {
        int n = word.length();
        int cnt = 1;
        List<Integer> freq = new ArrayList<>();
        for (int i = 1; i < n; ++i) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                ++cnt;
            } else {
                freq.add(cnt);
                cnt = 1;
            }
        }
        freq.add(cnt);

        long ans = 1;
        for (int o : freq) {
            ans = (ans * o) % mod;
        }
        if (freq.size() >= k) {
            return (int) ans;
        }

        int[] f = new int[k];
        int[] g = new int[k];

        Arrays.fill(g, 1);
        for (int i = 0; i < freq.size(); ++i) {
            int[] f_new = new int[k];
            for (int j = 1; j < k; ++j) {
                f_new[j] = g[j - 1];
                if (j - freq.get(i) - 1 >= 0) {
                    f_new[j] = (f_new[j] - g[j - freq.get(i) - 1] + mod) % mod;
                }
            }
            int[] g_new = new int[k];
            g_new[0] = f_new[0];
            for (int j = 1; j < k; ++j) {
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
            }
            f = f_new;
            g = g_new;
        }

        return (int) ((ans - g[k - 1] + mod) % mod);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var possibleStringCount = function (word, k) {
    const mod = 1000000007;
    const n = word.length;
    let cnt = 1;
    const freq = [];

    for (let i = 1; i < n; ++i) {
        if (word[i] === word[i - 1]) {
            ++cnt;
        } else {
            freq.push(cnt);
            cnt = 1;
        }
    }
    freq.push(cnt);

    let ans = 1;
    for (const o of freq) {
        ans = (ans * o) % mod;
    }

    if (freq.length >= k) {
        return ans;
    }

    let f = new Array(k).fill(0);
    let g = new Array(k).fill(1);


    for (let i = 0; i < freq.length; ++i) {
        const f_new = new Array(k).fill(0);
        for (let j = 1; j < k; ++j) {
            f_new[j] = g[j - 1];
            if (j - freq[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
            }
        }
        const g_new = new Array(k).fill(0);
        g_new[0] = f_new[0];
        for (let j = 1; j < k; ++j) {
            g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
        }
        f = f_new;
        g = g_new;
    }
    return (ans - g[k - 1] + mod) % mod;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        mod = 10**9 + 7
        n, cnt = len(word), 1
        freq = list()

        for i in range(1, n):
            if word[i] == word[i - 1]:
                cnt += 1
            else:
                freq.append(cnt)
                cnt = 1
        freq.append(cnt)

        ans = 1
        for o in freq:
            ans = ans * o % mod

        if len(freq) >= k:
            return ans

        f, g = [1] + [0] * (k - 1), [1] * k
        for i in range(len(freq)):
            f_new = [0] * k
            for j in range(1, k):
                f_new[j] = g[j - 1]
                if j - freq[i] - 1 >= 0:
                    f_new[j] = (f_new[j] - g[j - freq[i] - 1]) % mod
            g_new = [f_new[0]] + [0] * (k - 1)
            for j in range(1, k):
                g_new[j] = (g_new[j - 1] + f_new[j]) % mod
            f, g = f_new, g_new
        return (ans - g[k - 1]) % mod
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function possibleStringCount(word: string, k: number): number {
    const mod: number = 1000000007;
    const n = word.length;
    let cnt = 1;
    const freq: number[] = [];

    for (let i = 1; i < n; ++i) {
        if (word[i] === word[i - 1]) {
            ++cnt;
        } else {
            freq.push(cnt);
            cnt = 1;
        }
    }
    freq.push(cnt);

    let ans = 1;
    for (const o of freq) {
        ans = (ans * o) % mod;
    }

    if (freq.length >= k) {
        return ans;
    }

    let f: number[] = new Array(k).fill(0);
    let g: number[] = new Array(k).fill(1);

    for (let i = 0; i < freq.length; ++i) {
        const f_new: number[] = new Array(k).fill(0);
        for (let j = 1; j < k; ++j) {
            f_new[j] = g[j - 1];
            if (j - freq[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + mod) % mod;
            }
        }
        const g_new: number[] = new Array(k).fill(0);
        g_new[0] = f_new[0];
        for (let j = 1; j < k; ++j) {
            g_new[j] = (g_new[j - 1] + f_new[j]) % mod;
        }
        f = f_new;
        g = g_new;
    }

    return (ans - g[k - 1] + mod) % mod;
}
```

</details>
