# 2338. Count the Number of Ideal Arrays

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-the-number-of-ideal-arrays/)  
`Math` `Dynamic Programming` `Combinatorics` `Number Theory`

**Problem Link:** [LeetCode 2338 - Count the Number of Ideal Arrays](https://leetcode.com/problems/count-the-number-of-ideal-arrays/)

## Problem

You are given two integers n and maxValue, which are used to describe an ideal array.

A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:

- Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
- Every arr[i] is divisible by arr[i - 1], for 0 < i < n.

Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.

### Example 1

```text
Input: n = 2, maxValue = 5
Output: 10
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
- Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
- Arrays starting with the value 3 (1 array): [3,3]
- Arrays starting with the value 4 (1 array): [4,4]
- Arrays starting with the value 5 (1 array): [5,5]
There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
```

### Example 2

```text
Input: n = 5, maxValue = 3
Output: 11
Explanation: The following are the possible ideal arrays:
- Arrays starting with the value 1 (9 arrays):
   - With no other distinct values (1 array): [1,1,1,1,1]
   - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
   - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
- Arrays starting with the value 2 (1 array): [2,2,2,2,2]
- Arrays starting with the value 3 (1 array): [3,3,3,3,3]
There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
```

## Constraints

- 2 <= n <= 104
- 1 <= maxValue <= 104

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Ways to Make Array With Product](https://leetcode.com/problems/count-ways-to-make-array-with-product/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [Count the Number of Beautiful Subarrays](https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 2338. Count the Number of Ideal Arrays

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Approach: Combinatorial Mathematics | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach: Combinatorial Mathematics

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
const int MOD = 1e9 + 7;
#define MAX_N 10010
#define MAX_P 15  // There are up to 15 prime factors

int c[MAX_N + MAX_P][MAX_P + 1];
int sieve[MAX_N];                    // Minimum prime factor
int ps[MAX_N][MAX_P], psLen[MAX_N];  // List of prime factor counts

void init() {
    if (c[0][0]) {
        return;
    }
    for (int i = 2; i < MAX_N; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j < MAX_N; j += i) {
                if (sieve[j] == 0) {
                    sieve[j] = i;
                }
            }
        }
    }

    for (int i = 2; i < MAX_N; i++) {
        int x = i;
        while (x > 1) {
            int p = sieve[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            ps[i][psLen[i]++] = cnt;
        }
    }

    c[0][0] = 1;
    for (int i = 1; i < MAX_N + MAX_P; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= MAX_P && j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int idealArrays(int n, int maxValue) {
    init();
    long long ans = 0;
    for (int x = 1; x <= maxValue; x++) {
        long long mul = 1;
        for (int i = 0; i < psLen[x]; i++) {
            mul = mul * c[n + ps[x][i] - 1][ps[x][i]] % MOD;
        }
        ans = (ans + mul) % MOD;
    }
    return ans;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
const int MOD = 1e9 + 7, MAX_N = 1e4 + 10,
          MAX_P = 15;  // There are up to 15 prime factors
int c[MAX_N + MAX_P][MAX_P + 1];
vector<int> ps[MAX_N];  // List of prime factor counts
int sieve[MAX_N];       // Minimum prime factor

class Solution {
public:
    Solution() {
        if (c[0][0]) {
            return;
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i;
                }
            }
        }
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, MAX_P); j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }
    int idealArrays(int n, int maxValue) {
        long long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long long mul = 1;
            for (int p : ps[x]) {
                mul = mul * c[n + p - 1][p] % MOD;
            }
            ans = (ans + mul) % MOD;
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
    const int MOD = 1000000007;
    const int MAX_N = 10010;
    const int MAX_P = 15;  // There are up to 15 prime factors
    int[,] c = new int[MAX_N + MAX_P, MAX_P + 1];
    int[] sieve = new int[MAX_N];           // Minimum prime factor
    List<int>[] ps = new List<int>[MAX_N];  // List of prime factor counts

    public Solution() {
        if (c[0, 0] == 1) {
            return;
        }
        for (int i = 0; i < MAX_N; i++) {
            ps[i] = new List<int>();
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    if (sieve[j] == 0) {
                        sieve[j] = i;
                    }
                }
            }
        }

        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x];
                int cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].Add(cnt);
            }
        }
        c[0, 0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i, 0] = 1;
            for (int j = 1; j <= Math.Min(i, MAX_P); j++) {
                c[i, j] = (c[i - 1, j] + c[i - 1, j - 1]) % MOD;
            }
        }
    }

    public int IdealArrays(int n, int maxValue) {
        long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long mul = 1;
            foreach (var p in ps[x]) {
                mul = mul * c[n + p - 1, p] % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return (int)ans;
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const (
	MOD   int = 1e9 + 7
	MAX_N     = 10010
	MAX_P     = 15 // There are up to 15 prime factors
)

var (
	c     [MAX_N + MAX_P][MAX_P + 1]int
	sieve [MAX_N]int   // Minimum prime factor
	ps    [MAX_N][]int // List of prime factor counts
)

func initialize() {
	if c[0][0] != 0 {
		return
	}

	for i := 2; i < MAX_N; i++ {
		if sieve[i] == 0 {
			for j := i; j < MAX_N; j += i {
				if sieve[j] == 0 {
					sieve[j] = i
				}
			}
		}
	}

	for i := 2; i < MAX_N; i++ {
		x := i
		for x > 1 {
			p := sieve[x]
			cnt := 0
			for x%p == 0 {
				x /= p
				cnt++
			}
			ps[i] = append(ps[i], cnt)
		}
	}

	c[0][0] = 1
	for i := 1; i < MAX_N+MAX_P; i++ {
		c[i][0] = 1
		for j := 1; j <= MAX_P && j <= i; j++ {
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD
		}
	}
}

func idealArrays(n int, maxValue int) int {
	initialize()
	ans := 0
	for x := 1; x <= maxValue; x++ {
		mul := 1
		for _, p := range ps[x] {
			mul = mul * c[n+p-1][p] % MOD
		}
		ans = (ans + mul) % MOD
	}
	return ans
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static int MOD = 1000000007;
    static int MAX_N = 10010;
    static int MAX_P = 15; // There are up to 15 prime factors
    static int[][] c = new int[MAX_N + MAX_P][MAX_P + 1];
    static int[] sieve = new int[MAX_N]; // Minimum prime factor
    static List<Integer>[] ps = new List[MAX_N]; // List of prime factor counts

    public Solution() {
        if (c[0][0] == 1) {
            return;
        }

        for (int i = 0; i < MAX_N; i++) {
            ps[i] = new ArrayList<>();
        }

        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {
                for (int j = i; j < MAX_N; j += i) {
                    if (sieve[j] == 0) {
                        sieve[j] = i;
                    }
                }
            }
        }

        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int p = sieve[x], cnt = 0;
                while (x % p == 0) {
                    x /= p;
                    cnt++;
                }
                ps[i].add(cnt);
            }
        }

        c[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            c[i][0] = 1;
            for (int j = 1; j <= Math.min(i, MAX_P); j++) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
            }
        }
    }

    public int idealArrays(int n, int maxValue) {
        long ans = 0;
        for (int x = 1; x <= maxValue; x++) {
            long mul = 1;
            for (int p : ps[x]) {
                mul = (mul * c[n + p - 1][p]) % MOD;
            }
            ans = (ans + mul) % MOD;
        }
        return (int) ans;
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = 1e9 + 7;
const MAX_N = 10010;
const MAX_P = 15; // There are up to 15 prime factors
const c = Array.from({ length: MAX_N + MAX_P }, () => Array(MAX_P + 1).fill(0));
const sieve = Array(MAX_N).fill(0); // Minimum prime factor
const ps = Array.from({ length: MAX_N }, () => []); // List of prime factor counts

(function init() {
    for (let i = 2; i < MAX_N; i++) {
        if (sieve[i] === 0) {
            for (let j = i; j < MAX_N; j += i) {
                if (sieve[j] === 0) {
                    sieve[j] = i;
                }
            }
        }
    }

    for (let i = 2; i < MAX_N; i++) {
        let x = i;
        while (x > 1) {
            const p = sieve[x];
            let cnt = 0;
            while (x % p === 0) {
                x = Math.floor(x / p);
                cnt++;
            }
            ps[i].push(cnt);
        }
    }

    c[0][0] = 1;
    for (let i = 1; i < MAX_N + MAX_P; i++) {
        c[i][0] = 1;
        for (let j = 1; j <= Math.min(i, MAX_P); j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
})();

function idealArrays(n, maxValue) {
    let ans = 0n;
    for (let x = 1; x <= maxValue; x++) {
        let mul = 1n;
        for (const p of ps[x]) {
            mul = (mul * BigInt(c[n + p - 1][p])) % BigInt(MOD);
        }
        ans = (ans + mul) % BigInt(MOD);
    }
    return Number(ans);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
MOD = 10**9 + 7
MAX_N = 10**4 + 10
MAX_P = 15  # At most 15 prime factors

sieve = [0] * MAX_N  # Smallest prime factor

for i in range(2, MAX_N):
    if sieve[i] == 0:
        for j in range(i, MAX_N, i):
            sieve[j] = i

ps = [[] for _ in range(MAX_N)]

for i in range(2, MAX_N):
    x = i
    while x > 1:
        p = sieve[x]
        cnt = 0
        while x % p == 0:
            x //= p
            cnt += 1
        ps[i].append(cnt)

c = [[0] * (MAX_P + 1) for _ in range(MAX_N + MAX_P)]

c[0][0] = 1
for i in range(1, MAX_N + MAX_P):
    c[i][0] = 1
    for j in range(1, min(i, MAX_P) + 1):
        c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD


class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        ans = 0
        for x in range(1, maxValue + 1):
            mul = 1
            for p in ps[x]:
                mul = mul * c[n + p - 1][p] % MOD
            ans = (ans + mul) % MOD
        return ans
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD = 1e9 + 7;
const MAX_N = 10010;
const MAX_P = 15; // There are up to 15 prime factors
const c: number[][] = Array.from({ length: MAX_N + MAX_P }, () =>
    Array(MAX_P + 1).fill(0),
);
const sieve: number[] = Array(MAX_N).fill(0); // Minimum prime factor
const ps: number[][] = Array.from({ length: MAX_N }, () => []); // List of prime factor counts

(function init() {
    for (let i = 2; i < MAX_N; i++) {
        if (sieve[i] === 0) {
            for (let j = i; j < MAX_N; j += i) {
                if (sieve[j] === 0) {
                    sieve[j] = i;
                }
            }
        }
    }

    for (let i = 2; i < MAX_N; i++) {
        let x = i;
        while (x > 1) {
            const p = sieve[x];
            let cnt = 0;
            while (x % p === 0) {
                x = Math.floor(x / p);
                cnt++;
            }
            ps[i].push(cnt);
        }
    }

    c[0][0] = 1;
    for (let i = 1; i < MAX_N + MAX_P; i++) {
        c[i][0] = 1;
        for (let j = 1; j <= Math.min(i, MAX_P); j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
})();

function idealArrays(n: number, maxValue: number): number {
    let ans = 0n;
    for (let x = 1; x <= maxValue; x++) {
        let mul = 1n;
        for (const p of ps[x]) {
            mul = (mul * BigInt(c[n + p - 1][p])) % BigInt(MOD);
        }
        ans = (ans + mul) % BigInt(MOD);
    }
    return Number(ans);
}
```

</details>
