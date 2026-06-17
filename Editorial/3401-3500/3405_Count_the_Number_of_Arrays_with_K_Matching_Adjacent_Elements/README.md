# 3405. Count the Number of Arrays with K Matching Adjacent Elements

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/)  
`Math` `Combinatorics`

**Problem Link:** [LeetCode 3405 - Count the Number of Arrays with K Matching Adjacent Elements](https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/)

## Problem

You are given three integers n, m, k. A good array arr of size n is defined as follows:

- Each element in arr is in the inclusive range [1, m].
- Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].

Return the number of good arrays that can be formed.

Since the answer may be very large, return it modulo 109 + 7.

### Example 1

### Example 2

### Example 3

## Constraints

- 1 <= n <= 105
- 1 <= m <= 105
- 0 <= k <= n - 1

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count Good Numbers](https://leetcode.com/problems/count-good-numbers/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 3405. Count the Number of Arrays with K Matching Adjacent Elements

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
const int MOD = 1000000007;
const int MX = 100000;

long long fact[100000];
long long inv_fact[100000];

long long qpow(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

void init() {
    if (fact[0]) {
        return;
    }
    fact[0] = 1;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
}

long long comb(int n, int m) {
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
}

int countGoodArrays(int n, int m, int k) {
    init();
    return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long qpow(long long x, int n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i; i--) {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    const int MOD = 1_000_000_007;
    const int MX = 100000;
    static long[] fact = new long[MX];
    static long[] invFact = new long[MX];

    long qpow(long x, int n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }

    void init() {
        if (fact[0] != 0) {
            return;
        }
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i > 0; i--) {
            invFact[i - 1] = invFact[i] * i % MOD;
        }
    }

    long comb(int n, int m) {
        return fact[n] * invFact[m] % MOD * invFact[n - m] % MOD;
    }

    public int CountGoodArrays(int n, int m, int k) {
        init();
        return (int)(comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD);
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
const (
	MOD = 1e9 + 7
	MX  = 100000
)

var (
	fact    = make([]int64, MX)
	invFact = make([]int64, MX)
)

func qpow(x int64, n int) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % MOD
		}
		x = x * x % MOD
		n >>= 1
	}
	return res
}

func initFact() {
	if fact[0] != 0 {
		return
	}
	fact[0] = 1
	for i := 1; i < MX; i++ {
		fact[i] = fact[i-1] * int64(i) % MOD
	}
	invFact[MX-1] = qpow(fact[MX-1], MOD-2)
	for i := MX - 1; i > 0; i-- {
		invFact[i-1] = invFact[i] * int64(i) % MOD
	}
}

func comb(n, m int) int64 {
	return fact[n] * invFact[m] % MOD * invFact[n-m] % MOD
}

func countGoodArrays(n, m, k int) int {
	initFact()
	return int(comb(n-1, k) * int64(m) % MOD * qpow(int64(m-1), n-k-1) % MOD)
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    static final int MOD = (int) 1e9 + 7;
    static final int MX = 100000;
    static long[] fact = new long[MX];
    static long[] invFact = new long[MX];

    static long qpow(long x, int n) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            n >>= 1;
        }
        return res;
    }

    static {
        fact[0] = 1;
        for (int i = 1; i < MX; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        invFact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for (int i = MX - 1; i > 0; i--) {
            invFact[i - 1] = (invFact[i] * i) % MOD;
        }
    }

    long comb(int n, int m) {
        return (((fact[n] * invFact[m]) % MOD) * invFact[n - m]) % MOD;
    }

    public int countGoodArrays(int n, int m, int k) {
        return (int) ((((comb(n - 1, k) * m) % MOD) * qpow(m - 1, n - k - 1)) %
            MOD);
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
const MOD = BigInt(1e9 + 7);
const MX = 100000;
const fact = Array(MX).fill(0n);
const invFact = Array(MX).fill(0n);

function qpow(x, n) {
    x = BigInt(x);
    n = BigInt(n);
    let res = 1n;
    while (n > 0n) {
        if (n & 1n) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1n;
    }
    return res;
}

function init() {
    if (fact[0] != 0) {
        return;
    }
    fact[0] = 1n;
    for (let i = 1; i < MX; i++) {
        fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
    }
    invFact[MX - 1] = qpow(fact[MX - 1], MOD - 2n);
    for (let i = MX - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * BigInt(i + 1)) % MOD;
    }
}

function comb(n, m) {
    if (m < 0 || m > n) {
        return 0n;
    }
    return (((fact[n] * invFact[m]) % MOD) * invFact[n - m]) % MOD;
}

function countGoodArrays(n, m, k) {
    init();
    let res = comb(n - 1, k);
    res = (res * BigInt(m)) % MOD;
    res = (res * qpow(m - 1, n - k - 1)) % MOD;
    return Number(res);
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
MOD = 10**9 + 7
MX = 10**5

fact = [0] * MX
inv_fact = [0] * MX


def qpow(x, n):
    res = 1
    while n:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


def init():
    if fact[0] != 0:
        return
    fact[0] = 1
    for i in range(1, MX):
        fact[i] = fact[i - 1] * i % MOD
    inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2)
    for i in range(MX - 1, 0, -1):
        inv_fact[i - 1] = inv_fact[i] * i % MOD


def comb(n, m):
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD


class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        init()
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
const MOD: bigint = BigInt(1e9 + 7);
const MX: number = 100000;

const fact: bigint[] = new Array(MX).fill(0n);
const invFact: bigint[] = new Array(MX).fill(0n);
let built: boolean = false;

function qpow(x: number | bigint, n: number | bigint): bigint {
    x = BigInt(x);
    n = BigInt(n);
    let res = 1n;
    while (n > 0n) {
        if (n & 1n) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        n >>= 1n;
    }
    return res;
}

function init(): void {
    if (fact[0] != 0n) {
        return;
    }
    fact[0] = 1n;
    for (let i = 1; i < MX; i++) {
        fact[i] = (fact[i - 1] * BigInt(i)) % MOD;
    }

    invFact[MX - 1] = qpow(fact[MX - 1], MOD - 2n);
    for (let i = MX - 2; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * BigInt(i + 1)) % MOD;
    }
}

function comb(n: number, m: number): bigint {
    if (m < 0 || m > n) {
        return 0n;
    }
    return (((fact[n] * invFact[m]) % MOD) * invFact[n - m]) % MOD;
}

function countGoodArrays(n: number, m: number, k: number): number {
    init();
    let res = comb(n - 1, k);
    res = (res * BigInt(m)) % MOD;
    res = (res * qpow(m - 1, n - k - 1)) % MOD;
    return Number(res);
}
```

</details>
